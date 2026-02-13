#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Fstream>
#include <windows.h>


using namespace std;
/*Maratón de Desarrollo.
Cada punto debe ser desarrollado en un punto de un menú principal:
1. Multiplicación entre dos matrices de 3x3.
2. Multiplicación de una matriz de 3x3 con un vector de 4 posiciones.
3. Una función que eleve un valor al cuadrado y se conecte con otra función que emita un
sonido.
4. Un submenú que permite realizar todas las operaciones de la librería Math.h y cada
operación sea realiza en una función.
5. Realizar la serie Fibonacci.
6. Mostrar el Juego Triqui.
7. Hacer una función que escriba información en un archivo.
8. Hacer una función que cree una carpeta en el sistema.
9. Hacer una función que lea la información que contiene un archivo.
10. Un submenú informativo de ayuda que permita mostrar la información sobre: que es una
variable, una función, una librería.*/
int cuadrado(void);
int seno(void);
int main(void)
{
	int opc;
	cout<<"\nmenu principal\n";
	cout<<"\n1. Multiplicacion entre dos matrices de 3x3.";
	cout<<"\n2. Multiplicacion de una matriz de 3x3 con un vector de 4 posiciones.";
	cout<<"\n3. variable al cuadrado con sonido de cada valor.";
	cout<<"\n4. calculadora.";
	cout<<"\n5. Realizar la serie Fibonacci.";
	cout<<"\n6. Juego Triqui.";
	cout<<"\n7. Hacer una funcion que escriba informacion en un archivo.";
	cout<<"\n8. crear carpeta.";
	cout<<"\n9. lectura de archivo.";
	cout<<"\n10. Informacion.\n";
	cout<<"\n opcion: ";
	cin>>opc;
	if (opc==1)//multiplicacion de matrices
		{
			char mat[3][3];
			int j=0,k=0;
			for (j=0;j<3;j++)
			{
				j=0;
				while (j<3)
				{
					
				}
			}
			
		}
	else if (opc==2)//multiplicacion de matris 3x3 con un vector de 4 posiciones
		{
			
		}
	else if (opc==3)//variable al cuadrado con sonido de cada valor
		{
			cuadrado();
		}
	else if (opc==4)//calculadora
		{	//operaciones de math.h
		double resultado,var1,var2;
		int opcion;
		cout<<"\nmenu";
		cout<<"\n1. seno ";
		cout<<"\n2. coseno ";
		cout<<"\n3. tangente ";
		cout<<"\n4. seno hiperbolico ";
		cout<<"\n5. coseno hiperbolico ";
		cout<<"\n6. tangente hiperbolica";
		cout<<"\n7. arcoseno";
		cout<<"\n8. arcocoseno";
		cout<<"\n9. arcotangente";
		cout<<"\n10. logaritmo natural";
		cout<<"\n11. logaritmo base 10";
		cout<<"\n12. potencia";
		cout<<"\n13. arcotangente al cuadrado";
		cout<<"\n14. exponencial";
		cout<<"\n15. Raiz cuadrada";
		cout<<"\n16. Función techo";
		cout<<"\n17. Funcion piso";
		cout<<"\n digite su opcion: ";
		cin>>opcion;
		
		if (opcion==1)//seno
		{
			seno();
		}
		else if (opcion==2)//coseno
		{
			cout<<"\n ejecuta coseno";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =cos(var1);
			cout<<"\nresultado del coseno es = " <<resultado;
		}
		else if (opcion==3)//tangente
		{
			cout<<"\n ejecuta tangente";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =tan(var1);
			cout<<"\nresultado del tangente es = " <<resultado;
		}
		else if (opcion==4)//seno hiperbolico
		{
			cout<<"\n ejecuta seno hiperbolico";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =sinh(var1);
			cout<<"\nresultado del seno hiperbolico es = " <<resultado;
		}
		else if (opcion==5)//coseno hiperbolico
		{
			cout<<"\n ejecuta coseno hiperbolico";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =cosh(var1);
			cout<<"\nresultado del coseno hiperbolico es = " <<resultado;
		}
		else if (opcion==6)//tangente hiperbolica
		{
			cout<<"\n ejecuta tangente hiperbolica";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =tanh(var1);
			cout<<"\nresultado de la tangente hiperbolica es = " <<resultado;
		}
		else if (opcion==7)//arcoseno
		{
		cout<<"\n ejecuta arcoseno";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =asin(var1);
			cout<<"\nresultado del arcoseno es = " <<resultado;
		}
		else if (opcion==8)//arcocoseno
		{
			cout<<"\n ejecuta arcocoseno";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =acos(var1);
			cout<<"\nresultado del arcocoseno es = " <<resultado;
		}
		else if (opcion==9)//arcotangente
		{
			cout<<"\n ejecuta arcotangente";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =atan(var1);
			cout<<"\nresultado de arcotangente es = " <<resultado;
		}
		else if (opcion==10)//logaritmo natural
		{
			cout<<"\n ejecuta un logaritmo natural";
			cout<<"\nvalor variable : ";
			cin>>var1;
			resultado =log(var1);
			cout<<"\nresultado logaritmo natural = " <<resultado;
		}
		else if (opcion==11)//logaritmo base 10
		{
			cout<<"\n ejecuta un logaritmo base 10";
			cout<<"\nvalor variable : ";
			cin>>var1;
			resultado =log10(var1);
			cout<<"\nresultado logaritmo base 10 = " <<resultado;
		}
		else if (opcion==12)//potencia
		{
			cout<<"\n ejecuta una potencia";
			cout<<"\nvalor base: ";
			cin>>var1;
			cout<<"\nvalor exponente: ";
			cin>>var2;
			resultado =pow(var1,var2);
			cout<<"\nresultado potencia = " <<resultado;
		}
		else if (opcion==13)//arcotangente de dos parametros
		{
			cout<<"\n ejecuta arcotangente de dos parametros";
			cout<<"\nvalor varible x en radianes: ";
			cin>>var1;
			cout<<"\nvalor variable y en radianes";
			cin>>var2;
			resultado =atan2(var1,var2);
			cout<<"\nresultado de arcotangente cuadrado es = " <<resultado;
		}
		else if (opcion==14)//exponencial
		{
			cout<<"\n ejecuta exponencial";
			cout<<"\nvalor varible: ";
			cin>>var1;
			resultado =exp(var1);
			cout<<"\nresultado de la exponencial es= " <<resultado;
		}
			else if (opcion==15)//raiz cuadrada
		{
			cout<<"\n ejecuta una raiz cuadrada";
			cout<<"\nvalor varible: ";
			cin>>var1;
			resultado =sqrt(var1);
			cout<<"\nresultado de la raiz cuadrada es= " <<resultado;
		}
			else if (opcion==16)//funcion techo
		{
			cout<<"\n ejecuta una funcion techo";
			cout<<"\nvalor varible: ";
			cin>>var1;
			resultado =ceil(var1);
			cout<<"\nresultado de la funcion techo es= " <<resultado;
		}
			else if (opcion==17)//funcion piso
		{
			cout<<"\n ejecuta una funcion piso";
			cout<<"\nvalor varible: ";
			cin>>var1;
			resultado =floor(var1);
			cout<<"\nresultado de la funcion piso es= " <<resultado;
		}
		else
		{
			cout<<"\nopcion no valida";
			
		}
	}
	
	else if (opc==5)//serie Fibonacci.
		{
			
		}
	else if (opc==6)//juego triqui
		{
			
		}
	else if (opc==7)//función que escriba información en un archivo.
		{
			
		}
	else if (opc==8)//crear carpeta.
		{
			
		}
	else if (opc==9)//9. lectura de archivo.
		{
			
		}
	else if (opc==10)//Informacion.
		{
			
		}
	else //valor no encontrado
		{
			cout<<"\nopcion no valida";
			
		}
	};
int cuadrado(void)
{
	int val1,val2,res;
	cout<<"digite valor de la base: ";
	cin>>val1;
	for ( int x=0; x<val1; x++ )
	{
		Beep(500,400);
	}
	val2=2;
	res=pow(val1,val2);
	cout<<"\nel valor de la potencia es: " <<res;
		for (int x=0; x<res; x++ )
	{
		Beep(600,400);
	}
};
int seno(void)
		{
			int var1,var2,resultado;
			cout<<"\n ejecuta seno";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =sin(var1);
			cout<<"\nresultado del seno es = " <<resultado;
		};
	
