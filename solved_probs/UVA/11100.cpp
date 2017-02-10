//UVa
//11100 - The Trip, 2007
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vt;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    map<int, int>mp;
    int n, x, mx;
    bool first = 1;
    while(scanf("%d", &n) && n) {
        if(!first) printf("\n");
        first = 0;
        mx = 0;
        for(register int i = 0 ; i < n; i++) {
            scanf("%d", &x);
            mx = max(++mp[x], mx);
        }
        printf("%d\n", mx);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            for(register int i = 0; i < it->second; i++) {
                auto it_next = it;
                printf("%d", it->first);
                it_next++;
                int tmp = ceil(n/(float)mx) - 1;
                vector<pair<int, int> >v;
                while(it_next != mp.end() && tmp) {
                    if(it_next->second > 0)
                        v.push_back(make_pair(it_next->second, it_next->first));
                    it_next++;
                }
                sort(v.begin(), v.end(), greater<pair<int, int> >());
                for(register int i = 0; i < tmp && i < v.size(); i++) {
                    printf(" %d", v[i].second);
                    mp[v[i].second]--;
                }
                printf("\n");
            }
        }
        mp.clear();
    }
    return 0;
}
