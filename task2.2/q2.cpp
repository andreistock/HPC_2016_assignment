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

int main(int argc, char* argv[])
{
	double L=atof(argv[1]);
	int Nx=atoi(argv[2]);
	double T=atof(argv[3]);
	int Nt=atoi(argv[4]);
	double alpha=atof(argv[5]);
	double gamma1=atof(argv[6]);
	double gamma2=atof(argv[7]);

	double delta_t,delta_x,niu;
	std::vector<double> u,u0;
	gamma1=0;
	gamma2=0;
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

	u0.resize(Nx+1);
	u.resize(Nx+1);

	delta_t=T/(double)Nt;
	delta_x=L/(double)Nx;
	niu=alpha*delta_t/(pow(L/delta_x,2));

	trimatrix bar(Nx,niu,niu,1-2*niu);
//	bar.display_matrix();
	set_boundary_conditions(u0,L,Nx);
	bar.full_calculation(T,delta_t,u0,u,Nx,gamma1,gamma2);
	display_vector(u0);
	return 0;
}
