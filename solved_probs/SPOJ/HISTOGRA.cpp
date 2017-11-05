// SPOJ
// HISTOGRA - Largest Rectangle in a Histogram

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    ll n, h[100100];
    while(scanf("%lld", &n) && n != 0) {
        for(ll i = 0; i < n; ++i)
            scanf("%lld", &h[i]);
        
        stack<ll>st;
        ll i = 0, MaxArea = 0;
        while(i < n) {
            if(st.empty() || h[st.top()] <= h[i])
                st.push(i++);
            else {
                ll minHight = st.top();
                st.pop();
                MaxArea = max(MaxArea, h[minHight] * (st.empty() ? i : (i-st.top()-1)));
            }
        }
        
        while(!st.empty()) {
            ll minHight = st.top();
            st.pop();
            MaxArea = max(MaxArea, h[minHight] * (st.empty()? i : (i-st.top()-1)));
        }
        
        printf("%lld\n", MaxArea);
    }
    return 0;
}
