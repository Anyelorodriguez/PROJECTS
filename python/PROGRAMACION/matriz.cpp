
#include <iostream>

using namespace std;

int main()
{
	char matri[2][2];
	int i=0,j=0;
	for (i=0;i<3;i++)
		{
			j=0;
			while(j<3)
			{
		
			cout<<"por favor digite el valor en la posicion " <<i<<","<<j<<" : ";
			cin>>matri[i][j];
			j++;
			}
		}
		for (i=0;i<3;i++)
	{
		j=0;
		while(j<3)
		{
		
			cout<<"\n"<<i<<","<<j<<" : "<<matri[i][j];
			j++;
		
		}
	}
	return 0;	
};

