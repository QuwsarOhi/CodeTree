#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[50];
vector<ll>ans;

void F() {
    f[1] = 0;
    f[2] = 1;
    f[3] = 2;
    for(int i = 4; i < 50; ++i)
        f[i] = f[i-1] + f[i-2];
}

int main() {
    ll s, k;
    
    cin >> s >> k;
    F();
    
    for(int i = 49; i > 0; --i)
        if(f[i] <= s && s >= 0) {
            ans.push_back(f[i]);
            s -= f[i];
        }
    
    cout << ans.size() << endl;
    for(auto it : ans)
        cout << it << " ";
    cout << endl;
    
    return 0;
}
