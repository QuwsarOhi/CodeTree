// 897C - Nephren gives a riddle
// http://codeforces.com/problemset/problem/897/C

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string str1 = "What are you doing while sending \"";
string str2 = "\"? Are you busy? Will you send \"";
string str3 = "\"?";

ull sz[100010];

char recur(ull n, ull k) {
    //cout << n << " " << k << endl;
    if(n == 0) {        // Base Case
        if(k <= f0.size())
            return f0[k-1];
        return '.';
    }
    
    if(k > str1.size())
        k -= str1.size();
    else
        return str1[k-1];
    //cout << "str1" << endl;
    if(sz[n-1] >= k)        //recur
        return recur(n-1, k);
    else
        k -= sz[n-1];
    
    //cout << "f0" << endl;

    //if(k > f0.size())
    //    k -= f0.size();
    //else
    //    return f0[k];
    
    if(k > str2.size())
        k -= str2.size();
    else
        return str2[k-1];
        
    //cout << "str2" << endl;

    if(sz[n-1] >= k)        //recur
        return recur(n-1, k);
    else
        k -= sz[n-1];
    
    //cout << "f0" << endl;
    
    if(k > str3.size())
        k -= str3.size();
    else
        return str3[k-1];
    
    return '.';
}
    

int main() {
    //fileRead("in");
    //cout << str1 + f0 + str2 + f0 + str3 << endl;
    sz[0] = f0.size();
    //cout << f0.size() << " " << str1.size() << " " << str2.size() << " " << str3.size() << endl;
    for(int i = 1; i <= 100000; ++i) {
        sz[i] = str1.size() + sz[i-1] + str2.size() + sz[i-1] + str3.size();
        //cout << i << " : " << sz[i] << " " << (int)log10(sz[i])+1 << endl;
    }
    
    ull t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        //cout << "-------------------------------------- " << n << "  ====  " << k << endl;
        //if(n <= 50)
            cout << recur(n, k);
        //else
            //cout << recur(n%50, k);
    }
    
    cout << endl;
    return 0;
}
