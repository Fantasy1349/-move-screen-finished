#include "FunctionDef.h"
#include "Define.h"

void main_menu(ALLEGRO_FONT *Font, ALLEGRO_FONT *Font1){
    al_draw_textf(Font1, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/4, ALLEGRO_ALIGN_LEFT, "PLAY");
    al_draw_rectangle(DISPLAY_WIDTH/2 -5, DISPLAY_HEIGHT/4 -5, DISPLAY_WIDTH/2 +160, DISPLAY_HEIGHT/4 +100, al_map_rgb(0, 0, 0), 2.5);

    al_draw_textf(Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2.5+25, ALLEGRO_ALIGN_RIGHT, "HIGH SCORE");
    al_draw_rectangle(DISPLAY_WIDTH/2 -180, DISPLAY_HEIGHT/2.5 +20, DISPLAY_WIDTH/2 +5, DISPLAY_HEIGHT/2.5 +70, al_map_rgb(0, 0, 0), 2.5);

    al_draw_textf(Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2 -25, DISPLAY_HEIGHT/2 +45, ALLEGRO_ALIGN_LEFT, "HELP");
    al_draw_rectangle(DISPLAY_WIDTH/2 -30, DISPLAY_HEIGHT/2 +40, DISPLAY_WIDTH/2 +50, DISPLAY_HEIGHT/2 +88 , al_map_rgb(0, 0, 0), 2.5);
}

int move_choice(ALLEGRO_EVENT events){
    int choice = 1;
    if(events.keyboard.keycode == ALLEGRO_KEY_DOWN) choice ++;
    if(events.keyboard.keycode == ALLEGRO_KEY_UP) choice --;

    if(choice > 3) choice = choice -3;
    if(choice < 1) choice = choice +3;

    return choice;
}

