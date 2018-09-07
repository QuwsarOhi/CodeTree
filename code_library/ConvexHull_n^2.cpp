// Convex Hull
// Gift Wrapping (Jarvis)
// Complexity : O(n^2)
// https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
// https://www.hackerearth.com/problem/approximate/polygon-partition-910a3b76/

ll whichSide(pll p, pll q, pll r) {     // returns on which side point r is w.r.t pq line
    // slope = 0 : linear
    // slope > 0 : right
    // slope < 0 : left
    ll slope = (p.y-q.y)*(q.x-r.x) - (q.y-r.y)*(p.x-q.x);
    return slope;
}

ll dist(pll a, pll b) {
    ll X = a.x - b.x;
    ll Y = a.y - b.y;
    return X*X + Y*Y;
}


vector<int> hull;       // Used in convexHull
bool convexHull(vector<pll> &v) {
    if(v.size() < 3)
        return 0;
    
    // Finding LeftMost point
    int l = 0;
    for(int i = 1; i < (int)v.size(); ++i)
        if(v[i].x < v[l].x)
            l = i;
    
    //printf("Starting %lld %lld\n", v[l].x, v[l].y);
    int p = l, q;
    do {
        hull.push_back(p);          // Hull point index is pushed
        
        q = (p+1) % v.size();
        // This checks if there exists same point twice (no need if points are unique)
        while(v[p] == v[q])
            q = (q+1) % v.size();
        
        for(int i = 0; i < (int)v.size(); ++i) {
            ll side = whichSide(v[p], v[q], v[i]);
            if(side < 0)                                                        // point i is on left w.r.t point pq
                q = i;
            // Use this commented code, if minimum number of points needed (points in same line is rejected)
            //else if(side == 0 and dist(v[p], v[q]) < dist(v[p], v[i]))          // if point i is on same line pq
            //    q = i;
        }
        p = q;
    }while(p != l);
    
    return 1;
}

vector<pll>points;
vector<int>Ans[1010];
map<pll, vector<int> > Map;

int main() {
    int sz = 0, n;
    ll X, Y;
    
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &X, &Y);
        points.push_back({X, Y});
    }
            
    for(auto it : points)
        Map[it].push_back(sz++);
    sz = 0;
    
    while(1) {
        if(!convexHull(points))
            break;
        sort(hull.begin(), hull.end(), greater<int>());
        
        for(auto idx : hull) {
            Ans[sz].push_back(Map[points[idx]].back());
            Map[points[idx]].pop_back();
            points.erase(points.begin()+idx);
        }
        
        hull.clear();
        ++sz;
    }

    for(int i = 0; i < (int)points.size(); ++i)
        Ans[sz].push_back(Map[points[i]].back());
    sz += (points.empty() == 0);

    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i) {
        printf("%d", Ans[i].size());
        for(auto it : Ans[i])
            printf(" %d", it+1);
        printf("\n");
    }      
    return 0;
}
