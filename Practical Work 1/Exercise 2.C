#include <stdio.h>
#include <stdlib.h>

// Exercise 2.C: Swapping values using pass-by-value and pass-by-address in C

void echange_val(float a, float b) {
    float temp = a;
    a = b;
    b = temp;
}

void echange_addr(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float x = 5.0, y = 10.0;
    
    printf("Avant echange_val: x = %.2f, y = %.2f\n", x, y);
    echange_val(x, y);
    printf("Apres echange_val: x = %.2f, y = %.2f\n", x, y);
    
    printf("Avant echange_addr: x = %.2f, y = %.2f\n", x, y);
    echange_addr(&x, &y);
    printf("Apres echange_addr: x = %.2f, y = %.2f\n", x, y);
    
    return 0;
}

