#include <iostream>
#include <fstream>
#include <stdio.h>//system("cls"); limpia la pantalla

using namespace std;

void menu ();
void chat ();
void usuarios();
void lectusu();

int main (void){
	menu();
	
};


void menu(){
	int opcion;
	cout<<"Menu\n"<<"1.chatear\n"<<"2.Salir\n"<<"Digite su opcion: ";
	cin>>opcion;
	switch(opcion){
	case 1:
	system ("cls");	
	cout<<"Chat\n";
	usuarios();	
	chat();
	break;
	//
	case 2:
	cout<<"Hasta pronto uwu/\n";
	system ("pause");
	break;
//	
	default:
	cout<<"opcion invalida";
	system ("pause");
	system ("cls");
	menu();
	break;	
	}
	
}
void chat(){
	int s=1;
	ofstream uno;
	ifstream lectura;
	string mensaje, texto;
	//escribir en el archivo
	uno.open("historial.txt",ios::app);
	//bluce para escibir 			
	do{
		cout<<"Usuarios conectados: ";
		lectusu();
		
		//bucle para leer todo el archivo
		lectura.open("historial.txt",ios::in);
		while(!lectura.eof()){//mientras no sea el final del archivo
			getline(lectura,texto);
			cout<<texto<<"\n";	
		}
		lectura.close();
		//escribir mensaje		
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,mensaje);
		uno<<mensaje<<endl;
		//mensaje para seguir escribiendo
		cout<<"Desea seguir escribiendo? si(1) no(2): ";
		cin>>s;
		system("cls");
	}while((s == 1));	
	uno.close();
}


void usuarios(){
	ofstream usuarios;
	string usu;

	//escribir en el archivo
	usuarios.open("usuarios.txt",ios::app);
	//bluce para escibir 			

		fflush(stdin);
		cout<<"Digite el nombre usuario: ";
		getline(cin,usu);
		usuarios<<usu<<endl;
		
	usuarios.close();
}

void lectusu(){
	
	ifstream lectusu;
	string user;
	
	lectusu.open("usuarios.txt",ios::in);
	
	while(!lectusu.eof()){//mientras no sea el final del archivo
	getline(lectusu,user);
	cout<<user<<endl;
	}
	
	lectusu.close();
	
}


