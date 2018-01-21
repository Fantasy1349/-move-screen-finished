#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

int main()
{
    GAMEDATA gamedata;
    ICON icon;
    ROLE Doodle;
    BASE Base_G[BaseG_Num], Base_B[BaseB_Num], Base_W[BaseW_Num];

    srand( time( NULL ) );
    initialization(&gamedata, &icon);
    al_start_timer(gamedata.timer);

    PLAY_GAME(&gamedata, &icon, &Doodle, &Base_G, &Base_B, &Base_W);

}

