// part09.cpp
// ���ø�

#include<iostream>
#include<string>

using namespace std;

// ���� 1. Ŭ���� ���ø�
/*template<typename T>
class CMyData {
public:
	CMyData(T param) :m_Data(param) {}
	T GetData() const { return m_Data; }

	// ���Ŀ� ���� ��ȯ�� ����
	operator T() { return m_Data; }
	void SetData(T param) { m_Data = param; }

private:
	// T ������ ��� ���� ����
	T m_Data;
};

int main() {
	CMyData<int> a(5);
	cout << a << endl;
	CMyData<double> b(123.45);
	cout << b << endl;

	// ���ڿ��� �����ϱ� ���� �޸𸮸� �������� �Ҵ������� �ʴ´�.
	CMyData<char*> c((char* )"Hello");
	cout << c << endl;


	return 0;
}*/

// ���� 2. Ŭ���� ���ø��� ���� �迭 ����
template<typename T>
class CMyArray {
public:
	explicit CMyArray(int nSize) : m_nSize(nSize) {
		m_pData = new T[nSize];
	}

	~CMyArray() { delete[] m_pData; }

	// ���� ������
	CMyArray(const CMyArray& rhs) {
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;
	}

	// ���� ������
	CMyArray& operator=(const CMyArraya& rhs) {
		if (this == &rhs)
			return *this;

		delete m_pData;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
		m_nSize = rhs.m_nSize;

		return *this;
	}

	// �̵� ������
	CMyArray(CMyArray&& rhs) {
		operator = (rhs);
	}

	// �̵� ���� ������
	CMyArray& operator=(const CMyArray&& rhs) {
		m_pData = rhs.m_pData;
		m_nSize = rhs.m_nSize;
		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	// �迭 ������
	T& operator[](int nIndex) {
		if (nIndex < 0 || nIndex >= m_nSize) {
			cout << "ERROR: �迭�� ��踦 ��� �����Դϴ�." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	// ���ȭ�� �迭 ������
	T& operator[](int nIndex) const {
		return operaotr[](nIndex);
	}

	// �迭 ����� ������ ��ȯ
	int GetSize() { return m_nSize; }


private:
	T* m_pData = nullptr;
	int m_nSize = 0;
};

int main() {
	// int �ڷ��� �迭
	CMyArray<int> arr(5);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << ' ';
	}

	cout << endl;

	CMyArray<int> arr2(3);
	arr2 = arr;
	for (int i = 0; i < 5; ++i) {
		cout << arr2[i] << ' ';
	}

	return 0;
}