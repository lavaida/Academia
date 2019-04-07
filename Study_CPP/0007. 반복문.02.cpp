/*


###########
   반복문
###########

case 2. do while 문
- 반복문의 일종
- while과 비슷하나 최초 1회 코드 block을 실행 후 조건을 비교한다.

do {

	우선 무조건 1회 수행하고,
	조건이 참(1)일 경우 수행하는 코드 block

} while(조건);

#############################################

case 3. for 문
- 반복문의 일종
- 변수 선언 및 초기화, 조건식, 변수의 증감 연산이라는 3가지 정보를 한 곳에 모아 가독성을 높임.
- 

for(변수 선언 및 초기화 ; 조건식 ; 변수의 증감 연산) {
	조건이 참(1)일 경우 수행하는 코드 block
}

변수 선언 및 초기화: for문이 실행될 때 제일 먼저 실행되며, 한 번만 실행 됨.
조건식: 조건을 만족하는 동안 반복문이 실행된다.
변수의 증감 연산: 코드 block이 실행 된 후 증감식이 수행된다.
코드 블록: 조건식이 참(1)일 경우 수행되는 부분


N중 for문
- 중첩된 for문

- N이 늘어날수록 반복 횟수가 기하급수적으로 늘어나기 때문에
3중 for문부터는 잘 안 씀...

for(int i = 0; i < 2; i++) {
	for(int j = 0; j < 3; j++) {


	}
}


#################################################################################################

과제.


#
##
###
####
#####


#####
####
###
##
#

    *
   **
  ***
 ****
*****

*****
 ****
  ***
   **
    *

#################################################################################################

*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void) {

	cout << "##############################################################" << endl;
	cout << "### 입력 값을 누적하고, \"-1\" 입력 시 출력하기" << endl;

	//int inputNum = 0, sum = 0;

	//do {
	//	cin >> inputNum;
	//	sum += inputNum; // 순서 차이가 결과 값을 바꿈 !!! 더하는 과정을 먼저 해야 원하는 결과.
	//} while (inputNum != -1);
	//cout << "sum: " << sum << endl;


	cout << "##############################################################" << endl;
	cout << "### for 문 예제 " << endl << endl;

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << endl;
	}
	cout << endl;

	cout << "##############################################################" << endl;
	cout << "### for 문으로 2~ 9단 출력 " << endl << endl;

	for (int i = 2; i < 10; i++) {
		cout << "######################" << endl;

		for (int j = 1; j < 10; j++) {
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}

	cout << "##############################################################" << endl;
	cout << "### 각 단의 시작은 첫 줄에 표시, 각 곱은 세로로 표시하는 구구단?! " << endl << endl;

	for (int j = 1; j < 10; j++) {
		for (int i = 2; i < 10; i++) {
			cout << i << " * " << j << " = " << i*j << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "##############################################################" << endl;
	cout << "### for 단과 곱을 입력, 단의 곱까지 출력" << endl << endl;

	// ex. 단 5, 곱 4
	// 2단 전체, 3단 전체, 4단 전체, 5단은 4곱까지만 출력
	int iDan = 0, iGob = 0;
	int temp = 9;

	cout << "단: ";
	cin >> iDan;
	cout << "곱: ";
	cin >> iGob;
	cout << endl;

	for (int i = 2; i <= iDan; i++) {

		if (i >= iDan) {
			temp = iGob;
		}
		for (int j = 1; j <= temp; j++) {
			
			cout << i << " * " << j << " = " << i*j << endl; //
		}
		cout << endl;

		// 탈출하자고 if문 비교를 해야한다는게 좀...
	}
	cout << endl;

	cout << "##############################################################" << endl;

	for (int j = 1; j < 10; j++) {
		for (int i = 2; i <= iDan; i++) {
			if (i == iDan && j > iGob)
				break;
			cout << i << " * " << j << " = " << i*j << "\t";
		}
		cout << endl;
	}

	return 0;
}
