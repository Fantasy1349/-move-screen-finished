#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"


void Change_State(GAMEDATA *gamedata, ROLE *Doodle){
    if (gamedata->events.keyboard.keycode == ALLEGRO_KEY_LEFT)  {
        Doodle->state_L = 1;
        gamedata->picture_dir = Left;
    }
    if (gamedata->events.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        Doodle->state_R = 1;
        gamedata->picture_dir = Right;
    }
}

void STOP(GAMEDATA *gamedata, ROLE *Doodle){
    if (gamedata->events.keyboard.keycode == ALLEGRO_KEY_LEFT)  Doodle->state_L = 0;
    if (gamedata->events.keyboard.keycode == ALLEGRO_KEY_RIGHT) Doodle->state_R = 0;
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
    if (Doodle->X < 0) Doodle->X = DISPLAY_WIDTH-DoodleW;
    if (Doodle->X + DoodleW > DISPLAY_WIDTH) Doodle->X = 1;
}
