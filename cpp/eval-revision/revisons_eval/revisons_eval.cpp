#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct mabite {
    char nom[50];
    int categorie;//probleme ici
    int quantite_en_stock;
    float prix_unitaire;
};

void afficher_produit(struct mabite produit) {
    printf("produit ajt: \n");
    printf("nom %s\n", produit.nom);
    switch (produit.categorie) {
    case 1:printf("categorie: alimentiare\n");
        break;
    case 2 :printf("categorie: electronqiue\n");
        break;
    case 3 :printf("categorie: vetement\n");
        break;
    case 4 :printf("categorie: mobilier\n");
        break;
    }
    printf("quantite en stock %d \n", produit.quantite_en_stock);
    printf("prix unitaire %f \n", produit.prix_unitaire);


}
void ajouter_produit() {
    struct mabite produit;
 
    printf("Entrez le nom du produit: ");
    scanf("%s", &produit.nom);

    printf("Entrez la categorie (1: Alimentaire, 2: electronique, 3: Vetements, 4: mobilier): ");
    scanf("%d", &produit.categorie);

    printf("Entrez la quantite en stock: ");
    scanf("%d", &produit.quantite_en_stock);

    printf("Entrez le prix unitaire: ");
    scanf("%f", &produit.prix_unitaire);

    afficher_produit(produit);

    
}

int main() {
    struct mabite produit;
    ajouter_produit();



    return 0;
}   
