#include <stdlib.h>
#include <stdio.h>

#include "se_killer.h"

void branch_test(int l) {
    char buf[20];
    long p = 42;

    long *q = (long*) malloc(l*sizeof(long));

    if (l % 7 == 0) {
	p = 0x0;
	free(q);
    } else if (l % 11 == 0) {
	p = (long) &buf;
    } else {
	p = (long) &p;
    }

    q[0] = p; // potential use after free; consider heap exploit from homework 2
    
    printf("Might have executed malware- sorry.\n");
}

void killer(int argc, char *argv[]) {
    branch_test(21);
    return;
}
