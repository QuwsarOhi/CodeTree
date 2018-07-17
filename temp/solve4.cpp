#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> a(100005);
vector<ll> dist(100005,0);
vector<ll> p(100005,-1);
vector<ll> c(100005,1);
vector<ll> blocked(100005,0);

pii parent(ll x)
{
	if(p[x]==-1)
		return mp(x,dist[x]);

	pii tmp=parent(p[x]);
    
	if(blocked[p[x]]==1 || blocked[x]==1)
		blocked[x]=1,blocked[p[x]]=1;
	else
		dist[x]=(tmp.second+dist[x]);

	p[x]=tmp.first;
	
    cout << "AT " << x << " " << p[x] << " " << dist[x] << endl;
    return mp(p[x],dist[x]);
}

void dsu(ll v1,ll v2)
{
	ll x1=parent(v1).first;
	ll x2=parent(v2).first;
	//if(x1==x2)
	//{
	//	if((dist[v1]+dist[v2])%2==0)
	//		blocked[x1]=1;
	//}
	//else
	//{
		if(blocked[x1]==1 || blocked[x2]==1)
		{
			blocked[x1]=1;
			blocked[x2]=1;
		}
		if(c[x1]<c[x2])
		{
			p[x1]=x2;
			c[x1]+=c[x2];
			dist[x1]=(dist[v1]+dist[v2]+1);
		}
		else
		{
			p[x2]=x1;
			c[x2]+=c[x1];
			dist[x2]=(dist[v1]+dist[v2]+1);
		}
	//}
	return;
}


int main() {
    while(1) {
        int u, v, t;
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            dsu(u, v);
        
            for(int i = 1; i < 5; ++i)
                cout << p[i] << " ";
            cout << endl;
            for(int i = 1; i < 5; ++i)
                cout << c[i] << " ";
            cout << endl;
            for(int i = 1; i < 5; ++i)
                cout << dist[i] << " ";
            cout << endl;
        }
        else {
            cin >> u;
            pii x = parent(u);
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}
