    #include<allegro.h>
    #include <stdio.H>
    #define LARGEUR 640
    #define HAUTEUR 480
    #define RAQUETTE_LARGEUR 10
    #define RAQUETTE_HAUTEUR 60
    #define BALLE_TAILLE 10
    typedef struct {
        int x;
        int y;
        int vitesse_x;
        int vitesse_y;
    } Balle;
    typedef struct {
        int gauche_y;
        int droite_y;
    } Raquettes;
    typedef struct {
        int gauche;
        int droite;
    } Score;
    BITMAP* buffer;
    void init() {
        allegro_init();
        install_keyboard();
        set_color_depth(32);
        set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR, HAUTEUR, 0, 0);
        buffer = create_bitmap(LARGEUR, HAUTEUR);
    }
    void draw_score(Score *score) {// fonction qui affiche les scores sur le jeu
        textprintf_ex(buffer, font, LARGEUR / 2 - 25, 10, makecol(0, 0, 255), -1, "%d", score->gauche); // Score de gauche en bleu
        textprintf_ex(buffer, font, LARGEUR / 2-10, 10, makecol(255,255,255), -1, "-"); //tiret du milien entre les deux scores
        textprintf_ex(buffer, font, LARGEUR / 2+5 , 10, makecol(255, 0, 0), -1, "%d", score->droite); // Score de droite en rouge
    }
    void draw_game(Balle *balle, Raquettes *raquettes, Score *score) {
        clear_to_color(buffer, makecol(0, 0, 0));
        // dessiner la balle
        circlefill(buffer, balle->x, balle->y, BALLE_TAILLE, makecol(255, 255, 255));
        // dessiner les raquettes
        rectfill(buffer, 0, raquettes->gauche_y, RAQUETTE_LARGEUR, raquettes->gauche_y + RAQUETTE_HAUTEUR, makecol(0, 0, 255));
        rectfill(buffer, LARGEUR - RAQUETTE_LARGEUR, raquettes->droite_y, LARGEUR, raquettes->droite_y + RAQUETTE_HAUTEUR, makecol(255, 0, 0));
        // dessiner le score
        draw_score(score);
        // lignes au centre avec des points
        for (int i = 20; i < HAUTEUR; i += 20) {
            if (i % 40 == 0) {
                rectfill(buffer, LARGEUR/2 - 6, i, LARGEUR/2 - 6, i + 10, makecol(255, 255, 255));  // dessiner un espace
            } else {
                rectfill(buffer, LARGEUR/2 - 6, i, LARGEUR/2 - 6, i + 10, makecol(255, 255, 255));  // dessiner un espace
            }
        }
        blit(buffer, screen, 0, 0, 0, 0, LARGEUR, HAUTEUR);
    }
    void update_position_ball(Balle *balle, Raquettes *raquettes, Score *score) {
        // mise jour de la position de la balle en fonction de sa vitesse
        balle->x += balle->vitesse_x;
        balle->y += balle->vitesse_y;
        // collisions entre balle et raquettes et balle et ecran
        if (balle->y <= 0 || balle->y >= HAUTEUR) {
            balle->vitesse_y = -balle->vitesse_y;
        }
        if (balle->x <= RAQUETTE_LARGEUR && balle->y >= raquettes->gauche_y && balle->y <= raquettes->gauche_y + RAQUETTE_HAUTEUR) {
            printf("Collision avec la raquette gauche\n"); //messages de debug
            printf("Balle: x = %d, y = %d\n", balle->x, balle->y);//messages de debug
            printf("Raquette gauche: y = %d\n", raquettes->gauche_y);//messages de debug
            balle->vitesse_x = -balle->vitesse_x;
        }
        if (balle->x >= LARGEUR - RAQUETTE_LARGEUR && balle->y >= raquettes->droite_y && balle->y <= raquettes->droite_y + RAQUETTE_HAUTEUR) {
            printf("Collision avec la raquette droite\n");//messages de debug
            printf("Balle: x = %d, y = %d\n", balle->x, balle->y);//messages de debug
            printf("Raquette droite: y = %d\n", raquettes->droite_y);//messages de debug
            balle->vitesse_x = -balle->vitesse_x;
        }
        // mise a jour score
        if (balle->x <= 0) {
            score->droite++;
            balle->x = LARGEUR / 2;
            balle->y = HAUTEUR / 2;
        }
        if (balle->x >= LARGEUR) {
            score->gauche++;
            balle->x = LARGEUR / 2;
            balle->y = HAUTEUR / 2;
        }
    }
    void update_raquettes(Raquettes *raquettes) {
        // mise à jour position raquette gauche
        if (key[KEY_W]) {
            raquettes->gauche_y -= 5;
        }
        else if (key[KEY_S]) {
            raquettes->gauche_y += 5;
        }
        //mise a jour position raquette droite
        else if (key[KEY_UP]) {
            raquettes->droite_y -= 5;
        }
        else if (key[KEY_DOWN]) {
            raquettes->droite_y += 5;
        }
        // condition pour que raquettes sortent pas ecran
        if (raquettes->gauche_y < 0) {
            raquettes->gauche_y = 0;
        }
        if (raquettes->gauche_y > HAUTEUR - RAQUETTE_HAUTEUR) {
            raquettes->gauche_y = HAUTEUR - RAQUETTE_HAUTEUR;
        }
        if (raquettes->droite_y < 0) {
            raquettes->droite_y = 0;
        }
        if (raquettes->droite_y > HAUTEUR - RAQUETTE_HAUTEUR) {
            raquettes->droite_y = HAUTEUR - RAQUETTE_HAUTEUR;
        }
    }


    int main() {
        Balle balle = {LARGEUR / 2, HAUTEUR / 2, 4, 4};
        Raquettes raquettes = {HAUTEUR / 2 - RAQUETTE_HAUTEUR / 2, HAUTEUR / 2 - RAQUETTE_HAUTEUR / 2};
        Score score = {0, 0};
        init();

        // Affichage du menu titre
        textout_centre_ex(screen, font, "THE FRENCH PONG", LARGEUR / 2, HAUTEUR / 2 - 20, makecol(255, 255, 255), -1);
        textout_centre_ex(screen, font, "Appuyez sur une touche pour jouer", LARGEUR / 2, HAUTEUR / 2 + 20, makecol(255, 255, 255), -1);
        while (!keypressed()) {
            rest(1);
        }
        clear_bitmap(screen);

        while (!key[KEY_ESC]) {
            update_position_ball(&balle, &raquettes, &score);
            update_raquettes(&raquettes);
            draw_game(&balle, &raquettes, &score);
            rest(10);
        }

        allegro_exit();
        return 0;
    }
    END_OF_MAIN()
