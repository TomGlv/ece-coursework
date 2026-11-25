#include "menu.h"
void initniveau1facile(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    //definition d'une balle
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=8;
    balle.y=4;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée


    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 120;
    creer_plateau_niveau1(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);
    effacerEcran();
    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n", tempsRestant);
        //sauvegarderscore(tempsRestant);
        printf("  Vous avez reussi le niveau 1\n");
        printf("  le code pour le niveau 2 est : 8243\n");

        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }
    sleep(5);
    affichage_menu();
}

void initniveau1moyen(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=8;
    balle.y=4;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée

    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 110;
    creer_plateau_niveau1(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100 *2;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 1\n");
        printf("  le code pour le niveau 2 est : 8243\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(5);
    affichage_menu();
}
void initniveau1dur(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=8;
    balle.y=4;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 100;
    creer_plateau_niveau1(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100*3;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 1\n");
        printf("  le code pour le niveau 2 est : 8243\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(5);
    affichage_menu();
}
void initniveau2facile(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=4;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 100;
    creer_plateau_niveau2(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        //sauvegarderscore(tempsRestant);
        printf("  Vous avez reussi le niveau 2\n");
        printf("  le code pour le niveau 3 est : 6594\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(5);
    affichage_menu();
}
void initniveau2moyen(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=4;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 90;
    creer_plateau_niveau2(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100 *2;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 2\n");
        printf("  le code pour le niveau 3 est : 6594\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(3);
    affichage_menu();
}
void initniveau2dur(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=4;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 80;
    creer_plateau_niveau2(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100*3;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 2\n");
        printf("  le code pour le niveau 3 est : 6594\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(3);
    affichage_menu();
}
void initniveau3facile(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=9;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 100;
    creer_plateau_niveau3(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 3\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(3);
    affichage_menu();
}
void initniveau3moyen(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=9;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 90;
    creer_plateau_niveau3(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100 *2;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 3\n");
        printf("  le code pour le niveau 3 est : 6594\n");
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(3);
    affichage_menu();
}
void initniveau3dur(def_bloc plateau[HAUTEUR][LARGEUR]) {
    effacerEcran();

    def_bloc snoopy1;
    snoopy1.x = X;
    snoopy1.y = Y;
    snoopy1.perso = Ssnoopy;
    snoopy1.vie = 3;
    snoopy1.nb_oiseaux = 0;
    snoopy1.sensTapis = 0;
    def_bloc *snoopy = &snoopy1;
    def_bloc balle;
    balle.perso=Sballe;
    balle.x=9;
    balle.y=9;
    balle.directionX = 1;
    balle.directionY = 1;
    int tab_coord[2];
    tab_coord[1]=balle.y;
    tab_coord[0]=balle.x;// pour retenir les coordonnées de la balle quand elle ne peut etre affichée
    int tempsRestant = 120;
    time_t debut = time(NULL);
    int nbr_deplacements = 80;
    creer_plateau_niveau3(plateau, snoopy);
    int mouvement_effectue=0;
    int temps_balle=119;
    do {
        afficher_plateau(plateau);
        if(snoopy->sensTapis!=0)//conditions pour tapis
            tapis(snoopy,plateau);
        tempsRestant = 120 - (time(NULL) - debut);
        if(tempsRestant==temps_balle){//conditions pour balle
            deplacer_balle(&balle,snoopy,plateau,tab_coord);
            temps_balle-=1;
        };
        printf("Temps restant : %02d:%02d\n", tempsRestant / 60, tempsRestant % 60);
        printf("Appuyez sur espace pour mettre le jeu en pause.\n");
        printf("Il vous reste %d vies\n", snoopy->vie);
        printf("Il vous reste %d deplacements\n", nbr_deplacements );
        printf("Vous avez recupere %d oiseaux\n", snoopy1.nb_oiseaux);
        if (_kbhit()) {
            char touche = _getch();
            if (touche == ' ') {
                sauvegardeinit(plateau);
                menu_partie_en_cours(plateau);
                debut = time(NULL) - (120 - tempsRestant);
            } else
                deplacement(snoopy, plateau, &mouvement_effectue,touche);
            if (mouvement_effectue == 1) {
                nbr_deplacements--;
            }
            effacerEcran();
        }else{
            usleep(40000);
            effacerEcran();}
    } while ((snoopy1.nb_oiseaux < 4 && snoopy->vie > 0) && tempsRestant > 0 && nbr_deplacements > 0);

    effacerEcran();

    if (snoopy1.vie > 0 && snoopy1.nb_oiseaux >= 4) {
        debut = time(NULL) - (120 - tempsRestant);
        tempsRestant = 120 - (time(NULL) - debut);
        tempsRestant = tempsRestant * 100*3;
        printf("\n\n\n\n\n            BRAVO!\n");
        printf("\n\n\n\n\n    score : %d\n",tempsRestant);
        printf("  Vous avez reussi le niveau 3\n");
        printf("  le code pour le niveau 3 est : 6594\n");
        FILE* score;
        score = fopen("./score.txt", "w");
        if (score == NULL) {
            printf("Erreur d'ouverture");
            affichage_menu();
        }
        else {
            fprintf(score, "%d", tempsRestant);
            fclose(score);
        }
    } else {
        printf("\n\n\n\n\n     VOUS AVEZ PERDU\n");
        printf("  Ne vous inquietez pas,\n  vous pouvez recommencer\n");
    }

    sleep(3);
    affichage_menu();
}