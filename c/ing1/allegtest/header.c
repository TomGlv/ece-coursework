#include <allegro.h>
#include "header.h"
#include <stdio.h>
#include <stdlib.h>


#define CARRELAGE 1
#define PLANCHE 0
#define MARMITE 2
#define RIZ 3
#define SAUMON 4
#define FARINE 5
#define VIANDE 6
#define ASSIETTE 7
#define POUBELLE 8
#define SORTIE_CUISINE 9
#define VIANDE_CUITE 10
#define SUSHI 11
#define OEUF 12
#define LEGUMES 13
#define NOUILLES 14
#define RAMEN 15


ObjetList* creerObjetList(int capacite) {
    ObjetList *liste = (ObjetList*)malloc(sizeof(ObjetList));
    liste->objets = (Objet*)malloc(capacite * sizeof(Objet));
    liste->taille = 0;
    liste->capacite = capacite;
    return liste;
}

void Aliments(ObjetList *liste, int type, int x, int y, BITMAP *sprite, int dispo) {
    if (liste->taille == liste->capacite) {
        liste->capacite *= 2;
        liste->objets = (Objet*)realloc(liste->objets, liste->capacite * sizeof(Objet));
    }
    Objet obj;
    obj.type = type;
    obj.x = x;
    obj.y = y;
    obj.sprite = sprite;
    obj.dispo = dispo;
    liste->objets[liste->taille++] = obj;
}

void retirerAliment(ObjetList *liste, int index) {
    if (index >= 0 && index < liste->taille) {
        for (int i = index; i < liste->taille - 1; i++) {
            liste->objets[i] = liste->objets[i + 1];
        }
        liste->taille--;
    }
}




BITMAP* charger_bitmap(const char* fichier) {
    BITMAP* bmp = load_bitmap(fichier, NULL);
    if (!bmp) {
        allegro_message("Failed to load %s.", fichier);
        allegro_exit();
        exit(-1);
    }
    return bmp;
}

void chargerNiveau(int matrice[12][20], const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nomFichier);
        exit(1);
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 20; j++) {
            fscanf(fichier, "%d", &matrice[i][j]);
        }
    }

    fclose(fichier);
}

void loadNiveau(const char *nomFichier, BITMAP *buffer, ObjetList *listeObjets, BITMAP *sprites[16]) {
    int matrice[12][20];
    chargerNiveau(matrice, nomFichier);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 20; j++) {
            int x = j * 40;
            int y = i * 40;
            int caseType = matrice[i][j];
            if (sprites[caseType]) {
                stretch_sprite(buffer, sprites[caseType], x, y, 40, 40);
            }
            if (caseType == RIZ || caseType == SAUMON || caseType == FARINE || caseType == VIANDE || caseType == ASSIETTE || caseType == OEUF || caseType == LEGUMES) {
                Aliments(listeObjets, caseType, x, y, sprites[caseType], 1);
            }
        }
    }
}

void afficherNiveau(int matrice[12][20], BITMAP *buffer, BITMAP *sprites[16], ObjetList *listeObjets) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 20; j++) {
            int x = j * 40;
            int y = i * 40;
            int caseType = matrice[i][j];
            if (sprites[caseType]) {
                stretch_sprite(buffer, sprites[caseType], x, y, 40, 40);
            }
        }
    }

    for (int i = 0; i < listeObjets->taille; i++) {
        Objet obj = listeObjets->objets[i];
        stretch_sprite(buffer, obj.sprite, obj.x, obj.y, 40, 40);
    }
}

int testDeplacement(int matrice[12][20], int x, int y) {
    int indexX = x / 40;
    int indexY = y / 40;
    return matrice[indexY][indexX] == CARRELAGE;
}

int peutPrendre(ObjetList *listeObjets, int x, int y, int direction) {
    int indexX = x / 40;
    int indexY = y / 40;


    switch (direction) {
        case 0: indexY -= 1; break;
        case 1: indexY += 1; break;
        case 2: indexX -= 1; break;
        case 3: indexX += 1; break;
    }

    for (int i = 0; i < listeObjets->taille; i++) {
        if (listeObjets->objets[i].x == indexX * 40 && listeObjets->objets[i].y == indexY * 40) {
            return i;
        }
    }
    return -1;
}

void prendreAliment(ObjetList *listeObjets, int *objet, int index) {
    *objet = listeObjets->objets[index].type;
    if (!listeObjets->objets[index].dispo) {
        retirerAliment(listeObjets, index);
    }
}

int testPose(int matrice[12][20], int x, int y, int direction) {
    int indexX = x / 40;
    int indexY = y / 40;


    switch (direction) {
        case 0: indexY -= 1; break;
        case 1: indexY += 1; break;
        case 2: indexX -= 1; break;
        case 3: indexX += 1; break;
    }

    return matrice[indexY][indexX] == PLANCHE;
}

void poserAliment(ObjetList *listeObjets, int objet, int x, int y, BITMAP *sprite, int direction, int matrice[12][20], BITMAP *spriteSushi, BITMAP *spriteNouilles, BITMAP *spriteRamen) {
    int indexX = x / 40;
    int indexY = y / 40;

    switch (direction) {
        case 0: indexY -= 1; break;
        case 1: indexY += 1; break;
        case 2: indexX -= 1; break;
        case 3: indexX += 1; break;
    }


    if (matrice[indexY][indexX] == POUBELLE) {
        return;
    }


    int riz = 0, saumon = 0, assiette = 0, farine = 0, oeuf = 0, nouilles = 0, legumes = 0;
    for (int i = 0; i < listeObjets->taille; i++) {
        if (listeObjets->objets[i].x == indexX * 40 && listeObjets->objets[i].y == indexY * 40) {
            if (listeObjets->objets[i].type == RIZ) riz = 1;
            if (listeObjets->objets[i].type == SAUMON) saumon = 1;
            if (listeObjets->objets[i].type == ASSIETTE) assiette = 1;
            if (listeObjets->objets[i].type == FARINE) farine = 1;
            if (listeObjets->objets[i].type == OEUF) oeuf = 1;
            if (listeObjets->objets[i].type == NOUILLES) nouilles = 1;
            if (listeObjets->objets[i].type == RAMEN) legumes = 1;
        }
    }


    if (objet == RIZ) riz = 1;
    if (objet == SAUMON) saumon= 1;
    if (objet == ASSIETTE) assiette = 1;
    if (objet == FARINE) farine = 1;
    if (objet == OEUF) oeuf = 1;
    if (objet == NOUILLES) nouilles = 1;
    if (objet == LEGUMES) legumes = 1;


    if (riz && saumon && assiette) {
        for (int i = listeObjets->taille - 1; i >= 0; i--) {
            if (listeObjets->objets[i].x == indexX * 40 && listeObjets->objets[i].y == indexY * 40 &&
                (listeObjets->objets[i].type == RIZ || listeObjets->objets[i].type == SAUMON || listeObjets->objets[i].type == ASSIETTE)) {
                retirerAliment(listeObjets, i);
            }
        }
        Aliments(listeObjets, SUSHI, indexX * 40, indexY * 40, spriteSushi, 0);
    }

    else if (oeuf && farine && assiette) {
        for (int i = listeObjets->taille - 1; i >= 0; i--) {
            if (listeObjets->objets[i].x == indexX * 40 && listeObjets->objets[i].y == indexY * 40 &&
                (listeObjets->objets[i].type == FARINE || listeObjets->objets[i].type == OEUF || listeObjets->objets[i].type == ASSIETTE)) {
                retirerAliment(listeObjets, i);
            }
        }
        Aliments(listeObjets, NOUILLES, indexX * 40, indexY * 40, spriteNouilles, 0);
    }

    else if (nouilles && legumes) {
        for (int i = listeObjets->taille - 1; i >= 0; i--) {
            if (listeObjets->objets[i].x == indexX * 40 && listeObjets->objets[i].y == indexY * 40 &&
                (listeObjets->objets[i].type == NOUILLES || listeObjets->objets[i].type == LEGUMES)) {
                retirerAliment(listeObjets, i);
            }
        }
        Aliments(listeObjets, RAMEN, indexX * 40, indexY * 40, spriteRamen, 0);
    } else {
        Aliments(listeObjets, objet, indexX * 40, indexY * 40, sprite, 0);
    }
}

void updateCharacter(int *x, int *y, BITMAP **currentSprite, BITMAP *spriteRight, BITMAP *spriteLeft, BITMAP *spriteUp, BITMAP *spriteDown, int keyRight, int keyLeft, int keyUp, int keyDown, int keyTake, int matrice[12][20], int *objetPorte, ObjetList *listeObjets, BITMAP *sprites[16], int *direction, BITMAP *spriteTomateMozzarella, BITMAP *spritePates, BITMAP *spritePatesSaumon) {
    if (key[keyRight]) {
        int newX = *x + 5;
        if (newX < 800 - 50 && testDeplacement(matrice, newX, *y)) {
            *currentSprite = spriteRight;
            *x = newX;
            *direction = 3;
        }
    }
    if (key[keyLeft]) {
        int newX = *x - 5;
        if (newX >= 0 && testDeplacement(matrice, newX, *y)) {
            *currentSprite = spriteLeft;
            *x = newX;
            *direction = 2;
        }
    }
    if (key[keyUp]) {
        int newY = *y - 5;
        if (newY >= 0 && testDeplacement(matrice, *x, newY)) {
            *currentSprite = spriteUp;
            *y = newY;
            *direction = 0;
        }
    }
    if (key[keyDown]) {
        int newY = *y + 5;
        if (newY < 530 - 40 && testDeplacement(matrice, *x, newY)) {
            *currentSprite = spriteDown;
            *y = newY;
            *direction = 1;
        }
    }

    if (key[keyTake]) {
        if (*objetPorte == 0) {
            int index = peutPrendre(listeObjets, *x, *y, *direction);
            if (index != -1) {
                prendreAliment(listeObjets, objetPorte, index);
            }
        } else {
            if (testPose(matrice, *x, *y, *direction)) {
                poserAliment(listeObjets, *objetPorte, *x, *y, sprites[*objetPorte], *direction, matrice, spriteTomateMozzarella, spritePates, spritePatesSaumon);
                *objetPorte = 0;
            }
        }
        rest(200);
    }
}




int niveau1() {
    int matrice[12][20];
    chargerNiveau(matrice, "niveau1.txt");


    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *background = charger_bitmap("fond_blanc.bmp");

    BITMAP *characterSpriteRight = charger_bitmap("player2.bmp");
    BITMAP *characterSpriteLeft = charger_bitmap("player2.bmp");
    BITMAP *characterSpriteUp = charger_bitmap("player2.bmp");
    BITMAP *characterSpriteDown = charger_bitmap("player2.bmp");
    BITMAP *currentCharacterSprite = characterSpriteDown;

    BITMAP *secondCharacterSpriteRight = charger_bitmap("player3.bmp");
    BITMAP *secondCharacterSpriteLeft = charger_bitmap("player3.bmp");
    BITMAP *secondCharacterSpriteUp = charger_bitmap("player3.bmp");
    BITMAP *secondCharacterSpriteDown = charger_bitmap("player3.bmp");
    BITMAP *currentSecondCharacterSprite = secondCharacterSpriteDown;

    BITMAP *sprites[16];
    sprites[CARRELAGE] = charger_bitmap("carrelage.bmp");
    sprites[PLANCHE] = charger_bitmap("planche.bmp");
    sprites[MARMITE] = charger_bitmap("marmite.bmp");
    sprites[RIZ] = charger_bitmap("riz.bmp");
    sprites[SAUMON] = charger_bitmap("saumon.bmp");
    sprites[FARINE] = charger_bitmap("farine.bmp");
    sprites[VIANDE] = charger_bitmap("viande.bmp");
    sprites[ASSIETTE] = charger_bitmap("assiette.bmp");
    sprites[POUBELLE] = charger_bitmap("poubelle.bmp");
    sprites[SORTIE_CUISINE] = charger_bitmap("sortie_cuisine.bmp");
    sprites[VIANDE_CUITE] = charger_bitmap("viande_cuite.bmp");
    sprites[SUSHI] = charger_bitmap("sushi.bmp");
    sprites[OEUF] = charger_bitmap("oeuf.bmp");
    sprites[LEGUMES] = charger_bitmap("legumes.bmp");
    sprites[NOUILLES] = charger_bitmap("nouilles.bmp");
    sprites[RAMEN] = charger_bitmap("ramen.bmp");

    BITMAP *spriteSushi = charger_bitmap("sushi.bmp");
    BITMAP *spriteNouilles = charger_bitmap("nouilles.bmp");
    BITMAP *spriteRamen = charger_bitmap("ramen.bmp");

    for (int i = 0; i < 16; i++) {
        if (!sprites[i]) {
            allegro_message("Failed to load sprite for tile code %d.", i);
            for (int j = 0; j < i; j++) {
                destroy_bitmap(sprites[j]);
            }
            allegro_exit();
            exit(-1);
        }
    }

    ObjetList *listeObjets = creerObjetList(10);
    loadNiveau("niveau1.txt", buffer, listeObjets, sprites);

    int x1 = 400, y1 = 300;
    int x2 = 200, y2 = 300;

    int direction1 = 1;
    int direction2 = 1;

    int objetPorte1 = 0;
    int objetPorte2 = 0;

    int timeRemaining = 180;
    int maxTime = 180;
    time_t startTime = time(NULL);

    while (!key[KEY_ESC] && timeRemaining > 0) {
        clear(buffer);

        draw_sprite(buffer, background, 0, 0);
        afficherNiveau(matrice, buffer, sprites, listeObjets);

        updateCharacter(&x1, &y1, &currentCharacterSprite, characterSpriteRight, characterSpriteLeft, characterSpriteUp, characterSpriteDown, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, KEY_L, matrice, &objetPorte1, listeObjets, sprites, &direction1, spriteSushi, spriteNouilles, spriteRamen);
        updateCharacter(&x2, &y2, &currentSecondCharacterSprite, secondCharacterSpriteRight, secondCharacterSpriteLeft, secondCharacterSpriteUp, secondCharacterSpriteDown, KEY_D, KEY_A, KEY_W, KEY_S, KEY_C, matrice, &objetPorte2, listeObjets, sprites, &direction2, spriteSushi, spriteNouilles, spriteRamen);


        stretch_sprite(buffer, currentCharacterSprite, x1, y1, 50, 40);
        stretch_sprite(buffer, currentSecondCharacterSprite, x2, y2, 50, 40);

        if (objetPorte1 != 0) {
            stretch_sprite(buffer, sprites[objetPorte1], x1 + 5, y1 - 40, 40, 40);
        }


        if (objetPorte2 != 0) {
            stretch_sprite(buffer, sprites[objetPorte2], x2 + 5, y2 - 40, 40, 40);
        }


        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        rest(10);
    }



    return 0;
}

void saisir_pseudo_j1(char *pseudoJoueur1,char *pseudoJoueur2) {
    install_keyboard();
    int pos1 = 0;
    while (!key[KEY_SPACE]) {
        textout_centre_ex(screen, font, "Quel est le pseudo du joueur 1 :", (SCREEN_W / 4), SCREEN_H / 2 - 30, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, pseudoJoueur1, (SCREEN_W / 4), SCREEN_H / 2, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, "Quel est le pseudo du joueur 2 :", (SCREEN_W / 4) + 400, SCREEN_H / 2 - 30, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, pseudoJoueur2, (SCREEN_W / 4) + 400, SCREEN_H / 2, makecol(250, 250, 250), -1);
        if (keypressed()) {
            int Pkey = readkey();
            char caractere = Pkey & 0xFF;
            if (pos1 < 255) {
                pseudoJoueur1[pos1] = caractere;
                pos1++;
                pseudoJoueur1[pos1] = '\0';
            }
        }
    }
}
void saisir_pseudo_j2(char *pseudoJoueur1,char * pseudoJoueur2) {
    int pos2 = 0;
    while (!key[KEY_SPACE]) {
        textout_centre_ex(screen, font, "Quel est le pseudo du joueur 1 :", (SCREEN_W / 4), SCREEN_H / 2 - 30, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, pseudoJoueur1, (SCREEN_W / 4), SCREEN_H / 2, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, "Quel est le pseudo du joueur 2 :", (SCREEN_W / 4) + 500, SCREEN_H / 2 - 30, makecol(250, 250, 250), -1);
        textout_centre_ex(screen, font, pseudoJoueur2, (SCREEN_W / 4) + 500, SCREEN_H / 2, makecol(250, 250, 250), -1);
        if (keypressed()) {
            int Pkey = readkey();
            char caractere = Pkey & 0xFF;
            if (pos2 < 255) {
                pseudoJoueur2[pos2] = caractere;
                pos2++;
                pseudoJoueur2[pos2] = '\0';
            }
        }
    }
}

void menu(){
    char pseudoJoueur1[256] = "";
    char pseudoJoueur2[256] = "";
    BITMAP *menu;
    menu = load_bitmap("menu_ece_cooked.bmp", NULL);
    stretch_blit(menu, screen, 0, 0, menu->w, menu->h, 0, 0, 800, 457);
    int selected_option = 0;
    int show_rules = 0;
    int game_active = 0;
    int game_finish = 0;
    while (!key[KEY_ESC]) {
        if (!game_active) {
            if (key[KEY_DOWN]) {
                selected_option = (selected_option + 1) % 3;
                rest(100);
            }
            else if (key[KEY_UP]) {
                selected_option = (selected_option - 1 + 3) % 3;
                rest(100);
            }
            else if (key[KEY_SPACE]) {
                if (selected_option == 0) {
                    rest(300);
                    clear(screen);
                    saisir_pseudo_j1(pseudoJoueur1, pseudoJoueur2);
                    rest(200);
                    saisir_pseudo_j2(pseudoJoueur1, pseudoJoueur2);
                    rest(300);
                    allegro_message("Noms des joueurs confirmés");
                    game_active = 1;
                    niveau1();
                } else if (selected_option == 1) {
                    show_rules = 1;
                } else if (selected_option == 2) {
                    game_finish = 1;
                    break;
                }
            }
        }
        if (game_active && selected_option != 2) {
            niveau1();
        } else {
            for (int i = 0; i < 3; i++) {
                int rect_color = (i == selected_option) ? 255 : 0;
                int text_color = (i == selected_option) ? 0 : 255;
                rectfill(screen, 325, 125 + i * 75, 475, 175 + i * 75, makecol(rect_color, rect_color, rect_color));
                if (i == 0) {
                    textout_centre_ex(screen, font, "Play", 400, 150, makecol(text_color, text_color, text_color), -1);
                } else if (i == 1) {
                    textout_centre_ex(screen, font, "Controls Guide", 400, 225, makecol(text_color, text_color, text_color), -1);
                } else if (i == 2) {
                    textout_centre_ex(screen, font, "Quit", 400, 300, makecol(text_color, text_color, text_color), -1);
                }
            }
        }
        if (show_rules) {
            allegro_message("Controls:\n"
                            "Player 1:\n"
                            "Up: W\n"
                            "Left: A\n"
                            "Down: S\n"
                            "Right: D\n"
                            "Player 2:\n"
                            "Up: Arrow Up\n"
                            "Left: Arrow Left\n"
                            "Down: Arrow Down\n"
                            "Right: Arrow Right\n"
                            "Interact: Space (Both Players)");
            show_rules = 0;
        }

        rest(80);
    }
}


END_OF_FUNCTION()