#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <time.h>
#include <windows.h>

// Definition of display size
#define DISPLAY_WIDTH   600
#define DISPLAY_HEIGHT  920

#define DOWN_RIGHT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3

#define DoodleH 95
#define DoodleW 57

#define BaseH 15
#define BaseW 63
#define BaseSHIFT 15

#define Right  2
#define Left   3

#define BaseG_Num 28
#define BaseB_Num 20
#define BaseW_Num 30

#define Level_2_Score 5000
#define Level_3_Score 10000
#define jumphight 350

#define Prop_Num 6
#define Prop_H 40
#define Propheight 300


#endif // DEFINE_H_INCLUDED
