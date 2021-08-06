// part05.cpp

#include<iostream>
#include<string>

using namespace std;

// ���� 1. ������ ���� ���ǿ� �̵� ������ ȣ�� ����
/*class CMyData {
public:
	// ��ȯ ������
	CMyData(int nParam) :m_nData(nParam) {
		cout << "CMyData(int)" << endl;
	}

	// �̵� ������
	CMyData(const CMyData&& rhs) : m_nData(rhs.m_nData) {
		cout << "CMyData(const CMyData &&)" << endl;
	}

	// ����ȯ
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

	// b + c ������ �����ϸ� �̸� ���� �ӽ� ��ü�� ��������� a�� �����ϴ� ���� �� �ӽ� ��ü��.
	a = b + c;
	cout << a << endl;
	cout << "*****End*****" << endl;

	return 0;
}*/

// ���� 2. ���� ������ ���� ����
/*class CMyData {
public:
	explicit CMyData(int nParam) {
		m_pnData = new int(nParam);
	}

	~CMyData() { delete m_pnData; }

	operator int() { return *m_pnData; }

	// �ܼ� ���� ������ ���� ����
	void operator=(const CMyData& rhs) {
		// r-value == l-value�̸� ���� ���� ���� X
		if (this == &rhs)
			return;

		// ���� ����Ű�� �޸𸮸� �����ϰ�
		delete m_pnData;

		// ���� �Ҵ��� �޸𸮿� ���� ����
		m_pnData = new int(*rhs.m_pnData);
	}

	// += ������ �Լ� �߰�
	CMyData& operator+=(const CMyData& rhs) {
		// ���� �� ó��
		int* pnNewData = new int(*m_pnData);

		// ������ �� ó��
		*pnNewData += *rhs.m_pnData;

		// ���� �����͸� �����ϰ� �� �޸𸮷� ��ü
		delete m_pnData;
		m_pnData = pnNewData;

		return *this;
	}

	// �̵� ���� ������ ���� ����
	CMyData& operator=(CMyData&& rhs) {
		cout << "operator=(Move)" << endl;

		// ���� ���縦 �����ϰ� ������ NULL�� �ʱ�ȭ
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

// ���� 3. �迭 ������
/*class CIntArray {
public:
	CIntArray(int nSize) {
		// ���޵� ������ŭ int �ڷḦ ���� �� �ִ� �޸� Ȯ��
		m_pnData = new int[nSize];
		memset(m_pnData, 0, sizeof(int) * nSize);
	}

	~CIntArray() { delete m_pnData; }

	// ����� ������ ����� �迭 ������
	int operator[](int nIndex) const {
		cout << "operator[] const" << endl;
		return m_pnData[nIndex];
	}

	// �Ϲ����� �迭 ������
	int& operator[](int nIndex) {
		cout << "operator[]" << endl;
		return m_pnData[nIndex];
	}

private:
	// �迭 �޸�
	int* m_pnData;

	// �迭 ����� ����
	int m_nSize;
};

void TestFunc(const CIntArray& arParam) {
	cout << "TestFunc()" << endl;

	// ����� �����̹Ƿ� 'operator[](int nIndex) const'�� ȣ���Ѵ�.
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