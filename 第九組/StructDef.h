#ifndef STRUCTDED_H_INCLUDED
#define STRUCTDED_H_INCLUDED
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
    int HP;
    int direction;
} BASE;

typedef struct Rank{
    char NAME[30];
    int score ;
} RANK;

typedef struct GameData{
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE* event_queue; // create event queue
    ALLEGRO_EVENT events;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *Font; // declare Font file
    ALLEGRO_FONT *Font0;
    ALLEGRO_FONT *Font1;
    ALLEGRO_FONT *Font2;
    ALLEGRO_FONT *Font3; // declare Font file
    ALLEGRO_FONT *Font4;

    RANK rank1[20];

//	ROLE Doodle;
//    BASE Base_G[BaseG_Num];
//    BASE Base_B[BaseB_Num];
//    BASE Base_W[BaseW_Num];

	float FPS;
    bool run;
    bool quit;
    bool game;

    int level;
    int level1_stoptime,level2_stoptime, level3_stoptime;
    int Score, FinalScore;
	int select;
	int picture_dir;
	int move_hight;

} GAMEDATA;

typedef struct Icon{
    ALLEGRO_BITMAP *MenuBackground;
    ALLEGRO_BITMAP *BackGround;
    ALLEGRO_BITMAP *BackGround2;
    ALLEGRO_BITMAP *BackGround3;
    ALLEGRO_BITMAP *GameStart;
	ALLEGRO_BITMAP *SelectArrow;
	ALLEGRO_BITMAP *NoneSelectArrow;
    ALLEGRO_BITMAP *GameOver ;
    ALLEGRO_BITMAP *Level2 ;
    ALLEGRO_BITMAP *Level3 ;
    ALLEGRO_BITMAP *doodle ;
    ALLEGRO_BITMAP *baseG ;
    ALLEGRO_BITMAP *baseB ;
    ALLEGRO_BITMAP *baseW ;
    ALLEGRO_BITMAP *Menu ;
    ALLEGRO_SAMPLE *background;
} ICON;

#endif // STRUCTDED_H_INCLUDED
