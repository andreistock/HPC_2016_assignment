#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
int numbers()
	{
		return 1;
	}
void print(double k)
{
	std::cout<<k<<" ";
}

class trimatrix
{
private:
	double L,T,alpha,gamma1,gamma2,niu,delta_t,delta_x;
	int Nx,Nt;
	double *mDiag=NULL;
	double *mUpper=NULL;
	double *mLower=NULL;

public:
	std::vector<double> u,u0;

	trimatrix(double& L1,int& Nx1, double& T1,int& Nt1,double& alpha1,double& gamma11,double& gamma21)
	{
		L=L1;Nx=Nx1;T=T1;Nt=Nt1;alpha=alpha1;gamma1=gamma11;gamma2=gamma21;
		delta_t=T/(double)Nt;
		delta_x=L/(double)Nx;
		niu=alpha*delta_t/(pow(L/delta_x,2));
		mDiag = new double[Nx+1];
		mUpper = new double[Nx];
		mLower = new double[Nx];
		for (int i=1; i <=Nx;i++){


			mDiag[i]=1-2*niu;
			mUpper[i-1]=niu;
			mLower[i-1]=niu;

		}

		mDiag[0]=1;   //Setting end point conditions
		mDiag[Nx]=1;
		mUpper[Nx]=niu;
		mDiag[Nx+1]=1;
		mLower[Nx-1]=0;
		u0.resize(Nx+1);
		u.resize(Nx+1);
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
	void set_boundary_conditions()
	{
		double k;
		for (double i=0;i<=Nx;i++)
		{

			k=i*L/(double)Nx;
			std::cout<<k<<"\n";
			u0[i]=k*(1-k);
		}
	}
	void display_vector(std::vector<double> uk)
	{
		for_each(uk.begin(),uk.end(),print);
		std::cout<<"\n";
	}
	void calculate()
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
	void full_calculation()
	{
	
		for(double i=0;i<T;i+=delta_t)
		{
			calculate();
		}
	}
	~trimatrix()
	{
//		delete[] mDiag;
//		delete[] mUpper;
//		delete[] mLower;
	}

};
