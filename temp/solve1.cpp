#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

vector<int> mn, mx, tmp;
int LIM, tt, m;

long long dp[2001][2][2][2001][2];

long long recur(int pos, bool lower, bool higher, int sum, bool found) {
    if(pos == LIM) {
        if(pos == 1)
            return sum == 0;
        if(sum != 0 or not found) return 0;

        //for(auto it : tmp) cout << it;
        //cout << endl;

        return 1;
    }

    long long &ret = dp[pos][lower][higher][sum][found];
    if(ret != -1) return ret;
    ret = 0;

    //long long ret = 0;
    int lo = lower ? mn[pos]:0;
    int hi = higher ? mx[pos]:9;

    if(pos%2 != 0) {
        if(lo <= tt and tt <= hi)
            lo = hi = tt;
        else
            return 0;
    }

    for(int d = lo; d <= hi; ++d) {
        if(pos%2 == 0 and tt == d)
            continue;

        bool newLower = d == mn[pos] ? lower:0;
        bool newHigher = d == mx[pos] ? higher:0;

        //tmp.push_back(d);
        ret = (ret + recur(pos+1, newLower, newHigher, (sum*10 + d)%m, found or (d == tt)))%MOD;
        //tmp.pop_back();
    }
    return ret;
}

string a, b;

void genVal() {
    mn.clear(), mx.clear();
    LIM = b.size();

    for(auto it : b)
        mx.push_back(it-'0');

    while(a.size() < LIM)
        mn.push_back(0);

    for(auto it : a)
        mn.push_back(it-'0');
}

int main() {
    cin >> m >> tt;
    cin >> a >> b;
    
    genVal();

    memset(dp, -1, sizeof dp);
    cout << recur(0, 1, 1, 0, 0) << endl;
    return 0;
}