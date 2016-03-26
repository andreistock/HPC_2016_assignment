#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "trimatrix.hpp"
#include "trimatrix.cpp"

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

int main()
{
	double L,T,alpha,gamma1,gamma2,niu,delta_t,delta_x;
	int Nx,Nt;
	std::vector<double> u,u0;
 //    L=1;
	// Nx=20;
	// T=200000;
	// alpha=1;
	// Nt=1000;
	gamma1=0;
	gamma2=0;




	std::cout<<"Please input length of bar: ";
	std::cin>>L;
	if (L==0)
	{
		std::cout<<"Must input non 0 Length of bar!\n";
		throw;
	}
	else if(L<0)
	{
		std::cout<<"Must input Lenght of bar larger than 0\n";
		throw;
	}
	std::cout<<"Please input number Nx: ";
	std::cin>>Nx;
	if (Nx==0)
	{
		std::cout<<"Must input non 0 number of discretisation points\n";
		throw;
	}
	else if(Nx<0)
	{
		std::cout<<"Must input nr of discretisation points larger than 0\n";
		throw;
	}
	std::cout<<"Please input evaluated time T: ";
	std::cin>>T;
	if (T==0)
	{
		std::cout<<"Must input non 0 evaluated time\n";
		throw;
	}
	else if(T<0)
	{
		std::cout<<"Must input evaluated time larger than 0\n";
		throw;
	}
	std::cout<<"Please input number Nt: ";
	std::cin>>Nt;
	if (Nt==0)
	{
		std::cout<<"Must input non 0 number of time discretisation points\n";
		throw;
	}
	else if(Nt<0)
	{
		std::cout<<"Must input nr of time discretisation points larger than 0\n";
		throw;
	}
	std::cout<<"please input heat coefficient alpha: ";
	std::cin>>alpha;

	u0.resize(Nx+1);
	u.resize(Nx+1);

	delta_t=T/(double)Nt;
	delta_x=L/(double)Nx;
	niu=alpha*delta_t/(pow(L/delta_x,2));

	trimatrix bar(Nx,niu,niu,1-2*niu);
	bar.display_matrix();
	set_boundary_conditions(u0,L,Nx);
	bar.full_calculation(T,delta_t,u0,u,Nx,gamma1,gamma2);
	display_vector(u0);
	return 0;
}
