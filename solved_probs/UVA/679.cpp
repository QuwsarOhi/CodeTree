//UVa
//679 - Dropping Balls
#include<bits/stdc++.h>
using namespace std;

int d, l, t, ans, leaf;

void recurse(int node, int balls)
{
    //printf("node : %d, balls : %d\n", node, balls);
    if(node >= leaf)
        return;
    ans = node;
    if(balls % 2 != 0)
        recurse(node * 2, (balls/2)+1);
    else
        recurse((node*2)+1, balls/2);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &d, &l);
        leaf = 1 << d;
        recurse(1, l);
        printf("%d\n", ans);
    }
    scanf("%d", &t);
    return 0;
}
