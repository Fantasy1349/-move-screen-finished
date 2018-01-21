#include "FunctionDef.h"
#include "Define.h"
/*----------------Doodle-----------------*/

void Doodle_jump(ROLE *Doodle,BASE *Base_G, int *Score,int Plat_Num,BASE Prop[Prop_Num]){
/*Control the character jumping mode, up or down*/
/*Input Variable : Structure Pointer Role and Pointer Base*/
/*Output : void*/

    if(Doodle->state_S==0){
        if(Doodle->direction == 0){
            if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
            page_move(Doodle,Base_G,Score,Plat_Num,Prop);
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
    }

 //--------------------------prop----------------------------------
    else {           // doodle meet prop
        if(Doodle->direction == 0){
            if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
            page_move(Doodle,Base_G,Score,Plat_Num,Prop);
    //        Doodle->Y=Doodle->Y;
            }
            else Doodle->Y-=15;
        }
        else{
            Doodle->Y+=3;
        }
        if (Doodle->Y+DoodleH <= Doodle->base-jumphight - 250 &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH-jumphight - 250)    Doodle->direction = 1;//higher than normal plat

        if (Doodle->Y+DoodleH >= Doodle->base &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH)  Doodle->direction = 0;//jump up

        if (Doodle->Y+DoodleH >= DISPLAY_HEIGHT)      Doodle->Y = DISPLAY_HEIGHT + 100;
}
}

void Plat_jump(ROLE *Doodle,BASE Base_G[],int Plat_Num,int level){
/*When the character step the plat, it will jump up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0;i <Plat_Num;i++){
        if(Doodle->Y+DoodleH >= Base_G[i].Y && Doodle->Y+DoodleH <= Base_G[i].Y+BaseH&& Doodle->direction==1){
            if(Doodle->X+DoodleW >= Base_G[i].X+BaseSHIFT && Doodle->X <= Base_G[i].X+BaseW-BaseSHIFT){

                if(level != 3){
                    Doodle->base = Base_G[i].Y;
                    Doodle->state_S = 0;

                }
                //level 1, level 2
                else if(level == 3 && Base_G[i].HP != 0) {
                Doodle->base = Base_G[i].Y;
                Doodle->direction = 0;
                Base_G[i].HP = 0;
                Doodle->state_S = 0;
                }
                //level 3
            }
        }
        else Doodle->base += 0.1;
    }
}
void Prop_jump(ROLE *Doodle,BASE Prop[Prop_Num],int level){
/*When the character step the prop, it will jump up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/

    int i;

    for(i=0;i < Prop_Num/2;i++){
        if(Doodle->Y+DoodleH >= Prop[i].Y && Doodle->Y+DoodleH <= Prop[i].Y+42&& Doodle->direction==1){
            if(Doodle->X+DoodleW >= Prop[i].X+BaseSHIFT && Doodle->X <= Prop[i].X+57-BaseSHIFT){

                if(level != 3){
                    Doodle->state_S = 1;
                    Doodle->base = Prop[i].Y;
                    Doodle->direction = 0;
                }
                //level 1, level 2
                else if(level == 3 && Prop[i].HP != 0) {
                Doodle->base = Prop[i].Y;
                Doodle->direction = 0;
                Doodle->state_S = 1;
                Prop[i].HP = 0;
                }
                //level 3
            }
        }
        else Doodle->base += 0.1;
    }
    for(i = Prop_Num/2; i < Prop_Num; i++){
        if(Doodle->Y+DoodleH >= Prop[i].Y && Doodle->Y+DoodleH <= Prop[i].Y+42&& Doodle->direction==1){
            if(Doodle->X+DoodleW >= Prop[i].X+BaseSHIFT && Doodle->X <= Prop[i].X+57-BaseSHIFT){

                if(level != 3){
                    Doodle->state_S = 2;
                    Doodle->base = Prop[i].Y;
                    Doodle->direction = 0;
                }
                //level 1, level 2
                else if(level == 3 && Prop[i].HP != 0) {
                Doodle->base = Prop[i].Y;
                Doodle->direction = 0;
                Doodle->state_S = 2;
                Prop[i].HP = 0;
                }
                //level 3
            }
        }
        else Doodle->base += 0.1;
    }
}
void Plat_move(BASE Base_B[BaseB_Num],BASE Prop[Prop_Num]){
/*move plat B*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i=0;i<BaseB_Num;i++){
        if(Base_B[i].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Base_B[i].direction = Left;
        else if(Base_B[i].X-BaseSHIFT == 0) Base_B[i].direction = Right;

        if(Base_B[i].direction == Right) Base_B[i].X++;
        else if(Base_B[i].direction == Left) Base_B[i].X--;
    }

//-----------------spring----------------------

    if(Prop[1].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Prop[1].direction = Left;
    else if(Prop[1].X-BaseSHIFT == 0) Prop[1].direction = Right;

    if(Prop[1].direction == Right) Prop[1].X++;
    else if(Prop[1].direction == Left) Prop[1].X--;
//-----------------rocket----------------------
    if(Prop[4].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Prop[4].direction = Left;
    else if(Prop[1].X-BaseSHIFT == 0) Prop[4].direction = Right;

    if(Prop[4].direction == Right) Prop[4].X++;
    else if(Prop[4].direction == Left) Prop[4].X--;

}
void page_move(ROLE *Doodle,BASE Base_G[BaseG_Num], int *Score,int Plat_Num,BASE Prop[Prop_Num]){
/*When the character jump up, the page will also move up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0 ; i < Plat_Num ; i++){
        if(Doodle->state_S == 0)Base_G[i].Y += 3;
        if(Doodle->state_S == 1)Base_G[i].Y += 7;
        if(Doodle->state_S == 1)Base_G[i].Y += 27;


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
    Score[0] += 3;

    if(Doodle->state_S == 0){
        Prop[0].Y +=3;
        Prop[1].Y +=3;
        Prop[2].Y +=3;
        Prop[3].Y +=3;
        Prop[4].Y +=3;
        Prop[5].Y +=3;
    }
    else{
        Prop[0].Y +=15;
        Prop[0].Y +=15;
        Prop[1].Y +=15;
        Prop[1].Y +=15;
        Prop[2].Y +=15;
        Prop[2].Y +=15;
        Prop[3].Y +=15;
        Prop[3].Y +=15;
        Prop[4].Y +=15;
        Prop[4].Y +=15;
        Prop[5].Y +=15;
        Prop[5].Y +=15;

    }



}
void creat_Prop(int *Score,BASE Prop[Prop_Num],int level){


    int i;
//---------spring--------------
    for(i = 0; i < Prop_Num/2 ; i++){
    if(*Score%737 >= 0 && *Score >737 && *Score%737 <=1  && Prop[i].HP==0){
        Prop[i].HP=1;
        Prop[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Prop[i].Y = -43;
        printf("SPRING!");
    }
    if(abs(Prop[i].Y) > DISPLAY_HEIGHT){
        Prop[i].HP=0;
    }
  }
  //------rocket----------------
  for(i = Prop_Num/2; i < Prop_Num/2 ; i++){
    if(*Score%1097 >= 0 && *Score >1097 && *Score%1097 <=1  && Prop[i].HP==0){
        Prop[i].HP=1;
        Prop[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Prop[i].Y = -56;
        printf(("ROCKET!"));
    }
    if(abs(Prop[i].Y) > DISPLAY_HEIGHT){
        Prop[i].HP=0;
    }
  }
}
void initilaze_coordinate(ROLE *Doodle,BASE Base_G[BaseG_Num],int Plat_Num,BASE Prop[Prop_Num]){
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

    for(i = 0; i < Prop_Num; i++){

        Prop[i].HP=0;
    }


    Doodle->X = rand()%(DISPLAY_WIDTH-DoodleW +1); // give the Man its initial x-coordinate
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-BaseH; // give the Man its initial y-coordinate
    Doodle->state_S=0;
    Base_G[Plat_Num-1].X = Doodle->X+BaseSHIFT;
    Base_G[Plat_Num-1].Y = DISPLAY_HEIGHT-BaseH;
    Doodle->base = DISPLAY_HEIGHT-BaseH;
    Doodle->direction=0;
}

void initilaze_level(ROLE *Doodle,BASE Base_B[],int Plat_Num,BASE Prop[Prop_Num]){
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
    Prop[1].direction = Right;
    Prop[2].HP = 1;
    Prop[4].direction = Right;
    Prop[5].HP = 1;

}

