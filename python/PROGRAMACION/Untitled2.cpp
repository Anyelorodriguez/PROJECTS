#include <iostream>//incluir librerias
#include <string>
using namespace std;//uso de espacio de memoria

float resta();
int

 resta2();

int main()//funcion inicial
{
	int g=0;//definicion de variables
	string h;
	float ret=0.1;
	cout<<"escriba el valor entero:";//consol out imprime un texto 
	cin>>g;//console in espera un dato
	cout<<g;//console out imprime un dato
	cout<<"\nescriba un texto: ";
	cin>>h;
	cout<<h;
	printf("\nfuncion de resta");
	ret=resta();
	printf("\n Resultado de resta %f",ret);
	printf("\n funcion resta 2");
	g=resta2();
	printf("\n resultado de resta 2: %d",g);
	return 0;//retorno de la funcion main
};
float resta()
{
	float x=0;
	float y=0;
	float z=0;
	printf("\nescriba el numero 1:");
	cin>>x;
	cout<<x;
	printf("\nescriba el numero 2:");
	cin>>y;
	z=x-y;
	return z;
};

int resta2()
{
	int x=0;
	int y=0;
	int z=0;
	printf("\nescriba el numero 1:");
	cin>>x;
	cout<<x;
	printf("\nescriba el numero 2:");
	cin>>y;
	z=x-y;
	return z;
};
