#include "menu.h"
void elements_decors(char tab[N][R]) {
    int i, j;
    /// Il manque un cas epour les case vide
    tab[0][0]=0x1;    /// smiley pour bloc cassable
    tab[1][0]=0x1a;   ///flèche vers la droite pour bloc poussable
    tab[2][0]=0xC;    /// signe feminin pour snoopy
    tab[3][0]=0x3;    /// coeur pour les vies
    tab[4][0]=0x6;    ///pique pour bloc piégé
    tab[5][0]=0xf;    ///soleil pour balle
    tab[6][0]=0x1b;   ///flèche vers la gauche pour tapis roulant
    tab[7][0]=0x1c;   ///angle droit pour bloc de disparition/apparition
    tab[8][0]=0x1d;   ///double flèche bloc incassable
    tab[9][0]=0xe;    ///note de musique pour les oiseaux
    ///for (i = 0; i < 10; i++) {     ///Double boucle qui balaye le tableau et qui test le programme
    ///printf("%c", tab[3][0]);
    ///sleep(5);
    ///printf("\n");
    ///}
}
