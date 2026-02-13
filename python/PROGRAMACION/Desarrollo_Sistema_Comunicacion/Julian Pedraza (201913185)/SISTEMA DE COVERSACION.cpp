//SISTEMA DE CONVERSACION
//JULIAN PEDRAZA (201913185)
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

//EMPLEO DE MEMORIA
using namespace std;

void anadirTexto();
void crearArchivo();
void lecturaTexto();
void conectado();
void crearMensaje();
void lecturaMensaje();
void anadirMensaje();

//FUNCION ORIGINARIA
int main()
{
	int opc;
	crearArchivo();
	crearMensaje();
	cout<<"****************************\n";
	cout<<"*                          *\n";
	cout<<"* SISTEMA DE CONVERSACIOIN *\n";
	cout<<"*                          *\n";
	cout<<"****************************\n\n";
	cout<<"INICIO:\n";
	cout<<"                          \n";
	cout<<"1. UNIRSE\n";
	cout<<"                          \n";
	cout<<"2. Salir\n";
	cout<<"                          \n";
	cout<<"ELIGA SU OPCION:\n";
	cin>>opc;
	if(opc==1)
	{
		system("cls");

		anadirTexto();
		conectado();
	}
	else if(opc==2)
	{}
	else
	{
		system("cls");
		cout<<"LA OPCION NO EXISTE:(...\n\n\n";
		main();
	}
	system("pause");
	return 0;
};
 
 //CREA EL ARCHIVO PARA QUE INGRESEN LOS USUARIOS
void crearArchivo()
{
	ofstream archivo;
	//SOBREESCRIBIR EL ARCHIVO
	archivo.open ("usuarios.txt"); 
	archivo<<"PERFILES UNIDOS"<<"\n";
	archivo.close();	
};

//lECTURA DEL LOS ARCHIVOS, SEGUN SU PERFIL
void lecturaTexto()
{
	ifstream archivo;
	string nombreArchivo,texto;
	
	nombreArchivo="usuarios.txt";
	
	 //ABRE EL ARCHIVO EN MODO LECTUTURA
	archivo.open(nombreArchivo.c_str(),ios::in);
	
	if(archivo.fail())
	{
		cout<<"ERROR AL ABRIR EL ARCHIVO";
		exit(1);
	}
	
	while(!archivo.eof())
	{
		//MIENTRAS ESTE ARCHIVO NO TERMINE
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	//CERRAR ARCHIVO
	archivo.close(); 
};

//AÑADIR PERFILES
void anadirTexto()
{
	char rpt;
	ofstream archivo;
	string frase;
		
	archivo.open("usuarios.txt",ios::app); 
	
	if(archivo.fail())
	{ //SI OCURRIO ALGUN ERROR
		cout<<"\nERROR";
		exit(1);
	}

		fflush(stdin);
		cout<<"\nESCRIBA EL NOMBRE DEL USUARIO:\n "<<endl;
		getline(cin,frase);
		archivo<<frase;
		
    //CERRAR EL ARCHIVO
	archivo.close(); 
};

//OPCIONES DE LOS PERFILES
void conectado()
{
	int opc;
	
	cout<<"\nINICIO DE SELECCION \n\n";
    cout<<"1. Escribir Mensajen\n\n";
    cout<<"2. Mirar Chat\n\n";
    cout<<"3. Ver Perfiles Conectacos\n\n";
    cout<<"4. Desconectarse\n\n";
	cout<<"SELECCIONE POR FAVOR:\n\n";
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
		lecturaMensaje();
		conectado();
	}
	else if(opc==3)
	{
		system("cls");
		lecturaTexto();
		conectado();
		
	}
	else if(opc==4)
	{
	    main();	
	}
	else
	{
	   cout<<"LA OPCION NO EXISTE";
	   conectado();	
	}
};

//SE CREA EL ARCHIVO CHAT
void crearMensaje()
{
	ofstream archivo;
	//SEBREESCRIBIR ARCHIVO
	archivo.open ("chat.txt"); 
	archivo<<"Mensajes:"<<endl;
	archivo.close();	
};

//LECTURA DE MENSAJES
void lecturaMensaje()
{
	ifstream archivo;
	string nombreArchivo,texto;
	
	nombreArchivo="chat.txt";
	
	//MODO LECTURA (SEGUN EL ARCHIVO)
	archivo.open(nombreArchivo.c_str(),ios::in); 
	
	if(archivo.fail())
	{
		cout<<"EL ARCHIVO NO SE PUDO ABRIR";
		exit(1);
	}
	
	while(!archivo.eof())
	{ //MIENTRAS NO SE TERMINE EL ARCHIVO
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	//CERRAR ARCHIVO
	archivo.close(); 
};

//AÑADIR MENSAJES
void anadirMensaje()
{
	char rpt;
	ofstream archivo;
	string frase;
		
	archivo.open("chat.txt",ios::app); 
	
	if(archivo.fail())
	{ //Si OCURRIO UN ERROR
		cout<<"\nERROR";
		exit(1);
	}

		fflush(stdin);
		cout<<"\nINSPIRESE E INICIE LA CONVERSACION:"<<endl;
		getline(cin,frase);
		archivo<<frase;
	
	//CERRAR EL ARCHIVO
	archivo.close(); 
};
