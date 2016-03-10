#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
int numbers()
	{
		return 1;
	}
void print(double k)
{
	std::cout<<k<<" ";
}

class trimatrix
{
private:
	double L,T,alpha;
	int Nx,Nt;
	double *matrix=NULL;
	double niu;

public:
	std::vector<double> u,u0;
	trimatrix(double& L1,int& Nx1, double& T1,int& Nt1,double& alpha1)
	{
		L=L1;Nx=Nx1;T=T1;Nt=Nt1;alpha=alpha1;
		niu=(alpha*T/Nt)/(pow(L/Nx,2));
		matrix = new double[Nx*Nx];
		for (int i=0; i <=Nx;++i){
			for (int j=0; j <=Nx;++j){
				if ((i==j)&&(i!=0)&&(j!=Nx)&&(j!=Nx-1))
				{
					matrix[i*Nx+j]=1-2*niu;
					matrix[i*Nx+j-1]=niu;
					matrix[i*Nx+j+1]=niu;
				}

			}
		}
		matrix[0]=1;   //Setting end point conditions
		matrix[Nx*Nx-1]=1;
//		u0.resize(Nx);
//		generate(u0.begin(),u0.end(),numbers);
//		for_each(u0.begin(),u0.end(),print);
	}
	~trimatrix()
	{
		delete [] matrix;
	}
	void display_matrix()
	{
		for (int i=0;i <=Nx;++i){
			for (int j=0;j <=Nx;++j)
			{
				std::cout<<matrix[i*Nx+j]<<" ";
			}
			std::cout<<"\n";
		}
	}
	void set_boundary_conditions()
	{
		double k;
		for (double i=0;i<=Nx;i++)
		{

			k=i*L/(double)Nx;
			std::cout<<k<<"\n";
			u0.push_back(k*(1-k));
		}
	}
	void display_vector(std::vector<double> uk)
	{
		for_each(uk.begin(),uk.end(),print);
		std::cout<<"\n";
	}
	void calculate()
	{
		double sum=0;
		for (int i=0;i<=Nx;++i){
			for (int j=0;j<=Nx;++j){
				sum=sum+matrix[i*Nx+j]*u0[j];
			}
			u.push_back(sum);
		}
	}
};
