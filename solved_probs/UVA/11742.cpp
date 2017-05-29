//UVa
//11742 - Social Constraints

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
using namespace std;

int main()
{
    int n,m,a[20],b[20],con[20],perm[8],pos[8],i;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
            break;
        for(i=0;i<m;i++)
            scanf("%d %d %d",a+i,b+i,con+i);
        for(i=0;i<n;i++)
            perm[i]=i;
        int count = 0;
        int incr;
        do
        {
            for(i=0;i<n;i++)
                pos[perm[i]]=i;
            incr = 1;
            for(i=0;i<m && incr;i++)
                if((con[i]>0 && abs(pos[a[i]]-pos[b[i]])>con[i]) || (con[i]<0 && abs(pos[a[i]]-pos[b[i]])<-con[i]))
                    incr = 0;
            count+=incr;
        }while(next_permutation(perm,perm+n));
        printf("%d\n",count);
    }
    return 0;
}
