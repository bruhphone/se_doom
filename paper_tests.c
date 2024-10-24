#include <stdio.h>
#include <stdlib.h>

#include "paper.h"
#include "se_killer.h"

int main(void) {
    // bar(123, 1234); // seg faults on my system
    run_tests();
    killer(0, NULL);
    return 0;
}
