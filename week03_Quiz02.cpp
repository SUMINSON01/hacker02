// week03_Quiz02.cpp
// �Լ��� ���� ���� ������

#include<iostream>
#include<string>

using namespace std;

// 2. ���� main() �Լ��� ���� ����� �����Ͽ� half() �Լ��� �ۼ��϶�.
/*void half(double& n) {
	n = n / 2;
}

int main() {
	double n = 20;
	half(n); // n�� �ݰ��� ���� n�� �ٲ۴�.
	cout << n; // 10�� ���
}*/

// 3. ������ ���� �۵��ϵ��� combine() �Լ��� �ۼ��϶�
/*string combine(string& t1, string& t2, string& t3) {
	t3 = t1 + " " + t2 ;
	return t3;
}

int main() {
	string text1("I love you"), text2("very much");
	string text3; // ��� �ִ� ���ڿ�
	combine(text1, text2, text3);
	cout << text3;
}*/

// 4. �Լ� bigger() �ۼ�
//	  ����ڷκ��� 2���� ������ �Է� �޾� ū ���� ����ϴ� main() �ۼ�
//	  bigger()�� ���ڷ� �־��� a, b�� ������ true, �ƴϸ�false ����. ū ���� big���� ����
/*bool bigger(int a, int b, int& big) {
	big = a > b ? a : b;
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int big = 0;
	cout << bigger(4, 4, big) << ' ' << big << endl;
	cout << bigger(1, 4, big) << ' ' << big << endl;
	
	return 0;
}*/

// 5. Circle Ŭ���� �ۼ�
/*class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� " << radius << "�� ��" << endl; }
};

// Circle ��ü b�� a�� ���Ͽ� a�� Ű����� ���� �Լ��� �ۼ�
void increaseBy(Circle& a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x�� �������� 15�� ���� ������� �Ѵ�.
	x.show(); // "�������� 15�� ��"�� ���
}*/

// 6. find() �Լ��� ������ ������ ����.
//    ���ڿ� a���� ���� c�� ã��, ���� c�� �ִ� ������ ���� ������ ����
//    ���� �� c�� ã�� �� ���ٸ� success ���� �Ű� ������ false�� ����
//    success�� true�� ����
/*char& find(char a[], char c, bool& success) {
	int i = 0;
	while (1) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
		if (a[i] == '\n') {
			success = false;
			return a[i];
		}
		i++;
	}
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'm'; // 'M' ��ġ�� 'm' ���
	cout << s << endl; // "mike"�� ��µ�
}*/

// 7. MyInStack ����
//    MyInStack ���ÿ� ������ �� �ִ� ������ �ִ� ������ 10�̴�.
/*class MyIntStack{
	int p[10]; // �ִ� 10���� ���� ����
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() {
		for (int i = 0; i < 10; i++) {
			this->p[i] = { 0 };
		}
		tos = 0;
	};
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
};

bool MyIntStack::push(int n) {
	if (this->tos == 10) {
		return false;
	}
	else {
		p[this->tos] = n;
		this->tos++;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (this->tos == 0) {
		return false;
	}
	else {
		n = p[this->tos-1];
		this->tos--;
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) { // 11���� Ǫ���ϸ�, ���������� stack full�� �ȴ�.
		if (a.push(i)) cout << i << ' '; // Ǫ�õ� �� ����
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11���� ���ϸ�, ���������� stack empty�� �ȴ�.
		if (a.pop(n)) cout << n << ' '; // �� �� �� ���
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}*/

// 8. ���� 5���� MyIntStack�� �����Ͽ� ������ ���� ����.
//    ���ÿ� ������ �� �ִ� ������ �ִ� ������ �����ڿ��� �־����� size ����� ����
/*class MyIntStack {
	int *p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; // ������ ž�� ����Ű�� �ε���
public:
	MyIntStack() {
		this->p = new int[10];
		for (int i = 0; i < 10; i++) {
			this->p[i] = 0;
		}
		this->size = 10;
		this->tos = 0;
	};
	MyIntStack(int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = 0;
		}
		this->tos = 0;
	};
	MyIntStack(const MyIntStack& s) {// ���� ������
		this->size = s.size;
		this->p = new int[size];
		for (int i = 0; i < this->size; i++) {
			this->p[i] = s.p[i];
		}
		this->tos = s.tos;
	};
	~MyIntStack() {
		delete[] p;
	};
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
};

bool MyIntStack::push(int n) {
	if (this->tos == this->size) {
		return false;
	}
	else {
		p[this->tos] = n;
		this->tos++;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (this->tos == 0) {
		return false;
	}
	else {
		n = p[this->tos - 1];
		this->tos--;
		return true;
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; // ���� ����
	b.push(30);

	int n;
	a.pop(n); // ���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); // ���� b ��
	cout << "���� b���� ���� �� " << n << endl;
}*/

// 9. Ŭ���� Accumulator�� add() �Լ��� ���� ��� ���� �����ϴ� Ŭ����
//    Accumulator Ŭ������ �����϶�.
/*class Accumulator {
	int value;
public:
	Accumulator(int value) {// �Ű����� value ��� value�� �ʱ�ȭ�Ѵ�.
		this->value = value;
	};
	Accumulator& add(int n) {// value�� n�� ���� ���� �����Ѵ�.
		this->value += n;
		return *this;
	};
	int get(); // ������ �� value�� ����
};

int Accumulator::get() {
	return this->value;
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get(); // 28  ���
}*/

// 10. ������ �����ϴ� ��Ʈ �ۼ�.
//     append()�� Buffer ��ü�� ���ڿ��� �߰��ϰ� Buffer ��ü�� ���� ������ ��ȯ�ϴ� �Լ��̴�.
/*class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; } // text�� next ���ڿ� �����̱�
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& b, string Text) {
	b.add(Text);
	return b;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf�� ���ڿ��� "Guys" ������
	temp.print(); // "HelloGuys" ���
	buf.print(); // "HelloGuys" ���
}*/

// 11. å�� �̸��� ������ �����ϴ� ���� Book Ŭ����
/*class Book {
	string title; // ���� ���ڿ�
	int price; // ����
public:
	Book(const string title, int price) {
		this->title = title;
		this->price = price;
	};
	~Book() {
	};
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }

};

void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ������ ȣ���
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}*/

// 12. �а��� ��Ÿ���� Dept Ŭ����
class Dept {
	int size; // scores �迭�� ũ��
	int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size) { // ������
		this->size = size;
		scores = new int[size];
	}
	
	Dept(const Dept& dept) {// ���� ������
		this->size = dept.size;
		this->scores = new int[size];
		for (int i = 0; i < this->size; i++) {
			this->scores[i] = dept.scores[i];
		}
	}

	~Dept() { // �Ҹ���
		delete this->scores;
	}

	int getSize() { return size; }
	void read(); // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index); // index�� �л��� ������ 60���� ũ�� true ����
};

void Dept::read() {
	// �迭 ũ�⿡ ������ �ְ������ �����͸� ���. (���� �Ҵ�)
	cout << size << "�� ���� �Է�>>";
	for (int i = 0; i < size; i++) {
		cin >> this->scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (this->scores[index] >= 60) {
		return true;
	}
	else {
		return false;
	}
}

int countPass(Dept& d) {
	int count = 0;
	int size = d.getSize();
	for (int i = 0; i < size; i++) {
		if (d.isOver60(i)) {
			count++;
		}
	}
	return count;
}

int main() {
	Dept com(10); // �� 10���� �մ� �а� com
	com.read(); // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";

	return 0;
}