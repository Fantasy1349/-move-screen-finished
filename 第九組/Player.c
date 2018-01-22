#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void Enter_Name(GAMEDATA *gamedata, ICON *icon){

    char edittext[255]="";
    char letter[255]="";
    int  caret = 0;     //name length

        while(gamedata->quit){
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(icon->GameOver, 0, 0, 0);

        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2-40, ALLEGRO_ALIGN_CENTER, "Enter Your Name");
        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, ALLEGRO_ALIGN_CENTER,  edittext);

        al_flip_display();

        al_wait_for_event(gamedata->event_queue, &gamedata->events);

        switch(gamedata->events.type){
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                gamedata->quit = 0;
                break;
            case ALLEGRO_EVENT_KEY_CHAR:
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                    gamedata->quit = 0;
                    gamedata->quit_LB =1;
                    break;
                }
                else if (gamedata->events.keyboard.keycode==ALLEGRO_KEY_SPACE){
                    edittext[caret] = 32;
                    caret++;
                }
                else if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_BACKSPACE){
                    if (caret > 0) caret--;
                    edittext[caret] = '\0';
                }
                else{
                    sprintf(letter,"%c", gamedata->events.keyboard.keycode+64);
                    strcat (edittext, letter);
                    caret++;
                }
                break;
        }
    }
    gamedata->quit = 1;
    FILE *fptr;
    time_t t = time(0);
    char date[30];
    fptr = fopen("result.txt","a+");
    if(fptr== NULL) printf("fail to save result");

    fprintf(fptr,"%s  ", edittext);
    fprintf(fptr," %d\n", gamedata->FinalScore);
    fclose(fptr);
}

void Rank_Result(GAMEDATA *gamedata){
    FILE *fptr;
    fptr = fopen("result.txt","r");
    int i,j;
    RANK temp;
    for(i=0;i<19;i++)
        fscanf(fptr,"%s   %d",gamedata->rank1[i].NAME, &gamedata->rank1[i].score);

    for( i = 0; i < 20; i++) {
        for( j = i; j < 20; j++) {
            if( gamedata->rank1[j].score > gamedata->rank1[i].score ) {
                temp = gamedata->rank1[j];
                gamedata->rank1[j] = gamedata->rank1[i];
                gamedata->rank1[i] = temp;
            }
        }
    }
//    fptr = fopen("result.txt","w");
//    for(i=0;i<20;i++){
//        fprintf(fptr,"%s  ",gamedata->rank1[i].NAME);
//        fprintf(fptr," %d\n",gamedata->rank1[i].score);
//    }
//        fclose(fptr);

}
//
void Leaderboards(GAMEDATA *gamedata, ICON *icon){
    gamedata->select = 1;

    Rank_Result(gamedata);

    while(gamedata->quit_LB){
        al_wait_for_event(gamedata->event_queue, &gamedata->events);
        printf("select %d\n", gamedata->select);
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
                        text_LeaderBroads(gamedata,icon);
                        al_draw_bitmap(icon->SelectArrow,     200, 780, 0);
                        al_draw_bitmap(icon->NoneSelectArrow, 200, 850, 0);

                        al_flip_display();
                        switch(gamedata->events.type){
                            case ALLEGRO_EVENT_KEY_DOWN:
                            if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                                gamedata->run = 1;
                                gamedata->quit_LB= 0;
                                gamedata->game= 1;
                                al_destroy_sample(icon->background1);
                                al_destroy_display(gamedata->display);
                            }
                        }
                        break;

                    case 2:
                        text_LeaderBroads(gamedata,icon);
                        al_draw_bitmap(icon->NoneSelectArrow, 200, 780, 0);
                        al_draw_bitmap(icon->SelectArrow,     200, 850, 0);

                        al_flip_display();
                        al_flip_display();
                        switch(gamedata->events.type){
                            case ALLEGRO_EVENT_KEY_DOWN:
                                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                                    gamedata->run    = 0;
//                                    gamedata->quit   = 0;
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


void text_LeaderBroads(GAMEDATA *gamedata, ICON *icon){
    int i;
    al_draw_bitmap(icon->BackGround, 0, 0, 0);
    al_draw_filled_rectangle(100, 140, 500, 740,  al_map_rgb(0,89,179));
    al_draw_textf(gamedata->Font0, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 780, ALLEGRO_ALIGN_CENTER, "PLAY");
    al_draw_textf(gamedata->Font0, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 850, ALLEGRO_ALIGN_CENTER, "QUIT");
    al_draw_textf(gamedata->Font2, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 60, ALLEGRO_ALIGN_CENTER, "Rank");

    for(i=0;i<10;i++){
        al_draw_textf(gamedata->Font0, al_map_rgb(255,255,255), DISPLAY_WIDTH/2-150, 60*i+150, ALLEGRO_ALIGN_CENTER, "%d", i+1);
        al_draw_textf(gamedata->Font0, al_map_rgb(255,255,255), DISPLAY_WIDTH/2, 60*i+150, ALLEGRO_ALIGN_CENTER, "%s", gamedata->rank1[i].NAME);
        al_draw_textf(gamedata->Font0, al_map_rgb(255,255,255), DISPLAY_WIDTH/2+150, 60*i+150, ALLEGRO_ALIGN_CENTER, "%d", gamedata->rank1[i].score);
    }

}
