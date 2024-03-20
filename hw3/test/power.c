#include <stdio.h>

int power (int a, int n){
    int r;
    r = a;
    if (n == 0) return 1;
    while (n-1>0) {
        a = a*r;
        n = n-1;
    }
    return a;
}

int main() {
    printf("power(2, 5)=%d\n", power(2, 5));
}