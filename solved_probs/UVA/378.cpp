//UVa
//378 Intersecting Lines
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 500000
#define EPS 1e-9
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

struct point { double x, y; // only used if more precision is needed
point() { x = y = 0.0; } // default constructor
point(double _x, double _y) : x(_x), y(_y) {} }; // user-defined

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line &l) {
if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
} else {
l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
l.c = -(double)(l.a * p1.x) - p1.y;
} }

bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) { // also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

bool areIntersect(line l1, line l2, point &p) {
if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
else p.y = -(l2.a * p.x + l2.c);
return true; }

int main()
{
    //frein;
    //freout;
    int t;
    sf(" %d", &t);
    double x1, y1, x2, y2, x3, y3, x4, y4;
    pf("INTERSECTING LINES OUTPUT\n");
    wh(t--) {
        sf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
        //pf("%f %f %f %f %f %f %f %f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
        line l1, l2;
        point p;
        pointsToLine(p1, p2, l1), pointsToLine(p3, p4, l2);
        //pf("%f %f %f\n%f %f %f\n", l1.a, l1.b, l1.c, l2.a, l2.b, l2.c);
        if(areIntersect(l1, l2, p))
            pf("POINT %.2f %.2f\n", p.x, p.y);
        else if(areSame(l1, l2))
            pf("LINE\n");
        else
            pf("NONE\n");
    }
    pf("END OF OUTPUT\n");
    return 0;
}
