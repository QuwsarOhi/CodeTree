//UVa
//191 Intersection
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
#define EPS 1e-3
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
}; // second criteria, by y-coordinate

struct line {double a, b, c;};

bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areIntersect(line l1, line l2, point &p) {
if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
else p.y = -(l2.a * p.x + l2.c);
return true; }

bool pointIntersect(point p1, point p2, point p3) {
    double maxx, maxy, miny, minx;
    if(p1.x > p2.x) maxx = p1.x;
    else maxx = p2.x;
    if(p1.y > p2.y) maxy = p1.y;
    else maxy = p2.y;
    if(p3.x - maxx <= EPS  && p3.x - minx >= EPS &&
       p3.y - maxy <= EPS && p3.y - miny <= EPS)
        return 1;
    return 0;
}

double dist(point p1, point p2) //DISTANCE
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x)
                 + (p1.y - p2.y) * (p1.y - p2.y));
}

bool isOnSegment(point p1, point p2, point p3) //Testing if a point(intersection of two lines) is in a line segment
{
    if (dist(p1, p3) - EPS <= dist(p1, p2)
        && dist(p2, p3) - EPS <= dist(p1, p2))
        return true;

    return false;
}

bool isInsideRectangle(point p1, point p2, point p3)
{
    if (p3.x <= max(p1.x, p2.x)
        && p3.x >= min(p1.x, p2.x)
        && p3.y <= max(p1.y, p2.y)
        && p3.y >= min(p1.y, p2.y))
        return true;

    return false;
}

void pointsToLine(point p1, point p2, line &l) {
if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
} else {
l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
l.c = -(double)(l.a * p1.x) - p1.y;
} }

int main()
{
    //frein;
    //freout;
    register int t;
    double x1, y1, x2, y2, xl, yt, xr, yb;
    sf("%d", &t);
    wh(t--) {
        sf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &xl, &yt, &xr, &yb);
        point p1(x1, y1), p2(x2, y2), leftbottom(xl, yb), lefttop(xl, yt), rightbottom(xr, yb), righttop(xr, yt), p;
        line l, top, bottom, left, right;
        pointsToLine(p1, p2, l);
        pointsToLine(leftbottom, rightbottom, bottom);
        pointsToLine(lefttop, righttop , top);
        pointsToLine(lefttop, leftbottom, left);
        pointsToLine(rightbottom, righttop, right);
        if(isInsideRectangle(lefttop, rightbottom, p1) || isInsideRectangle(lefttop, rightbottom, p2))
            pf("T\n");
        else {
            bool ok = 0;
            if(areIntersect(top, l, p))
                if(isOnSegment(lefttop, righttop, p) && isOnSegment(p1, p2, p)) ok = 1;
            if(areIntersect(bottom, l, p))
                if(isOnSegment(leftbottom, rightbottom, p) && isOnSegment(p1, p2, p)) ok = 1;
            if(areIntersect(left, l, p))
                if(isOnSegment(lefttop, leftbottom, p) && isOnSegment(p1, p2, p)) ok = 1;
            if(areIntersect(right, l, p))
                if(isOnSegment(righttop, rightbottom, p) && isOnSegment(p1, p2, p)) ok = 1;
            if(ok) pf("T\n");
            else pf("F\n");
        }
    }
    return 0;
}
