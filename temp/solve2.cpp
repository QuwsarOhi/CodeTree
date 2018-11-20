#include <bits/stdc++.h>
using namespace std;

vector<int> mn, mx;
int cntLim[10], tt[20], lim;
/*
long long dp[19][2][2][2][2][2][2][2][2][2][2][2][2][2];

bool tmpBool[10];
long long getVal(int pos, int cnt[], bool nonZero, bool lowTight, bool hiTight) {
    for(int i = 0; i < 10; ++i)
        tmpBool[i] = cnt[i] == cntLim[i];
    return dp[pos][tmpBool[0]][tmpBool[1]][tmpBool[2]][tmpBool[3]][tmpBool[4]][tmpBool[5]][tmpBool[6]][tmpBool[7]][tmpBool[8]][tmpBool[9]][nonZero][lowTight][hiTight];
}

void setVal(int pos, int cnt[], bool nonZero, bool lowTight, bool hiTight, long long val) {
    for(int i = 0; i < 10; ++i)
        tmpBool[i] = cnt[i] == cntLim[i];
    dp[pos][tmpBool[0]][tmpBool[1]][tmpBool[2]][tmpBool[3]][tmpBool[4]][tmpBool[5]][tmpBool[6]][tmpBool[7]][tmpBool[8]][tmpBool[9]][nonZero][lowTight][hiTight] = val;
}*/


unordered_map<string, long long>dp;

string Convert(int pos, int cnt[], bool nonZero, bool lowTight, bool hiTight) {
    string ret;
    if(pos < 10)
        ret += "0";
    ret += to_string(pos);
    for(int i = 0; i < 10; ++i) {
        if(cnt[i] < 10)
            ret += "0";
        ret += to_string(cnt[i]);
    }

    ret += to_string(nonZero);
    ret += to_string(lowTight);
    ret += to_string(hiTight);

    return ret;
}


long long recur(int pos, int cnt[], bool nonZero, bool lowTight, bool hiTight) {
    if(pos == lim) {
        for(int i = 0; i < 10; ++i)
            if(cnt[i] == cntLim[i])
                return 0;
        /*for(int i = 0; i < lim; ++i)
            cout << tt[i];
        cout << endl;*/
        return 1;
    }

    string tag = Convert(pos, cnt, nonZero, lowTight, hiTight);
    if(dp.find(tag) != dp.end()) {
        //cerr << "HIT" << endl;
        return dp[tag];
    }


    long long ret = 0;
    int lo = lowTight ? mn[pos]:0;
    int hi = hiTight ? mx[pos]:9; 

    for(int d = lo; d <= hi; ++d) {
        bool newLowTight = d == mn[pos] ? lowTight:0;
        bool newHiTight = d == mx[pos] ? hiTight:0; 
        bool newNonZero = nonZero or d > 0;

        //tt[pos] = d;
        if(newNonZero)
            cnt[d] += 1;
        ret += recur(pos+1, cnt, newNonZero, newLowTight, newHiTight);
        if(newNonZero)
            cnt[d] -= 1;
    }

    dp[tag] = ret;
    return ret;
}

int main() {
    //dp.rehash(10000);
    int t, cnt[10];
    long long a, b;
    cin >> t;


    while(t--) {
        cin >> a >> b;
        if(a > b) swap(a, b);

        for(int i = 0; i < 10; ++i)
            cin >> cntLim[i];

        mx.clear();
        while(b) {
            mx.push_back(b%10);
            b/=10;
        }
        lim = mx.size();

        mn.clear();
        while(a) {
            mn.push_back(a%10);
            a/=10;
        }

        while(mn.size() < lim)
            mn.push_back(0);

        reverse(mx.begin(), mx.end());
        reverse(mn.begin(), mn.end());
        memset(cnt, 0, sizeof cnt);

        dp.clear();
        cout << recur(0, cnt, 0, 1, 1) << endl;
    }
    return 0;
}