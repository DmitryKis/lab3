#include "front.h"
extern void distan(double, double, double, double, double&);
extern void perpendicular(double, double, double, double, double&);
extern int testing(double, double, double, double&);
extern void proverka(double, double, double, double, double, double, double&, double, bool&);
extern void printCircle(double, double, double, bool, int, int, int);
extern void printTriangle(double, double, double, double, double, double, bool, int, int,int);
extern void printPoligon(double, double, double, double, double, double, double, double, bool, int, int,int);
extern void circle_intersects(double,double,double,double,double,double);

extern int peresech(double, double, double, double, double, double, double, double, bool&);
extern double getCos(double, double, double, double);
extern double getYIntercept(double, double, double, double);
extern bool projectionsIntersect(double, double, double, double);
extern double getMax(double, double);
extern double getMin(double, double);
extern bool areCollinear(double, double, double, double);
extern double getSlope(double x1, double  y1, double x2, double y2);
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
        if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 &&
            getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <=
            0) // I?iaa?yai iaoiaeony ee oi?ea ia iaieo io?aceao
            /*cout << "Intersect at a point (" << xIntersection << "," << yIntersection << ")";*/ fact = true;
        else if (yIntercept1 == yIntercept2) {
            if (projectionsIntersect(x1, x2, x3, x4))
                /*	cout << "Overlap";*/ fact = true;
            else
                /* cout << "On the same line, but don't intersect";*/fact = false;
        } else if (yIntercept1 != yIntercept2 && (areCollinear(vx1, vy1, vx2, vy2) || (y1 == y2 && y3 == y4)))
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
            if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 &&
                getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <= 0)
                /*cout << "Intersect at a point ("  << xIntersection << "," << yIntersection << ")";*/fact = true;
            else
                /*cout << "Don't intersect";*/ fact = false;
        } // Aeie aey i?yiuo aeaa y = b e x = a
        else if (slope1 == 0 && slope2 == 0) {
            if (slope1 == 0) {
                swap(x1, x3);
                swap(x2, x4);
                swap(y1, y3);
                swap(y2, y4);
                swap(yIntercept1, yIntercept2);
            }
            xIntersection = x3;
            yIntersection = x3 + yIntercept1;
            if (getCos(x1 - xIntersection, y1 - yIntersection, x2 - xIntersection, y2 - yIntersection) <= 0 &&
                getCos(x3 - xIntersection, y3 - yIntersection, x4 - xIntersection, y4 - yIntersection) <= 0)
                /*cout << "Intersect at a point ("  << xIntersection << "," << yIntersection << ")";*/fact = true;
            else
                /*cout << "Don't intersect";*/fact = false;
        } // Aeie iaoi?aaiey ?aniiei?aiey, eiaaa oieuei iaia i?yia eiaao aea x = a, a aoi?ay y = kx +b
    } // Aeie iaoi?aaiey ?aniiei?aiey, anee oioy au iaei io?acie iaoiaeony ia i?yiie aeaa x = a
    return 0;
}

