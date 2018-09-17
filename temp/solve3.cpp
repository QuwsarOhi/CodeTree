#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


struct MergeSortTree {
    vector<long>tree[MAX*4];

    void init(int pos, int l, int r, vector<long> &val) {
        tree[pos].clear();                              // Clears past values
        if(l == r) {
            tree[pos].push_back(val[l]);
            return;
        }

        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }

    int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) {
            //return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());
                 // MODIFY

           // cout<<"tree  k    "<<k<<endl;
       //     for(int i=0; i<(int)tree[pos].size(); i++) cout<<tree[pos][i]<<"   ";
        //    cout<<endl;

            int lb=lower_bound(tree[pos].begin(),tree[pos].end(),k)-tree[pos].begin();
            return lb;
         //   cout<<"TTT  "<<lb<<endl;
        }
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}};


vector<long>v, sum;
MergeSortTree MT;

int main() {
    long n, x;

    scanf("%ld%ld", &n, &x);

    v.resize(n+1);
    for(int i = 1; i <= n; ++i)
        scanf("%ld", &v[i]);

    sum.resize(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        sum[i] = v[i] + sum[i-1];
        //cerr << i << " :: " << sum[i] << endl;
    }

    MT.init(1, 1, n, sum);
    long ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += MT.query(1, 1, n, i, n, x+sum[i-1]);
        //cerr << "AT " << i << " :: " << x+sum[i]<< " = " << MT.query(1, 1, n, i, n, x+sum[i]) << endl;
        //ans += v[i] < t;
    }

    printf("%ld\n", ans);
    return 0;
}