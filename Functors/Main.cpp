#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	int mas[10] {2, 1, 3, 6, 4, 7, 5, 9, 8, 10};
	
	list<int> lst(mas, mas + 10);

	ostream_iterator<int> out(cout, "\t");

	copy(lst.begin(), lst.end(), out);
	lst.sort();
	cout << endl;
	copy(lst.begin(), lst.end(), out);
}