#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void Game_Start(GAMEDATA *gamedata, ICON *icon, ROLE *Doodle, BASE *Base_G, BASE *Base_B, BASE *Base_W){
    int i;
    initilaze_coordinate(BaseW_Num,  Base_W, Doodle);
	initilaze_coordinate(BaseB_Num,  Base_B, Doodle);
    initilaze_coordinate(BaseG_Num,  Base_G, Doodle);

    ini_stoptime(gamedata);
	while(gamedata->run){
        al_draw_bitmap(icon->BackGround, 0, 0, 0);
        if (!al_is_event_queue_empty(gamedata->event_queue)) {
            while (al_get_next_event(gamedata->event_queue, &gamedata->events)) {
                 switch (gamedata->events.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        gamedata->run = 0;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)  gamedata->run = 0;
                        Change_State(gamedata, Doodle);
                        break;
                    case ALLEGRO_EVENT_KEY_UP:
                        STOP(gamedata, Doodle);
                    case ALLEGRO_EVENT_TIMER:
                        if (gamedata->level == 1){
                            if(gamedata->level1_stoptime < 10) {
                                initilaze_level(Doodle, Base_G,BaseG_Num);
                                gamedata->level1_stoptime++;
                            }
                            else if(gamedata->level1_stoptime >= 10){
                                Plat_jump(BaseG_Num, Base_G, Doodle, gamedata);
                                Doodle_jump(gamedata, BaseG_Num, Base_G, Doodle);
                            }
                        }

                        else if (gamedata->level == 2) {
                            if(gamedata->level2_stoptime < 150) {
                                initilaze_level(Doodle, Base_B,BaseB_Num);
                                gamedata->level2_stoptime++;
                            }
                            else if(gamedata->level2_stoptime >=150){
                                Plat_move(Base_B);
                                //Countdown about 1.5 seconds then move plat
                            }
                                Plat_jump(BaseB_Num, Base_B, Doodle, gamedata);
                                Doodle_jump(gamedata, BaseB_Num, Base_B, Doodle);
                        }

                        else{
                            if(gamedata->level3_stoptime < 150 ) {
                                initilaze_level(Doodle,Base_W,BaseW_Num);
                                gamedata->level3_stoptime++;
                            }
                            else if(gamedata->level3_stoptime >= 150){
                                Plat_jump(BaseW_Num, Base_W, Doodle, gamedata);
                                Doodle_jump(gamedata, BaseW_Num, Base_W, Doodle);
                                //Countdown about 1.5 seconds then playing level 3
                            }
                        }
                       if(Doodle->Y > 930) gamedata->run=0;
                        break;
                 }
           Doodle_Moving(Doodle);
          }
       }
       gamedata->FinalScore = gamedata->Score / 10;

       if(gamedata->FinalScore>=Level_2_Score &&
          gamedata->FinalScore<=Level_2_Score + 30 && gamedata->level == 1) {
               al_draw_bitmap(icon->Level2, 0, 0, 0);//show Game Over bitmap
               al_rest(0.01);
               al_flip_display(); // Wait for the beginning of a vertical retrace.
               al_rest(0.5);
               gamedata->level = 2;
//               initilaze_level(&Doodle, Base_B,BaseB_Num);
       }
       if(gamedata->FinalScore>=Level_3_Score &&
          gamedata->FinalScore<=Level_3_Score + 30 && gamedata->level == 2) {
               al_draw_bitmap(icon->Level3, 0, 0, 0);//show Game Over bitmap
               al_rest(0.01);
               al_flip_display(); // Wait for the beginning of a vertical retrace.
               al_rest(0.5);
               gamedata->level = 3;
//               initilaze_level,(&Doodle, Base_W,BaseW_Num);
       }

//       printf("\nScore=%d\n", FinalScore);
        //display bitmap
        if(gamedata->level == 1){
            for(i = 0; i < BaseG_Num; i++){
                al_draw_bitmap(icon->baseG, Base_G[i].X, Base_G[i].Y, 0);
            }
        }
        else if(gamedata->level == 2){
            for(i = 0; i < BaseB_Num; i++){
                al_draw_bitmap(icon->baseB, Base_B[i].X, Base_B[i].Y, 0);
            }
        }
        else if(gamedata->level == 3){
            for(i = 0; i < BaseW_Num; i++){
                    if(Base_W[i].HP != 0)     al_draw_bitmap(icon->baseW, Base_W[i].X, Base_W[i].Y, 0);
            }
        }

        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Score = %d", gamedata->FinalScore);

        if(gamedata->picture_dir == Left)
        al_draw_scaled_bitmap(icon->doodle, 0, 0,al_get_bitmap_width(icon->doodle), al_get_bitmap_height(icon->doodle),
                              Doodle->X, Doodle->Y,DoodleW, DoodleH,1);
        else
        al_draw_scaled_bitmap(icon->doodle, 0, 0,al_get_bitmap_width(icon->doodle), al_get_bitmap_height(icon->doodle),
                              Doodle->X, Doodle->Y,DoodleW, DoodleH,0);

        al_rest(0.01);

        al_flip_display(); // Wait for the beginning of a vertical retrace.
//        printf("level=%d\n",level);

    }

}
