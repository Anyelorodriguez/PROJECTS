#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std;
//alerta!
int sonido(void);
int suma(void);
int main(void)
{
	int opc,terminar=0;
	while(terminar==0);
	{
		system ("cls");
		cout<<"menu";
		cout<<"\n1. sonido ";
		cout<<"\n2. suma\n";
		cout<<"digite la opcion";
		cin>>opc;
		if (opc==1)
			sonido();
		else if (opc==2)
			suma();
		else
			cout<<"\nNo existe la opcion en el menu";
		system("pause");
	}
};

int sonido(void)
{
	int valorBeep,duracion;
	cout<<"Digite el valor de la frecuancia (400-1000): ";
	cin>>valorBeep;;
	cout<<"Digite la duracion del sonido (500-2000ms): ";
	cin>>duracion;
	Beep(valorBeep,duracion);
};
int suma(void)
{
	int val1,val2,res;
	cout<<"digite valor 1: ";
	cin>>val1;
	cout<<"digite valor 2: ";
	cin>>val2;
	res=val1+val2;
	cout<<"el valor de la suma es: " <<res;
	
};

