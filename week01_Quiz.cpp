// week01_Quiz.cpp

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int sum(int, int);
int alphaTotal(const char*, int);
void alphaHistogram(const char*, int);

int main() {
	// 1. cout과 << 연산자를 이용
	//    1 ~ 100 정수를 10개씩 출력
	//    정수는 탭으로 분리. 한 줄에 10개씩 출력
	/*int i;
	for (i = 1; i <= 100; i++) {
		if (i % 10 == 0) {
			cout << i  << endl;
		}
		else {
			cout << i << "\t";
		}
	}*/

	// 2. cout과 <<연산자를 이용하여 구구단 출력
	/*int i, k;
	for (i = 1; i < 10; i++) {
		for (k = 1; k < 10; k++) {
			cout << i << "x" << k << "=" << i * k << "\t";
		}
		cout << endl;
	}*/

	// 3. 키보드로부터 두 개의 정수를 읽어 큰 수 출력
	/*int num1, num2;
	cout << "두 수를 입력하라>>";
	cin >> num1 >> num2;
	if (num1 > num2)
		cout << "큰 수 = " << num1;
	else if (num1 < num2)
		cout << "큰 수 = " << num2;
	else
		cout << "수가 똑같습니다.";*/

	// 4. 소수점을 가지는 5개의 실수를 입력 받아 제일 큰 수 화면에 출력
	/*/double num[5] = {0.0};
	cout << "5 개의 실수를 입력하라>>";
	int i;
	for (i = 0; i < 5; i++) {
		cin >> num[i];
	}
	double max = num[0];
	for (i = 0; i < 5; i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}
	cout << "제일 큰 수 = " << max;*/

	// 5. <Enter> 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의 개수를 화면에 출력
	/*char stn[100];
	int count = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(stn, sizeof(stn), '\n');

	for (int i = 0; stn[i]; i++) {
		if ('x' == stn[i])
			count++;
	}
	cout << "x의 개수는 " << count;*/

	// 6. 문자열 두 개 입력 받음
	//    두 개의 문자열이 같은 지 검사
	//    같다면 "같습니다", 아니면 "같지 않습니다"를 출력
	/*char word1[100], word2[100];
	cout << "새 암호를 입력하세요>>";
	cin >> word1;

	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> word2;

	if (strcmp(word1 ,word2)) {
		cout << "같지 않습니다";
	}
	else {
		cout << "같습니다";
	}

	// 7. yes가 입력되면 종료하는 프로그램
	//    사용자로부터의 입력은 cin.getline() 함수 사용
	char result[100];
	while (1) {
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(result, sizeof(result), '\n');
		if (strcmp(result, "yes"));
		else {
			cout << "종료합니다...";
			break;
		}
	}*/

	// 8. 한 라인에 ';'으로 5개의 이름을 구분하여 입력받아,
	//    각 이름을 끊어 화면에 출력하고 가장 긴 이름을 판별하라.
	/*char name[5][100];
	int nameSize[5];
	int max=0;
	
	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		cin.getline(name[i], 100, ';');
	}
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << " : " << name[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		for (int k = 0; i < 100; k++) {
			if (name[i][k] == '\0') {
				nameSize[i] = k;
				break;
			}
		}
		if (nameSize[max] < nameSize[i]) {
			max = i;
		}
	}
	cout << "가장 긴 이름은 " << name[max];*/

	// 9. 이름, 주소, 나이를 입력받아 다시 출력하는 프로그램을 작성
	/*char name[100];
	cout << "이름은?";
	cin.getline(name, sizeof(name), '\n');

	char address[100];
	cout << "주소는?";
	cin.getline(address, sizeof(address), '\n');

	char age[100];
	cout << "나이는?";
	cin.getline(age, sizeof(age), '\n');

	cout << name << ", " << address << ", " << age << "세";

	// 10. 문자열을 하나 입력받고 문자열의 부분 문자열을 출력
	string stn;
	cout << "문자열 입력>>"; cin >> stn;
	int stnSize = stn.length();
	for (int i = 1; i < stnSize+1; i++) {
		string result(stn, 0, i);
		cout << result << endl;
	}*/
	
	
	// 11. C언어를 C++언어로 수정
	/*int k = 0;
	int n = 0;
	int sum = 0;
	cout << "끝 수를 입력하세요>>"; cin >> n;
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum << " 입니다.";*/

	// 12. C언어를 C++언어로 수정
	/*int n = 0;
	cout << "끝 수를 입력하세요>>"; cin >> n;
	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << " 입니다.";*/

	// 13. 중식당
	/*cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	while (1) {
		int menu;
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4 >>"; cin >> menu;
		if (menu == 4) {
			cout << "오늘 영업은 끝났습니다.";
			break;
		}
		else if (menu > 0 && menu < 5) {
			int many;
			cout << "몇인분?"; cin >> many;
			if (menu == 1) {
				cout << "짬뽕 ";
			}
			else if (menu == 2) {
				cout << "짜장";
			}
			else if (menu == 3) {
				cout << "군만두";
			}
			cout << many << "인분 나왔습니다" << endl;
		}
		else {
			cout << "다시 주문하세요 !!" << endl;
		}
	}*/

	// 14. 카페
	//     커피 종류: 에스프레소, 아메리카노, 카푸치노
	//     커피 가격: 2000원,    2300원,    2500원
	//     하루 20000원 이상 벌면 카페 닫음
	/*char coffee[100];
	int num, priceNow;
	int priceTotal = 0;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	while (1) {
		cout << "주문>>"; cin >> coffee >> num; // ex) 에스프레소 4
		if (strcmp(coffee, "에스프레소") == 0) {
			priceNow = 2000 * num;
		}
		else if (strcmp(coffee, "아메리카노") == 0) {
			priceNow = 2300 * num;
		}
		else if (strcmp(coffee, "카푸치노") == 0) {
			priceNow = 2500 * num;
		}
		cout << priceNow << "원입니다. 맛있게 드세요" << endl;
		priceTotal += priceNow;
		
		if (priceTotal >= 20000) {
			cout << "오늘 " << priceTotal << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~";
			break;
		}
	}*/

	// 15. 정수 5칙 연산(덧셈, 뺄셈, 곱셈, 나눗셈, 나머지)을 하는 프로그램 작성
	/*int num1, num2;
	char operation[1];
	while (1) {
		cout << "? "; cin >> num1 >> operation >> num2;
		if (strcmp(operation, "+") == 0) { // 덧셈
			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
		}
		else if (strcmp(operation, "-") == 0) { // 뺄셈
			cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
		}
		else if (strcmp(operation, "*") == 0) { // 곱셈
			cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
		}
		else if (strcmp(operation, "/") == 0) { // 나눗셈
			cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
		}
		else if (strcmp(operation, "%") == 0) {
			cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;
		}
	}*/

	// 16. 영문 텍스트를 받아 알파벳 히스토그램을 그리는 프로그램을 작성
	//     대문자는 모두 소문자로 집계
	//     텍스트 입력의 끝은 ';' 문자
	//     대문자 -> 소문자 tolower(char c)
	//     알파벳 검사 isalpha(char c)
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl
		 << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	char stn[10000];
	cin.getline(stn, 10000, ';');
	
	// 배열 사이즈 구하기
	int stnSize = 10000;
	for (int i = 0; i < 10000; i++) {
		if (stn[i] == '\0') {
			stnSize = i;
			break;
		}
	}

	// 모든 알파벳 소문자로 변경
	for (int i = 0; i < stnSize; i++) {
		stn[i] = tolower(stn[i]);
	}

	alphaTotal(stn, stnSize);
	cout << endl;
	alphaHistogram(stn, stnSize);





	return 0;
}

int sum(int a, int b) {
	int k = 0;
	int res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}

int alphaTotal(const char* stn, int stnSize) {
	// isalpha()
	// 알파벳 대문자 "a-z"는 1을 반환
	// 알파벳 소문자 "a-z"는 2를 반환
	// 알파벳이 아닌 것은 0을 반환
	int total = 0;
	for (int i = 0; i < stnSize; i++) {
		if (isalpha(stn[i]) == 1 || isalpha(stn[i]) == 2) {
			total += 1;
		}
	}
	cout << "총 알파벳 수 " << total << endl;
	return total;
}

void alphaHistogram(const char* stn, int stnSize) {
	int alphabet[26] = { 0 };

	for (int i = 0; i < stnSize; i++) {
		for (int k = 97; k <= 122; k++) {
			if (stn[i] == char(k)) {
				alphabet[k-97]++;
				break;
			}
		}
	}
	
	for (int i = 0; i < 26; i++) {
		cout << char(97 + i) << " (" << alphabet[i] << ")\t: ";
		for (int k = 0; k < alphabet[i]; k++) {
			cout << '*';
		}
		cout << endl;
	}


}
