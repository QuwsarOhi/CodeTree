//LightOJ
//1080 - Binary Simulation
//Segment Tree

#include <bits/stdc++.h>
#define MAX 100010;
using namespace std;

bitset<400010>toggle;
bitset<100010>N;

//Toggle bit in range of [l, r]
//update(1, 1, length_of_input, l, r)
void update(int pos, int L, int R, int l, int r) {   // Lazy without propagation
    if(l <= L && R <= r) {
        toggle[pos].flip();
        return;
    }

    if(r < L || R < l)
        return;

    int mid = (L+R)/2;

    update(pos*2, L, mid, l, r);
    update((pos*2) + 1, mid+1, R, l, r);
}

//Check bit in q_pos
//query(1, 1, length_of_input, q_pos)
bool query(int pos, int L, int R, int q_pos) {      //q_pos is the desired position
    //return false if q_pos is out of [L, R]
    //else return the q_pos value

    if(L == R && L == q_pos)        //L == R == q_pos
        return toggle[pos];
    if(L == R && L != q_pos)        //L == R != q_pos
        return false;

    int mid = (L+R)/2;
    bool x;

    if(q_pos <= mid)                //if q_pos <= mid, then it should be in this segment
        x = query(pos*2, L, mid, q_pos);
    else                            //otherwise it is in this segment
        x = query(pos*2 + 1, mid+1, R, q_pos);

    if(q_pos < L || R < q_pos)      //[L, R] is out of range
        x ^= false;
    if(L <= q_pos && q_pos <= R)    //[L, R] is in the range
        x ^= toggle[pos];

    return x;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    char S[100010];
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        printf("Case %d:\n", Case);
        scanf(" %s", S);
        int n = strlen(S);
        int q;
        toggle.reset();
        scanf("%d", &q);
        while(q--) {
            char c;
            scanf(" %c ", &c);
            if(c == 'I') {
                int l, r;
                scanf(" %d %d", &l, &r);
                update(1, 1, n, l, r);
            }
            else {
                int p;
                scanf("%d", &p);
                bool q = S[p-1] == '1' ? 1:0;
                bool tog = query(1, 1, n, p);
                printf("%d\n", q ^ tog);
            }
        }
    }
    return 0;
}
