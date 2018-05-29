// UVa
// 216 - Getting in Line

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int>pii;

vector<pii>T, Ans, V;
double best = 1e7;
int n;

double dist(pii a, pii b) {
    int x = a.X - b.X;
    int y = a.Y - b.Y;
    
    return sqrt(x*x + y*y);
}

void recur(int pos, double cost, int mask) {
    if(__builtin_popcount(mask) == n) {
        if(cost < best) {
            best = cost;
            Ans.clear();
            Ans = T;
        }
        return;
    }
    
    for(int i = 0; i < n; ++i)
        if(not (mask & (1<<i))) {
            double t = dist(V[pos], V[i]);
            T.push_back({pos, i});
            recur(i, cost+t, mask | (1<<i));
            T.pop_back();
        }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int x, y, Case = 1;
    
    while(scanf("%d", &n) and n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            V.push_back({x, y});
        }
        
        //cout << "DONE\n";
        for(int i = 0; i < n; ++i)
            recur(i, 0, (1<<i));
        
        printf("**********************************************************\n");
        printf("Network #%d\n", Case++);
        for(auto it : Ans)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", V[it.X].X, V[it.X].Y, V[it.Y].X, V[it.Y].Y, dist(V[it.X], V[it.Y])+16);
        printf("Number of feet of cable required is %.2lf.\n", best+(n-1)*16);
        Ans.clear();
        V.clear();
        best = 1e7;
    }
    
    return 0;
}
