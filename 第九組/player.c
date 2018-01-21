#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"

void Enter_Name(GAMEDATA *gamedata){

    char edittext[255]="";
    char letter[255]="";
    int  caret = 0;     //name length

    gamedata->run = 1;


        while(gamedata->run){
        al_clear_to_color(al_map_rgb(255, 255, 255));


        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2-40, ALLEGRO_ALIGN_CENTER, "Enter Your Name");
        al_draw_textf(gamedata->Font, al_map_rgb(0, 0, 0), DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, ALLEGRO_ALIGN_CENTER,  edittext);

        al_flip_display();

        al_wait_for_event(gamedata->event_queue, &gamedata->events);

        switch(gamedata->events.type){
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                gamedata->run = 0;
                break;
            case ALLEGRO_EVENT_KEY_CHAR:
                if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ENTER){
                    gamedata->run = 0;
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
}
//
void Leaderboards(GAMEDATA *gamedata, ICON *icon){
    gamedata->run = 1;

    Rank_Result(gamedata);

    while(gamedata->run){
        al_draw_bitmap(icon->BackGround, 0, 0, 0);
        if (!al_is_event_queue_empty(gamedata->event_queue)) {
            while (al_get_next_event(gamedata->event_queue, &gamedata->events)) {
                 switch (gamedata->events.type) {
                    case ALLEGRO_EVENT_KEY_DOWN:    //press keyboard(up, down, left, right) -> move
                        if(gamedata->events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)   // if press enter, return
                            gamedata->run = 0;
                        break;
                    case ALLEGRO_EVENT_TIMER :
                        al_clear_to_color(al_map_rgb(0,0,0));
                        al_draw_bitmap(icon->BackGround, 0, 0, 0);
                        al_draw_textf(gamedata->Font, al_map_rgb(0,0,0), DISPLAY_WIDTH/2, 70, ALLEGRO_ALIGN_CENTER, "Rank");

                        int i;
                        for(i=0;i<10;i++){
                            al_draw_textf(gamedata->Font, al_map_rgb(0,0,0), DISPLAY_WIDTH/2-150, 60*i+130, ALLEGRO_ALIGN_CENTER, "%d", i+1);
                            al_draw_textf(gamedata->Font, al_map_rgb(0,0,0), DISPLAY_WIDTH/2, 60*i+130, ALLEGRO_ALIGN_CENTER, "%s", gamedata->rank1[i].NAME);
                            al_draw_textf(gamedata->Font, al_map_rgb(0,0,0), DISPLAY_WIDTH/2+150, 60*i+130, ALLEGRO_ALIGN_CENTER, "%d", gamedata->rank1[i].score);
                        }
                        al_flip_display();
                        break;
                 }
            }
        }
    }

}
