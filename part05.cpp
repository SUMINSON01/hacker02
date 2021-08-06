// part05.cpp

#include<iostream>
#include<string>

using namespace std;

// 예제 1. 연산자 다중 정의와 이동 생성자 호출 시점
/*class CMyData {
public:
	// 변환 생성자
	CMyData(int nParam) :m_nData(nParam) {
		cout << "CMyData(int)" << endl;
	}

	// 이동 생성자
	CMyData(const CMyData&& rhs) : m_nData(rhs.m_nData) {
		cout << "CMyData(const CMyData &&)" << endl;
	}

	// 형변환
	operator int() { return m_nData; }

	// +
	CMyData operator+(const CMyData& rhs) {
		cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;
		
		return result;
	}

	// =
	CMyData& operator=(const CMyData& rhs) {
		cout << "operator=" << endl;
		m_nData = rhs.m_nData;

		return *this;
	}

private:
	int m_nData = 0;
};

int main() {
	cout << "*****Begin*****" << endl;
	CMyData a(0), b(3), c(4);

	// b + c 연산을 실행하면 이름 없는 임시 객체가 만들어지며 a에 대입하는 것이 이 임시 객체다.
	a = b + c;
	cout << a << endl;
	cout << "*****End*****" << endl;

	return 0;
}*/

// 예제 2. 대입 연산자 다중 정의
/*class CMyData {
public:
	explicit CMyData(int nParam) {
		m_pnData = new int(nParam);
	}

	~CMyData() { delete m_pnData; }

	operator int() { return *m_pnData; }

	// 단순 대입 연산자 다중 정의
	void operator=(const CMyData& rhs) {
		// r-value == l-value이면 대입 연산 수행 X
		if (this == &rhs)
			return;

		// 본래 가리키던 메모리를 삭제하고
		delete m_pnData;

		// 새로 할당한 메모리에 값을 저장
		m_pnData = new int(*rhs.m_pnData);
	}

	// += 연산자 함수 추가
	CMyData& operator+=(const CMyData& rhs) {
		// 현재 값 처리
		int* pnNewData = new int(*m_pnData);

		// 누적할 값 처리
		*pnNewData += *rhs.m_pnData;

		// 기존 데이터를 삭제하고 새 메모리로 대체
		delete m_pnData;
		m_pnData = pnNewData;

		return *this;
	}

	// 이동 대입 연산자 다중 정의
	CMyData& operator=(CMyData&& rhs) {
		cout << "operator=(Move)" << endl;

		// 얕은 복사를 수행하고 원본은 NULL로 초기화
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = NULL;

		return *this;
	}

private:
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(0), b(5);
	a = b;
	cout << a << endl;

	return 0;
}*/

// 예제 3. 배열 연산자
/*class CIntArray {
public:
	CIntArray(int nSize) {
		// 전달된 개수만큼 int 자료를 담을 수 있는 메모리 확보
		m_pnData = new int[nSize];
		memset(m_pnData, 0, sizeof(int) * nSize);
	}

	~CIntArray() { delete m_pnData; }

	// 상수형 참조인 경우의 배열 연산자
	int operator[](int nIndex) const {
		cout << "operator[] const" << endl;
		return m_pnData[nIndex];
	}

	// 일반적인 배열 연산자
	int& operator[](int nIndex) {
		cout << "operator[]" << endl;
		return m_pnData[nIndex];
	}

private:
	// 배열 메모리
	int* m_pnData;

	// 배열 요소의 개수
	int m_nSize;
};

void TestFunc(const CIntArray& arParam) {
	cout << "TestFunc()" << endl;

	// 상수형 참조이므로 'operator[](int nIndex) const'를 호출한다.
	cout << arParam[3] << endl;
}

int main() {
	CIntArray arr(5);
	for (int i = 0; i < 5; ++i) {
		arr[i] = i * 10;
	}

	TestFunc(arr);

	return 0;
}*/