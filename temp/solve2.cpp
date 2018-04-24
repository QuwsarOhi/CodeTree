#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)
#define MAX 100005

#define PR 52477425
#define MOD 1000075057

long long hashval[MAX],pwr[MAX];
int n,ara[MAX];

int calc_hash(int l,int r)
{
    long long ret=hashval[r+1];
    ret*=pwr[r-l+1];
    ret%=MOD;
    return (hashval[l]-ret+MOD)%MOD;
}

void precal_hash(void)
{
    int i;
    pwr[0]=1;
    for(i=1;i<MAX;i++){
        pwr[i]=pwr[i-1]*PR;
        pwr[i]%=MOD;
    }
    for(i=n-1;i>=0;i--){
        hashval[i]=hashval[i+1]*PR;
        hashval[i]+=ara[i];
        hashval[i]%=MOD;
    }
}

map<int,vector<int> > allpos;

int main()
{
    freopen("out","r",stdin);
    freopen("in", "w", stdout);
    int i,j;
    si(n);
    for(i=0;i<n;i++){
        si(ara[i]);
        allpos[ara[i]].push_back(i);
    }
    
    int mx = -1;
    for(auto it : allpos) mx = max(mx, (int)it.second.size());
    
    cout << "MAX " << mx << " " << allpos.size() << endl;
    
    precal_hash();
    
    cout << "PRECAL DONE\n";
    
    long long CNT = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
    for(map<int,vector<int> >::iterator it=allpos.begin();it!=allpos.end();it++){
        vector<int> ttt=(it->s);
        cout << it->f << " " << ttt.size() << endl;
        for(i=0;i<ttt.size();i++){
            for(j=i+1;j<ttt.size();j++){
                int l=ttt[i],r=ttt[j];
                CNT++;
                cout << "Boundary " << l << " " << r << " CNT " << CNT << endl;
                if(r+r-l-1<n && calc_hash(l,r-1)==calc_hash(r,r+r-l-1)) {
                    cout << "PB " << l << " " << r << endl;
                    Q.push(mp(r-l,l));
                }
            }
        }
    }
    
    cout << "PAIR DONE " << CNT << endl;
    
    int st=0;
    while(!Q.empty()){
        pair<int,int> now=Q.top();
        Q.pop();
        if(now.s<st)continue;
        st=now.s+now.f;
    }
    printf("%d\n",n-st);
    for(i=st;i<n;i++)printf("%d ",ara[i]);
    printf("\n");
    return 0;
}
