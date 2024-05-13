/*! Timer api testing */

#include <stdio.h>
#include <time.h>
#include <api/prog_info.h>

static timespec_t t0;

static int HZ;

static void alarm_nt(sigval_t param)
{
	
	timespec_t t;

	clock_gettime(CLOCK_REALTIME, &t);
	time_sub(&t, &t0);

	if(get_HZ()!=HZ){
		HZ=get_HZ();
		
	}
	printf("System time %d:%d\n",t.tv_sec,t.tv_nsec/1000000);
		
}

int timer()
{
	HZ=get_HZ();
	printf("%d",HZ);
	timespec_t t;
	itimerspec_t tc;
	//t1, t2;
	timer_t timerc;
	//timer1, timer2;
	sigevent_t evp;

	printf("Example program: [%s:%s]\n%s\n\n", __FILE__, __FUNCTION__,
		 timer_PROG_HELP);

	clock_gettime(CLOCK_REALTIME, &t);
	t0 = t;
	printf("System time: %d:%d\n", t.tv_sec, t.tv_nsec/100000000);

	evp.sigev_notify = SIGEV_THREAD;
	evp.sigev_notify_function = alarm_nt;
	evp.sigev_notify_attributes = NULL;

	
	tc.it_interval.tv_sec = 0;
	tc.it_interval.tv_nsec = 1000000000/HZ;
	tc.it_value.tv_sec = 0;
	tc.it_value.tv_nsec = 1000000000/HZ;
	evp.sigev_value.sival_int = tc.it_interval.tv_nsec;
	timer_create(CLOCK_REALTIME, &evp, &timerc);
	timer_settime(&timerc, 0, &tc, NULL);
	

	t.tv_sec = 5;
	t.tv_nsec = 0;

	while (TIME_IS_SET(&t))
		if (clock_nanosleep(CLOCK_REALTIME, 0, &t, &t))
			printf("Interrupted sleep?\n");
	clock_gettime(CLOCK_REALTIME, &t);
	printf("System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000);

	timer_delete(&timerc);
	return 0;
}
