// UVa
// 409 - Excuses, Excuses!

#include <bits/stdc++.h>
using namespace std;

set<string>Set;

string sep(string &s) {
    bool alpha = 0;
    string ret;
    
    for(auto it : s) {
        if(not alpha and isalpha(it))
            ret.push_back(' ');
        else if(alpha and not isalpha(it))
            ret.push_back(' ');
        ret.push_back(it);
        alpha = isalpha(it);
    }
    return ret;
}

void toLower(string &s) {
    for(int i = 0; i < (int)s.size(); ++i)
        s[i] = tolower(s[i]);
}

vector<pair<string, int> > v;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, m, Case = 1;
    string str;
    
    while(cin >> n >> m) {
        cout << "Excuse Set #" << Case++ << "\n";
        while(n--) {
            cin >> str;
            Set.insert(str);
        }
        int mx = -1, cnt;
        getline(cin, str);
        while(m--) {
            getline(cin, str);
            v.push_back({str, 0});
            str = sep(str);
            stringstream ss;
            ss << str;
            cnt = 0;
            while(ss >> str) {
                toLower(str);
                if(Set.count(str))
                    ++cnt;
            }
            mx = max(mx, cnt);
            v.back().second = cnt;
        }

        for(auto it : v)
            if(it.second == mx)
                cout << it.first << "\n";
        
        v.clear();
        Set.clear();
        cout << "\n";
    }
    return 0;
}
