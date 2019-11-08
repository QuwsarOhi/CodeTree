 #include <bits/stdc++.h>
 
#define vpii vector< pair<int,int> >
#define vi vector<int>
 
#define for0(i,a) for(int i=0;i<a;i++)
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 2020
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
 
#define maxp 3
#define p1 31
#define p2 51
using namespace std;

long long power[maxp + 2];
long long mod1 = 1e9+9,mod2=1e9+7;
ll cum[maxl +2][maxl + 2];
int r1, c1, r2, c2;

void Power_generate()
{
    power[0]=1;
    for(long long i=1; i<=maxp; i++)
    {
        power[i]= ((power[i-1])*p1 )%mod1;
    }
}

long long Hashing(string s[maxl + 2], int r, int c) {
    memset(cum, 0, sizeof cum);
    for(int i = 0; i < r; i++){
        ll value = 0;
        for(int j = 0; j < c; j++){
            int temp = (s[i][j] - 'a') + 1;
            value = (value + (temp * power[i])) % mod1;
            cum[i + 1][j + 1] = value;
        }
    }
    for(int j = 0; j < c; j++) {
        ll value = 0;
        for(int i = 0; i < r; i++){
            int temp = cum[i + 1][j + 1];
            value = ( value + (temp * power[i]) ) % mod1;
            cum[i + 1][j + 1] = value;
        }
    }
    return cum[r][c];
}


bool Check(int si, int sj, int ei, int ej, ll value){

  //  cout<<"S  "<<si<<"  "<<sj<<"  "<<ei<<"  "<<ej<<"   "<<value<<"   "<<cum[ei][ej]<<endl;

    ll ans = ( (cum[ei][ej] - cum[ei - r1][ej] - cum[ei][ej - c1] + cum[ei - r1][ej - c1] ) + mod1 ) % mod1;

  //  cout<<"CC   "<<cum[ei - r1][ej] <<"   "<<cum[ei][ej - c1] <<"      "<<cum[si - 1][sj - 1]<<endl;
    ans = (ans + mod1) % mod1;
     
    // cout<<"W  "<<ans<<endl;
    ll po = ( maxp - (si - 1) );
    ll po1 = ( maxp - (sj - 1) );

 //   cout<<"P  "<<po<<"  "<<po1<<endl;
    ans = ( ans * power[po]) % mod1;
    ans = ( ans * power[po]) % mod1;

  //  cout<<"A  "<<ans<<"  "<<value<<endl;
    if(ans == value) return true;
    return false;
}

int main()
{
    Power_generate();
    string s1[maxl + 2];
    cin >> r1 >> c1;

    for(int i = 0; i < r1; i++){
        cin >> s1[i];
    }

    ll pattern = Hashing(s1, r1, c1);
   // cout<<"P "<<pattern<<endl;
    pattern = (pattern * power[maxp]) % mod1;
    pattern = (pattern * power[maxp]) % mod1;

    cin >> r2 >> c2;

    for(int i = 0; i < r2; i++){
        cin >> s1[i];
    }
    Hashing(s1, r2, c2);
    vector<pii>v;

    for(int i = 1; i <= r2; i++){
        for(int j = 1; j <= c2; j++){

            if(i >= r1 && j >= c1){

                if(Check(i - r1 + 1, j - c1 + 1, i, j, pattern)){
                    v.pb(mk(i - r1 + 1, j - c1 + 1));
                }
            }

        }
    }

    for(int i = 0; i < v.size(); i++){
        cout<<"("<<v[i].f<<","<<v[i].s<<")"<<endl;
    }

    return 0;
}
