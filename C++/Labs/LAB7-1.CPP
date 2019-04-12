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

		Complex & operator =(Complex & s);

		int operator ==(Complex & s);
		int operator <(Complex & s);

		Complex operator +(Complex & s);
		Complex operator +(float f);
		Complex & operator +=(Complex &s);

		Complex operator -(Complex & s);
		Complex operator -(float f);
		Complex & operator -=(Complex &s);

		operator float();

		void operator()(float r,float i);

		Complex & operator ++();//prefix
		Complex  operator ++(int dummy);//postfix

		friend Complex operator +(float f,Complex & s);
		friend Complex operator -(float f,Complex & s);

		friend istream & operator >>(istream &in , Complex &c);
		friend ostream & operator <<(ostream &out , Complex &c);



};

Complex::Complex()
{
	real=imag=0;
   //	cout<<"Defult Constructor"<<endl;
}

Complex::Complex(float r)
{
	real=imag=r;
   //	cout<<"Constructor takes 1 value"<<endl;
}

Complex::Complex(float r , float i)
{
	real=r;
	imag=i;
   //	cout<<"Constructor takes 2 values"<<endl;
}

Complex::~Complex()
{
   //	cout<<"Destructor"<<endl;
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
/////////////operators////////////////
Complex & Complex::operator =(Complex & s)
{
   real=s.real;
   imag=s.imag;
   return *this;
}

int Complex::operator ==(Complex & s)
{
	return((real == s.real) && (imag == s.imag));
}
int Complex::operator <(Complex & s)
{
	if(real<s.real)
	{
	  return 1;
	}
	if(imag<s.imag)
	{
		return 1;
	}
	return 0;
}


Complex Complex::operator +(Complex & s)
{
	return Complex(real+s.real , imag+s.imag);
}
Complex Complex::operator +(float f)
{
	Complex temp;
	temp.real = real+f;
	temp.imag = imag;
	return temp;
}
Complex & Complex::operator +=(Complex &s)
{
	real+=s.real;
	imag+=s.imag;
	return *this;
}

Complex Complex::operator -(Complex & s)
{
	return Complex(real-s.real , imag-s.imag);
}
Complex Complex::operator -(float f)
{
	Complex temp;
	temp.real = real-f;
	temp.imag = imag;
	return temp;
}
Complex & Complex::operator -=(Complex &s)
{
	real-=s.real;
	imag-=s.imag;
	return *this;
}

Complex::operator float()
{
	return real;
}

void Complex::operator()(float r,float i)
{
	real=r;
	imag=i;
}

Complex & Complex::operator ++()//prefix
{
	++real;
	++imag;
	return *this;
}
Complex Complex::operator ++(int dummy)//postfix
{
	Complex temp(*this);
	real++;
	imag++;
	return temp;
}

////////////////friends////////////////////
Complex operator +(float f,Complex & s)
{
	return s+f;
}
Complex operator -(float f,Complex & s)
{
	return s-f;
}

istream & operator >>(istream &in , Complex &c)
{
	cout<<"Enter complex data:\nreal=";
	in>>c.real;
	cout<<"imag=";
	in>>c.imag;
	return in;
}
ostream & operator <<(ostream &out , Complex &c)
{
	out<<"\nComplex data is:\n";
	out<<"real="<<c.real;
	out<<"\timag="<<c.imag;
	return out;
}

void main()
{

	clrscr();
	Complex c3,c2,c1;
	float x;
	cin>>c1>>c2;
	c3=c1+c2;
	cout<<"c3=c1+c2 "<<c3<<"\t";

	c3=c1-c2;
	cout<<"c3=c1+c2 "<<c3<<"\t";

	c3=c1+5;
	cout<<"c3=c1+5 "<<c3<<endl;

	c3=5+c1;
	cout<<"c3=5+c1 "<<c3<<"\t";

	c3=c1-5;
	cout<<"c3=c1-5 "<<c3<<"\t";

	c3=5-c1;
	cout<<"c3=5-c1 "<<c3<<endl;

	c1+=c2;
	cout<<"c1+=c2 "<<c1<<"\t";

	c1-=c2;
	cout<<"c1-=c2 "<<c1<<endl;
   /*
	c3=c1++;
	cout<<"c3=c1++"<<c3<<"\t";

	c3=++c1;
	cout<<"c3=++c "<<c3<<endl;

	x=(float) c1;
	cout<<"float c1="<<x<<"\t";

	cout<<"c1<c2="<<(c1<c2)<<endl; */

	getch();
}
