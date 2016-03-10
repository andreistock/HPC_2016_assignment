#include "trimatrix.hpp"

int main()
{

	double L,T,alpha;
	int Nx,Nt;
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
*/	L=1;
	Nx=20;
	T=100;
	alpha=1;
	Nt=1000;
	trimatrix bar(L,Nx,T,Nt,alpha);
	bar.display_matrix();
	bar.display_vector(bar.u0);
	bar.set_boundary_conditions();
	bar.display_vector(bar.u0);
	bar.calculate();
	bar.display_vector(bar.u);

}
