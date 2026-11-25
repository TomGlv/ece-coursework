#include <allegro.h>

int main() {
    // Initialisation d'Allegro
    allegro_init();
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL);

    // Charger le fichier audio
    SAMPLE *musique = load_wav("C:\\Users\\tomga\\CLionProjects\\musique allegro\\the-cave.wav");
    if (!musique) {
        allegro_message("Erreur de chargement du fichier WAV !");
        return 1;
    }

    // Jouer la musique
    play_sample(musique, 255, 128, 1000, 0); // volume, balance, fréquence, boucle

    // Attendre une touche pour quitter
    readkey();

    // Nettoyage
    destroy_sample(musique);
    return 0;
}
END_OF_MAIN();
