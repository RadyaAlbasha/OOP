#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

class GeoShape
{
	protected:
		float dim1,dim2;
	public:
		GeoShape()
		{
			dim1=dim2=0;
		}
		GeoShape(float f)
		{
			dim1=dim2=f;
		}
		GeoShape(float f1,float f2)
		{
			dim1=f1;
			dim2=f2;
		}
		~GeoShape()
		{
			cout<<"GeoShape Destructor";
		}
		void SetDim1(float f)
		{
			dim1=f;
		}
		void SetDim2(float f)
		{
			dim2=f;
		}
		float GetDim1()
		{
			return dim1;
		}
		float GetDim2()
		{
			return dim2;
		}
		void SetAll(float f1,float f2)
		{
			dim1=f1;
			dim2=f2;
		}
		virtual float CalcArea()=0;

};

class Rect:public GeoShape
{
	public:
		Rect():GeoShape(0,0)
		{}
		Rect(float w ,float h):GeoShape(w,h)
		{}
		~Rect()
		{}
		float CalcArea()
		{
			return dim1*dim2;
		}

};

class Square:protected Rect
{
	public:
		Square():Rect(0,0)
		{}
		Square(float s):Rect(s,s)
		{}
		~Square()
		{}
		float CalcArea()
		{
			return dim1*dim2;
		}
		void SetSide(float s)
		{
			dim1=dim2=s;
		}

};

class Circle:protected GeoShape
{
	public:
		Circle():GeoShape(0,0)
		{}
		Circle(float r):GeoShape(r,r)
		{}
		~Circle()
		{}
		float CalcArea()
		{
			return (3.14*dim1*dim2);
		}
		void SetRad(float r)
		{
			dim1=dim2=r;
		}


};


class Triangle:public GeoShape
{
	public:
		Triangle():GeoShape(0,0)
		{}
		Triangle(float b,float h):GeoShape(b,h)
		{}
		~Triangle()
		{}
		float CalcArea()
		{
			return (0.5*dim1*dim2);
		}

};

float SumAreas(GeoShape * p1,GeoShape * p2,GeoShape * p3)
{
	return p1->CalcArea()+ p2->CalcArea()+ p3->CalcArea();
}



int main()
{

	clrscr();
	//GeoShape g=new GeoShape(); //Cannot create instance of abstract class {ERROR}
	Rect r(5,10);
	Square s(30);
	Circle c(25);
	Triangle t(30,10);
	cout<<s.CalcArea()<<endl;
	cout<<r.CalcArea()<<endl;
	cout<<c.CalcArea()<<endl;
	cout<<t.CalcArea()<<endl;

	cout<<"////////////ptr////////////"<<endl;
	GeoShape *gptr;
	gptr =(GeoShape*)& s;
	cout<<s.CalcArea()<<endl;

	gptr =(GeoShape*)& r;
	cout<<r.CalcArea()<<endl;

	gptr =(GeoShape*)& c;
	cout<<c.CalcArea()<<endl;

	gptr =(GeoShape*)& t;
	cout<<t.CalcArea()<<endl;


	getch();

	return 0;
}