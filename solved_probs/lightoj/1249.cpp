//LightOJ
//1249 - Chocolate Thief
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, n, x, w, l, h, vol;
    char a[30];
    scanf("%d", &t);
    for(register int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        map<int, int>volume;
        map<int, string>name;
        while(n--) {
            scanf(" %s %d %d %d", a, &w, &l, &h);
            vol = l*h*w;
            volume[vol]++;
            name[vol] = a;
        }
        if(volume.size() == 1)
            printf("Case %d: no thief\n", Case);
        else {
            int mx = -1, mn = 1e9;
            for(map<int, int> ::iterator it = volume.begin(); it != volume.end(); it++) {
                mx = max(mx, it->first);
                mn = min(mn, it->first);
            }
            printf("Case %d: %s took chocolate from %s\n", Case, name[mx].c_str(), name[mn].c_str());
            //cout << "Case " << Case << ": " << name[mx] << " took chocolate from " << name[mn] << "\n";
        }
        //volume.clear();
        //name.clear();
    }
    return 0;
}
