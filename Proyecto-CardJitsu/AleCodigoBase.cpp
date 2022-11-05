#include <iostream>
#include <ctime>
#include "rlutil.h"
using namespace std;
void cargarMaso(string vec1[],int tam1,string vec2[],int tam2,int vec3[],int tam3){


int indice=1;

    for(int x=0;x<tam1;x++){

        vec3[x]=indice;
    indice++;
    if(indice==6){
        indice=1;
    }

        if(x>=0 && x<20){
        vec2[x]="FUEGO";
        }

        if(x>=20 && x<40){
        vec2[x]="AGUA";
        }

        if(x>=40 && x<60){
        vec2[x]="NIEVE";
        }

        if(x>=0 && x<5 || x>=20 && x<25 || x>=40 && x<45 ){
        vec1[x]="VERDE";

        }
        if(x>=5 && x<10 || x>=25 && x<30 || x>=45 && x<50 ){
        vec1[x]="AZUL";
        }
        if(x>=10 && x<15 || x>=30 && x<35 || x>=50 && x<55 ){
        vec1[x]="ROJO";
        }
        if(x>=15 && x<20 || x>=35 && x<40 || x>=55 && x<60 ){
        vec1[x]="AMARILLO";
        }

    }
}

int main(){

    string Elemento[60]{},CartaJugada;

    string Color[60]{},ManoCPU_CE[4][2]{},ManoJugador_CE[4][2]{},CartatiradaCE[2],CartatiradaCE_CPU[2];

    int ManoCPU_N[4]{},ManoJugador_N[4]{},indice2,Carta1,Carta2,Carta3,Carta4,CartaCPU1,CartatiradaN,CartatiradaN_CPU;
    int CartaCPU2,CartaCPU3,CartaCPU4,indice=1,Numero[60]{};
    char JugarCarta;


  cargarMaso(Elemento,60,Color,60,Numero,60);
    //Repartir cartas jugador-------------------------------------------------------------------------------------------------------------------------//
srand(time(0));

    Carta1=rand()%60+1;
     ManoJugador_CE[0][0]=Color[Carta1];
     ManoJugador_CE[0][1]=Elemento[Carta1];
     ManoJugador_N[0]=Numero[Carta1];
     cout<<Carta1<<endl;


    Carta2=rand()%60+1;

    if (Carta2==Carta1){
        while (Carta2!=Carta1){
            Carta2= rand()%60+1;
        }
    }
    ManoJugador_CE[1][0]=Color[Carta2];
    ManoJugador_CE[1][1]=Elemento[Carta2];
    ManoJugador_N[1]=Numero[Carta2];

    Carta3= rand()%60+1;
    if (Carta3==Carta1 ||Carta3==Carta2 ){
        while (Carta3!=Carta1 && Carta3!=Carta2){
            Carta3= rand()%60+1;
        }
    }
    ManoJugador_CE[2][0]=Color[Carta3];
    ManoJugador_CE[2][1]=Elemento[Carta3];
    ManoJugador_N[2]=Numero[Carta3];


    Carta4= rand()%60+1;
        if (Carta4==Carta1 ||Carta4==Carta2 || Carta4 == Carta3){
        while (Carta4!=Carta1 && Carta4!=Carta2&&Carta4 != Carta3){
            Carta4= rand()%60+1;
        }
    }
    ManoJugador_CE[3][0]=Color[Carta4];
    ManoJugador_CE[3][1]=Elemento[Carta4];
     ManoJugador_N[3]=Numero[Carta4];
    //Rrpartir cartas cpu-----------------------------------------------------------------------------------------------------------------------------//


    CartaCPU1=rand()%60+1;

    if (CartaCPU1==Carta1||CartaCPU1==Carta2||CartaCPU1==Carta3||CartaCPU1==Carta4){
        while (CartaCPU1!=Carta1 && CartaCPU1!=Carta2 && CartaCPU1!=Carta3&&CartaCPU1!=Carta4){
            CartaCPU1=rand()%60+1;
        }
    }
    ManoCPU_CE[0][0]=Color[CartaCPU1];
    ManoCPU_CE[0][1]=Elemento[CartaCPU1];
    ManoCPU_N[0]=Numero[CartaCPU1];
    CartaCPU2=rand()%60+1;

    if (CartaCPU2==Carta1||CartaCPU2==Carta2||CartaCPU2==Carta3||CartaCPU2==Carta4||CartaCPU2==CartaCPU1){
        while (CartaCPU2!=Carta1 && CartaCPU2!=Carta2 && CartaCPU2!=Carta3&&CartaCPU2!=Carta4&&CartaCPU2!=CartaCPU1){
            CartaCPU2=rand()%60+1;
        }
    }
    ManoCPU_CE[1][0]=Color[CartaCPU2];
    ManoCPU_CE[1][1]=Elemento[CartaCPU2];
    ManoCPU_N[1]=Numero[CartaCPU2];
    CartaCPU3=rand()%60+1;

    if (CartaCPU3==Carta1||CartaCPU3==Carta2||CartaCPU3==Carta3||CartaCPU3==Carta4||CartaCPU3==CartaCPU1||CartaCPU3==CartaCPU2){
        while (CartaCPU3!=Carta1 && CartaCPU3!=Carta2 && CartaCPU3!=Carta3&&CartaCPU3!=Carta4&&CartaCPU3!=CartaCPU1&&CartaCPU3!=CartaCPU2){
            CartaCPU3=rand()%60+1;
        }
    }
    ManoCPU_CE[2][0]=Color[CartaCPU3];
    ManoCPU_CE[2][1]=Elemento[CartaCPU3];
    ManoCPU_N[2]=Numero[CartaCPU3];
    CartaCPU4=rand()%60+1;
     if (CartaCPU4==Carta1||CartaCPU4==Carta2||CartaCPU4==Carta3||CartaCPU4==Carta4||CartaCPU4==CartaCPU1||CartaCPU4==CartaCPU3||CartaCPU4==CartaCPU2){
        while (CartaCPU3!=Carta1 && CartaCPU3!=Carta2 && CartaCPU3!=Carta3&&CartaCPU4!=Carta4&&CartaCPU4!=CartaCPU1&&CartaCPU4!=CartaCPU2&&CartaCPU4!=CartaCPU3){
            CartaCPU4=rand()%60+1;
        }
    }
    ManoCPU_CE[3][0]=Color[CartaCPU4];
    ManoCPU_CE[3][1]=Elemento[CartaCPU4];
    ManoCPU_N[3]=Numero[CartaCPU4];

    //----------------------------------------------------------------------------------------------------------------------------------------------------//
//rlutil::cls();
cout<<"Tus cartas de esta ronda son :"<<endl<<endl;
        cout<<"A Carta # "<<Numero[Carta1]<<" "<<Color[Carta1]<<" "<<Elemento[Carta1]<<endl;
    cout<<"B Carta # "<<Numero[Carta2]<<" "<<Color[Carta2]<<" "<<Elemento[Carta2]<<endl;
    cout<<"C Carta # "<<Numero[Carta3]<<" "<<Color[Carta3]<<" "<<Elemento[Carta3]<<endl<<endl;


    cout<<"Levante una carta del mazo(Enter)"<<endl<<endl;
    rlutil::anykey();
    rlutil::cls();


    cout<<"Tus cartas de esta ronda son :"<<endl<<endl;
    cout<<"A Carta # "<<Numero[Carta1]<<" "<<Color[Carta1]<<" "<<Elemento[Carta1]<<endl;
    cout<<"B Carta # "<<Numero[Carta2]<<" "<<Color[Carta2]<<" "<<Elemento[Carta2]<<endl;
    cout<<"C Carta # "<<Numero[Carta3]<<" "<<Color[Carta3]<<" "<<Elemento[Carta3]<<endl;
    cout<<"D Carta # "<<Numero[Carta4]<<" "<<Color[Carta4]<<" "<<Elemento[Carta4]<<endl<<endl;


/*cout<<"Las cartas del CPU en esta ronda son :"<<endl<<endl;

        cout<<"Carta # "<<Numero[CartaCPU1]<<" "<<Color[CartaCPU1]<<" "<<Elemento[CartaCPU1]<<endl;
    cout<<"Carta # "<<Numero[CartaCPU2]<<" "<<Color[CartaCPU2]<<" "<<Elemento[CartaCPU2]<<endl;
    cout<<"Carta # "<<Numero[CartaCPU3]<<" "<<Color[CartaCPU3]<<" "<<Elemento[CartaCPU3]<<endl<<endl;


*/

//Elegir carta------------------------------------------------------------------------------------------------------------------------------------------//
    cout<<"Juega una carta(A,B C o D )"<<endl<<endl;
    cin>>JugarCarta;
    rlutil::cls();
    cout<<"*************************"<<endl<<endl;
    switch (JugarCarta){

    case 'A':
    cout<<" Tiraste : "<<endl<<endl;
    cout<<"A Carta # "<<Numero[Carta1]<<" "<<Color[Carta1]<<" "<<Elemento[Carta1]<<endl<<endl;
        CartatiradaCE[0]=Color[Carta1];
        CartatiradaCE[1]=Elemento[Carta1];
        CartatiradaN=Numero[Carta1];

    break;

    case 'B' :
    cout<<" Tiraste : "<<endl<<endl;
        cout<<"B Carta # "<<Numero[Carta2]<<" "<<Color[Carta2]<<" "<<Elemento[Carta2]<<endl<<endl;
        CartatiradaCE[0]=Color[Carta2];
        CartatiradaCE[1]=Elemento[Carta2];
        CartatiradaN=Numero[Carta2];



    break;

    case 'C' :
    cout<<" Tiraste : "<<endl<<endl;

        cout<<"C Carta # "<<Numero[Carta3]<<" "<<Color[Carta3]<<" "<<Elemento[Carta3]<<endl<<endl<<endl;

        CartatiradaCE[0]=Color[Carta3];
        CartatiradaCE[1]=Elemento[Carta3];
        CartatiradaN=Numero[Carta3];





    break;
    case 'D' :
          cout<<" Tiraste : "<<endl<<endl;

        cout<<"D Carta # "<<Numero[Carta4]<<" "<<Color[Carta4]<<" "<<Elemento[Carta4]<<endl<<endl<<endl;

        CartatiradaCE[0]=Color[Carta4];
        CartatiradaCE[1]=Elemento[Carta4];
        CartatiradaN=Numero[Carta4];

break;
    }

     cout<<"+--------+            "<<endl;
   cout<<"|"<<CartatiradaN<<"       |"<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|       "<<CartatiradaN<<"|"<<endl;
   cout<<"+--------+"<<endl<<endl;
    cout<<"*************************"<<endl<<endl;


     srand(time(0));
     indice2=rand()%3+1;
     CartatiradaCE_CPU[0]=ManoCPU_CE[indice2][0];
     CartatiradaCE_CPU[1]=ManoCPU_CE[indice2][1];
     CartatiradaN_CPU=ManoCPU_N[indice2];
    cout<<"Carta que tira el CPU : "<<endl<<endl;
cout<<"Carta # "<<ManoCPU_N[indice2]<<" "<<ManoCPU_CE[indice2][0]<<" "<<ManoCPU_CE[indice2][1]<<endl<<endl;

 cout<<"+--------+            "<<endl;
   cout<<"|"<<CartatiradaN_CPU<<"       |"<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|        |            "<<endl;
   cout<<"|       "<<CartatiradaN_CPU<<"|"<<endl;
   cout<<"+--------+"<<endl<<endl;
   cout<<"*************************"<<endl<<endl;
   cout<<" "<<"# "<<CartatiradaN<<" "<<CartatiradaCE[0]<<" "<<CartatiradaCE[1]<<" contra "<<"# "<<CartatiradaN_CPU<<" "<<CartatiradaCE_CPU[0]<<" "<<CartatiradaCE_CPU[1]<<endl<<endl;
   cout<<" +----------------------------------------------------------+"<<endl;
   cout<<" |                                         |"<<endl;
   cout<<" | +--------+                             +--------+        |"<<endl;
   cout<<" | |"<<CartatiradaN<<"       |                           "<<"  |"<<CartatiradaN_CPU<<"       |        |"<<endl;
   cout<<" | |        |                             "<<"|        |        |"<<endl;
   cout<<" | |        |                             "<<"|        |        |"<<endl;
   cout<<" | |        |                             "<<"|        |        |"<<endl;
   cout<<" | |       "<<CartatiradaN<<"|                          "<<"   |       "<<CartatiradaN_CPU<<"|        |"<<endl;
   cout<<" | +--------+              VS           +--------+        |"<<endl;
   cout<<" |                                                          |"<<endl;
   cout<<" +----------------------------------------------------------+"<<endl<<endl;
   cout<<"*************************"<<endl<<endl;

//FUEGO VS NIEVE/FUEGO VS FUEGO---------------------------------------------------------------------------------------------------------------------------//
    if(CartatiradaCE[1]==("FUEGO")&&CartatiradaCE_CPU[1]==("NIEVE")){
    cout<<">>FUEGO le gana a NIEVE,Ganaste la ronda"<<endl<<endl;
    }
    else{ if (CartatiradaCE[1]==("FUEGO")&&CartatiradaCE_CPU[1]==("FUEGO")){
        if (CartatiradaN>CartatiradaN_CPU){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda"<<endl<<endl;
        }
    }
    }
    if(CartatiradaCE[0]==("NIEVE")&&CartatiradaCE_CPU[0]==("FUEGO")){
    cout<<">>FUEGO le gana a NIEVE,Perdiste la ronda "<<endl<<endl;
    }
//NIEVE VS AGUA/NIEVE VS NIEVE---------------------------------------------------------------------------------------------------------------------------//
    if(CartatiradaCE[0]==("NIEVE")&&CartatiradaCE_CPU[0]==("AGUA")){
    cout<<">>NIEVE le gana a AGUA,Ganaste la ronda"<<endl<<endl;
    }
    else{ if (CartatiradaCE[0]==("NIEVE")&&CartatiradaCE_CPU[0]==("NIEVE")){
        if (CartatiradaN>CartatiradaN_CPU){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda "<<endl<<endl;
        }
    }
    }
       if(CartatiradaCE[0]==("AGUA")&&CartatiradaCE_CPU[0]==("NIEVE")){
    cout<<">>NIEVE le gana a AGUA,Perdiste la ronda "<<endl<<endl;
       }
//AGUA VS FUEGO/AGUA VS AGUA------------------------------------------------------------------------------------------------------------------------//

    if(CartatiradaCE[0]==("AGUA")&&CartatiradaCE_CPU[0]==("FUEGO")){
    cout<<">>NIEVE le gana a AGUA,Ganaste la ronda"<<endl<<endl;
    }


    else{ if(CartatiradaCE[0]==("AGUA")&&CartatiradaCE_CPU[0]==("AGUA")){
        if (CartatiradaN>CartatiradaN_CPU){
            cout<<">>Ganaste la ronda por mayor numero"<<endl<<endl;
        }
        else{cout<<">>Perdiste la ronda "<<endl<<endl;
        }
    }
    }
   if(CartatiradaCE[0]==("FUEGO")&&CartatiradaCE_CPU[0]==("AGUA")){
    cout<<">>AGUA le gana a FUEGO,Perdiste la ronda "<<endl<<endl;
    }


//--------------------------------------------------------------------------------------------------------------------------------------------------------//


return 0;



    }

