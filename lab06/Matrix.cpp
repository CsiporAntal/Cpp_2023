//
// Created by Toni on 2023. 11. 08..
//

#include "Matrix.h"
#include <iostream>
#include <random>
#include <stdexcept>

// Default constructor
Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    mElements = new double*[mRows];
    for(int i = 0; i < mRows; ++i)
        mElements[i] = new double[mCols];
}

// Copy constructor
Matrix::Matrix(const Matrix& what) : mRows(what.mRows), mCols(what.mCols) {
    mElements = new double*[mRows];
    for(int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
        copy(what.mElements[i], what.mElements[i] + mCols, mElements[i]);
    }
}

// Move constructor
Matrix::Matrix(Matrix&& what) : mElements(what.mElements), mRows(what.mRows), mCols(what.mCols) {
    what.mElements = nullptr;
    what.mRows = 0;
    what.mCols = 0;
}

// Destructor
Matrix::~Matrix() {
    for(int i = 0; i < mRows; ++i)
        delete [] mElements[i];
    delete [] mElements;
}

void Matrix::fillMatrix(double value) {
    for(int i = 0; i < mRows; ++i)
        fill(mElements[i], mElements[i] + mCols, value);
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(a, b);

    for(int i = 0; i < mRows; ++i)
        for(int j = 0; j < mCols; ++j)
            mElements[i][j] = dis(gen);
}

void Matrix::printMatrix(ostream& os) const {
    for(int i = 0; i < mRows; ++i) {
        for(int j = 0; j < mCols; ++j)
            os << mElements[i][j] << ' ';
        os << '\n';
    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

//copy& operator =
Matrix & Matrix::operator=(const Matrix& mat) {
    if(this != &mat) {
        for(int i = 0; i < mRows; ++i)
            delete [] mElements[i];
        delete [] mElements;

        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = new double*[mRows];
        for(int i = 0; i < mRows; ++i) {
            mElements[i] = new double[mCols];
            copy(mat.mElements[i], mat.mElements[i] + mCols, mElements[i]);
        }
    }
    return *this;
}

//move operator =
Matrix & Matrix::operator=(Matrix&& mat) {
    if(this != &mat) {
        for(int i = 0; i < mRows; ++i)
            delete [] mElements[i];
        delete [] mElements;

        mElements = mat.mElements;
        mRows = mat.mRows;
        mCols = mat.mCols;
        mat.mElements = nullptr;
        mat.mRows = 0;
        mat.mCols = 0;
    }
    return *this;
}

double* Matrix::operator[] (int index){
    return mElements[index];
}

// Index operator const
double* Matrix::operator[] (int index)const  {
    return mElements[index];
}

// Extractor
istream & operator>>(istream& is, Matrix& mat) {
    for(int i = 0; i < mat.mRows; ++i)
        for(int j = 0; j < mat.mCols; ++j)
            is >> mat.mElements[i][j];
    return is;
}
// Inserter
ostream & operator<<(ostream& os, const Matrix& mat) {
    mat.printMatrix(os);
    return os;
}
// + operator
Matrix operator+(const Matrix& x, const Matrix& y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols)
        throw out_of_range("Matrices must have the same dimensions for addition!");

    Matrix result(x.mRows, x.mCols);
    for(int i = 0; i < x.mRows; ++i)
        for(int j = 0; j < x.mCols; ++j)
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
    return result;
}

// * operator
Matrix operator*(const Matrix& x, const Matrix& y) {
    if(x.mCols != y.mRows)
        throw out_of_range("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication!");

    Matrix result(x.mRows, y.mCols);
    for(int i = 0; i < x.mRows; ++i)
        for(int j = 0; j < y.mCols; ++j)
            for(int k = 0; k < x.mCols; ++k)
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
    return result;
}

