//inicio de libreria
#include <iostream>
//uso de espacio de memoria 
using namespace std;
//inicio de funcion sin retorno
int main(void)
{
	//variables - area de definicion de variables
	char nombre [200];
	char apellido [200];
	char edad [200];
	char direccion[200];
	//impresion de la variable
	cout<<nombre;
	cout<<apellido;
	cout<<edad;
	cout<<direccion;
	//impresion de texto para pedir informacion del usuario
	cout<<"\n Geben Sie den Namen ein: ";
	//adquisicion de informacion por input
		cin>>nombre;
	cout<<"\n Geben Sie den Nachnamen ein: ";
		cin>>apellido;
	cout<<"\n Geben Sie das Alter ein: ";
		cin>>edad;
	cout<<"\n Geben Sie die Adresse ein ";
		cin>>direccion;
	//salida de mensaje por autput de la variable nombre en la posicion 2
	cout<<"Der Name ist: "<<nombre;
	//output de impresion de la variable nombre
	//el nombre de la variable depende de el lugar donde estan definidos 
	cout<<"\n Der Nachname ist: "<<apellido;
	cout<<"\n Alter ist: " <<edad;
	cout<<"\n Die adresse ist: " <<direccion;
//cierre de la funcion inicio main
};
