#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>
using namespace std;

#define ln printf("\n")

void Vector_sum_int(vector<int> &v1, vector<int> &v2) { // поэлементная сумма векторов. предполагается, что их размеры одинаковы.
	if (v1.size() != v2.size())
		return;
	auto it2 = v2.begin();
	for (auto it1 = v1.begin(); it1 != v1.end(); it1++) {
		*it1 += *it2;
		it2++;
	}
}

bool PalindromeChecker(vector<int> v) {
	auto it_b = v.begin();
	auto it_e = v.end() - 1;
	int count=0;
	for (int i = 1; i <= v.size(); i++) {
		if ((it_b == it_e) || (it_b == v.end()-1))
			break;
		else {
			if (*it_b == *it_e) {
				++count;
			}

			++it_b;
			if (it_b == it_e)
				break;
			else
			--it_e;
		}
	}
	return ((count*2 == v.size()) || (count*2 + 1 == v.size())) ? true : false;
}

int NumLength(int number) { // считаем длину числа
	int count;
	for (count = 0; count <= 100; count++) {
		if ((number - 10) >= 0) {
			number = number / 10;
		}
		else
			break;
	}
	return ++count;
}

const void PrintVector_int(vector<int> v) { // вывод вектора с целыми числами на экран
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it;
	}
}

void RecountVector_int(vector<int> &vect) { // делаем так, чтобы на каждой позиции была цифра (то есть натуральное число меньше 10)
	auto iter = vect.end() -1;
	for (iter; iter != vect.begin(); iter--) { // проверяем с конца, пока не дойдём до 1-го (по индексу) элемента
		if (*iter >= 10) {
				*(iter - 1) += *iter/10;
				*iter %= 10;
		}
	}

	iter = vect.begin();
	if(*iter>=10) { // проверяем нулевой (по индексу) элемент
		vector<int> v_temp;
		v_temp.push_back(*iter / 10);
		v_temp.push_back(*iter % 10);
		auto it = vect.begin() + 1;
		while (it != vect.end()) {
			v_temp.push_back(*it);
			++it;
		}
		vect = v_temp;
	}
}

int main() { // <----------------------------------------- main
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("color 02");

	int input,times=0;
	vector<int> vec,vec2;
	auto iter = vec.begin();
	cout << "Введите число, чтобы проверить его на палиндром :";
	cin >> input;
	ln;
	int count = NumLength(input);
	for (count; count > 0; count--) { // записываем число в вектор посимвольно
		int i = count;
		int inp_vector = input;
		while (i > 1) {
			inp_vector = inp_vector / 10;
			i--;
		}
		vec.push_back(inp_vector%10);
	}

	bool check = false;
	while (!check) {
		if ((times % (int)pow(10,6) == 0) && (times!=0)) {
			cout << "Мы проверили уже " << times << " раз. Продолжаем?";
			system("pause");
		}
		check = PalindromeChecker(vec);
		if (check) {
			cout << "Это палиндром. Ура! За " << times << " операции(й) у нас получилось: ";
			PrintVector_int(vec);
			break;
		}
		else {
			ln;
			++times;
			vec2 = vec; // приравниваем слагаемое 2 к первому
			reverse(vec2.begin(), vec2.end()); // переворачиваем слагаемое 2
			Vector_sum_int(vec, vec2); // суммируем вектора по элементам
			RecountVector_int(vec); // пересчитываем, чтобы каждый элемент был цифрой
			PrintVector_int(vec);
			cout << "     номер операции: " << times;
			ln;
		}
	}
	ln;
	system("pause");
	return 0;
}