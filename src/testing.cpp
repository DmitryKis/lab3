#include "front.h"
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

