#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>

using namespace std;

void R_conectividad();
int Menu();
void Mensajes();

int main(){
	
	system("cls");
	Menu();
	system("pause");
	cout<<"\tFin de programa, Hasta luego";
	
};

void Lectura(){
	
	ifstream archivo;
	string texto;
	system("cls");
	
	archivo.open("mensajes.txt",ios::in);//abrimos el archivo en modo lectura
	if(archivo.fail()){
		cout<<"\tHouston, tenemos un problema,El archivo no se pudo abrir"<<endl;
		system("pause");
		exit(1);
	}
	while(!archivo.eof()){  //mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
};

void Mensajes(){
	int con,i=0;
	static ofstream archivo;
	static ofstream conectividad;
	string texto,user;
	system("cls");
	do{
		system("cls");
		cout<<"Conversacion en curso: "<<endl;
		Lectura();
		cout<<endl;
		cout<<"\tDigita tu Nombre de usuario: ";
		fflush(stdin);
		getline(cin,user);
		cout<<endl<<"\tActivar Conexion (1)"<<endl;
		cin>>con;
		if(con==1){
			conectividad.open("conectividad.txt",ios::app);
			if(archivo.fail()){
			cout<<"\tError no se pudo abrir el archivo"<<endl;
			system("pause");
			exit(1);
			}
			conectividad<<user<<"\t: 1"<<endl;
			cout<<"\tBienvenido "<<user<<" Ahora estas conectado"<<endl;
			i=1;
		}else{
			conectividad<<"0";
			cout<<"\tIntenta conectarte de nuevo";
		}
		conectividad.close();
	}while(i=0);
		
	archivo.open("mensajes.txt",ios::app);//abrimos el archivo en modo editable
	if(archivo.fail()){
		cout<<"\tError no se pudo abrir el archivo"<<endl;
		system("pause");
		exit(1);
	}
	cout<<"\tEscribe un mensaje: "<<endl;
	fflush(stdin);
	getline(cin,texto);
	archivo<<user<<": "<<texto<<endl;
	archivo.close();
	Lectura();
	system("pause");
	
};

int Menu(){
	int op,conf=1;
	do{
		system("cls");
		cout<<"\t\tMenu de acceso"<<endl;
		cout<<"\t\t--------------"<<endl;
		cout<<"\tBienvenido a nuestro sistema de mensajeria."<<endl;
		cout<<"\t1. Configuracion del Perfil y mensajeria"<<endl;
		cout<<"\t2. Revisar personas conectadas."<<endl;
		cout<<"\t3. Salir"<<endl;
		cout<<"\tDigite la opcion de su interes: "<<endl;
		cin>>op;
		switch(op) {
			case 1: {
				Mensajes();
				break;
			}
			case 2: {
				R_conectividad();
				break;
			}
			case 3: {
				conf= 0;
				break;
			}
			default:
				cout<<"\tOpcion no existente, por favor intente otra opcion diferente";
				Menu();
			}
		}while(conf!=0);
};
void R_conectividad(){
	ifstream archivo;
	string texto;
	system("cls");
	cout<<"\tFuncion para detectar las personas conectadas. "<<endl;
	cout<<"\t-----------------------------------------------"<<endl;
	cout<<"\tEn esta funcion podra consultar cuales usuarios se encuentran conectados"<<endl;
	cout<<"\tRecuerde si aparece el numero 1 al lado del nombre de usuario la persona esta conectada "<<endl;
	cout<< "\tsi es un 0 la persona no se encuentra activa"<<endl;
	cout<<"\tListado de Personas."<<endl;
	archivo.open("conectividad.txt",ios::in);//abrimos el archivo en modo lectura
	if(archivo.fail()){
		cout<<"Houston, tenemos un problema,El archivo no se pudo abrir"<<endl;
		system("pause");
		exit(1);
	}
	while(!archivo.eof()){  //mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();	
	system("pause");
};
