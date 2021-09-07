// week04_Quiz.cpp
// ���

#include<iostream>
#include<string>

using namespace std;

// 1-2. ���� �ߤ̰�ȭ�� Circle Ŭ���� �ϼ�
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
		cout << "�������� " << this->getRadius() << "�� " << getName() << endl;
	}
	static int count;
};
int NameCircle :: count = 1;

int main() {
	// ���� 1.
	//NameCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	//waffle.show();

	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	NameCircle pizza[5];
	for (int i = 0; i < 5; i++) {
		int a = pizza[i].getRadius();
		
	}

	return 0;
}

// 3-4. 2���� ���� �� ���� ǥ���ϴ� Point Ŭ����
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
		cout << color<<"������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�.";
	}
};

int main() {
	// ���� 3.
	//ColorPoint cp(5, 5, "RED");
	//cp.setPoint(10, 20);
	//cp.setColor("BLUE");
	//cp.show();

	// ���� 4.
	//ColorPoint zeroPoint; // BLACK ���� (0,0) ��ġ�� ��
	//zeroPoint.show(); // zeroPoint�� ���
}*/

// 5-6. BaseArraya Ŭ����
/*class BaseArray {
private:
	int capacity; // �迭�� ũ��
	int* mem; // ���� �迭�� ����� ���� �޸��� ������
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