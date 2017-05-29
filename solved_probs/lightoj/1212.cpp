//LightOJ
//1212 - Double Ended Queue
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, n, q, x;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d%d", &n, &q);
        printf("Case %d:\n", Case);
        deque<int>dq;
        while(q--) {
            char a[20];
            scanf("%s", &a);
            if(!strcmp(a, "pushLeft")) {
                scanf("%d", &x);
                if(dq.size() < n) {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
                else
                    printf("The queue is full\n");
            }
            else if(!strcmp(a, "pushRight")) {
                scanf("%d", &x);
                if(dq.size() < n) {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
                else
                    printf("The queue is full\n");
            }
            else if(!strcmp(a, "popLeft")) {
                if(!dq.empty()) {
                    x = dq.front();
                    dq.pop_front();
                    printf("Popped from left: %d\n", x);
                }
                else
                    printf("The queue is empty\n");
            }
            else if(!strcmp(a, "popRight")) {
                if(!dq.empty()) {
                    x = dq.back();
                    dq.pop_back();
                    printf("Popped from right: %d\n", x);
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }
    return 0;
}
