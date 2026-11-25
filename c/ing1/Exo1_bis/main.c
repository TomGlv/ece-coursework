#include <stdio.h>

void sauvegarder(int n,char chaine[10]){
    int i;
    FILE* pf=fopen("./fichier.txt","w+");
    if(pf==NULL){
        printf("Erreur lors de l'ouverture du fichier");
    }
    fprintf(pf,"%s",chaine);
    for (i=0;i<n;i++){
        fprintf(pf,"%d",i);
    }
}
int main() {
    char chaine[10];
    int n;
    printf("Entrez le nom du fichier : ");
    scanf("%s", chaine);
    printf("Entrez le nombre de reels : ");
    scanf("%d", &n);
    sauvegarder(n,chaine);
    return 0;
}
