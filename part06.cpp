// part06.cpp

#include<iostream>
#include<string>

using namespace std;

// 예제 1. 상속 클래스 기본
/*class CmyData {
public: // 누구나 접근 간으
	CmyData() { cout << "CMyData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected: // 파생 클래스만 접근 가능
	void PrintData() { cout << "CMyData::PrintData()" << endl; }

private: // 누구도 접근 불가능
	int m_nData = 0;
};

class CMyDataEx : public CmyData {
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc() {
		// 기본 형식 멤버에 접근
		PrintData();
		SetData(5);
		cout << CmyData::GetData() << endl;
	}
};

int main() {
	CMyDataEx data;

	// 기본 클래스(CMyData) 멤버에 접근
	data.SetData(10);
	cout << data.GetData() << endl;

	// 파생 클래스(CMyDataEx) 멤버에 접근
	data.TestFunc();

	return 0;
}*/

// 예제 2. 메서드 재정의 기본
/*class CMyData {
public:
	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }


private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData {
public:
	// 파생 클래스에서 긱본 클래스의 메서드를 재정의
	void SetData(int nParam) {
		if (nParam < 0) {
			CMyData::SetData(0);
		}

		if (nParam > 10) {
			CMyData::SetData(10);
		}
	}
};

int main() {
	// 구형에는 값을 보정하는 기능이 없다.
	CMyData a;
	a.SetData(-10);
	cout << a.GetData() << endl;

	// 신형에는 값을 보정하는 기능이 있다.
	CMyDataEx b;
	b.SetData(15);
	cout << b.GetData() << endl;

	
	// 예제 3. 메서드 재정의로 원본 형식을 참조
	CMyDataEx a;
	CMyData& rData = a; // 참조의 원본인 a는 실 형식, rData는 '참조 형식'
	rData.SetData(15); // 참조 형식 호출
	cout << rData.GetData() << endl;



	return 0;
}*/

// 예제 3. 상속 관계의 생성자와 소멸자의 호출 순서
/*class CMyDataA {
public:
	CMyDataA() { cout << "CMyDataA()" << endl; }

	~CMyDataA() { cout << "~CMyDataA()" << endl; }
};

class CMyDataB : public CMyDataA {
public:
	CMyDataB() { cout << "CMyDataB()" << endl; }
	
	~CMyDataB() { cout << "~CMyDataB()" << endl; }
};

class CMyDataC : public CMyDataB {
public:
	CMyDataC() { cout << "CMyDataC()" << endl; }
	
	~CMyDataC() { cout << "~CMyDataC()" << endl; }
};

int main() {
	cout << "*****Begin*****" << endl;
	CMyDataC data;
	cout << "*****End*****" << endl;

	return 0;
}*/

// 예제 4. 생성자 초기화 목록에서 생성자 선택
/*class CMyData {
public:
	CMyData() { cout << "CMyData()" << endl; }
	CMyData(int nParam) { cout << "CMyData(int)" << endl; }
	CMyData(double dParam) { cout << "CMyData(double)" << endl; }
};

class CMyDataEx :public CMyData {
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }

	// 기본 클래스의 세 가지 생성자 중에서 int 변수를 갖는 생성자를 선택했다.
	CMyDataEx(int nParam) :CMyData(nParam) {
		cout << "CMyDataEx(int)" << endl;
	}

	// 기본 클래스의 디폴트 생성자를 선택했다.
	CMyDataEx(double) :CMyData() {
		cout << "CMyDataEx(double)" << endl;
	}
};

int main() {
	CMyDataEx a;
	cout << "**********" << endl;
	CMyDataEx b(5);
	cout << "**********" << endl;
	CMyDataEx(3.3);
}*/