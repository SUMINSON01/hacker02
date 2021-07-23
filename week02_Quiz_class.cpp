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
		cout << date.substr(0, s[0]) << "년 " << date.substr(s[0]+1, s[1]-s[0]-1) << "월" << date.substr(s[1]+1) << "일";
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
		cout.width(10); cout << "커피머신상태, ";
		cout.width(10); cout << "커피:" << coffee;
		cout.width(10); cout << "물:" << water;
		cout.width(10); cout << "설탕:" << sugar;
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
		if (select == "짝수") {
			while (1) {
				int n = rand();
				if (n % 2 == 0) {
					return n;
				}
			}
		}
		else if (select == "홀수") {
			while (1) {
				int n = rand();
				if (n % 2 == 1) {
					return n;
				}
			}
		}
	}

	int nextInRange(int min, int max) {
		if (select == "짝수") {
			while (1) {
				int n = (double)rand() / (RAND_MAX + 1) * (max - min + 1) + min;
				if (n % 2 == 0) {
					return n;
				}
			}
		}
		else if (select == "홀수") {
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
		cout << "Oval 소멸 : width = " << width << ", height = " << height;
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
	// 1. main()의 실행 결과가 다음과 같도록 Tower 클래스 작성
	/*Tower myTower; // 1미터
	Tower seoulTower(100); // 100 미터
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;*/

	// 2. main()의 실행 결과가 다음과 같도록 Date 클래스 작성
	/*Date birth(2014, 3, 20); // 2014년 3월 20일
	Date independenceDay("1945/8/15"); // 1945년 8월 15일
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << "," << birth.getDay() << endl;*/

	// 3. main()의 실행 결과가 다음과 같도록 Account 클래스 작성
	//    계좌 정보는 계좌의 주인, 계좌 번호, 잔액을 나타내는 3 멤버 변수로 이루어진다.
	/*Account a("kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000); // 50000만원 저금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000원 출금. withdraw()는 출금한 실제 금액 리턴
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;*/

	// 4. main()의 실행 결과가 다음과 같도록 CoffeeMachine 클래스 작성
	//    에스프레소 커피 1, 물 1가 소비
	//    아메리카노 커피 1, 물 2가 소비
	//    설탕커피는 커피 1, 물 2, 설탕 1 소비
	/*CoffeeMachine java(5, 10, 3); // 커피량:5, 물량:10, 설탕:6 으로 초기화
	java.drinkEspresso(); // 커피 1, 물 1 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkAmericano(); // 커피 1, 물 2 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkSugarCoffee();// 커피 1, 물 2, 설탕 1 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.fill(); // 커피 10, 물 10, 설탕 10 으로 채우기
	java.show(); // 현재 커피 머신의 상태 출력*/

	// 5. main()의 실행 결과가 다음과 같도록 Random 클래스 작성
	//    Random 클래스가 생성자, next(), nextInRange()의 3개의 멤버 함수를 가진다.
	/*Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2 에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;*/

	// 6. 5번 문제를 참고하여 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스 작성
	//    0도 짝수로 처리
	/*EvenRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 rand_max(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2 에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2에서 10 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;*/

	// 7. 5번 문제를 참고하여 생성자를 이용하여 짝수 홀수를 선택할 수 있는 SelectableRandom 클래스 작성
	//    짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램
	/*SelectableRandom r("짝수");
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 " << r.select << " 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 rand_max(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}

	SelectableRandom r2("홀수");
	cout << endl << endl << "-- 2 에서 " << "9 까지의 랜덤 " << r2.select << " 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r2.nextInRange(2, 9); // 2에서 9 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;*/

	// 8. int 타입 정수를 객체화한 Integer 클래스 작성
	//    Integer의 모든 멤버 함수를 자동 인라인으로 작성
	/*Integer n(30);
	cout << n.get() << ' '; // 30 출력
	n.set(50);
	cout << n.get() << ' '; // 50 출력

	Integer m("300");
	cout << m.get() << ' '; // 300 출력
	cout << m.isEven(); //true(정수로 1) 출력*/

	// 9. Oval 클래스는 주어진 사각형에 내접하는 타원을 추상화한 클래스이다.
	/*Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;*/

	// 10. 더하기(+), 빼기(-), 곱하기(*)), 나누기(/)를 수행하는 4개의 클래스 Add, Sub, Mul, Div를 만들어라
	/*Add a;
	Sub s;
	Mul m;
	Div d;
	while (1) {
		int num1, num2;
		string opt;
		cout << "두 정수와 연산자를 입력하세요>>";
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



	// 12. .cpp와 .h 분리





















	return 0;
}