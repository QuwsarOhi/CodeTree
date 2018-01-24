#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#define oo (1<<30)
using namespace std;


struct Node {
	int sum;
	Node *lch,*rch;
	Node() {
		lch=rch=NULL;
		sum=0;
	}
};

inline Node *duplicate(Node *x) {
	Node *ret=new Node();
	if(x)
	{
		ret->sum=x->sum;
		ret->lch=x->lch;
		ret->rch=x->rch;
	}
	return ret;
}

#define getsum(x) (x?x->sum:0)
#define update(x) x->sum=getsum(x->lch)+getsum(x->rch)

void modify(Node *now,int l,int r,int p,int v) {
	if(l==r) {
		now->sum+=v;
		return;
	}
    
	int mid=(l+r)>>1;
	
    if(p<=mid) {
		now->lch=duplicate(now->lch);
		modify(now->lch,l,mid,p,v);
	}
	else {
		now->rch=duplicate(now->rch);
		modify(now->rch,mid+1,r,p,v);
	}
    
	update(now);
}

int query(Node *now,int l,int r,int ql,int qr) {
	if(!now||r<ql||l>qr)
		return 0;
        
	if(ql<=l&&r<=qr)
		return now->sum;
	
    int mid=(l+r)>>1;
	
    return query(now->lch,l,mid,ql,qr)+query(now->rch,mid+1,r,ql,qr);
}


Node *value[101010],*ps[101010];
char op[11];
char name[20];
map<string,int> id;
int cnt=0;

inline int getid(const char *s) {
	if(id.count(s))
		return id[s];
	id[s]=++cnt;
	return cnt;
}


int main() {
    freopen("in", "r", stdin);
	int q;
	scanf("%d",&q);
    
    
    
	for(int i=1;i<=q;i++) {
		scanf("%s",op);
		
        if(op[0]=='u') {
			int x;
			scanf("%d",&x);
			value[i]=duplicate(value[i-x-1]);
			ps[i]=duplicate(ps[i-x-1]);
			continue;
		}
        
		value[i]=duplicate(value[i-1]);
		ps[i]=duplicate(ps[i-1]);
		scanf("%s",name);
		int nid=getid(name);
		int origin=query(value[i],1,q,nid,nid);
        printf("nid %d : origin %d\n", nid, origin);
		
        // ps : presistant segment tree
        // value : unknown
        
        if(op[0]=='s') {
			int x;
			scanf("%d",&x);
			if(origin)                  // removing the priority from value 
				modify(ps[i],0,oo,origin,-1);
			
            modify(ps[i],0,oo,x,1);     // adding the string in priority position
            
			modify(value[i],1,q,nid,x-origin);      // change in value, indx : nid, value x-origin
            printf("added in value[%d] : pos %d : val : %d\n", i, nid, x-origin);
			continue;
		}
        
		else if(op[0]=='r') {
			if(origin)
				modify(ps[i],0,oo,origin,-1);
			modify(value[i],1,q,nid,-origin);
			continue;
		}
        
		if(origin==0)
			puts("-1");
		
        else {
			printf("%d\n",query(ps[i],0,oo,0,origin-1));
        }
		
        fflush(stdout);
	}
	return 0;
}
