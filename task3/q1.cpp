#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "trimatrix.hpp"
#include "trimatrix.cpp"


int main()
{
	double L,T,alpha,gamma1,gamma2,niu,delta_t,delta_x;
	int Nx,Nt;
    L=1;
	Nx=20;
	T=2000000;
	alpha=1;
	Nt=1000000;
	gamma1=0;
	gamma2=0;
	double niu1=0;



	// std::cout<<"Please input length of bar: ";
	// std::cin>>L;
	// if (L==0)
	// {
	// 	std::cout<<"Must input non 0 Length of bar!\n";
	// 	throw;
	// }
	// else if(L<0)
	// {
	// 	std::cout<<"Must input Lenght of bar larger than 0\n";
	// 	throw;
	// }
	// std::cout<<"Please input number Nx: ";
	// std::cin>>Nx;
	// if (Nx==0)
	// {
	// 	std::cout<<"Must input non 0 number of discretisation points\n";
	// 	throw;
	// }
	// else if(Nx<0)
	// {
	// 	std::cout<<"Must input nr of discretisation points larger than 0\n";
	// 	throw;
	// }
	// std::cout<<"Please input evaluated time T: ";
	// std::cin>>T;
	// if (T==0)
	// {
	// 	std::cout<<"Must input non 0 evaluated time\n";
	// 	throw;
	// }
	// else if(T<0)
	// {
	// 	std::cout<<"Must input evaluated time larger than 0\n";
	// 	throw;
	// }
	// std::cout<<"Please input number Nt: ";
	// std::cin>>Nt;
	// if (Nt==0)
	// {
	// 	std::cout<<"Must input non 0 number of time discretisation points\n";
	// 	throw;
	// }
	// else if(Nt<0)
	// {
	// 	std::cout<<"Must input nr of time discretisation points larger than 0\n";
	// 	throw;
	// }
	// std::cout<<"please input heat coefficient alpha: ";
	// std::cin>>alpha;

	
	delta_t=T/(double)Nt;
	delta_x=L/(double)Nx;
	niu=alpha*delta_t/(pow(L/delta_x,2));

	trimatrix bar(Nx,niu,niu,1-2*niu);
	trimatrix bar1(Nx,niu,niu,1-2*niu);
	bar.display_matrix();
	bar1.display_matrix();
	bar1.set_boundary_conditions(bar1.u0,L,Nx);
	bar.set_boundary_conditions(bar.u0,L,Nx);
	trimatrix bar2(Nx,niu,niu,1-2*niu);
	for (int i=0;i<T;i+=delta_t)
	{
		bar2=bar/bar1;
	}
	// bar.full_calculation(T,delta_t,gamma1,gamma2);
	bar2.display_vector(bar2.u0);
	bar.display_vector(bar.u0);
	bar1.display_vector(bar1.u0);
	bar1.display_matrix();
	bar.display_matrix();
	bar2.display_matrix();
	return 0;
}
