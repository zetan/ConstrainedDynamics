/**
 * This file includes functions based on
 * the class MATRIX.
*/

#include "MATRIX.h"

/**
These are non-member operator overload functions.
All illegal usage should be warnned here.
*/
MATRIX operator +(const MATRIX & A,const MATRIX & B)
{
	if (A.MatrixType()=='R' && B.MatrixType()=='R'){
		//Both A and B are real numbers

		MATRIX ret(A);

		ret.setBody(0,0,A(1,1)+B(1,1));

		return ret;
	}
	else if (A.MatrixType()=='R' && B.MatrixType()!='R'){
		//A is a real number
		//B is a matrix

		MATRIX ret(B);//copy B

		for (int i=0;i<B.Row();i++){
			for (int j=0;j<B.Column();j++){
				ret.setBody(i,j,B(i+1,j+1)+A(1,1));
			}
		}

		return ret;
	}
	else if (A.MatrixType()!='R' && B.MatrixType()=='R'){
		//A is matrix
		//B is a real number

		MATRIX ret(A);//copy A

		for (int i=0;i<A.Row();i++){
			for (int j=0;j<A.Column();j++){
				ret.setBody(i,j,A(i+1,j+1)+B(1,1));
			}
		}

		return ret;
	}
	else{
	//Matrix + Matrix

		if (A.Row()!=B.Row() || A.Column()!=B.Column()){
			//dimensions are not match

			cerr<<"Error! Two matrixes must have the same dimension."<<endl;

			return A;
		}
		//finally is ret+=B;
		MATRIX ret(A);//copy A
		ret+=B;//use the += operator overload

		return ret;
	}
}

MATRIX operator -(const MATRIX & A,const MATRIX & B)
{
	if (A.MatrixType()=='R' && B.MatrixType()=='R'){
		//Both A and B are real numbers

		MATRIX ret(A);

		ret.setBody(0,0,A(1,1)-B(1,1));

		return ret;
	}
	else if (A.MatrixType()=='R' && B.MatrixType()!='R'){
		//A is a real number
		//B is a matrix

		MATRIX ret(B);//copy B

		for (int i=0;i<B.Row();i++){
			for (int j=0;j<B.Column();j++){
				ret.setBody(i,j,A(1,1)-B(i+1,j+1));
			}
		}

		return ret;
	}
	else if (A.MatrixType()!='R' && B.MatrixType()=='R'){
		//A is matrix
		//B is a real number

		MATRIX ret(A);//copy A

		for (int i=0;i<A.Row();i++){
			for (int j=0;j<A.Column();j++){
				ret.setBody(i,j,A(i+1,j+1)-B(1,1));
			}
		}

		return ret;
	}
	else{
	//Matrix - Matrix

		if (A.Row()!=B.Row() || A.Column()!=B.Column()){
			//dimensions are not match

			cerr<<"Error! Two matrixes must have the same dimension."<<endl;

			return A;
		}
		//finally is ret-=B;
		MATRIX ret(A);//copy A
		ret-=B;//use the -= operator overload

		return ret;
	}
}

MATRIX operator *(const MATRIX & A,const MATRIX & B)
{
	if (A.MatrixType()=='R' && B.MatrixType()=='R'){
		//Both A and B are real numbers

		MATRIX ret(A);

		ret.setBody(0,0,A(1,1)*B(1,1));

		return ret;
	}
	else if (A.MatrixType()=='R' && B.MatrixType()!='R'){
		//A is a real number
		//B is a matrix

		MATRIX ret(B);//copy B

		for (int i=0;i<B.Row();i++){
			for (int j=0;j<B.Column();j++){
				ret.setBody(i,j,A(1,1)*B(i+1,j+1));
			}
		}

		return ret;
	}
	else if (A.MatrixType()!='R' && B.MatrixType()=='R'){
		//A is matrix
		//B is a real number

		MATRIX ret(A);//copy A

		for (int i=0;i<A.Row();i++){
			for (int j=0;j<A.Column();j++){
				ret.setBody(i,j,A(i+1,j+1)*B(1,1));
			}
		}

		return ret;
	}
	else{
	//Matrix * Matrix

		if (A.Column()!=B.Row()){
			//dimensions are not match

			cerr<<"Error! Matrix A's column and matrix B's row must be equal."
				<<endl;

			return A;
		}
		//finally is ret*=B;
		MATRIX ret(A);//copy A
		ret*=B;//use the *= operator overload

		return ret;
	}
}

MATRIX operator /(const MATRIX & A,const MATRIX & B)
{
	if (B.MatrixType()=='R' && B(1,1)==0){
		cerr<<"Error! Divider can not be 0."<<endl;
		return A;
	}

	if (A.MatrixType()=='R' && B.MatrixType()=='R'){
		MATRIX ret(A);
		ret.setBody(0,0,A(1,1)/B(1,1));

		return ret;
	}
	else if (A.MatrixType()!='R' && B.MatrixType()=='R'){
		MATRIX ret(A);

		for (int i=0;i<ret.Row();i++){
			for (int j=0;j<ret.Column();j++){
				ret.setBody(i,j,A(i+1,j+1)/B(1,1));
			}
		}

		return ret;
	}else{
		//Both A and B are matrix
		//but A/B has no definition
		cerr<<"Matrix A/B has no definition."<<endl;
		return A;
	}
}

ostream & operator <<(ostream & out,MATRIX & A)
{
	for (int i=0;i<A.Row();i++){
		for (int j=0;j<A.Column();j++){
			out<<A(i+1,j+1)<<' ';
		}
		out<<endl;
	}

	return out;
}


/**
This LU Decomposition doesn't contain the pivot
rule.
*/
MATRIX LUDecomposition(const MATRIX & A)
{
	if (A.Row()!=A.Column()){
		cerr<<"Matrix must be a square matrix."<<endl;
		return A;
	}

	MATRIX B(A);//copy matrix A

	for (int k=1;k<B.Row();k++){
		for (int i=k+1;i<=B.Row();i++){
			B(i,k)=B(i,k)/B(k,k);

			for (int j=k+1;j<=B.Column();j++){
				B(i,j)=B(i,j)-B(i,k)*B(k,j);
			}
		}
	}

	return B;
}


/**
This is another LU decomposition within column-pivot rule.
P records the order, P=Pn-1Pn-2...P1
*/
MATRIX Column_PivotLU(const MATRIX & A,MATRIX & P)
{
	if (A.Row()!=A.Column()){
		cerr<<"Matrix must be a square matrix."<<endl;
		return A;
	}

	int p=0;

	MATRIX B(A);

	P.convertToI();
	MATRIX Pn(B.Row(),B.Column());
	Pn.convertToI();

	for (int k=1;k<B.Row();k++){
		double maxInRow=0.0;
		p=k;

		//seBrch for p
		for (int loop=k;loop<=B.Row();loop++){
			if (B(loop,k)>maxInRow){
				maxInRow=B(loop,k);
				p=loop;//sBve the row of mBx
			}

			if (p!=k){
				Pn.convertToP(p,k);
			}

			P=P*Pn;
		}

		B=Pn*B;

		if (B(k,k)==0){
			//singulBr mBtrix
			return B;
		}

		for (int i=k+1;i<=B.Row();i++){
			B(i,k)=B(i,k)/B(k,k);

			for (int j=k+1;j<=B.Row();j++){
				B(i,j)=B(i,j)-B(i,k)*B(k,j);
			}
		}

	}

	return B;
}

/**
Cholesky decomposition
L*L'=A
this method save the L in return lower triangular B
*/
MATRIX Cholesky(const MATRIX & A)
{
	if (A.Row()!=A.Column()){
		cerr<<"Matrix must be a square matrix."<<endl;
		return A;
	}

	MATRIX B(A);

	for (int k=1;k<=B.Row();k++){
		B(k,k)=sqrt(B(k,k));

		for (int i=k+1;i<=B.Row();i++){
			B(i,k)=B(i,k)/B(k,k);
		}

		for (int j=k+1;j<=B.Row();j++){
			for (int i=j;i<=B.Row();i++){
				B(i,j)=B(i,j)-B(i,k)*B(j,k);
			}
		}
	}

	return B;
}

/**
Improved Cholesky method.
*/
MATRIX ImprovedCholesky(const MATRIX & A)
{
	if (A.Row()!=A.Column()){
		cerr<<"Matrix must be a square matrix."<<endl;
		return A;
	}

	MATRIX B(A);

	int n=B.Row();
	MATRIX v(n-1,1);

	v(1,1)=B(1,1);

	for (int j=1;j<=n;j++){
		for (int i=1;i<j;i++){
			v(i)=B(j,i)*B(i,i);
		}

		B(j,j)=B(j,j)-double(B.SubMatrix(j,j,1,j-1)*v.SubMatrix(1,j-1,1,1));

		for (int i=j+1;i<=n;i++){
			B(i,j)=(B(i,j)-double(B.SubMatrix(i,i,1,j-1)*v.SubMatrix(1,j-1,1,1)))/B(j,j);
		}
	}

	return B;
}

/**
This function is designd for solve the
Ly=b case. Returns y.
*/
MATRIX SolveL(const MATRIX & L,const MATRIX & b)
{
	if (L.Row()!=b.Row()){
		cerr<<"L matrix and b must have the same dimension."<<endl;
		return b;
	}

	MATRIX y(b);

	int n=y.Row();

	for (int j=1;j<n;j++){
		y(j)=y(j)/L(j,j);

		for (int i=j+1;i<=n;i++){
			y(i)=y(i)-y(j)*L(i,j);
		}
	}

	y(n)=y(n)/L(n,n);

	return y;
}

/**
This function is designd for solve the
Ux=y case. Returns x.
*/
MATRIX SolveU(const MATRIX & U,const MATRIX & y)
{
	if (U.Row()!=y.Row()){
		cerr<<"L matrix and b must have the same dimension."<<endl;
		return y;
	}

	MATRIX x(y);

	int n=x.Row();

	for (int j=n;j>1;j--){
		x(j)=x(j)/U(j,j);

		for (int i=1;i<j;i++){
			x(i)=x(i)-x(j)*U(i,j);
		}
	}

	x(1)=x(1)/U(1,1);

	return x;
}
