// The trig functions of C++ take radian exclusively
// 0D Objects---------------------------------------------------------------
struct point {          // In Integer
    int x, y;
    point() { x = y = 0; }
    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
    
    bool operator == (point other) const {
        return (x == other.x) && (y == other.y);
}};

struct point {          // In Double
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
}};

bool Equal(double a, double b) {
    return (fabs(a-b) <= EPS);
}

int hypot(point p1, point p2) {
    int x = p1.x-p2.x;
	int y = p1.y-p2.y;
    return x*x + y*y;
}
    
double dist(point p1, point p2) {
	int x = p1.x-p2.x;
	int y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

double DEG_to_RAD(double deg) {             // Converts Degree to Radian
    return (deg*PI)/180;
}

double RAD_to_DEG(double rad) {
    return (180/PI)*rad;
}

point rotate(point p, double theta) {       // Rotates point p w.r.t. origin.  (theta is in degree)
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

double PointToArea(point p1, point p2, point p3) {                      // Returns Positive Area in if the points are clockwise, Negative for Anti-Clockwise
	return (p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y));	// Divide by 2 if Triangle area is needed
}

/*
if(slope==0): They are all colinear
if(slope>0) : They are all clockwise
if(slope<0) : They are counter clockwise
*/
double whichSide(point p, point q, point r) {     // returns on which side point r is w.r.t pq line
    double slope = (p.y-q.y)*(q.x-r.x) - (q.y-r.y)*(p.x-q.x);
    return slope;
}

// 1D Objects---------------------------------------------------------------
struct line {
    double a, b, c;
};
void pointsToLine(point p1, point p2, line &l) {    // ax + by + c = 0  [comes from y = mx + c]
    if (fabs(p1.x - p2.x) < EPS)                    // vertical line is fine
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;          // default values
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;                                  // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
}}
bool areParallel(line l1, line l2) {            // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) {                // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
    if(areParallel(l1, l2)) return 0;                                   // no intersection
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);    // solve system of 2 linear algebraic equations with 2 unknowns
    if(fabs(l1.b) > EPS)    p.y = -(l1.a * p.x + l1.c);                 // special case: test for vertical line to avoid division by zero
    else                    p.y = -(l2.a * p.x + l2.c);
    return 1;
}
line perpendicularLine(line l, point p) {           // returns a perpendicular line on l which goes throuth
    line ret;                                       // point p
    ret.a = l.b, ret.b = -l.a;
    ret.c = -(ret.a*p.x + ret.b*p.y);
    if(ret.b < 0) ret.a *= -1, ret.b *= -1, ret.c *= -1;    // as line must contain b = 1.0 by default
    if(ret.b != 0) {
        ret.a /= ret.b;
        ret.c /= ret.b;
        ret.b = 1;
    }
    return ret;
}

// Vectors ------------------------------
struct vec { 
    double x, y;                        // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) {           // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) {            // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);       // shorter.same.longer
}
point translate(point p, vec v) {       // translate p according to v
    return point(p.x + v.x , p.y + v.y);
}
double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

// Parametric Line ------------------------------
struct ParaLine {                                       // Line in Parametric Form
    point a, b;                                         // points must be in DOUBLE
    ParaLine() { a.x  = a.y = b.x = b.y = 0; }
    ParaLine(point _a, point _b) : a(_a), b(_b) {}      // {Start, Finish} or {from, to}

    point getPoint(double t) {                          // Parametric Line : a + t * (b - a)    t = [-inf, +inf]
        return point(a.x + t*(b.x-a.x), a.y + t*(b.y-a.y));
}};

// Returns the distance from p to the line defined by  two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {        // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                             // translate a to c
    return dist(p, c);                                          // Euclidean distance between p and c
}

// Returns the distance from p to the line segment ab defined by two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0) {
        c = point(a.x, a.y);        // closer to a
        return dist(p, a);          // Euclidean distance between p and a
    }
    if (u > 1.0) { 
        c = point(b.x, b.y);        // closer to b
        return dist(p, b);          // Euclidean distance between p and b 
    }
    return distToLine(p, a, b, c);  // run distToLine as above
}

// Returns the angle aob given three points: a, o, and b, (using dot product)
double angle(point a, point o, point b) {       // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {                    // Cross product of two vectors
    return a.x * b.y - a.y * b.x;               // note: to accept collinear points, we have to change the ‘> 0’
}

bool ccw(point p, point q, point r) {           // returns true if point r is on the left side of line pq
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {     // returns true if point r is on the same line as the line pq
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// 2D Objects ---------------------------------------------------------------
// --------- CIRCLE --------- 
struct circle {
	int x, y, r;
	circle(int _x, int _y, int _r) {
		x = _x;
		y = _y;
		r = _r;
	}
	double Area() {
		return PI*r*r;
	}
};

// Reference: https://www.mathsisfun.com/geometry/circle-sector-segment.html
double CircleSegmentArea(double r, double theta) {		// Circle Radius, Center Angle(degree)
	return r * r * 0.5 * (DEG_to_RAD(theta) - sin(DEG_to_RAD(theta)));
}
double CircleSectorArea(double r, double theta) {		// Circle Radius, Center Angle(degree)
	return r * r * 0.5 * DEG_to_RAD(theta);
}
double CircleArcLength(double r, double theta) {		// Circle Radius, Center Angle(degree)
	return r * DEG_to_RAD(theta);
}
bool doIntersectCircle(circle c1, circle c2) {
	int dis = dist(point(c1.x, c1.y), point(c2.x, c2.y));
	if(sqrt(dis) < c1.r+c2.r) return 1;
	return 0;
}
bool isInside(circle c1, circle c2) {                   // Returns true if any one of the circle is fully into another circle
    int dis = dist(point(c1.x, c1.y), point(c2.x, c2.y));
    return ((sqrt(dis) <= max(c1.r, c2.r)) and (sqrt(dis) + min(c1.r, c2.r) < max(c1.r, c2.r)));
}
// Returns where a point p lies according to a circle of center c and radius r
int insideCircle(point p, point c, int r) {         // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;     // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;      // inside(0)/border(1)/outside(2)
}

// Given 2 points on the circle (p1 and p2) and radius r of the corresponding circle,
// determine the location of the centers (c1 and c2) of the two possible circles
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if(det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;                                            // to get the other center, reverse p1 and p2
}

// --------- Triangle ---------
double TriangleArea(double AB, double BC, double CA) {
	double s = (AB + BC + CA)/2.0;
	return sqrt(s*(s-AB)*(s-BC)*(s-CA));
}
double getAngle(double AB, double BC, double CA) {		// Returns the angle(IN RADIAN) opposide of side CA
	return acos((AB*AB + BC*BC - CA*CA)/(2*AB*BC));
}
double rInCircle(double ab, double bc, double ca) {     // Returns radius of inCircle of a triangle
    return TriangleArea(ab, bc, ca) / (0.5 * (ab + bc+ ca));
}
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0;                    // no inCircle center
    line l1, l2;                    
    double ratio = dist(p1, p2) / dist(p1, p3);     // compute these two angle bisectors
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr);
    return 1;
}
// radius of Circle Outside of a Triangle
double rCircumCircle(double ab, double bc, double ca) {     // ab, ac, ad are sides of triangle
    return ab * bc * ca / (4.0 * TriangleArea(ab, bc, ca));
}
point CircumCircleCenter(point a, point b, point c, double &r) {    // returns certer and radius of circumcircle
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ca = dist(c, a);
    r = rCircumCircle(ab, bc, ca);
    if(Equal(r, ab))    return point((a.x+b.x)/2, (a.y+b.y)/2);
    if(Equal(r, bc))    return point((b.x+c.x)/2, (b.y+c.y)/2);
    if(Equal(r, ca))    return point((c.x+a.x)/2, (c.y+a.y)/2);
    line AB, BC;
    pointsToLine(a, b, AB);
    pointsToLine(b, c, BC);
    line perpenAB = perpendicularLine(AB, point((a.x+b.x)/2, (a.y+b.y)/2));
    line perpenBC = perpendicularLine(BC, point((b.x+c.x)/2, (b.y+c.y)/2));
    point center;
    areIntersect(perpenAB, perpenBC, center);
    return center;
}

// --------- Trapizoid ---------
double TrapiziodArea(double a, double b, double c, double d) {      // a and c are parallel
    double BASE = fabs(a-c);
    double AREA = TriangleArea(d, b, BASE);
    double h = (AREA*2)/BASE;
    return ((a+c)/2)*h;
}
