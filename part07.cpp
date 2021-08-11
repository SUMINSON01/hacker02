// part07.cpp

#include<iostream>
#include<string>

using namespace std;

// ���� 1. ���� �Լ� ����
/*class CMyData {
public:
	// ���� �Լ��� ���� �� ����
	virtual void PrintData() {
		cout << "CMyData: " << m_nData << endl;
	}

	void TestFunc() {
		cout << "***TestFunc***" << endl;

		// �� ������ �Լ��� ȣ��ȴ�
		PrintData();
		cout << "***************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx : public CMyData {
public:
	// �⺻ Ŭ������ ���� �Լ� ����� �������ߴ�.
	// ���� ���� ���Ǵ� ���õȴ�.
	virtual void PrintData() {
		cout << "CMyDataEx: " << m_nData * 2 << endl;
	}
};

int main() {
	CMyDataEx a;
	a.PrintData();

	CMyData& b = a;

	// ���� ���Ŀ� ������� �� ������ �Լ��� ȣ��ȴ�.
	b.PrintData();

	// �� �������� �����ǵ��Լ��� ȣ��ȴ�
	a.TestFunc();

	return 0;
}*/

// ���� 2. �Ҹ��� ����ȭ
/*class CMyData {
public:
	CMyData() { m_pszData = new char[32]; }
	// �Ҹ��ڸ� ���� �Լ��� ����
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

	// ���� ���Ŀ� �´� �Ҹ��ڰ� ȣ��ȴ�.
	delete pData;

	return 0;	
}*/

// ���� 3. vtablee ����
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

// ���� 4. �̸� ���ε�
/*void TestFunc(int nParam) { }

int main() {
	TestFunc(10);

	return 0;
}*/

// ���� 5. ���� ���ε�
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

// ���� 6. ���� ���� Ŭ���� ����
/*class CMyInterface {
public:
	CMyInterface() {
		cout << "CMyInterface()" << endl;
	}

	// ���� �ְ� ���Ǵ� ���� ���� ���� �Լ�
	virtual int GetData() const = 0;
	virtual void SetData(int nParam) = 0;
};

class CMyData :public CMyInterface {
public:
	CMyData() { cout << "CMyData()" << endl; }

	// ���� ���� �Լ��� �Ļ� Ŭ�������� '�ݵ��' �����ؾ� �Ѵ�.
	virtual int GetData() const { return m_nData; }
	virtual void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// ���� ���� Ŭ������ �ν��Ͻ��� ���� �� ������ �� ����.
	// CMyInterface a;
	CMyData a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}*/

// ���� 7. �������̽�
/*class CMyObject {
public:
	CMyObject() { }
	virtual ~CMyObject() { }

	// ��� �Ļ� Ŭ������ �� �޼��带 �����ٰ� ������ �� �ִ�.
	virtual int GetDeviceID() = 0;

protected:
	int m_nDeviceID;
};

// �ʱ� �����ڰ� ���� �Լ�
void PrintID(CMyObject* pObj) {
	// ������ � �������� ������ �׷��� ID�� ����� �� �մ�.
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

	// ���� ��ü�� �����̵� �˾Ƽ� �ڽ��� ID�� ����Ѵ�.
	::PrintID(&a);
	::PrintID(&b);

	return 0;
}*/

// ���� 8. �߻� �ڷ����� ��� ��
/*#define DEFAULT_FARE 1000

class CPerson {
public:
	CPerson() { }
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// ��� ��� �������̽�(���� ���� �Լ�)
	virtual void CalcFare() = 0; // �� �Լ��� �����Լ��̹Ƿ� ����� �Է¿� ���� ������ ������ '�� ����'�� CalcFare() �Լ��� ȣ�� ��.
								 // ���� if���̳� wsitch-case���� ������ �������� �����ؾ� �� ����� ���� �þ�� �þ���� ������ �������ٴ� ��

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

class CBaby : public CPerson {
public:
	// ������(0~7��) ��� ���
	virtual void CalcFare() {
		m_nFare = 0; // 0%
	}
};

class CChild : public CPerson {
public:
	// ���(8~13��) ��� ���
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 50 / 100; // 50%
	}
};

class CTeen : public CPerson {
public:
	// ����(20�� �̻�) ��� ���
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE * 75 /100; // 75%
	}
};

class CAdult : public CPerson {
public:
	// ����(20�� �̻�) ��� ���
	virtual void CalcFare() {
		m_nFare = DEFAULT_FARE;			// 100%
	}
};

int main() {
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	// 1. �ڷ� �Է�: ����� �Է¿� ���� ������ ��ü ����
	for (auto& person : arList) {
		cout << "���̸� �Է��ϼ��� : ";
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

		// ������ ��ü�� �´� ����� �ڵ����� ���ȴ�.
		person->CalcFare();
	}

	// 2. �ڷ� ���: ����� ����� Ȱ���ϴ� �κ�
	for (auto person : arList) {
		cout << person->GetFare() << "��" << endl;
	}

	// 3. �ڷ� ���� �� ����
	for (auto person : arList) {
		delete person;
	}

	return 0;
}*/

// ���� 9. static_cast ��� ��
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
	// �Ļ� ������ ��ü�� �⺻ �������� �������մϴ�.
	CMyData* pData = new CMyDataEx;
	CMyDataEx* pNewData = NULL;

	// CMyData::SetData() �Լ��� ȣ���մϴ�.
	// ���� 10�� �Ѵ��� �˻����� �ʽ��ϴ�.
	pData->SetData(15);

	// �⺻ ���Ŀ� ���� �������̳� ����Ű�� ����� �Ļ� �����Դϴ�.
	// �� ����� ��Ȯ�ϹǷ� �Ļ� ���Ŀ� ���� �����ͷ� ����ȯ�� �õ��մϴ�.
	pNewData = static_cast<CMyDataEx*>(pData);
	pNewData->PrintData();
	delete pData;

	return 0;
}*/

// ���� 10. dynamic_cast ��� ��
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
	cout << "���� ��ȣ�� �Է��ϼ���. [1:�簢��, 2:��]: " << endl;
	int nInput = 0;
	cin >> nInput;

	CShape* pShape = nullptr;
	if (nInput == 1)
		pShape = new CRectangle;

	else if (nInput == 2)
		pShape = new CCircle;

	else
		pShape = new CShape;

	// ���� ��
	pShape->Draw();

	// ���� ��. å 346p ����
}*/

// ���� 11. �Ļ� Ŭ������ ������ ���� ����
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

	// �˸��̴� �״�� ����Ŭ������ ���� ����ϰ� �������̽��� ���� �Ÿ� �Ʒ� �ڵ� ���
	// �������̽��� �����ֱ� ���� ������ ���� ����
	using CMyData::operator+;
	using CMyData::operator=;
};

int main() {
	CMyData a(3), b(4);
	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);

	// CMyDataEx Ŭ������ �´� �ܼ� ���� �����ڰ� ��� ������ ������ �߻��Ѵ�.
	e = c + d;
	cout << e << endl;

	return 0;
}*/

// ���� 12. ���� ���
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

// �� Ŭ������ ��� ��ӹ޴´�.
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

// ���� 13. ���� ��� ����
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

// ���� 14. �������̽� ���� ���
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
	// USB �������̽�
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// �ø��� �������̽�
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main() {
	CMyDevice dev;

	return 0;
}