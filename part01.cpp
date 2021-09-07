// part01.cpp

#include <iostream>
#include <string>
#include <cstdio>

using namespace std; // std 네임스페이스 사용

void TestFunc(int& rParam);
void Swap(int& a, int& b);
int TestFunc2(int nParam);

int main(void) {
	// 예제 1. Hello, World
	//cout << "Hello, World" << endl; // end of line(줄바꿈)


	// 예제 2. cout 사용법
	cout << 10 << endl; // int
	cout << -10U << endl; // unsigned int
	cout << 10.5F << endl; // float
	cout << 10.5 << endl; // double
	cout << 3 + 4 << endl;


	// 예제 3. 문자열 조합 출력
	string strData = "Test String";
	cout << "Sample String" << endl;
	cout << strData << endl;

	strData = "New string";
	cout << strData << endl;

	cout << "저는" << 20 << "살" << "입니다." << endl;


	// 예제 4. cin 사용법
	int nAge;
	cout << "나이를 입력하세요." << endl;
	cin >> nAge;

	char szJob[32]; // 자료형의 32개 배열
	cout << "직업을 입력하세요." << endl;
	cin >> szJob;

	string strName;
	cout << "이름을 입력하세요." << endl;
	cin >> strName;

	cout << "당신의 이름은 " << strName << "이고, "
		<< "나이는 " << nAge << "살이며, "
		<< "직업은 " << szJob << "입니다." << endl;


	// 예제 5. auto 예약어
	int a = 10;
	int b(a);
	auto c(b); // 자동으로 int형 배정

	cout << a + b + c << endl;


	// 예제 6. new 연산자 사용
	// 인스턴스만 동적으로 생성하는 경우
	int* pData = new int;

	// 초깃값을 기술하는 경우
	int* pNewData = new int(10);

	*pData = 5;
	cout << *pData << endl;
	cout << *pNewData << endl;

	delete pData;
	delete pNewData;


	// 예제 7. 배열 형태의 객체 생성
	// 객체를 배열 형태로 동적 생성
	int* arr = new int[5];
	for (int i = 0; i < 5; ++i)
		arr[i] = (i + 1) * 10;

	for (int i = 0; i < 5; ++i)
			cout << arr[i] << endl;

	// 배열 형태로 생성한 대상은 반드시 배열 형태를 통해 삭제
	delete[] arr;
	// new 연산자는 객체의 생성자를 호출하고, delete 연산자는 객체의 소멸자를 호출한다/


	// 예제 8. 참조형 변수 사용
	//상수에는 참조자를 선언할 수 없음
	int nData = 10;

	// nData 변수에 대한 참조자 선언
	int &ref = nData;

	// 참조자의 값을 변경하면 원본도 변경됨
	ref = 20;
	cout << nData << endl;

	// 포인터를 쓰는 것과 비슷함
	int *pnData = &nData;
	*pnData = 30;
	cout << nData << endl;


	// 예제 9. 참조에 의한 호출
	// 매개변수가 참조자인 경우 호출자 코드만 봐서는 매개변수가 참조 형식임을 확인할 수 없음
	int nData = 0;

	// 참조에 의한 인수 전달이다.
	TestFunc(nData);
	cout << nData << endl;


	// 예제 10. 참조 전달
	// 참조 전달이므로 호출자 변수의 값 변경 가능
	int x = 10, y = 20;

	// 참조 전달이며 두 변수의 값이 교환됨.
	Swap(x, y);

	// 교환된 결과를 출력
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;


	// 예제 11. r-value 참조
	int nInput = 0;
	cout << "Input number: ";
	cin >> nInput;

	// 산술 연산으로 만들어진 임시 객체에 대한 r-value 참조
	int &&rdata = nInput + 5;
	cout << rdata << endl;

	// 함수 반환으로 만들어진 임시 객체에 대한 r-value 참조
	int &&result = TestFunc2(10);

	// 값 변경 가능
	result += 10;
	cout << result << endl;


	// 예제 12. 범위 기반 for문
	int aList[5] = {10, 20, 30, 40, 50};

	for (auto n : aList) { // == for(int i =0; i<5; ++i)
		cout << n << ' ';
	}
	cout << endl;

	// n은 각 요소에 대한 참조다.
	for (auto& n : aList) {
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}

void TestFunc(int& rParam) {
	// 피호출자 함수에서 원본의 값을 변경했다.
	rParam = 100;
}

void Swap(int& a, int& b) {
	int nTmp = a;
	a = b;
	b = nTmp;
}

int TestFunc2(int nParam) {
	int nResult = nParam * 2;
	return nResult;
}
