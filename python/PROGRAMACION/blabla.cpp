//inicio de libreria
#include <iostream>
//uso de espacio de memoria 
using namespace std;
//inicio de funcion sin retorno
int main(void)
{
// variables - variable definition area
char Name [200];
char surname [200];
char age [200];
char address [200];
// print the variable
cout << Name;
cout << surname;
cout << age;
cout << address;
// print text to request user information
cout<<"\n type the name:";
// acquisition of information by input
cin >> Name;
cout << "\n type the last name:";
cin >> surname;
cout << "\n type the age:";
cin >> age;
cout << "\n type the address";
cin >> address;
// output message by autput of variable name at position 2
cout << "the name is:" << Name;
// print output of variable name
// the name of the variable depends on where they are defined
cout << "\n The last name is:" << surname;
cout << "\n age is:" << age;
cout << "\n the address is:" << address;
};
