// part03_1.cpp

#include <iostream>
#include <cstdio>

using namespace std;

class USERdATA
{
public: // 접근 제어 지시자
	// 멤버 변수 선언
	int nAge;
	char szName[32];

	// 멤버 함수 선언 및 정의
	void Print(void) {
		// nAge와 szName은 Print() 함수의 지역 변수가 아님
		printf("%d, %s\n", nAge, szName);
	}
};

class CTest {
public:
	// CTest 클래스의 '생성자 함수' 선언 및 정의
	CTest() {
		// 인스턴스가 생성되면 멤버 데이터를 '자동으로' 초기화
		m_nData = 10;
	}

	// 멤버 데이터 선언
	int m_nData;

	// 멤버 함수 선언 및 정의
	void PrintData(void) {
		// 멤버 데이터에 접근하고 값을 출력
		cout << m_nData << endl;
	}
};

class CTest2 {
public:
	// CTest2 클래스의 '생성자 함수' 선언 및 정의
	CTest2() {
		// 인스턴스가 생성되면 멤버 데이터를 '자동'으로 초기화
		cout << "CTEST2() : 생성자 함수" << endl;
		m_nData = 10;
	}

	// 멤버 데이터 선언
	int m_nData;

	// 멤버 함수 선언 및 정의
	void PrintData(void) {
		// 멤버 데이터에 접근하고 값을 출력
		cout << m_nData << endl;
	}
};

class CTest3 {
public:
	// CTest3 클래스의 '생성자 함수' 선언 및 정의
	CTest3() {
		// 인스턴스가 생성되면 멤버 데이터를 '자동'으로 초기화
		m_nData = 10;
	}
	// 멤버 데이터 선언
	int m_nData;

	// 멤버 함수 선언. 정의는 분리
	void PrintData(void);
};
// 외부에 분리된 멤버 함수 정의
void CTest3::PrintData(void) {
	// 멤버 데이터에 접근하고 값을 출력
	cout << m_nData << endl;
}

class CTest4 {
public:
	// 생성자 초기화 목록을 이용한 멤버 초기화
	CTest4()
		: m_nData1(10), m_nData2(20)
	{}

	// 두 개의 멤버 데이터 선언
	int m_nData1;
	int m_nData2;

	// 멤버 함수 선언 및 정의
	void PrintData(void) {
		// 두 개의 멤버 데이터에 접근하고 값을 출력
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

class CTest5
{
public:
	// 생성자 초기화 목록을 이용한 멤버 초기화
	CTest5() {}

	// C++11부터 선언과 동시에 멤버 변수를 초기화할 수 있음
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData(void) {
		// 두 개의 멤버 데이터에 접근하고 값을 출력
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

class CMyData {
	// 기본 접근 제어 지시자는 'private'이다.
	int m_nData;
public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

class CTest6 {
public:
	CTest6() {
		cout << "CTest6::CTest6()" << endl;
	}

	~CTest6() {
		cout << "~CTest6::CTest6()" << endl;
	}
};

class CTest7 {
	int m_nData;
public:
	// 생성자의 매개변수로 전달된 값으로 멤버 변수를 초기화
	CTest7(int nParam) : m_nData(nParam) {
		cout << "CTest7::CTest7()" << endl;
	}

	~CTest7() {
		// 생성할 때 매개변수로 받은 값을 출력
		cout << "~CTest7::CTest7()" << m_nData << endl;
	}
};

class CTest8 {
	int m_nData;
public:
	CTest8() {
		cout << "CTest8::CTest8()" << endl;
	}

	~CTest8() {
		cout << "~CTest8::CTest8()" << endl;
	}
};

class CRefTest {
public:
	// 참조형 멤버는 반드시 생성자 초기화 목록을 이용해 초기화한다.
	CRefTest(int& rParam) : m_nData(rParam) { };
	int GetData(void) { return m_nData; }

private:
	int& m_nData;
};

class CMyData2 {
public:
	// 디폴트 생성자는 없다
	// 매개변수가 int 하나인 생성자 함수 선언 및 정의
	CMyData2(int nParam) : m_nData(nParam) { };

	// 매개변수가 int 자료형 두 개인 생성자 함수 다중 정의
	CMyData2(int x, int y) : m_nData(x + y) { };

	int GetData(void) { return m_nData; }

private:
	int m_nData;
};

class CMyPoint {
public:
	CMyPoint(int x) {
		cout << "CMyPoint(int)" << endl;
		// x 값이 100이 넘으면 100으로 맞춤
		if (x > 100) {
			x = 100;
		}
		m_x = 100;
	}

	CMyPoint(int x, int y)
		// x 값을 검사하는 코드는 이미 존재하므로 재사용
		:CMyPoint(x)
	{
		cout << "CMyPoint(int, int" << endl;

		// y 값이 200이 넘으면 200으로 맞춤
		if (y > 200) {
			y = 200;
		}
		m_y = 200;
	}

	void Print() {
		cout << "X: " << m_x << endl;
		cout << "Y: " << m_y << endl;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

class CTest9 {
public:
	// 디폴트 생성자 선언
	CTest9(void);
	int m_nData = 5;
};
CTest9::CTest9(void){ }



int main() {
	// 예제 1. 클래스를 이용해 객체지향 프로그램으로 변경
	/*USERdATA user = {10, "철수"};
	user.Print();*/

	// 예제 2. 멤버 변수 초기화를 위한 생성자 함수 사용
	/*CTest t;
	t.PrintData();*/

	// 예제 3. 생성자 함수의 역할
	/*cout << "main() 함수 시작" << endl;

	CTest2 t2;
	t2.PrintData();

	cout << "main() 함수 끝" << endl;*/

	// 예제 4. 멤버 함수 선언과 정의를 분리
	/*CTest3 t3;
	t3.PrintData();*/

	// 예제 5. 생성자 초기화 목록을 이용한 멤버 변수 초기화
	/*CTest4 t4;
	t4.PrintData();*/

	// 예제 6. C++11의 멤버 변수 초기화
	/*CTest5 t5;
	t5.PrintData();*/

	// public : 멤버에 관한 모든 외부 접근 허용
	// protected : 멤버에 관한 모든 외부 접근 차단. 단, 상속 관계에 있는 파생 클래스에서의 접근은 허용
	// private : 외부 접근, 파생클래스로부터 접근 모두 차단.(클래스를 선언할 때 접근제어 지시자를 기술하지 않으면 private로 간주)

	// 예제 7. 객체 내부 멤버 변수의 임의 접근 차단
	/*CMyData data;
	data.SetData(10);
	cout << data.GetData() << endl;*/
	
	// 예제 8. 생성자와 소멸자
	/*/cout << "Begint" << endl;
	CTest6 a;
	cout << "End" << endl;*/

	// 예제 9. 디폴트 생성자의 생략
	/*cout << "Begin" << endl;
	CTest7 a(1);
	cout << "Beforee b" << endl;
	CTest7 b(2);
	cout << "End" << endl;*/

	// 예제 10. new와 delete 연산자 사용
	/*cout << "Begin" << endl;

	// new 연산자를 이용해 동적으로 객체 생성
	CTest8* pData = new CTest8;
	cout << "Test" << endl;

	// delete 연산자를 이용해 객체 삭제
	delete pData;
	cout << "End" << endl;*/

	// 예제 11. 참조자 선언을 위한 생성자 초기화 목록 이용
	/*int a = 10;
	CRefTest tr(a);
	cout << tr.GetData() << endl;

	//참조 원본인 a의 값 수정
	a = 20;
	cout << tr.GetData() << endl;*/

	// 예제 12. 생성자 다중 정의
	/*CMyData2 a(10);
	CMyData2 b(3, 4);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;*/

	// 예제 13. 다른 생성자를 추가로 부르는 생성자 초기화 함수
	/*// 매개변수가 하나인 생성자만 호출
	CMyPoint ptBegin(100);
	ptBegin.Print();

	// 두 생성자 모두 호출
	CMyPoint ptEnd(50, 250);
	ptEnd.Print();*/

	// 예제 14. 디폴트 생성자의 정의를 클래스 외부로 분리
	CTest9 t9;
	cout << t9.m_nData << endl;


	return 0;
}
