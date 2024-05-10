#include <stdio.h>
#include <time.h>
#include <api/prog_info.h>

static timespec_t t0;
int HZ=1000;
static void alarm_nt(sigval_t param)
{
    int num;
    timespec_t t;

    num = param.sival_int;
    clock_gettime(CLOCK_REALTIME, &t);
    time_sub(&t, &t0);
    
    printf("[%d:%d] Alarm %d(every %d seconds)\n",
		t.tv_sec, t.tv_nsec/100000000, num, HZ);
}

int timer()
{
	
    timespec_t t;
    itimerspec_t t1;
    timer_t timer1;
    sigevent_t evp;

    printf("Example program: [%s:%s]\n%s\n\n", __FILE__, __FUNCTION__, timer_PROG_HELP);

    clock_gettime(CLOCK_REALTIME, &t);
    t0 = t;
    printf("System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000);

    evp.sigev_notify = SIGEV_THREAD;
    evp.sigev_notify_function = alarm_nt;
    evp.sigev_notify_attributes = NULL;

    /* Postavljanje timera */
    t1.it_interval.tv_sec = 0;
    t1.it_interval.tv_nsec = 1 / HZ;  // 1000 puta u sekundi
    t1.it_value = t1.it_interval;  // početak odmah na 1/HZ sekundi
    evp.sigev_value.sival_int = HZ;  // prenosi se HZ kao parametar
    timer_create(CLOCK_REALTIME, &evp, &timer1);
    timer_settime(&timer1, 0, &t1, NULL);

    // Pokretanje timera na određeno vrijeme
    t.tv_sec = 30; 
    t.tv_nsec = 0;

    if (clock_nanosleep(CLOCK_REALTIME, 0, &t, NULL))
        printf("Interrupted sleep?\n");

    clock_gettime(CLOCK_REALTIME, &t);
    printf("System time after running timer: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000);

    timer_delete(&timer1);

    return 0;
}
