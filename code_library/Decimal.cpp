vi DecimalVal(int a, int b) {           // Calculate Decimal values (after .) of a/b
    vi v;
    a %= b;
    if(a == 0) {
        v.pb(0);
        return v;
    }
    bool first = 1;
    while(SIZE(v) <= 200) {             // Define the Maximum Length of decimal values 
        if(a == 0)
            return v;                   // If any Zero divisor is found (then, rest all will be Zero) return values
        else if(a < b && !first) {      // If we need to add another zero (add zero after first time)
            a*=10;
            v.pb(0);
        }
        else if(a < b && first) {       // If we need to add a extra zero (adding zero first time)
            first = 0;
            a *= 10;
            continue;
        }
        else {
            v.pb(a/b);
            a%=b;
            first = 1;
        }
    }
    return v;
}

// Repetation (PunoPonik) is also calculated
vi dec1, dec2;                              // Before . (decimal), after . (decimal)
int DecimalRepeated(int a, int b) {         // Calculate Decimal values (after .) of a/b
    unordered_map<int, int>mp;
    int k = 0, point = -1;
    bool divisable = 0;
    if(a >= b) {                            // Before Decimal Calculation
        dec1.push_back(a/b);
        a %= b;
    }
    if(dec1.size() == 0)
        dec1.push_back(0);
    while(a != 0) {
        if(mp.find(a) != mp.end()) {        // if the remainder is found again, there exists a loop
            point = mp[a];
            break;
        }
        if(a%b == 0) {
            dec2.push_back(a/b);
            break;
        }
        mp[a] = k++;
        int cnt = 0;
        while(a < b) {
            a *= 10;
            if(cnt != 0) {
                dec2.push_back(0);
                k++;
            }
            ++cnt;
        }
        if(cnt != 0 && mp.find(a) != mp.end()) {
            point = mp[a];
            break;
        }
        if(cnt == 1)
            mp[a] = (k-1);
        dec2.push_back(a/b);
        a %= b;
        if(a == 0) {
            divisable = 1;
            break;
        }} 
    return divisable == 1 ? 1:((int)dec2.size()-point);
}
 
int main() {
    int a, b;
    cin >> a >> b;
    vi v = DecimalVal(a, b);
    for(auto it : v)
        cout << it;
    cout << endl;
    int Cycle = DecimalRepeated(a, b);
    for(auto it : dec1)
        cout << it;
    cout << ".";
    for(auto it : dec2)
        cout << it;
    cout << "\n\n";
    cout << "Last Repeating Cycle " << Cycle << endl;
    return 0;
}
