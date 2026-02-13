#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main(void)
{
	int recorrido=1;
	while(recorrido<2000)
	{
		system ("cls");
		cout<<"frecuencia a sonar es: \n"<<recorrido;
		Beep(recorrido,1000);
		system ("pause");
		recorrido=recorrido+100;
	};
};
