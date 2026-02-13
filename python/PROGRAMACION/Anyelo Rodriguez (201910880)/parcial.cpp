/*
Por favor desarrollar un sistema que pida los siguientes datos de un usuario:
 nombre, apellido, fecha de nacimiento, (debe calcular la edad actual de la persona y registrarla),
  salario, calcular el 10% del salario. Almacenarlo en un archivo.
   Y realizar la suma total de las personas registradas, salarios totales.
    Cada registro de usuario debe ingresarse en un solo archivo sin perder el contenido del mismo
	 y los usuarios inscritos. Solo almacenamiento e impresión por pantalla. Menu,
 1. ingreso de usuario.
  2. Impresion de usuarios. 
  3. Calculo total de usuarios y total salarios.
  */
#include <iostream>
#include <Fstream>//archivos
#include <ctime>//Hora fecha minutos segundos
#include <math.h>

using namespace std;
//funciones
void menu();//menu
void reg();
void lectu();
void funcion();
int calcu();
void borrar();

int main(void)
{
	menu();// llama menu principal
}

void menu()//menu principal
{
	int opc;
	cout<<"\nPROGRAMA PARCIAL 2DO 50\n  1. registrar usuario.\n  2. lectura de registros.\n  3. Calculo total de usuarios y total salarios.\n  4. Borrar registros\n  5. calcular funcion (X^2)+sen(y)+z\n";
	cin>>opc;
	if (opc==1)
		{
			reg();
		}
	else if (opc==2)
		{
			lectu();
		}
	else if(opc==3)
		{
			calcu();
		}
	else if(opc==4)
		{
			borrar();
		}
	else if(opc==5)
		{
			funcion();
		}
}
void reg()
{
	ofstream registro;
	registro.open("registro.txt", ios::app);//creando o abriendo archivo
	if (registro.is_open())
	{
			string linea,error,nom,apel;
				int dia,mes,year,edad,sala,sala10;
				getline(cin,error);
			cout<<"\ndigite su(s) nombre(s): ";
				getline(cin,nom);
			cout<<"digite su(s) apellido(s): ";
				getline(cin,apel);
			cout<<"\nFecha de nacimiento (en numeros).";
			cout<<"\ndigite su dia de nacimiento: ";
				cin>>dia;
			cout<<"digite su mes de nacimiento: ";
				cin>>mes;
			cout<<"digite su anio de nacimiento: ";
				cin>>year;
			if(mes<9)
				{
				edad=2020-year;
				}
			else if(mes>8)
				{
				edad=2020-year-1;
				}
			cout<<"\nsu edad es:"<<edad;
			cout<<"\ndigite su salario mensual sin puntos ni signos: ";
				cin>>sala;
			sala10=sala*0.1;
			cout<<"el 10% de su salario es: "<<sala10<<"\n\n";
			system("pause");
			system ("cls");
			registro<<" nombre de usuario: "<<nom<<" "<<apel<<"\n fecha de nacimiento: "<<dia<<"/"<<mes<<"/"<<year<<"\n edad: "<<edad<<"\n salario mensual: "<<sala<<"\n 10% salario: "<<sala10<<"\n\n";
			cout<<"\n nombre de usuario: "<<nom<<" "<<apel<<"\n fecha de nacimiento: "<<dia<<"/"<<mes<<"/"<<year<<"\n edad: "<<edad<<"\n salario mensual: "<<sala<<"\n 10% salario: "<<sala10;
			cout<<"\n\n REGISTRO CORRECTO";
	}
	else
	{
		cout<<"\n ERROR AL ENCONTRAR ARCHIVO DE REGISTROS\n";
	}
};
void lectu()
{
	system ("cls");
	cout<<"REGISTROS\n\n";
	fstream archivo;
	archivo.open("registro.txt",ios::in);//Abre el archivo
	
	if(archivo.is_open()) //lectura de archivo
	{
		string lectu;
		while(getline(archivo,lectu))
		{
			cout<<lectu<<endl;
		}
		
		archivo.close();
	}
	else
	{
		cout<<"hubo un problema la abrir el archivo de registros";
	}
	//se cierra el archivo
	archivo.close();
};	
int calcu()
{
	int y,z;
	ifstream calcureg;
	string texto;
	calcureg.open("registro.txt",ios::in);//abre archivo
	y=0;
	if(calcureg.fail())//por si no existe
		{
			cout<<"hubo un problema la abrir el archivo de registros";
		}
	while(!calcureg.eof())
	{		
		for (int x=0;x<6;x++)
			{
			getline(calcureg,texto);
			}
		y++;	
	}
	z=y-1;	
	cout<<"Cantidad de registros: "<<z<<"\n";
	calcureg.close();
	system("pause");
	
};
void funcion()
{
	int x,y,z,a=2,res;	
		cout<<"Operacion: (X^2)+sen(y)+z";
		cout<<"\npor favor ingrese el valor de x: ";
		cin>>x;
		cout<<"\npor favor ingrese el valor del angulo 'y' en radianes: ";
		cin>>y;
		cout<<"\npor favor ingrese el valor de z: ";	
		cin>>z;	
		res=pow(x,a)+sin(y)+z;
		cout<<"\nEl resultado de la operacion es: "<<res;
}
void borrar()
{
	fstream borr;
	borr.open("registro.txt", ios::out);
	borr.close();
}
