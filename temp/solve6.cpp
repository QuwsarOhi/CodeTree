#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Trie {
    struct node {
        ll val1, val2;
        node *next[15];
        node() {
            for(int i = 0; i < 15; ++i)
                next[i] = NULL;

    node *root;
    int fixLen, v[20];

    Trie(int len = 13) {
        root = new node();
        fixLen = len;
    }

    void insert(pll p, int pos, node *cur) {
        if(cur == NULL)
            cur = new node();
        if(pos == fixLen) {
            cur->val1 = p.first, cur->val2 = p.second;
            return;
        }
        if(cur->next[v[pos]] == NULL)
            cur->next[v[pos]] = new node();
        insert(p, pos+1, cur->next[v[pos]]);
    }

    void clear() {
        cclear(root);
        root = new node();
    }

    void cclear(node *cur) {
        for(int i = 0; i < 15; ++i)
            if(cur->next[i] != NULL)
                cclear(cur->next[i]);
        delete cur;
    }

    pll check(int pos, node *cur) {
        if(cur == NULL)
            return make_pair(-1, -1);
        if(pos == fixLen)
            return make_pair(cur->val1, cur->val2);
        if(cur->next[v[pos]] == NULL)
            return make_pair(-1, -1);
        return check(pos+1, cur->next[v[pos]]);
    }

    void convert(int pos, int cnt[], bool tight, bool firstZero) {
        v[0] = pos;
        for(int i = 0; i < 10; ++i)
            v[i+1] = cnt[i];
        v[11] = tight;
        v[12] = firstZero;
    }
};

Trie DP(13);
vector<int>mxDigit;

/*
unordered_map<string, pll>DP;
string conv(int pos, int cnt[], bool tight, bool firstZero) {
    string ret;
    if(pos < 10)
        ret += "0";
    ret += to_string(pos);

    for(int i = 0; i < 10; ++i) {
        if(cnt[i] < 10)
            ret += "0";
        ret += to_string(cnt[i]);
    }

    ret += tight? "1":"0";
    ret += firstZero? "1":"0";

    return ret;
}*/

int CntCal(int val, int cnt[]) {
    int ret = 0;
    for(int i = 0; i < val; ++i)
        ret += cnt[i];
    return ret;
}

// {total_number_of_values, DI(K)_for_the_next_vals}

pll recur(int pos, int cnt[], bool tight = 1, bool firstZero = 1) {
    if(pos == -1)
        return make_pair(1, 0);

    // Unordered Map DP
    /*string ss = conv(pos, cnt, tight, firstZero);
    if(DP.find(ss) != DP.end())
        return DP[ss];*/

    DP.convert(pos, cnt, tight, firstZero);
    pll tmp = DP.check(0, DP.root);

    if(tmp.first != -1) {
        cerr << "HIT\n";
        return tmp;
    }

    pll ret = {0, 0};
    int lim = tight ? mxDigit[pos]:9;
    for(int i = 0; i <= lim; ++i) {
        bool newTight = (mxDigit[pos] == i)?tight:0;
        bool newZero = (i == 0) and firstZero;
        int newCnt = CntCal(i, cnt);
        
        if(not newZero)
            ++cnt[i];

        tmp = recur(pos-1, cnt, newTight, newZero);
        ret.first += tmp.first;
        ret.second += tmp.second + tmp.first*newCnt;

        if(not newZero)
            --cnt[i];
    }

    // Unordered Map DP
    //DP[ss] = ret;

    DP.convert(pos, cnt, tight, firstZero);
    DP.insert(ret, 0, DP.root);

    return ret;
}

int main() {
    ll x, y;
    int t, cnt[10];

    // Unordered Map DP bucket increse
    //DP.rehash(10000000);
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &y, &x);
        if(x < y) swap(x, y);

        mxDigit.clear();
        
        // Unordered Map DP
        //DP.clear();
        //cerr << "Bucket Size " << DP.bucket_count() << endl;
        
        while(x) {
            mxDigit.push_back(x%10);
            x/=10;
        }

        memset(cnt, 0, sizeof cnt);
        ll ans = recur((int)mxDigit.size()-1, cnt, 1).second;
            
        y -= 1;
        if(y > 0) {
            mxDigit.clear();

            // Unordered Map DP
            //DP.clear();

            while(y) {
                mxDigit.push_back(y%10);
                y/=10;
            }

            memset(cnt, 0, sizeof cnt);
            ans -= recur((int)mxDigit.size()-1, cnt, 1).second;
        }

        printf("Case %d: %lld\n", Case, ans);
    }
    
    // Trie DP clear
    DP.clear();
    return 0;
}

/*

6
1 9
1 100
50 60
23 2343
345 99373
1 100000000000000

Case 1: 0
Case 2: 36
Case 3: 4
Case 4: 6083
Case 5: 410008
Case 6: 3966111111111111

*/