#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void menu(GAMEDATA *gamedata, ICON *icon){
    gamedata->run = 1;

    while(gamedata->run){
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(icon->BackGround, 0, 0, 0)    ;

        al_draw_textf(gamedata->Font1, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/4, ALLEGRO_ALIGN_LEFT, "PLAY");
        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2.5+25, ALLEGRO_ALIGN_RIGHT, "HIGH SCORE");
		al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2 -25, DISPLAY_HEIGHT/2 +45, ALLEGRO_ALIGN_LEFT, "HELP");

		al_flip_display();

        al_wait_for_event(gamedata->event_queue, &gamedata->events);
        printf("select %d\n", gamedata->select);

        switch(gamedata->events.type){
            case ALLEGRO_EVENT_KEY_DOWN:
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_DOWN){
                    gamedata->select++;
                    if(gamedata->select > 3) gamedata->select -= 3;
                }
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_UP){
                    gamedata->select--;
                    if(gamedata->select < 1) gamedata->select += 3;
                }
        }
        switch(gamedata->select){
            case 1:
                al_draw_bitmap(icon->SelectArrow, 200, 370, 0);
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER) gamedata->run = 0;
                }
                break;
            case 2:
                al_draw_bitmap(icon->SelectArrow, 200, 530, 0);
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER) Leaderboards(gamedata, icon);
                        break;
                }
                break;
            case 3:
                al_draw_bitmap(icon->SelectArrow, 200, 635, 0);
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER) Rule(gamedata);
                        break;
                }
                break;
        }
    }
}

void Rule(GAMEDATA *gamedata){
     al_draw_textf(gamedata->Font1, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/4, ALLEGRO_ALIGN_LEFT, "PLAY");


}
