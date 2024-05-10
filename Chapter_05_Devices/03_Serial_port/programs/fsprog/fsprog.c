
#include <kernel/errno.h>
#include <kernel/features.h>
#include <arch/interrupt.h>
#include <arch/processor.h>
#include <api/stdio.h>
#include <api/prog_info.h>


int fsprog(){
	printf("\n");
	printf("TEST PROGRAM \n");
	
    	printf("\ntest1\n");
    	int fd2 = open("file:test1", O_CREAT | O_WRONLY, 0);
	kprintf("fd=%d\n", fd2);
	int retval2 = write(fd2, "Pišem neki tekst", 17);
	kprintf("retval2=%d\n", retval2);
	retval2 = close(fd2);
	kprintf("retval2=%d\n", retval2);

	fd2 = open("file:test1", O_RDONLY, 0);
	kprintf("fd=%d\n", fd2);
	char buff[11];
	retval2 = read(fd2, buff, 17);
	kprintf("retval2=%d\n", retval2);
	kprintf("buff=%s\n", buff);
    
    	printf("\ntest2\n");
    	int fd3 = open("file:test2", O_CREAT | O_WRONLY, 0);
	kprintf("fd=%d\n", fd3);
	int retval3 = write(fd3, "Lijepi tekst", 13);
	kprintf("retval3=%d\n", retval3);
	retval3 = close(fd3);
	kprintf("retval3=%d\n", retval3);

	fd3 = open("file:test2", O_RDONLY, 0);
	kprintf("fd=%d\n", fd3);
	char buff2[11];
	retval3 = read(fd3, buff2, 13);
	kprintf("retval3=%d\n", retval3);
	kprintf("buff=%s\n", buff2);
	
	printf("\nToo long filename\n");
	printf("\ntest3hahahhahahah\n");
	int fd4 = open("file:test3hahahhahahah", O_CREAT | O_WRONLY, 0);
	kprintf("fd=%d\n", fd4);
	int retval4 = write(fd4, "Moj tekst", 10);
	kprintf("retval4=%d\n", retval4);
	retval4 = close(fd4);
	kprintf("retval4=%d\n", retval4);

	fd4 = open("file:test3hahahhahahah", O_RDONLY, 0);
	kprintf("fd=%d\n", fd4);
	char buff3[11];
	retval4 = read(fd4, buff3, 10);
	kprintf("retval4=%d\n", retval4);
	kprintf("buff=%s\n", buff3);
	
	return 0;}
    
