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
	double L,T,alpha;
	int Nx,Nt;
	double *mDiag=NULL;
	double *mUpper=NULL;
	double *mLower=NULL;

	double niu;

public:
	std::vector<double> u,u0,u1;
	trimatrix(double& L1,int& Nx1, double& T1,int& Nt1,double& alpha1)
	{
		L=L1;Nx=Nx1;T=T1;Nt=Nt1;alpha=alpha1;
		niu=(alpha*T/Nt)/(pow(L/Nx,2));
		mDiag = new double[Nx];
		mUpper = new double[Nx-1];
		mLower = new double[Nx-1];
		for (int i=1; i <=Nx;i++){
			
			mDiag[i]=1-2*niu;
			mUpper[i-1]=niu;
			mLower[i-1]=niu;
		}

		mDiag[0]=1;   //Setting end point conditions
		u.resize(Nx);
		generate(u.begin(),u.end(),numbers);
//		for_each(u0.begin(),u0.end(),print);
	}
	~trimatrix()
	{
		delete [] mDiag;
		delete [] mUpper;
		delete [] mLower;
	}
	void display_matrix()
	{
		for (int i=0;i <Nx;++i){
			for(int j=0;j<Nx;j++){
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
			
		std::cout<<"\n";
		std::cout<<"\n";
	}
	void set_boundary_conditions()
	{
		double k;
		for (double i=0;i<=Nx;i++)
		{

			k=i*L/(double)Nx;
			std::cout<<k<<"\n";
			u0.push_back(k*(1-k));
		}
	}
	void display_vector(std::vector<double> uk)
	{
		for_each(uk.begin(),uk.end(),print);
		std::cout<<"\n";
	}
	void calculate()
	{
		double sum=0;
		for (int i=0;i<Nx;i++){
			sum=0;
			for(int j=0;j<Nx;j++){
				if(i==0){
					sum=sum+mDiag[i]*u0[i];
				}
				else if(j==i-1){
					sum=sum+mLower[j]*u0[i-1];
				}
					
				else if(j==i){
					sum=sum+mDiag[i]*u0[i];
				}
				else if(j==i+1){
					sum=sum+mUpper[j]*u0[i+1];
				}
			u[i]=sum;
			}
		
		}
		u0=u;
	}
	void full_calculation()
	{
		for (double i=0;i<=T;i+=T/(double)Nt){
			calculate();
		}
	}

};
