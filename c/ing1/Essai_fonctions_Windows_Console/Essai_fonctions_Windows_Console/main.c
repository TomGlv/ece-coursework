#include <stdio.h>
#include <conio.h> // inclure cette librairie pour la fonction system dans le main
#include <windows.h> // inclure cette librairie pour les 2 sous-programmes qui suivent

/*
 * Nom du sous-programme de la librairie windows.h à copier : gotoligcol
 * Rôle : positionne le curseur à l'écran
 * Paramètres : lig pour la ligne et col pour la colonne du curseur à 'écran
 */
void gotoligcol( int lig, int col )
{
// ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

/*
 * Nom du sous-programme de la librairie windows.h à copier  : Color
 * Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
 * Paramètres : couleurDuTexte pour la couleur du texte et couleurDeFond pour la couleur du fond
 */
void Color(int couleurDuTexte,int couleurDeFond)
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int main() {
    int touche;

    // positionner le curseur à la ligne 5 colonne 20 de curseur avant d'afficher le message
    gotoligcol(5,20);

    // afficher le message avec le texte en rouge fluo (12) et le fond en jaune (14)
    Color(12, 14);
    printf("Tape une touche sans valider par entree\n");

    // taper sur une touche du clavier sans valider avec la touche entrée
    touche=getch();

    // afficher cette touche avec le texte en bleu fluo (9) et le fond en blanc (15)
    Color(9, 15);
    printf("la touche tapee est %c\n",touche);

    // taper sur une touche pour effacer l'écran
    printf("tape une touche pour effacer l'ecran");
    touche=getch();

    // effacer l'écran
    system("cls");

    // En ligne 4 et colonne 10 de l'écran, afficher un message en blanc (15) sur noir (0)
    gotoligcol(4, 10);
    Color(15, 0);
    printf("ceci est un autre ecran\n");

    // Taper une dernière touche pour finir le programme
    printf("tape une touche pour finir le programme");
    touche=getch();
    return 0;
}
