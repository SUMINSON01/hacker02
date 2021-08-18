// week03_Quiz02.cpp
// 함수와 참조 복사 생성자

#include<iostream>
#include<string>

using namespace std;

// 2. 다음 main() 함수와 실행 결과를 참고하여 half() 함수를 작성하라.
/*void half(double& n) {
	n = n / 2;
}

int main() {
	double n = 20;
	half(n); // n의 반값을 구해 n을 바꾼다.
	cout << n; // 10이 출력
}*/

// 3. 다음과 같이 작동하도록 combine() 함수를 작성하라
/*string combine(string& t1, string& t2, string& t3) {
	t3 = t1 + " " + t2 ;
	return t3;
}

int main() {
	string text1("I love you"), text2("very much");
	string text3; // 비어 있는 문자열
	combine(text1, text2, text3);
	cout << text3;
}*/

// 4. 함수 bigger() 작성
//	  사용자로부터 2개의 정수를 입력 받아 큰 값을 출력하는 main() 작성
//	  bigger()는 인자로 주어진 a, b가 같으면 true, 아니면false 리턴. 큰 수는 big에게 전달
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

// 5. Circle 클래스 작성
/*class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

// Circle 객체 b를 a에 더하여 a를 키우고자 다음 함수를 작성
void increaseBy(Circle& a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x의 반지름이 15인 원을 만들고자 한다.
	x.show(); // "반지름이 15인 원"을 출력
}*/

// 6. find() 함수의 원형은 다음과 같다.
//    문자열 a에서 문자 c를 찾아, 문자 c가 있는 공간에 대한 참조를 리턴
//    만일 문 c를 찾을 수 없다면 success 참조 매개 변수에 false를 설정
//    success에 true를 설정
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
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'm'; // 'M' 위치에 'm' 기록
	cout << s << endl; // "mike"가 출력됨
}*/

// 7. MyInStack 구현
//    MyInStack 스택에 저장할 수 있는 정수는 최대 개수는 10이다.
/*class MyIntStack{
	int p[10]; // 최대 10개의 정수 저장
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() {
		for (int i = 0; i < 10; i++) {
			this->p[i] = { 0 };
		}
		tos = 0;
	};
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
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
	for (int i = 0; i < 11; i++) { // 11개를 푸시하면, 마지막에는 stack full이 된다.
		if (a.push(i)) cout << i << ' '; // 푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11개를 팝하면, 마지막에는 stack empty가 된다.
		if (a.pop(n)) cout << n << ' '; // 팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}*/

// 8. 문제 5번의 MyIntStack를 수정하여 다음과 같이 선언.
//    스택에 저장할 수 있는 정수의 최대 개수는 생성자에서 주어지고 size 멤버에 유지
/*class MyIntStack {
	int *p; // 스택 메모리로 사용할 포인터
	int size; // 스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
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
	MyIntStack(const MyIntStack& s) {// 복사 생성자
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
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
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
	MyIntStack b = a; // 복사 생성
	b.push(30);

	int n;
	a.pop(n); // 스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n); // 스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;
}*/

// 9. 클래스 Accumulator는 add() 함수를 통해 계속 값을 누적하는 클래스
//    Accumulator 클래스를 구현하라.
/*class Accumulator {
	int value;
public:
	Accumulator(int value) {// 매개변수 value 멤버 value를 초기화한다.
		this->value = value;
	};
	Accumulator& add(int n) {// value에 n을 더해 값을 누적한다.
		this->value += n;
		return *this;
	};
	int get(); // 누적된 값 value를 리턴
};

int Accumulator::get() {
	return this->value;
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get(); // 28  출력
}*/

// 10. 참조를 리턴하는 코트 작성.
//     append()는 Buffer 객체에 문자열을 추가하고 Buffer 객체에 대한 참조를 반환하는 함수이다.
/*class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; } // text에 next 문자열 덧붙이기
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& b, string Text) {
	b.add(Text);
	return b;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf의 문자열에 "Guys" 덧붙임
	temp.print(); // "HelloGuys" 출력
	buf.print(); // "HelloGuys" 출력
}*/

// 11. 책의 이름과 가격을 저장하는 다음 Book 클래스
/*class Book {
	string title; // 제목 문자열
	int price; // 가격
public:
	Book(const string title, int price) {
		this->title = title;
		this->price = price;
	};
	~Book() {
	};
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }

};

void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사 생성자 호출됨
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}*/

// 12. 학과를 나타내는 Dept 클래스
class Dept {
	int size; // scores 배열의 크기
	int* scores; // 동적 할당 받은 정수 배열의 주소
public:
	Dept(int size) { // 생성자
		this->size = size;
		scores = new int[size];
	}
	
	Dept(const Dept& dept) {// 복사 생성자
		this->size = dept.size;
		this->scores = new int[size];
		for (int i = 0; i < this->size; i++) {
			this->scores[i] = dept.scores[i];
		}
	}

	~Dept() { // 소멸자
		delete this->scores;
	}

	int getSize() { return size; }
	void read(); // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index); // index의 학생의 성적이 60보다 크면 true 리턴
};

void Dept::read() {
	// 배열 크기에 변수를 넣고싶으면 포인터를 써라. (동적 할당)
	cout << size << "개 점수 입력>>";
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
	Dept com(10); // 총 10명이 잇는 학과 com
	com.read(); // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
	int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
	cout << "60점 이상은 " << n << "명";

	return 0;
}