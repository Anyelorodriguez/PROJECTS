#include <iostream>
#include <math.h>//calculadora
#include <stdio.h>//limpiar pantalla
#include <Fstream>//archivos
#include <windows.h>//sonido
#include<stdlib.h>//salir del programa
#include <direct.h>//crear carpetas

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
int cuadrado();
int calculadora(double x, double y);
int matri(int x,int y);
int vect( int x, int y);
int fibonacci(int x,int y);
void archivo();
void carpeta();
void leer();
int main(void)
{
	int opc;
	cout<<"\nmenu principal\n";
	cout<<"\n1. Multiplicacion entre dos matrices de 3x3.";
	cout<<"\n2. Multiplicacion de una matriz de 3x3 con un vector de 3 posiciones.";
	cout<<"\n3. variable al cuadrado con sonido de cada valor.";
	cout<<"\n4. calculadora.";
	cout<<"\n5. Realizar la serie Fibonacci.";
	cout<<"\n6. Juego Triqui.";
	cout<<"\n7. crear o abrir archivo de texto llamado maraton.txt.";
	cout<<"\n8. crear carpeta.";
	cout<<"\n9. lectura de archivo.";
	cout<<"\n10. Informacion.\n";
	cout<<"\n opcion: ";
	cin>>opc;
	if (opc==1)//multiplicacion de matrices
		{
			int c,d;
			cout<<"multiplicacion de matrices";
			matri(c,d);
		}
	else if (opc==2)//multiplicacion de matriz 3x3 con un vector de 3 posiciones
		{
			int c,d;
			cout<<"multiplicacion de matriz 3x3 por un vector de 3 posiciones\n";
			vect(c,d);
		}
	else if (opc==3)//variable al cuadrado con sonido de cada valor
		{
			cuadrado();
		}
	else if (opc==4)//calculadora
		{
			double a,b;
			system("cls");//solo para esta porque es muy grande 
			calculadora(a,b);
		}
	else if (opc==5)//serie Fibonacci.
		{
			cout<<"serie de fibonacci.\n";
			int a,b;
			fibonacci(a,b);
		}
	else if (opc==6)//juego triqui
		{
			cout<<"no supe como hacerlo ingeniero (T-T), no me funciono, disculpe :(";
		}
		else if (opc==7)//función que escriba información en un archivo.
		{
			archivo();
			cout<<"Archivo de texto creado\n";
			system("pause");
		}
		else if (opc==8)//crear carpeta.
		{
			system ("cls");
			carpeta();
			system("pause");
		}
		else if (opc==9)//9. lectura de archivo.
		{
			system ("cls");
			leer();
			system("pause");
		}
		else if (opc==10)//Informacion.
		{
			cout<<"\nDEFINICION DE VARIABLE\n\nUna variable es un espacio en la memoria, en el cual el programador asigna \nun valor determinado por el tipo de dato que el lenguaje de programacion va \nsoportar, para declararla es necesario saber que tipo de dato la contiene.\nEs representada por un nombre que es asignado por el programador, y se \nnombra justo despues de su tipo de dato.\n\nDEFINICION DE FUNCION\n \nUna funcion es un bloque de codigo que realiza alguna operacion. Una funcion \npuede definir opcionalmente parametros de entrada que permiten a los \nllamadores pasar argumentos a la funcion. Una funcion tambien puede devolver \nun valor como salida. Las funcioes son utiles para encapsular las \noperaciones comunes en un solo bloque reutilizable, idealmente con un nombre \nque describa claramente lo que hace la funcion.\n\nDEFINICION DE LIBRERIA\n\nEn C++, se conoce como librerias (o bibliotecas) a cierto tipo de archivos \nque podemos importar o incluir en nuestro programa. Estos archivos contienen \nlas especificaciones de diferentes funcionalidades ya construidas y \nutilizables que podremos agregar a nuestro programa, como por ejemplo leer \ndel teclado o mostrar algo por pantalla entre muchas otras mas.";
		}
	else //valor que no esta entre el menu
		{
			cout<<"\nopcion no valida";
		}
	};
int matri(int x,int y)
{
	int a[3][3],b[3][3],c[3][3],i=x,j=y;
	cout<<"primer matriz 3x3: \n";
	for(x=0;x<3;x++)// filas
		for(y=0;y<3;y++)//columnas
			{
				cout<<"introducir valor de la matris 1 en la posicion ["<<x<<"]["<<y<<"]: ";
				cin>>a[x][y];
			}
			cout<<"\n";
	cout<<"segunda matriz 3x3: \n";
	for(x=0;x<3;x++)// filas
		for(y=0;y<3;y++)//columnas
			{
				cout<<"introducir valor de la matris 2 en la posicion ["<<x<<"]["<<y<<"]: ";
				cin>>b[x][y];
			}
			cout<<"\n";
	for(x=0;x<3;x++)// filas
		for(y=0;y<3;y++)//columnas
			c[x][y]=(a[x][1]*b[1][y])+(a[x][2]*b[2][y])+(a[x][3]*b[3][y]);
	
	for(x=0;x<3;x++)// filas
		{
		for(y=0;y<3;y++)//columnas
			cout<<"|"<<c[x][y]<<"|";
		cout<<"\n";
		}
	system ("pause");
}
int vect( int x, int y)
{
	int A[3][3],B[3],C[3],i=x,j=y;
	//peticion de relleno matriz	
	cout<<"\nMatriz\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"Por favor digite el valor de la matriz en la posicion "<<i<<","<<j<<" :";
		cin>>A [i][j];
		}		
	}
	//Peticion relleno vector
	cout<<"\nvector\n";
	for (i=0;i<3;i++)
	{
		cout<<"Por favor digite el dato en la posicion "<<i<<" :";
		cin>>B[i];
	}
	//multiplicacion 
	for (i=0;i<3;i++)
	{
		C[i]=0;
	}
	//generacion del nuevo vector
	for (i=0;i<3;i++)
	{
			for (j=0; j<3; ++j)
			{
			C[i]+= A[i][j]*B[i];	
			}		
	}
	//Impresion del vector resultante (multiplicacion matriz y vector)
	cout<<"vector resultante (Multipliacion de matriz y vector):\n";
	for (i=0;i<3;i++)
	{
		cout<<"|"<<C[i]<<"|";
		cout<<"\n";			
	}	
	
	
return 0;	
}
int cuadrado()
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
	
}
int calculadora(double x, double y)
{
	double var1=x,var2=y,resultado;
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
			cout<<"\n ejecuta seno";
			cout<<"\nvalor varible en radianes: ";
			cin>>var1;
			resultado =sin(var1);
			cout<<"\nresultado del seno es = " <<resultado;
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
int fibonacci(int x,int y)
{
	
	//variables
	int i=x,j=y,k,l=0;
		i=1;
		j=0;
	//bucle para la funcion	
	while (l==0)
	{
		k=i+j;                     
		cout<<i<<"+"<<j<<"="<<k;
		cout<<"\n";
		j=i;					 
		i=k; 					
		system("pause");//con esto no se ejecuta sin infinitamente.
	}
return 0;	
}
void archivo()
{
	ofstream ejem;
	ejem.open("maraton.txt", ios::out);//creando o abriendo archivo
	
	if (ejem.is_open())
	{
		cout<<"escriba 'link' para cerrar el programa \n\n ingrese un texto \n\n";
		string salida_texto;
		for(;;)
		{
			string linea;
			getline(cin,linea);
			if(linea == "link")
				break;
			salida_texto+=linea+'\n';
		}
		ejem<<salida_texto;
		ejem.close();
	}
	else 
	{
		cout<<"no se encontro el archivo ";
	}
	
}

void carpeta()
{
	string ruta;
	getline(cin,ruta);
	cout<<"Nombre de la carpeta: ";
	string carp;
	getline(cin,carp);
	string ruta_absoluta = ruta + carp;
	if (mkdir(ruta_absoluta.c_str())==0)
		cout<<"Carpeta creada correctamente"<<endl;
	else
	{
		cout<<"Ha ocurrido un error al crear la carpeta"<<endl;
		carpeta ();
	}
	
}

void leer()
{
	fstream archivo;
	archivo.open("maraton.txt",ios::in);//Abre el archivo
	
	if(archivo.is_open()) //lectura de archivo
	{
		string linea;
		while(getline(archivo,linea))
		{
			cout<<linea<<endl;
		}
		
		archivo.close();
	}
	else
	{
		cout<<"hubo un problema la abrir el archivo";
	}
	//se cierra el archivo
	archivo.close();
}
