// part03_2.cpp

#include<iostream>

using namespace std;

class CMyData {
public:
	CMyData(int nParam) : m_nData(nParam) { };
	void PrintData() {
		// m_nData의 값을 출력
		cout << m_nData << endl;

		// CMyData 클래스의 멤버인 m_nData의 값을 출력
		cout << CMyData::m_nData << endl;

		// 메서드를 호출한 인스턴스의 m_nData 멤버 값을 출력
		cout << this->m_nData << endl;

		// 메서드를 호출한 인스턴스의 CMyData 클래스 멤버 m_nData를 출력
		cout << this->CMyData::m_nData << endl;
	}
private:
	int m_nData;
};

class CTest {
public:
	CTest(int nParam) : m_nData(nParam) { };
	~CTest() {}

	// 상수형 메서드로 선언 및 정의
	int GetData() const {
		// 멤버 변수의 값을 읽을 수는 있지만 쓸 수는 없다.
		return m_nData;
	}

	int SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

void TestFunc(const int& nParam) {
	// 상수형 참조였으나 일반 참조로 형변환
	int& nNewParam = const_cast<int&>(nParam);
	// 따라서 l-value가 될 수 있다.
	nNewParam = 20;
}

class CMyData2 {
public:
	CMyData2() : m_nData(0) { };

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// 매개변수가 double 자료형인 경우로 다중 정의
	void SetData(double dParam) { m_nData = 0; }

private:
	int m_nData;
};

class CTest3 {
public:
	CTest3(int nParam) : m_nData(nParam) { m_nCount++; }
	int GetData() { return m_nData; };
	void ResetCount() { m_nCount = 0; }

	// 정적 메서드 선언 및 정의
	static int GetCount() {
		return m_nCount;
	}
private:
	int m_nData;

	// 정적 멤버 변수 선언 (정의는 아님)
	static int m_nCount;
};

int main() {
	// 예제 1. this 포인터 사용
	/*CMyData a(5), b(10);
	a.PrintData();
	b.PrintData();*/

	// 예제 2. const 예약어로 선언한 상수형 메서드
	/*CTest a(10);
	cout << a.GetData() << endl;*/

	// 예제 3. const_cast< >를 사용한 상수형 참조 변경
	//int nData = 10;

	// 예제 4. 상수형 참조로 전달하지만 값이 변경
	/*TestFunc(nData);
	cout << nData << endl;*/

	// 예제 5. 멤버 함수 다중 정의 1
	/*CMyData2 a2;

	a2.SetData(10);
	cout << a2.GetData() << endl;

	CMyData2 b2;
	b2.SetData(5.5);
	cout << b2.GetData() << endl;*/

	// 예제 6. static 예약어를 사용한 정적 멤버 선언 및 정의
	CTest3 a(5), b(10);

	// 정적 멤버에 접근
	cout << a.GetCount() << endl;
	b.ResetCount();

	// 정적 멤버에 접근. 인스턴스 없이도 접근 가능
	cout << CTest3::GetCount() << endl;




	return 0;
}
