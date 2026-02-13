#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main (void)
{
	system ("Cls");
	int num;
	while(num<20)
	{
	
	cout<<"\nDigite el numero: ";
	cin>>num;
	if (num<20)
		Beep(423,500);
	else
		Beep(523,1000);
	}
};
