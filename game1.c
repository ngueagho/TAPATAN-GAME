#include<stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct game1
    {
        int value;
        char id ;
    } game;
    int possibilite_joueur1=1;
    int possibilite_joueur2=0;
    char gamer_name1[20];
    char gamer_name2[20];
    int nouvelle_position;
    int encienne_position;
    int id;

    int i=0 ,j=0;int k=0;
    game terrain[3][3];
    /*the next function is used to redisplay the map when a point is moved */
    void afficher ()
    {
        printf("\n\n\n\n                     --- --- ---\n");
        printf("                    | %c | %c | %c |\n",terrain[0][0].id ,terrain[0][1].id, terrain[0][2].id);
        printf("                     --- --- ---\n");
        printf("                    | %c | %c | %c |\n",terrain[1][0].id ,terrain[1][1].id, terrain[1][2].id);
        printf("                     --- --- ---\n");
        printf("                    | %c | %c | %c |\n",terrain[2][0].id ,terrain[2][1].id, terrain[2][2].id);
        printf("                     --- --- ---\n");
    }

    /*the next function is used to tell if it is the end of the game or nota*/
    int fin(){
        int total=0;
            if(((terrain[0][0].value +terrain[0][1].value+ terrain[0][2].value)==3)||((terrain[1][0].value +terrain[1][1].value+ terrain[1][2].value)==3)||((terrain[2][0].value +terrain[2][1].value+ terrain[2][2].value)==3))
            {
                printf("victoire %s :) ...\n",gamer_name1);
                return 1;
            }else if(((terrain[0][0].value +terrain[1][0].value+ terrain[2][0].value)==3)||((terrain[0][1].value +terrain[1][1].value+ terrain[2][1].value)==3)||((terrain[0][2].value +terrain[1][2].value+ terrain[2][2].value)==3))
            {
                printf("victoire %s :) ... \n",gamer_name1);
                return 1;
            }
            else if(((terrain[0][0].value +terrain[1][1].value+ terrain[2][2].value)==3)||((terrain[2][0].value +terrain[1][1].value+ terrain[0][2].value)==3)){
                printf("victoire %s :) ... \n",gamer_name1);
                return 1;
            }
///////////////
            else if(((terrain[0][0].value +terrain[0][1].value+ terrain[0][2].value)==21)||((terrain[1][0].value +terrain[1][1].value+ terrain[1][2].value)==21)||((terrain[2][0].value +terrain[2][1].value+ terrain[2][2].value)==21))
            {
                printf("victoire %s :) ...\n",gamer_name2);
                return 1;
            }else if(((terrain[0][0].value +terrain[1][0].value+ terrain[2][0].value)==21)||((terrain[0][1].value +terrain[1][1].value+ terrain[2][1].value)==21)||((terrain[0][2].value +terrain[1][2].value+ terrain[2][2].value)==21))
            {
                printf("victoire %s :) ...\n",gamer_name2);
                return 1;
            }
            else if(((terrain[0][0].value +terrain[1][1].value+ terrain[2][2].value)==21)||((terrain[2][0].value +terrain[1][1].value+ terrain[0][2].value)==21)){
                printf("victoire %s :) ...\n",gamer_name2);
                return 1;
            }
            else{
                return 0;
            }
    }
    // int monter(int i, int j){
    //     if(i==0){
    //         printf("impossible de monter\n");
    //         return 1;
    //     }
    //     else if(terrain[i-1][j].value!=0){
    //         printf("impossible de monter\n");
    //         return 1;
    //     }
    //     else{
    //         terrain[i-1][j].id= terrain[i][j].id;
    //         terrain[i-1][j].value= terrain[i][j].value;
    //         terrain[i][j].id= ' ';
    //         terrain[i][j].value =0;
    //         return 0;
    //     }
    // }
    // int descendre(int i, int j){
    //     if(i==3){
    //         printf("impossible de descendre\n");
    //         return 1;
    //     }
    //     else if(terrain[i+1][j].value!=0){
    //         printf("impossible de monter\n");
    //         return 1;
    //     }
    //     else{
    //         terrain[i+1][j].id= terrain[i][j].id;
    //         terrain[i+1][j].value= terrain[i][j].value;
    //         terrain[i][j].id= ' ';
    //         terrain[i][j].value =0;
    //         return 0;
    //     }

    // }
    // int gauche(int i, int j){
    //     if(j==0){
    //         printf("impossible d'aller a gauche\n");
    //         return 1;
    //     }
    //     else if(terrain[i][j-1].value!=0){
    //         printf("impossible de monter\n");
    //         return 1;
    //     }
    //     else{
    //         terrain[i][j-1].id= terrain[i][j].id;
    //         terrain[i][j-1].value= terrain[i][j].value;
    //         terrain[i][j].id= ' ';
    //         terrain[i][j].value =0;
    //         return 0;
    //     }


    // }
    // int droite(int i, int j){
    //     if(j==3){
    //         printf("impossible d'aller a droite\n");
    //         return 1;
    //     }
    //     else if(terrain[i][j+1].value!=0){
    //         printf("impossible de monter\n");
    //         return 1;
    //     }
    //     else{
    //         terrain[i][j+1].id= terrain[i][j].id;
    //         terrain[i][j+1].value= terrain[i][j].value;
    //         terrain[i][j].id= ' ';
    //         terrain[i][j].value =0;
    //         return 0;
    //     }

    // }
    /*the next function like his name said return the absciss of the position enter by the gamer*/
    int return_abscisse(int position){
        if((position==1)||(position==2)||(position==3)){
            return 0;
        }
        else if((position==4)||(position==5)||(position==6)){
            return 1;
        }
        else if((position==7)||(position==8)||(position==9)){
            return 2;
        }
        else{
            printf("ERROR : element out of the range\n");
        }
    }
     /*the next function like his name said return the absciss of the position enter by the gamer*/
    int return_ordonne(int position){
        if((position==1)||(position==4)||(position==7)){
            return 0;
        }
        else if((position==2)||(position==5)||(position==8)){
            return 1;
        }
        else if((position==3)||(position==6)||(position==9)){
            return 2;
        }
        else{
            printf("ERROR : element out of the range\n");
        }
    }

    /*this function tests if the entered position is empty and if we are still on the ground*/
    int tester_position(int position){
        if((terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].value==0)&&( (position==1)||  (position==2)||  (position==3)|| (position==4)||  (position==5)||  (position==6)||  (position==7)|| (position==8)|| (position==9))){
            return 1;
        }
        else{
            printf("ERROR : either the place specified is out of the bord or it is not free\n");
            printf("------------>please retry\n");
            return 0;
        }
    }
    /*this function tests whether, based on our current position, the movement we want to make is possible*/
    int tester_si_on_vas_dans_une_bonne_case(){
        if((encienne_position==1)&&((nouvelle_position==2)||(nouvelle_position==4)||(nouvelle_position==5))){
            return 1;
        }
        else if((encienne_position==2)&&((nouvelle_position==1)||(nouvelle_position==3)||(nouvelle_position==5))){
            return 1;
        }
        else if((encienne_position==3)&&((nouvelle_position==2)||(nouvelle_position==5)||(nouvelle_position==6))){
            return 1;
        }
        else if((encienne_position==4)&&((nouvelle_position==1)||(nouvelle_position==5)||(nouvelle_position==7))){
            return 1;
        }
        if((encienne_position==5)&&((nouvelle_position==1)||(nouvelle_position==2)||(nouvelle_position==3)||(nouvelle_position==4)||(nouvelle_position==6)||(nouvelle_position==7)||(nouvelle_position==8)||(nouvelle_position==9))){
            return 1;
        }
        else if((encienne_position==6)&&((nouvelle_position==3)||(nouvelle_position==5)||(nouvelle_position==9))){
            return 1;
        }
        else if((encienne_position==7)&&((nouvelle_position==4)||(nouvelle_position==5)||(nouvelle_position==8))){
            return 1;
        }
        else if((encienne_position==8)&&((nouvelle_position==5)||(nouvelle_position==7)||(nouvelle_position==9))){
            return 1;
        }
        else if((encienne_position==9)&&((nouvelle_position==5)||(nouvelle_position==6)||(nouvelle_position==8))){
            return 1;
        }
        else{
            printf("ERROR: the position specified is nor valid");
            printf("------------>please retry\n");
            return 0;
        }



    }

    /*this function is used to place pions on the ground during intitialisation*/
    void deplacer(){
        if((id==1)&&(possibilite_joueur1==1)){
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].id='x';
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].value=1;
            possibilite_joueur1=0;
            possibilite_joueur2=1;
        }
        else if((id==2)&&(possibilite_joueur2==1)){
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].id='0';
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].value=7;
            possibilite_joueur1=1;
            possibilite_joueur2=0;
        }
        else{
            printf("ERROR : please verify all the elements\n");
        }
    }
    /*this function is used to move pion on the ground during the game*/
    void deplacement(){
        if((id==1)&&(possibilite_joueur1==1)){
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].id='x';
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].value=1;
            terrain[return_abscisse(encienne_position)][return_ordonne(encienne_position)].id=' ';
            terrain[return_abscisse(encienne_position)][return_ordonne(encienne_position)].value=0;
            possibilite_joueur1=0;
            possibilite_joueur2=1;
        }
        else if((id==2)&&(possibilite_joueur2==1)){
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].id='0';
            terrain[return_abscisse(nouvelle_position)][return_ordonne(nouvelle_position)].value=7;
            terrain[return_abscisse(encienne_position)][return_ordonne(encienne_position)].id=' ';
            terrain[return_abscisse(encienne_position)][return_ordonne(encienne_position)].value=0;
            possibilite_joueur1=1;
            possibilite_joueur2=0;
        }
        else{
            printf("ERROR : please verify all the elements\n");
        }
    }

        /*this function is used to test if it our round to game*/
        int  tester_si_on_peut_jouer(int id){
        if(id==1){
            if((possibilite_joueur1==1))          {
                return 1;
            }
            else{
                printf("ERROR : please check again the id entered // ca peut ne pas etre votre tour\n");
                printf("------------>please retry\n");
                return 0;
            }
        }
        else if(id==2){
            if((possibilite_joueur2==1))
            {
                return 1;//on ne peut jour car c'est notre tour
            }
            else{
                printf("ERROR : please check again the id entered // ca peut ne pas etre votre tour\n");
                printf("------------>please retry\n");
                return 0;
            }
        }
        else{
            printf("ERROR : verify your id\n");
            printf("------------>please retry\n");
            return 0;
        }
    }


/*this function is used to place all the 6 pions before the game begin*/
    void intialisation(){
        int i;
        printf("initialisation:\n");
        printf("chacun des joueurs se doit de placer ces trois pions sur le terrain\n");
        printf("les possibilites de positionnement vont de 1->9 comme decrit ci-dessous\n\n");


        printf("                     --- --- ---\n");
        printf("                    | %d | %d | %d |\n",1 ,2, 3);
        printf("                     --- --- ---\n");
        printf("                    | %d | %d | %d |\n",4 ,5, 6);
        printf("                     --- --- ---\n");
        printf("                    | %d | %d | %d |\n",7 ,8, 9);
        printf("                     --- --- ---\n");

        printf("\npour placer un pion le joueur se doit d'entrer son id, et a la suite la position du pion.\n");
        printf("par defaut %s commence et a pour id=1 ,%s jouera apres et ainsi de suite jusqua la fin\n",gamer_name1,gamer_name2);
        printf("%s lui a pour id=2\n",gamer_name2);



        for(i=0; i<3;i++){
            do{
                printf("\n\n%s joue : id = 1   et %d pions restant a placer\n",gamer_name1,3-i);
                printf("id joueur\n");
                scanf("%d",&id);
                printf("position pion\n");
                scanf("%d",&nouvelle_position);

            }while((tester_si_on_peut_jouer(id)==0)||(tester_position(nouvelle_position)==0));
            deplacer();
            system("clear");
            afficher();

            do{
                printf("\n\n%s joue : id = 2   et %d pions restant a placer\n",gamer_name2,3-i);
                printf("id joueur\n");
                scanf("%d",&id);
                printf("position pion\n");
                scanf("%d",&nouvelle_position);

            }while((tester_si_on_peut_jouer(id)==0)||(tester_position(nouvelle_position)==0));
            deplacer();
            system("clear");
            afficher();
        }
    }



    /*this function is to game*/
    void jeux(){
        intialisation();
        fin();
        printf("Debut jeux :)\n");
        printf("chacun des joueurs a maintenant ces trois pions sur le terrain\n\n");
        afficher();

        printf("\npour deplacer un pion le joueur se doit d'entrer son id, et a la suite la position actuelle du pion et enfin la nouvelle position.\n");
        while(fin()==0){
            printf("\n\n%s joue id =1 joue avec les X\n",gamer_name1);
            do{
                printf("id joueur\n");
                scanf("%d",&id);
                printf("encienne position pion\n");
                scanf("%d",&encienne_position);
                printf("nouvelle position pion\n");
                scanf("%d",&nouvelle_position);

            }while((tester_si_on_peut_jouer(id)==0)||(tester_position(nouvelle_position)==0)||(tester_si_on_vas_dans_une_bonne_case()==0));
            deplacement();
            system("clear");
            afficher();

            printf("\n\n%s joue id =2 joue avec les 0\n",gamer_name2);
            do{
                printf("id joueur\n");
                scanf("%d",&id);
                printf("encienne position pion\n");
                scanf("%d",&encienne_position);
                printf("nouvelle position pion\n");
                scanf("%d",&nouvelle_position);

            }while((tester_si_on_peut_jouer(id)==0)||(tester_position(nouvelle_position)==0)||(tester_si_on_vas_dans_une_bonne_case()==0));
            deplacement();
            system("clear");
            afficher();


        }
    }



int main(){
    for(i=0;i<3;i++){
        for (j=0; j <3; j++)
        {
            terrain[i][j].value=0;
            terrain[i][j].id = ' ';
            k=k+1;
        }
    }

    printf("**************WELCOME TO MY GAME***************\n\n");
    printf("enter the name of the first gamer\n");
    scanf("%s",gamer_name1);
    printf("enter the name of the second gamer\n");
    scanf("%s",gamer_name2);
    printf("**************WELCOME AGAIN TO MY GAME***************\n\n");
    printf("              %s V/S %s\n",gamer_name1 , gamer_name2);
    afficher();

    jeux();
    return 0;
}