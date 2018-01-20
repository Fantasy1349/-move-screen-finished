#include "FunctionDef.h"
#include "Define.h"
/*----------------Doodle-----------------*/

void Doodle_jump(ROLE *Doodle,BASE *Base_G, int *Score,int Plat_Num){
/*Control the character jumping mode, up or down*/
/*Input Variable : Structure Pointer Role and Pointer Base*/
/*Output : void*/
    if(Doodle->direction == 0){
        if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
        page_move(Doodle,Base_G,Score,Plat_Num);
//        Doodle->Y=Doodle->Y;
        }
        else Doodle->Y-=3;
    }
    else{
        Doodle->Y+=3;
    }
//    printf("\nbase=%lf\n",Doodle->base);
    if (Doodle->Y+DoodleH <= Doodle->base-jumphight &&
        Doodle->Y+DoodleH <= Doodle->base+BaseH-jumphight)    Doodle->direction=1;//jump down

    if (Doodle->Y+DoodleH >= Doodle->base &&
        Doodle->Y+DoodleH <= Doodle->base+BaseH)  Doodle->direction=0;//jump up

    if (Doodle->Y+DoodleH >= DISPLAY_HEIGHT)      Doodle->Y = DISPLAY_HEIGHT+100;
    if (Doodle->Y+DoodleH <= -10)                 Doodle->Y = 1;
}

void Plat_jump(ROLE *Doodle,BASE Base_G[],int Plat_Num,int level){
/*When the character step the plat, it will jump up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0;i <Plat_Num;i++){
        if(Doodle->Y+DoodleH >= Base_G[i].Y && Doodle->Y+DoodleH <= Base_G[i].Y+BaseH&& Doodle->direction==1){
            if(Doodle->X+DoodleW >= Base_G[i].X+BaseSHIFT && Doodle->X <= Base_G[i].X+BaseW-BaseSHIFT){

                if(level != 3) Doodle->base = Base_G[i].Y;
                //level 1, level 2
                else if(level == 3 && Base_G[i].HP != 0) {
                Doodle->base = Base_G[i].Y;
                Base_G[i].HP = 0;
                }
                //level 3
            }
        }
        else Doodle->base += 0.1;
    }
}
void Plat_move(BASE Base_B[BaseB_Num]){
/*move plat B*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i=0;i<BaseB_Num;i++){
        if(Base_B[i].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Base_B[i].direction = Left;
        else if(Base_B[i].X-BaseSHIFT == 0) Base_B[i].direction = Right;

        if(Base_B[i].direction == Right) Base_B[i].X++;
        else if(Base_B[i].direction == Left) Base_B[i].X--;
    }
}
void page_move(ROLE *Doodle,BASE Base_G[BaseG_Num], int *Score,int Plat_Num){
/*When the character jump up, the page will also move up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0 ; i < Plat_Num ; i++){
        Base_G[i].Y += 3;
        Score[0] += 3;

        if(Base_G[i].Y > DISPLAY_HEIGHT){
            Base_G[i].Y -= DISPLAY_HEIGHT;
            Base_G[i].X  = rand()%(DISPLAY_WIDTH-BaseW +1);
            Base_G[i].HP = 1;

            while((Base_G[i].X >= Base_G[i-1].X -150) &&(Base_G[i].X <= Base_G[i-1].X + 150)){
                Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            }

            while((Doodle->X >= Base_G[i].X -30) && (Doodle->X <= Base_G[i].X +90)){
                Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            }
        }
    }
}

void initilaze_coordinate(ROLE *Doodle,BASE Base_G[BaseG_Num],int Plat_Num){
/*Set up the initial coordinate of the plat*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    int i, j;

    for(i = 0; i < 10; i++){
        Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base_G[i].Y = i*100;
    }
    for(i = 10; i < Plat_Num-11; i++){
        Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base_G[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
    }
    //check whether has near plat
    for(i = 10; i < Plat_Num-1; i++){
        for(j = i-1; j >= 0; j--){
            while((Base_G[i].X >= Base_G[j].X - 120) && (Base_G[i].X <= Base_G[j].X + 120) &&
                  (Base_G[i].Y >= Base_G[j].Y - 60) && (Base_G[i].Y <= Base_G[j].Y + 60)){
                   Base_G[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
                   Base_G[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
            }
        }
    }

    Doodle->X = rand()%(DISPLAY_WIDTH-DoodleW +1); // give the Man its initial x-coordinate
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-BaseH; // give the Man its initial y-coordinate
    Base_G[Plat_Num-1].X = Doodle->X+BaseSHIFT;
    Base_G[Plat_Num-1].Y = DISPLAY_HEIGHT-BaseH;
    Doodle->base = DISPLAY_HEIGHT-BaseH;
    Doodle->direction=0;
}

void initilaze_level(ROLE *Doodle,BASE Base_B[],int Plat_Num){
/*Set up the initial coordinate of the level2*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    int i;
    for(i=0;i<Plat_Num/2;i++){
        Base_B[i].direction = Right;
        Base_B[i].HP = 1;
    }
    for(;i<Plat_Num;i++){
        Base_B[i].direction = Left;
        Base_B[i].HP = 1;
    }
    Doodle->X = DISPLAY_WIDTH/2; // give the Man its initial x-coordinate
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-BaseH; // give the Man its initial y-coordinate
    Base_B[Plat_Num-1].X = Doodle->X+BaseSHIFT;
    Base_B[Plat_Num-1].Y = DISPLAY_HEIGHT-BaseH;
    Doodle->base = DISPLAY_HEIGHT-BaseH;
    Doodle->direction=0;
}

