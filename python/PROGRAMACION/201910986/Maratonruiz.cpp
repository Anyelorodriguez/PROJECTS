#include <iostream>
#include <math.h>//operaciones matematicas
#include <stdio.h>//system("cls"); limpia la pantalla
#include <Fstream>//archivos
#include <windows.h>//beep; emite un sonido
#include<stdlib.h>//exit(1),salir del programa
#include <direct.h>//crear directorios/carpetas
using namespace std;
void menu();//menu general
int matriz(int x, int y);//punto 1
int matvect( int x, int y);//punto 2
int cuadrado(double x, double y);//punto 3
int math(double x, double y);//punto 4
int fibonacci(int x,int y);//punto 5
int triqui(int x, int y);//punto 6
void archivo();//punto 7
void carpeta();//punto 8
void leer();//punto 9
void definiciones();//punto 10

int main(void)
{
menu();
system("pause");
return 0;
};

void menu(){
int opcion;

		cout<<"Menu\n"<<"1.Multiplicacion dos matrices 3x3\n"<<"2.Multiplicacion matriz 3x3 con vector de 3 posiciones\n"<<"3.Funcion que eleva al cuadrado y emite un sonido\n";
		cout<<"4.Menu con operaciones de math.h\n"<<"5.Sucesion fibonacci\n"<<"6.Triqui\n"<<"7. Funcion que escriba informacion en un archivo\n";
		cout<<"8.Funcion que crea una carpeta en el sistema\n"<<"9.Funcion que lee archivos\n"<<"10.Conceptos claves\n"<<"inserte la opcion deseada: ";
		cin>>opcion;
		//condicional 1
		if(opcion==1)
		{
		system ("cls");
		int a,b;
		cout<<"multiplicacion dos matrices 3x3\n";
		cout<<"inserte valores en las matrices A y B respectivamente\n";
		matriz(a,b);
		}
		//condicional 2		
		else if(opcion==2){
		system ("cls");
		int a,b;
		cout<<"multiplicacion de matriz 3x3 por un vector de 3 posiciones\n";//no puede ser vector de 4 posiciones pues el numero de columnas del vector debe coincidir con el numero de filas de la matriz
		matvect(a,b);			
		}
		//condicional 3		
		else if(opcion==3)
		{
		double a,b;
		system ("cls");
		cout<<"Funcion que eleva al cuadrado y emite un sonido dependiendo el valor en el resultado\n";
		cuadrado(a,b);
		}
		//condicional 4
		else if (opcion==4)
		{
		double a,b;
		system("cls");
		math(a,b);
		}
		//condicional 5		
		if (opcion==5){
		system("cls");
		int a,b;
		fibonacci(a,b);
		}
		//condicional 6
		else if (opcion==6){
		system("cls");
		int a,b;
		cout<<"Triqui\n";
		triqui(a,b);		
		}
		//condicional 7
		else if (opcion==7){
		system ("cls");
		archivo();
		cout<<"Archivo de texto creado correctamente\n";
		system("pause");
		}
		//condicional 8
		else if (opcion==8){
		system ("cls");
		carpeta();
		system("pause");
		}
		//condicional 9
		else if (opcion==9){
		system ("cls");
		leer();
		system("pause");
		}
		//condicional 10
		else if (opcion==10){
		system ("cls");
		definiciones();
		}
		else if(opcion>10 || opcion<1)
		{
		cout<<"opcion no valida\n";
		system("pause");
		system ("cls");
		menu();
		}
}

int matriz(int x, int y)
{
	int A[3][3];
	int B[3][3];
	int C[3][3];
	//matriz A
	int i=x;
	int j=y;

	
	//peticion valores en la matriz A
	cout<<"Matriz A\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"Por favor digite el valor de la matriz A en la posicion "<<i<<","<<j<<" :";
		cin>>A [i][j];
		}		
	}
	//peticion valores en la matriz B
	cout<<"Matriz B\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"Por favor digite el valor de la matriz B en la posicion "<<i<<","<<j<<" :";
		cin>>B[i][j];
		}		
	}
	//impresion matriz A 3x3
	cout<<"Matriz A:\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"|"<<A[i][j]<<"|";
		}
		cout<<"\n";			
	}


	//impresion matriz B 3x3
	cout<<"Matriz B:\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"|"<<B[i][j]<<"|";
		}
		cout<<"\n";			
	}
	//inicializacion matriz C
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		C[i][j]=0;
		}		
	}
	//generacion matriz c
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			for (int z=0; z<3; ++z)
			{
			C[i][j]+= A[i][z]*B[z][j];	
			}
		}		
	}
	//Impresion matriz C (multiplicacion A y B)
	cout<<"Matriz C (Multipliacion de matrices A y B):\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"|"<<C[i][j]<<"|";
		}
		cout<<"\n";			
	}
	


return 0;	
}

int matvect( int x, int y){
	//matriz A
	int A[3][3];
	//vector B
	int B[3];
	//resultado multiplicacion
	int C[3];
	//variable
	int i=x;
	int j=y;
	//peticion de relleno matriz A	
	cout<<"Matriz A\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"Por favor digite el valor de la matriz A en la posicion "<<i<<","<<j<<" :";
		cin>>A [i][j];
		}		
	}
	//impresion matriz A 3x3
	cout<<"Matriz A:\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
		cout<<"|"<<A[i][j]<<"|";
		}
		cout<<"\n";			
	}
	//Peticion relleno vector B
	for (i=0;i<3;i++)
	{
		cout<<"\nPor favor digite el dato en la posicion "<<i<<" :";
		cin>>B[i];
	}
	//Impresion vector B
	cout<<"vector B:\n";
	for (i=0;i<3;i++)
	{
	cout<<"|"<<B[i]<<"|";
	cout<<"\n";
	}
	//multiplicacion 
	for (i=0;i<3;i++)
	{
		C[i]=0;
	}
	//generacion  c
	for (i=0;i<3;i++)
	{
			for (j=0; j<3; ++j)
			{
			C[i]+= A[i][j]*B[i];	
			}		
	}
	//Impresion C (multiplicacion A y B)
	cout<<"Matriz C (Multipliacion de matriz A y vector B):\n";
	for (i=0;i<3;i++)
	{
		cout<<"|"<<C[i]<<"|";
		cout<<"\n";			
	}	
	
	
return 0;	
}

int cuadrado(double x, double y){
	//variables dobles
	double i=x,j=y,z;
	//peticion Peticion e impresion de la variable
	cout<<"inserte el valor de x: ";
	cin>>i;
	//declaracion exponente cuadrado
	j=2;
	z=pow(i,j);
	cout<<"el resultado de la potencia x^2 es: "<<z;
	//repeticion del sonido dependiendo del resultado
	for(int w=0; w<z;w++)
	{
		Beep(300,500);
	}
		return 0;	
}

int math(double x, double y){
//variables dobles
double i=x, j=y,z;
int op;
//submenu operaciones math.h
cout<<"Menu de operaciones Math.h\n"<<"1.seno\n"<<"2.coseno\n"<<"3.tangente\n"<<"4.seno hiperbolico\n"<<"5.coseno hiperbolico\n";
cout<<"6.tangente hiperbolica\n"<<"7.arcoseno\n"<<"8.arcocoseno\n"<<"9.arcotangente\n"<<"10.arcotangente de dos parametros\n";
cout<<"11.exponencial\n"<<"12.logaritmo natural\n"<<"13.Logaritmo en base 10\n"<<"14.potencial\n"<<"15.Raiz cuadrada\n"<<"16.ceil\n"<<"17.floor\n";
cout<<"digite la opcion: ";
//peticion de opcion
cin>>op;
system ("cls");
//condicional 1
if (op==1){

	cout<<"Seno\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=sin(i);
	cout<<"El resultado es: "<<z;
};
//condicional 2
if (op==2){

	cout<<"Coseno\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=cos(i);
	cout<<"El resultado es: "<<z;
};
//condicional 3
if (op==3){

	cout<<"Tangente\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=tan(i);
	cout<<"El resultado es: "<<z;
};
//condicional 4
if (op==4){
	cout<<"Seno Hiperbolico\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=sinh(i);
	cout<<"El resultado es: "<<z;	
};
//condicional 5
if (op==5){

	cout<<"Coseno Hiperbolico\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=cosh(i);
	cout<<"El resultado es: "<<z;
};
//condicional 6
if (op==6){

	cout<<"Tangente Hiperbolica\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=tanh(i);
	cout<<"El resultado es: "<<z;
};
//condicional 7
if (op==7){

	cout<<"Arcoseno\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=asin(i);
	cout<<"El resultado es: "<<z;
};
//condicional 8
if (op==8){

	cout<<"Coseno\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=acos(i);
	cout<<"El resultado es: "<<z;
};
//condicional 9
if (op==9){

	cout<<"Tangente\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	z=atan(i);
	cout<<"El resultado es: "<<z;
};
//condicional 10
if (op==10){

	cout<<"Tangente\n"<<"Digite el valor de x en radianes: ";
	cin>>i;
	cout<<"digite el valor de y en radianes: ";
	cin>>j;
	z=atan2(i,j);
	cout<<"El resultado es: "<<z;
};
//condicional 11
if (op==11){
	cout<<"Exponencial\n"<<"Digite el valor de x: ";
	cin>>i;
	z=exp(i);
	cout<<"El resultado es: "<<z;	
};
//condicional 12
if (op==12){
	cout<<"logaritmo natural\n"<<"Digite el valor de x: ";
	cin>>i;
	z=log(i);
	cout<<"El resultado es: "<<z;	
};
//condicional 13
if (op==13){
	cout<<"logaritmo en base 10\n"<<"Digite el valor de x: ";
	cin>>i;
	z=log10(i);
	cout<<"El resultado es: "<<z;	
};
//condicional 14
if (op==14){
	cout<<"potencia x^y\n"<<"Digite el valor de x: ";
	cin>>i;
	cout<<"\nDigite el valor de y: ";
	cin>>j;
	z=pow(i,j);
	cout<<"El resultado es: "<<z;	
};
//condicional 15
if (op==15){
	cout<<"Raiz cuadrada\n"<<"Digite el valor de x: ";
	cin>>i;
	z=sqrt(i);
	cout<<"El resultado es: "<<z;
};
//condicional 16
if(op==16){
	cout<<"Ceil(aproximacion de numero o algo asi)\n"<<"Digite el valor de x: ";
	cin>>i;
	z=ceil(i);
	cout<<"El resultado es: "<<z;
};
//condicional 17
if (op==17){
	cout<<"floor(no aproximacion de numeros)\n"<<"Digite el valor de x: ";
	cin>>i;
	z=floor(i);
	cout<<"El resultado es: "<<z;
}
return 0;
};

int fibonacci(int x,int y){
	//declaracion de las variables
	int i=x;
	int j=y;
	int k;
	int l=0;
	//defincion valores de las variables
		i=1;
		j=0;
	//bucle para la funcion	
	while (l==0){
		k=i+j;                     //1//2//3//5//8//13
		cout<<i<<"+"<<j<<"="<<k;
		j=i;					 //1//2//3//5//8//
		i=k; 					//1//1//2//3//5 
		system("pause");//evita que el codigo se ejecute sin control
	}
return 0;	
}

int triqui(int x, int y)
{
	char mat[3][3]={'1','2','3' , '4','5','6' , '7','8','9'};
	int i=x;
	int j=y;
	for (int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<"|"<<mat[i][j]<<"|";
		}
	cout<<"\n";
	}
	///blucle para controlar la cantidad de jugadas
	for (int p=0; p<5; p++){
		int j1;
		int j2;
		


/*___________________________________Jugador 1_______________*/	
		do{
			cout<<"ingrese la posicion deseada J1(X): ";
			cin>>j1;
			switch (j1){

				case 1:
				mat[0][0]= 'X';
				break;
				case 2:
				mat[0][1]='X';
				break;
				case 3:
				mat[0][2]='X';
				break;
				case 4:
				mat[1][0]='X';
				break;
				case 5:
				mat[1][1]='X';
				break;
				case 6:
				mat[1][2]='X';
				break;
				case 7:
				mat[2][0]='X';
				break;
				case 8:
				mat[2][1]='X';
				break;
				case 9:
				mat[2][2]='X';
				break;
				default:
					
				cout<<"opcion invalida\n";
			}
		}while(j1<1 || j1>9 );
/*_________________________________________impresion matriz modoficada______________*/
		system("cls");
		for (int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cout<<"|"<<mat[i][j]<<"|";
				}
			cout<<"\n";
			}
/*Condicional para victoria j1________FILA1______________________________FILA2______________________________________________FILA 3___________________________________________________DIAGONAL1_____________________________________________DAIGONAL2________________________________________________COLUMNA1__________________________________________COLUMNA2_______________________________________________COLUMNA3*/
		if ((mat[0][0]=='X' && mat[0][1]=='X'&& mat[0][2]=='X')||(mat[1][0]=='X' && mat[1][1]=='X'&& mat[1][2]=='X')||(mat[2][0]=='X' && mat[2][1]=='X'&& mat[2][2]=='X')||(mat[0][0]=='X' && mat[1][1]=='X'&& mat[2][2]=='X')||(mat[0][2]=='X' && mat[1][1]=='X'&& mat[2][0]=='X')||(mat[0][0]=='X' && mat[1][0]=='X'&& mat[2][0]=='X') || (mat[0][1]=='X' && mat[1][1]=='X'&& mat[2][1]=='X') || (mat[0][2]=='X' && mat[1][2]=='X'&& mat[2][2]=='X'))
			{
			p=6;	
			cout<<"J1 gana";
			}
		

/*________________________Jugador2____________________*/
		else if (!(p==4)){	
			do{
				cout<<"ingrese la posicion deseada J2(O): ";
				cin>>j2;
				switch (j2){
					case 1:
					mat[0][0]='O';
					break;
					case 2:
					mat[0][1]='O';
					break;
					case 3:
					mat[0][2]='O';
					break;
					case 4:
					mat[1][0]='O';
					break;
					case 5:
					mat[1][1]='O';
					break;
					case 6:
					mat[1][2]='O';
					break;
					case 7:
					mat[2][0]='O';
					break;
					case 8:
					mat[2][1]='O';
					break;
					case 9:
					mat[2][2]='O';
					break;
					default:
						
					cout<<"opcion invalida\n";
				}
			}while(j2<1 || j2>9 );
/*_________________________________________impresion matriz modoficada______________*/
			system("cls");
			for (int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					cout<<"|"<<mat[i][j]<<"|";
					}
				cout<<"\n";
				}
		}
/*Condicional para victoria j2________FILA1______________________________FILA2______________________________________________FILA 3___________________________________________________DIAGONAL1_____________________________________________DAIGONAL2________________________________________________COLUMNA1__________________________________________COLUMNA2_______________________________________________COLUMNA3*/
		if ((mat[0][0]=='O' && mat[0][1]=='O'&& mat[0][2]=='O') || (mat[1][0]=='O' && mat[1][1]=='O'&& mat[1][2]=='O') || (mat[2][0]=='O' && mat[2][1]=='O'&& mat[2][2]=='O') || (mat[0][0]=='O' && mat[1][1]=='O'&& mat[2][2]=='O') || (mat[0][2]=='O' && mat[1][1]=='O'&& mat[2][0]=='O')||(mat[0][0]=='O' && mat[1][0]=='O'&& mat[2][0]=='O') || (mat[0][1]=='O' && mat[1][1]=='O'&& mat[2][1]=='O') || (mat[0][2]=='O' && mat[1][2]=='O'&& mat[2][2]=='O'))
			{
			p=6;	
			cout<<"J2 gana";
			}			
			
	}
return 0;
};

void archivo(){
	ofstream ejemplo;
	ejemplo.open("ejemplo1.txt", ios::out);//abriendo el archivo
	
	if (ejemplo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	ejemplo<<"Hola, esto es una prueba";
	ejemplo.close();//cerrar el archivo
}

void carpeta(){
	
	//cout<<"Ruta: ";
	string ruta;
	getline(cin,ruta);
	cout<<"Nombre de la carpeta: ";
	string nombrecarp;
	getline(cin,nombrecarp);
	string ruta_absoluta = ruta + nombrecarp;
	if (mkdir(ruta_absoluta.c_str())==0)
	cout<<"Carpeta creada correctamente"<<endl;
	
	else {
	cout<<"Ha ocurrido un error al crear la carpeta"<<endl;
	carpeta ();
	}
	
}

void leer(){
	
	//declaracion de variables
	ifstream lectura;
	string texto;
	
	//Abre el archivo
	lectura.open("lectura1.txt",ios::in);
	
	//condicional por si el archivo no existe
	if(lectura.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	//bucle para leer todo el archivo
	while(!lectura.eof()){//mientras no sea el final del archivo
		getline(lectura,texto);
		cout<<texto<<"\n";
		
	}
	//se cierra el archivo
	lectura.close();
}

void definiciones(){
	//declaracion de variables
	ifstream lectura;
	string texto;
	
	//Abre el archivo
	lectura.open("definiciones.txt",ios::in);
	
	//condicional por si el archivo no existe
	if(lectura.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	//bucle para leer todo el archivo
	while(!lectura.eof()){//mientras no sea el final del archivo
		getline(lectura,texto);
		cout<<texto<<"\n";
		
	}
	//se cierra el archivo
	lectura.close();
	
}
