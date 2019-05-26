#include "myMatrix.h"
// Constructor
myMatrix::myMatrix(int nRows, int nCols) :rows(1), cols(1), pData(NULL){}

myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols),
pData(NULL)
{
   allocateMemory();
   for (int i = 0; i<rows; i++)
      for (int j = 0; j<cols; j++)
         pData[i][j] = initValue;
}

myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols),
pData(NULL)
{
   allocateMemory();
   for (int i = 0; i<rows; i++)
      for (int j = 0; j<cols; j++)
         pData[i][j] = data[i*cols + j];
}

myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),
pData(NULL)
{
   allocateMemory();
   for (int i = 0; i<rows; i++)
      for (int j = 0; j<cols; j++)
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
   for (int i = 0; i<rows; i++)
      for (int j = 0; j<cols; j++)
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
   if ((i < 0) || (i >= rows))
      errorMessage("Accessing out-of-bound value of a matrix");
   return pData[i];
}

int& myMatrix::operator ()(int i, int j) const
{
   if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
      errorMessage("Accessing out-of-bound value of a matrix");
   return pData[i][j];
}

// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
   if ((rows != mat.rows) || (cols != mat.cols))
      errorMessage("cannot add two matrices of different size");

   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = this->pData[i][j] + mat.pData[i][j];
      }
   }

   myMatrix temp(rows, cols,temp_ele);
   return temp;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
   if ((rows != mat.rows) || (cols != mat.cols))
      errorMessage("cannot do subtraction between two matrices of different size");

   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = this->pData[i][j] - mat.pData[i][j];
      }
   }

   myMatrix temp(rows, cols, temp_ele);
   return temp;
}
myMatrix myMatrix::operator *(const myMatrix& mat) const
{
   if (cols != mat.rows)
      errorMessage("cannot do multiplication between the given two matrices");

   int r = rows;
   int s = cols;
   int t = mat.cols;
   int cnt = 0;
   int temp_ele[101] = { 0, };

   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < t; j++)
      {
         for (int k = 0; k < s; k++)
         {
            temp_ele[cnt] += pData[i][k] * mat.pData[k][j];
         }
         cnt++;
      }
   }
   myMatrix temp(r, t, temp_ele);
   return temp;
}
myMatrix myMatrix::operator *(int value) const
{
   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = pData[i][j] * value;
      }
   }
   myMatrix temp(rows, cols, temp_ele);
   return temp;
}
// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
   if (&mat == this)
      return *this;
   else
   {
      this->rows = mat.rows;
      this->cols = mat.cols;
      int r = mat.rows;
      int c = mat.cols;
      allocateMemory();
      for (int i = 0; i < r; i++)
      {
         for (int j = 0; j < c; j++)
         {
            this->pData[i][j] = mat.pData[i][j];
         }
      }
   }
   return *this;
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
   if ((rows != mat.rows) || (cols != mat.cols))
      errorMessage("cannot add two matrices of different size");

   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = this->pData[i][j] + mat.pData[i][j];
      }
   }

   myMatrix temp(rows, cols, temp_ele);
   this->operator=(temp);
   return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
   if ((rows != mat.rows) || (cols != mat.cols))
      errorMessage("cannot add two matrices of different size");

   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = this->pData[i][j] - mat.pData[i][j];
      }
   }

   myMatrix temp(rows, cols, temp_ele);
   this->operator=(temp);
   return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
   if (cols != mat.rows)
      errorMessage("cannot do multiplication between the given two matrices");

   int r = rows;
   int s = cols;
   int t = mat.cols;
   int temp_ele[101] = { 0, };
   int cnt = 0;

   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < t; j++)
      {
         for (int k = 0; k < s; k++)
         {
            temp_ele[cnt] += pData[i][k] * mat.pData[k][j];
         }
         cnt++;
      }
   }
   myMatrix temp(r, t, temp_ele);
   this->operator=(temp);
   return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         temp_ele[cnt++] = pData[i][j] * value;
      }
   }
   myMatrix temp(rows, cols, temp_ele);
   this->operator=(temp);
   return *this;
}
// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const
{
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         if (pData[i][j] == mat.pData[i][j]) cnt++;
      }
   }
   if ((rows != mat.rows) || (cols != mat.cols))
      return false;
   else if (cnt != rows*cols)
      return false;
   else
      return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
   return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const // unary minus
{
   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
         temp_ele[cnt++] = -1 * pData[i][j];
   }
   myMatrix temp(rows, cols, temp_ele);
   return temp;
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{
   int r = rows;
   int c = cols;
   int temp_ele[101];
   int cnt = 0;
   for (int i = 0; i < c; i++)
   {
      for (int j = 0; j < r; j++)
      {
         temp_ele[cnt++] = pData[j][i];
      }
   }
   myMatrix temp(c, r, temp_ele);
   this->operator=(temp);
   return *this;
}
// private functions
void myMatrix::allocateMemory()
{
   if (pData != NULL)
      deleteMemory();
   pData = new int *[rows];
   if (pData == NULL)
      errorMessage("Memory allocation error");
   pData[0] = new int[rows*cols];
   if (pData[0] == NULL)
   {
      delete[] pData;
      errorMessage("Memory allocation error");
   }
   for (int i = 1; i<rows; i++)
      pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
   delete[] pData[0];
   delete[] pData;
   pData = NULL;
}
void myMatrix::errorMessage(string str) const
{
   cout << "Error: " << str << endl;
   exit(1);
}
// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
   int temp_ele[101];
   int cnt = 0;
   int row = mat.getRows();
   int col = mat.getCols();
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         temp_ele[cnt++] = mat.operator()(i, j) * value;
      }
   }
   myMatrix temp(row, col, temp_ele);
   return temp;
}
ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
   outStream << mat.rows << "*" << mat.cols << endl;
   for (int i = 0; i<mat.rows; i++)
   {
      for (int j = 0; j<mat.cols; j++)
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
   for (int i = 0; i<mat.rows; i++)
   {
      for (int j = 0; j<mat.cols; j++)
         inStream >> mat[i][j];
   }
   return inStream;
}
