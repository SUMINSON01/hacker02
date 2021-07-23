// part4_FunctionAndClass.cpp

#include<iostream>
#include "part4_FunctionAndClass.h"

using namespace std;

CTestData {
	CTestData::CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}
	CTestData::CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestDataa &)" << endl;
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

void functionAndClass() {
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);

	// �Լ� ȣ�� �� a�� ���� ���
	cout << "a: " << a.GetData() << endl;

	cout << "*****End*****" << endl;

}