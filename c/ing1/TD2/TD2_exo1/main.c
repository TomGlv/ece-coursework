#include <stdio.h>

int main() {
    int val1,val2;
    printf("saisir le premier nombre : ");
    scanf("%d",&val1);
    printf("saisir le deuxieme nombre : ");
    scanf("%d",&val2);
    if (val1>val2)
        printf("le plus grand nombre entre les deux est : %d",val1);
    else
        printf("le plus grand nombre entre les deux est : %d",val2);
    return 0;
}