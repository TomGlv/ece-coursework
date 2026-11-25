#include <stdio.h>

int main() {
    int entier;
    printf("saisir un entier :");
    scanf("%d",&entier);
    if(entier%3==0)
        printf("Cet entier est un multiple de 3");
    else
        printf("Cet entier n'est pas un multiple de 3");
    if(entier>=10)
        printf("\nCet entier est superieur ou egal a 10");
    else
        printf("\nCet entier n'est pas superieur ou egal a 10");
    return 0;
}