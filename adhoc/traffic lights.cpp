//UVa
//161 - Traffic Lights
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long

struct post {
    int red;
    int timer;
    int green;
    int yellow;
    bool state; // 1 for green
}post[110];

void calc(int i, int n)
{
    post[i].red = n;
    post[i].green = n - 5;
    post[i].yellow = 5;
    post[i].timer = 0;
    post[i].state = 1; //green initialized;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    ll n, i, j, k;
    bool brk = 0;
    wh(1) {
        for(i = 0; ;i++) {
            sf(" %lld", &n);
            if(i == 0 && n == 0) {
                brk = 1;
                break;
            }
            if(n == 0) break;
            calc(i, n);
        }
        bool first = 1, inft = 0;
        if(brk) break;
        for(j = 1; ; j++) {
            bool found = 1;
            for(k = 0; k < i; k++) {
                ++post[k].timer;
                if(post[k].timer == post[k].green +1)
                    post[k].state = 0;
                else if(post[k].timer == 2*post[k].red)
                    post[k].timer = 0;
                else if(post[k].timer <= post[k].green)
                    post[k].state = 1;
                else if(post[k].timer >= post[k].green+5)
                    post[k].state = 0;
                if(post[k].state == 0 && first)
                    first = 0;
                if(post[k].state == 0)
                {
                    //pf("breaking for post %d state %d\n", k, post[k].state);
                    found = 0;
                }
                if(first)
                    found = 0;
                //pf("post : %d, time : %d, state: %d\n", k, j, post[k].state);
            }
            if(found && !first) {
                //pf("Breaking\n");
                break;
            }
            if(j > 18000) {
                inft = 1;
                break;
            }
        }
        if(inft) {
            pf("Signals fail to synchronise in 5 hours\n");
            continue;
        }
        --j;
        ll m, h, s;
        s = j % 60;
        m = j / 60;
        h = m / 60;
        m = m%60;
        pf("%02lld:%02lld:%02lld\n",h, m ,s);
    }
    return 0;
}
