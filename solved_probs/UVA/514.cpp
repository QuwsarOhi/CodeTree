//UVa
//514 - Rails
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
#define N 20000000

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, t, x, i;
    char a[1000000];
    int d[1010];
    //bool first = 1;
    wh(sf(" %d", &t) && t) {
        bool skip = 0;
        //if(!first) pf("\n");
        //first = 0;
        wh(1) {
            sf( " %[^\n]", a);
            ss s;
            s << string(a);
            i = -1;
            wh(s >> x) {
                if(x > 0) {
                    d[++i]=x;
                    //if(x == n) p = i-1;
                }
                else {
                    //pf("zero\n");
                    pf("\n");
                    skip = 1;
                    break;
                }
            }
            if(skip) break;
            n = t;
            stack<int>st;
            //pf("i is %d\n", i);
            st.push(d[i--]);
            wh(1) {
                if(!st.empty() && st.top() == n) {
                    //pf("popping %d\n", st.top());
                    st.pop();
                    n--;
                }
                else {
                    if(i == -1) break;
                    st.push(d[i--]);
                    //pf("pushing %d\n", st.top());
                }
                //pf("i is %d\n", i);
            }
            if(st.empty())
                pf("Yes\n");
            else
            {
                pf("No\n");
                /*pf("size : %d\n", st.size());
                wh(!st.empty()) {
                    pf("%d\n", st.top());
                    st.pop();
                }*/
            }
        }
    }
    return 0;
}
