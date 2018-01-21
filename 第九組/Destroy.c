<<<<<<< HEAD
#define MYHEADER_H_INCLUDED
#include "Define.h"
#include "StructDef.h"
void Destroy(GAMEDATA *gamedata, ICON *icon){
    al_destroy_event_queue( gamedata->event_queue);
    al_destroy_display( gamedata->display);

    al_destroy_bitmap(icon->BackGround); // destroy the ball bitmap
    al_destroy_bitmap(icon->GameStart);
    al_destroy_bitmap(icon->SelectArrow);
    al_destroy_bitmap(icon->GameOver);
    al_destroy_bitmap(icon->doodle);
    al_destroy_bitmap(icon->baseG);
    al_destroy_bitmap(icon->baseB);
    al_destroy_bitmap(icon->baseW);
    al_destroy_bitmap(icon->Level2);
    al_destroy_bitmap(icon->Level3);

    al_destroy_sample(icon->background1);
    al_destroy_sample(icon->background2);
    al_destroy_sample(icon->background3);

    al_destroy_timer(gamedata->timer);
    al_destroy_font( gamedata->Font );
    al_destroy_font( gamedata->Font0 );
    al_destroy_font( gamedata->Font1 );
    al_destroy_font( gamedata->Font2 );
    al_destroy_font( gamedata->Font3 );
    al_destroy_font( gamedata->Font4 );
}
=======
#define MYHEADER_H_INCLUDED
#include "Define.h"
#include "StructDef.h"
void Destroy(GAMEDATA *gamedata, ICON *icon){
    al_destroy_event_queue( gamedata->event_queue);
    al_destroy_display( gamedata->display);

    al_destroy_bitmap(icon->BackGround); // destroy the ball bitmap
    al_destroy_bitmap(icon->GameStart);
    al_destroy_bitmap(icon->SelectArrow);
    al_destroy_bitmap(icon->GameOver);
    al_destroy_bitmap(icon->doodle);
    al_destroy_bitmap(icon->baseG);
    al_destroy_bitmap(icon->baseB);
    al_destroy_bitmap(icon->baseW);
    al_destroy_bitmap(icon->Level2);
    al_destroy_bitmap(icon->Level3);

    al_destroy_sample(icon->background);

    al_destroy_timer(gamedata->timer);
    al_destroy_font( gamedata->Font );
    al_destroy_font( gamedata->Font0 );
    al_destroy_font( gamedata->Font1 );
    al_destroy_font( gamedata->Font2 );
    al_destroy_font( gamedata->Font3 );
    al_destroy_font( gamedata->Font4 );
}
>>>>>>> chunyen
