#include <iostream>
#include <math.h>
class trimatrix
{
private:
	
	int Nx;


public:
	double *mDiag=NULL;
	double *mUpper=NULL;
	double *mLower=NULL;
	trimatrix(int Nx1,double elem_upper,double elem_lower,double elem_princ,double gamma1,double gamma2 )
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
		mDiag[Nx+1]=1;
		mLower[Nx-1]=0;
	}
	
	void display_matrix()
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




	~trimatrix()
	{
		// delete [] mDiag;
		// delete [] mUpper;
		// delete [] mLower;
	}

};
