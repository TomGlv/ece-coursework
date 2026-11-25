#include <stdio.h>

//déclaration du sous programme Remplissage du Tableau
void RemplissageTab (int tab[], int lignes){
    //déclaration des variables tab et lignes
    for (int i = 0; i<lignes; i++){
        //boucle for avec un systeme de comptage i qui permet de passer d'une ligne a l'autre et de remplir les valeurs
        printf("saisir la valeur %d du tableau\n", i+1);
        //saisie des valeurs
        scanf("%d",&tab[i]);
    }
}
//nouveau sous programme qui permet l'affichage du tableau
void AffichageTab (int tab[], int lignes){
    for (int i = 0; i<lignes; i++){
        printf ("%d",tab[i]);
    }
    printf("\n");
}
// sous programme pour tri par ordre croisant les valeurs rentrées pécédemment
void TriParInsertion (int tab[], int lignes){
    // declaration des variables i et j pour les lignes et les colonnes et inter qui vous nous permettre de grader les dernieres valeurs rentrées afin de mieux les trier sans les oublier
    int j, inter;
    for (int i = 1; i<lignes; i++){
        //inter va prendre la valeur de la deuxieme valeur rentrée car i est initialise à 1
        inter = tab[i];
        //j prend la valeur de la premiere valeur rentrée soit au rang i0
        j=i-1;
        //boucle while pour saisir toutes les valeurs et les trier dans l'ordre croissant
        while (j>=0 && tab[j]>inter){
            tab[j+1]=tab[j];
            j--;
        }
        //sortie du programme avec les dernieres valeurs prises par j qui va valoir la derniere valeur saisie au rang i
        tab[j+1]=inter;
    }
}
//sous programme qui permet de verifier si une valeur est presente dans le tableau
int ValeurPresente (int tab[], int lignes, int valeur){
    //boucle for pour la valeur interroge par l'utilisateur et savoir si elle est dzns le tableau
    for (int i = 0; i<lignes; i++){
        //outil de comparaison
        if (tab[i]== valeur){
            //si elle est presente le programme retourne 1 si nous il retourne 0
            return 1;
        }
        else {

        }
    }
    return 0;
}
int main() {
    //declaration de la variable taille pour determiner le nombre de valeur a rentrer et donc la taille de notre tableau
    int taille = 10;
    int tab[taille];
    //appel du sous programme pour remplir les valeurs dans notre tableau
    printf("creation et remplissage du tableau\n");
    RemplissageTab(tab, taille);
    //sous programme pour afficher notre tableau avec les valeurs saisies
    printf("affichage du tableau\n");
    AffichageTab(tab, taille);
    //affichage pour determiner l'ordre croissant des valeurs rentrées et le reafficher apres le tri
    printf("tri par ordre croissant des valeurs et affichage du nouveau\n");
    TriParInsertion(tab, taille);
    AffichageTab(tab, taille);
    //sous programme pour verifier si les valeurs sont presentent dans le tableau, on peut en verifier qu'une a la fois et quand elle est presente le programme nous retourne un 1
    printf("recherche d'une valeur dans le tableau et validation de sa presence dans celui-ci\n");
    printf("quelle valeur souhaitez vous verifier\n");
    int valeur = 0;
    scanf("%d",&valeur);
    if(ValeurPresente(tab, taille, valeur)==1){
        printf("valeur presente dans le tableau");
    }
    else{
        printf("valeur absente du tableau");
    }
    return 0;
}
