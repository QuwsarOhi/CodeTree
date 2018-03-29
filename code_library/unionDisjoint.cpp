//Union Find Disjoint Set
//Data Structure

#include<bits/stdc++.h>
using namespace std;

vector<int>u_list, u_set;

//u_list[x] contains the size of a set x
//u_set[x] contains the root of x

int unionRoot(int n) {
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

int makeUnion(int a, int b) {
    int x = unionRoot(a);
    int y = unionRoot(b);

    if(x == y)
        return x;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return x;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return y;
    }
}

void unionInit(int len) {
    u_list.resize(len+5, 1);
    u_set.resize(len+5);

    for(int i = 0; i <= len; i++)
        u_set[i] = i;
}

bool isSameSet(int a, int b) {
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}


int main() {
    return 0;
}
