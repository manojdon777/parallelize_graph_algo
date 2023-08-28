#include <time.h>
#include <stdlib.h>
int foo() {
    srand(time(NULL));
    return rand() % 100;;
}
