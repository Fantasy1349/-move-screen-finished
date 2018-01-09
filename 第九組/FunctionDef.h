#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED
#include "Define.h"

typedef struct Role{
int X;
int Y;
int direction;//1->jump down  0->jump up
double base;

int state_U;
int state_D;
int state_R;
int state_L;
} ROLE;

typedef struct Bases{
int X;
int Y;
} BASE;
/*----------------Doodle-----------------*/
void Doodle_Moving(ROLE *Doodle);
void STOP(ALLEGRO_EVENT events,ROLE *Doodle);
void Change_State(ALLEGRO_EVENT events,ROLE *Doodle);
void Doodle_jump(ROLE *Doodle,BASE *Base_G, int *Score);
void Plat_jump(ROLE *Doodle,BASE *Base_G);
void page_move(ROLE *Doodle,BASE Base_G[BaseG_Num], int *Score);
void initilaze_coordinate(ROLE *Doodle,BASE Base_G[BaseG_Num]);
void initialization();
void main_menu(ALLEGRO_FONT *Font, ALLEGRO_FONT *Font1);
/*---------------------------------------*/
#endif // MYHEADER_H_INCLUDED
