//UVa
//12582 - Wedding of Sultan
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    char a[150];
    for(int Case = 1; Case <= t; Case++) {
        map<char, int>mp;
        vector<int>V[150];
        scanf(" %s", a);
        mp[a[0]]++;
        char start = a[0];
        stack<char>current;
        current.push(a[0]);
        for(int i = 1; a[i] != start; i++) {
            mp[a[i]]++;
            if(current.top() == a[i]) {
                current.pop();
            }
            else {
                V[current.top()- 'A'].push_back(a[i] - 'A');
                V[a[i]-'A'].push_back(current.top() - 'A');
                current.push(a[i]);
            }
        }
        printf("Case %d\n", Case);
        for(map<char, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
            printf("%c = %d\n", it->first, V[it->first - 'A'].size());
        }
    }
    return 0;
}
