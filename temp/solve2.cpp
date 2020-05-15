//Bismillahir-Rahmanir-Rahim (In The Name Of ALLAH)

//everything is long long

#include<bits/stdc++.h>
//#include<unordered_map>

using namespace std;

//... Define Section

#define   mem(a,val)		memset(a,val,sizeof(a))
#define   all(a)		    a.begin(),a.end()
#define   sz(A) 		    A.size()
#define   len(A)		    strlen(A)
#define   ff                first
#define   ss                second
#define   pb 			    push_back
#define   PI			    acos(-1.00)
#define   ll			    long long
#define   pii			    pair<ll,ll>
#define   READ 		        freopen("input.txt", "r", stdin)
#define   WRITE 		    freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(int i=a;i>=b;i--)
#define   sfll(a) 		    scanf("%lld",&a)
#define   sfll2(a,b) 		scanf("%lld %lld",&a,&b)
#define   sfll3(a,b,c) 	    scanf("%lld%lld%lld",&a,&b,&c)
#define   cs 			    printf("Case %lld: ",kk++)
#define   cn 			    printf("Case %lld:\n",kk++)
#define   pfll(a) 		    printf("%lld",a)
#define   nl			    printf("\n")
#define   done 		        printf("DONE\n")
#define   EPS			    1e-9
#define   MOD 			    1000000007
#define   MAX			    1e6
#define   fast 		        ios_base::sync_with_stdio(false);
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
//BitMask Section

#define   checkBit(S, j)    (S & (1 << j))
#define   setBit(S, j)      (S |= (1 << j))
#define   clearBit(S, j)    (S &= ~(1 << j))
#define   toggleBit(S, j)   (S ^= (1 << j))
#define   lowBit(S)         (S & (-S))
#define   setAll(S, n)      (S = (1 << n) - 1)
//Default Function

template<typename T>inline string Tostring(T a){ostringstream os("");os << a;return os.str();} //number to string
template<typename T>inline ll Tolong(T a){ll res;istringstream os(a);os>>res;return res;} //string to number
template< class T > inline T Bigmod(T n,T m,T mod){T ans=1,mult=n%mod;while(m){if(m & 1) ans=(ans*mult)%mod;m>>=1;mult=(mult*mult)%mod;}ans%=mod;return ans;}//Big Mod (A^B)%M
template< class T > inline T Modinv(T x,T mod){return Bigmod(x,(T) mod-2,mod)%mod;} // Modular Inverse (A/B=A^(-B))%M
template<typename T>inline vector<int> Parse(T str){vector<int> res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}//string to vector
template< class T > inline T Lcm(T x,T y){return x*y/__gcd(x,y);}//LCM (a*b)/gcd(a,b)
template<typename T> inline T pwr(T b, T p) {T res  = 1;while(p > 0) {if(p&1) {res *= b ;}b *= b;p >>= 1;}return res ;}//power a^b
template <typename T>inline vector< T > Unique(vector< T > v) {sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()),v.end());return v;}// 1 2 1 3 = 1 2 3 (vector)


//Direction Array

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//Running Time

clock_t begn,ed;
double time_spent;
#define   timestart()		begn=clock()
#define   timestop()		ed=clock()
void      timelimit()		{time_spent = (double)(ed - begn) / CLOCKS_PER_SEC;cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;}
// start coding
map<string,set<int>>boilaCheck;
int cnt = 1;
string substring(string s,int a,int b,int pos)
{
    string s1="";
    for(int i = a; i < b; i++){
        s1 = s1 + s[i];
    }
    return s1;
}
int vis[101];
int allPalindromeSubstring(string s)
{
    int cnt  = 0;
    for (float pivot = 0; pivot < s.length();
                                 pivot += .5)
    {
        float palindromeRadius = pivot -
                                  (int)pivot;
        while ((pivot + palindromeRadius)
         < s.length() && (pivot - palindromeRadius)
         >= 0 && s[((int)(pivot - palindromeRadius))]
             == s[((int)(pivot + palindromeRadius))])
        {
            cnt++;
            palindromeRadius++;
        }
    }

    return cnt;
}
ll HASH[101];
ll power[101];
ll prime = 57;
ll prefix[101];
ll suffix[101];
ll tree[10001];
void build(int index,int l,int r)
{
    if(l==r)
    {
        tree[index] = vis[l];
        return;
    }
    int mid =(l+r)/2;
    int lft = index<<1;
    int rgt = lft+1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    tree[index] = max(tree[lft],tree[rgt]);
}
int query(int index,int l,int r,int L,int R)
{
    if(R<l || L>r)return 0;
    if(L<=l && r<=R)return tree[index];
    int mid =(l+r)/2;
    int lft = index<<1;
    int rgt = lft+1;
    int p1 = query(lft,l,mid,L,R);
    int p2 = query(rgt,mid+1,r,L,R);
    return max(p1,p2);
}
void calculatePower()
{
    power[0]=1;
    for(int i=1; i<101; i++)
    {
        power[i] = (power[i-1]%MOD*prime)%MOD;
    }
}
int index(char ch)
{
    return (int)ch;
}
void calculateHash(string &s)
{
    HASH[0] = 0;
    HASH[1] = s[0];
    for(int i=2; i<=s.size(); i++)
    {
        HASH[i] = ( HASH[i-1] % MOD + ( power[i-1] * index(s[i-1]) % MOD ) %MOD ) % MOD;
    }
}
ll calculateHashForFree(string &s)
{
    ll Hash = s[0];
    for(int i=2; i<=s.size(); i++)
    {
        Hash = ( Hash % MOD + ( power[i-1] * s[i-1] % MOD )%MOD ) % MOD;
    }
    return Hash;
}
void computePrefixHash(string str, int n)
{
    prefix[0] = 0;
    prefix[1] = str[0];

    for (int i=2; i<=n; i++){
        prefix[i] = (prefix[i-1]%MOD + (str[i-1]%MOD * power[i-1]%MOD)%MOD)%MOD;
    }

    return;
}
void computeSuffixHash(string str, int n)
{
    suffix[0] = 0;
    suffix[1] = str[n-1];

    for (int i=n-2, j=2; i>=0 && j<=n; i--,j++)
        suffix[j] = (suffix[j-1]%MOD + (str[i]%MOD * power[j-1]%MOD)%MOD)%MOD;
    return;
}
bool isPalindrome(string str, int L, int R)
{
    // Keep comparing characters while they are same
    while (R > L)
        if (str[L++] != str[R--])
            return(false);
    return(true);
}
int main()
{
    calculatePower();
    ll n,q;
    while(sfll2(n,q)!=EOF)
    {
        cnt = 1;
        string s;
        cin>>s;
        memset(vis,0,sizeof vis);
        memset(HASH,0,sizeof HASH);
        calculateHash(s);
        computePrefixHash(s,n);
        computeSuffixHash(s,n);
        int queryPlainDrome = 0;
        while(q--)
        {
            string S;
            cin>>S;
            ll newHash = calculateHashForFree(S);
            //cout<<newHash<<endl;
            for(int i=0; i<=n-S.size(); i++)
            {
                int l = i;
                int r = i+S.size()-1;
                l++;
                r++;
                ll currHASH = (((HASH[r]-HASH[l-1]+MOD)%MOD+MOD)%MOD*Modinv(power[l-1],(ll)MOD)%MOD)%MOD;
                //cout<<currHASH<<" ";
                if(currHASH == newHash)
                {
                    vis[r]=max(vis[r],l);
                }
            }
            //cout<<endl;
        }
        build(1,1,n);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                int  L = i;
                int  R = j;
                //cout<<s.substr(L,R)<<endl;
                ll LR = ((prefix[R+1]-prefix[L]+MOD)%MOD * Modinv(power[L],(ll)MOD)%MOD)%MOD;
                ll RL = ((suffix[n-L]-suffix[n-R-1]+MOD)%MOD * Modinv(power[n-R-1],(ll)MOD)%MOD)%MOD;

                if(LR == RL)
                {
                   if(query(1,1,n,L+1,R+1)<L)
                   ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}