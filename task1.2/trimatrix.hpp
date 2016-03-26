#include <vector>
#ifndef CLASS_TRIMATRIX
#define CLASS_TRIMATRIX

class trimatrix {
private:
	int Nx;
public:
	double *mDiag;
	double *mUpper;
	double *mLower;

	trimatrix(int &Nx1,double &elem_upper,double &elem_lower,double elem_princ);

	~trimatrix();

	void display_matrix();
	void calculate(std::vector<double> &u0,std::vector<double> &u,
		int &Nx,double &gamma1,double &gamma2);

	void full_calculation(double &T,
		double &delta_t,std::vector<double> &u0,
		std::vector<double> &u,
		int &Nx,double &gamma1,double &gamma2);


};
#endif