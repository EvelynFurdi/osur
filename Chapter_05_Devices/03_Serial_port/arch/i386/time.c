#include "time.h"
#include "stdio.h"
#include <types/time.h>

extern arch_timer_t TIMER; // Pretpostavlja se definicija ovog uređaja u nekoj drugoj datoteci
static arch_timer_t *timer = &TIMER;

// Funkcija za početnu inicijalizaciju tajmera
void arch_timer_init(timespec_t period, void *kernel_timer_handler)
{

	timer->init();  // Inicijalizacija tajmera
    // Provera da li je period unutar minimalnog i maksimalnog intervala tajmera
    if (period.tv_sec < timer->min_interval.tv_sec ||
        (period.tv_sec == timer->min_interval.tv_sec && period.tv_nsec < timer->min_interval.tv_nsec))
    {
        period = timer->min_interval;
    }
    else if (period.tv_sec > timer->max_interval.tv_sec ||
             (period.tv_sec == timer->max_interval.tv_sec && period.tv_nsec > timer->max_interval.tv_nsec))
    {
        period = timer->max_interval;
    }

    
    timer->set_interval(&period);  // Postavljanje intervala tajmera
    timer->register_interrupt(kernel_timer_handler);  // Registracija funkcije za prekid
    timer->enable_interrupt();  // Omogućavanje prekida
}

// Funkcija za promjenu intervala tajmera
void arch_timer_set_interval(timespec_t period)
{
    timer->set_interval(&period);  // Ažuriranje intervala tajmera
}
