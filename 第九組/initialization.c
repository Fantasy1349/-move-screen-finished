#include "Define.h"

void initialization(){
/*for initialize the tool that using in this project*/
/*Input Variable : void*/
/*Output : void*/
    al_init(); //initialize Allegro
    al_install_keyboard(); // install the keyboard for Allegro to use
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_mouse();
}



