#include <stdio.h>
#define PI 3.14159

void calculer_cercle_valeur(float rayon) {
    float aire = PI * rayon * rayon;
    float perimetre = 2 * PI * rayon;
    printf("Aire du cercle : %.2f\n", aire);
    printf("Perimetre du cercle : %.2f\n", perimetre);
}
void calculer_cercle_adresse(float rayon, float *aire, float *perimetre) {
    *aire = PI * rayon * rayon;
    *perimetre = 2 * PI * rayon;
}
void calculer_rectangle_valeur(float longueur, float largeur) {
    float aire = longueur * largeur;
    float perimetre = 2 * (longueur + largeur);
    printf("Aire du rectangle : %.2f\n", aire);
    printf("Perimetre du rectangle : %.2f\n", perimetre);
}
void calculer_rectangle_adresse(float longueur, float largeur, float *aire, float *perimetre) {
    *aire = longueur * largeur;
    *perimetre = 2 * (longueur + largeur);
}
void calculer_triangle_valeur(float base, float hauteur) {
    float aire = 0.5 * base * hauteur;
    printf("Aire du triangle : %.2f\n", aire);
}
void calculer_triangle_adresse(float base, float hauteur, float *aire) {
    *aire = 0.5 * base * hauteur;
}

int main() {
    int choix;
    printf("Choisissez une forme geometrique :\n");
    printf("1. Cercle\n2. Rectangle\n3. Triangle\n");
    scanf("%d", &choix);

    if (choix == 1) {
        float rayon, aire, perimetre;
        printf("Entrez le rayon du cercle : ");
        scanf("%f", &rayon);
        calculer_cercle_valeur(rayon);
        calculer_cercle_adresse(rayon, &aire, &perimetre);
        printf("Aire du cercle (par adresse) : %.2f\n", aire);
        printf("Perimtre du cercle (par adresse) : %.2f\n", perimetre);
    } else if (choix == 2) {
        float longueur, largeur, aire, perimetre;
        printf("Entrez la longueur et la largeur du rectangle : ");
        scanf("%f %f", &longueur, &largeur);

        calculer_rectangle_valeur(longueur, largeur);
        calculer_rectangle_adresse(longueur, largeur, &aire, &perimetre);
        printf("Aire du rectangle (par adresse) : %.2f\n", aire);
        printf("Péerimetre du rectangle (par adresse) : %.2f\n", perimetre);
    } else if (choix == 3) {
        float base, hauteur, aire;
        printf("Entrez la base et la hauteur du triangle : ");
        scanf("%f %f", &base, &hauteur);
        calculer_triangle_valeur(base, hauteur);
        calculer_triangle_adresse(base, hauteur, &aire);
        printf("Aire du triangle (par adresse) : %.2f\n", aire);
    } else {
        printf("Choix invalide.\n");
    }

    return 0;
}
