#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

// Класс для удаления в выбранном диапазоне
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
	// Создание области работы (создание масива(vector) и итератор для вывода в консоль)
	vector<char> vec{ 'a', 'h', 'l', 'K', 'e', 'g', 'c', 'A', 'k', 'B' };
	ostream_iterator<char> out(cout, " ");

	// Показать какой у нас имеется масив(vector)
	cout << "<----------<Start>---------->\n\n";
	cout << "     <--<Your vector>-->\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << "\n     <----------------->\n\n";

	// С какого элемента удалить
	cout << "      Del letters from:\n              ";
	char a;
	cin >> a;

	// До какого элемента удалить
	cout << "\n       Del letters to:\n              ";
	char b;
	cin >> b;
	system("cls");

	// Показать каков диапазон
	cout << "<----------<Result>---------->\n Delete range from " 
		<< "\"" << a << "\"" << " to " << "\"" << b << "\"\n" << endl;

	// Повторный вывод для сравнения
	cout << "     <------<Firt>------>\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << "\n     <------------------>\n\n";

	// Удаление в назначеном диапазоне
	auto it = remove_if(vec.begin(), vec.end(), DelRange(a,b));
	vec.erase(it, vec.end());

	// Вывод результата
	cout << "     <------<Secd>------>\n     ";
	copy(vec.begin(), vec.end(), out);
	cout << " <- it works!\n     <------------------>\n";

	// Дизайнерское решение
	cout << "<---------------------------->";
}