#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
double pi = 3.14159265359;
void distan(double, double, double, double, double&);
void perpendicular(double, double, double, double, double&);
int testing(double, double, double, double&);
void proverka(double, double, double, double, double, double, double&, double, bool&);
void printCircle(double, double, double, bool, int, int, int);
void printTriangle(double, double, double, double, double, double, bool, int, int,int);
void printPoligon(double, double, double, double, double, double, double, double, bool, int, int,int);
void circle_intersects(double,double,double,double,double,double);

int peresech(double, double, double, double, double, double, double, double, bool&);
double getCos(double, double, double, double);
double getYIntercept(double, double, double, double);
bool projectionsIntersect(double, double, double, double);
double getMax(double, double);
double getMin(double, double);
bool areCollinear(double, double, double, double);

int main()
{
	cout << "\t\t\t  |Select two figures|" << endl;
	cout << " ____________________________________________________________________________" << endl;
	cout << "|1.Circle(Press'1')|2.Triangle(Press'2')|3.Polygon(Press'3')|exit(Press'esc')|" << endl;
	cout << "|__________________|____________________|___________________|________________|" << endl;
	double Perimetr1;
	struct Figure {
		double x;
		double y;
		double x1;
		double y1;
		double x2;
		double y2;
		double x3;
		double y3;
		double r;

	};

	Figure circle;
	Figure triangle;
	Figure poligon;
	Figure circle2;
	Figure triangle2;
	Figure poligon2;
	int k = 0, lkl1 = 0, lkl2 = 0, lkl3 = 0, f = 2, f1 = 2, lkl_1 = 0, lkl_2 = 0, lkl_3 = 0;
	bool fact = false, okr = false;

	cin >> f; 
	if(f1<=0||f<=0||f1>3||f>3)
	{
		cout<<"ERROR INPUT DATA"<<endl;
		system("PAUSE");
		return 0;
	}
	cin >> f1;
	if(f1<=0||f<=0||f1>3||f>3)
	{
		cout<<"ERROR INPUT DATA"<<endl;
		system("PAUSE");
		return 0;
	}
	if (f == 1 && f1 == 1)
	{
		
		lkl_1 = 1;
		printf("( x  y , r) "); cin >> circle2.x; cin >> circle2.y; cin >> circle2.r; cout << endl;
		k++;

	}
	if (f == 2 && f1 == 2)
	{
		
		lkl_2 = 2;
		printf("((x1 y1 , x2, y2 , x3 y3)) "); cin >> triangle2.x; cin >> triangle2.y; cin >> triangle2.x1; cin >> triangle2.y1; cin >> triangle2.x2; cin >> triangle2.y2; cout << endl;
		k++;
	}
	if (f == 3 && f1 == 3)
	{
		
		lkl_3 = 3;
		printf("((x1 y1 , x2, y2 , x3 y3 , x4 y4)) "); cin >> poligon2.x; cin >> poligon2.y; cin >> poligon2.x1; cin >> poligon2.y1; cin >> poligon2.x2; cin >> poligon2.y2; cin >> poligon2.x3; cin >> poligon2.y3; cout << endl;
		k++;
	}
	

	if (f == 1 || f1 == 1)
	{
		lkl1 = 1;
		printf("( x  y , r) "); cin >> circle.x; cin >> circle.y; cin >> circle.r; cout << endl;
		k++;
	} 

	if (f == 2 || f1 == 2)
	{

		lkl2 = 2;
		printf("((x1 y1 , x2, y2 , x3 y3)) "); cin >> triangle.x; cin >> triangle.y; cin >> triangle.x1; cin >> triangle.y1; cin >> triangle.x2; cin >> triangle.y2; cout << endl;
		k++;
	}

	if (f == 3 || f1 == 3)
	{
		lkl3 = 3;
		printf("((x1 y1 , x2, y2 , x3 y3 , x4 y4)) "); cin >> poligon.x; cin >> poligon.y; cin >> poligon.x1; cin >> poligon.y1; cin >> poligon.x2; cin >> poligon.y2; cin >> poligon.x3; cin >> poligon.y3; cout << endl;
		k++;
	}
	if (lkl_1 == 1 && lkl1 == 1)
	{
		circle_intersects(circle.x, circle.y, circle.r, circle2.x, circle2.y, circle2.r);
	}
	
	if (lkl_2 == 2 && lkl2 == 2)
	{
		peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle2.x, triangle2.y, triangle2.x1, triangle2.y1, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle2.x1, triangle2.y1, triangle2.x2, triangle2.y2, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle2.x2, triangle2.y2, triangle2.x, triangle2.y, fact);
		if (fact == false)
			
			
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, triangle2.x, triangle2.y, triangle2.x1, triangle2.y1, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, triangle2.x1, triangle2.y1, triangle2.x2, triangle2.y2, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, triangle2.x2, triangle2.y2, triangle2.x, triangle2.y, fact);

		if (fact == false)
			peresech(triangle.x2, triangle.y2, triangle.x, triangle.y, triangle2.x, triangle2.y, triangle2.x1, triangle2.y1, fact);
		if (fact == false)
			peresech(triangle.x2, triangle.y2, triangle.x, triangle.y, triangle2.x1, triangle2.y1, triangle2.x2, triangle2.y2, fact);
		if (fact == false)
			peresech(triangle.x2, triangle.y2, triangle.x, triangle.y, triangle2.x2, triangle2.y2, triangle2.x, triangle2.y, fact);
		
		printTriangle(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle.x2, triangle.y2, fact, 2, 2, 1);
		printTriangle(triangle2.x, triangle2.y, triangle2.x1, triangle2.y1, triangle2.x2, triangle2.y2, fact, 1, 2, 2);

	}
	
	if (lkl_3 == 3 && lkl3 == 3)
	{
		peresech(poligon.x, poligon.y, poligon.x1, poligon.y1, poligon2.x, poligon2.y, poligon2.x1, poligon2.y1, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x1, poligon.y1, poligon2.x1, poligon2.y1, poligon2.x2, poligon2.y2, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x1, poligon.y1, poligon2.x2, poligon2.y2, poligon2.x3, poligon2.y3, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x1, poligon.y1, poligon2.x, poligon2.y, poligon2.x3, poligon2.y3, fact);
		
		
		
		if (fact == false)
			peresech(poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon2.x, poligon2.y, poligon2.x1, poligon2.y1, fact);
		if (fact == false)
			peresech(poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon2.x1, poligon2.y1, poligon2.x2, poligon2.y2, fact);
		if (fact == false)
			peresech(poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon2.x2, poligon2.y2, poligon2.x3, poligon2.y3, fact);
		if (fact == false)
			peresech(poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon2.x, poligon2.y, poligon2.x3, poligon2.y3, fact);

		if (fact == false)
			peresech(poligon.x2, poligon.y2, poligon.x3, poligon.y3, poligon2.x, poligon2.y, poligon2.x1, poligon2.y1, fact);
		if (fact == false)
			peresech(poligon.x2, poligon.y2, poligon.x3, poligon.y3, poligon2.x1, poligon2.y1, poligon2.x2, poligon2.y2, fact);
		if (fact == false)
			peresech(poligon.x2, poligon.y2, poligon.x3, poligon.y3, poligon2.x2, poligon2.y2, poligon2.x3, poligon2.y3, fact);
		if (fact == false)
			peresech(poligon.x2, poligon.y2, poligon.x3, poligon.y3, poligon2.x, poligon2.y, poligon2.x3, poligon2.y3, fact);

		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x3, poligon.y3, poligon2.x, poligon2.y, poligon2.x1, poligon2.y1, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x3, poligon.y3, poligon2.x1, poligon2.y1, poligon2.x2, poligon2.y2, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x3, poligon.y3, poligon2.x2, poligon2.y2, poligon2.x3, poligon2.y3, fact);
		if (fact == false)
			peresech(poligon.x, poligon.y, poligon.x3, poligon.y3, poligon2.x, poligon2.y, poligon2.x3, poligon2.y3, fact);

		printPoligon(poligon.x , poligon.y, poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon.x3, poligon.y3, fact, 2, 3, 1);
		printPoligon(poligon2.x, poligon2.y, poligon2.x1, poligon2.y1, poligon2.x2, poligon2.y2, poligon2.x3, poligon2.y3, fact, 1, 3, 2);

		
	}
	
	if (lkl1 == 1 && lkl2 == 2)
	{
		proverka(circle.x, circle.y, triangle.x, triangle.y, triangle.x1, triangle.y1, Perimetr1, circle.r, okr);
		if (okr != 1)
			proverka(circle.x, circle.y, triangle.x1, triangle.y1, triangle.x2, triangle.y2, Perimetr1, circle.r, okr);
		if (okr != 1)
			proverka(circle.x, circle.y, triangle.x, triangle.y, triangle.x2, triangle.y2, Perimetr1, circle.r, okr);
		printCircle(circle.x, circle.y, circle.r, okr, 2, lkl2,1);
		printTriangle(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle.x2, triangle.y2, okr, 1, lkl1,2);

	}
	if (lkl1 == 1 && lkl3 == 3)
	{
		proverka(circle.x, circle.y, poligon.x, poligon.y, poligon.x1, poligon.y1, Perimetr1, circle.r, okr);
		if (okr != 1)
			proverka(circle.x, circle.y, poligon.x1, poligon.y1, poligon.x2, poligon.y2, Perimetr1, circle.r, okr);
		if (okr != 1)
			proverka(circle.x, circle.y, poligon.x2, poligon.y2, poligon.x3, poligon.y3, Perimetr1, circle.r, okr);
		if (okr != 1)
			proverka(circle.x, circle.y, poligon.x3, poligon.y3, poligon.x, poligon.y, Perimetr1, circle.r, okr);
		printCircle(circle.x, circle.y, circle.r, okr, 2, lkl3,1);
		printPoligon(poligon.x, poligon.y, poligon.x1, poligon.y1, poligon.x2, poligon.y2, poligon.x3, poligon.y3, okr, 1, lkl1,2);

	}
	
	if (lkl3 == 3 && lkl2 == 2)
	{
		peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, poligon.x, poligon.y, poligon.x1, poligon.y1, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, poligon.x1, poligon.y1, poligon.x2, poligon.y2, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, poligon.x2, poligon.y2, poligon.x3, poligon.y3, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x1, triangle.y1, poligon.x, poligon.y, poligon.x3, poligon.y3, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, poligon.x, poligon.y, poligon.x1, poligon.y1, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, poligon.x1, poligon.y1, poligon.x2, poligon.y2, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, poligon.x2, poligon.y2, poligon.x3, poligon.y3, fact);
		if (fact == false)
			peresech(triangle.x1, triangle.y1, triangle.x2, triangle.y2, poligon.x1, poligon.y1, poligon.x2, poligon.y1, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x2, triangle.y2, poligon.x, poligon.y, poligon.x1, poligon.y1, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x2, triangle.y2, poligon.x1, poligon.y1, poligon.x2, poligon.y2, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x2, triangle.y2, poligon.x2, poligon.y2, poligon.x3, poligon.y3, fact);
		if (fact == false)
			peresech(triangle.x, triangle.y, triangle.x2, triangle.y2, poligon.x, poligon.y, poligon.x3, poligon.y3, fact);

		printPoligon(poligon.x,poligon.y,poligon.x1,poligon.y1,poligon.x2,poligon.y2,poligon.x3,poligon.y3,fact,2,lkl2,1);
		printTriangle(triangle.x, triangle.y, triangle.x1, triangle.y1, triangle.x2, triangle.y2, fact, 1, lkl3, 2);

	}
	
	system("PAUSE");
	return 0;
}
void circle_intersects(double x, double y, double r,double x1, double y1,double r1)
{
	bool flag;
	double N;
	N = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	if (x == x1&&y == y1&&r == r1)
	{
		flag = true;
	}
	else if (x == x1&&y == y1 && (r < r1 || r > r1))
	{
		flag = false;
	}
	else
		if (N == (r + r1))
		{
			flag = true;
		}
		else
			if (N <= (r + r1))
			{
				flag = true;
			}
	printCircle(x, y,r,flag, 2, 1, 1);
	printCircle(x1, y1, r1, flag, 1, 1, 2);
}
void proverka(double x0, double y0, double x1, double y1, double x2, double y2, double &Perimetr, double r, bool & okr)
{
	double a, b, c, H, dl, J, Poluper;

	distan(x0, y0, x1, y1, a);
	distan(x0, y0, x2, y2, b);
	distan(x1, y1, x2, y2, c);
	Perimetr = a + b + c;

	Poluper = Perimetr / 2;
	dl = testing(a, b, c, J);
	if (dl == -1)
	{
		perpendicular(a, b, c, Poluper, H);
		dl = H;

	}
	else dl = J;
	if (dl <= r)
	{
		okr = true;
	}
}
void distan(double x, double y, double x1, double y1, double & L)
{
	L = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
}
void perpendicular(double a, double b, double c, double P, double &H)
{
	H = (2 * sqrt(P*(P - a)*(P - b)*(P - c))) / c;
}
int testing(double a, double b, double c, double &J)
{
	int cs;
	cs = (b*b + c * c - (a*a)) / 2 * b*c;
	if (cs < 0) {
		J = b;
		return 1;
	}
	cs = (a*a + c * c - (b*b)) / 2 * a*c;
	if (cs < 0) {
		J = a;
		return 1;
	}
	return -1;
}
void printCircle(double x1, double y1, double r1, bool flag, int k, int lkl,int n)
{
	double p1, s1;
	p1 = pi * r1*r1;
	s1 = 2 * pi*r1;
	cout << n << endl;
	printf("Circle(%.1f %.1f , %.1f)\n", x1, y1, r1);
	printf("perimetr = %.3f\n", p1);
	printf("area = %.3f\n", s1);
	if (flag == true) {
		printf("intersects: \n   ");
		if (lkl == 1)
		{
			cout << k << ". Circle" << endl;

		}
		else
			if (lkl == 2)
			{
				cout << k << ". Triangle" << endl;

			}
			else
				if (lkl == 3)
				{
					cout << k << ". Poligon" << endl;

				}

	}
	else
		printf("intersects: \n   - \n");

}
void printTriangle(double x1, double y1, double x2, double y2, double x3, double y3, bool flag, int k, int lkl,int n)
{
	double s, p, determinant;
	p = sqrt((x2 - x1)*(x2 - x1)) + sqrt((x3 - x1)*(x3 - x1)) + sqrt((x3 - x2)*(x3 - x2));
	determinant = (x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3);

	determinant < 0 ? s = determinant / (-2) : s = determinant / 2;
	cout << n << endl;
	printf("Triangle(%.1f %.1f , %.1f %.1f , %.1f %.1f)\n", x1, y1, x2, y2, x3, y3);
	printf("perimetr = %.3f\n", p);
	printf("area = %.3f\n", s);
	if (flag == 1) {
		printf("intersects: \n   ");
		if (lkl == 1)
		{
			cout << k << ". Circle" << endl;

		}
		else
			if (lkl == 2)
			{
				cout << k << ". Triangle" << endl;


			}
			else
				if (lkl == 3)
				{
					cout << k << ". Poligon" << endl;

				}
	}
	else
		printf("intersects: \n   - \n");
	
}
void printPoligon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, bool flag, int k, int lkl, int n)
{
	double p, s, determinant, s1, s2;
	p = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - x1)) + sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)) + sqrt((x4 - x3)*(x4 - x3) + (y4 - y3)*(y4 - y3)) + sqrt((x1 - x3)*(x1 - x4) + (y1 - y3)*(y1 - y4));
	determinant = (x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3);
	determinant < 0 ? s1 = determinant / (-2) : s1 = determinant / 2;
	determinant = (x4 - x3)*(y2 - y3) - (x2 - y3)*(y1 - y3);
	determinant < 0 ? s2 = determinant / (-2) : s2 = determinant / 2;
	s = s1 + s2;
	cout << n << endl;
	printf("Poligon(%.1f %.1f , %.1f %.1f , %.1f %.1f , %.1f %.1f)\n", x1, y1, x2, y2, x3, y3, x4, y4);
	printf("perimetr = %.3f\n", p);
	printf("area = %.3f\n", s);
	if (flag == 1) {
		printf("intersects: \n   ");
		if (lkl == 1)
		{
			cout << k << ". Circle" << endl;
		}
		else
			if (lkl == 2)
			{
				cout << k << ". Triangle" << endl;

			}
			else
				if (lkl == 3)
				{
					cout << k << ". Poligon" << endl;

				}
	}
	else
		printf("intersects: \n   - \n");

	
}




bool areCollinear(double x1, double y1, double x2, double y2) {
	return x1 / x2 == y1 / y2 ? true : false;// i?iaa?ea ia eieeeiaa?iinou
}

double getMin(double x1, double x2) {
	return x1 < x2 ? x1 : x2;
}

double getMax(double x1, double x2) {
	return x1 > x2 ? x1 : x2;
}

// I?iaa?ea ia ia?ana?aiea i?iaeoee ia ine, iin?aanoaii iaoi?aaiey acaeiiiai ?aniiei?aiey eiioia i?iaeoee
bool projectionsIntersect(double x1, double x2, double x3, double x4) {
	return ((getMin(x1, x2) <= getMin(x3, x4) && getMin(x3, x4) <= getMax(x1, x2)) || ((getMin(x3, x4) <= getMin(x1, x2) && getMin(x1, x2) <= getMax(x3, x4))));
}

// Au?eneaiea eiyooeoeaioa oaea iaeeiia o?aaiaiey i?yiie
double getSlope(double x1, double  y1, double x2, double y2) {
	return (y2 - y1) / (x2 - x1);
}

// Au?eneaiea naiaiaiiai ?eaia o?aaiaiey i?yiie
double getYIntercept(double x1, double  y1, double x2, double y2) {
	return (x2 * y1 - x1 * y2) / (x2 - x1);
}

// Iaoi?aaiea eineiona oaea ia?ao aaeoi?aie
double getCos(double x1, double  y1, double x2, double y2) {
	return (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) + sqrt(x2 * x2 + y2 * y2));
}
int peresech(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, bool &fact) {
	double slope1, slope2; // Eiyooeoeaiou oaeia iaeeiia o?aaiaiee i?yiuo, ia eioi?uo ?aniiei?aiu io?acee
	bool f1 = false, f2 = false; // Eiae?aneea oeaae aey i?yiuo aeaa x = a 
	double yIntercept1, yIntercept2; // Naiaiaiua ?eaiu o?aaiaiee i?yiuo, ia eioi?uo ?aniiei?aiu io?acee
	double xIntersection, yIntersection; // Eii?aeiaou oi?ee ia?ana?aiey, anee iia nouanoaoao

	double vx1 = x2 - x1;
	double vy1 = y2 - y1; // Au?eneei eii?aeiaou aaeoi?ia,
	double vx2 = x4 - x3; // Caaaaaaiuo aaiiuie io?aceaie
	double vy2 = y4 - y3;
	slope1 = (vx1 != 0 ? getSlope(x1, y1, x2, y2) : 0); // Aey i?yiuo aeaa x = a
	slope2 = (vx2 != 0 ? getSlope(x3, y3, x4, y4) : 0); // I?enaaeaaai cia?aiea 0 eiyooeoeaioo oaea iaeeiia
	vx1 != 0 ? yIntercept1 = getYIntercept(x1, y1, x2, y2) : f1 = true; // Aey i?yiuo aeaa x = a 
	vx2 != 0 ? yIntercept2 = getYIntercept(x3, y3, x4, y4) : f2 = true; // I?enaaeaaai oeaao cia?aiea true
	if (!f1 && !f2) {
		xIntersection = (yIntercept2 - yIntercept1) / (slope1 - slope2); // Iaoiaei ?aoaiea nenoaiu o?aaiaiee 
		yIntersection = slope1 * xIntersection + yIntercept1;
		if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 && getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <= 0) // I?iaa?yai iaoiaeony ee oi?ea ia iaieo io?aceao 
			/*cout << "Intersect at a point (" << xIntersection << "," << yIntersection << ")";*/ fact = true;
		else if (yIntercept1 == yIntercept2) {
			if (projectionsIntersect(x1, x2, x3, x4))
				/*	cout << "Overlap";*/ fact = true;
			else
				/* cout << "On the same line, but don't intersect";*/fact = false;
		}
		else if (yIntercept1 != yIntercept2 && (areCollinear(vx1, vy1, vx2, vy2) || (y1 == y2 && y3 == y4)))
			/*cout << "Paralell";*/fact = false;
		else
			/*cout << "Don't intersect";*/fact = false;
	} // Aeie iaoi?aaiey ?aniiei?aiey aey anao io?aceia, e?iia oao, aaa oioy au iaei ec ieo ?aniiei?ai ia i?yiie aeaa x = a
	else {
		if (slope1 == 0 && slope2 == 0 && f1 && f2) {
			if (x1 == x4 && projectionsIntersect(y1, y2, y3, y4))
				/* cout << "Overlap";*/fact = true;
			else if (x1 != x4)
				/* cout << "Paralell";*/fact = false;
			else
				/*cout << "On the same line, but don't intersect";*/fact = false;
		} // Aeie aey aaoo i?yiuo aeaa x = a
		else if (f1 ^ f2 && slope1 == 0 && slope2 == 0) {
			if (f1) {
				swap(x1, x3);
				swap(x2, x4);
				swap(y1, y3);
				swap(y2, y4);
				swap(yIntercept1, yIntercept2);
			}
			yIntersection = y1;
			xIntersection = x3;
			if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 && getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <= 0)
				/*cout << "Intersect at a point ("  << xIntersection << "," << yIntersection << ")";*/fact = true;
			else
				/*cout << "Don't intersect";*/ fact = false;
		} // Aeie aey i?yiuo aeaa y = b e x = a
		else if (slope1 == 0 ^ slope2 == 0) {
			if (slope1 == 0) {
				swap(x1, x3);
				swap(x2, x4);
				swap(y1, y3);
				swap(y2, y4);
				swap(yIntercept1, yIntercept2);
			}
			xIntersection = x3;
			yIntersection = x3 + yIntercept1;
			if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 && getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <= 0)
				/*cout << "Intersect at a point ("  << xIntersection << "," << yIntersection << ")";*/fact = true;
			else
				/*cout << "Don't intersect";*/fact = false;
		} // Aeie iaoi?aaiey ?aniiei?aiey, eiaaa oieuei iaia i?yia eiaao aea x = a, a aoi?ay y = kx +b
	} // Aeie iaoi?aaiey ?aniiei?aiey, anee oioy au iaei io?acie iaoiaeony ia i?yiie aeaa x = a
	return 0;
