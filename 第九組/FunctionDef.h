#define MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED
#include "Define.h"
#include "StructDef.h"

/* initialization.c*/
void initialization(GAMEDATA *gamedata, ICON *icon);

//void Game_Start(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE Base_G[], BASE Base_B[], BASE Base_W[]);

void Doodle_jump(GAMEDATA *gamedata, int Plat_Num, BASE *Base, ROLE *Doodle,BASE Prop[Prop_Num]);
void Plat_jump(int Plat_Num, BASE Base[], ROLE *Doodle, GAMEDATA *gamedata);
void Plat_move(BASE Base[],BASE Prop[Prop_Num]);
void page_move(GAMEDATA *gamedata, int Plat_Num,  BASE Base[], ROLE *Doodle,BASE Prop[Prop_Num]);
void creat_Prop(GAMEDATA *gamedata,BASE Prop[Prop_Num]);
void Prop_jump(GAMEDATA *gamedata,ROLE *Doodle,BASE Prop[Prop_Num]);
void initilaze_coordinate(int Plat_Num,  BASE Base[], ROLE *Doodle,BASE Prop[Prop_Num]);
void initilaze_level(ROLE *Doodle, BASE Base[], int Plat_Num,BASE Prop[Prop_Num]);
void int_stoptime(GAMEDATA *gamedata);

void Change_State(GAMEDATA *gamedata, ROLE *Doodle);
void STOP(GAMEDATA *gamedata, ROLE *Doodle);
void Doodle_Moving(ROLE *Doodle);


void menu(GAMEDATA *gamedata, ICON *icon);
void Rule(GAMEDATA *gamedata, ICON*icon);
void text_menu(GAMEDATA *gamedata, ICON*icon);
void text_Rule(GAMEDATA *gamedata, ICON*icon);

void PLAY_GAME(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W,BASE *Prop);
void Game_Start(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W,BASE *Prop);

void Game_Menu(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W);


void Enter_Name(GAMEDATA *gamedata, ICON *icon);
void Rank_Result(GAMEDATA *gamedata);
void Leaderboards(GAMEDATA *gamedata, ICON *icon);
void text_LeaderBroads(GAMEDATA *gamedata, ICON *icon);

void Destroy(GAMEDATA *gamedata, ICON *icon);
