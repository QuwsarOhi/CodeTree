#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void lftAdd(int x) {
    

int main() {
    int n, Q;
    
    scanf("%d%d", &n, &Q);
    
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &val[i]);
    
    
    for(int i = 0; i < Q; ++i) {
        scanf("%d")
