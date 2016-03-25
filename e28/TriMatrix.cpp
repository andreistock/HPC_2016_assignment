#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "TriMatrix.h"

// part (a)
TriMatrix::TriMatrix(const unsigned int pSize)
        : mSize(pSize),
          mZero(0.0) {
    if (pSize == 0) {
        cout << "Matrix size must be > 0" << endl;
        throw;  // This causes a C++ "Exception" and is a clean way of saying
                // something went wrong and the program should terminate.
    }
    mDiag  = new double[mSize];
    mLower = new double[mSize - 1];
    mUpper = new double[mSize - 1];
}

TriMatrix::TriMatrix(const TriMatrix& pSrc)
        : mSize(pSrc.mSize),
          mZero(0.0) {
    mDiag  = new double[mSize];
    mLower = new double[mSize - 1];
    mUpper = new double[mSize - 1];
    memcpy(mDiag,  pSrc.mDiag,  sizeof(double) * mSize);
    memcpy(mLower, pSrc.mLower, sizeof(double) * (mSize - 1));
    memcpy(mUpper, pSrc.mUpper, sizeof(double) * (mSize - 1));
}

TriMatrix::~TriMatrix() {
    delete[] mDiag;
    delete[] mLower;
    delete[] mUpper;
}

// part (b)
TriMatrix& TriMatrix::operator=(const TriMatrix& pSrc) {
    // If the assignment is between different sized matrices, we need to
    // reallocate our memory to change size.
    if (mSize != pSrc.mSize) {
        mSize = pSrc.mSize;
        delete[] mDiag;
        delete[] mLower;
        delete[] mUpper;
        mDiag  = new double[mSize];
        mLower = new double[mSize - 1];
        mUpper = new double[mSize - 1];
    }

    // Now copy the data from the RHS into this object
    memcpy(mDiag,  pSrc.mDiag,  sizeof(double) * mSize);
    memcpy(mLower, pSrc.mLower, sizeof(double) * (mSize - 1));
    memcpy(mUpper, pSrc.mUpper, sizeof(double) * (mSize - 1));
    return *this;
}

double& TriMatrix::operator() (unsigned int pRow, unsigned int pCol) {
    // We just check we are not outside the bounds of the full matrix
    if (pRow >= mSize || pCol >= mSize) {
        cout << "Index out of range." << endl;
        throw;
    }
    // else if (...) {
    // ...
    // TODO: insert suitable logic here to return the correct value if i,j
    // lie on one of the three diagonals
    // ...
    // }
    else {
        // Why could we not just do 'return 0;' here?
        //
        // Think about what it means to pass by reference...
        //
        // Since we return by reference (to allow users to assign values to
        // the matrix through this function, e.g. A(1,2) = 1.0), we need to
        // return an actual member variable here. A local variable would
        // disappear when this function returns and we cannot just return the
        // value zero by reference.
        //
        // This trick just uses a separate member variable called 'mZero', to
        // circumvent this restriction. We assign it with '0' immediately before
        // we return, in case the user had previously 'assigned' a different
        // value to mZero through this function.
        //
        mZero = 0.0;
        return mZero;
    }
}

TriMatrix TriMatrix::operator+(const TriMatrix& pSrc) {
    if (mSize != pSrc.mSize) {
        cout << "Matrices are of different sizes." << endl;
        throw;
    }
    TriMatrix result(*this);
    result += pSrc; // We reuse the combined-assignment operators below
                    // to reuse the code. We could also explicitly sum the
                    // matrices here.
    return result;
}

TriMatrix TriMatrix::operator-(const TriMatrix& pSrc) {
    if (mSize != pSrc.mSize) {
        cout << "Matrices are of different sizes." << endl;
        throw;
    }
    TriMatrix result(*this);
    result -= pSrc;
    return result;
}

TriMatrix TriMatrix::operator*(const double& pVal) {
    TriMatrix result(*this);
    result *= pVal;
    return result;
}

TriMatrix TriMatrix::operator/(const double& pVal) {
    TriMatrix result(*this);
    result *= 1.0/pVal;
    return result;
}


// The combined-assignment operators are just added for convenience to allow
// us to do: A += L, where A and L are TriMatrix objects of the same size.
TriMatrix& TriMatrix::operator+=(const TriMatrix& pSrc) {
    if (mSize != pSrc.mSize) {
        cout << "Matrices are of different sizes." << endl;
        throw;
    }
    // Separate loops to optimise cache line usage and memory pre-fetch
    for (unsigned int i = 0; i < mSize; ++i) {
        mDiag[i] += pSrc.mDiag[i];
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mLower[i] += pSrc.mLower[i];
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mUpper[i] += pSrc.mUpper[i];
    }
    return *this;
}

TriMatrix& TriMatrix::operator-=(const TriMatrix& pSrc) {
    if (mSize != pSrc.mSize) {
        cout << "Matrices are of different sizes." << endl;
        throw;
    }
    for (unsigned int i = 0; i < mSize; ++i) {
        mDiag[i] -= pSrc.mDiag[i];
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mLower[i] -= pSrc.mLower[i];
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mUpper[i] -= pSrc.mUpper[i];
    }
    return *this;
}

TriMatrix& TriMatrix::operator*=(const double& pVal) {
    for (unsigned int i = 0; i < mSize; ++i) {
        mDiag[i] *= pVal;
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mLower[i] *= pVal;
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mUpper[i] *= pVal;
    }
    return *this;
}

TriMatrix& TriMatrix::operator/=(const double& pVal) {
    double vTmp = 1.0/pVal;
    for (unsigned int i = 0; i < mSize; ++i) {
        mDiag[i] *= vTmp;
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mLower[i] *= vTmp;
    }
    for (unsigned int i = 0; i < mSize-1; ++i) {
        mUpper[i] *= vTmp;
    }
    return *this;
}

// part (c)
void TriMatrix::print() {
    for (unsigned int i = 0; i < mSize; ++i) {
        for (unsigned int j = 0; j < mSize; ++j) {
            // Let's just use the () operator to make our life easier
            // since it is not so important that printing is efficient!
            cout << setprecision(3) << setw(5) << this->operator()(i,j);
        }
        cout << endl;
    }
    cout << endl;
}
