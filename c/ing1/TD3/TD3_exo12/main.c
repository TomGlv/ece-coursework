#include <stdio.h>

int main() {
    int entier,i;
    printf("Saisissez un entier :\n");
    scanf("%d",&entier);
    for (i = 1;i<=entier;i+=2){
        printf("%d\n",i);
    }
    return 0;
}