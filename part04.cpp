// part04.cpp

#include<iostream>
#include<string>

using namespace std;


// ���� 1. ���� ������ ���� �� ����
/*class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }

	// ���� ������ ���� �� ����
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
	// ����Ʈ �����ڰ� ȣ��Ǵ� ���
	CMyData a;
	a.SetData(10);

	// ���� �����ڰ� ȣ��Ǵ� ���
	CMyData b(a);
	cout << b.GetData() << endl;

	return 0;
}*/

// ���� 2. �Ű������� ���Ǵ� ���� ������
/*class CTestData {
public:
	CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs) :m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}

	// �б� ������ ����� �޼���
	int GetData() const { return m_nData; }

	// ��� ������ ���⸦ �õ��ϴ� �޼���
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// �Ű������� CTestData Ŭ���� �����̹Ƿ� ���� �����ڰ� ȣ��ȴ�.
void TestFunc(CTestData param) {
	cout << "TestFunc()" << endl;

	// ��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� �����Ѵ�.
	param.SetData(20);
}

int main() {
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);

	// �Լ� ȣ�� �� a�� ���� ����Ѵ�.
	cout << "a: " << a.GetData() << endl;

	cout << "*****End*****" << endl;

	return 0;
}*/

// ���� 3. ���� ������ ������
/*int main() {
	// ��'��'
	int* pA, * pB;

	// �� ģ���� �ѳ� ź��
	pA = new int;
	*pA = 10;

	// �ڱ� ���� ģ�� ���ΰ� ģ���� ģ���� ������ ���� �ٺ�
	pB = new int;
	pB = pA;

	// �׷��� ��� �� ������ ��ó�� ���δ�.
	cout << *pA << endl;
	cout << *pB << endl;

	// �׷� �̰�?
	delete pA;
	delete pB;

	return 0;
}*/

// ���� 4. �����Ͱ� ���� ���� ������ ���
/*class CMyData {
public:
	CMyData() { cout << "CMyData()" << endl; }

	int GetData(void) const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// ����Ʈ �����ڰ� ȣ��Ǵ� ���
	CMyData a;
	a.SetData(10);

	// ���� �����ڰ� ȣ��Ǵ� ���
	CMyData b(a);
	cout << b.GetData() << endl;

	return 0;
}*/

// ���� 5. �����Ͱ� �������� ���� ���� ����
/*class CMyData {
public:
	CMyData(int nParam) {
		m_pnData = new int;
		*m_pnData = nParam;
	}
	CMyData(const CMyData &rhs) {
		cout << "CMyData(const CMyData &)" << endl;

		// �޸𸮸� �Ҵ��Ѵ�.
		m_pnData = new int;

		// �����Ͱ� ����Ű�� ��ġ�� ���� �����Ѵ�.
		*m_pnData = *rhs.m_pnData;
	}

	// ��ü�� �Ҹ��ϸ� ���� �Ҵ��� �޸𸮸� �����Ѵ�.
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
	// ������ ��� ������
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(a);
	cout << a.GetData() << endl;
	cout << b.GetData() << endl;

	return 0;
}*/

// ���� 6. �ùٸ��� ���� �����ڸ� ����ϴ� ����
/*class CMyData {
public:
	CMyData(int nParam) {
		m_pnData = new int;
		*m_pnData = nParam;
	}

	// ���� ������ ���� �� ����
	CMyData(const CMyData& rhs) {
		cout << "CMyData(const CMyData &)" << endl;

		// �޸� �Ҵ�
		m_pnData = new int;
		
		// �����Ͱ� ����Ű�� ��ġ�� �� ����
		*m_pnData = *rhs.m_pnData;
	}

	~CMyData() {
		delete m_pnData;
	}

	// �ܼ� ���� ������ �Լ� ����
	CMyData& operator=(const CMyData& rhs) {
		*m_pnData = *rhs.m_pnData;

		// ��ü �ڽſ� ���� ���� ��ȯ
		return *this;
	}

	int GetData() {
		if (m_pnData != NULL) {
			return *m_pnData;
		}
		return 0;
	}

private:
	// ������ ��� ������  
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(20);

	// �ܼ� ������ �õ��ϸ� ��� ����� ���� �״�� �����Ѵ�.
	a = b;
	cout << a.GetData() << endl;
}*/

// ���� 7. int �ڷ����� ��ȯ ������
/*class CTestData {
public:
	// �Ű������� �ϳ����� �����ڴ� ����ȯ�� ����
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

// ����� �ڵ�
// �Ű������� Ŭ���� �����̸� ��ȯ ���� ����
void TestFunc(const CTestData& param) {
	cout << "TestFunc(): " << param.GetData() << endl;
}

int main() {
	cout << "*****Begin*****" << endl;

	// ���ο� CTestData ��ü�� �����ϰ� ������ �����Ѵ�.
	TestFunc(5); // == TestFunc(CTestData(5));
	
	// �Լ��� ��ȯ�Ǹ鼭 �ӽ� ��ü�� �Ҹ��Ѵ�.
	cout << "*****End*****" << endl;
	return 0;
}*/

// ���� 8. ����ȯ �����ڸ� ���� �ڷ��� ��ȯ
/*class CTestData {
public:
	explicit CTestData(int nParam) : m_nData(nParam) {}

	// CTestData Ŭ������ int �ڷ������� ��ȯ�� �� �ִ�
	operator int(void) { return m_nData; }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	CTestData a(10);
	cout << a.GetData() << endl;

	// CTestData ���Ŀ��� int �ڷ������� ��ȯ�� �� �ִ�.
	cout << a << endl;
	cout << (int)a << endl; // C��� ��Ÿ��
	cout << static_cast<int>(a) << endl; // C++ ��Ÿ��

	return 0;
}*/

// ���� 9. �̸� ���� �ӽ� ��ü�� ������ �Ҹ�
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

		// ���� ���������� �̸�(m_pszName)�� �״�� �д�.
		m_nData = rhs.m_nData;

		return *this;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;

	// ���� �̸��� �����ϱ� ���� ���
	char* m_pszName = nullptr;
};

// CTestData ��ü�� ��ȯ�ϴ� �Լ�
CTestData TestFunc(int nParam) {
	// CTestData Ŭ���� �ν��Ͻ��� a�� ���� ������.
	// ���� �Լ��� ��ȯ�Ǹ� �Ҹ��Ѵ�.
	char name[2] = "a";
	CTestData a(nParam, name);

	return a;
}

int main() {
	char name[2] = "b";
	CTestData b(5, name);
	cout << "******Before*****" << endl;

	// �Լ��� ��ȯ�Ǹ餤�� �ӽ� ��ü�� �����ƴٰ� ���� ���� �� ��� �Ҹ��Ѵ�
	b = TestFunc(10);
	cout << "*****After*****" << endl;
	cout << b.GetData() << endl;

	return 0;
}*/

// ���� 10. r-value ������ ��� �� 1
/*/int main() {
	int&& data = 3 + 4;
	cout << data << endl;
	data++;
	cout << data << endl;

	return 0;
}*/

// ���� 11. r-value ������ ��� �� 2
/*void TestFunc(int& rParam) {
	cout << "TestFunc(int &)" << endl;
}

void TestFunc(int&& rParam) {
	cout << "TestFunc(int &&)" << endl;
}

int main() {
	// 3 + 4 ���� ����� r-value�̴�. ����� l-value�� �� �� ����.
	TestFunc(3 + 4);

	return 0;
}*/

// ���� 12. ���� ������ ��ȣ��
/*
// r-value ���� ����
void TestFunc(int&& rParam) {
	cout << "TestFunc(int &&)" << endl;
}

// r-value ���� ���İ� ȣ���� �ڵ尡 ����.
void TestFunc(int nParam) {
	cout << "TestFunc(int)" << endl;
}

int main() {
	// ��ȣ�� ȣ���̴�.
	TestFunc(3 + 4);
}*/

// ���� 13. �̵� �������� ȣ�� ����

class CTestData {
public:
	CTestData() { cout << "CTestData()" << endl; }
	~CTestData() { cout << "~CTestData()" << endl; }

	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}

	// �̵� ������
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