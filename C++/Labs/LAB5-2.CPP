#include<stdlib.h>
#include<conio.h>
#include<iostream.h>

class Complex
{
	private:
		float real,imag;
	public:
		Complex();

		Complex(float r);

		Complex(float r , float i);

		~Complex();

		void SetReal(float r);

		void SetImag(float i);

		float GetReal();

		float GetImag();

		void SetComplex(float x);

		void SetComplex(float r , float i);

		void PrintComplex();



};

Complex::Complex()
{
	real=imag=0;
	cout<<"Defult Constructor"<<endl;
}

Complex::Complex(float r)
{
	real=imag=r;
	cout<<"Constructor takes 1 value"<<endl;
}

Complex::Complex(float r , float i)
{
	real=r;
	imag=i;
	cout<<"Constructor takes 2 values"<<endl;
}

Complex::~Complex()
{
	cout<<"Destructor"<<endl;
}

void Complex::SetReal(float r)
{
	real=r;
}
void Complex::SetImag(float i)
{
	imag=i;
}
float Complex::GetReal()
{
	return real;
}
float Complex::GetImag()
{
	return imag;
}
void Complex::SetComplex(float x)
{
	real=imag=x;
}

void Complex::SetComplex(float r , float i)
{
	real=r;
	imag=i;
}

void Complex::PrintComplex()
{
	if(imag>0)
		cout<<real<<"+"<<imag<<"i"<<endl;
	else if(imag==0)
		cout<<real<<endl;
	else
		cout<<real<<imag<<"i"<<endl;
}
////////////////Stand alon functions///////////////
Complex Add(Complex c1 , Complex c2)
{
	Complex res;
	res.SetReal((c1.GetReal() + c2.GetReal() ));
	res.SetImag((c1.GetImag() + c2.GetImag() ));

	return res;

}
//Complex x= sub(a,b);
Complex Sub(Complex c1 , Complex c2)
{
	Complex res;
	res.SetReal((c2.GetReal() - c1.GetReal() ));
	res.SetImag((c2.GetImag() - c1.GetImag() ));

	return res;
}

void RAdd(Complex c1 , Complex c2,Complex &res)
{
	res.SetReal((c1.GetReal() + c2.GetReal() ));
	res.SetImag((c1.GetImag() + c2.GetImag() ));

}
void RSub(Complex c1 , Complex c2 ,Complex &res)
{
	res.SetReal((c2.GetReal() - c1.GetReal() ));
	res.SetImag((c2.GetImag() - c1.GetImag() ));
}


void main()
{
	float i , r;
	clrscr();
   //	cout<<"Enter Real num1:" ;
	cin>> r;
   //	cout<<"Enter Imag num1:" ;
	cin>>i;

	Complex c(r,i);
//	c.PrintComplex();

   //	cout<<"Enter Real num2:" ;
	cin>> r;
   //	cout<<"Enter Imag num2:" ;
	cin>>i;

	Complex c2(r,i);

  //	c2.PrintComplex();

	Complex Cres1 , Cres2;

	//cout<<"Sub:"<<endl;

	Cres1=Add(c,Sub(c,c2));
	//cout<<"Sub:"<<endl;

   //	Cres1=Sub(c,c2);
	RSub(c,c2,Cres1);
   //	Cres1.PrintComplex();

	//cout<<"Add:"<<endl;

   //	Cres2=Add(c,c2);
	RAdd(c,c2,Cres2);
	//Cres2.PrintComplex();

	getch();

}
