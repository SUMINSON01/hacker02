// part08.cpp
// 수평적 관계와 집합 관계

#include<iostream>
#include<string>

using namespace std;

// 예제 1. friend 함수
/*class CMyData {
public:
	CMyData(int nParam) : m_nData(nParam) {};
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// friend 함수 선언
	friend void PrintData(const CMyData&);

private:
	int m_nData = 0;
};

void PrintData(const CMyData& rData) {
	// 프렌드 함수이므로 접근 제어 지시자의 영향을 받지 않고
	// private 멤버에 직접 접근한다.
	cout << "PrintData(): " << rData.m_nData << endl;
}

int main() {
	CMyData a(5);
	PrintData(a);

	return 0;
}*/

// 예제 2. friend 예약어를 선언한 클래스
/*class CNode {
	// friend 클래스 선언
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// 단일 연결 리스트로 관리할 데이터
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// 리스트에 담긴 데이터들을 모두 출력하고 삭제
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
		
		// 리스트에 새로운 노드를 추가
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

private:
	CNode m_HeadNode;
};

int main() {
	// 메모리 추가 / 삭제 코드가 등장하지 않는다.
	CMyList list;
	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}*/

// 예제 3. Composition 관계
/* // 자료구조 클래스
class CNode {
	// friend 클래스 선언
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// 단일 연결 리스트로 관리할 데이터
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// 리스트에 담긴 데이터들을 모두 출력하고 삭제
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode) {
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	// 리스트에 새로운 노드 추가
	void AddNewNode(const char* pszName) {
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// 리스트의 모든 노드 값을 출력
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

// UI 클래스
class CMyUI {
public:
	// 메뉴 출력 및 사용자 입력 확인
	int PrintMenu() {
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// 지속적으로 메뉴를 출력하는 메인 이벤트 반복문
	void Run() {
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0) {
			switch (nInput) {
			case 1: // Add
				cout << "이름: ";
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
	// UI 클래스 내부에 자료구조가 포함된다.
	CMyList m_list;
};

// 프로그램 시작
int main() {
	CMyUI ui;
	ui.Run();

	return 0;
}*/

// 예제 4. Aggregation 관계
// 자료구조 클래스
class CNode {
	// friend 클래스 선언
	friend class CMyList;

public:
	explicit CNode(const char* pszName) {
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// 단일 연결 리스트로 관리할 데이터
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList {
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList() {
		// 리스트에 담긴 데이터들을 모두 출력하고 삭제
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode) {
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	// 리스트에 새로운 노드 추가
	void AddNewNode(const char* pszName) {
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// 리스트의 모든 노드 값을 출력
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

// UI 클래스
class CMyUI {
public:
	// 참조 멤버는 반드시 초기화 목록을 이용해 초기화해야 한다.
	CMyUI(CMyList& rList) : m_list(rList) {}

	// 메뉴 출력 및 사용자 입력 확인
	int PrintMenu() {
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// 지속적으로 메뉴를 출력하는 메인 이벤트 반복문
	void Run() {
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0) {
			switch (nInput) {
			case 1: // Add
				cout << "이름: ";
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
	// UI 클래스 내부에 자료구조가 포함된다.
	CMyList &m_list;
};

// 프로그램 시작
int main() {
	// 자료구조와 UI 객체를 별도로 선언하고 연결한다.
	CMyList list;
	CMyUI ui(list);
	ui.Run();

	return 0;
}