#include "pch.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;





void main()
{
	random_device rd; // для генератора псевдослучайных чисел
	mt19937 generator(rd());

	int number; // номер задачи или упражнения (см меню)

	cout << "1: zadacha 1" << endl;
	cout << "2: zadacha 2" << endl;
	cout << "3: yprazhnenie 1" << endl;
	cout << "4: zadacha 3" << endl;
	cout << "5: zadacha 4" << endl;
	cout << "6: zadacha 5" << endl;
	cout << "7: yprazhnenie 2" << endl;
	cout << "8: yprazhnenie 3" << endl;
	cout << "9: zadacha 6" << endl;
	cout << "10: yprazhnenie 4" << endl;
	cout << "11: zadacha 7" << endl;
	cout << "12: zadacha 8" << endl;
	cout << "13: yprazhnenie 5" << endl;
	cout << "14: zadacha 9" << endl;
	cout << "15: zadacha 10" << endl;

	cin >> number;

	if (number == 1) { // задача 1

		int n; // количество повторений эксперимента
		cout << "Vvedite kol-vo povtoreniy: ";
		cin >> n;
		int win_A = 0, win_B = 0; // количество побед А и В соответсвенно
		string S; // сюда будем записывать строку из рандомных чисел
		string A; // комбинация игрока А
		string B; // комбинация игрока В
		string hlp; // вспомогательная строка
		cout << "Vvedite stroki A and B na raznih strokah: ";
		cin >> A;
		cin >> B;
		uniform_int_distribution<> distribution(0, 1);
		int c; // случайное числ0 (0(орел) или 1(решка))

		for (int i = 0; i < 3; i++) { // запишем первые три броска чтобы было с чем сравнивать
			c = distribution(generator);
			hlp = to_string(c);
			S += hlp;
			hlp.clear();
		}

		for (int i = 0; i < n; i++) { // считаем количчество побед А и В
			if (A == S) win_A++;
			if (B == S) win_B++;
			c = distribution(generator);
			hlp = to_string(c);
			S += hlp;
			S.erase(0, 1);
			hlp.clear();
		}
		cout << win_A << ' ' << win_B << endl;
		cout << (float)win_B / win_A << endl; // отношение числа выигрышей В к А
	}

	if (number == 2) { //задача 2
		int N, Ny = 0; // кол-во повторений эксперимента и число успешных испытаний
		int A[2] = {-1, 1}; // можем ходить только налево(-1) и направо(1)
		cout << "Vvedite kol-vo povtoreniy: ";
		cin >> N;
		uniform_int_distribution<> distribution(0, 1);
		int c; // случайное число (0(налево) или 1(направо))
		int k; // координата начала
		cout << "Vvedite koordinaty nachala: ";
		cin >> k;
		int k1 = k; // текущая координата
		
		for (int i = 0; i < N; i++) {
			c = distribution(generator);
			k1 += A[c];
			if (k1 == 0) { Ny++; k1 = k;  continue; }
			if (k1 == 10) { k1 = k;  continue; }
		}
		cout << Ny << ' ' << (float)Ny / N << endl; // отношение успешных испытаний ко всем
	}

}