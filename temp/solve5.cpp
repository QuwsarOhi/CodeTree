// UVa
// 353 - Pesky Palindromes

#include <bits/stdc++.h>
using namespace std;

int dp[90][90];
set<string>p;
string s;

bool recur(int l, int r) {
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l == r) {
        p.insert(s.substr(l, 1));
        return (dp[l][r] = 1);
    }
    if(l+1 == r) {
        if(s[l] == s[r])
            p.insert(s.substr(l, 2));
        return (dp[l][r] = (s[l] == s[r]));
    }
    
    bool ret = 0;
    if(s[l] == s[r]) {
        ret = recur(l+1, r-1);
        if(ret)
            p.insert(s.substr(l, r-l+1));
    }
    
    recur(l+1, r);
    recur(l, r-1);
    recur(l+1, r-1);
    return (dp[l][r] = ret);
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    while(cin >> s) {
        memset(dp, -1, sizeof dp);
        recur(0, (int)s.size()-1);
        for(int i = 0; i < (int)s.size(); ++i) p.insert(s.substr(i, 1)); 
        cout << "The string '" << s << "' contains " << p.size() << " palindromes.\n";
        //for(auto it : p)
        //    cout << it << endl;
        p.clear();
    }
    return 0;
}
