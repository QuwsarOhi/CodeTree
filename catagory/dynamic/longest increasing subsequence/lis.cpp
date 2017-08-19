//UVa
//481 - What Goes Up
//Longest Increasing Subsequence (Strictly increasing)

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    //P[i] contains the previous position of the previous number
    //L_id contains the position (from the input array A[]) of the current n'th LIS number
    //V contains the LIS
    vector<int> V;
    int x, i = 0, pos, lis = 0, lis_end, last_pos = 0, L_id[MAX], P[MAX], A[MAX];
    //lis : max size of LIS
    //lis_end : end position of lis P[]
    //pos : position of element insert
    //last_pos : keeping track of the lis_end if it is changed in the last moment
    while(scanf("%d", &x) != EOF) {
        A[i] = x;
        vector<int> :: iterator it = lower_bound(V.begin(), V.end(), x);
        //USE upper_bound for non-decreasing order
        //USE lower_bound for strictly increasing order
        pos = it - V.begin();
        if(pos == last_pos)
            lis_end = i;
        L_id[pos] = i;
        P[i] = pos ? L_id[pos-1] : -1;
        //printf("pos of %d P[%d] : %d\n", x, i, P[i]);
        if(it == V.end())
            V.push_back(x);
        else
            V[pos] = x;
        if(pos + 1 > lis) {     //if new position (pos) is greater than the last max position, then save this as the last value
            lis = pos + 1;
            lis_end = i;
            last_pos = pos;
        }
        i++;
    }
    printf("%d\n", V.size());
    //printf("lis_end is %d\n", lis_end);
    printf("-\n");
    //Use this method to print the last possible LIS
    //If the first possible LIS is needed, print the V vector instead
    stack<int> s;
    for( ; P[lis_end] >= 0; lis_end = P[lis_end])       //inputs all element except the last one i.e -1
        s.push(A[lis_end]);
    s.push(A[lis_end]);                         //input for -1
    while(!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }
    return 0;
}
