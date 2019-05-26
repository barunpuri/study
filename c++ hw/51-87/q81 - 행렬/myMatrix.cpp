#include <string>
#include "myMatrix.h"

using namespace std;
// Constructor
myMatrix::myMatrix(int nRows, int nCols): rows(nRows), cols(nCols),pData(NULL)
{
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = 0;
}
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols),
pData(NULL)
{
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols),
pData(NULL)
{
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = data[i*cols+j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),
pData(NULL)
{
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
 if (pData != NULL)
 deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :
rows(mat.rows), cols(mat.cols), pData(NULL)
{
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const
{
 return rows;
}
int myMatrix::getCols() const
{
 return cols;
}
int* myMatrix::operator [](int i) const
{
 if((i < 0) || (i >= rows))
 errorMessage("Accessing out-of-bound value of a matrix"); 
 return pData[i];
}
int& myMatrix::operator ()(int i, int j)
{
 if((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
 errorMessage("Accessing out-of-bound value of a matrix");
 return pData[i][j];
}
int myMatrix::operator ()(int i, int j) const
{
 if((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
 errorMessage("Accessing out-of-bound value of a matrix");
 return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
 if ((rows != mat.rows) || (cols != mat.cols))
 {
 errorMessage("cannot add two matrices of different size");
 return myMatrix();
 //return *this;
 }
 myMatrix m(rows, cols);
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 m(i,j) = pData[i][j] + mat.pData[i][j];
 return m;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
 if ((rows != mat.rows) || (cols != mat.cols))
 {
 errorMessage("cannot do subtraction between two matrices of different size");
 return myMatrix();
 //return *this;
 }
 myMatrix m(rows, cols);
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 m(i,j) = pData[i][j] - mat.pData[i][j];
 return m;
}
myMatrix myMatrix::operator *(const myMatrix& mat) const
{
 if (cols != mat.rows)
 {
 errorMessage("cannot do multiplication between the given two matrices");
 return myMatrix();
 //return *this;
 }
 myMatrix m(rows, mat.getCols());
 for(int i=0; i<rows; ++i)
 for(int j=0; j<mat.getCols(); ++j)
 for(int k=0; k<cols; ++k)
 m(i,j) += pData[i][k]*mat.pData[k][j];
 return m;
}
myMatrix myMatrix::operator *(int value) const
{
 return value * (*this);
}
// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
 if(&mat == this)
 return *this;
 else 
 {
 rows = mat.rows;
 cols = mat.cols;
 pData = NULL;
 allocateMemory();
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = mat.pData[i][j];
 return *this;
 }
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
 if ((rows != mat.rows) || (cols != mat.cols))
 errorMessage("cannot add two matrices of different size");
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = pData[i][j] + mat.pData[i][j];
 return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
 if ((rows != mat.rows) || (cols != mat.cols))
 errorMessage("cannot do subtraction between two matrices of different size");
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] = pData[i][j] - mat.pData[i][j];
 return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
 if (cols != mat.rows)
 errorMessage("cannot do multiplication between the given two matrices");
 myMatrix m(rows, mat.getCols());
 for(int i=0; i<rows; ++i)
 for(int j=0; j<mat.getCols(); ++j)
 for(int k=0; k<cols; ++k)
 m(i,j) += pData[i][k]*mat.pData[k][j];
 *this = m;
 return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 pData[i][j] *= value;
 return *this;
}
// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const
{
 if ((rows != mat.rows) || (cols != mat.cols))
 return false;
 else 
 {
 	for(int i=0; i<rows; ++i)
 	for(int j=0; j<cols; ++j)
 	if( pData[i][j] != mat(i,j) )
 		return false;
 	return true;
 }
}
bool myMatrix::operator !=(const myMatrix& mat) const 
{
 return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const // unary minus
{
 myMatrix m(rows, cols);
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 m(i,j) = -pData[i][j];
 return m;
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{
 myMatrix m(cols, rows);
 for(int i=0; i<rows; i++)
 for(int j=0; j<cols; j++)
 m(j,i) = pData[i][j];
 *this = m;
 return *this;
}
// private functions
void myMatrix::allocateMemory()
{
 if (pData != NULL)
 deleteMemory();
 pData = new int * [rows];
 if(pData == NULL)
 errorMessage("Memory allocation error");
 pData[0] = new int [rows*cols];
 if(pData[0] == NULL)
 {
 delete [] pData;
 errorMessage("Memory allocation error");
 }
 for(int i=1; i<rows; i++)
 pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
 delete [] pData[0];
 delete [] pData;
 pData = NULL;
}
void myMatrix::errorMessage(string str) const
{
 cout << "Error: " << str << endl;
 //exit(1);
}


// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
 myMatrix m(mat.rows, mat.cols);
 for(int i=0; i<mat.rows; i++)
 for(int j=0; j<mat.cols; j++)
 m(i,j) = mat.pData[i][j]*value ;
 return m; 
}
ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
 outStream << mat.rows << "*" << mat.cols << endl;
 for(int i=0; i<mat.rows; i++)
 {
 for (int j=0; j<mat.cols; j++)
 outStream << mat[i][j] << " ";
 outStream << endl;
 }
 return outStream;
} 
istream &operator >>(istream &inStream, myMatrix& mat)
{
 mat.deleteMemory();
 inStream >> mat.rows >> mat.cols;
 mat.allocateMemory();
 for(int i=0; i<mat.rows; i++)
 {
 for (int j=0; j<mat.cols; j++)
 inStream >> mat[i][j];
 }
 return inStream;
} 
