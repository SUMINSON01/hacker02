// part08.cpp
// ������ ����� ���� ����

#include<iostream>
#include<string>

using namespace std;

// ���� 1. friend �Լ�
/*class CMyData {
public:
	CMyData(int nParam) : m_nData(nParam) {};
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// friend �Լ� ����
	friend void PrintData(const CMyData&);

private:
	int m_nData = 0;
};

void PrintData(const CMyData& rData) {
	// ������ �Լ��̹Ƿ� ���� ���� �������� ������ ���� �ʰ�
	// private ����� ���� �����Ѵ�.
	cout << "PrintData(): " << rData.m_nData << endl;
}

int main() {
	CMyData a(5);
	PrintData(a);

	return 0;
}*/

// ���� 2. friend ���� ������ Ŭ����
/*class CNode {
	// friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// ���� ���� ����Ʈ�� ������ ������
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// ����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode) {
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char* pszName) {
		CNode* pNode = new CNode(pszName);
		
		// ����Ʈ�� ���ο� ��带 �߰�
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

private:
	CNode m_HeadNode;
};

int main() {
	// �޸� �߰� / ���� �ڵ尡 �������� �ʴ´�.
	CMyList list;
	list.AddNewNode("�浿");
	list.AddNewNode("ö��");
	list.AddNewNode("����");

	return 0;
}*/

// ���� 3. Composition ����
/* // �ڷᱸ�� Ŭ����
class CNode {
	// friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// ���� ���� ����Ʈ�� ������ ������
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// ����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode) {
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	// ����Ʈ�� ���ο� ��� �߰�
	void AddNewNode(const char* pszName) {
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// ����Ʈ�� ��� ��� ���� ���
	void Print() {
		CNode* pNode = m_HeadNode.pNext;
		while (pNode) {
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

// UI Ŭ����
class CMyUI {
public:
	// �޴� ��� �� ����� �Է� Ȯ��
	int PrintMenu() {
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// ���������� �޴��� ����ϴ� ���� �̺�Ʈ �ݺ���
	void Run() {
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0) {
			switch (nInput) {
			case 1: // Add
				cout << "�̸�: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;

			case 2: // Print
				m_list.Print();
				break;

			default:
				break;
			}
		}
	}

private:
	// UI Ŭ���� ���ο� �ڷᱸ���� ���Եȴ�.
	CMyList m_list;
};

// ���α׷� ����
int main() {
	CMyUI ui;
	ui.Run();

	return 0;
}*/

// ���� 4. Aggregation ����
// �ڷᱸ�� Ŭ����
class CNode {
	// friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// ���� ���� ����Ʈ�� ������ ������
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// ����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode) {
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	// ����Ʈ�� ���ο� ��� �߰�
	void AddNewNode(const char* pszName) {
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// ����Ʈ�� ��� ��� ���� ���
	void Print() {
		CNode* pNode = m_HeadNode.pNext;
		while (pNode) {
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

// UI Ŭ����
class CMyUI {
public:
	// ���� ����� �ݵ�� �ʱ�ȭ ����� �̿��� �ʱ�ȭ�ؾ� �Ѵ�.
	CMyUI(CMyList& rList) : m_list(rList) {}

	// �޴� ��� �� ����� �Է� Ȯ��
	int PrintMenu() {
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// ���������� �޴��� ����ϴ� ���� �̺�Ʈ �ݺ���
	void Run() {
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0) {
			switch (nInput) {
			case 1: // Add
				cout << "�̸�: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;

			case 2: // Print
				m_list.Print();
				break;

			default:
				break;
			}
		}
	}

private:
	// UI Ŭ���� ���ο� �ڷᱸ���� ���Եȴ�.
	CMyList &m_list;
};

// ���α׷� ����
int main() {
	// �ڷᱸ���� UI ��ü�� ������ �����ϰ� �����Ѵ�.
	CMyList list;
	CMyUI ui(list);
	ui.Run();

	return 0;
}