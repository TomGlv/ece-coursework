#include <stdio.h>

int main() {
    int i;
    int tab[13];
    for (i = 0; i < 13; i++) {
        printf("\nrentre un entier :");
        scanf("%d", &tab[i]);
    }
    for (i = 0; i < 13; i++) {
        printf("%d\n", tab[i]);
    }
    return 0;
}