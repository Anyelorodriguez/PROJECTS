#include <iostream>
#include <math.h>

using namespace std;

int suma(int x,int y);
int resta(int x,int y);
int multiplicacion(int x,int y);
int division(int x,int y);

int main (void)
{
	double resultado,var1,var2;
	int opcion;
	cout<<"\nmenu";
	cout<<"\n1. suma";
	cout<<"\n2. resta";
	cout<<"\n3. multiplicacion";
	cout<<"\n4. division";
	cout<<"\n5. seno ";
	cout<<"\n6. coseno ";
	cout<<"\n7. tangente ";
	cout<<"\n8. seno hiperbolico ";
	cout<<"\n9. coseno hiperbolico ";
	cout<<"\n10. tangente hiperbolica";
	cout<<"\n11. arcoseno";
	cout<<"\n12. arcocoseno";
	cout<<"\n13. arcotangente";
	cout<<"\n14. logaritmo natural";
	cout<<"\n15. logaritmo base 10";
	cout<<"\n16. potencia";
	cout<<"\n digite su opcion: ";
	cin>>opcion;
	if (opcion==1)//suma
	{
		cout<<"\n ejecuta una suma";
		cout<<"\nvalor varible 1: ";
		cin>>var1;
		cout<<"\nvalor variable 2: ";
		cin>>var2;
		resultado =suma(var1,var2);
		cout<<"\nresultado suma = " <<resultado;
	}
	else if (opcion==2)//ressta
	{
		cout<<"\n ejecuta una resta";
		cout<<"\nvalor varible 1: ";
		cin>>var1;
		cout<<"\nvalor variable 2: ";
		cin>>var2;
		resultado =resta(var1,var2);
		cout<<"\nresultado resta = " <<resultado;
	}
	else if (opcion==3)//multiplicacion
	{
		cout<<"\n ejecuta una multiplicacion";
		cout<<"\nvalor varible 1: ";
		cin>>var1;
		cout<<"\nvalor variable 2: ";
		cin>>var2;
		resultado =multiplicacion(var1,var2);
		cout<<"\nresultado multiplicacion = " <<resultado;
	}
	else if (opcion==4)//divicion
	{
		cout<<"\n ejecuta una divicion";
		cout<<"\nvalor varible 1: ";
		cin>>var1;
		cout<<"\nvalor variable 2: ";
		cin>>var2;
		resultado =division(var1,var2);
		cout<<"\nresultado division = " <<resultado;
	}
	else if (opcion==5)//seno
	{
		cout<<"\n ejecuta seno";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =sin(var1);
		cout<<"\nresultado del seno es = " <<resultado;
	}
	else if (opcion==6)//coseno
	{
		cout<<"\n ejecuta coseno";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =cos(var1);
		cout<<"\nresultado del coseno es = " <<resultado;
	}
	else if (opcion==7)//tangente
	{
		cout<<"\n ejecuta tangente";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =tan(var1);
		cout<<"\nresultado del tangente es = " <<resultado;
	}
	else if (opcion==8)//seno hiperbolico
	{
		cout<<"\n ejecuta seno hiperbolico";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =sinh(var1);
		cout<<"\nresultado del seno hiperbolico es = " <<resultado;
	}
	else if (opcion==9)//coseno hiperbolico
	{
		cout<<"\n ejecuta coseno hiperbolico";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =cosh(var1);
		cout<<"\nresultado del coseno hiperbolico es = " <<resultado;
	}
	else if (opcion==10)//tangente hiperbolica
	{
		cout<<"\n ejecuta tangente hiperbolica";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =tanh(var1);
		cout<<"\nresultado de la tangente hiperbolica es = " <<resultado;
	}
	else if (opcion==11)//arcoseno
	{
	cout<<"\n ejecuta arcoseno";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =asin(var1);
		cout<<"\nresultado del arcoseno es = " <<resultado;
	}
	else if (opcion==12)//arcocoseno
	{
		cout<<"\n ejecuta arcocoseno";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =acos(var1);
		cout<<"\nresultado del arcocoseno es = " <<resultado;
	}
	else if (opcion==13)//arcotangente
	{
		cout<<"\n ejecuta arcotangente";
		cout<<"\nvalor varible en radianes: ";
		cin>>var1;
		resultado =atan(var1);
		cout<<"\nresultado de arcotangente es = " <<resultado;
	}
	else if (opcion==14)//logaritmo natural
	{
		cout<<"\n ejecuta un logaritmo natural";
		cout<<"\nvalor variable : ";
		cin>>var1;
		resultado =log(var1);
		cout<<"\nresultado logaritmo natural = " <<resultado;
	}
	else if (opcion==15)//logaritmo base 10
	{
		cout<<"\n ejecuta un logaritmo base 10";
		cout<<"\nvalor variable : ";
		cin>>var1;
		resultado =log10(var1);
		cout<<"\nresultado logaritmo base 10 = " <<resultado;
	}
	else if (opcion==16)//potencia
	{
		cout<<"\n ejecuta una potencia";
		cout<<"\nvalor base: ";
		cin>>var1;
		cout<<"\nvalor exponente: ";
		cin>>var2;
		resultado =pow(var1,var2);
		cout<<"\nresultado potencia = " <<resultado;
	}
	else
	{
		cout<<"\nopcion no valida";
		
	}
};
int suma(int x,int y)
{
	int z=x;
	int h=y;
	int t;
	t=z+h;
	return t;
	
};
int resta(int x,int y)
{
	int z=x;
	int h=y;
	int t;
	t=z-h;
	return t;
	
};
int multiplicacion(int x,int y)
{
	int z=x;
	int h=y;
	int t;
	t=z*h;
	return t;
	
};

int division(int x,int y)
{
	int z=x;
	int h=y;
	int t;
	t=z/h;
	return t;
	
};
