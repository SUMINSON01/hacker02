// week04_Quiz.cpp
// 상속

#include<iostream>
#include<string>

using namespace std;

// 1-2. 원을 추ㅜ강화한 Circle 클래스 완성
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NameCircle :Circle {
	string name;
public:
	NameCircle(int radius, string name) : Circle(radius){
		this->name = name;
	}
	NameCircle() {
		int a;
		string b;
		cout << count<<">> ";
		cin >> a >> b;
		setRadius(a);
		setName(b);
		count++;
	}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	void show() {
		cout << "반지름이 " << this->getRadius() << "인 " << getName() << endl;
	}
	static int count;
};
int NameCircle :: count = 1;

int main() {
	// 예제 1.
	//NameCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	//waffle.show();

	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	NameCircle pizza[5];
	for (int i = 0; i < 5; i++) {
		int a = pizza[i].getRadius();
		
	}

	return 0;
}

// 3-4. 2차원 상의 한 점을 표현하는 Point 클래스
/*class Point {
	int x, y;
public:
	Point() { this->x = 0; this->y = 0; }
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	void setX(int x) { this->x = x; }
	int getY() { return y; }
	void setY(int y) { this->y = y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint :Point {
	string color;
public:
	ColorPoint() {
		this->color = "BLACK";
		setX(0);
		setY(0);
	}
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y) {
		setX(x);
		setY(y);
	}
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color<<"색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다.";
	}
};

int main() {
	// 예제 3.
	//ColorPoint cp(5, 5, "RED");
	//cp.setPoint(10, 20);
	//cp.setColor("BLUE");
	//cp.show();

	// 예제 4.
	//ColorPoint zeroPoint; // BLACK 색에 (0,0) 위치의 점
	//zeroPoint.show(); // zeroPoint를 출력
}*/

// 5-6. BaseArraya 클래스
/*class BaseArray {
private:
	int capacity; // 배열의 크기
	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue :BaseArray {

};*/