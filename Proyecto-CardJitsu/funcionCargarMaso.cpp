#include <iostream>
#include <ctime>
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

	 string Color[60]={},Elemento[60]={};
	 int Numero[60]={};
	 cargarMaso(Color,60,Elemento,60,Numero,60);
	 	for(int y=0;y<60;y++){
    cout<<"#"<<Numero[y]<<" ";
    cout<<Color[y]<<" ";
    cout<<Elemento[y]<<endl;


	}
	 return 0;

}
