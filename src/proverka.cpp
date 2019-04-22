#include "front.h"
extern void distan(double, double, double, double, double&);
extern void perpendicular(double, double, double, double, double&);
extern int testing(double, double, double, double&);
extern void proverka(
        double, double, double, double, double, double, double&, double, bool&);
extern void printCircle(double, double, double, bool, int, int, int);
extern void printTriangle(
        double, double, double, double, double, double, bool, int, int, int);
extern void printPoligon(
        double,
        double,
        double,
        double,
        double,
        double,
        double,
        double,
        bool,
        int,
        int,
        int);
extern void circle_intersects(double, double, double, double, double, double);

extern int
peresech(double, double, double, double, double, double, double, double, bool&);
extern double getCos(double, double, double, double);
extern double getYIntercept(double, double, double, double);
extern bool projectionsIntersect(double, double, double, double);
extern double getMax(double, double);
extern double getMin(double, double);
extern bool areCollinear(double, double, double, double);
extern double getSlope(double x1, double y1, double x2, double y2);
void proverka(
        double x0,
        double y0,
        double x1,
        double y1,
        double x2,
        double y2,
        double& Perimetr,
        double r,
        bool& okr)
{
    double a, b, c, H, dl, J, Poluper;

    distan(x0, y0, x1, y1, a);
    distan(x0, y0, x2, y2, b);
    distan(x1, y1, x2, y2, c);
    Perimetr = a + b + c;

    Poluper = Perimetr / 2;
    dl = testing(a, b, c, J);
    if (dl == -1) {
        perpendicular(a, b, c, Poluper, H);
        dl = H;

    } else
        dl = J;
    if (dl <= r) {
        okr = true;
    }
}
