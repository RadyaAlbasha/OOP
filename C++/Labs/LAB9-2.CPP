#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

class Shapes
{
	protected:
		int color;
	public:
		Shapes()
		{
			color=1;
		}
		~Shapes()
		{}
		void SetColor(int c)
		{
			color=c;
		}
		int GetColor()
		{
			return color;
		}
};

class Point
{
	private:
		int x,y;
	public:
		Point()
		{
			x=y=0;
		}
		Point(int a)
		{
			x=y=a;
		}
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		~Point()
		{
			cout<<"Point Destructor";
		}
		void SetX(int a)
		{
			x=a;
		}
		void SetY(int b)
		{
			y=b;
		}
		int GetX()
		{
			return x;
		}
		int GetY()
		{
			return y;
		}
		void SetAll(int a,int b)
		{
			x=a;
			y=b;
		}
		Point & operator =(Point &p)
		{
			this->x=p.x;
			this->y=p.y;
			return *this;
		}

};

class Line:public Shapes
{
	private:
		Point start,end;
	public:
		Line():start(0,0),end(0)
		{}
		Line(int x1, int y1, int x2,int y2,int c):start(x1,y1),end(x2,y2)
		{
			color=c;
		}
		Line(Point p1,Point p2):start(p1),end(p2)
		{}
		void SetStart(int x, int y)
		{
			start.SetAll(x,y);
		}
		void SetStart(Point p)
		{
			start=p;
		}
		Point GetStart()
		{
			return start;
		}
		void SetEnd(int x, int y)
		{
			end.SetAll(x,y);
		}
		void SetEnd(Point p)
		{
			end=p;
		}
		Point GetEnd()
		{
			return end;
		}
		void SetAll2(int x1,int y1,int x2,int y2 ,int c)
		{
			start.SetX(x1);
			start.SetY(y1);
			end.SetX(x2);
			end.SetY(y2);
			color=c;
		}
		void Draw()
		{
			setcolor(color);
			line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
		}

		Line& operator =(Line &l)
		{
			this->start=l.start;
			this->end=l.end;
			color=l.color;
			return *this;
		}

};

class Circle:public Shapes
{
	private:
		int radius;
		Point center;
	public:
		Circle():center(),radius(0)
		{}
		Circle(int x ,int y,int r,int c):center(x,y),radius(r)
		{
			color =c;
		}
		Circle(Point p, int r):center(p),radius(r)
		{}
		void SetRad(int r)
		{
			radius = r;
		}
		int GetRad()
		{
			return radius;
		}
		void SetCenter(Point p)
		{
			center = p;
		}
		Point GetCenter()
		{
			return center;
		}
		void SetAll(Point p , int r)
		{
			center=p;
			radius=r;
		}
		void SetAll2(int x,int y,int r,int c)
		{
			center.SetX(x);
			center.SetY(y);
			radius=r;
			color=c;
		}
		void Draw()
		{
			setcolor(color);
			circle(center.GetX(), center.GetY(), radius);
		}
		Circle& operator =(Circle &c)
		{
			this->center=c.center;
			this->radius=c.radius;
			color=c.color;
			return *this;
		}


};

class Arc:public Shapes
{
	private:
		int radius,stangle, endangle;
		Point center;
	public:
		Arc():center(),radius(0), stangle(0), endangle(0)
		{}
		Arc(int x ,int y,int r,int sa,int ea,int c):center(x,y),radius(r),stangle(sa),endangle(ea)
		{
			color=c;
		}
		void SetRad(int r)
		{
			radius = r;
		}
		int GetRad()
		{
			return radius;
		}
		void SetCenter(Point p)
		{
			center = p;
		}
		Point GetCenter()
		{
			return center;
		}
		void SetAll2(int x,int y,int r,int sa,int ea,int c)
		{
			center.SetX(x);
			center.SetY(y);
			radius=r;
			stangle=sa;
			endangle=ea;
			color=c;
		}
		void Draw()
		{
			setcolor(color);
			arc(center.GetX(), center.GetY(), stangle, endangle, radius);
		}
		Arc& operator =(Arc &a)
		{
			this->center=a.center;
			this->radius=a.radius;
			this->stangle=a.stangle;
			this->endangle=a.endangle;
			color=a.color;
			return *this;
		}


};

class Rect:public Shapes
{
	private:
		Point ul , lr;

	public:
		Rect():ul(),lr()
		{}
		Rect(int x1 ,int y1,int x2,int y2,int c):ul(x1,y1),lr(x2,y2)
		{
			color=c;
		}
		Rect(Point p1, Point p2):ul(p1),lr(p2)
		{}
		void SetUL(Point p)
		{
			ul = p;
		}
		Point GetUL()
		{
			return ul;
		}
		void SetLR(Point p)
		{
			lr = p;
		}
		Point GetLR()
		{
			return lr;
		}
		void SetAll2(int x1,int y1,int x2,int y2,int c)
		{
			ul.SetX(x1);
			ul.SetY(y1);
			lr.SetX(x2);
			lr.SetY(y2);
			color=c;
		}
	   /*	void GetRect(Point &rec[4])
		{
			rec[0]=ul;
			rec[1].SetAll(lr.x,ul.y);
			rec[2].SetAll(ul.x,lr.y);
			rec[3]=lr;
		}   */
		void Draw()
		{
			setcolor(color);
			rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
		}
		Rect& operator =(Rect &r)
		{
			this->ul=r.ul;
			this->lr=r.lr;
			color=r.color;
			return *this;
		}




};
class Triangle:public Shapes
{
	private:
		Point a,b,c;
	public:
		Triangle():a(0),b(0),c(0)
		{}
		Triangle(int x1, int y1, int x2,int y2,int x3,int y3,int clr):a(x1,y1),b(x2,y2),c(x3,y3)
		{
			color=clr;
		}
		Triangle(Point p1,Point p2 , Point p3):a(p1),b(p2),c(p3)
		{}
		void SetX3(int x)
		{
			c.SetX(x);
		}
		void SetAll2(int x1,int y1,int x2,int y2,int x3 ,int y3,int clr)
		{
			a.SetX(x1);
			a.SetY(y1);
			b.SetX(x2);
			b.SetY(y2);
			c.SetX(x3);
			c.SetY(y3);
			color=clr;
		}
		void Draw()
		{
			setcolor(color);
			line(a.GetX(),a.GetY(),b.GetX(),b.GetY());
			line(b.GetX(),b.GetY(),c.GetX(),c.GetY());
			line(a.GetX(),a.GetY(),c.GetX(),c.GetY());
		}

		Triangle& operator =(Triangle &t)
		{
			this->a=t.a;
			this->b=t.b;
			this->c=t.c;
			color=t.color;
			return *this;
		}

};


class Pic
{
	private:
		int nl,nc,nr,nt,na;
		Line *pl;
		Circle *pc;
		Rect *pr;
		Triangle *pt;
		Arc *pa;

	public:
		Pic()
		{
			nc=nl=nr=nt=na=0;
			pl=NULL;
			pc=NULL;
			pr=NULL;
			pt=NULL;
			pa=NULL;
		}
		Pic(int c,int r,int l,int t ,int a,Circle *p1,Rect *p2,Line *p3,Triangle *p4, Arc *p5)
		{
			nc=c; nl=l; nr=r; nt=t; na=a;
			pc=p1; pr=p2; pl=p3 ; pt=p4; pa=p5;
		}
		void SetLines(int l,Line *p)
		{
			nl=l;
			pl=p;
		}
		void SetCircles(int c,Circle *p)
		{
			nc=c;
			pc=p;
		}
		void SetRects(int r,Rect *p)
		{
			nr=r;
			pr=p;
		}
		void SetTriangle(int t,Triangle *p)
		{
			nt=t;
			pt=p;
		}
		void SetArc(int a,Arc *p)
		{
			na=a;
			pa=p;
		}
		void Draw()
		{
			int i;

		   //	delay(200);
			for(i=0 ; i<nl;i++)
			{
				pl[i].Draw();
			}
			for(i=0 ; i<nc;i++)
			{
				pc[i].Draw();
			}
			for(i=0 ; i<na;i++)
			{
				pa[i].Draw();
			}
			for(i=0 ; i<nr;i++)
			{
				pr[i].Draw();
			}
			for(i=0 ; i<nt;i++)
			{
				if(i>18 && i<21)
				{
					int xx=375,ch=0;
					while (!kbhit())
					{
						if(xx<=375 &&ch==0 )
						{
							xx--;
							if(xx==370)
								ch=1;
						}
						else if(xx >= 370 && ch==1)
						{
							xx++;
							if(xx==375)
								ch=0;
						}
						pt[19].SetX3(xx);
						pt[20].SetX3(xx);
						pt[19].Draw();
						pt[20].Draw();
						delay(100);
						cleardevice();

						for(i=0 ; i<na;i++)
						{
							pa[i].Draw();
						}
						for(i=0 ; i<nl;i++)
						{
							pl[i].Draw();
						   //	delay(0);
						}
						for(i=0 ; i<nc;i++)
						{
							pc[i].Draw();
						  //	delay(0);
						}
						for(i=0 ; i<nr;i++)
						{
							pr[i].Draw();
						   //	delay(0);
						}
						for(i=0 ; i<nt;i++)
						{
							if(i!=19 && i!=20)
							{

								pt[i].Draw();
							   //	delay(0);

							}
						}
					   //	cleardevice();

					}

				}
				else
					pt[i].Draw();


			}




		}
};

int main()
{

	//clrscr();

	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "..\\BGI");
	cleardevice();
	/* read result of initialization */
	errorcode = graphresult();
	/* an error occurred */
	if (errorcode != grOk)
	{
		 printf("Graphics error: %s\n", grapherrormsg(errorcode));
		 printf("Press any key to halt:");
		 getch();
		 exit(1);
	}


//////

   //	Point ;

	int nc=7,nl=4,nr=2,nt=21,na=11;
   /*	Line *pl=new Line();
	Circle *pc=new Circle();
	Rect *pr=new Rect();*/

	Line pl[4];
	Rect pr[2];
	Circle pc[7];
	Triangle pt[21];
	Arc pa[11];

	Line l(125,377,465,377,13);
	pl[0]=l;
	////////start board   ////////
	Rect r(120,120,470,370,12);
	pr[0]=r;
	r.SetAll2(118,118,472,372,12);
	pr[1]=r;
	////////// end board////////

	//////////start sun///////////////
	Circle c(155,155,16,14);
	pc[0]=c;

	Triangle t(150,135,160,135,155,125,14);
	pt[0]=t;
	t.SetAll2(150,175,160,175,155,185,14);
	pt[1]=t;
	t.SetAll2(135,150,135,160,125,155,14);
	pt[2]=t;
	t.SetAll2(175,150,175,160,185,155,14);
	pt[3]=t;
	t.SetAll2(165,137,173,145,177,133,6);
	pt[4]=t;
	t.SetAll2(165,173,173,165,177,177,6);
	pt[5]=t;
	t.SetAll2(145,137,137,145,133,133,6);
	pt[6]=t;
	t.SetAll2(145,173,137,165,133,177,6);
	pt[7]=t;
	//////////end sun////////////
	/////////////start sea//////////////
	Arc a(140 ,270,20,180,300,3);
	pa[0]=a;
	a.SetAll2(170 ,290,20,50,170,9);
	pa[1]=a;
	a.SetAll2(202,272,20,181,300,3);
	pa[2]=a;
	a.SetAll2(232 ,292,20,50,170,9);
	pa[3]=a;
	a.SetAll2(264,274,20,181,300,3);
	pa[4]=a;
	a.SetAll2(294 ,294,20,50,170,9);
	pa[5]=a;
	a.SetAll2(326,276,20,181,300,3);
	pa[6]=a;
	a.SetAll2(356,296,20,50,170,9);
	pa[7]=a;
	a.SetAll2(388,278,20,181,300,3);
	pa[8]=a;
	a.SetAll2(418,298,20,50,170,9);
	pa[9]=a;
	a.SetAll2(451,280,21,181,330,3);
	pa[10]=a;


	///////////////end sea///////////////
	///////////// start fish////////////
	t.SetAll2(400,320,400,310,390,315,6);
	pt[8]=t;
	t.SetAll2(370,330,370,300,390,315,14);
	pt[9]=t;
	t.SetAll2(370,330,370,300,350,315,6);
	pt[10]=t;
	c.SetAll2(362,312,2,14);
	pc[1]=c;
	l.SetAll2(350,315,355,315,14);
	pl[1]=l;


	t.SetAll2(303,340,303,330,293,335,5);
	pt[11]=t;
	t.SetAll2(273,350,273,320,293,335,3);
	pt[12]=t;
	t.SetAll2(273,350,273,320,253,335,5);
	pt[13]=t;
	c.SetAll2(265,332,2,3);
	pc[2]=c;
	l.SetAll2(253,335,258,335,3);
	pl[2]=l;

	t.SetAll2(230,320,230,310,220,315,4);
	pt[14]=t;
	t.SetAll2(200,330,200,300,220,315,12);
	pt[15]=t;
	t.SetAll2(200,330,200,300,180,315,4);
	pt[16]=t;
	c.SetAll2(192,312,2,12);
	pc[3]=c;
	l.SetAll2(180,315,185,315,12);
	pl[3]=l;


	/////////////end fish//////////////
	///////////////start bird/////////
	c.SetAll2(370,172,10,2);
	pc[4]=c;
	c.SetAll2(355,172,5,2);
	pc[5]=c;
	c.SetAll2(354,170,1,3);
	pc[6]=c;
	t.SetAll2(349,171,349,174,344,173,14);
	pt[17]=t;
	t.SetAll2(390,167,390,177,380,172,10);
	pt[18]=t;
	t.SetAll2(373,161,367,161,375,151,10);
	pt[19]=t;
	t.SetAll2(373,183,367,183,375,193,10);
	pt[20]=t;

	///////////////end bird//////////




	Pic pic(nc,nr,nl,nt,na,pc,pr,pl,pt,pa);
	pic.Draw();

//////
	/* clean up */
	getch();

   //	delete pl;
   //	delete pc;
   //	delete pr;
	closegraph();
	return 0;
}