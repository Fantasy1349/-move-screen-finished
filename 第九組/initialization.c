<<<<<<< HEAD
#include "Define.h"
#include "StructDef.h"

void initialization(GAMEDATA *gamedata, ICON *icon){
/*for initialize the tool that using in this project*/
/*Input Variable : void*/
/*Output : void*/
    icon -> MenuBackground                  = NULL;
    icon -> BackGround                      = NULL;
    icon -> BackGround2                     = NULL;
    icon -> BackGround3                     = NULL;
    icon -> GameStart                       = NULL;
    icon -> GameOver                        = NULL;
    icon -> SelectArrow                     = NULL;
    icon -> NoneSelectArrow                 = NULL;
    icon -> Level2                          = NULL;
    icon -> Level3                          = NULL;
    icon -> doodle                          = NULL;
    icon -> baseG                           = NULL;
    icon -> baseB                           = NULL;
    icon -> baseW                           = NULL; //declare bitmap
    icon -> background1                     = NULL;

    gamedata -> display					    = NULL;
    gamedata -> timer					    = NULL;
    gamedata -> event_queue					= NULL; // create event queue
    gamedata -> Font					    = NULL; // declare Font file
    gamedata -> Font0					    = NULL;
    gamedata -> Font1					    = NULL;
    gamedata -> Font2					    = NULL;
    gamedata -> Font3					    = NULL;
    gamedata -> Font4					    = NULL;

    al_init(); //initialize Allegro
    al_install_keyboard(); // install the keyboard for Allegro to use
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();
    al_init_primitives_addon();

    gamedata -> FPS                        = 120;
    gamedata -> run                        = 1;
    gamedata -> quit                       = 1;
    gamedata -> game                       = 1;
    gamedata -> level                      = 1;
    gamedata -> select                     = 1;
    gamedata -> Score                      = 0;
    gamedata -> FinalScore                 = 0;
    gamedata -> level2_stoptime            = 0;
    gamedata -> level3_stoptime            = 0;

    for(int i = 0; i < 20; i++){
        gamedata->rank1[i].NAME[30] = "NONE";
        gamedata->rank1[i].score = 0;
    }

    gamedata -> display                    = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    gamedata -> timer                      = al_create_timer(1.0 / gamedata->FPS);
    gamedata -> event_queue                = al_create_event_queue();

    icon -> MenuBackground                 = al_load_bitmap( "Menu.jpg");
    icon -> BackGround                     = al_load_bitmap( "Background.png");
    icon -> BackGround2                    = al_load_bitmap( "Background2.png");
    icon -> BackGround3                    = al_load_bitmap( "Background3.png");
    icon -> GameStart                      = al_load_bitmap( "GameStart.jpg");
	icon -> SelectArrow                    = al_load_bitmap( "SelectArrow.png");
	icon -> NoneSelectArrow                = al_load_bitmap( "NOSelectArrow.png");
    icon -> GameOver                       = al_load_bitmap( "GameOver.png");
    icon -> Level2                         = al_load_bitmap( "level2.jpg");
    icon -> Level3                         = al_load_bitmap( "level3.jpg");
    icon -> doodle                         = al_load_bitmap( "Doodle.png");
    icon -> baseG                          = al_load_bitmap( "PlatG.png");
    icon -> baseB                          = al_load_bitmap( "PlatB.png");
    icon -> baseW                          = al_load_bitmap( "PlatW.png");
    icon -> background1                    = al_load_sample("Background.wav");
    icon -> background2                    = al_load_sample("Background.wav");
    icon -> background3                    = al_load_sample("Background.wav");

    gamedata -> Font                       = al_load_ttf_font("QUEEOC__.ttf", 30, 0);
    gamedata -> Font0                      = al_load_ttf_font("OCRAEXT.ttf", 28, 0);
    gamedata -> Font1                      = al_load_ttf_font("OCRAEXT.ttf", 40, 0);
    gamedata -> Font2                      = al_load_ttf_font("OCRAEXT.ttf", 80, 0);
    gamedata -> Font3                      = al_load_ttf_font("ARCHRISTY.ttf", 40, 0);
    gamedata -> Font4                      = al_load_ttf_font("ARCHRISTY.ttf", 80, 0);

    al_register_event_source(gamedata->event_queue, al_get_keyboard_event_source());    /* register keyboard to event queue */
    al_register_event_source(gamedata->event_queue, al_get_display_event_source(gamedata->display));
    al_register_event_source(gamedata->event_queue, al_get_timer_event_source(gamedata->timer));

    al_start_timer(gamedata->timer);

}
=======
#include "Define.h"
#include "StructDef.h"

void initialization(GAMEDATA *gamedata, ICON *icon){
/*for initialize the tool that using in this project*/
/*Input Variable : void*/
/*Output : void*/
    icon -> MenuBackground                  = NULL;
    icon -> BackGround                      = NULL;
    icon -> BackGround2                     = NULL;
    icon -> BackGround3                     = NULL;
    icon -> GameStart                       = NULL;
    icon -> GameOver                        = NULL;
    icon -> SelectArrow                     = NULL;
    icon -> NoneSelectArrow                 = NULL;
    icon -> Level2                          = NULL;
    icon -> Level3                          = NULL;
    icon -> doodle                          = NULL;
    icon -> baseG                           = NULL;
    icon -> baseB                           = NULL;
    icon -> baseW                           = NULL; //declare bitmap
    icon -> background                      = NULL;

    gamedata -> display					    = NULL;
    gamedata -> timer					    = NULL;
    gamedata -> event_queue					= NULL; // create event queue
    gamedata -> Font					    = NULL; // declare Font file
    gamedata -> Font0					    = NULL;
    gamedata -> Font1					    = NULL;
    gamedata -> Font2					    = NULL;
    gamedata -> Font3					    = NULL;
    gamedata -> Font4					    = NULL;

    al_init(); //initialize Allegro
    al_install_keyboard(); // install the keyboard for Allegro to use
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_reserve_samples(9);
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();
    al_init_primitives_addon();

    gamedata -> FPS                        = 120;
    gamedata -> run                        = 1;
    gamedata -> quit                       = 1;
    gamedata -> game                       = 1;
    gamedata -> level                      = 1;
    gamedata -> select                     = 1;
    gamedata -> Score                      = 0;
    gamedata -> FinalScore                 = 0;
    gamedata -> level2_stoptime            = 0;
    gamedata -> level3_stoptime            = 0;

    for(int i = 0; i < 20; i++){
        gamedata->rank1[i].NAME[30] = "NONE";
        gamedata->rank1[i].score = 0;
    }

    gamedata -> display                    = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    gamedata -> timer                      = al_create_timer(1.0 / gamedata->FPS);
    gamedata -> event_queue                = al_create_event_queue();

    icon -> MenuBackground                 = al_load_bitmap( "Menu.jpg");
    icon -> BackGround                     = al_load_bitmap( "Background.png");
    icon -> BackGround2                    = al_load_bitmap( "Background2.png");
    icon -> BackGround3                    = al_load_bitmap( "Background3.png");
    icon -> GameStart                      = al_load_bitmap( "GameStart.jpg");
	icon -> SelectArrow                    = al_load_bitmap( "SelectArrow.png");
	icon -> NoneSelectArrow                = al_load_bitmap( "NOSelectArrow.png");
    icon -> GameOver                       = al_load_bitmap( "GameOver.png");
    icon -> Level2                         = al_load_bitmap( "level2.jpg");
    icon -> Level3                         = al_load_bitmap( "level3.jpg");
    icon -> doodle                         = al_load_bitmap( "Doodle.png");
    icon -> baseG                          = al_load_bitmap( "PlatG.png");
    icon -> baseB                          = al_load_bitmap( "PlatB.png");
    icon -> baseW                          = al_load_bitmap( "PlatW.png");
    icon -> background                     = al_load_sample("Background.wav");

    gamedata -> Font                       = al_load_ttf_font("QUEEOC__.ttf", 30, 0);
    gamedata -> Font0                      = al_load_ttf_font("OCRAEXT.ttf", 2, 0);
    gamedata -> Font1                      = al_load_ttf_font("OCRAEXT.ttf", 40, 0);
    gamedata -> Font2                      = al_load_ttf_font("OCRAEXT.ttf", 80, 0);
    gamedata -> Font3                      = al_load_ttf_font("ARCHRISTY.ttf", 40, 0);
    gamedata -> Font4                      = al_load_ttf_font("ARCHRISTY.ttf", 80, 0);

    al_register_event_source(gamedata->event_queue, al_get_keyboard_event_source());    /* register keyboard to event queue */
    al_register_event_source(gamedata->event_queue, al_get_display_event_source(gamedata->display));
    al_register_event_source(gamedata->event_queue, al_get_timer_event_source(gamedata->timer));


}



>>>>>>> chunyen
