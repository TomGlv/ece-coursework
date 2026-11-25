#include <stdio.h>
#include <allegro.h>

int main() {
    allegro_init();
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0){
// message et sortie de prog. si échec
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *buffer;
    buffer = load_bitmap("carte2.bmp", NULL);
    ///BORDURES///

    int x1_bord = 250;
    int x2_bord = 550;

    ///Raquette///
    int R = 10;
    int x = 350;
    int y = 580;

    ///Balle///
    int etat = 0;
    int xb = 400;
    int yb = 300;

    ///Boucle du jeu
    while (!key[KEY_ESC]) {
        clear(buffer);
        rectfill(buffer, x1_bord, 0, x1_bord + 5, 600, makecol(255, 255, 255));
        rectfill(buffer, x2_bord, 0, x2_bord + 5, 600, makecol(255, 255, 255));
        rectfill(buffer, x, y, x + 50, y+5, makecol(255,255,255));
        circlefill(buffer, xb, yb, 5, makecol(255, 255, 255));
        if ((key[KEY_D])&&(x + 50 < x2_bord)){
            x = x + R;
            key[KEY_D] = !key[KEY_D];

        }
        if ((key[KEY_A]) &&(x > x1_bord)){
            x = x - R;
            key[KEY_A] = !key[KEY_A];
        }
        if (etat == 0){
            yb= yb + 2;
            rest(5);
        }
        if(etat == 1){
            yb = yb-2;
            rest(5);
        }
        if(etat == 2){
            yb = yb-2;
            xb=xb - 2;
            rest(5);
        }
        if(etat == 3){
            yb = yb-2;
            xb= xb+2;
            rest(5 );
        }
        if ( ((yb == y) && (x+15<xb)) && (xb<x+35))  {
            etat = 1;
        }
        if ( ((yb == y) && (x < xb))&& (xb < x + 15) ){
            etat = 2;
        }
        if ( ((yb == y) && (x+35 < xb))&& (xb < x + 50) ){
            etat = 3;
        }
        if ((xb == x1_bord)&&(etat == 2)) {
            etat = 3;
        }
        if ((xb == x2_bord)&&(etat == 3)) {
            etat = 2;
        }
        blit(buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
    }
    return 0;
}END_OF_MAIN();