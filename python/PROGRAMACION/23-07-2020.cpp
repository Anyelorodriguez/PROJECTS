#include <iostream>
#include <math.h>

using namespace std; 

int main (void)
{
	int var1, var2, var3;
	cout<<"por ingrese el primer valor: " ;
	cin>>var1;
	cout<<"\npor ingrese el primer valor: ";
	cin>>var2;
	cout<<"\npor ingrese el primer valor: ";
	cin>>var3;
	if ((var1<var2) && (var1<var3))
		cout<<"variable 1 la menor de las 3 : "<<var1;
	else if ((var1>var2) && (var1<var3))
		cout<<"variable 2 la menor de las 3 : "<<var2;
	else
		cout<<"error de funcionamiento";
}
