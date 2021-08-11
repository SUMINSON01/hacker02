// part07.cpp

#include<iostream>
#include<string>

using namespace std;

// 예제 1. 가상 함수 정의
/*class CMyData {
public:
	// 가상 함수로 선언 및 정의
	virtual void PrintData() {
		cout << "CMyData: " << m_nData << endl;
	}

	void TestFunc() {
		cout << "***TestFunc***" << endl;

		// 실 형식의 함수가 호출된다
		PrintData();
		cout << "***************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx : public CMyData {
public:
	// 기본 클래스의 가상 함수 멤버를 재정의했다.
	// 따라서 기존 정의는 무시된다.
	virtual void PrintData() {
		cout << "CMyDataEx: " << m_nData * 2 << endl;
	}
};

int main() {
	CMyDataEx a;
	a.PrintData();

	CMyData& b = a;

	// 참조 형식에 상관없이 실 형식의 함수가 호출된다.
	b.PrintData();

	// 늘 마지막에 재정의된함수가 호출된다
	a.TestFunc();

	return 0;
}*/

// 예제 2. 소멸자 가상화
/*class CMyData {
public:
	CMyData() { m_pszData = new char[32]; }
	// 소멸자를 가상 함수로 선언
	virtual ~CMyData() {
	cout << "~CMyData()" << endl;
	delete m_pszData;
	}

private:
	char* m_pszData;
};

class CMyDataEx :public CMyData {
public:
	CMyDataEx() { m_pnData = new int; }
	~CMyDataEx() {
		cout << "~CMyDataEx()" << endl;
	}

private:
	int* m_pnData;
};

int main() {
	CMyData* pData = new CMyDataEx;

	// 참조 형식에 맞는 소멸자가 호출된다.
	delete pData;

	return 0;	
}*/

// 예제 3. vtablee 구현
/*class CMyData {
public:
	CMyData() {
		cout << "CMyData()" << endl;
	}

	virtual ~CMyData() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2() { }
};

class CMyDataEx :public CMyData {
public:
	CMyDataEx() {
		cout << "CMyDataEx()" << endl;
	}

	virtual ~CMyDataEx() { }
	virtual void TestFunc1() { }
	virtual void TestFunc2() {
		cout << "TesstFunc2()" << endl;
	}
};

int main() {
	CMyData* pData = new CMyDataEx;
	pData->TestFunc2();
	delete pData;

	return 0;
}*/

// 예제 4. 이른 바인딩
/*void TestFunc(int nParam) { }

int main() {
	TestFunc(10);

	return 0;
}*/

// 예제 5. 늦은 바인딩
/*void TestFunc1(int nParam) { }
void TestFunc2(int nParam) { }

int main() {
	int nInput = 0;
	cin >> nInput;
	void(*pfTest)(int) = NULL;

	if (nInput > 10) {
		pfTest = TestFunc1;
	}

	else {
		pfTest = TestFunc2;
	}

	pfTest(10);

	return 0;
}*/

// 예제 6. 순수 가상 클래스 정의
/*class CMyInterface {
public:
	CMyInterface() {
		cout << "CMyInterface()" << endl;
	}

	// 선언만 있고 정의는 없는 순수 가상 함수
	virtual int GetData() const = 0;
	virtual void SetData(int nParam) = 0;
};

class CMyData :public CMyInterface {
public:
	CMyData() { cout << "CMyData()" << endl; }

	// 순수 가상 함수는 파생 클래스에서 '반드시' 정의해야 한다.
	virtual int GetData() const { return m_nData; }
	virtual void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// 순수 가상 클래스는 인스턴스를 선언 및 정의할 수 없다.
	// CMyInterface a;
	CMyData a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}*/

// 예제 7. 인터페이스
/*class CMyObject {
public:
	CMyObject() { }
	virtual ~CMyObject() { }

	// 모든 파생 클래스는 이 메서드를 가졌다고 가정할 수 있다.
	virtual int GetDeviceID() = 0;

protected:
	int m_nDeviceID;
};

// 초기 제작자가 만든 함수
void PrintID(CMyObject* pObj) {
	// 실제로 어떤 것일지는 모르지만 그래도 ID는 출력할 수 잇다.
	cout << "Device ID: " << pObj->GetDeviceID() << endl;
}

class CMyTV : public CMyObject {
public:
	CMyTV(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID() {
		cout << "CMyTV::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

class CMyPhone : public CMyObject {
public:
	CMyPhone(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID() {
		cout << "CMyPhone::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

int main() {
	CMyTV a(5);
	CMyPhone b(10);

	// 실제 객체가 무엇이든 알아서 자신의 ID를 출력한다.
	::PrintID(&a);
	::PrintID(&b);

	return 0;
}*/

// 예제 8. 추상 자료형의 사용 예
/*#define DEFAULT_FARE 1000

class CPerson {
public:
	CPerson() { }
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// 요금 계산 인터페이스(순수 가상 함수)
	virtual void CalcFare() = 0; // 이 함수가 가상함수이므로 사용자 입력에 따라 실제로 생성된 '실 형식'의 CalcFare() 함수가 호출 됨.
								 // 다중 if문이나 wsitch-case문의 구조적 문제점은 생각해야 할 경우의 수가 늘어나면 늘어날수록 성능이 떨어진다는 점

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

class CBaby : public CPerson {
public:
	// 영유아(0~7세) 요금 계산
	virtual void CalcFare() {
		m_nFare = 0; // 0%
	}
};

class CChild : public CPerson {
public:
	// 어린이(8~13세) 요금 계산
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 50 / 100; // 50%
	}
};

class CTeen : public CPerson {
public:
	// 성인(20세 이상) 요금 계산
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 75 /100; // 75%
	}
};

class CAdult : public CPerson {
public:
	// 성인(20세 이상) 요금 계산
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE;			// 100%
	}
};

int main() {
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	// 1. 자료 입력: 사용자 입력에 따라서 생성할 객체 선택
	for (auto& person : arList) {
		cout << "나이를 입력하세요 : ";
		cin >> nAge;
		if (nAge < 8) {
			person = new CBaby;
		}
		else if (nAge < 14) {
			person = new CChild;
		}
		else if (nAge < 20) {
			person = new CTeen;
		}
		else {
			person = new CAdult;
		}

		// 생성한 객체에 맞는 요금이 자동으로 계산된다.
		person->CalcFare();
	}

	// 2. 자료 출력: 계산한 요금을 활용하는 부분
	for (auto person : arList) {
		cout << person->GetFare() << "원" << endl;
	}

	// 3. 자료 삭제 및 종료
	for (auto person : arList) {
		delete person;
	}

	return 0;
}*/

// 예제 9. static_cast 사용 예
/*class CMyData {
public:
	CMyData() { }
	virtual ~CMyData() { }
	void SetData(int nParam) { m_nData = nParam; }
	int GetData() { return m_nData; }

private:
	int m_nData = 0;
};

class CMyDataEx :public CMyData {
public:
	void SetData(int nParam) {
		if (nParam > 10) {
			nParam = 10;
		}

		CMyData::SetData(nParam);
	}

	void PrintData() {
		cout << "PrintData(): " << GetData() << endl;
	}
};

int main() {
	// 파생 형식의 객체를 기본 형식으로 포인팅합니다.
	CMyData* pData = new CMyDataEx;
	CMyDataEx* pNewData = NULL;

	// CMyData::SetData() 함수를 호출합니다.
	// 따라서 10이 넘는지 검사하지 않습니다.
	pData->SetData(15);

	// 기본 형식에 대한 포인터이나 가리키는 대상은 파생 형식입니다.
	// 이 사실이 명확하므로 파생 형식에 대한 포인터로 형변환을 시도합니다.
	pNewData = static_cast<CMyDataEx*>(pData);
	pNewData->PrintData();
	delete pData;

	return 0;
}*/

// 예제 10. dynamic_cast 사용 예
/*class CShape {
public:
	CShape() { }
	virtual ~CShape() { }
	virtual void Draw() { cout<<"CShape::Draw()"<<endl; }
};

class CRectangle : public CShape {
public:
	virtual void Draw() { cout << "CRectangle::Draw()" << endl; }
};

class CCircle : public CShape {
public:
	virtual void Draw() { cout << "CCircle::Draw()" << endl; }
};

int main() {
	cout << "도형 번호를 입력하세요. [1:사각형, 2:원]: " << endl;
	int nInput = 0;
	cin >> nInput;

	CShape* pShape = nullptr;
	if (nInput == 1)
		pShape = new CRectangle;

	else if (nInput == 2)
		pShape = new CCircle;

	else
		pShape = new CShape;

	// 좋은 예
	pShape->Draw();

	// 나쁜 예. 책 346p 참고
}*/

// 예제 11. 파생 클래스의 연산자 다중 정의
/*class CMyData {
public:
	CMyData(int nParam) : m_nData(nParam) { }

	CMyData operator+(const CMyData& rhs) {
		return CMyData(m_nData + rhs.m_nData);
	}
	
	CMyData& operator=(const CMyData& rhs) {
		m_nData = rhs.m_nData;

		return *this;
	}

	operator int() { return m_nData; }
	
protected:
	int m_nData = 0;
};

class CMyDataEx : public CMyData {
public:
	CMyDataEx(int nParam) : CMyData(nParam) { }
	//CMyDataEx operator+(const CMyDataEx& rhs) {
	//	return CMyDataEx(static_cast<int>(CMyData::operator+(rhs)));
	//}

	// 알맹이는 그대로 상위클래스의 것을 사용하고 인터페이스만 맞출 거면 아래 코드 사용
	// 인터페이스를 맞춰주기 위한 연산자 다중 정의
	using CMyData::operator+;
	using CMyData::operator=;
};

int main() {
	CMyData a(3), b(4);
	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);

	// CMyDataEx 클래스에 맞는 단순 대입 연산자가 없어서 컴파일 오류가 발생한다.
	e = c + d;
	cout << e << endl;

	return 0;
}*/

// 예제 12. 다중 상속
/*class CMyImage {
public:
	CMyImage(int nHeight, int nWidth) : m_nHeight(nHeight), m_nWidth(nWidth){
		cout << "CMyImage(int, int)" << endl;
	}

	int GetHeight() const { return m_nHeight; }
	int GetWidth() const { return m_nWidth; }

protected:
	int m_nHeight;
	int m_nWidth;
};

class CMyShape {
public:
	CMyShape(int nType) : m_nType(nType) {
		cout << "CMyShape(int)" << endl;
	}

	int GetType() const { return m_nType; }

protected:
	int m_nType;
};

// 두 클래스를 모두 상속받는다.
class CMyPicture : public CMyImage, public CMyShape {
public:
	CMyPicture() : CMyImage(200, 120), CMyShape(1) {
		cout << "CMyPicture()" << endl;
	}
};

int main() {
	CMyPicture a;
	cout << "Width: " << a.GetWidth() << endl;
	cout << "Height: " << a.GetHeight() << endl;
	cout << "Type: " << a.GetType() << endl;

	return 0;
}*/

// 예제 13. 가상 상속 적용
/*class CMyObject {
public:
	CMyObject() { cout << "CMyObject()" << endl; }
	virtual ~CMyObject() { }
};

class CMyImage : virtual public CMyObject {
public:
	CMyImage() { cout << "CMyImage(int, int)" << endl; }
};

class CMyShape : virtual public CMyObject {
public:
	CMyShape() { cout << "CMyShape(int)" << endl; }
};

class CMyPicture : public CMyImage, public CMyShape {
public:
	CMyPicture() { cout << "CMyPicture()" << endl; }
};

int main() {
	CMyPicture a;
}*/

// 예제 14. 인터페이스 다중 상속
class CMyUSB {
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial {
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial {
public:
	// USB 인터페이스
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// 시리얼 인터페이스
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main() {
	CMyDevice dev;

	return 0;
}