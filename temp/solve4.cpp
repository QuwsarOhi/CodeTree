// UVa
// 290 - Palindroms <---> smordnilaP

#include <bits/stdc++.h>
using namespace std;

char reVal(int num) {
    if(num >= 0 && num <= 9)
        return (char)(num + '0');
    return (char)(num - 10 + 'A');
}
    
int getVal(char c) {
    if(c <= '9' && c >= '0')
        return c-'0';
    return c-'A'+10;
}


void sum(string &a, string &b, string &c, int base) {
    c.clear();
    int carry = 0;
    
    for(int i = (int)a.size()-1; i >= 0; --i) {
        int x = getVal(a[i]);
        int y = getVal(b[i]);
        int sum = x+y+carry;
        carry = sum/base;
        
        c.push_back(reVal(sum%base));
    }
    
    while(carry) {
        c.push_back(reVal(carry%base));
        carry /= base;
    }
}

int Check(string a, int base) {
    string b = a, c;
    reverse(b.begin(), b.end());
    
    for(int i = 0; i <= 100; ++i) {
        if(a == b)
            return i;
        
        sum(a, b, c, base);
        b = c;
        a = c;
        reverse(a.begin(), a.end());
    }
    return -1;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    string s;
    while(cin >> s) {
        int lim = -1;
        
        for(auto it : s)
            lim = max(lim, getVal(it));
        
        for(int i = 15; i >= 2; --i) {
            if(i <= lim)    cout << '?';
            else            cout << Check(s, i);
            if(i != 2)      cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}
            
