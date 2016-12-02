// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

using namespace std;

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);
  
  cout << "Before making heap, top value :" << v[0] << endl;
  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << '\n';
  
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';
    
  pop_heap (v.begin(),v.end());
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';
    
  v.pop_back();
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';
    
  cout << "max heap after pop : " << v.front() << '\n';

  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';

  v.push_back(99);
  
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';
  
  push_heap (v.begin(),v.end());
  
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';
  
  cout << "max heap after push: " << v.front() << '\n';
  
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];
    cout << '\n';

  sort_heap (v.begin(),v.end());
  

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  cout << '\n';

  return 0;
}
