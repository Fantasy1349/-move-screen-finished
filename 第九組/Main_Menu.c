#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void menu(GAMEDATA *gamedata, ICON *icon){
     gamedata->quit_m = 1;
    gamedata->select = 1;

    while(gamedata->quit_m){
        al_wait_for_event(gamedata->event_queue, &gamedata->events);

        switch(gamedata->events.type){
            case ALLEGRO_EVENT_KEY_DOWN:
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_DOWN){
                    gamedata->select++;
                    if(gamedata->select > 4) gamedata->select -= 4;
                }
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_UP){
                    gamedata->select--;
                    if(gamedata->select < 1) gamedata->select += 4;
                }
        }
        switch(gamedata->select){
            case 1:
                al_clear_to_color(al_map_rgb(255, 255, 255));
                text_menu(gamedata, icon);
                al_draw_bitmap(icon->SelectArrow,     100, 310, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 450, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 590, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 730, 0);
                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                            gamedata->run = 1;
                            gamedata->quit_m= 0;
                        }
                        break;
                }
                break;

            case 2:
                al_clear_to_color(al_map_rgb(255, 255, 255));
                text_menu(gamedata, icon);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 310, 0);
                al_draw_bitmap(icon->SelectArrow,     100, 450, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 590, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 730, 0);

                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER) Leaderboards(gamedata, icon);
                        break;
                }
                break;
            case 3:
                al_clear_to_color(al_map_rgb(255, 255, 255));
                text_menu(gamedata, icon);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 310, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 450, 0);
                al_draw_bitmap(icon->SelectArrow,     100, 590, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 730, 0);

                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER) Rule(gamedata, icon);
                        break;
                }
                break;
            case 4:
                al_clear_to_color(al_map_rgb(255, 255, 255));
                text_menu(gamedata, icon);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 310, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 450, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 100, 590, 0);
                al_draw_bitmap(icon->SelectArrow,     100, 730, 0);

                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                            gamedata->run    = 0;
                            gamedata->quit   = 0;
                            gamedata->quit_m = 0;
                            gamedata->quit_LB= 0;
                            gamedata->quit_R = 0;
                            gamedata->game   = 0;
                        }
                        break;
                }

        }
    }
}

void Rule(GAMEDATA *gamedata, ICON*icon){
    gamedata->select = 1;

    while(gamedata->quit_R){
        al_wait_for_event(gamedata->event_queue, &gamedata->events);
        switch (gamedata->events.type) {
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_DOWN){
                        gamedata->select++;
                        if(gamedata->select > 2)gamedata->select-=2;
                    }
                    if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_UP){
                        gamedata->select--;
                        if(gamedata->select < 1)gamedata->select+=2;
                    }
                 }
        switch(gamedata->select){
            case 1:
                text_Rule(gamedata, icon);
                al_draw_bitmap(icon->SelectArrow,     200, 750, 0);
                al_draw_bitmap(icon->NoneSelectArrow, 200, 850, 0);

                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                            gamedata->run = 1;
                            gamedata->quit_R= 0;
                            gamedata->quit_m = 0;
                        }
                }
                break;

            case 2:
                text_Rule(gamedata, icon);
                al_draw_bitmap(icon->NoneSelectArrow, 200, 750, 0);
                al_draw_bitmap(icon->SelectArrow,     200, 850, 0);

                al_flip_display();
                switch(gamedata->events.type){
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                            gamedata->run    = 0;
                            gamedata->quit   = 0;
                            gamedata->quit_m = 0;
                            gamedata->quit_LB= 0;
                            gamedata->quit_R = 0;
                            gamedata->game   = 0;

                        }
                }
                break;
        }


    }
}

void text_menu(GAMEDATA *gamedata, ICON*icon){
    al_draw_bitmap(icon-> MenuBackground, 0, 0, 0);
    al_draw_textf(gamedata->Font4, al_map_rgb(235, 255, 255), DISPLAY_WIDTH/2, 300, ALLEGRO_ALIGN_CENTER, "PLAY");
    al_draw_textf(gamedata->Font3, al_map_rgb(255, 255, 255), DISPLAY_WIDTH/2, 440, ALLEGRO_ALIGN_CENTER, "LEADER BROAD");
    al_draw_textf(gamedata->Font3, al_map_rgb(255, 255, 255), DISPLAY_WIDTH/2, 580, ALLEGRO_ALIGN_CENTER, "HELP");
    al_draw_textf(gamedata->Font3, al_map_rgb(255, 255, 255), DISPLAY_WIDTH/2, 720, ALLEGRO_ALIGN_CENTER, "QUIT");
}

void text_Rule(GAMEDATA *gamedata, ICON*icon){
    al_draw_bitmap(icon->BackGround3, 0, 0, 0);
    al_draw_filled_rectangle(40, 190, 560, 650,  al_map_rgb(235,117,0));
    al_draw_textf(gamedata->Font1, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 750, ALLEGRO_ALIGN_CENTER, "PLAY");
    al_draw_textf(gamedata->Font1, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 850, ALLEGRO_ALIGN_CENTER, "QUIT");
    al_draw_textf(gamedata->Font2, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 80, ALLEGRO_ALIGN_CENTER, "HELP");
    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 200, ALLEGRO_ALIGN_CENTER, "When switching the levels");
    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 250, ALLEGRO_ALIGN_CENTER, "there will be some preparation time");

    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 330, ALLEGRO_ALIGN_CENTER, "The platform  of the second level");
    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 380, ALLEGRO_ALIGN_CENTER, "will move left and right");

    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 430, ALLEGRO_ALIGN_CENTER, "The platform  of the third level");
    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 480, ALLEGRO_ALIGN_CENTER, "can only step for once");

    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 560, ALLEGRO_ALIGN_CENTER, "Good luck");
    al_draw_textf(gamedata->Font, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 610, ALLEGRO_ALIGN_CENTER, "Do Your Best and Jump to the Highest Score");
}
