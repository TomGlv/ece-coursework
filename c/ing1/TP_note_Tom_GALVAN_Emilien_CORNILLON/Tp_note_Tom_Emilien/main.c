#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 16

void Creer_nombre_aleatoire(int tab[M]) {
    srand(time(NULL));
    for(int i=0;i<M;i++){
        tab[i]=rand() % 20 + 1;
    }
}
void creer_tableau_vect(int vect[M]){
    int a;
    for(int i=0;i<M;i++){
        printf("\necrivez le chiffre de la case %d du tableau a comparer :",i+1);
        scanf("%d",&a);
        vect[i]=a;
    }
}
void nbr_apparition(int tab[M]){
    for(int i=0;i<M;i++){
        int t=tab[i];
        int a=0;
        for(int j=0;j<M;j++){
            if(tab[j]==t)
                a++;
        }
        printf("%d : %d\n",tab[i],a);
    }
}
void entier(int tab[M]) {
    int E;
    int aE=0;
    int amax=0;

    do {
        printf("Choisissez un entier entre 1 et 100 :");
        scanf("%d",&E);
    } while (E<1||E>100);

    for(int i=0;i<M;i++) {
        int t=tab[i];
        int a=0;

        for(int j=0;j<M;j++) {
            if(tab[j]==t)
                a++;
            if(a>amax)
                amax=a;
        }
        for(int J;J<M;J++) {
            if(tab[J]==E) {
                aE++;
                if (aE != amax||aE!=0) {
                    printf("1\n");
                    return;
                }
                if (aE == amax) {
                    printf("2\n");
                    return;
                }
            }else printf("0");
            return;
        }
    }
}
void comparerTableaux(int tab[M], int vect[M]) {
    int somme=0;
    int y;
    for (y=0;y<M;y++){
        if(tab[y]==vect[y]) {
            somme = somme + tab[y] + vect[y];
        } if (somme > 13) {
            printf("0\n");
            return;
        } else {
            printf("1\n");
            return;
        }
    }
}
int main() {
    int tab[M];
    int vect[M];
    Creer_nombre_aleatoire(tab);
    nbr_apparition(tab);
    entier(tab);
    creer_tableau_vect(tab);
    comparerTableaux(tab,vect);
    return 0;
}
