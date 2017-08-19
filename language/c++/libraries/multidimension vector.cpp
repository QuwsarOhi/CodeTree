#include <iostream>
#include <vector>

using namespace std;

void printer(vector< vector < int > > &matrix)
{
	matrix[0][0] = 1;
	cout << matrix[0][0] << endl;
	cout << matrix[1][0] << endl;
	
}

int main()
{
	vector< vector<int> > vec;
	int len;
	
	vec.push_back(vector<int>() );
	vec.push_back(vector<int> () );
	
	
	vec[0].push_back(5);
	vec[1].push_back(8);
	vec[0].push_back(3);
	
	len = sizeof(vec[0])/sizeof(vector< int >);
	
	cout << vec[0][0] << endl;
	cout << vec[0][1] << endl;
	cout << vec[0][2] << endl;
	cout << vec[1][0] << endl;
	
	cout << "size of vect[0] : " << vec[0].size() << endl;
	cout << "len of vec[0] : " << len << endl;
	
	printer(vec);
	
	return 0;
	
}
