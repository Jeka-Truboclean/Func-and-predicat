#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

// ����� ��� �������� � ��������� ���������
class DelRange
{
	char F, L;
public:
	DelRange(char a, char b) { F = a; L = b; }
	bool operator()(char el)
	{
		return (el >= F && el <= L);
	}
};

int main()
{
	// �������� ������� ������ (�������� ������(vector) � �������� ��� ������ � �������)
	vector<char> vec{ 'a', 'h', 'l', 'K', 'e', 'g', 'c', 'A', 'k', 'B' };
	ostream_iterator<char> out(cout, " ");

	// �������� ����� � ��� ������� �����(vector)
	cout << "<----------<Start>---------->\n\n";
	cout << "     <--<Your vector>-->\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << "\n     <----------------->\n\n";

	// � ������ �������� �������
	cout << "      Del letters from:\n              ";
	char a;
	cin >> a;

	// �� ������ �������� �������
	cout << "\n       Del letters to:\n              ";
	char b;
	cin >> b;
	system("cls");

	// �������� ����� ��������
	cout << "<----------<Result>---------->\n Delete range from " 
		<< "\"" << a << "\"" << " to " << "\"" << b << "\"\n" << endl;

	// ��������� ����� ��� ���������
	cout << "     <------<Firt>------>\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << "\n     <------------------>\n\n";

	// �������� � ���������� ���������
	auto it = remove_if(vec.begin(), vec.end(), DelRange(a,b));
	vec.erase(it, vec.end());

	// ����� ����������
	cout << "     <------<Secd>------>\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << " <- it works!\n     <------------------>\n";

	// ������������ �������
	cout << "<---------------------------->";
}