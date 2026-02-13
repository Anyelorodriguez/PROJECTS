#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;//Espacio  de memoria

void conectado();
void Archivo();
void Texto();
void Leertexto();
void anadirMensaje();
void LeerMensaje();
void Mensaje();


int main()// Inicio de Funcion inicial
{
	
	int opc;
	system("color f0");
	Archivo();
	Mensaje();
	cout <<"\t**SISTEMA DE COMUNICACION**\n";
	cout << "\t**ANGEL DUVAN CUERVO HUERFANO\n\t\t201710001\n";	
	cout<<"Menu\n";
	cout<<"1. Conectarse\n"<<"2. Salir\n";
	
	cout<<"Digite una opcion:\n";
	cin>>opc;
	if(opc==1)
	{
		system("cls");
		Texto();
		conectado();
	}
	else if(opc==2)
	{}
	else
	{
		system("cls");
		cout<<"No existe esa opcion :(...\n\n\n";
		main();
	}
	system("pause");
	return 0;
};
 
void Archivo()//creacion de  archivo donde se ingresan los usuarios
{
	ofstream archivo;
	archivo.open ("usuarios.txt"); //Sobreescribir el archivo.
	archivo<<"Usuarios conectados"<<"\n";
	archivo.close();	
};

void Leertexto()//ifstream implementado con fin de leer el archivo donde se ingresaron los usuarios
{
	ifstream archivo;
	string nombreArchivo,texto;
	
	nombreArchivo="usuarios.txt";
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Opcion de Abrir el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ 
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close(); //Cerrar el archivo
};


void Texto()//Agregar mas  usuarios
{

	char rpt;
	ofstream archivo;
	string frase;
		
	archivo.open("usuarios.txt",ios::app); 
	
	if(archivo.fail())
	{ //Identificar errores que puedan ocurrir 
		cout<<"\nNo se pudo";
		exit(1);
	}

		fflush(stdin);
		cout<<"\nPor favor digite su nombre de usuario\n "<<endl;
		getline(cin,frase);
		archivo<<frase;
	archivo.close(); //Cerrar el archivo


};

void conectado()//variables de opciones que los usuarios conectados pueden seleccionar
{
	int opc;
	
	cout<<"\nMenu de usuario conectado\n\n";
	cout<<"1. Desea Enviar Un Mensaje\n";
	cout<<"2. Desea Leer Un Mensaje\n";
	cout<<"3. Usuarios Conectados\n";
	cout<<"4. Desea Desconectarse\n";
	cout<<"Digite una opcion:\n";
	cin>>opc;	
	
	if(opc==1)
	{
		system("cls");
		anadirMensaje();
		conectado();
	}
	else if(opc==2)
	{
		system("cls");
		LeerMensaje();
		conectado();
	}
	else if(opc==3)
	{
		system("cls");
		Leertexto();
		conectado();
		
	}
	else if(opc==4)
	{
	    main();	
	}
	else
	{
	   cout<<"Error de opcion";
	   conectado();	
	}
};

void Mensaje()//crear el archivo donde se ingresan los mensajes
{
	ofstream archivo;
	archivo.open ("chat.txt"); //Sobreescribe el archivo.
	archivo<<"Mensajes:"<<endl;
	archivo.close();	
};

void LeerMensaje()//leer el archivo donde se ingresaron los mensajes
{
	ifstream archivo;
	string nombreArchivo,texto;
	
	nombreArchivo="chat.txt";
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close(); //Cerramos el archivo
};


void anadirMensaje()//añadir mensajes
{

	char rpt;
	ofstream archivo;
	string frase;
		
	archivo.open("chat.txt",ios::app); 
	
	if(archivo.fail())
	{ //Si a ocurrido algun error
		cout<<"\nNo se pudo";
		exit(1);
	}

		fflush(stdin);
		cout<<"\nDigite el mensaje:"<<endl;
		getline(cin,frase);
		archivo<<frase;

	archivo.close(); //Cerrar el archivo

};

