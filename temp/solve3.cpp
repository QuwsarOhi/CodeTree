#include <bits/stdc++.h>
using namespace std;
#define MAX                 20000
#define EPS                 1e-9
#define INF                 1e7
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

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

// Suffix Array
// Complexity : N log(N)

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}

int wa[MAX],wb[MAX],wws[MAX],wv[MAX];
int rank[MAX],height[MAX];

void DA(char str[], int *sa, int n, int m = 256){           // str, suff, len, max_ascii_val
    int i,j,p,*x=wa,*y=wb,*t;
    for(i = 0; i < m; i++) wws[i]=0;
    for(i = 0; i < n; i++) wws[x[i]=str[i]]++;
    for(i = 1; i < m; i++) wws[i]+=wws[i-1];
    for(i = n-1; i >= 0; i--) sa[--wws[x[i]]]=i;
    for(j=1, p = 1; p < n; j *= 2, m = p) {
        for(p = 0, i = n-j; i < n; i++) y[p++]=i;
        for(i = 0; i < n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i= 0; i < n; i++) wv[i]=x[y[i]];
        for(i= 0; i < m; i++) wws[i]=0;
        for(i= 0; i < n; i++) wws[wv[i]]++;
        for(i= 1; i < m; i++) wws[i]+=wws[i-1];
        for(i= n-1; i >= 0; i--) sa[--wws[wv[i]]]=y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
}}

void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n;
char str[N];
int lcp[N];
 
LL Deal (int p,int q)
{
    DA(data,sa,n+1,128);
    calheight(data,sa,n);
 
    //here rank said in which position a suffix is situated
    //in the sorted suffix list.
 
    //height gives the LCP of id && id-1
 
    //sa gives the sorted suffix indexes
 
    LL ans = 0;
 
    for (int i=1;i<=n;i++){
        int st,ed;
        int ltr = n-sa[i];
 
        if (ltr < p)    continue;
 
        st = height[i]+1;
        ed = ltr;
 
        st = max(st,p);
        ed = min(ed,q);
 
        //cout << height[i] << " & " << ltr << " so " << st << " to " << ed << endl;
 
        if (st <= ed)            ans += ed - st + 1;
    }
 
    return ans;
}
 */
char str[MAX];
int SA[MAX];

int main() {
    //fileRead("in");
    //fileWrite("out");

    int t, lo, hi, len;
    sf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        sf("%s%d%d", str, &lo, &hi);
        len = strlen(str);

       /* memset(idxToRank, 0, sizeof idxToRank);
        memset(lcp, 0, sizeof lcp);
        for(int i = 0; i < MAX; ++i)
            suff[i].idx = 0, suff[i].rank = mp(0, 0);*/


        DA(str, SA, len);
        //Kasai(len, str);

        //for(int i = 0; i < len; ++i)
        //    cerr << i << " : " << suff[i].idx << " = " << str+suff[i].idx << " " << lcp[suff[i].idx] << endl;

        for(int i = 0; i < len; ++i)
            cerr << i << " :: " << SA[i] << endl;

        //pf("Case %d: %d\n", Case, totUniqueSubstr(len, lo, hi));
    }
    return 0;
}