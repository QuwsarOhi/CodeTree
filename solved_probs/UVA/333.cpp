// UVa
// 333 - Recognizing Good ISBNs

#include <bits/stdc++.h>
using namespace std;

bool check(string &s, vector<int> &ret) {
    ret.clear();
    
    int l, r;
    
    for(l = 0; l < s.size(); ++l) if(s[l] != ' ') break;
    for(r = (int)s.size()-1; r >= 0; r--) if(s[r] != ' ') break;
    
    if(l >= r) return 0;
    
    s = s.substr(l, r-l+1);
    
    bool last = 0;
    for(auto it : s) {
        if(last and it != ' ' and it != '-')
            return 0;
        if(it == ' ')
            continue;
        if(isdigit(it))
            ret.push_back(it-'0');
        else if(it == 'X') {
            last = 1;
            ret.push_back(10);
        }
        else if(it != '-')
            return 0;
    }
    
    return (ret.size() == 10);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    vector<int>v;
    string str;
    
    while(getline(cin, str)) {
        bool ok = check(str, v);
        
        for(int i = 1; i < 10; ++i)
            v[i] = v[i] + v[i-1];
        
        for(int i = 1; i < 10; ++i)
            v[i] = v[i] + v[i-1];
        
        cout << str << " is ";
        cout << (((v[9]%11 == 0) and ok) ? "correct":"incorrect") << ".\n";
    }
    return 0;
}
