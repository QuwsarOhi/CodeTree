#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    while(cin>>n){

        map < string , int > yes;
         for(int i=0;i<n;i++){
            cin>>s;
            yes[s]++;
         }
         n=0;
         for( auto it : yes ){
            if(it.second>n){
                n=it.second;
                s=it.first;
            }
         }
         cout<< s <<endl;
    }
    return 0;
}
