#include "menu.h"
//definition du plateau
void creer_plateau_niveau1(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy){                  //chaque cellule du tableau correspond à un objet de la structure bloc
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (y == 0 || y == HAUTEUR - 1 || x == 0 || x == LARGEUR - 1) {
                plateau[y][x].perso = Sincassable; // Bord du plateau
                plateau[y][x].y=y;
                plateau[y][x].x=x;
                plateau[y][x].sensTapis = 0;
            }else if(y==1 && x==20) {                                               //definition du niveau dans creer_plateau temporaire -> se fera par ouverture de fichier texte interpretée par creer tableau à l'avenir
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==1 && x==1) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==10 && x==1) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==10 && x==20) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==1 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==10 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==2 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==3 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==1 && x==17) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==8 && x==4) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==8 && x==5) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==8 && x==6) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==8 && x==7) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==9 && x==7) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==10 && x==7) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==10 && x==8) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==10 && x==9) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==10 && x==10) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==10 && x==11) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==10 && x==11) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==10 && x==11) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==2 && x==3) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==3 && x==3) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==1 && x==3) {
                plateau[y][x].perso = Smort;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }

            else if(y==5 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==3) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==8 && x==3) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==7 && x==3) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==8&& x==20) {
                plateau[y][x].perso = Sbonus;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==3 && x==20) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;

            }
            else if(y==3 && x==19) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;

            }
            else if(y==2 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==1 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==7 && x==20) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==8 && x==19) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
            }else if(y==8 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==10 && x==17) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;

            }else if(y==1 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==17) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;

            }else if(y==9 && x==1) {
                plateau[y][x].perso = Scassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }

            else if(y==Y && x==X)//on place snoopy dans le plateau, snoopy precedemment entré en parametres
                plateau[y][x]=(*snoopy);
            else {
                plateau[y][x].perso = ' ';
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
        };
    };
}
void creer_plateau_niveau2(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy){                  //chaque cellule du tableau correspond à un objet de la structure bloc
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (y == 0 || y == HAUTEUR - 1 || x == 0 || x == LARGEUR - 1) {
                plateau[y][x].perso = Sincassable; // Bord du plateau
                plateau[y][x].y=y;
                plateau[y][x].x=x;
                plateau[y][x].sensTapis = 0;
            }else if(y==2 && x==19) {                                               //definition du niveau dans creer_plateau temporaire -> se fera par ouverture de fichier texte interpretée par creer tableau à l'avenir
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==2 && x==2) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==9 && x==19 ){
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==9 && x==2) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
                //coin en haut à gauche
            else if(y==1 && x==2) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==1 && x==3) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==2 && x==4) {
                plateau[y][x].perso = StapisBas;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 1;
            }
            else if(y==3 && x==2) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==3 && x==3) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==2 && x==1) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==1 && x==2) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==1 && x==3) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
            }
            else if(y==2 && x==4) {
                plateau[y][x].perso = StapisBas;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 1;
            }

                //coin en haut à droite
            else if(y==1 && x==20) {
                plateau[y][x].perso = Sbonus;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==1 && x==19) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==1 && x==18) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==3 && x==19) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==3 && x==18) {
                plateau[y][x].perso = StapisGauche;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -2;
            }
            else if(y==2 && x==20) {
                plateau[y][x].perso = StapisHaut;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = -1;
            }
            else if(y==2 && x==17) {
                plateau[y][x].perso = StapisBas;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 1;
            }
            else if(y==3 && x==16) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==3 && x==5) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }


                //barriere
            else if(y==6 && x==1) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==3) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==4) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==5) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==6) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==7) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==8) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==9) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==10) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==7 && x==11) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==12) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==13) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==14) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==15) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==16) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==17) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==18) {
                plateau[y][x].perso = Smort;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==19) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==6 && x==20) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }

/*            //Teleportation
            else if(y==1 && x==11) {
                plateau[y][x].perso = Steleportation;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }*/
            else if(y==Y && x==X)//on place snoopy dans le plateau, snoopy precedemment entré en parametres
                plateau[y][x]=(*snoopy);
            else {
                plateau[y][x].perso = ' ';
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
        };
    };
}
void creer_plateau_niveau3(def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *snoopy){                  //chaque cellule du tableau correspond à un objet de la structure bloc
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (y == 0 || y == HAUTEUR - 1 || x == 0 || x == LARGEUR - 1) {
                plateau[y][x].perso = Sincassable; // Bord du plateau
                plateau[y][x].y=y;
                plateau[y][x].x=x;
                plateau[y][x].sensTapis = 0;
            }else if(y==1 && x==20) {                                               //definition du niveau dans creer_plateau temporaire -> se fera par ouverture de fichier texte interpretée par creer tableau à l'avenir
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==1 && x==1) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==10 && x==20 ){
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==10 && x==1) {
                plateau[y][x].perso = Soiseau;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==1 && x==18) {
                plateau[y][x].perso = StapisDroite;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 2;
                ///printf("\nsens tapis : %d ",plateau[y][x].sensTapis);
                sleep(1);
            }
            else if(y==10 && x==19) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==19) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }

            else if(y==9 && x==1) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==4) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;

            }
            else if(y==1 && x==3) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==2 && x==3) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==3 && x==3) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==1) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==2) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==2 && x==11) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==3 && x==11) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==4 && x==11) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==11) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==12) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==13) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==16) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==5 && x==17) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==4 && x==17) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==3 && x==17) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==3 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==3 && x==19) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }else if(y==2 && x==18) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==3) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==5) {
                plateau[y][x].perso = Sincassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==4 && x==12) {
                plateau[y][x].perso = Sbonus;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==3 && x==2) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;

            }
            else if(y==5 && x==15) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].piege = 1;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==4 && x==2) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==5 && x==14) {
                plateau[y][x].perso = Spoussable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==9 && x==20) {
                plateau[y][x].perso = Scassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==3 && x==20) {
                plateau[y][x].perso = Scassable;
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
            else if(y==Y && x==X)//on place snoopy dans le plateau, snoopy precedemment entré en parametres
                plateau[y][x]=(*snoopy);
            else {
                plateau[y][x].perso = ' ';
                plateau[y][x].y = y;
                plateau[y][x].x = x;
                plateau[y][x].sensTapis = 0;
            }
        }
    }
}
//retourne 1 si snoopy peut se deplacer dans la direction souhaitée, 0 sinon. Prend en parametre snoopy, la case sur laquelle il veut aller,et le plateau
int autorise_deplacement(def_bloc *bloc,def_bloc *cellule,def_bloc plateau[HAUTEUR][LARGEUR]) {
    //calcul du sens de déplacement du bloc pour le cas bloc poussable -> en effet si tous les blocs devant lui sont poussables il doit pouvoir tous les pousser
    int x, y;
    x = (*cellule).x;
    y = (*cellule).y;
    if (((*bloc).x - (*cellule).x) == 0) {
        if (((*bloc).y - (*cellule).y) > 0)//snoopy monte
            y--;
        else        //snoopy descend
            y++;
    } else {
        if (((*bloc).x - (*cellule).x) > 0)//snoopy va à droite
            x--;
        else        //snoopy va à gauche
            x++;
    };

    if ((*cellule).perso == Sespace)//espace libre
        return 1;
    else if ((*cellule).perso == Sincassable)//bloc incassable
        return 0;
    else if ((*cellule).sensTapis !=0) {//bloc tapis roulant                         etant donné qu'il y 4 symboles de tapis, il est plus rapide de tester la variable sensTapis
        (*cellule).perso = Sespace;
        return 1;
    } else if ((*cellule).perso == Spoussable && plateau[y][x].perso == Sespace) {//Bloc poussable
        if ((*cellule).piege == 1)
            (*bloc).vie -= 1;// ne change rien si le bloc n'est pas snoopy, enleve une vie à snoopy sinon
        pouss(cellule, plateau);//-> execute le role du bloc poussable
        return 1;
    } else if ((*cellule).perso == Soiseau) {//bloc oiseau
        if ((*bloc).perso == Ssnoopy) {
            (*bloc).nb_oiseaux += 1;//on incremente de 1 la somme des oiseaux récupérés par snoopy
            (*cellule).perso = Sespace;
            return 1;
        }
    } else if ((*cellule).perso == Sbonus) {// bloc vie bonus
        if ((*bloc).perso == Ssnoopy) {
            (*bloc).vie += 1;// ne change rien si le bloc n'est pas snoopy, rajoute une vie a snoopy
            (*cellule).perso = Sespace;
            return 1;
        } else
            return 0;
    }else if((*cellule).perso == Smort){
        bloc->vie-=3;
        (*cellule).perso == Sespace;
        return 1;

    }
    else
        return 0;
}

//modifie le tableau pour echanger les positions de bloc et bloc2
void maj_position(def_bloc *bloc,def_bloc *bloc2,def_bloc plateau[HAUTEUR][LARGEUR]){
    def_bloc blocCopie,blocCopie2;
    blocCopie=*bloc;
    blocCopie2=*bloc2;

    //echange de place les deux blocs dans le tableau
    (*bloc).x=(*bloc2).x;
    (*bloc).y=(*bloc2).y;
    (*bloc).sensTapis=(*bloc2).sensTapis;// car coordonnées des tapis ne bougent pas, tout commme x,y
    plateau[(*bloc2).y][(*bloc2).x]=(*bloc);

    blocCopie2.x=blocCopie.x;
    blocCopie2.y=blocCopie.y;
    blocCopie2.sensTapis=blocCopie.sensTapis;
    plateau[blocCopie.y][blocCopie.x]=blocCopie2;

}


//affiche le plateau avec les blocs qui s'y trouvent
void afficher_plateau(def_bloc plateau[HAUTEUR][LARGEUR]) {
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            printf("%c", plateau[y][x].perso);
        }
        printf("\n");
    }}


void deplacement(def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR], int *mouvement_effectue, char touche) {
    int x, y;
    x = (*snoopy).x;
    y = (*snoopy).y;
    switch (touche) {
        case 'z':
            if (autorise_deplacement(snoopy, &plateau[(*snoopy).y - 1][(*snoopy).x], plateau) == 1) {
                y--;
                *mouvement_effectue = 1;
            }
            break;
        case 's':
            if (autorise_deplacement(snoopy, &plateau[(*snoopy).y + 1][(*snoopy).x], plateau) == 1) {
                y++;
                *mouvement_effectue = 1;
            }
            break;
        case 'q':
            if (autorise_deplacement(snoopy, &plateau[(*snoopy).y][(*snoopy).x - 1], plateau) == 1) {
                x--;
                *mouvement_effectue = 1;
            }
            break;
        case 'd':
            if (autorise_deplacement(snoopy, &plateau[(*snoopy).y][(*snoopy).x + 1], plateau) == 1) {
                x++;
                *mouvement_effectue = 1;
            }
            break;
        case 'c':
            // casse le bloc cassable si il est autour de snoopy
            casse(snoopy, plateau);
            break;
        default:
            break;
    }
    maj_position(snoopy, &plateau[y][x], plateau);
}