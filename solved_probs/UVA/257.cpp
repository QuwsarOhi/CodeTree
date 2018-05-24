// UVa
// 257 - Palinwords

#include <bits/stdc++.h>
using namespace std;

int dp[260][260];
string str;
vector<pair<int, int> >p;

int recur(int l, int r) {
    if(l == r)
        return 1;
    if(l+1 == r)
        return dp[l][r] = (str[l] == str[r])?2:0 ;
    if(dp[l][r] != -1)
        return dp[l][r];
    
    int T = -1;
    if(str[l] == str[r]) {
        T = recur(l+1, r-1)+2;
        int len = r-l+1;
        if(len == T and T <= 4)
            p.push_back({l, r});
    }
    return dp[l][r] = max(recur(l+1, r), max(recur(l, r-1), T));
}

bool Check2() {
    for(int i = 0; i < (int)p.size(); ++i) {
        for(int j = i+1; j < (int)p.size(); ++j) {
            int l1 = p[i].second - p[i].first + 1;
            int l2 = p[j].second - p[j].first + 1;
            
            string s1 = str.substr(p[i].first, l1);
            string s2 = str.substr(p[j].first, l2);
            
            if(l1 < l2) {
                size_t T = s2.find(s1);
                if(T == string::npos)
                    return 1;
            }
            else if(l1 > l2) {
                size_t T = s1.find(s2);
                if(T == string::npos)
                    return 1;
            }
            else if(s1 != s2)
                return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(cin >> str) {
        memset(dp, -1, sizeof dp);
        p.clear();
        recur(0, str.size());
        
        if(Check2())
            cout << str << "\n";
    }
    return 0;
}
