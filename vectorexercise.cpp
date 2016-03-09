#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
int random1()
{
	return rand()%1000;
}
void print(double k)
{
	std::cout<<k<<"\n";
}
int main()
{
	std::vector<double> v1(100);
	std::vector<double> v2(100);
	std::vector<double>::iterator vIt;
	generate(v1.begin(),v1.end(),random1);
	for_each(v1.begin(),v1.end(),print);
	double *matrix=new double[10*10];
	for (unsigned int i=0;i<10;i++)
	{
		for (unsigned int j=0;j<10;j++)
		{
			if (i==j)
			{
				matrix[i*10+j]=1;
			}
		}
	}

	delete [] matrix;
	std::cout<<5/2.0;
	double** pvalue  = NULL;     // Pointer initialized with null
	pvalue  = new double [10][10];
	for (unsigned int i=0;i<10;i++)
	{
		for (unsigned int j=0;j<10;j++)
		{
			if (i==j)
			{
				pvalue[i][j]=2;
			}
		}
	}
	std::cout<<pvalue[5][5];
}