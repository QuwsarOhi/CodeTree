// Policy Based Data Structures
// Source : http://codeforces.com/blog/entry/11080
//          http://codeforces.com/blog/entry/13279
// Problems:
// http://codeforces.com/blog/entry/53735
// http://codeforces.com/contest/762/problem/E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// key, Mapped-Policy, Key Comparison Func, Underlying data Structure, Policy for updating node interval

// Key Comparison Func : Defines how data will be stored (incleasing, decrasing order)
//                       less<int>          -   Same value occurs once & increasing                 SET
//                       less_equal<int>    -   Same value occurs one or more & increasing          MULTISET
//                       greater<int>, greater_equal<int>
//
// if Mapped-Policy set to null_type, this works as a SET
// else works as MAP
//
// Underlying Data Structures : rb_tree_tag     -   Red Black Tree
//                              splay_tree_tag  -   Splay Tree
//                              ov_tree_tag     -   Ordered Vector Tree
//
// Policy for Updaing Node :  default   -   null_node_update
//                   c++ immplemented   -   tree_order_statistics_node_update

// Features :
// Can be used as SET/MULTISET
// lower_bound and upper bound works as expected
// insertion, deletation, clear
// container.find_by_order(x) returns x'th elements iterator
// container.order_of_key(x) returns number of values less than (or equal to) x 
// auto casting works
// 

int main() {
    ordered_set<int> X;
    // -------------- INSERTION --------------
    // Data are indexed in increasing order & can occur only once (like STL SET)
    X.insert(1); X.insert(18); X.insert(2); X.insert(2); X.insert(4); X.insert(8); X.insert(16);

    // -------------- ITERATION --------------    
    // Index-Wise : log_n
    cout << *X.find_by_order(0) << endl;
    cout << *X.find_by_order(2) << endl;
    cout << *X.find_by_order(6) << endl;    // Not Present, Will return 0
    
    if(X.end() == X.find_by_order(6)) cout << "End Reached" << endl;
    X.erase(X.find_by_order(2));        // Deleting element by iterator
    cout << "Iterating \n";
    for(auto x : X) cout << x << endl;
    cout << endl;
    
    // -------------- Range Search ------------
    // Returns number of elements STRICTLY less than value
    cout << X.order_of_key(-5) << endl;
    cout << X.order_of_key(1) << endl;
    cout << X.order_of_key(3) << endl;
    cout << X.order_of_key(4) << endl;
    cout << X.order_of_key(400) << endl;
    X.clear();          // Clearing
}
