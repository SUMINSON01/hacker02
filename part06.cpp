// part06.cpp

#include<iostream>
#include<string>

using namespace std;

// ���� 1. ��� Ŭ���� �⺻
/*class CmyData {
public: // ������ ���� ����
	CmyData() { cout << "CMyData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected: // �Ļ� Ŭ������ ���� ����
	void PrintData() { cout << "CMyData::PrintData()" << endl; }

private: // ������ ���� �Ұ���
	int m_nData = 0;
};

class CMyDataEx : public CmyData {
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc() {
		// �⺻ ���� ����� ����
		PrintData();
		SetData(5);
		cout << CmyData::GetData() << endl;
	}
};

int main() {
	CMyDataEx data;

	// �⺻ Ŭ����(CMyData) ����� ����
	data.SetData(10);
	cout << data.GetData() << endl;

	// �Ļ� Ŭ����(CMyDataEx) ����� ����
	data.TestFunc();

	return 0;
}*/

// ���� 2. �޼��� ������ �⺻
/*class CMyData {
public:
	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }


private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData {
public:
	// �Ļ� Ŭ�������� �㺻 Ŭ������ �޼��带 ������
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
	// �������� ���� �����ϴ� ����� ����.
	CMyData a;
	a.SetData(-10);
	cout << a.GetData() << endl;

	// �������� ���� �����ϴ� ����� �ִ�.
	CMyDataEx b;
	b.SetData(15);
	cout << b.GetData() << endl;

	
	// ���� 3. �޼��� �����Ƿ� ���� ������ ����
	CMyDataEx a;
	CMyData& rData = a; // ������ ������ a�� �� ����, rData�� '���� ����'
	rData.SetData(15); // ���� ���� ȣ��
	cout << rData.GetData() << endl;



	return 0;
}*/

// ���� 3. ��� ������ �����ڿ� �Ҹ����� ȣ�� ����
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

// ���� 4. ������ �ʱ�ȭ ��Ͽ��� ������ ����
/*class CMyData {
public:
	CMyData() { cout << "CMyData()" << endl; }
	CMyData(int nParam) { cout << "CMyData(int)" << endl; }
	CMyData(double dParam) { cout << "CMyData(double)" << endl; }
};

class CMyDataEx :public CMyData {
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }

	// �⺻ Ŭ������ �� ���� ������ �߿��� int ������ ���� �����ڸ� �����ߴ�.
	CMyDataEx(int nParam) :CMyData(nParam) {
		cout << "CMyDataEx(int)" << endl;
	}

	// �⺻ Ŭ������ ����Ʈ �����ڸ� �����ߴ�.
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