#include "menu.h"

//prend en parametres un bloc poussable ainsi que le tableau et deplace le bloc
void pouss(def_bloc *bloc_poussable,def_bloc plateau[HAUTEUR][LARGEUR]) {
    int x,y;
    x=(*bloc_poussable).x;
    y=(*bloc_poussable).y;
    if(plateau[(*bloc_poussable).y-1][(*bloc_poussable).x].perso==Ssnoopy){ //si snoopy au dessus du bloc, on deplace le bloc de 1 vers le bas
        y++;
    }
    else if (plateau[(*bloc_poussable).y][(*bloc_poussable).x-1].perso==Ssnoopy) {//si snoopy à gauche du bloc, on deplace le bloc de 1 vers la droite
        x++;
    }
    else if (plateau[(*bloc_poussable).y+1][(*bloc_poussable).x].perso==Ssnoopy) {//si snoopy au dessous du bloc, on deplace le bloc de 1 vers le haut
        y--;
    }
    else if (plateau[(*bloc_poussable).y][(*bloc_poussable).x+1].perso==Ssnoopy) {//si snoopy à droite du bloc, on deplace le bloc de 1 vers la gauche
        x--;
    };
    (*bloc_poussable).perso=Sincassable;
    maj_position(bloc_poussable,&plateau[y][x],plateau);// on met à jour les coordonnées du bloc poussable
}

void casse(def_bloc *snoopy,def_bloc plateau[HAUTEUR][LARGEUR]){
    int x,y;
    x=(*snoopy).x;
    y=(*snoopy).y;
    if(plateau[(*snoopy).y-1][(*snoopy).x].perso==Scassable){ //si bloc cassable au dessus du bloc
        plateau[y-1][x].perso=Sespace;// remplace le bloc cassable par un espace
    }
    else if (plateau[(*snoopy).y][(*snoopy).x-1].perso==Scassable) {//si bloc cassable à gauche du bloc
        plateau[y][x-1].perso=Sespace;
    }
    else if (plateau[(*snoopy).y+1][(*snoopy).x].perso==Scassable) {//si bloc cassable au dessous du bloc
        plateau[y+1][x].perso=Sespace;
    }
    else if (plateau[(*snoopy).y][(*snoopy).x+1].perso==Scassable) {//si bloc cassable à droite du bloc
        plateau[y][x+1].perso=Sespace;
    };
}

//deplace snoopy en fonction de la diection du tapis
void tapis(def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR]) {
    int x, y, x1, y1;
    char perso_tapis;
    x1 = (*snoopy).x;
    y1 = (*snoopy).y;
    x = (*snoopy).x;
    y = (*snoopy).y;
    if ((*snoopy).sensTapis == 1) {// descend
        y+=1;
        perso_tapis = StapisBas;
    }
    if ((*snoopy).sensTapis == -1) {//monte
        y-=1;
        perso_tapis = StapisHaut;
    }
    if ((*snoopy).sensTapis == 2) {//droite
        x+=1;
        perso_tapis = StapisDroite;
    }
    if ((*snoopy).sensTapis == -2) {//gauche
        x-=1;
        perso_tapis = StapisGauche;
    }
    //reaffiche le tapis après le passage de snoopy
    if(autorise_deplacement(snoopy,&plateau[y][x], plateau)) {
        maj_position(snoopy, &plateau[y][x], plateau);
        plateau[y1][x1].perso = perso_tapis;
        usleep(100000);
    }
    effacerEcran();
    afficher_plateau(plateau);
}

void deplacer_balle(def_bloc *balle,def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR],int tab[2]) {
    // Rebondir diago
    if (tab[0] == 1 || tab[0] == LARGEUR - 2) {//tab0 la coordonnée x de la balle
        balle->directionX *= -1;
    }if ((tab[1]) == 1 || tab[1] == HAUTEUR - 2) {//tab1 la coordonnée y de la balle
        balle->directionY *= -1;
    }

    tab[0] += balle->directionX;// les nouvelles positions de la balle
    tab[1] += balle->directionY;
    //nouvelle position valide
    if (plateau[tab[1]][tab[0]].perso == Sespace) {
        balle->perso=Sballe;
        maj_position(balle,&plateau[tab[1]][tab[0]],plateau);
    }else{
        if( plateau[tab[1]-balle->directionY][tab[0]-balle->directionX].perso==Sballe)
            plateau[tab[1]-balle->directionY][tab[0]-balle->directionX].perso=Sespace;
        if( plateau[tab[1]][tab[0]].perso==Ssnoopy)
            snoopy->vie-=1;}
}

void teleportation(def_bloc *snoopy, def_bloc plateau[HAUTEUR][LARGEUR],def_bloc *destination){
    maj_position(snoopy,destination,plateau);
}