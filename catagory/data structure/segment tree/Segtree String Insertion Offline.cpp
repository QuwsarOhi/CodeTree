// Codechef
// https://www.codechef.com/problems/TAEDITOR
// Simple Editor

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define MAX                 200100
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

vector<pair<int, char> >Insert;
vector<pair<int, int> >Query;
ordered_set<int>Position;
char Output[310000];

int main() {
    int q, sz = 0, idx, len;
    char typ;
    string str;
    
    cin >> q;
    
    for(int i = 0; i < q; ++i) {
        cin >> typ;
        
        if(typ == '+') {
            cin >> idx >> str;
            for(auto it : str) {
                Insert.push_back({idx++, it});
                ++sz;
            }
        }
        else {
            cin >> idx >> len;
            while(len--) {
                if(len == 0) 
                    Insert.push_back({idx++, '*'});
                else
                    Insert.push_back({idx++, '?'});
            }
        }
    }
    
    for(int i = 0; i < sz; ++i)
        Position.insert(i);
    
    for(auto it = Insert.rbegin(); it != Insert.rend(); ++it) {
        if(it->second == '?' || it->second == '*') {
            it->first = *Position.find_by_order(it->first-1);
            continue;
        }
        int pos = *Position.find_by_order(it->first); 
        Output[pos] = it->second;
        Position.erase(Position.find_by_order(it->first));
    }
    
    
    for(auto it : Insert) {
        if(it.second == '?')
            cout << Output[it.first];
        else if(it.second == '*')
            cout << Output[it.first] << "\n";
    }
    
    return 0;
}
    
