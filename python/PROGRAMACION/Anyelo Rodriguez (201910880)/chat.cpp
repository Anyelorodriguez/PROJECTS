#include <iostream>
#include <ctime>//Hora fecha minutos segundos
#include <Fstream>//archivos

using namespace std;
void chat();
void leer();
void borrar();
int hela1();

int main(void)
{
	int opc;
	cout<<"\nchat entre amigos\n";
	cout<<" 1. iniciar chat.\n 2. historial.\n 3. borrar historial.\n 4. heladeria\n";
	cout<<"presione cualquier otra tecla para cerrar\n";
	cin>>opc;
	if (opc==1)
	{
		chat();
	}
	else if (opc==2)
	{
		cout<<"\n"<<"HISTORIAL"<<"\n"<<"\n";
		leer();
	}
	else if (opc==3)
	{
		borrar();
	}
	else if (opc==4)
	{
		hela1();
	}
	else
	{
	cout<<"\nsaliendo del sistema :(";
	}
};
void leer()
{
	fstream archivo;
	archivo.open("chat.txt",ios::in);//Abre el archivo
	
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
		cout<<"hubo un problema la abrir el archivo";
	}
	//se cierra el archivo
	archivo.close();
};
void chat()
{
	int x,y,z,a,b,c;
	time_t now=time(0);
	tm*time=localtime(&now);
	//impresion de la hora segun cada parametro
	x=time->tm_hour;
	y=time->tm_min;
	z=time->tm_sec;
	//se le suma 1 a el mes porque enero seria cero y se le suma 1900 a el añor porque solo cuenta el programa desde 1900
	a=time->tm_mday;
	b=time->tm_mon+1;
	c=time->tm_year+1900;
	
	ofstream chat;
	chat.open("chat.txt", ios::app);//creando o abriendo archivo
	if (chat.is_open())
	{
		string salida_texto;
		string linea,error,nom,apel,fecha;
				getline(cin,error);
			cout<<"\ndigite su nombre: ";
				getline(cin,nom);
			cout<<"digite su apellido: ";
				getline(cin,apel);
		cout<<"\nACTIVO\n";
		cout<<nom<<" "<<apel<<"\n"<<x<<":"<<y<<":"<<z<<" - "<<a<<"/"<<b<<"/"<<c<<"\n"<<linea<<"\n";
		cout<<"escriba su mensaje\n";
		chat<<"ACTIVO\n";
		chat<<nom<<" "<<apel<<"\n"<<x<<":"<<y<<":"<<z<<" - "<<a<<"/"<<b<<"/"<<c<<"\n"<<"\n"<<"\n";
		chat.close();
		for(;;)
		{
			chat.open("chat.txt", ios::app);
			getline(cin,linea);
			if(linea == "link")
			{
				
				cout<<"DESCONECTADO\n";
				cout<<nom<<" "<<apel<<"\n"<<x<<":"<<y<<":"<<z<<" - "<<a<<"/"<<b<<"/"<<c<<"\n"<<"\n"<<"\n";
				break;
			}
			else if(linea == "read")
				{
				leer();
				}
			chat<<nom<<" "<<apel<<"\n"<<x<<":"<<y<<":"<<z<<" - "<<a<<"/"<<b<<"/"<<c<<"\n"<<linea<<"\n"<<"\n";
			chat.close();
			system ("cls");
			leer();
			cout<<"\nescriba su mensaje\nescriba 'link' para cerrar el programa -- escriba 'read' para ver nuevos mensajes\n\n";
		}
		chat<<"DESCONECTADO\n";
		chat<<nom<<" "<<apel<<"\n"<<x<<":"<<y<<":"<<z<<" - "<<a<<"/"<<b<<"/"<<c<<"\n"<<"\n"<<"\n";
		chat.close();
		system("pause");
	}
	else
	{
		cout<<"no se encontro el archivo ";
	}
}
int hela1()
{
	int x,y,z,e,f;
	x=10;
	y=2500;
	cout<<"cuantos helados quire:";
	cin>>z;
	e=x-z;
	if (z<=10)
		{
			cout<<"helados que quedan: "<<e;
			f=y*z;
			cout<<"el precio de los helados es: "<<f;
		}
	
	else
		{
			cout<<"no hay suficientes helados";
			
		}
	
}
void borrar()
{
	fstream borr;
	borr.open("chat.txt", ios::out);
	borr.close();
}
