//UVa
//573 - The Snail
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

using namespace std;

float H, U, D, F, place;
int day;



int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    wh(sf("%f %f %f %f", &H,&U, &D, &F) && H) {
        day = 0;
        place = 0;
        bool ok = 0;
        float m = (U*F)/100;
        wh(1) {
            ++day;
            if(U > 0)
                place += U;
            U -= m;
            if(place > H) {
                ok = 1;
                break;
            }
            place -= D;
            if(place < 0)
                break;
        }
        if(ok) pf("success on day %d\n", day);
        else pf("failure on day %d\n", day);
    }
    return 0;
}
