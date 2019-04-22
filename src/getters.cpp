#include "front.h"

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

