#include<bits/stdc++.h>
#define i64 long long

using namespace std;

int arr[100005];
int pos[1000005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", arr+i);
        pos[arr[i]] = true;
    }
    int f = 1, l = 1000000;
    int cnt = 0;
    int sc = 0;
    for(int i=1; i<=1000000 ; i++){
        if(pos[f]) cnt++;
        if(cnt==n) break;
        if(pos[l]) cnt++;
        if(cnt==n) break;
        f++; l--;
        sc++;
    }
    
    printf("%d\n", sc);
    main();
}
