// part04.cpp

#include<iostream>
#include<string>

using namespace std;


// 예제 1. 복사 생성자 선언 및 정의
/*class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }

	// 복사 생성자 선언 및 정의
	CMyData(const CMyData& rhs)
		// : m_Data(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyData(const CMyData &)" << endl;
	}
		int GetData(void) const { return m_nData; }
		void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// 디폴트 생성자가 호출되는 경우
	CMyData a;
	a.SetData(10);

	// 복사 생성자가 호출되는 경우
	CMyData b(a);
	cout << b.GetData() << endl;

	return 0;
}*/

// 예제 2. 매개변수로 사용되는 복사 생성자
/*class CTestData {
public:
	CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs) :m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}

	// 읽기 전용인 상수형 메서드
	int GetData() const { return m_nData; }

	// 멤버 변수에 쓰기를 시도하는 메서드
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// 매개변수가 CTestData 클래스 형식이므로 복사 생성자가 호출된다.
void TestFunc(CTestData param) {
	cout << "TestFunc()" << endl;

	// 피호출자 함수에서 매개변수 인스턴스의 값을 변경한다.
	param.SetData(20);
}

int main() {
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);

	// 함수 호출 후 a의 값을 출력한다.
	cout << "a: " << a.GetData() << endl;

	cout << "*****End*****" << endl;

	return 0;
}*/

// 예제 3. 얇은 복사의 문제점
/*int main() {
	// 그'들'
	int* pA, * pB;

	// 한 친구의 ㅡ녀 탄생
	pA = new int;
	*pA = 10;

	// 자기 여자 친구 놔두고 친구의 친구를 마음에 담은 바보
	pB = new int;
	pB = pA;

	// 그렇게 모두 잘 지내는 것처럼 보인다.
	cout << *pA << endl;
	cout << *pB << endl;

	// 그럼 이건?
	delete pA;
	delete pB;

	return 0;
}*/

// 예제 4. 포인터가 없는 복사 생성자 사용
/*class CMyData {
public:
	CMyData() { cout << "CMyData()" << endl; }

	int GetData(void) const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// 디폴트 생성자가 호출되는 경루
	CMyData a;
	a.SetData(10);

	// 복사 생성자가 호출되는 경우
	CMyData b(a);
	cout << b.GetData() << endl;

	return 0;
}*/

// 예제 5. 포인터가 존재했을 때의 얕은 복사
/*class CMyData {
public:
	CMyData(int nParam) {
		m_pnData = new int;
		*m_pnData = nParam;
	}
	CMyData(const CMyData &rhs) {
		cout << "CMyData(const CMyData &)" << endl;

		// 메모리를 할당한다.
		m_pnData = new int;

		// 포인터가 가리키는 위치에 값을 복사한다.
		*m_pnData = *rhs.m_pnData;
	}

	// 객체가 소멸하면 동적 할당한 메모리를 해제한다.
	~CMyData() {
		delete m_pnData;
	}

	int GetData() {
		if (m_pnData != NULL) {
			return *m_pnData;
		}
		return 0;
	}

private:
	// 포인터 멤버 데이터
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(a);
	cout << a.GetData() << endl;
	cout << b.GetData() << endl;

	return 0;
}*/

// 예제 6. 올바르게 복사 생성자를 사용하는 예제
/*class CMyData {
public:
	CMyData(int nParam) {
		m_pnData = new int;
		*m_pnData = nParam;
	}

	// 복사 생성자 선언 및 정의
	CMyData(const CMyData& rhs) {
		cout << "CMyData(const CMyData &)" << endl;

		// 메모리 할당
		m_pnData = new int;
		
		// 포인터가 가르키는 위치에 값 복사
		*m_pnData = *rhs.m_pnData;
	}

	~CMyData() {
		delete m_pnData;
	}

	// 단순 대입 연산자 함수 정의
	CMyData& operator=(const CMyData& rhs) {
		*m_pnData = *rhs.m_pnData;

		// 객체 자신에 대한 참조 반환
		return *this;
	}

	int GetData() {
		if (m_pnData != NULL) {
			return *m_pnData;
		}
		return 0;
	}

private:
	// 포인터 멤버 데이터  
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(20);

	// 단순 대입을 시도하면 모든 멤버의 값을 그대로 복사한다.
	a = b;
	cout << a.GetData() << endl;
}*/

// 예제 7. int 자료형의 변환 생성자
/*class CTestData {
public:
	// 매개변수가 하나뿐인 생성자는 형변환이 가능
	CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}

	~CTestData() {
		cout << "~CTestData()" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// 사용자 코드
// 매개변수가 클래스 형식이며 변환 생성 가능
void TestFunc(const CTestData& param) {
	cout << "TestFunc(): " << param.GetData() << endl;
}

int main() {
	cout << "*****Begin*****" << endl;

	// 새로운 CTestData 객체를 생성하고 참조로 전달한다.
	TestFunc(5); // == TestFunc(CTestData(5));
	
	// 함수가 반환되면서 임시 객체는 소멸한다.
	cout << "*****End*****" << endl;
	return 0;
}*/

// 예제 8. 형변환 연산자를 통한 자료형 변환
/*class CTestData {
public:
	explicit CTestData(int nParam) : m_nData(nParam) {}

	// CTestData 클래스는 int 자료형으로 변환될 수 있다
	operator int(void) { return m_nData; }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	CTestData a(10);
	cout << a.GetData() << endl;

	// CTestData 형식에서 int 자료형으로 변환될 수 있다.
	cout << a << endl;
	cout << (int)a << endl; // C언어 스타일
	cout << static_cast<int>(a) << endl; // C++ 스타일

	return 0;
}*/

// 예제 9. 이름 없는 임시 객체의 생성과 소멸
/*class CTestData {
public:
	CTestData(int nParam, char* pszName) : m_nData(nParam), m_pszName(pszName) {
		cout << "CTestData(int): " << m_pszName << endl;
	}

	~CTestData() {
		cout << "~CTestData(): " << m_pszName << endl;
	}

	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData), m_pszName(m_pszName) {
		cout << "CTestData(const CTestData &): " << m_pszName << endl;
	}

	CTestData& operator=(const CTestData& rhs) {
		cout << "operator=" << endl;

		// 값은 변경하지만 이름(m_pszName)은 그대로 둔다.
		m_nData = rhs.m_nData;

		return *this;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;

	// 변수 이름을 저장하기 위한 멤버
	char* m_pszName = nullptr;
};

// CTestData 객체를 반환하는 함수
CTestData TestFunc(int nParam) {
	// CTestData 클래스 인스턴스인 a는 지역 변수다.
	// 따라서 함수가 반환되면 소멸한다.
	char name[2] = "a";
	CTestData a(nParam, name);

	return a;
}

int main() {
	char name[2] = "b";
	CTestData b(5, name);
	cout << "******Before*****" << endl;

	// 함수가 반환되면ㄴ서 임시 객체가 생성됐다가 대입 연산 후 즉시 소멸한다
	b = TestFunc(10);
	cout << "*****After*****" << endl;
	cout << b.GetData() << endl;

	return 0;
}*/

// 예제 10. r-value 참조의 사용 예 1
/*/int main() {
	int&& data = 3 + 4;
	cout << data << endl;
	data++;
	cout << data << endl;

	return 0;
}*/

// 예제 11. r-value 참조의 사용 예 2
/*void TestFunc(int& rParam) {
	cout << "TestFunc(int &)" << endl;
}

void TestFunc(int&& rParam) {
	cout << "TestFunc(int &&)" << endl;
}

int main() {
	// 3 + 4 연산 결과는 r-value이다. 절대로 l-value가 될 수 없다.
	TestFunc(3 + 4);

	return 0;
}*/

// 예제 12. 다중 정의의 모호성
/*
// r-value 참조 형식
void TestFunc(int&& rParam) {
	cout << "TestFunc(int &&)" << endl;
}

// r-value 참조 형식과 호출자 코드가 같다.
void TestFunc(int nParam) {
	cout << "TestFunc(int)" << endl;
}

int main() {
	// 모호한 호출이다.
	TestFunc(3 + 4);
}*/

// 예제 13. 이동 생성자의 호출 시점

class CTestData {
public:
	CTestData() { cout << "CTestData()" << endl; }
	~CTestData() { cout << "~CTestData()" << endl; }

	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}

	// 이동 생성자
	CTestData(CTestData&& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(CTestData &&)" << endl;
	}
	CTestData& operator=(const CTestData&) = default;

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

CTestData TestFunc(int nParam) {
	cout << "**TestFunc(): Begin***" << endl;
	CTestData a;
	a.SetData(nParam);
	cout << "**TestFunc(): End*****" << endl;

	return a;
}

int main() {
	CTestData b;
	cout << "*Before**********" << endl;
	b = TestFunc(20);
	cout << "*After**********" << endl;
	CTestData c(b);

	return 0;
}