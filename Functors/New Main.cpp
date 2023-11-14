#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

bool Nega(int el)
{
	if (el < 0)
	{
		return true;
	}
	return false;
}

class Func
{
	int dig;
public:
	Func(int a) { dig = a; }

	bool operator()(int el)
	{
		if (el == dig)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	list<int> lst{1,4,-67,3,2,1,-8,45,1};
	ostream_iterator<int> out(cout, " | ");
	copy(lst.begin(), lst.end(), out);

	auto it = remove_if(lst.begin(), lst.end(), Func(1));
	lst.erase(it, lst.end());
	cout << endl;
	copy(lst.begin(), lst.end(), out);
}