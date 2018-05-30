// UVa
// 347 - Run

#include <bits/stdc++.h>
#define isOn(XX, II) (XX & (1<<II))
using namespace std;

inline bool allUnique(int i) {
    int mask = 0;
    if(!i) return 0; 
    while(i) {
        int x = i%10;
        if(x == 0 or isOn(mask, x))
            return 0;
        mask |= (1 << x);
        i /= 10;
    }
    return 1;
}

inline bool Check(int n) {
    string s = to_string(n);
    int mask = 0;
    register int t, start = s[0]-'0';
    
    for(register int i = 0; ; i += t) {
        if(i >= (int)s.size())
            i %= s.size();
        t = s[i] - '0';
        if(isOn(mask, t))
            return ((t == start) and __builtin_popcount(mask) == s.size());
        mask |= (1 << t);
    }
    return 1;
}

vector<int>v;
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    for(int i = 12; i <= 9876543; ++i)
        if(allUnique(i))
            if(Check(i)) {
                //cout << i << endl;
                v.push_back(i);
            }
    
    //return 0;
    
    int n, Case = 1;
    while(scanf("%d", &n) and n) {
        auto it = lower_bound(v.begin(), v.end(), n);
        printf("Case %d: %d\n", Case++, *it);
    }
    
    return 0;
}
