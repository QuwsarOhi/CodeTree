// LightOJ
// 1060 - nth Permutation

#include <bits/stdc++.h>
using namespace std;

long long per[30] = {0};

long long permute(int freq[]) {
    int cnt = 0;
    
    for(int i = 0; i < 26; ++i)
        cnt+=freq[i];
        
    long long permutation = per[cnt] < 1 ? 0:per[cnt];
    
    for(int i = 0; i < 26; ++i)
        if(freq[i] > 1)
            permutation /= per[freq[i]];
        
    return permutation;
}


string NthPermutation(string str, int n) {
    string s;
    int freq[30] = {0};
    
    for(int i = 0; i < (int)str.size(); ++i)
        freq[str[i]-'a']++;
    
    if(per[0] == 0) {       // if not initialized
        per[0] = 1;
        for(int i = 1; i <= 25; ++i)
            per[i] = per[i-1]*i;
    }
    
    if(permute(freq) < n)
        return s;
    
    for(int i = 0; i < (int)str.size(); ++i) {
        for(int j = 0; j < 26; ++j) {
            if(freq[j] <= 0)
                continue;
            freq[j]--;
            long long P = permute(freq);
            if(P >= n) {
                s += char(j+'a');
                break;
            }
            else {
                n -= P;
                freq[j]++;
            }
        }
    }
    
    return s;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n;
    string s;
    cin >> t;
    
    for(int Case = 1; Case <= t; ++Case) {
        cin >> s >> n;
        s = NthPermutation(s, n);
        cout << "Case " << Case << ": ";
        if(s.empty())
            cout << "Impossible\n";
        else
            cout << s << "\n";
    }
    
    return 0;
}
