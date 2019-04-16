#include <bits/stdc++.h>
using namespace std;

string p;
vector<int>S, E;

int main() {
    int t, n;
    cin >> t;

    for(int Case = 1; Case <= t; ++Case) {
        cin >> n;
        cin >> p;

        E.clear(), S.clear();
        for(int i = 0; i < p.size(); ++i) {
            if(p[i] == 'E')
                E.push_back(i);
            else
                S.push_back(i);
        }

        for(int i = 0; i < E.size(); ++i)
            p[E[i]] = 'S';
        for(int i = 0; i < S.size(); ++i)
            p[S[i]] = 'E';

        cout << "Case #" << Case << ": " << p << endl;
    }
    return 0;
}