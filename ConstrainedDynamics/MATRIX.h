/**
 * This headfile defines the class MATRIX
 * The class MATRIX is designed for a small scale
 * matrix-computing, including LU decomposition, Jacobi method etc.
 *
 * Written by HaoxuanLi, Mathematica School of Shandong University
 * Anyone could use and modify this file freely.
 * 2011/10/20
*/

/**
 * zh-cn
 * 矩阵运算主要包括
 * 数乘 + - x transposition track inverse determinant eigenvalue
 *
 * 特殊矩阵主要有 单位矩阵 对角矩阵 顺序矩阵 带状矩阵 上三角矩阵 下三角矩阵
 * 矩阵的使用过程为：构建，赋值，运算，释放内存
 * 由于先构建简单的小规模矩阵，将采用一维数组保存完整矩阵，并且通过重载小括号来引用元素
 * 如果要扩展，可以考虑十字链表等储存办法
 * 运算符的重载一般需要使用友元函数
*/

/**
class MATRIX

memebers:
	matrix[][];
	row;
	column;
	type;'I','D','P','B','U','L'

functions:
	Constructor
	Destructor
	Copy Constructor

	det(determinant)
	trans(transposition)
	trace(trace)
	inv(inverse)

operator overload:
	+
	-
	*
	/ (Matrix/k only)
	=
	() (Matrix(i,j))

Notes:
zh-cn
运算符对于与实数结合的情况如下处理
设 MATRIX M;int k;
M+k 在每一个元素上 +k
M-k 在每一个元素上 -k
M/k 在每一个元素上 /k
M*k 在每一个元素上 *k
*/

/**
 * zh-cn
 * 枚举常量代表特殊矩阵类型
 * I 单位矩阵
 * D 对角矩阵
 * P 顺序矩阵
 * B 带状矩阵
 * U 上三角矩阵
 * L 下三角矩阵
 * R 实数
 * N 一般矩阵
 * Z 零矩阵
 * E 无效矩阵
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

class MATRIX
{
	public:
		MATRIX();//default constructor
		//overload constructor
		MATRIX(int m,int n);//constructor
		MATRIX(const MATRIX & A);//copy constructor
		MATRIX(int m,int n,const double * array);//use const array construct
		MATRIX(char t,int n,double val,int pRow=0);//I,D,U,L,P
		MATRIX(char t,int n,string & band);//B
		MATRIX(char t,int n,const char * band);//B
		MATRIX(double k);//k is a real number
		MATRIX(int k);//k is a real number
		~MATRIX();//destructor

		double Det();//determinant
		double Trace();//trace
		double Eig();//eigen value
		double Norm1();//norm p=1
		double Norm2();//norm p=2
		double NormInfinite();//norm p=infinity
		MATRIX Inv();//inverse
		MATRIX Trans();//transposition
		MATRIX Upper();//return upper triangular matrix
		MATRIX UpperI();//return identity upper triangular matrix
		MATRIX Lower();//return lower triangular matrix
		MATRIX LowerI();//return identity lower triangular matrix
		MATRIX Diag();//return the diagonal matrix
		MATRIX SubMatrix(int i,int j,int k,int l);//return submatrix (i:j,k:l)

		//operator overload
		//assume that matrix A is legal
		MATRIX & operator +=(const MATRIX & A);
		MATRIX & operator -=(const MATRIX & A);
		MATRIX & operator *=(const MATRIX & A);
		MATRIX & operator = (const MATRIX & A);
		MATRIX & operator = (const double k);
		MATRIX & operator = (const int k);
		double & operator () (int i,int j)const;
		double & operator () (int i) const;//when MATRIX is a vector
		//this overload supports A("i:j,l:m") method
		MATRIX operator () (const char *range);
		operator double(){return Body[0];};

		//other functions
		void PrintMatrix(int width,int precision=2,bool isfixed=true);//width for setw()
		void Input();//input the elements' value
		void setBody(int i,int j,double val);//set Body[i*row+j]
		int Row() const {return row;}
		int Column() const {return col;}
		char MatrixType() const {return type;}
		void setAll(double val);//set all elements a same value
		void PrintBody();//print all the elements
		void setType(char t);
		//save the matrix to file
		void save(const char * path,int width,int precision=2,bool isfixed=true);

		//convert matrix
		void convertToI();
		void convertToP(int Row1,int Row2);

	private:
		double *Body;//the content of the matrix
		int row;//the row of the matrix
		int col;//the column of the matrix
		char type;//matrix type:I,D,P,B,U,L,E,Z,N,R
};


//operator overload
//all validity will be checked below
MATRIX operator +(const MATRIX & A,const MATRIX & B);
MATRIX operator -(const MATRIX & A,const MATRIX & B);
MATRIX operator *(const MATRIX & A,const MATRIX & B);
MATRIX operator /(const MATRIX & A,const MATRIX & B);
ostream & operator <<(ostream & out,MATRIX & A);


//functions
MATRIX LUDecomposition(const MATRIX & A);
MATRIX Column_PivotLU(const MATRIX & A,MATRIX & P);
MATRIX Cholesky(const MATRIX & A);//Cholesky decomposition
MATRIX SolveL(const MATRIX & L,const MATRIX & b);
MATRIX SolveU(const MATRIX & U,const MATRIX & y);

//Attention: this method has some problem, is there anyone can
//fix it?
MATRIX ImprovedCholesky(const MATRIX & A);
