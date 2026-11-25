#include <allegro.h>
#include <time.h>

void initialisation_allegro();

int main()
{
    // Déclaration du pointeur sur BITMAP devant recevoir l'image
    BITMAP *image, *buffer;
    int touche;
    int x, y;
    int dep = 5; // Pas de déplacement
    int effet_actif = 1; // Activation/désactivation de l'effet de révélation
    int zone_w = 200, zone_h = 150; // Taille de la zone éclairée

    // Initialisation du hasard
    srand(time(NULL));

    // Lancer Allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Chargement de l'image
    image = load_bitmap("C:\\Users\\tomga\\CLionProjects\\exo1_2_allegro\\andromede.bmp", NULL);
    if (!image)
    {
        allegro_message("pas pu trouver/charger andromede.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Création du buffer pour le double buffering
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    // Position initiale de l'image (au centre)
    x = (SCREEN_W - image->w) / 2;
    y = (SCREEN_H - image->h) / 2;

    // Boucle interactive
    while (!key[KEY_ESC])
    {
        if (keypressed())
        {
            touche = readkey();
            touche = touche >> 8;

            if (touche == KEY_SPACE)
            {
                x = rand() % (SCREEN_W - image->w);
                y = rand() % (SCREEN_H - image->h);
            }
            if (touche == KEY_UP)
            {
                if (y - dep >= 0)
                    y -= dep;
            }
            if (touche == KEY_DOWN)
            {
                if (y + image->h + dep <= SCREEN_H)
                    y += dep;
            }
            if (touche == KEY_LEFT)
            {
                x -= dep;
                if (x + image->w <= 0)
                    x = SCREEN_W;
            }
            if (touche == KEY_RIGHT)
            {
                x += dep;
                if (x >= SCREEN_W)
                    x = -image->w;
            }
            if (touche == KEY_ENTER)
            {
                x = (SCREEN_W - image->w) / 2;
                y = (SCREEN_H - image->h) / 2;
            }
            if (touche == KEY_E) // Activer/désactiver l'effet
            {
                effet_actif = !effet_actif;
            }
        }

        // Effacer le buffer
        clear_bitmap(buffer);

        // Dessiner l'image complète dans le buffer
        blit(image, buffer, 0, 0, x, y, image->w, image->h);

        if (effet_actif)
        {
            // Coordonées de la zone éclairée centrée sur la souris
            int mx = mouse_x - zone_w / 2;
            int my = mouse_y - zone_h / 2;

            // Dessiner un rectangle noir semi-transparent partout sauf sur la zone éclairée
            rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, makecol(0, 0, 0));
            masked_blit(image, buffer, mx - x, my - y, mx, my, zone_w, zone_h);
        }

        // Afficher le buffer sur l'écran
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    // Libération des ressources
    destroy_bitmap(image);
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
