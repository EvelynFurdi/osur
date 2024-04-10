#include <types/basic.h>

void premjesti()
{
	extern int instrukcije_end;
	extern char size_data;
	extern size_t size_i;
	size_t size_d = (size_t) &size_data;
	size_t i;
	char *od = (char *) 0x50000;
	char *kamo = (char *) (&instrukcije_end);

	//for ( i = 0; i< size_d; i++ )
	//	kamo[i] = od[i];

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;

	od = (char *) 0x10000;
	kamo = (char *) 0x200000;
	size_d = (size_t) &size_i;

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;
}


