/*! Timer in arch layer; use 'arch_timer_t' device defined in configuration */

#pragma once

#include <types/time.h>

/*! (arch) timer interface */
typedef struct _arch_timer_t_
{
	timespec_t  min_interval;
	timespec_t  max_interval;

	void (*init)();
	void (*set_interval)(timespec_t *);
	void (*get_interval_remainder)(timespec_t *);
	void (*enable_interrupt)();
	void (*disable_interrupt)();
	void (*register_interrupt)(void *handler);
	
}
arch_timer_t;

void arch_timer_init(timespec_t period, void *kernel_timer_handler);
void arch_timer_set_interval(timespec_t period);

