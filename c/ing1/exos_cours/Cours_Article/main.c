#include <stdio.h>
#include <stdlib.h>
#include "article.h"
#define N 1
int main() {
    int i;
    t_article tab[N];
    t_article pa;

    for (i=0; i<N; i++) {
        printf("Saisir le %d article", i+1);
        saisirArticle(&pa);
        tab[i] = pa;
    }
    AffArticle(&pa);
    return 0;
}