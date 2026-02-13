#include <iostream>

using namespace std;

int main()
{
	char mat[2][2];
	int i=0,j=0;
	for (i=0;i<3;i++)
	{
		j=0;
		while(j<3)
		{
			cout<<"Por favor digite el valor en la posicion "<<i<<","<<j<<" :";
			cin>>mat[i][j];
			j++;
		}
	}
	for (i=0;i<3;i++)
	{
		j=0;
		while(j<3)
		{
			//cout<<"Informacion en la matriz en la posicion "<<i<<","<<j<<" "<<mat[i][j];

			cout<<"\n"<<i<<","<<j<<" "<<mat[i][j];
			j++;
		}
	}
	return 0;
};

