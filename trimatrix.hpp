#include<iostream>
#include<vector>
#include<math.h>

class trimatrix
{
private:
	double L,T,alpha;
	int Nx,Nt;
	double* matrix = new double;
public:
	std::vector<double> u,u0;

	trimatrix(double& L,int& Nx,double& T, int& Nt,double& alpha)
	{
		double* matrix = new double[Nx*Nx];
		for (int i=0; i < Nx;i++){
			for (int j=0; j < Nx;j++){
				if (i==j)
				{
					matrix[i*Nx+j]=1-(2*alpha*L/Nx)/(pow(T/Nt,2));
				}
			}

		}
	}
	void disp_matrix()
	{
		for (int i=0;i < Nx;i++){
			for (int j=0;j < Nx;j++)
			{	
				std::cout<<matrix[i*Nx+j]<<" ";
			}
			std::cout<<"\n";
		}
	}
	~trimatrix()
	{
		delete [] matrix;
	}
};