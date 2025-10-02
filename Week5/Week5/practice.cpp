#include <iostream>
#include <string>
using namespace std;
int main() {
	// 스트링생성
	string str; // 빈문자열을가진스트링객체생성
	string address("서울시성북구삼선동389");
	string copyAddress(address); // address의문자열을복사한스트링객체생성
	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' }; // C-스트링
	string title(text); // "Love C++" 문자열을가진스트링객체생성
	// 스트링출력
	cout << str << endl; // 빈스트링. 아무값도출력되지않음
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}