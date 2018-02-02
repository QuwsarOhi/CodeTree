#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop pop_back()
#define ll long long
#define sz size()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
///////////////////////////////////////////
int n;
int a[200200];
int lef[200200];
int righ[200200];
int main(){
    freopen("in", "r", stdin);
    speed
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        a[i]=x;
    }
    string s;
    cin>>s;

    for(int i=1;i<n;i++){
        if(s[i-1]=='1') lef[i] = lef[i-1]+1;
        else lef[i]=0;
    }

    for(int i=n-2;i>=0;i--){
        if(s[i]=='1') righ[i] = righ[i+1]+1;
        else righ[i]=0;
    }
    bool ok=0;

    for(int i=0;i<n;i++){
        if(a[i]>0){
            if(righ[i]<a[i]-i) ok=1;
        }
        if(a[i]<=0){
            if(lef[i]<i-a[i]) ok=1;
        }
    }
    if(!ok) cout<<"YES";
    else cout<<"NO";
}
