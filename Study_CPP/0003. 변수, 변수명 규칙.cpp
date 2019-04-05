///*
//2019.03.14.02 목
//
//다른 파일의 main 함수와 중복이 되므로,
//해당 파일을 우클릭하고 속성 -> 빌드에서 제외!!!
//
//#############
//변수와 자료형
//#############
//
//1. 
//
//변수 - 데이터를 저장할 수 있는 메모리 공간에 이름을 부여한 것.
//자료형 - 어떤 데이터를 저장할 지, 얼마만큼 메모리 공간을 부여할 지 설정하는 것.
//
//
//2. 변수 선언
//int playerHp;
//
//int : int는 자료형 중 하나. / int라는 자료형의 형태와 크기에 맞는 메모리 공간을 할당한다.
//playerHp : playerHp라는 이름의 변수(메모리 공간에 이름을 붙여줌)
//
//- playerHp라는 변수에는 초기화를 안 해주면 "쓰레기값" <= 무의미한 값 / 무조건 "0"이라고 생각하면 안됨 !!!!
//
//
//3. 변수 초기화 - 선언된 변수에 최초로 값을 저장하는 행위.
//playerHp = 100;
//
//
//4. 선언과 동시에 초기화
//ex.
//int playerHp = 100;
//- 대부분 0으로 초기화를 많이 함.
//
//
//5. 변수명 규칙
//
//##1. 변수명은 알파벳과 숫자로 구성할 수 있다.
//- 숫자가 먼저 올 수 없음.
//ex. int 2player; <= 불가능함 !!!!
//
//##2. 변수명은 대소문자를 구분한다.
//ex. int A; / int a; <= 서로 다른 것임 !!!!
//
//##3. 프로그램 언어에서 제공하는 키워드로 이름을 지을 수 없다.
//ex. int namespace; <= 불가능 !!!!
//
//##4. 공백 또는 특수 문자가 올 수 없다.
//- but, 언더바(_)는 가능하다!!!
//ex. int player_Hp; <= 가능
//
//##5. 같은 이름의 변수를 재선언할 수 없다. = 재정의 불가능.
//
//
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//void main(void) {
//	int playerHp;
//
//	playerHp = 100;
//
//
//}