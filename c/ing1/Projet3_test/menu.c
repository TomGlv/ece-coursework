#include "menu.h"
// Fonction pour effacer l'écran
void effacerEcran() {
    system("cls"); // Utilise la commande "cls" de la librairie windows pour effacer l'écran sur Windows
}
void choix_menu(){//les choix du menu sont executés ici
    char touche=0;
    touche=_getch(); //recupere une commande au clavier sans necessiter de scanf
    def_bloc plateau[HAUTEUR][LARGEUR];
    switch (touche) {
        case '1' : //regles du jeu
            effacerEcran();
            int i,j;
            j=10;
            for (i=0;i<10;i++){
                printf("\nChaque niveau devra etre resolu en moins de 120 secondes.\nSi le temps est ecoule, le joueur perd une ");
                printf("vie et recommence le niveau.\nLe but est de recuperer les 4 oiseaux du niveau sans se faire toucher par ");
                printf("la balle et/ou les ennemis (si presents).\nVous pouvez vous deplacer avec les touches z,q,s,d.\n");
                printf("Snoopy : S\nballe : O\noiseau : ~\nbloc poussable : P\nbloc bonus : +\nbloc cassable en appuyant sur la touche c : C\n");
                printf("\n===  Ce menu s'affichera pendant 10 secondes, il reste : ");
                printf("%d",j);
                printf(" secondes  ===");
                j--;
                sleep(1);
                effacerEcran();
            }
            affichage_menu();
            break;




        case '2' : /// lancer un nouveau jeu a partir du niveau 1
            effacerEcran();
            print_text();
            effacerEcran();
            print_text();
            Color(10,0);
            printf("1. Niveau 1 Mode Facile\n2. Niveau 1 Mode Moyen\n3. Niveau 1 Mode Difficile");
            char touche2=0;
            touche2=_getch();
            switch(touche2){
                case '1' : initniveau1facile(plateau);
                    break;
                case '2' : initniveau1moyen(plateau);
                    break;
                case '3' : initniveau1dur(plateau);
                    break;
            }
            break;
        case '3' :
            chargerpartie(plateau);
            ///charger une partie
            break;
        case '4' :

            effacerEcran();
            print_text();
            printf("Quel niveau voulez vous lancer ?\n");
            printf("1. Niveau 2\n2. Niveau 3");
            char choix=0;
            choix=_getch();
            int a;
            switch (choix){
                case '1' :
                    effacerEcran();
                    print_text();
                    Color(10,0);
                    printf("\nsaisir le mot de passe du niveau 2 : ");
                    scanf("%d",&a);
                    if (a==mp2){
                        printf("Bravo pour votre reussite !!!\nMaintenant place aux choses serieuses : \n1. Niveau 2 Mode Facile\n2. Niveau 2 Mode Moyen\n3. Niveau 2 Mode Difficile");
                    }
                    else {
                        printf("Mot de passe incorrect vous devez reussir le niveau 1 pour avoir acces au niveau 2 !!");
                        affichage_menu();
                    }
                    char nv2;
                    nv2 = _getch();
                    switch (nv2) {
                        case '1' :
                            initniveau2facile(plateau);
                            break;
                        case '2' :
                            initniveau2moyen(plateau);
                            break;
                        case'3' :
                            initniveau2dur(plateau);
                            break;
                        default :
                            break;
                    }
                    break;


                case '2'  :
                    effacerEcran();
                    print_text();
                    Color(10,0);
                    printf("\nsaisir le mot de passe du niveau 3 :");
                    scanf("%d",&a);
                    if (a==mp3){
                        printf("Bravo pour votre reussite !!!\nMaintenant place aux choses serieuses : \n1. Niveau 3 Mode Facile\n2. Niveau 3 Mode Moyen\n3. Niveau 3 Mode Difficile");
                    }else {
                        printf("Mot de passe incorrect vous devez reussir le niveau  pour avoir acces au niveau 3 !!");
                        affichage_menu();
                    }
                    char touche4=0;
                    touche4=_getch();

                    switch(touche4){
                        case '1' : initniveau3facile(plateau);
                            break;
                        case '2' : initniveau3moyen(plateau);
                            break;
                        case '3' : initniveau3dur(plateau);
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
            break;
        case '5' :
            savescore();
            affichage_menu();
            break;
        case '6' :
            exit(1);//commande permettant d'arreter tout le programme
            break;
        default :
            printf("veuillez saisir une valeur entre 1 et 6");
            choix_menu();
            break;
    }
}
void affichage_menu() {//affiche la partie textuelle du menu
    effacerEcran(); // Efface l'écran
    print_text();
    printf("                            Que voulez vous faire ?\n");
    printf("                            1. Regles du jeu\n                            2. lancer un niveau\n                            3. charger une partie \n                            4. mot de passe\n                            5. scores\n                            6. quitter");
    printf("\n");
    choix_menu();
}
void menu_partie_en_cours(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran(); // Efface l'écran
    print_text();
    printf("Que voulez vous faire ?\n");
    printf("1. Reprendre la partie en cours\n2. Revenir au menu principal\n3. Sauvegarder la partie\n4. Quitter le jeu\n");
    printf("\n");
    int touche;
    touche = _getch();
    switch (touche) {
        case '1' :
            ///reprendre le jeu
            break;
        case '2' :
            affichage_menu();
            break;
        case '3' :
            sauvegarde(plateau);
            break;
        case '4' :
            exit(1);
            ///Quitter le jeu
            break;
        default :
            menu_partie_en_cours(plateau);
            break;
    }
}
