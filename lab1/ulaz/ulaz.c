#include <stdio.h>

#include "ulaz.h"
#include "../postavke.h"
#include "datoteka/datoteka.h"

int ucitaj(char *ulaz, size_t max_vel, int od_kuda)
{
	size_t velicina = 0;
	
	if ((od_kuda & ZASTAVICA(UCITAJ_IZ_DATOTEKE)))
		velicina = ucitaj_iz_datoteke(ulaz, max_vel);

	#if DEBUG == 1
	printf("\nUlaz:\n______\n%s\n", ulaz);
	#endif

	return velicina;
}
