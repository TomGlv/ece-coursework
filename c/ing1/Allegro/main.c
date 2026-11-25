#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void initialisation_allegro() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 600, 0, 0) != 0) {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

int main() {
    initialisation_allegro();
    clear_to_color(screen, makecol(255,255,255));
    BITMAP *une_image;
    BITMAP *une_image2;
    BITMAP *une_image3;
    BITMAP *une_image4;
    BITMAP *une_image5;
    BITMAP *une_image6;
    BITMAP *une_image7;
    BITMAP *une_image8;
    BITMAP *une_image9;
    BITMAP *une_image10;

    while (!key[KEY_0]) {
        une_image = load_bitmap("ours1.bmp", NULL);
        if (!une_image) {
            allegro_message("Erreur lors du chargement de l'image ours1.bmp");
            break;
        }
        blit(load_bitmap("ours1.bmp", NULL), screen, 0, 0, 100, 0, une_image->w, une_image->h);
        rest(100);
        destroy_bitmap(une_image);

        une_image2 = load_bitmap("ours2.bmp", NULL);
        if (!une_image2) {
            allegro_message("Erreur lors du chargement de l'image ours2.bmp");
            break;
        }
        blit(une_image2, screen, 0, 0, 100, 0, une_image2->w, une_image2->h);
        rest(100);
        destroy_bitmap(une_image2);

        une_image3 = load_bitmap("ours3.bmp", NULL);
        if (!une_image3) {
            allegro_message("Erreur lors du chargement de l'image ours3.bmp");
            break;
        }
        blit(une_image3, screen, 0, 0, 100, 0, une_image3->w, une_image3->h);
        rest(100);
        destroy_bitmap(une_image3);

        une_image4 = load_bitmap("ours4.bmp", NULL);
        if (!une_image4) {
            allegro_message("Erreur lors du chargement de l'image ours4.bmp");
            break;
        }
        blit(une_image4, screen, 0, 0, 100, 0, une_image4->w, une_image4->h);
        rest(100);
        destroy_bitmap(une_image4);

        une_image5 = load_bitmap("ours5.bmp", NULL);
        if (!une_image5) {
            allegro_message("Erreur lors du chargement de l'image ours5.bmp");
            break;
        }
        blit(une_image5, screen, 0, 0, 100, 0, une_image5->w, une_image5->h);
        rest(50);
        destroy_bitmap(une_image5);

        une_image6 = load_bitmap("ours6.bmp", NULL);
        if (!une_image6) {
            allegro_message("Erreur lors du chargement de l'image ours6.bmp");
            break;
        }
        blit(une_image6, screen, 0, 0, 100, 0, une_image6->w, une_image6->h);
        rest(50);
        destroy_bitmap(une_image6);

        une_image7 = load_bitmap("ours6.bmp", NULL);
        if (!une_image7) {
            allegro_message("Erreur lors du chargement de l'image ours7.bmp");
            break;
        }
        blit(une_image7, screen, 0, 0, 100, 0, une_image7->w, une_image7->h);
        rest(50);
        destroy_bitmap(une_image7);

        une_image8 = load_bitmap("ours8.bmp", NULL);
        if (!une_image8) {
            allegro_message("Erreur lors du chargement de l'image ours8.bmp");
            break;
        }
        blit(une_image8, screen, 0, 0, 100, 0, une_image8->w, une_image8->h);
        rest(50);
        destroy_bitmap(une_image8);

        une_image9 = load_bitmap("ours8.bmp", NULL);
        if (!une_image9) {
            allegro_message("Erreur lors du chargement de l'image ours9.bmp");
            break;
        }
        blit(une_image9, screen, 0, 0, 100, 0, une_image9->w, une_image9->h);
        rest(50);
        destroy_bitmap(une_image9);

        une_image10 = load_bitmap("ours10.bmp", NULL);
        if (!une_image10) {
            allegro_message("Erreur lors du chargement de l'image ours10.bmp");
            break;
        }
        blit(une_image10, screen, 0, 0, 100, 0, une_image10->w, une_image10->h);
        rest(50);
        destroy_bitmap(une_image10);




        rest(50);
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();
