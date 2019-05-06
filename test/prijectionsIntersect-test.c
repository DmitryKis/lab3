#include "geometry.h"

double getMax_(double x1, double x2) { return x1 > x2 ? x1 : x2; }

double getMin_(double x1, double x2) { return x1 < x2 ? x1 : x2; }

bool projectionsIntersect(double x1, double x2, double x3, double x4) {
  return ((getMin_(x1, x2) <= getMin_(x3, x4) &&
           getMin_(x3, x4) <= getMax_(x1, x2)) ||
          ((getMin_(x3, x4) <= getMin_(x1, x2) &&
            getMin_(x1, x2) <= getMax_(x3, x4))));
}

TEST_CASE("", "[]") {
  REQUIRE(projectionsIntersect(1, 2, 3, 4) == false);
  REQUIRE(projectionsIntersect(1, 1, 1, 1) == true);
  cout << "Test projections intersect" << endl;
}
