// LightOJ
// 1039 - A Toy Company
// http://lightoj.com/volume_showproblem.php?problem=1039

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;


map<string, bool>visited, notVisit;

char nextS(char x) {
    if(x + 1 > 'z')
        return 'a';
    return x+1;
}

char prevS(char x) {
    if(x - 1 < 'a')
        return 'z';
    return x-1;
}

int main() {
    int t, n, ans;
    string start, finish, x, y, z;
    FIO;
    cin >> t;
    fr(Case, 1, t+1) {
        ans = -1;
        visited.clear();
        notVisit.clear();
        cin >> start;
        cin >> finish;
        
        cin >> n;
        while(n--) {
            cin >> x >> y >> z;
            fr(i, 0, x.size()) 
                fr(j, 0, y.size())
                    fr(k, 0, z.size()) {
                        string t;
                        t += x[i], t +=y[j], t += z[k];
                        notVisit[t] = 1;
                        //dbug(t);
                    }
        }
        
		if(notVisit[start]) {
            cout << "Case " << Case << ": " << ans << endl;
            continue;
        }
        if(start == finish)
            ans = 0;
        
        queue<pair<string, int> >q;
        q.push({start, 0});
        visited[start] = 1;
        //dbug(notVisit.size());
        while(!q.empty() && ans == -1) {
            string t = q.front().fi;
            int cnt = q.front().se;           
            q.pop();
            
            fr(i, 0, 3) {
                string n = t;
                n[i] = nextS(n[i]);
                if(!visited[n] && !notVisit[n]) {
                    visited[n] = 1;
                    if(n == finish) {
                        //cout << "ans : " << n << endl;
                        ans = cnt+1;
                        break;
                    }
                    //dbug(n);
                    q.push({n, cnt+1});
                }
                n = t;
                n[i] = prevS(n[i]);
                if(!visited[n] && !notVisit[n]) {
                    visited[n] = 1;
                    if(n == finish) {
                        //cout << "ans : " << n << endl;
                        ans = cnt+1;
                        break;
                    }
					//dbug(n);
                    q.push({n, cnt+1});
                }
            }
        }
        
        cout << "Case " << Case << ": " << ans << endl;
    }
    return 0;
}
