#include "trimatrix.hpp"
#include <vector>
#include <algorithm>
#include <math.h>
void print(double k)
{
	std::cout<<k<<" ";
}
void set_boundary_conditions(std::vector<double> &u0,double &L,int &Nx)
{
	double k;
	for (double i=0;i<=Nx;i++)
	{
		k=i*L/(double)Nx;
//		std::cout<<k<<"\n";
		u0[i]=k*(1-k);
	}
}
void display_vector(std::vector<double> &uk)
{
	for_each(uk.begin(),uk.end(),print);
	std::cout<<"\n";
}
void calculate(std::vector<double> &u0,std::vector<double> &u,int &Nx,double &gamma1,double &gamma2,trimatrix &bar)
{
	u[0]=gamma1;
	u[Nx]=gamma2;
	double sum=0;
	for (int i=1;i<Nx;i++){
		sum=0;
		for(int j=0;j<Nx;j++){
			if(i==j)
			{
				sum=sum+bar.mDiag[i]*u0[i];
			}
			else if(j==i-1)
			{
				sum=sum+bar.mLower[j]*u0[i-1];
			}
			else if(j==i+1)
			{
				sum=sum+bar.mUpper[j]*u0[i+1];
			}
		}
		u[i]=sum;
	}
	u0=u;
}
void full_calculation(double &T,
					  double &delta_t,std::vector<double> &u0,
					  std::vector<double> &u,
					  int &Nx,double &gamma1,double &gamma2,trimatrix &bar)
{

	for(double i=0;i<T;i+=delta_t)
	{
		calculate(u0,u,Nx,gamma1,gamma2,bar);
	}
}
int numbers()
{
	return 1;
}
int main()
{
	double L,T,alpha,gamma1,gamma2,niu,delta_t,delta_x;
	int Nx,Nt;
    L=1;
	Nx=100;
	T=200000000;
	alpha=1;
	Nt=100000;
	gamma1=0;
	gamma2=0;
	std::vector<double> u,u0;
	u0.resize(Nx+1);
	u.resize(Nx+1);

	delta_t=T/(double)Nt;
	delta_x=L/(double)Nx;
	niu=alpha*delta_t/(pow(L/delta_x,2));

	// std::cout<<"Please input length of bar: ";
	// std::cin>>L;
	// std::cout<<"Please input number Nx: ";
	// std::cin>>Nx;
	// std::cout<<"Please input evaluated time T: ";
	// std::cin>>T;
	// std::cout<<"Please input number Nt: ";
	// std::cin>>Nt;
	// std::cout<<"please input heat coefficient alpha: ";
	// std::cin>>alpha;

	trimatrix *bar = new trimatrix(Nx,niu,niu,1-2*niu,gamma1,gamma2);
	bar->display_matrix();
	set_boundary_conditions(u0,L,Nx);
//	display_vector(u0);
//	calculate(u0,u,Nx,gamma1,gamma2,bar);
//	display_vector(u0);
//	calculate(u0,u,Nx,gamma1,gamma2,bar);
//	display_vector(u0);
	full_calculation(T,delta_t,u0,u,Nx,gamma1,gamma2,*bar);
	display_vector(u0);
	delete bar;
//	bar.display_vector(bar.u);
//	bar.display_vector(bar.u0);
}
