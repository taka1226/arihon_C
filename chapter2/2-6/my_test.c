#include <stdio.h>
#include <math.h>

int main(void) {

    double num1 = 1.5;
    double num2 = 2.3;

    double max = fmax(num1, num2);

    printf("max=%f\n", max);

    return 0;
}
