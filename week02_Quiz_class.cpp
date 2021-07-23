// week02_Quiz_class.cpp

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

class Tower {
public:
	Tower(int nParam) : height(nParam) { };
	Tower() {}
	int getHeight() {
		return height;
	}

private:
	int height = 1;
};

class Date {
public:
	Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {};
	Date(string _date) : date(_date) {};

	void show() {
		char s[2];
		int count = 0;
		int dateSize = date.size();
		for (int i = 0; i < dateSize; i++) {
			if (date[i] == '/') {
				s[count] = i;
				count++;
			}
		}
		cout << date.substr(0, s[0]) << "�� " << date.substr(s[0]+1, s[1]-s[0]-1) << "��" << date.substr(s[1]+1) << "��";
		cout << endl;
		
	}

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

		
private:
	int year = 0;
	int month = 0;
	int day = 0;

	string date = "";
};

class Account {
public:
	Account(string _name, int _id, int _balance) : name(_name), id(_id), balance(_balance) {};

	int deposit(int inputmoney) { return balance += inputmoney; }
	int withdraw(int outputmoney) { return balance -= outputmoney; }

	int inquiry() { return balance; }
	string getOwner() { return name; }




private:
	string name = "none";
	int id = 0;
	int balance = 0;
};

class CoffeeMachine {
public:
	CoffeeMachine(int _coffee, int _water, int _sugar) : coffee(_coffee), water(_water), sugar(_sugar) {};

	void drinkEspresso() {
		coffee -= 1;
		water -= 1;
	}
	void drinkAmericano() {
		coffee -= 1;
		water -= 2;
	}
	void drinkSugarCoffee() {
		coffee -= 1;
		water -= 2;
		sugar -= 1;
	}
	void fill() {
		coffee = 10;
		water = 10;
		sugar = 10;
	}



	void show() {
		cout.width(10); cout << "Ŀ�ǸӽŻ���, ";
		cout.width(10); cout << "Ŀ��:" << coffee;
		cout.width(10); cout << "��:" << water;
		cout.width(10); cout << "����:" << sugar;
		cout << endl;
	}

private:
	int coffee = 0;
	int water = 0;
	int sugar = 0;

};

class Random {
public:
	Random() {};

	int next() { return rand(); }
	int nextInRange(int min, int max) {
		return (double)rand() / (RAND_MAX + 1) * (max - min + 1) + min;
	}
};

class EvenRandom {
public:
	EvenRandom() {};

	int next() { 
		while (1) {
			int n = rand();
			if (n % 2 == 0) {
				return n;
			}
		}
	}
	int nextInRange(int min, int max) {
		while (1) {
			int n = (double)rand() / (RAND_MAX + 1) * (max - min + 1) + min;
			if (n % 2 == 0) {
				return n;
			}
		}
	}
		
	
};

class SelectableRandom {
public:
	SelectableRandom(string _select) : select(_select) {};
	
	int next() {
		if (select == "¦��") {
			while (1) {
				int n = rand();
				if (n % 2 == 0) {
					return n;
				}
			}
		}
		else if (select == "Ȧ��") {
			while (1) {
				int n = rand();
				if (n % 2 == 1) {
					return n;
				}
			}
		}
	}

	int nextInRange(int min, int max) {
		if (select == "¦��") {
			while (1) {
				int n = (double)rand() / (RAND_MAX + 1) * (max - min + 1) + min;
				if (n % 2 == 0) {
					return n;
				}
			}
		}
		else if (select == "Ȧ��") {
			while (1) {
				int n = (double)rand() / (RAND_MAX + 1) * (max - min + 1) + min;
				if (n % 2 == 1) {
					return n;
				}
			}
		}
	}

	string select;

};

class Integer {
public:
	Integer(int _n) : n(_n) {};
	Integer(string _m) { n = stoi(_m); };

	inline int get() {
		return n;
	}
	inline int set(int _n) {
		return n = _n;
	}
	inline bool isEven() {
		return (n % 2) ? false : true;
	}


private:
	int n;
};

class Oval {
public:
	Oval() { int width = 1; int height = 1; };
	Oval(int _width, int _height) : width(_width), height(_height) {};

	void set(int _width, int _height) {
		width = _width;
		height = _height;
	}
	void show() {
		cout << "width = " << width << ", height = " << height << endl;
	}
	int getWidth() { return width; }
	int getHeight() { return height; }

	~Oval() {
		cout << "Oval �Ҹ� : width = " << width << ", height = " << height;
		cout << endl;
	}
private:
	int width = 1;
	int height = 1;

};

class Add {
public:
	Add() {};
	void SetValue(int x, int y) {
		a = x;
		b = y;
	}
	int calculate() { return a + b; }
private:
	int a;
	int b;
};
class Sub {
public:
	Sub() {};
	void SetValue(int x, int y) {
		a = x;
		b = y;
	}
	int calculate() { return a - b; }
private:
	int a;
	int b;
};
class Mul {
public:
	Mul() {};
	void SetValue(int x, int y) {
		a = x;
		b = y;
	}
	int calculate() { return a * b; }
private:
	int a;
	int b;
};
class Div {
public:
	Div() {};
	void SetValue(int x, int y) {
		a = x;
		b = y;
	}
	int calculate() { return a / b; }
private:
	int a;
	int b;
};



int main() {
	// 1. main()�� ���� ����� ������ ������ Tower Ŭ���� �ۼ�
	/*Tower myTower; // 1����
	Tower seoulTower(100); // 100 ����
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;*/

	// 2. main()�� ���� ����� ������ ������ Date Ŭ���� �ۼ�
	/*Date birth(2014, 3, 20); // 2014�� 3�� 20��
	Date independenceDay("1945/8/15"); // 1945�� 8�� 15��
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << "," << birth.getDay() << endl;*/

	// 3. main()�� ���� ����� ������ ������ Account Ŭ���� �ۼ�
	//    ���� ������ ������ ����, ���� ��ȣ, �ܾ��� ��Ÿ���� 3 ��� ������ �̷������.
	/*Account a("kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000); // 50000���� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;*/

	// 4. main()�� ���� ����� ������ ������ CoffeeMachine Ŭ���� �ۼ�
	//    ���������� Ŀ�� 1, �� 1�� �Һ�
	//    �Ƹ޸�ī�� Ŀ�� 1, �� 2�� �Һ�
	//    ����Ŀ�Ǵ� Ŀ�� 1, �� 2, ���� 1 �Һ�
	/*CoffeeMachine java(5, 10, 3); // Ŀ�Ƿ�:5, ����:10, ����:6 ���� �ʱ�ȭ
	java.drinkEspresso(); // Ŀ�� 1, �� 1 �Һ�
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.drinkAmericano(); // Ŀ�� 1, �� 2 �Һ�
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.drinkSugarCoffee();// Ŀ�� 1, �� 2, ���� 1 �Һ�
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.fill(); // Ŀ�� 10, �� 10, ���� 10 ���� ä���
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���*/

	// 5. main()�� ���� ����� ������ ������ Random Ŭ���� �ۼ�
	//    Random Ŭ������ ������, next(), nextInRange()�� 3���� ��� �Լ��� ������.
	/*Random r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2 ���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;*/

	// 6. 5�� ������ �����Ͽ� ¦�� ������ �����ϰ� �߻���Ű�� EvenRandom Ŭ���� �ۼ�
	//    0�� ¦���� ó��
	/*EvenRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� rand_max(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2 ���� " << "10 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2���� 10 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;*/

	// 7. 5�� ������ �����Ͽ� �����ڸ� �̿��Ͽ� ¦�� Ȧ���� ������ �� �ִ� SelectableRandom Ŭ���� �ۼ�
	//    ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷�
	/*SelectableRandom r("¦��");
	cout << "-- 0���� " << RAND_MAX << "������ ���� " << r.select << " 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� rand_max(32767) ������ ������ ����
		cout << n << ' ';
	}

	SelectableRandom r2("Ȧ��");
	cout << endl << endl << "-- 2 ���� " << "9 ������ ���� " << r2.select << " 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r2.nextInRange(2, 9); // 2���� 9 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;*/

	// 8. int Ÿ�� ������ ��üȭ�� Integer Ŭ���� �ۼ�
	//    Integer�� ��� ��� �Լ��� �ڵ� �ζ������� �ۼ�
	/*Integer n(30);
	cout << n.get() << ' '; // 30 ���
	n.set(50);
	cout << n.get() << ' '; // 50 ���

	Integer m("300");
	cout << m.get() << ' '; // 300 ���
	cout << m.isEven(); //true(������ 1) ���*/

	// 9. Oval Ŭ������ �־��� �簢���� �����ϴ� Ÿ���� �߻�ȭ�� Ŭ�����̴�.
	/*Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;*/

	// 10. ���ϱ�(+), ����(-), ���ϱ�(*)), ������(/)�� �����ϴ� 4���� Ŭ���� Add, Sub, Mul, Div�� ������
	/*Add a;
	Sub s;
	Mul m;
	Div d;
	while (1) {
		int num1, num2;
		string opt;
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		cin >> num1 >> num2 >> opt;
		if (opt == "+") {
			a.SetValue(num1, num2);
			cout << a.calculate() << endl;
		}
		else if (opt == "-") {
			s.SetValue(num1, num2);
			cout << s.calculate() << endl;
		}
		else if (opt == "*") {
			m.SetValue(num1, num2);
			cout << m.calculate() << endl;
		}
		else if (opt == "/") {
			d.SetValue(num1, num2);
			cout << d.calculate() << endl;
		}
	}*/



	// 12. .cpp�� .h �и�





















	return 0;
}