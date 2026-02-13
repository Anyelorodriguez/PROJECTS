//triqui

#include <iostream>

using namespace std;

int main(void)
{
	char dato [2];
	for (int i = 0; i < 3; i++)
	{
		cout<<"\npor favor digite un dato en la posicion " <<i<<" :";
		cin>>dato[i];
	}
		for (int i = 0; i < 3; i++)
	{
		cout<<"\nlos datos digitados son: "<<dato[i];
	}
}
