// LightOJ
// 1061 - N Queen Again

#include <bits/stdc++.h>
#define isOn(XX, II) (XX & (1<<II))
#define INF 1e7
using namespace std;
typedef pair<int, int>pii;

vector<pii>s, qPos;
vector<vector<pii> >ValidPos;
int col[8], dp[8][260];

bool place(int r, int c) {
    for(int prevR = 0; prevR < r; ++prevR)
        if(col[prevR] == c || abs(col[prevR]-c) == abs(prevR-r))
            return 0;
    return 1;
}

void genPlace(int r) {
    if(r == 8) {
        ValidPos.push_back(s);
        return;
    }
    
    for(int i = 0; i < 8; ++i)
        if(place(r, i)) {
            s.push_back(make_pair(r, i));
            col[r] = i;
            genPlace(r+1);
            s.pop_back();
        }
}


int dist(pii u, pii v) {
    if(u == v) return 0;
    if(u.first == v.first || u.second == v.second) return 1;
    if(abs(u.first-v.first) == abs(u.second-v.second)) return 1;
    return 2;
}

int Try(int idx, int p, int mask) {
    if(p == 8)
        return 0;
    
    if(dp[p][mask] != -1)
        return dp[p][mask];   
     
    int ret = INF;
    for(int i = 0; i < 8; ++i)
        if(!isOn(mask, i)) {
            pii T = ValidPos[idx][i];
            int d = dist(qPos[p], T);
            ret = min(ret, Try(idx, p+1, mask | (1 << i))+d);
        }
    return dp[p][mask] = ret;
}
            

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    genPlace(0);
    int t, sz = ValidPos.size();
    char c;

    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j) {
                scanf(" %c", &c);
                if(c == 'q')
                    qPos.push_back(make_pair(i, j));
            }
        
        int ans = INF;
        for(int i = 0; i < sz; ++i) {
            memset(dp, -1, sizeof dp);
            ans = min(ans, Try(i, 0, 0));
        }

        printf("Case %d: %d\n", Case, ans);
        qPos.clear();
    }
    
    return 0;
}
        
