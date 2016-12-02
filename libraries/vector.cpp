#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vec(4, 100);
	vector <int> vec2(2, 456);
	vector <int>::iterator itbegin;
	vector <int>::iterator itend;

	cout << "vector size " << vec.size() << endl;
	
	vec.push_back(34);
	vec.push_back(21);
	
	cout << "vector size " << vec.size() << endl;
		
	for(int unsigned i =0; i < vec.size(); i++)
		cout << "value " << vec[i] << endl;
	
	cout << "===end====" << endl;
	cout << "vector size " << vec.size() << endl;
	
	itbegin = vec.begin();
	vec.insert(itbegin, 300);

	vec.insert(itbegin+2, 4);
	itend = vec.end();
	
	vec.insert(itend, 123);
		
	for(int unsigned i =0; i < vec.size(); i++)
		cout << "value " << vec[i] << endl;
	
	vec.swap(vec2);
	
	cout << "===end====" << endl;
	cout << "vector size " << vec.size() << endl;
	
	vec[0] = 23;
	
	for(int unsigned i =0; i < vec.size(); i++)
		cout << "value " << vec[i] << endl;
		
	vector<int> matrix[100];

	
	matrix[0].push_back(3);
	matrix[0].push_back(2);
	
	cout << matrix[0][0] << endl;
	cout << matrix[0][1] << endl;
	cout << sizeof(matrix)/sizeof(matrix[0][0]) << endl;
		
	return 0;
}
