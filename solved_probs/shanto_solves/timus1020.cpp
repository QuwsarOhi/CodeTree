// Timus
// 1020. Rope

#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

float dist(pair<float, float>p1, pair<float, float>p2) {
    float x = p1.first - p2.first;
    float y = p1.second - p2.second;
    return sqrt(x*x + y*y);
}

int main() {
    int n;
    float ans = 0, x, y, r;
    vector<pair<float, float> >v;
    scanf("%d %f", &n, &r);
    for(int i = 0; i < n; ++i) {
        scanf("%f %f", &x, &y);
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    for(int i = 0; i < n; ++i)
        ans += dist(v[i], v[i+1]);
    //printf("%f\n", ans);
    ans += 2*PI*r;
    printf("%.2f\n", ans);
    return 0;
}
