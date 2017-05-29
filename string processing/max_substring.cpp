//UVa
//902 - Password Search

#include<bits/stdc++.h>
using namespace std;

char a[1000010];

int main()
{
    string x, s;
    int n, past;
    map<string, int>pass;
    while(scanf(" %d %s", &n, a) != EOF) {
        past = -1;
        x = a;
        size_t len = x.size();
        for(size_t i = 0; len - i >= n; i++) {
            string y = x.substr(i, n);
            pass[y]++;
        }
        for(map<string, int>::iterator it = pass.begin(); it != pass.end(); it++)
            if(it->second > past) {
                s = it->first;
                past = it->second;
            }
        printf("%s\n", s.c_str());
        pass.clear();
    }
    return 0;
}
