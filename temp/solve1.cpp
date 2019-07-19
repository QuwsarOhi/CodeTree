#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

int st[100009], ed[100009];

int main() {
    int t;
    cin >> t;

    string s;
    while(t--) {
        cin >> s;

        for(int i = 0; i < s.size(); ++i) {
            st[i] = (i > 0) ? st[i-1]:0;
            st[i] += (s[i] == '(');
        }

        for(int i = (int)s.size()-1; i >= 0; --i) {
            ed[i] = ed[i+1];
            ed[i] += (s[i] == ')');
        }

        ll ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            //cerr << st[i] << " " << ed[i] << endl;
            ans = max(ans, (ll)min(st[i], ed[i]));
        }

        cout << ans*2 << endl;
    }
    
    return 0;
}


/*

3
(()())
(()(()))
()()()()()

*/