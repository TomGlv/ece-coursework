#include <stdio.h>

int fibonacci_recursive(int n) {
    int i;
    if (n == 0 || n == 1)
        return 1;
    else
        i = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
        return i;
}
int main() {
    int n;
    printf("Entrez la valeur de n : ");
    scanf("%d", &n);
    printf("La valeur de Fibonacci pour n est : %d\n", fibonacci_recursive(n));
    return 0;
}
 