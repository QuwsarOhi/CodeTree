#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    
    cin >> n >> k;
    vector<int> v(n+1);
    
    if((n == 1 && k == 1) || n == k) {
        cout << -1 << endl;
        return 0;
    }
    
    //set<int>Set;
    
    //for(int i = 1; i <= n; ++i)
    //    Set.insert(i);
    
    int i = 2, j = n-k;
    
    if((n-k) % 2 == 0)
        i = 1;
    else {
        v[1] = 1;
        j--;
    }
    
    
    for( ; i+1 <= n && j-2 >= 0; i+=2, j-=2) {
        v[i] = i+1;
        v[i+1] = i;
        //Set.erase(i);
        //Set.erase(i+1);
    }
    
    //cout << "done\n";
    
    //cout << i << endl;
    for( ; i <= n; ++i) v[i] = i;
    
    for( i = 1; i <= n; ++i)
        cout << v[i] << " ";
    
    return 0;
}
    
    
    
    
