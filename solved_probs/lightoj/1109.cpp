//LightOJ
//1109 	False Ordering
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> >v;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if(x.first != y.first)
        return x.first < y.first;
    else
        return x.second > y.second;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    for(register int i = 0; i <= 1000; i++)
        v.push_back(make_pair(0, i));
    for(register int i = 1; i <= 1000; i++)
        for(register int j = 1; j*i <= 1000; j++) {
            v[i*j].first++;
        }

    sort(v.begin(), v.end(), cmp);
    int t, n;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", Case, v[n].second);
    }
    return 0;
}
