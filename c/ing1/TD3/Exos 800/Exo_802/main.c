#include <stdio.h>
void addition(int *pa)
{
    *pa = *pa+1;
    printf("%d",*pa);
}
void multiplication(int *pa)
{
    *pa = (*pa)*2;
    printf("%d",*pa);
}
void soustraction(int *pa)
{
    *pa = *pa-4;
    printf("%d",*pa);
}
void somme(int *pa)
{
    int i,a;
    for (i=0;i<=*pa;i++)
        a=a+i;
    printf("\n%d",a);
}
void menu(int pa) {
    int a;
    do{
        printf("\n1 : Ajouter 1  \n2 :Multiplier par 2  \n3 : Soustraire 4  \n4 : Somme de n premiers entiers (n etant passe en parametre)\n5 : Quitter  ");
    scanf("%d", &a);
        switch (a) {
            case 1 :
                addition(&pa);
                break;
            case 2 :
                multiplication(&pa);
                break;
            case 3 :
                soustraction(&pa);
                break;
            case 4 :
                somme(&pa);
                break;
            case 5 :
                printf("Quitter");
                break;
            default:
                menu(pa);
        }
} while (a!=0);
}
int main(void) {
    int a;
    do {
        printf("saisir 1 entier :");
        scanf("%d", &a);
    } while (a<0);
    int *pa =&a;
    menu(*pa);
    return 0;
}