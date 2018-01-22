#include "FunctionDef.h"
#include "Define.h"
#include "StructDef.h"
/*----------------Doodle-----------------*/

void Doodle_jump(GAMEDATA *gamedata, int Plat_Num, BASE *Base, ROLE *Doodle,BASE Prop[]){
/*Control the character jumping mode, up or down*/
/*Input Variable : Structure Pointer Role and Pointer Base and Prop*/
/*Output : void*/
    if(Doodle->state_S==0){
        if(Doodle->direction == 0){
            if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
                gamedata->move_hight += 3;
                page_move(gamedata, Plat_Num, Base, Doodle, Prop);
//                printf("move hight=%d\n",gamedata->move_hight);
            if(gamedata->move_hight > jumphight) {//if move over jump hight -> fall down
//                printf("DOWN!\n");
                Doodle->direction=1;
                gamedata->move_hight = 0;
            }
            }
            else Doodle->Y -= 3;
        }
        else{
            Doodle->Y += 3;
        }
    //    printf("\nbase=%lf\n",Doodle->base);
        if (Doodle->Y+DoodleH <= Doodle->base-jumphight &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH-jumphight)    Doodle->direction=1;//jump down

        if (Doodle->Y+DoodleH >= Doodle->base &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH)  Doodle->direction=0;//jump up

        if (Doodle->Y+DoodleH >= DISPLAY_HEIGHT)      Doodle->Y = DISPLAY_HEIGHT+100;
        if (Doodle->Y+DoodleH <= -10)                 Doodle->Y = 1;
    }
 //----------------------prop----------------------------
    else {
        if(Doodle->direction == 0){
            if(Doodle->Y <=DISPLAY_HEIGHT/3)  {
                gamedata->move_hight += 3;
                page_move(gamedata, Plat_Num, Base, Doodle, Prop);
//                printf("move hight=%d\n",gamedata->move_hight);
            if(gamedata->move_hight > jumphight) {//if move over jump hight -> fall down
//                printf("DOWN!\n");
//                Doodle->direction=1;
                gamedata->move_hight = 0;
            }
            }
            else Doodle->Y -= 15;
        }
        else{
            Doodle->Y += 3;
        }
    //    printf("\nbase=%lf\n",Doodle->base);
        if (Doodle->Y+DoodleH <= Doodle->base-jumphight-Propheight &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH-jumphight-Propheight)    Doodle->direction=1;//jump down

        if (Doodle->Y+DoodleH >= Doodle->base &&
            Doodle->Y+DoodleH <= Doodle->base+BaseH)  Doodle->direction=0;//jump up

        if (Doodle->Y+DoodleH >= DISPLAY_HEIGHT)      Doodle->Y = DISPLAY_HEIGHT+100;
        if (Doodle->Y+DoodleH <= -10)                 Doodle->Y = 1;
    }
}

void Plat_jump(int Plat_Num, BASE Base[], ROLE *Doodle, GAMEDATA *gamedata){
/*When the character step the plat, it will jump up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0; i <Plat_Num; i++){
        if(Doodle->direction == 1){
            if(Doodle->Y+DoodleH > Base[i].Y && Doodle->Y+DoodleH < Base[i].Y+BaseH){
                if(Doodle->X+DoodleW > Base[i].X+BaseSHIFT && Doodle->X < Base[i].X+BaseW-BaseSHIFT){
                    //level 1, level 2
                    if(gamedata->level != 3 && Base[i].HP != 0) {
                        Doodle->base = Base[i].Y;
                        Doodle->state_S = 0;
                        gamedata->move_hight=0;//initilaze move hight distance
                    }
                    //level 3
                    else if(gamedata->level == 3 && Base[i].HP != 0) {
                    Doodle->base = Base[i].Y;
                    Doodle->direction = 0;
                    Doodle->state_S = 0;
                    gamedata->move_hight=0;//initilaze move hight distance
                    Base[i].HP = 0;
                    }
                }
            }
        }
        else Doodle->base += 0.1;
    }
}
void Prop_jump(GAMEDATA *gamedata,ROLE *Doodle,BASE Prop[]){
/*When the character step the plat, it will jump up*/
/*Input Variable : Structure Pointer Role and Prop*/
/*Output : void*/
    for(int i = 0; i <Prop_Num/2; i++){
        if(Doodle->direction == 1){
            if(Doodle->Y+DoodleH > Prop[i].Y && Doodle->Y+DoodleH < Prop[i].Y+BaseH){
                if(Doodle->X+DoodleW > Prop[i].X+BaseSHIFT && Doodle->X < Prop[i].X+BaseW-BaseSHIFT){
                    //level 1, level 2
                    if(gamedata->level != 3 && Prop[i].HP != 0) {
                        Doodle->base = Prop[i].Y;
                        Doodle->state_S = 1;
                        Doodle->direction=0;
                        gamedata->move_hight=0;//initilaze move hight distance
                    }
                    //level 3
                    else if(gamedata->level == 3 && Prop[i].HP != 0) {
                    Doodle->base = Prop[i].Y;
                    Doodle->direction = 0;
                    Doodle->state_S = 1;
                    gamedata->move_hight=0;//initilaze move hight distance
                    Prop[i].HP = 0;
                    }
                }
            }
        }
        else Doodle->base += 0.1;
    }
//-----------rocket-----------
    for(int i = Prop_Num/2; i <Prop_Num; i++){
            if(Doodle->Y+DoodleH > Prop[i].Y && Doodle->Y+DoodleH < Prop[i].Y+Prop_H){
                if(Doodle->X+DoodleW > Prop[i].X+BaseSHIFT && Doodle->X < Prop[i].X+BaseW-BaseSHIFT){
                    //level 1, level 2
                    if(gamedata->level != 3 && Prop[i].HP != 0) {
                        Doodle->base = Prop[i].Y;
                        Doodle->state_S = 2;
                        Doodle->direction=0;
                        gamedata->move_hight=0;//initilaze move hight distance
                    }
                    //level 3
                    else if(gamedata->level == 3 && Prop[i].HP != 0) {
                    Doodle->base = Prop[i].Y;
                    Doodle->direction = 0;
                    Doodle->state_S = 2;
                    gamedata->move_hight=0;//initilaze move hight distance
                    Prop[i].HP = 0;
                    }
                }
            }
        else Doodle->base += 0.1;
    }


}
void Plat_move(BASE Base[],BASE Prop[]){
/*move plat B and Prop B*/
/*Input Variable : Structure Pointer Role and Base and Prop*/
/*Output : void*/
    for(int i=0; i<BaseB_Num; i++){
        if(Base[i].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Base[i].direction = Left;
        else if(Base[i].X+BaseSHIFT == 0) Base[i].direction = Right;

        if(Base[i].direction == Right) Base[i].X++;
        else if(Base[i].direction == Left) Base[i].X--;
    }

//-----------------spring----------------------

    if(Prop[1].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Prop[1].direction = Left;
    else if(Prop[1].X-BaseSHIFT+5 == 0) Prop[1].direction = Right;

    if(Prop[1].direction == Right) Prop[1].X++;
    else if(Prop[1].direction == Left) Prop[1].X--;
//-----------------rocket----------------------
    if(Prop[4].X+BaseW-BaseSHIFT == DISPLAY_WIDTH) Prop[4].direction = Left;
    else if(Prop[4].X-BaseSHIFT+5 == 0) Prop[4].direction = Right;

    if(Prop[4].direction == Right) Prop[4].X++;
    else if(Prop[4].direction == Left) Prop[4].X--;

}
void page_move(GAMEDATA *gamedata, int Plat_Num,  BASE Base[], ROLE *Doodle,BASE Prop[]){
/*When the character jump up, the page will also move up*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    for(int i = 0 ; i < Plat_Num ; i++){
        if(Doodle->state_S == 0)Base[i].Y += 3;
        if(Doodle->state_S == 1)Base[i].Y += 6;
        if(Doodle->state_S == 2)Base[i].Y += 21;

        if(Base[i].Y > DISPLAY_HEIGHT){
            Base[i].Y -= DISPLAY_HEIGHT;
            Base[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            Base[i].HP = 1;

            while((Base[i].X >= Base[i-1].X -150) &&
				  (Base[i].X <= Base[i-1].X + 150)){
                Base[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            }


        }
    }

    gamedata->Score += 3;

    if(Doodle->state_S == 2){

        Prop[0].Y +=15;
        Prop[1].Y +=15;
        Prop[2].Y +=15;
        Prop[3].Y +=15;
        Prop[4].Y +=15;
        Prop[5].Y +=15;
    }
    if(Doodle->state_S == 1){
        Prop[0].Y +=6;
        Prop[1].Y +=6;
        Prop[2].Y +=6;
        Prop[3].Y +=6;
        Prop[4].Y +=6;
        Prop[5].Y +=6;
    }
    else{
        Prop[0].Y +=3;
        Prop[1].Y +=3;
        Prop[2].Y +=3;
        Prop[3].Y +=3;
        Prop[4].Y +=3;
        Prop[5].Y +=3;
    }
}
void creat_Prop(GAMEDATA *gamedata,BASE Prop[]){
    for(int i = 0; i < Prop_Num/2 ; i++){
    if(gamedata->Score%737 >= 0 && gamedata->Score >737 && gamedata->Score%737 <=1  && Prop[i].HP==0){
        Prop[i].HP=1;
        Prop[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Prop[i].Y = -43;
//        printf("SPRING!");
    }
    if(abs(Prop[i].Y) > DISPLAY_HEIGHT){
        Prop[i].HP=0;
    }
  }
    for(int i = Prop_Num/2; i < Prop_Num ; i++){
        if(gamedata->Score%1097 >= 0 && gamedata->Score >1097 && gamedata->Score%1097 <=1  && Prop[i].HP==0){
            Prop[i].HP=1;
            Prop[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
            Prop[i].Y = -56;
//            printf(("ROCKET!"));
        }
        if(abs(Prop[i].Y) > DISPLAY_HEIGHT){
            Prop[i].HP=0;
        }
      }
}
void initilaze_coordinate(int Plat_Num,  BASE Base[], ROLE *Doodle,BASE Prop[]){
/*Set up the initial coordinate of the plat*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    int i, j;
    Base[0].X = rand()%(DISPLAY_WIDTH-BaseW +1);
    Base[0].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
    Base[0].HP = 0;
    for(i = 1; i < 11; i++){
        Base[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base[i].Y = i*90;
        Base[i].HP = 0;
    }
    for(i = 11; i < Plat_Num-12; i++){
        Base[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
        Base[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
        Base[i].HP = 0;
    }
    //check whether has near plat
    for(i = 11; i < Plat_Num-1; i++){
        for(j = i-1; j >= 0; j--){
            while((Base[i].X >= Base[j].X - 120) && (Base[i].X <= Base[j].X + 120) &&
                  (Base[i].Y >= Base[j].Y - 60) && (Base[i].Y <= Base[j].Y + 60)){
                   Base[i].X = rand()%(DISPLAY_WIDTH-BaseW +1);
                   Base[i].Y = rand()%(DISPLAY_HEIGHT-BaseH +1);
            }
        }
    }
    for(i = 0; i < Prop_Num; i++){
        Prop[i].HP=0;
        Prop[i].X = DISPLAY_WIDTH;
    }

    Doodle->X = rand()%(DISPLAY_WIDTH-DoodleW +1); // give the Man its initial x-coordinate
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-BaseH; // give the Man its initial y-coordinate
    Base[Plat_Num-1].HP = 0;
    Base[Plat_Num-1].X = Doodle->X+BaseSHIFT;
    Base[Plat_Num-1].Y = DISPLAY_HEIGHT-BaseH;
    Doodle->base = DISPLAY_HEIGHT-BaseH;
    Doodle->direction=0;
}

void initilaze_level(ROLE *Doodle, BASE Base[], int Plat_Num,BASE Prop[]){
/*Set up the initial coordinate of the level2*/
/*Input Variable : Structure Pointer Role and Base*/
/*Output : void*/
    int i;
    for(i=0;i<Plat_Num/2;i++){
        Base[i].direction = Right;
        Base[i].HP = 1;
    }
    for(;i<Plat_Num;i++){
        Base[i].direction = Left;
        Base[i].HP = 1;
    }
    Doodle->X = DISPLAY_WIDTH/2; // give the Man its initial x-coordinate
    Doodle->Y = DISPLAY_HEIGHT-DoodleH-BaseH; // give the Man its initial y-coordinate
    Base[Plat_Num-1].X = Doodle->X+BaseSHIFT;
    Base[Plat_Num-1].Y = DISPLAY_HEIGHT-BaseH;
    Doodle->base = DISPLAY_HEIGHT-BaseH;
    Doodle->direction=0;
    Doodle->state_S=0;
    Prop[1].direction = Right;
    Prop[2].HP = 1;
    Prop[4].direction = Right;
    Prop[5].HP = 1;
}

void ini_stoptime(GAMEDATA *gamedata){
    gamedata->level1_stoptime=0;
    gamedata->level2_stoptime=0;
    gamedata->level3_stoptime=0;
}
