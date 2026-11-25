#include <stdio.h>

int main() {
    int largeur,longueur,aire,perimetre;
    printf("saisir la largeur du rectangle : ");
    scanf("%d",&largeur);
    printf("saisir la longueur du rectangle : ");
    scanf("%d",&longueur);
    perimetre=(longueur+largeur)*2;
    aire=longueur*largeur;
    printf("Ce rectangle de largeur %d et de longueur %d a : \n\t pour perimetre : %d \n\t pour aire : %d",largeur,longueur,perimetre,aire);
    return 0;
}
