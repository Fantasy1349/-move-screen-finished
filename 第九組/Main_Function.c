#include "FunctionDef.h"
#include "Define.h"
/*----------------Doodle-----------------*/

void Doodle_jump(ROLE *Doodle,BASE *Base_G, int *Score,PROP *spring){
/*Control the character jumping mode, up or down*/
/*Input Variable : Structure Pointer Role and Pointer Base*/
/*Output : void*/

    spring->open=1;
    spring->Y=-100;
    if(Doodle->direction == 0){
        if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
        page_move(Doodle,Base_G,Score,spring);
        Doodle->Y=Doodle->Y;
        }
        else Doodle->Y-=3;
    }
    else{
        Doodle->Y+=2;
    }
//    printf("\nbase=%lf\n",Doodle->base);
    if (Doodle->Y+DoodleH <= Doodle->base-jumphight &&
        Doodle->Y+DoodleH <= Doodle->base+BaseH-jumphight)    Doodle->direction=1;//jump down

    if (Doodle->Y+DoodleH >= Doodle->base &&
        Doodle->Y+DoodleH <= Doodle->base+BaseH)  Doodle->direction=0;//jump up

    if (Doodle->Y+DoodleH >= DISPLAY_HEIGHT)      Doodle->Y = DISPLAY_HEIGHT+100;
    if (Doodle->Y+DoodleH <= -10)                   Doodle->Y = 1;
}

void Plat_jump(ROLE *Doodle,BASE Base_G[BaseG_Num]){
/*When the character step the plat, it will jump up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0;i <BaseG_Num;i++){
        if(Doodle->Y+DoodleH >= Base_G[i].Y && Doodle->Y+DoodleH <= Base_G[i].Y+BaseH&& Doodle->direction==1){
            if(Doodle->X+DoodleW >= Base_G[i].X+BaseSHIFT && Doodle->X <= Base_G[i].X+BaseW-BaseSHIFT){
                Doodle->base = Base_G[i].Y;
            }
        }
        else Doodle->base += 0.1;
    }
}

void page_move(ROLE *Doodle,BASE Base_G[BaseG_Num], int *Score,PROP *spring){
/*When the character jump up, the page will also move up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/



    for(int i = 0 ; i < BaseG_Num ; i++){

        if (Doodle->Y >= 270 && Doodle->Y <= 430){
            Base_G[i].Y += 5;
            spring->Y +=5;
            Score[0] += 5;
        }
        else if (Doodle->Y >= 187 && Doodle->Y <= 270){
            Base_G[i].Y += 7;
            spring->Y +=7;
            Score[0] += 7;
        }
        else if(Doodle->Y < 187){
            Base_G[i].Y += 12;
            spring->Y +=12;
            Score[0] += 12;
        }
        else{
            Base_G[i].Y += 3;
            spring->Y +=3;
            Score[0] += 3;
        }
        Base_G[i].X = Base_G[i].X;
        if(Base_G[i].Y > DISPLAY_HEIGHT){
            Base_G[i].Y -= DISPLAY_HEIGHT;
            Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            while((Doodle->X >= Base_G[i].X -30) && (Doodle->X <= Base_G[i].X +90)){
                Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            }
        if(spring->open==1){
            spring->X = Base_G[i].X+29;
            spring->Y = Base_G[i].Y-19;
            spring->open = 0;
        }
        }
    }
}

void initilaze_coordinate(ROLE *Doodle,BASE Base_G[BaseG_Num]){
/*Set up the initial coordinate of the plat*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    int i, j;
    Base_G[0].X = rand()%(DISPLAY_WIDTH-BaseW +1);
    Base_G[0].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
    for(i = 1; i < 10; i++){
        Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base_G[i].Y = i*100;
    }
    for(i = 10; i < BaseG_Num-10; i++){
        Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base_G[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
    }
    //check whether has near plat
    for(i = 10; i < BaseG_Num; i++){
        for(j = i-1; j >= 0; j--){
            while((Base_G[i].X >= Base_G[j].X - 120) && (Base_G[i].X <= Base_G[j].X + 120) &&
                  (Base_G[i].Y >= Base_G[j].Y - 60) && (Base_G[i].Y <= Base_G[j].Y + 60)){
                   Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
                   Base_G[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
            }
        }
    }

    Doodle->X = rand()%(DISPLAY_WIDTH-DoodleW +1); // give the Man its initial x-coordinate
    Base_G[BaseG_Num-1].X = Doodle->X;
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-50; // give the Man its initial y-coordinate
    Base_G[BaseG_Num-1].Y = DISPLAY_HEIGHT-50;
    Doodle->base = DISPLAY_HEIGHT-50;
    Doodle->direction=0;
}
