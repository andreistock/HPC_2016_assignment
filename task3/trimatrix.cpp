#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <cstring>
#include <algorithm>
void print(double k)
{
	std::cout<<k<<" ";
}


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
	u0.resize(Nx+1);
	u.resize(Nx+1);

}
trimatrix::trimatrix(const trimatrix& pSrc)
        : mSize(pSrc.mSize),
          mZero(0.0) {
    mDiag  = new double[mSize];
    mLower = new double[mSize - 1];
    mUpper = new double[mSize - 1];
    memcpy(mDiag,  pSrc.mDiag,  sizeof(double) * mSize);
    memcpy(mLower, pSrc.mLower, sizeof(double) * (mSize - 1));
    memcpy(mUpper, pSrc.mUpper, sizeof(double) * (mSize - 1));
}

trimatrix::~trimatrix()
{
	// delete [] mDiag;
	// delete [] mUpper;
	// delete [] mLower;
}
void trimatrix::set_boundary_conditions(std::vector<double> &u0,double &L,int &Nx)
{
	double k;
	for (double i=0;i<=Nx;i++)
	{
		k=i*L/(double)Nx;
//		std::cout<<k<<"\n";
		u0[i]=k*(1-k);
	}
}


void trimatrix::display_vector(std::vector<double> &uk)
{
	for_each(uk.begin(),uk.end(),print);
	std::cout<<"\n";
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
trimatrix& trimatrix::operator=(const trimatrix& pSrc) {
    mDiag = pSrc.mDiag;
    mLower = pSrc.mLower;
    mUpper = pSrc.mUpper;
    return *this;
}
trimatrix trimatrix::operator/(const trimatrix& pSrc) {
    trimatrix result(*this);
    double m;

    for (int i=2;i<Nx;i++)
    {
    	m=
    }

//    result *= 1.0/pVal;

    return result;
}
void trimatrix::calculate(double &gamma1,double &gamma2)
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
					  double &delta_t,double &gamma1,double &gamma2)
{

	for(double i=0;i<T;i+=delta_t)
	{
		calculate(gamma1,gamma2);
	}
}
