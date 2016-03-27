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
	unsigned int mSize;
	double mZero;
	std::vector<double> u,u0;
	trimatrix(int &Nx1,double &elem_upper,double &elem_lower,double elem_princ);
	trimatrix(const trimatrix &pSrc);
	~trimatrix();

	void set_boundary_conditions(std::vector<double> &u0,double &L,int &Nx);
	void display_matrix();
	void display_vector(std::vector<double> &uk);
	void calculate(double &gamma1,double &gamma2);

	void full_calculation(double &T,
		double &delta_t,double &gamma1,double &gamma2);

    trimatrix& operator=  (const trimatrix &pSrc);
	trimatrix operator/  (const trimatrix &mult);


};
#endif