#include "trimatrix.hpp"

int main()
{

	double L,T,alpha;
	int Nx,Nt;
	std::cout<<"Please input length of bar: ";
	std::cin>>L;
	std::cout<<"Please input number Nx: ";
	std::cin>>Nx;
	std::cout<<"Please input evaluated time T: ";
	std::cin>>T;
	std::cout<<"Please input number Nt: ";
	std::cin>>Nx;
	std::cout<<"please input heat coefficient alpha: ";
	std::cin>>alpha;
	trimatrix matrix(L,Nx,T,Nt,alpha);
	matrix.disp_matrix();
}