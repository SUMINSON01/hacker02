// part02.cpp

#include<iostream>

using namespace std;

int TestFunc(int = 10);
int TestFunc2(int nParam1, int = 2);
int Add(int a, int b, int c) {
	cout << "Add(int, int, int): ";

	return a + b + c;
}
int Add(int a, int b) {
	cout << "Add(int, int): ";

	return a + b;
}
double Add(double a, double b) {
	cout << "Add(double, double): ";

	return a + b;
}
template <typename T>
T TestFunc3(T a) {
	cout << "매개변수 a: " << a << endl;
	
	return a;
}
template <typename T> 
T Add2(T a, T b) {
	return  a + b;
}

/*#define Add3(a, b)((a) + (b))
int Add3(int a, intb) {
	return a + b;
}
inline int AddNew(int a, int b) {
	return a + b;
}*/

int main(void) {
	// 예제 1. 디폴트 매개변수 사용
	// 호출자가 실인수를 기술하지 않았응므로 디폴트 값을 적용
	/*cout << TestFunc() << endl;

	// 호출자가 실인수를 확정했으므로 디폴트 값을 무시
	cout << TestFunc(20) << endl;
	// 반환자료형 함수이름(매개변수자료형이름 = 디폴트값);

	
	// 예제 2. 매개변수가 두 개일 때의 디폴트 값
	/*cout << TestFunc2(10) << endl;
	cout << TestFunc2(10, 5) << endl;*/


	// 예제 2. 매개변수가 두 개일 때의 디폴트 값
	/*cout << TestFunc2(10) << endl;
	cout << TestFunc2(10, 5) << endl;*/


	// 예제 3. Add() 함수의 다중 정의
	/*cout << Add(3, 4) << endl;
	cout << Add(3, 4, 5) << endl;
	cout << Add(3.3, 4.4) << endl;*/


	// 예제 4. 템플릿 함수
	/*cout << "int\t" << TestFunc3(3) << endl;
	cout << "double\t" << TestFunc3(3.3) << endl;
	cout << "char\t" << TestFunc3('A') << endl;
	cout << "char*\t" << TestFunc3("TestString") << endl;*/


	// 예제 5. 함수 템플릿으로 만든 Add() 함수
	/*cout << Add2<int>(3, 4) << endl;
	cout << Add2(3.3, 4.4) << endl;*/

	
	// 예제 6. 인라인 함수
	/*int a, b;
	scanf_s("%d%d", &a, &b);

	printf("ADD(): %d", ADD3(a, b));
	printf("Add(): %d", Add3(a, b));
	printf("AddNew(): %d", AddNew(a, b));*/

	// 예제 7. 범위 검색의 확장
	/*int nInput = 0;
	cout << "11 이상의 정수를 입력하세요" << endl;
	cin >> nInput;

	if (nInput > 10) {
		cout << nInput << endl;
	}
	else
		cout << "Error" << endl;*/
	












	return 0;
}

int TestFunc(int nParam) { // nParam 매개변수의 디폴트 값은 10이다.
	return nParam;
}
int TestFunc2(int nParam1, int nParam2) {
	return nParam1 * nParam2;
}
