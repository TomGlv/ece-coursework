#include <stdio.h>
#include "article.h"
void saisirArticle(t_article* pa){
    printf("\nsaisir le code :\n");
    fflush(stdin);
    scanf("%d",&(pa->code));
    ///ou scanf("%d",&((*pa).code);
    printf("\nsaisir le nom :\n");
    fflush(stdin);
    scanf("%d",&(pa->nom));
    printf("\nsaisir le prix :\n");
    fflush(stdin);
    scanf("%d",&(pa->prix));
    printf("\nsaisir le stock :\n");
    fflush(stdin);
    scanf("%d",&(pa->qStock));
}
void AffArticle(t_article* pa){
    printf("Les details de l'article %d sont : \n -Nom de l'article :%c\n -Prix de l'article %f \n-Stock de l'article : %d",
           (pa->code), (pa->nom), (pa->prix), (pa->qStock));
}