#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED
#include "Define.h"

typedef struct Role{
int X;
int Y;
int direction;//1->jump down  0->jump up
double base;

int state_S;
int state_U;
int state_D;
int state_R;
int state_L;
} ROLE;

typedef struct Bases{
int X;
int Y;
int HP;
int direction;
} BASE;
/*----------------Doodle-----------------*/
void Doodle_Moving(ROLE *Doodle);
void STOP(ALLEGRO_EVENT events,ROLE *Doodle);
void Change_State(ALLEGRO_EVENT events,ROLE *Doodle,int *picture_dir);
void Doodle_jump(ROLE *Doodle,BASE *Base_G, int *Score,int Plat_Num,BASE Prop[Prop_Num]);
void Plat_jump(ROLE *Doodle,BASE *Base_G,int Plat_Num,int level);
void Plat_move(BASE Base_B[BaseG_Num],BASE Prop[Prop_Num]);
void page_move(ROLE *Doodle,BASE Base_G[BaseG_Num], int *Score,int Plat_Num,BASE Prop[Prop_Num]);
void creat_Prop(int *Score,BASE Prop[Prop_Num],int level);
void Prop_jump(ROLE *Doodle,BASE Prop[Prop_Num],int level);
void initilaze_coordinate(ROLE *Doodle,BASE Base_G[BaseG_Num],int Plat_Num,BASE Prop[Prop_Num]);
void initilaze_level(ROLE *Doodle,BASE Base_B[],int Plat_Num,BASE Prop[Prop_Num]);
void initialization();
void main_menu(ALLEGRO_FONT *Font, ALLEGRO_FONT *Font1);
/*---------------------------------------*/
#endif // MYHEADER_H_INCLUDED
