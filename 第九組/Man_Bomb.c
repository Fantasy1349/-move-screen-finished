#include "FunctionDef.h"
#include "Define.h"

int main()
{
    /*-----------------------Declared-----------------------*/
    ALLEGRO_BITMAP *BackGround = NULL;
    ALLEGRO_BITMAP *GameOver = NULL;
    ALLEGRO_BITMAP *doodle = NULL;
    ALLEGRO_BITMAP *baseG = NULL;
    ALLEGRO_BITMAP *baseB = NULL; //declare bitmap
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL; // create event queue
    ALLEGRO_EVENT events;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *Font = NULL; // declare Font file
    ALLEGRO_FONT *Font1 = NULL;
    ALLEGRO_FONT *Font2 = NULL;

    int i,level=1;
    int Score[1]={0}, FinalScore = 0;
    bool run=1;
    float FPS = 120;
    ROLE Doodle;
    BASE Base_G[BaseG_Num];
    BASE Base_B[BaseG_Num];

    /*-----------set up Allegro and the graphics mode-----------*/
    initialization();
    display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    timer = al_create_timer(1.0 / FPS);

    /*------------------Load Bitmap------------------*/
    BackGround  = al_load_bitmap( "Background.png");
    GameOver    = al_load_bitmap( "GameOver.png");
    doodle      = al_load_bitmap( "Doodle.png");
    baseG       = al_load_bitmap( "PlatG.png");
    baseB       = al_load_bitmap( "PlatB.png");
    Font = al_load_ttf_font("ARCHRISTY.ttf", 23, 0);
    Font1 = al_load_ttf_font("ARCHRISTY.ttf", 35, 0);
    Font2 = al_load_ttf_font("ARCHRISTY.ttf", 80, 0);
    /*----------------Work space----------------*/
    srand( time( NULL ) );
     //seed the random function

    if (level == 1)     initilaze_coordinate(&Doodle, Base_G);
    else if (level == 2)initilaze_coordinate(&Doodle, Base_B);

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());    /* register keyboard to event queue */
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while(run){
        al_draw_bitmap(BackGround, 0, 0, 0);
//        main_menu(Font1, Font2);

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
                        Plat_jump(&Doodle,Base_G);
                        Doodle_jump(&Doodle,Base_G,&Score);
                        }
                        else if (level == 2) {
                        Plat_jump(&Doodle,Base_B);
                        Doodle_jump(&Doodle,Base_B,&Score);
                        }
                        if(Doodle.Y > 930) run=0;
                        break;
                 }
           Doodle_Moving(&Doodle);
           if(Score[0]>=10000) level = 2;
          }
       }
       FinalScore = Score[0] / 10;
//       printf("\nScore=%d\n", FinalScore);
       al_draw_textf( Font, al_map_rgb(0, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Score = %d", FinalScore);
        //display bitmap
        for(i = 0; i < BaseG_Num; i++){
            al_draw_bitmap(baseG, Base_G[i].X,Base_G[i].Y, 0);
        }

        al_draw_scaled_bitmap(doodle, 0, 0,
                              al_get_bitmap_width(doodle), al_get_bitmap_height(doodle),
                              Doodle.X, Doodle.Y,
                              DoodleW, DoodleH,
                              0
                              );

        al_rest(0.01);

        al_flip_display(); // Wait for the beginning of a vertical retrace.
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
