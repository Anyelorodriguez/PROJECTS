#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <direct.h>

using namespace std;

void usuarios();
void emisor();
void receptor();
void conectados();

int main(){
   int j=1;

   while(j==1){
   	system("cls");
   	cout<<"\n";
   	 usuarios();
   	 emisor();
   	 cout<<"\nhistorial de mensajes";
	 receptor();
	 conectados();
	 cout<<"desea continuar en el programa? Si(1) No(2)";
	 cin>>j;
	 system("pause");
   }	
	return 0;
};

void emisor(){
   ofstream archivo;//nombre del archivo(similar a int numero)
   string texto;
   int i, opc;
//abrir archivo
   archivo.open("bambi.txt",ios::app);//abriendo el archivo, añadir texto//ubicacion

//verificar si el archivo se abrio correctamente
   if(archivo.fail()){
     cout<<"\nNo se pudo abrir el archivo.";
     exit(1);
    }
    
   do{
     fflush(stdin);//limpia el bufer//stdio.h
     cout<<"\nescriba su mensaje\n";
     getline(cin,texto);
     archivo<<texto<<endl;
     cout<<"desea seguir escribiendo? si(1)no(2)";
     cin>>i;
     cout<<"\n";
    }while(i==1);  

    archivo.close();
};

void receptor(){
	ifstream archivo;
    string texto;
    archivo.open("bambi.txt",ios::in);//abrir el archivo, solo lectura
	
    if(archivo.fail()){
        cout<<"\nNo se pudo abrir el archivo.";
        exit(1);
    }
    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
        cout<<texto<<endl;
        }
 archivo.close();
};

void usuarios(){
   ofstream archivo;//nombre del archivo(similar a int numero)
   string user;
   int x,r;

    fflush(stdin);//limpia el bufer//stdio.h
	cout<<"\ningrese su nombre de usuario";
    getline(cin,user);
    cout<<endl<<"\npresione(1) para conectarse"<<endl;
	cin>>x;

     if(x==1){
         archivo.open("users.txt",ios::app);//abriendo el archivo//ubicacion	
         //verificar si el archivo se abrio correctamente
         if(archivo.fail()){
             cout<<"\nNo se pudo abrir el archivo.";
             exit(1);
            } 
         archivo<<user<<" 1"<<endl;
         cout<<user<<" usuario conectado"<<endl;
         r=1;
	    }
	 else{
	     archivo<<"0";
	     cout<<"\nno esta conectado\n";
	    }
     //archivo<<user<<endl;
	 archivo.close();

};
void conectados(){
	ifstream archivo;//leer
	string texto;
	
 cout<<"personas conectadas:\n";
 archivo.open("users.txt",ios::in);//abrir el archivo 
  if(archivo.fail()){
     cout<<"\nNo se pudo abrir el archivo.";
     exit(1);
    }

    while(!archivo.eof()){  //mientras no sea el final del archivo
      getline(archivo,texto);
      cout<<texto<<endl;
	}
	archivo.close();
};

