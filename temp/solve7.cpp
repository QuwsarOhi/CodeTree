
#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<stack>
#include<string>  
#include<ctime>
#include<queue>  
#include<cassert>
#define inf 1000000005  
#define M 10000005 
#define N 110005
#define maxn 210005  
#define eps 1e-8
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
int n,q,a[N];
int T[N],tot,lson[M],rson[M],lazy[M],mark[M];
LL sum[M];
void push_up(int root){
    sum[root]=sum[lson[root]]+sum[rson[root]];
}
void push_down(int root,int l,int r){
    if(mark[root]){
        sum[tot]=sum[lson[root]];
        lazy[tot]=lazy[lson[root]];
        lson[tot]=lson[lson[root]];
        rson[tot]=rson[lson[root]];
        lson[root]=tot++;
        sum[tot]=sum[rson[root]];
        lazy[tot]=lazy[rson[root]];
        lson[tot]=lson[rson[root]];
        rson[tot]=rson[rson[root]];
        rson[root]=tot++;
        mark[lson[root]]=mark[rson[root]]=1;
        mark[root]=0;
    }
    if(lazy[root]){
        int m=(l+r)>>1;
        lazy[lson[root]]+=lazy[root];
        lazy[rson[root]]+=lazy[root];
        sum[lson[root]]+=(LL)lazy[root]*(m-l+1);
        sum[rson[root]]+=(LL)lazy[root]*(r-m);
        lazy[root]=0;
    }
}
int bulid(int l,int r){
    int root=tot++;
    lazy[root]=mark[root]=0;
    if(l==r){
        sum[root]=a[l];
        return root;
    }
    int m=(l+r)>>1;
    lson[root]=bulid(l,m);
    rson[root]=bulid(m+1,r);
    push_up(root);
    return root;
}
int update(int root,int L,int R,int l,int r,int val){
    int newroot=tot++;
    if(L==l&&R==r){
        lazy[newroot]=lazy[root]+val;
        sum[newroot]=sum[root]+(LL)val*(r-l+1);
        if(l!=r){
            lson[newroot]=lson[root];
            rson[newroot]=rson[root];
            mark[newroot]=1;
        }
        return newroot;
    } 
    lazy[newroot]=0;
    sum[newroot]=0;
    mark[newroot]=0;
    push_down(root,L,R);
    int m=(L+R)>>1;
    if(r<=m){
        lson[newroot]=update(lson[root],L,m,l,r,val);
        rson[newroot]=rson[root];
    }
    else if(l>m){
        lson[newroot]=lson[root];
        rson[newroot]=update(rson[root],m+1,R,l,r,val);
    }
    else{
        lson[newroot]=update(lson[root],L,m,l,m,val);
        rson[newroot]=update(rson[root],m+1,R,m+1,r,val);
    }
    push_up(newroot);
    return newroot;
}
LL query(int root,int L,int R,int l,int r){
    if(L==l&&R==r) return sum[root];
    push_down(root,L,R);
    int m=(L+R)>>1;
    if(r<=m) return query(lson[root],L,m,l,r);
    else if(l>m) return query(rson[root],m+1,R,l,r);
    else return (LL)query(lson[root],L,m,l,m)+query(rson[root],m+1,R,m+1,r);
}
void debug(int root,int l,int r){  
    cout<<l<<" "<<r<<" "<<sum[root]<<endl; 
    push_down(root,l,r); 
    if(l!=r){  
        int m=(l+r)>>1;  
        debug(lson[root],l,m);  
        debug(rson[root],m+1,r);  
    }  
}  
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&n,&q)!=EOF){
        tot=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        T[0]=bulid(1,n);
        int Time=0;
        while(q--){
            char str[5];
            scanf("%s",str);
            int l,r,k;
            if(str[0]=='Q'){
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(T[Time],1,n,l,r));
            }
            else if(str[0]=='H'){
                scanf("%d%d%d",&l,&r,&k);
                printf("%lld\n",query(T[k],1,n,l,r));
            }
            else if(str[0]=='C'){
                scanf("%d%d%d",&l,&r,&k);
                T[Time+1]=update(T[Time],1,n,l,r,k);
                Time++;
            }
            else{
                scanf("%d",&k);
                Time=k;
            }
        }
    }
    return 0;
}
