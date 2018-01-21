#include "FunctionDef.h"
#include "Define.h"

void Change_State(ALLEGRO_EVENT events,ROLE *Doodle,int *picture_dir){
    if (events.keyboard.keycode == ALLEGRO_KEY_LEFT)  {
        Doodle->state_L = 1;
        *picture_dir = Left;
    }
    if (events.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        Doodle->state_R = 1;
        *picture_dir = Right;
    }
}

void STOP(ALLEGRO_EVENT events,ROLE *Doodle){
    if (events.keyboard.keycode == ALLEGRO_KEY_LEFT)  Doodle->state_L = 0;
    if (events.keyboard.keycode == ALLEGRO_KEY_RIGHT) Doodle->state_R = 0;
}

void Doodle_Moving(ROLE *Doodle){
/*Using Keyboard to control Doodle, x-coordinate*/
/*Input Variable : Structure Pointer Role*/
/*Output : void*/
    switch ( Doodle->state_L ){
            case 1:
                Doodle->X -= 3;
                break;
            case 0:
                Doodle->X  = Doodle->X;
                break;
    }
           switch ( Doodle->state_R ){
            case 1:
                Doodle->X += 3;
                break;
            case 0:
                Doodle->X = Doodle->X;
                break;
    }
    if (Doodle->X < 1) Doodle->X = 519;
    if (Doodle->X + 80 > DISPLAY_WIDTH) Doodle->X = 1;
}
