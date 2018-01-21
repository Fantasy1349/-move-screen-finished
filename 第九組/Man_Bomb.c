#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

int main()
{
    GAMEDATA gamedata;
    ICON icon;
    ROLE Doodle;
    BASE Base_G[BaseG_Num];
    BASE Base_B[BaseB_Num];
    BASE Base_W[BaseW_Num];

    int selection = 1;

    initialization(&gamedata, &icon);

    srand( time( NULL ) );


    al_start_timer(gamedata.timer);

    menu(&gamedata, &icon);

    gamedata.run = 1;
    Game_Start(&gamedata, &icon, &Doodle, &Base_G, &Base_B, &Base_W);

    Enter_Name(&gamedata);
    Leaderboards(&gamedata, &icon);


//    al_draw_bitmap(icon.GameOver, 0, 0, 0);//show Game Over bitmap
//    al_rest(1);
//    al_flip_display(); // Wait for the beginning of a vertical retrace.
//    al_rest(0.5);

    al_destroy_bitmap(icon.BackGround); // destroy the ball bitmap
    al_destroy_bitmap(icon.GameOver);
    al_destroy_bitmap(icon.doodle);
    al_destroy_bitmap(icon.baseG);


}
