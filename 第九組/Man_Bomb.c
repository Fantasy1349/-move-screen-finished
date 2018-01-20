#include "FunctionDef.h"
#include "Define.h"

int main()
{
    /*-----------------------Declared-----------------------*/
    ALLEGRO_BITMAP *BackGround = NULL;
    ALLEGRO_BITMAP *GameOver = NULL;
    ALLEGRO_BITMAP *Level2 = NULL;
    ALLEGRO_BITMAP *Level3 = NULL;
    ALLEGRO_BITMAP *doodle = NULL;
    ALLEGRO_BITMAP *baseG = NULL;
    ALLEGRO_BITMAP *baseB = NULL;
    ALLEGRO_BITMAP *baseW = NULL; //declare bitmap
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL; // create event queue
    ALLEGRO_EVENT events;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *Font = NULL; // declare Font file
    ALLEGRO_FONT *Font1 = NULL;
    ALLEGRO_FONT *Font2 = NULL;

    int i,level = 1;
    int Score[1]={0}, FinalScore = 0;
    int level2_stoptime=0,level3_stoptime=0;
    bool run=1;
    float FPS = 120;
    ROLE Doodle;
    BASE Base_G[BaseG_Num];
    BASE Base_B[BaseB_Num];
    BASE Base_W[BaseW_Num];

    /*-----------set up Allegro and the graphics mode-----------*/
    initialization();
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    timer = al_create_timer(1.0 / FPS);

    /*------------------Load Bitmap------------------*/
    BackGround  = al_load_bitmap( "Background.png");
    GameOver    = al_load_bitmap( "GameOver.png");
    Level2      = al_load_bitmap( "level2.jpg");
    Level3      = al_load_bitmap( "level3.jpg");
    doodle      = al_load_bitmap( "Doodle.png");
    baseG       = al_load_bitmap( "PlatG.png");
    baseB       = al_load_bitmap( "PlatB.png");
    baseW       = al_load_bitmap( "PlatW.png");
    Font = al_load_ttf_font("ARCHRISTY.ttf", 23, 0);
    Font1 = al_load_ttf_font("ARCHRISTY.ttf", 35, 0);
    Font2 = al_load_ttf_font("ARCHRISTY.ttf", 80, 0);
    /*----------------Work space----------------*/
    srand( time( NULL ) );
     //seed the random function

    initilaze_coordinate(&Doodle, Base_W,BaseW_Num);
    initilaze_coordinate(&Doodle, Base_B,BaseB_Num);
    initilaze_coordinate(&Doodle, Base_G,BaseG_Num);


    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());    /* register keyboard to event queue */
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while(run){
        al_draw_bitmap(BackGround, 0, 0, 0);
        if (!al_is_event_queue_empty(event_queue)) {
            while (al_get_next_event(event_queue, &events)) {
                 switch (events.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        run = 0;
                        break;
                    case ALLEGRO_EVENT_KEY_DOWN:
                        if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)  run = 0;
                        Change_State(events,&Doodle);
                        break;
                    case ALLEGRO_EVENT_KEY_UP:
                        STOP(events,&Doodle);
                    case ALLEGRO_EVENT_TIMER:
                        if (level == 1)      {
                            Plat_jump(&Doodle,Base_G,BaseG_Num);
                            Doodle_jump(&Doodle,Base_G,&Score,BaseG_Num);
                        }
                        else if (level == 2) {

                        if(level2_stoptime < 150) {
                            initilaze_level(&Doodle, Base_B,BaseB_Num);
                            level2_stoptime++;
                        }
                        else if(level2_stoptime >=150)
                        {   Plat_move(Base_B);
                            //Countdown about 1.5 seconds then move plat
                        }
                            Plat_jump(&Doodle,Base_B,BaseB_Num);
                            Doodle_jump(&Doodle,Base_B,&Score,BaseB_Num);
                        }
                        else{

                            if(level3_stoptime < 150 ) {
                                initilaze_level(&Doodle,Base_W,BaseW_Num);
                                level3_stoptime++;
                        }
                        else if(level3_stoptime >= 150){
                                //del_platW
                            //Countdown about 1.5 seconds then playing level 3
                        }
                            Plat_jump(&Doodle,Base_W,BaseW_Num);
                            Doodle_jump(&Doodle,Base_W,&Score,BaseW_Num);
                        }
                        if(Doodle.Y > 930) run=0;
                        break;
                 }
           Doodle_Moving(&Doodle);
          }
       }
       FinalScore = Score[0] / 10;

       if(FinalScore>=Level_2_Score && FinalScore<=Level_2_Score + 30 && level == 1) {
               al_draw_bitmap(Level2, 0, 0, 0);//show Game Over bitmap
               al_rest(0.01);
               al_flip_display(); // Wait for the beginning of a vertical retrace.
               al_rest(0.5);
               level = 2;
//               initilaze_level(&Doodle, Base_B,BaseB_Num);
       }
       if(FinalScore>=Level_3_Score && FinalScore<=Level_3_Score + 30 && level == 2) {
               al_draw_bitmap(Level3, 0, 0, 0);//show Game Over bitmap
               al_rest(0.01);
               al_flip_display(); // Wait for the beginning of a vertical retrace.
               al_rest(0.5);
               level = 3;
//               initilaze_level,(&Doodle, Base_W,BaseW_Num);
       }

//       printf("\nScore=%d\n", FinalScore);
        //display bitmap
        if(level == 1){
            for(i = 0; i < BaseG_Num; i++){
                al_draw_bitmap(baseG, Base_G[i].X,Base_G[i].Y, 0);
            }
        }
        else if(level == 2){
            for(i = 0; i < BaseB_Num; i++){
                al_draw_bitmap(baseB, Base_B[i].X,Base_B[i].Y, 0);
            }
        }
        else if(level == 3){
            for(i = 0; i < BaseW_Num; i++){
                al_draw_bitmap(baseW, Base_W[i].X,Base_W[i].Y, 0);
            }
        }

        al_draw_textf( Font, al_map_rgb(0, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Score = %d", FinalScore);
        al_draw_scaled_bitmap(doodle, 0, 0,al_get_bitmap_width(doodle), al_get_bitmap_height(doodle),
                              Doodle.X, Doodle.Y,DoodleW, DoodleH,0);

        al_rest(0.01);

        al_flip_display(); // Wait for the beginning of a vertical retrace.
//        printf("level=%d\n",level);
    }
        // Clear the complete target bitmap, but confined by the clipping rectangle.

    al_draw_bitmap(GameOver, 0, 0, 0);//show Game Over bitmap
    al_rest(0.01);
    al_flip_display(); // Wait for the beginning of a vertical retrace.
    al_rest(0.5);

    al_destroy_bitmap( BackGround); // destroy the ball bitmap
    al_destroy_bitmap( GameOver);
    al_destroy_bitmap( doodle);
    al_destroy_bitmap( baseG);

    return 0;
}
