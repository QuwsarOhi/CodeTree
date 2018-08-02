#include <bits/stdc++.h>
using namespace std;
#define MAX                 100009
#define EPS                 1e-9
#define INF                 1e17
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


struct SegTree {
    int sum[4*MAX], propl[4*MAX], propr[4*MAX], propSetVal[4*MAX];
    bool isSet[4*MAX];
    
    // No init added
    void init() {
        memset(sum, 0, sizeof sum);
        memset(propl, 0, sizeof propl);
        memset(propr, 0, sizeof propr);
        memset(propSetVal, 0, sizeof propSetVal);
        memset(isSet, 0, sizeof isSet);
    }
    
    ll getSum(ll l, ll r, ll n) {
        if(l > r) swap(l, r);
        ll d = (r-l) / ((n-1) > 1 ? n-1:1);
        return (n*(2*l + (n-1)*d))/2;
    }
    
    ll getIth(ll l, ll r, ll i, ll n) {
        ll d = abs(r-l)/(n-1);
        if(l < r)   return l + (i-1)*d;
        else        return r + (n-i-1)*d;
    }
    
    void propSet(int pos, int l, int r) {
        if(l == r || isSet[pos] == 0) return;
        
        propl[pos] = propr[pos] = propl[pos<<1] = propr[pos<<1] = propl[pos<<1|1] = propr[pos<<1|1] = 0;
        sum[pos<<1] = sum[pos<<1|1] = ((r-l+1)/2)*propSetVal[pos];
        
        propSetVal[pos<<1] = propSetVal[pos<<1|1] = propSetVal[pos];
        propSetVal[pos] = 0;
    }
    
    void propSeries(int pos, int l, int r) {
        if(l == r || propl[pos] == 0) return;
        int mid = (l+r)>>1, n = r-l+1;
        int d = mid-l+1;
        
        if(isSet[pos<<1] == 1)   propSet(pos<<1, l, mid);
        if(isSet[pos<<1|1] == 1) propSet(pos<<1|1, mid+1, r);
        
        int l1 = l, r1 = getIth(propl[pos], propr[pos], d, n);
        int l2 = getIth(propl[pos], propr[pos], d+1, n), r2 = r;
        
        
        cerr << "ps " << l << " " << r << " (" << d << ")" << endl;
        cerr << "psr " << l1 << " " << r1 << " = " << getSum(l1, r1, mid-l+1) << ", " << l2 << " " << r2 << " = " << getSum(l2, r2, r-mid) << endl;
        
        propl[pos<<1] += l1, propr[pos<<1] += r1;
        propl[pos<<1|1] += l2, propr[pos<<1|1] += r2;
        
        sum[pos<<1] += getSum(l1, r1, mid-l+1);
        sum[pos<<1|1] += getSum(l2, r2, r-mid);
        
        propl[pos] = propr[pos] = 0;
    }
    
    void updateSeries(int pos, int l, int r, int L, int R, bool isReverse) {
        if(r < L || R < l) return;
        propSet(pos, l, r);
        propSeries(pos, l, r);
        if(L <= l && r <= R) {
            cerr << l << " -- " << r << endl;
            int s, rr;
            if(!isReverse)  s = l-L+1, rr = l-L+1 + (r-l);
            else            rr = R-r+1, s = R-r+1 + (r-l);
            cerr << s << " to " << rr << " = " << getSum(s, rr, r-l+1) << endl;
            propl[pos] += s, propr[pos] += rr, sum[pos] += getSum(s, rr, r-l+1);
            return;
        }
        int mid = (l+r)>>1;
        updateSeries(pos<<1, l, mid, L, R, isReverse);
        updateSeries(pos<<1|1, mid+1, r, L, R, isReverse);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
        cerr << "sum " << l << " " << r << " = " << sum[pos] << endl;
    }
    /*
    void updateS2(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            int r = R-r+1, s = R-r+1 + (r-l);
            propl[pos] += s, propr[pos] += r, sum[pos] += getSum(s, r, r-l+1);
            return;
        }
        int mid = (l+r)>>1;
        updateS2(pos<<1, l, mid, L, R);
        updateS2(pos<<1|1, mid+1, r, L, R);
    }*/
    
    void updateSet(int pos, int l, int r, int L, int R, int val) {
        if(r < L || R < l) return;
        propSet(pos, l, r);
        propSeries(pos, l, r);
        if(L <= l && r <= R) {
            cerr << l << " -- " << r << " = " << val*(r-l+1) << endl;
            sum[pos] = val*(r-l+1);
            propSetVal[pos] = val, isSet[pos] = 1;
            return;
        }
        int mid = (l+r)>>1;
        updateSet(pos<<1, l, mid, L, R, val);
        updateSet(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
        cerr << "sum " << l << " " << r << " = " << sum[pos] << endl;
    }
    
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        propSet(pos, l, r);
        propSeries(pos, l, r);
        if(L <= l && r <= R) {
            cerr << "AT " << l << " " << r << " = " << sum[pos] << endl;
            return sum[pos];
        }
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
    }
};

SegTree ST;
int LIM = 10;

int main() {
    int t, l, r, x, q;
    char TT;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &q);
        ST.init();
        printf("Case %d:\n", Case);
        
        while(q--) {
            scanf(" %c %d %d", &TT, &l, &r);
            
            if(TT == 'A')
                ST.updateSeries(1, 1, LIM, l, r, 0);
            else if(TT == 'B')
                ST.updateSeries(1, 1, LIM, l, r, 1);
            else if(TT == 'S')
                printf("%lld\n", ST.query(1, 1, LIM, l, r));
            else {
                scanf("%d", &x);
                ST.updateSet(1, 1, LIM, l, r, x);
            }
        }
    }
    return 0;
}
