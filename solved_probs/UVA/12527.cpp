//UVa
//12527 - Different Digits
#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pf printf
#define sf scanf
#define wh while

using namespace std;

int main()
{
    register int n, m, cnt, tmp, chk[10], x;
    bool ok;
    while(sf("%d %d", &n, &m) != EOF)
    {
        cnt = 0;
        fr(i, n, m+1)
        {
            ok = true;
            //pf("num  = %d\n", i);
            memset(chk, 0, sizeof(chk));
            x = i;
            while(x)
            {
                tmp = x%10;
                x/=10;
                //pf("%d ", tmp);
                if(!chk[tmp]) chk[tmp] = 1;
                else
                {
                    ok = false;
                    break;
                }
            }
            //pf("\n");
            if(ok) cnt++;
        }
        pf("%d\n", cnt);
    }
    return 0;
}
