#include "trimatrix.hpp"
#include <stdlib.h>
#include <iostream>
int main(int argc, char* argv[])
{
/*	double L,T,alpha,gamma1,gamma2;
	int Nx,Nt;
	if (argc<7)
	{
		std::cout<<"Not enough input arguments";
	}
	else if (argc==7)
	{
*/		double L=atof(argv[1]);
		int Nx=atoi(argv[2]);
 		double T=atof(argv[3]);
  		int Nt=atoi(argv[4]);
		double alpha=atof(argv[5]);
		double gamma1=atof(argv[6]);
		double gamma2=atof(argv[7]);
//	}
//	double L,T,alpha,gamma1,gamma2;
//	int Nx,Nt;
/*	std::cout<<"Please input length of bar: ";
	std::cin>>L;
	std::cout<<"Please input number Nx: ";
	std::cin>>Nx;
	std::cout<<"Please input evaluated time T: ";
	std::cin>>T;
	std::cout<<"Please input number Nt: ";
	std::cin>>Nt;
	std::cout<<"please input heat coefficient alpha: ";
	std::cin>>alpha;
	L=1;
	Nx=10;
	T=10000;
	alpha=1.6;
	Nt=1000;
	gamma1=0;
	gamma2=0;
*/	trimatrix bar(L,Nx,T,Nt,alpha,gamma1,gamma2);
//	bar.display_matrix();
	bar.set_boundary_conditions();
	// bar.display_vector(bar.u0);
	// bar.calculate();
	// bar.display_vector(bar.u);
	// bar.calculate();
	// bar.display_vector(bar.u);
	bar.full_calculation();
//	bar.display_vector(bar.u0);
//	bar.~trimatrix();
//	bar.display_vector(bar.u);
//	bar.display_vector(bar.u0);

}
