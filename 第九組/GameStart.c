#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void PLAY_GAME(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W,BASE *Prop){
     while(gamedata->game){
            initialization(gamedata, icon);
            al_start_timer(gamedata->timer);

            menu(gamedata, icon);
            Game_Start(gamedata, icon, Doodle, Base_G,Base_B, Base_W,Prop);

            Enter_Name(gamedata, icon);
            Leaderboards(gamedata, icon);
//            Destroy(gamedata, icon);

        }

}


void Game_Start(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W,BASE * Prop){
    int i;
    initilaze_coordinate(BaseW_Num,  Base_W, Doodle,Prop);
    initilaze_coordinate(BaseB_Num,  Base_B, Doodle,Prop);
    initilaze_coordinate(BaseG_Num,  Base_G, Doodle,Prop);
    STOP(gamedata, Doodle);
    ini_stoptime(gamedata);
	while(gamedata->run){
        if (!al_is_event_queue_empty(gamedata->event_queue)) {
            while (al_get_next_event(gamedata->event_queue, &gamedata->events)) {
                 switch (gamedata->events.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        gamedata->run = 0;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                            gamedata->run=0;
                            gamedata->quit=1;
                       }
                        Change_State(gamedata, Doodle);
                        break;
                    case ALLEGRO_EVENT_KEY_UP:
                        STOP(gamedata, Doodle);
                    case ALLEGRO_EVENT_TIMER:
                        if (gamedata->level == 1){
                            al_play_sample(icon->background1, 1.0, 0.0, 1.0,  ALLEGRO_PLAYMODE_LOOP, NULL);
                            al_draw_bitmap(icon->BackGround, 0, 0, 0);

                            if(gamedata->level1_stoptime < 10) {
                                initilaze_level(Doodle, Base_G,BaseG_Num,Prop);
                                gamedata->level1_stoptime++;
                            }
                            else if(gamedata->level1_stoptime >= 10){
                                Plat_jump(BaseG_Num, Base_G, Doodle, gamedata);
                                Doodle_jump(gamedata, BaseG_Num, Base_G, Doodle,Prop);
                                creat_Prop(gamedata,Prop);
                                Prop_jump(gamedata,Doodle,Prop);

                            }
                        }

                        else if (gamedata->level == 2) {
                            al_destroy_sample(icon->background1);
                            al_play_sample(icon->background2, 1.0, 0.0, 1.5,  ALLEGRO_PLAYMODE_LOOP, NULL);
                            al_draw_bitmap(icon->BackGround2, 0, 0, 0);
                            if(gamedata->level2_stoptime < 150) {
                                initilaze_level(Doodle, Base_B,BaseB_Num,Prop);
                                gamedata->level2_stoptime++;
                            }
                            else if(gamedata->level2_stoptime >=150){
                                Plat_move(Base_B,Prop);
                                //Countdown about 1.5 seconds then move plat
                            }
                                Plat_jump(BaseB_Num, Base_B, Doodle, gamedata);
                                creat_Prop(gamedata,Prop);
                                Prop_jump(gamedata,Doodle,Prop);
                                Doodle_jump(gamedata, BaseB_Num, Base_B, Doodle,Prop);
                        }

                        else{
                            al_destroy_sample(icon->background2);
                            al_play_sample(icon->background3, 1.0, 0.0, 2,  ALLEGRO_PLAYMODE_LOOP, NULL);
                            al_draw_bitmap(icon->BackGround3, 0, 0, 0);
                            if(gamedata->level3_stoptime < 150 ) {
                                initilaze_level(Doodle,Base_W,BaseW_Num,Prop);
                                gamedata->level3_stoptime++;
                            }
                            else if(gamedata->level3_stoptime >= 150){
                                Plat_jump(BaseW_Num, Base_W, Doodle, gamedata);
                                creat_Prop(gamedata,Prop);
                                Prop_jump(gamedata,Doodle,Prop);
                                Doodle_jump(gamedata, BaseW_Num, Base_W, Doodle,Prop);
                                //Countdown about 1.5 seconds then playing level 3
                            }
                        }
                       if(Doodle->Y > 930){
                            gamedata->run=0;
                            gamedata->quit=1;
                       }
                        break;
                 }
           Doodle_Moving(Doodle);
          }
       }
       gamedata->FinalScore = gamedata->Score ;

        if(gamedata->FinalScore>=Level_2_Score &&
            gamedata->FinalScore<Level_3_Score && gamedata->level == 1) {
                al_draw_bitmap(icon->Level2, 0, 0, 0);//show Game Over bitmap
                al_rest(0.01);
                al_flip_display(); // Wait for the beginning of a vertical retrace.
                al_rest(0.5);
                gamedata->level = 2;
            }

       if(gamedata->FinalScore>=Level_3_Score  && gamedata->level == 2) {
               al_draw_bitmap(icon->Level3, 0, 0, 0);//show Game Over bitmap
               al_rest(0.01);
               al_flip_display(); // Wait for the beginning of a vertical retrace.
               al_rest(0.5);
               gamedata->level = 3;
       }

        //display bitmap
        if(gamedata->level == 1){
            for(i = 0; i < BaseG_Num; i++){
                al_draw_bitmap(icon->baseG, Base_G[i].X, Base_G[i].Y, 0);
            }
            if (Prop[0].HP != 0)al_draw_bitmap(icon->springG, Prop[0].X,Prop[0].Y,0);
            if (Prop[3].HP != 0)al_draw_bitmap(icon->rocketG, Prop[3].X,Prop[3].Y,0);
        }
        else if(gamedata->level == 2){
            for(i = 0; i < BaseB_Num; i++){
                al_draw_bitmap(icon->baseB, Base_B[i].X, Base_B[i].Y, 0);
            }
            if (Prop[1].HP != 0)al_draw_bitmap(icon->springB, Prop[1].X,Prop[1].Y,0);
            if (Prop[4].HP != 0)al_draw_bitmap(icon->rocketB, Prop[4].X,Prop[4].Y,0);
        }
        else if(gamedata->level == 3){
            for(i = 0; i < BaseW_Num; i++){
                    if(Base_W[i].HP != 0)     al_draw_bitmap(icon->baseW, Base_W[i].X, Base_W[i].Y, 0);
            }
            if (Prop[2].HP != 0)al_draw_bitmap(icon->springW, Prop[2].X,Prop[2].Y,0);
            if (Prop[5].HP != 0)al_draw_bitmap(icon->rocketW, Prop[5].X,Prop[5].Y,0);
        }

        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Score = %d", gamedata->FinalScore);

        if(gamedata->picture_dir == Left)
        al_draw_scaled_bitmap(icon->doodle, 0, 0,al_get_bitmap_width(icon->doodle), al_get_bitmap_height(icon->doodle),
                              Doodle->X, Doodle->Y,DoodleW, DoodleH,0);
        else
        al_draw_scaled_bitmap(icon->doodle, 0, 0,al_get_bitmap_width(icon->doodle), al_get_bitmap_height(icon->doodle),
                              Doodle->X, Doodle->Y,DoodleW, DoodleH,1);

        al_rest(0.01);

        al_flip_display(); // Wait for the beginning of a vertical retrace.
    }

}
