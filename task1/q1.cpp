#include "trimatrix.hpp"

int main()
{

	double L,T,alpha,gamma1,gamma2;
	int Nx,Nt;
	std::cout<<"Please input length of bar: ";
	std::cin>>L;
	std::cout<<"Please input number Nx: ";
	std::cin>>Nx;
	std::cout<<"Please input evaluated time T: ";
	std::cin>>T;
	std::cout<<"Please input number Nt: ";
	std::cin>>Nt;
	std::cout<<"please input heat coefficient alpha: ";
	std::cin>>alpha;
/*	L=1;
	Nx=20;
	T=100;
	alpha=1.6;
	Nt=100;
*/	gamma1=0;
	gamma2=0;
	trimatrix bar(L,Nx,T,Nt,alpha,gamma1,gamma2);
	bar.display_matrix();
	bar.set_boundary_conditions();
	bar.display_vector(bar.u0);
	bar.calculate();
	bar.display_vector(bar.u);
	bar.calculate();
	bar.display_vector(bar.u);
	bar.full_calculation();
	bar.display_vector(bar.u0);
//	bar.~trimatrix();
//	bar.display_vector(bar.u);
//	bar.display_vector(bar.u0);

}
