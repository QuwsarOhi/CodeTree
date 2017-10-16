#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> >mp;
int n;
double mid;

bool isOk(int x1, int x2) {
    if(mid == 1e9)
        mid = (x1+x2)/2;
    else if(mid != (x1+x2)/2)
        return 0;
    return 1;
}


bool isSymmetric() {
    mid = 1e9;
    for(auto it : mp) {
        vector<int> &v = it.second;
        sort(v.begin(), v.end());
        if((int)v.size() % 2 != 0) {
            if(!isOk(v[(int)v.size()/2], v[(int)v.size()/2])) {
                return 0;
            }
            continue;
        }
        for(int i = 0, j = (int)v.size()-1; i < j; ++i, --j)
            if(!isOk(v[i], v[j])) {
                return 0;
            }
    }
    return 1;
}


int main() {
    int t, x, y;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            mp[y].push_back(x);
        }
        if(isSymmetric())
            printf("YES\n");
        else
            printf("NO\n");
        mp.clear();
    }

    return 0;
}
