/**
 * The definition of functions in MATRIX.h
*/

#include "MATRIX.h"

/**
This is the default constructor.
*/
MATRIX::MATRIX()
{
	Body=NULL;
	row=0;
	col=0;
	type='E';
}


/**
This conductor create the default matrix with
the dimension MxN. All the default elements's
value are 0.

Type:N
*/
MATRIX::MATRIX(int m,int n)
{
	if (m<=0 || n<=0){
		cerr<<"Error! m and n must > 0."<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	Body=new double[m*n];

	row=m;
	col=n;

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[col*i+j]=0;
		}
	}

	type='N';
}


/**
This construct use the const array to initialize
the matrix.
e.g.
double a[]={1,2,3,4,5,6,7,8,9};
MATRIX A(3,3,a);

then A:
|1 2 3|
|4 5 6|
|7 8 9|

Note:This constructor has some problem:
if the array's length doesn't match,
the rest of the Body has unpredictable values.
*/
MATRIX::MATRIX(int m,int n,const double * array)
{
	if (m<=0 || n<=0){
		cerr<<"Error! m and n must > 0."<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	Body=new double[m*n];
	row=m;
	col=n;
	type='N';

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]=array[i*col+j];
		}
	}
}

/**
This copy conductor create the same matrix
as the parameter given.
Note: operator "=" will call this function

Type:parameter's type
*/
MATRIX::MATRIX(const MATRIX & A)
{
	Body=new double[A.Row()*A.Column()];
	row=A.Row();
	col=A.Column();
	type=A.MatrixType();

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]=A(i+1,j+1);
		}
	}
}


/**
This conductor create the 1x1 real matrix.

Type:R
*/
MATRIX::MATRIX(int k)
{
	Body=new double;
	*Body=double(k);
	row=1;
	col=1;
	type='R';
}

/**
This conductor create the special matrix including
I(identity matrix), D(diagonal matrix),
U(upper triangular matrix),L(lower triangular matrix).
n for order,val for initial value

Note:if the matrix type is not I,D,U,L
the I will be created.

Type:I,D,U,L

This conductor also create the special matrix: elementary
transformation matrix.
An elementary transformation matrix (marked with P)
is like this:
Matrix P:
|1 0 0 0 0|
|0 0 0 1 0|
|0 0 1 0 0| is a 5x5-dimension elementary transformation matrix,
|0 1 0 0 0|
|0 0 0 0 1|
if A is a 5x5-dimension matrix, then
P*A means exchange the 2nd and 4th row of A
A*P means exchange the 2rd and 4th column of A

Note:for the sake of saving the memory,
assign i to row,k to col.

When using, exchange the row according to
variable row and col in form P*A;
exchange the column according to variable
row and col in form A*P.

Type:P
*/
MATRIX::MATRIX(char t,int n,double val,int pRow)
{
	if (n<=0){
		cerr<<"Error! n must > 0."<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	Body=new double[n*n];
	row=n;
	col=n;
	type='I';

	//initialize as I
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			if (i==j) Body[i*col+j]=1;
			else Body[i*col+j]=0;
		}
	}

	switch (t){
		case 'D'://is an diagonal matrix
			for (int i=0;i<row;i++){
				Body[i*col+i]=val;
			}

			type='D';
			break;
		case 'U'://is an upper triangular matrix
			for (int i=0;i<row;i++){
				for (int j=i+1;j<col;j++){
					Body[col*i+j]=val;
				}
			}

			type='U';
			break;
		case 'L'://is an lower triangular matrix
			for (int i=1;i<row;i++){
				for (int j=0;j<i;j++){
					Body[col*i+j]=val;
				}
			}

			type='L';
			break;
		case 'P'://is an elementary transformation matrix,use val as a row parameter
			//Row1,Row2 is the index of Body, meaning P(2,3)->P[1,2]
			int Row1,Row2;
			Row1=int(val)-1;
			Row2=pRow-1;

			Body[col*Row1+Row1]=0;
			Body[col*Row1+Row2]=1;
			Body[col*Row2+Row2]=0;
			Body[col*Row2+Row1]=1;

			type='P';

			break;
		default:
			break;
	}
}


/**
This conductor create the special matrix: band matrix.
n for order,val for initial value, band is the string-
type variable.
e.g.
Matrix A:
|2 3 0 0 0|
|1 2 3 0 0|
|0 1 2 3 0| is a 5x5-dimension band matrix,
|0 0 1 2 3|
|0 0 0 1 2|
the string variable should be "1,2,3" without any spaces.

Note:if the matrix type is not B the I will be created.

Type:B
*/
MATRIX::MATRIX(char t,int n,string & band)
{
	if (n<=0 || band.length()<=0){
		cerr<<"Error! The band matrix should satisfied:"<<endl
			<<"1.n>0"<<endl
			<<"2.band string.length()>0"<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	Body=new double[n*n];
	row=n;
	col=n;
	type='B';

	//get the number of string
	int counter=0;

	for (int i=0;unsigned(i)<band.length();i++){
		if (band[i]!='-' && band[i]!=' ' && band[i]!=','
			&&(band[i]<'0' || band[i]>'9')){
			counter=-1;
			break;
		}
		if (band[i]==',') counter++;
	}

	//if string is illegal
	if (counter==-1 || (counter+1)%2==0){
		cerr<<"Wrong band array."<<endl
			<<"1.band array must be like this:"<<endl
			<<"\"1,2,3,4,5\""<<endl
			<<"2.the array length must be an odd number"<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	counter++;
	double *array,num=0.0;
	array=new double[counter];
	bool isNagtive=false;

	for (int i=0,j=0;j<counter;i++,j++){
		isNagtive=false;
		num=0.0;
		while (band[i]!=',' && band[i]!=' ' && unsigned(i)<band.length()){
			if (band[i]=='-'){
				isNagtive=true;
				i++;
				continue;
			}

			num*=10.0;
			num+=band[i]-'0';
			i++;
		}

		if (isNagtive) array[j]=-num;
		else array[j]=num;
	}

	int index=(counter+1)/2-1;
	//band index of the first row
	int preZero=0;
	//0s before the band
	int restZero=0;
	//0s after the band

	for (int i=0;i<row;i++){
		int j=0;

		preZero=-index;
		restZero=row-counter-preZero;

		while (preZero>0){
			Body[i*col+j]=0;
			j++;
			preZero--;
		}

		while ((j+index)<counter && j<col){
			Body[i*col+j]=array[index+j];
			j++;
		}

		if (j<col){//has restZero
			while (restZero>0){
				Body[i*col+j]=0;
				j++;
				restZero--;
			}
		}

		index--;
	}

	delete[] array;
}


/**
This conductor is another version of band matrix.
*/
MATRIX::MATRIX(char t,int n,const char * band)
{
	int length=0;

	for (int i=0;band[i]!='\0';i++) length++;

	if (n<=0 || length<=0){
		cerr<<"Error! The band matrix should satisfied:"<<endl
			<<"1.n>0"<<endl
			<<"2.band length>0"<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	Body=new double[n*n];
	row=n;
	col=n;

	//get the number of string
	int counter=0;

	for (int i=0;i<length;i++){
		if (band[i]!='-' && band[i]!=' ' && band[i]!=','
			&&(band[i]<'0' || band[i]>'9')){
			counter=-1;
			break;
		}
		if (band[i]==',') counter++;
	}

	//if string is illegal
	if (counter==-1 || (counter+1)%2==0){
		cerr<<"Wrong band array."<<endl
			<<"1.band array must be like this:"<<endl
			<<"\"1,2,3,4,5\""<<endl
			<<"2.the array length must be an odd number"<<endl;
		Body=NULL;
		row=0;
		col=0;
		type='E';
		return;
	}

	counter++;
	double *array,num=0.0;
	array=new double[counter];
	bool isNagetive=false;

	for (int i=0,j=0;j<counter;i++,j++){
		isNagetive=false;

		num=0.0;
		while (band[i]!=',' && band[i]!=' ' && i<length){
			if (band[i]=='-'){
				isNagetive=true;
				i++;
				continue;
			}

			num*=10.0;
			num+=band[i]-'0';
			i++;
		}

		if (isNagetive) array[j]=-num;
		else array[j]=num;
	}

	int index=(counter+1)/2-1;
	//band index of the first row
	int preZero=0;
	//0s before the band
	int restZero=0;
	//0s after the band

	for (int i=0;i<row;i++){
		int j=0;

		preZero=-index;
		restZero=row-counter-preZero;

		while (preZero>0){
			Body[i*col+j]=0;
			j++;
			preZero--;
		}

		while ((j+index)<counter && j<col){
			Body[i*col+j]=array[index+j];
			j++;
		}

		if (j<col){//has restZero
			while (restZero>0){
				Body[i*col+j]=0;
				j++;
				restZero--;
			}
		}

		index--;
	}

	delete[] array;
}

/**
This conductor acts as the type converter
from double to a 1x1 dimension matrix.
*/
MATRIX::MATRIX(double k)
{
	Body=new double(k);
	row=1;
	col=1;
	type='R';
}

/**
Destructor
*/
MATRIX::~MATRIX()
{
	if (Body!=NULL) delete[] Body;
}

/**
This function is reserved for more studying.
Numerical calculation course will provide
more powerfull method for caculating the
determinant of a matrix.
*/
double MATRIX::Det()
{
	return 0.0;
}

double MATRIX::Trace()
{
	double Trace=0.0;

	if (col==row){
		for (int i=0;i<row;i++){
			Trace+=Body[i*col+i];
		}
	}
	else{
		cerr<<"Matrix is not a square one."<<endl;
	}

	return Trace;
}

/**
Reserved for future extension.
*/
double MATRIX::Eig()
{
	return 0.0;
}

/**
returns norm p=1
*/
double MATRIX::Norm1()
{
	if (Body==NULL){
		cerr<<"Matrix is empty."<<endl;
		return 0;
	}

	double maxInRow=Body[0];

	for (int j=0;j<col;j++){
		double sum=0.0;

		for (int i=0;i<row;i++){
			sum+=Body[i*col+j];
		}

		if (sum>maxInRow) maxInRow=sum;
	}

	return maxInRow;
}

/**
returns norm p=2
*/
double MATRIX::Norm2()
{
	/*for future extension
	if (Body==NULL){
		cerr<<"Matrix is empty."<<endl;
		return 0;
	}

	MATRIX Inverse=this->inv();
	Inverse=Inverse*(*this);

	return sqrt(Inverse->lambda());
	*/
	return 0;
}

/**
returns norm p=infinity
*/
double MATRIX::NormInfinite()
{
	if (Body==NULL){
		cerr<<"Matrix is empty."<<endl;
		return 0;
	}

	double maxInCol=Body[0];

	for (int i=0;i<row;i++){
		double sum=0.0;

		for (int j=0;j<col;j++){
			sum+=Body[i*col+j];
		}

		if (sum>maxInCol) maxInCol=sum;
	}

	return maxInCol;
}


/**
Reserved for future extension.
*/
MATRIX MATRIX::Inv()
{
	if(this->Row() != this->Column()){ // 只可求狭义逆矩阵，即行列数相同                                            
		cout << "Matrix should be N x N\n";                                                           
		exit(0);                                                                                      
	}                                                                                                
	// 构造一个与A行列相同的单位阵B                                                                  
	MATRIX B(this->Row() , this->Column());  
	B.setAll(0);
	for(int r=0; r<this->Row(); r++)                                                                       
		for(int c=0; c<this->Column(); c++)                                                                     
			if(r == c) B.setBody(r,c,1.0);                                                                   

	MATRIX A = *this;
	// 对矩阵A进行A.row次消元运算，每次保证第K列只有对角线上非零                                     
	// 同时以同样的操作施与矩阵B，结果A变为单位阵B为所求逆阵                                         
	for(int k=0; k<A.Row(); k++){                                                                      
		//------------------ 选主元 --------------------------------------                               
		double max = fabs(A(k+1, k+1));   // 主元初始默认为右下方矩阵首个元素                             
		int    ind = k;       // 主元行号默认为右下方矩阵首行                                 
		// 结果第ind行为列主元行                                                                       
		for(int n=k+1; n<A.Row(); n++){                                                             
			if(fabs(A(n+1,k+1)) > max){   // 遇到绝对值更大的元素                                     
				max = fabs(A(n+1,k+1));   // 更新主元值                                               
				ind = n;      // 更新主元行号                                             
			}                                                                                            
		}                                                                                              
		//------------------- 移动主元行 --------------------------------                              
		if(ind != k){       // 主元行不是右下方矩阵首行                                    
			for(int m=k; m<A.Row(); m++){   // 将主元行与右下方矩阵首行互换                                
				double tempa = A(k+1,m+1);                                                                 
				A.setBody(k, m, A(ind+1,m+1));                                                                 
				A.setBody(ind, m, tempa);                                                                      
			}                                                                                            
			for(int m=0; m<B.Row(); m++){                                                                      
				double tempb = B(k+1,m+1);  // 对矩阵B施以相同操作                                         
				B.setBody(k, m, B(ind+1,m+1));  // B与A阶数相同，可在一个循环中                              
				B.setBody(ind, m, tempb);                                                                      
			}                                                                                            
		}                                                                                              
		//--------------------- 消元 -----------------------------------                               
		// 第k次消元操作，以第k行作为主元行，将其上下各行的第k列元素化为零                             
		// 同时以同样的参数对B施以同样的操作，此时可以将B看作A矩阵的一部分                             
		for(int i=0; i<A.Column(); i++){                                                                  
			if(i != k){                                                                                
				double Mik = -A(i+1,k+1)/A(k+1,k+1);                                                     
				for(int j=k+1; j<A.Row(); j++)                                                             
					A.setBody(i, j, A(i+1,j+1) + Mik*A(k+1,j+1));                                              
				for(int j=0; j<B.Row(); j++)                                                                   
					B.setBody(i, j, B(i+1,j+1) + Mik*B(k+1,j+1));                                              
			}//end if                                                                                  
		}//loop i                                                                                    

		double Mkk = 1.0/A(k+1,k+1);                                                                 
		for(int j=0; j<A.Row(); j++)                                                                   
			A.setBody(k, j, A(k+1,j+1) * Mkk);                                                             
		for(int j=0; j<B.Row(); j++)                                                                       
			B.setBody(k, j, B(k+1,j+1) * Mkk);                                                             
	}//loop k                                                                                        
	return B;

}


/**
This function is designed for calculate
transposition of matrix A.

e.g.
|1 2 3|
|4 5 6| is matrix A
|7 8 9|

A.trns is
|1 4 7|
|2 5 8|
|3 6 9|

Use a new array to save the original array by column.
*/
MATRIX MATRIX::Trans()
{/*
	double *array=NULL;

	array=new double[row*col];

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			array[j*row+i]=Body[i*col+j];
		}
	}

	for (int i=0;i<row*col;i++){
		Body[i]=array[i];
	}

	int swapInt=0;
	swapInt=row;
	row=col;
	col=swapInt;

	delete[] array;

	return *this;
*/

	MATRIX B(this->Column(),this->Row());

	for (int i=0;i<B.Row();i++){
		for (int j=0;j<B.Column();j++){
			B(i+1,j+1)=Body[j*col+i];
		}
	}

	return B;
}

MATRIX MATRIX::Scale(double s){
	MATRIX B(this->Row(),this->Column());
	for (int i=0;i<B.Row();i++){
		for (int j=0;j<B.Column();j++){
			B.setBody(i, j, Body[i*col+j] * s);
		}
	}

	return B;
}

/**
This function returns the upper part of
the matrix.
*/
MATRIX MATRIX::Upper()
{
	if (row!=col){
		cerr<<"Matrix is not a square matrix."<<endl;
		return *this;
	}

	MATRIX ret(row,col);

	for (int i=0;i<row;i++){
		for (int j=i;j<col;j++){
			ret(i+1,j+1)=Body[i*col+j];
		}
	}

	ret.setType('U');

	return ret;
}


/**
This function returns the Unit Upper matrix
*/
MATRIX MATRIX::UpperI()
{
	if (row!=col){
		cerr<<"Matrix is not a square matrix."<<endl;
		return *this;
	}

	MATRIX ret(row,col);

	for (int i=0;i<row;i++){
		ret(i+1,i+1)=1;
		for (int j=i+1;j<col;j++){
			ret(i+1,j+1)=Body[i*col+j];
		}
	}

	ret.setType('U');

	return ret;
}

/**
This function returns the lower part of
the matrix.
*/
MATRIX MATRIX::Lower()
{
	if (row!=col){
		cerr<<"Matrix is not a square matrix."<<endl;
		return *this;
	}

	MATRIX ret(row,col);

	for (int i=0;i<row;i++){
		for (int j=0;j<=i;j++){
			ret(i+1,j+1)=Body[i*col+j];
		}
	}

	ret.setType('L');

	return ret;
}

/**
This function returns the Unit Lower matrix
*/
MATRIX MATRIX::LowerI()
{
	if (row!=col){
		cerr<<"Matrix is not a square matrix."<<endl;
		return *this;
	}

	MATRIX ret(row,col);

	for (int i=0;i<row;i++){
		ret(i+1,i+1)=1;
		for (int j=0;j<i;j++){
			ret(i+1,j+1)=Body[i*col+j];
		}
	}

	ret.setType('L');

	return ret;
}

/**
This function returns the diagonal the matrix.
*/
MATRIX MATRIX::Diag()
{
	if (this->Row()!=this->Column()){
		cerr<<"Error! Matrix must be a square matrix."<<endl;
		return *this;
	}

	MATRIX ret(this->Row(),this->Column());

	for (int i=0;i<ret.Row();i++){
		ret(i+1,i+1)=Body[i*col+i];
	}

	return ret;
}

/**
This function returns the submatrix
like A(i:j,k:l)
*/
MATRIX MATRIX::SubMatrix(int i,int j,int k,int l)
{
	if (i<1 || j<1 || k<1 || l<1){
		cerr<<"Wrong reference of the matirx."<<endl;
	}

	if (i>j || k>l || i>row || j>row || k>col || l>col){
		cerr<<"Wrong reference of the matirx."<<endl;
	}

	MATRIX B(j-i+1,l-k+1);

	for (int ii=i;ii<j;ii++){
		for (int jj=k;jj<l;jj++){
			B(ii+1,jj+1)=Body[ii*col+jj];
		}
	}

	return B;
}

/**
+= is overloaded for A+B
assume that A and *this is legal,
which means both A and *this has the
same dimension
*/
MATRIX & MATRIX::operator +=(const MATRIX & A)
{
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]+=A(i+1,j+1);
		}
	}

	return *this;
}

/**
The same as += operator
*/
MATRIX & MATRIX::operator -=(const MATRIX & A)
{
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]-=A(i+1,j+1);
		}
	}

	return *this;
}


/**
*= is calculated as the conception of
matrix multiplication.
The product is made from tmpMatrix
and A, saved in *this.
*/
MATRIX & MATRIX::operator *=(const MATRIX & A)
{
	MATRIX tmpMatrix(*this);
	//tmpMatrix is used for
	//temporary save the product

	//product may have the different dimension
	if (Body){
		delete[] Body;
	}
	Body=new double[this->Row()*A.Column()];


	row=this->Row();
	col=A.Column();
	type=A.MatrixType();

	double sum=0.0;

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			sum=0.0;

			//k is the row number of A
			for (int k=0;k<A.Row();k++){
				if (A(k+1,j+1)==0 || tmpMatrix(i+1,k+1)==0){
					continue;
				}
				else{
					sum+=tmpMatrix(i+1,k+1)*A(k+1,j+1);
				}
			}

			Body[i*col+j]=sum;
		}
	}

	return *this;
}

/**
= operator is overloaded for "Matrix=" form.
*/

MATRIX & MATRIX::operator = (const MATRIX & A)
{
	if (Body){//a new defined matrix should clean the older Body
		delete[] Body;
	}

	Body=new double[A.Row()*A.Column()];
	row=A.Row();
	col=A.Column();
	type=A.MatrixType();

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]=A(i+1,j+1);
		}
	}

	return *this;
}

MATRIX & MATRIX::operator = (const double k)
{
	if (Body){//a new defined matrix should clean the older Body
		delete[] Body;
	}

	Body=new double(k);
	row=1;
	col=1;
	type='R';

	return *this;
}

MATRIX & MATRIX::operator = (const int k)
{
	if (Body){//a new defined matrix should clean the older Body
		delete[] Body;
	}

	Body=new double;
	*Body=double(k);
	row=1;
	col=1;
	type='R';

	return *this;
}

/**
This function refers A(i,j)
while i,j is not the index of Body.
*/
double & MATRIX::operator () (int i,int j) const
{
	if (Body==NULL){
		cerr<<"Matrix is empty!"<<endl;
		return *Body;
	}

	if (i<1 || j<1 || i>row || j>col){
		cerr<<"i or j is beyond the dimension."<<endl;
		cerr<<"i="<<i<<",j="<<j<<endl;
		return *Body;
	}

	return *(Body+col*(i-1)+j-1);
}

/**
This operator overload supports the
usage A("i:j,k:l"). And returns a new
matrix.
*/
MATRIX MATRIX::operator () (const char *range)
{
	int ij[4]={0,0,0,0};
	//ij[0]rowStart
	//ij[1]rowEnd
	//ij[2]colStart
	//ij[3]colEnd

	int len=sizeof(range),count=0;
	//count==1 rowStart
	//count==2 rowEnd
	//count==3 colStart
	//count==4 colEnd

	//get rowStart...colEnd
	for (int i=0;i<len;i++){
		if (range[i]==':' || range[i]==','){
			count++;
		}

		if (range[i]>='0' && range[i]<='9'){
			ij[count]*=10;
			ij[count]+=range[i]-'0';
		}
	}

	if (ij[0]==0) ij[0]=1;
	if (ij[1]==0) ij[1]=row;
	if (ij[2]==0) ij[2]=1;
	if (ij[3]==0) ij[3]=col;

	for (int i=0;i<4;i++){
		if (ij[i]<1){
			cerr<<"Wrong reference of the matirx."<<endl;
		}
	}

	if (ij[0]>ij[1] || ij[2]>ij[3] || ij[0]>row || ij[1]>row ||
		ij[2]>col || ij[3]>col){
		cerr<<"Wrong reference of the matirx."<<endl;
	}

	MATRIX B(ij[1]-ij[0]+1,ij[3]-ij[2]+1);

	for (int i=ij[0]-1;i<ij[1];i++){
		for (int j=ij[2]-1;j<ij[3];j++){
			B(i+1,j+1)=Body[i*col+j];
		}
	}

	return B;
}


/**
This function returns the reference of Body[i-1]
*/
double & MATRIX::operator () (int i) const
{
	if (Body==NULL){
		cerr<<"Matrix is empty!"<<endl;
		return *Body;
	}

	if (row>1 && col>1){
		cerr<<"Matrix is not a vector."<<endl;
		return *Body;
	}

	if (row==1 && i>col){
		cerr<<"Index i is beyond the dimension."<<endl;
		return *Body;
	}

	if (col==1 && i>row){
		cerr<<"Index i is beyond the dimension."<<endl;
		return *Body;
	}

	return *(Body+i-1);
}

/**
Print the Matrix
*/
void MATRIX::PrintMatrix(int width,int precision,bool isfixed)
{
	if (width<=1) width=2;

	if (isfixed){
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				/*qDebug()<<setw(width)
					<<fixed
					<<setprecision(precision)
					<<Body[i*col+j]<<' ';*/
				qDebug()<<Body[i*col+j]<<' ';
			}
			qDebug()<<endl;
		}
	}else{
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
			/*	qDebug()<<setw(width)
					<<setprecision(precision)
					<<Body[i*col+j]<<' ';
			*/
				qDebug()<<Body[i*col+j]<<' ';
			}
			qDebug()<<endl;
		}
	}
}


/**
This function allows you to set val at Body[i*row+j]
*/
void MATRIX::setBody(int i,int j,double val)
{
	Body[col*i+j]=val;
}


/**
This function is designed for inputting every element.
*/
void MATRIX::Input()
{
	if (Body==NULL){
		cerr<<"Error! Matrix has no-dimension."<<endl;
		return ;
	}

	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			qDebug()<<"Inputting("<<(i+1)<<","<<(j+1)<<"):";
			cin>>Body[col*i+j];
		}
	}
}

/**
This function is designed for set all
elements to the same value.
*/
void MATRIX::setAll(double val)
{
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			Body[i*col+j]=val;
		}
	}
}

void MATRIX::PrintBody()
{
	for (int i=0;i<row*col;i++){
		qDebug()<<Body[i]<<"#"<<i<<' ';
	}

	qDebug()<<endl;
}

/**
This function is to set type.
*/
void MATRIX::setType(char t)
{
	if (t<'A' || t>'Z'){
		cerr<<"Matrix type uses upper case letter."<<endl;
		return;
	}

	type=t;
}


/**
When matrix is too large, use this func to save it in the file.
*/
void MATRIX::save(const char * path,int width,int precision,bool isfixed)
{
	if (path==NULL){
		cerr<<"Path is empty."<<endl;
		return;
	}

	fstream fout;

	fout.open(path,fstream::out);

	if (!fout.is_open()){
		cerr<<"File open failed."<<endl;
		return;
	}

	if (width<=1) width=2;

	if (isfixed){
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				fout<<setw(width)
					<<fixed
					<<setprecision(precision)
					<<Body[i*col+j]<<' ';
			}
			fout<<endl;
		}
	}else{
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				fout<<setw(width)
					<<setprecision(precision)
					<<Body[i*col+j]<<' ';
			}
			fout<<endl;
		}
	}

	fout.close();
}


/**
convert matrix to Indenty matrix with the same dimension.
*/
void MATRIX::convertToI()
{
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			if (i==j) Body[i*col+j]=1;
			else Body[i*col+j]=0;
		}
	}

	type='I';
}

/**
convert matrix to order matrix with the same dimension.
*/
void MATRIX::convertToP(int Row1,int Row2)
{
	if (type!='I'){
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				if (i==j) Body[i*col+j]=1;
				else Body[i*col+j]=0;
			}
		}
	}

	Row1--;
	Row2--;

	Body[col*Row1+Row1]=0;
	Body[col*Row1+Row2]=1;
	Body[col*Row2+Row2]=0;
	Body[col*Row2+Row1]=1;

	type='P';
}
