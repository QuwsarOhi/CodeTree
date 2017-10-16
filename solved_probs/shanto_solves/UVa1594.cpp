#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, n, v[20];
    unordered_map<string, bool>mp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        bool ok;
        while(1) {
            string y;
            ok = 1;
            for(int i = 0; i < n; ++i)
                if(v[i])
                    ok = 0;
            if(ok)
                break;

            for(int i = 0; i < n; ++i) {
                int t = v[i];
                if(t == 0)
                    y += '0';
                while(t) {
                    y += '0' + t%10;
                    t /= 10;
                }
            }

            if(mp.find(y) != mp.end())
                break;
            else
                mp[y] = 1;

            int tmp = v[0];
            for(int i = 0; i < n; ++i) {
                if(i == n-1)
                    v[i] = abs(v[i] - tmp);
                else
                    v[i] = abs(v[i] - v[i+1]);
            }

            //for(int i = 0 ; i < n; ++i)
              //  printf("%d ", v[i]);
            //printf("\n");

        }
        if(ok)
            printf("ZERO\n");
        else
            printf("LOOP\n");
        mp.clear();
    }
    return 0;
}
