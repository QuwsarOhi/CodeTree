// Codeforces
// B. Maxim Buys an Apartment
// http://codeforces.com/contest/854/problem/B

// Count maximum & minimum position where there exists an element beside the position

#include <bits/stdc++.h>
using namespace std;

int cal1(int n, int k) {
    int cnt = 0, empty = n-k, pos=0;
    bool filled = 0;
    while(pos < n) {
        if(!filled && pos+k+1 <= n) {
            cnt++;
            empty--;
            filled = 1;
            //cout << "counting at " << pos << endl;
            if(k == 0)
                break;
        }
        else if(filled) {
            k--;
            filled = 0;
            if(empty == 0)
                break;
        }
        pos++;
        
        if(filled && empty > 0 && k > 0) {             // we just counted an empty apt
            if(pos+empty+k <= n) {
                //cout << "Double at " << pos << endl;
                pos+=2;
                cnt += 1;
                empty--;
                k--;
                filled = 0;
            }
            if(empty == 0 || k == 0)
                break;
        }
    }
    return cnt;
}

int main() {
    int n, k;
    
    cin >> n >> k;
    
    if(n == k || k == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    
    cout << "1 ";               // if everyone is side by side minimum is always one

    
    // When to break the loop
    // 1. if there is no more people to place
    // 2. if there is no more empty apts
    
    // always start by setting an empty apt
    // also check if there is any empty 

    
    
    cout << cal1(n, k) << endl;
    
    //main();
    
    return 0;
}
