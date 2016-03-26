#include <iostream>
#include <math.h>
#include <vector>



trimatrix::trimatrix(int &Nx1,double &elem_upper,double &elem_lower,double elem_princ)
{
	Nx=Nx1;
	mDiag = new double[Nx+1];
	mUpper = new double[Nx];
	mLower = new double[Nx];
	for (int i=1; i <=Nx;i++){
		mDiag[i]=elem_princ;
		mUpper[i-1]=elem_upper;
		mLower[i-1]=elem_lower;

	}
	mDiag[0]=1;   //Setting end point conditions
	mDiag[Nx]=1;
	mUpper[Nx]=elem_upper;
	mDiag[Nx]=1;
	mLower[Nx-1]=0;
}

trimatrix::~trimatrix()
{
	// delete [] mDiag;
	// delete [] mUpper;
	// delete [] mLower;
}

void trimatrix::display_matrix()
{
	for (int i=0;i<=Nx;++i){
		for(int j=0;j<=Nx;j++){
			if (i==0){
				if (i==j){
					std::cout<<mDiag[i]<<" ";
				}
				else {
					std::cout<<"0 ";
				}
			}
			else if(j==i-1){
					std::cout<<mLower[j]<<" ";
				}

				else if(j==i){
					std::cout<<mDiag[i]<<" ";
				}
				else if(j==i+1){
					std::cout<<mUpper[j]<<" ";
				}
				else {
					std::cout<<"0 ";
				}
		}
	std::cout<<"\n";
	}
}
void trimatrix::calculate(std::vector<double> &u0,std::vector<double> &u,int &Nx,double &gamma1,double &gamma2)
{
	u[0]=gamma1;
	u[Nx]=gamma2;
	double sum=0;
	for (int i=1;i<Nx;i++){
		sum=0;
		for(int j=0;j<Nx;j++){
			if(i==j)
			{
				sum=sum+mDiag[i]*u0[i];
			}
			else if(j==i-1)
			{
				sum=sum+mLower[j]*u0[i-1];
			}
			else if(j==i+1)
			{
				sum=sum+mUpper[j]*u0[i+1];
			}
		}
		u[i]=sum;
	}
	u0=u;
}
void trimatrix::full_calculation(double &T,
					  double &delta_t,std::vector<double> &u0,
					  std::vector<double> &u,
					  int &Nx,double &gamma1,double &gamma2)
{

	for(double i=0;i<T;i+=delta_t)
	{
		calculate(u0,u,Nx,gamma1,gamma2);
	}
}
