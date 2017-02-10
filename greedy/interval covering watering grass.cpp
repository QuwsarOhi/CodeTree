//UVa
//10382 - Watering Grass
//Interval Covering
#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, l, w, cnt;
    double d, r;
    vector<pdd>v;
    while(scanf("%d %d %d", &n, &l, &w) != EOF) {
        for(register int i = 0; i < n; i++) {
            scanf("%lf %lf", &d, &r);
            if(r > w/2.0)
                v.push_back(make_pair(d - sqrt(r*r - w*w/4.0), d + sqrt(r*r - w*w/4.0)));
        }
        sort(v.begin(), v.end());
        double segment_finish = 0;
        cnt = 0;
        for(register int i = 0; i < v.size(); i++) {
            double temp = segment_finish;
            int pos = -1, j = i;
            while(v[j].first <= segment_finish && j < v.size()) {
                if(temp < v[j].second) {
                    temp = v[j].second;
                    pos = j;
                }
                j++;
            }
            if(pos != -1 && pos < v.size()) {
                cnt++;
                segment_finish = v[pos].second;
            }
            if(segment_finish >= l)
                break;
        }
        if(segment_finish >= l)
            printf("%d\n", cnt);
        else
            printf("-1\n");
        v.clear();
    }
    return 0;
}
