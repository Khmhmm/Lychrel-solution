/*#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void RecountVector_int(vector<int> &vect) { // ������ ���, ����� �� ������ ������� ���� �����, � �� �����.
	auto iter = vect.end() -1;
	for (iter; iter != vect.begin(); iter--) { // ��������� � �����, ���� �� ����� �� 1-�� (�� �������) ��������
		if (*iter >= 10) {
				cout << "this block";
				*(iter - 1) += *iter/10;
				*iter %= 10;
		}
	}

	iter = vect.begin();
	if(*iter>=10) { // ��������� ������� �������
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

const void PrintVector_int(vector<int> v){ // ����� ������� � ������ ������� �� �����
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(61);
	RecountVector_int(v);
	PrintVector_int(v);
	system("pause");
	return 0;
}
*/