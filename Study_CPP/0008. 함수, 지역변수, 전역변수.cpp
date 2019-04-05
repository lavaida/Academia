/*


2019.03.22.01 금


##########
   함수
##########

- 수학의 함수는 y = f(x)꼴
- f는 Function의 약자로, 기능이라는 뜻을 가진다.
- "함수를 구현한다"라는 말은 "기능을 구현한다"라는 뜻이다.
- 결과물을 한 번만 만들고 기능을 부수지 않는다. (재사용을 한다.)



- 함수의 4가지 유형
(매개변수_인자의 유무와 반환값의 유무에 따른 4가지)

case 1. Input O, Output O

case 2. Input O, Output X
- srand(unsigned(time(NULL)));
- system(" ");

case 3. Input X, Output O
- rand();

case 4. Input X, Output X


- 함수의 형태(선언부, 정의부)

반환 타입, 함수 이름, (매개변수_인자_prameter) {

	실행하고자 하는 코드 block
}

반환 타입: 함수의 기능을 수행한 후 얻어진 결과물을 반환해줄 때 명시해준다.
(함수의 반환값이 없는 경우, void라고 명시해주면 됨.)

함수 이름: 함수의 이름, 변수명 규칙과 동일하게 사용한다.
(수행하는 기능을 의미하는 뜻을 가지도록...)

매개변수: 해당 함수를 수행하기 위해 필요한 데이터의 종류 및 개수를 명시함.
(함수의 매개변수 없는 경우, 생략하거나 void라고 명시해주면 됨.)

{} 중괄호: 함수의 Body, 시작되는 곳과 끝나는 곳을 감싸줌.
- 지역적 특성을 지닌다.

###############
  지역적 특성
###############

- 지정된 영역 내부에 선언 된 변수는 해당 함수의 Stack에 메모리가 할당되며,
함수 호출이 종료되면 사라진다.

- 함수 외부에서는 해당 영역의 접근이 불가능 하다?!
또한, 함수 내부에서는 외부로의 접근이 불가능 하다.

- 함수 내 새로운 block이 있다면 block 내부에서는 함수의 변수에 접근이 가능하다.
but, 함수에 있는 변수들은 block 내부에 접근 불가.



코드 block: 해당 함수에 작성되어 있는 실질적인 기능을 의미함.

###############################################################################

return 문
- 함수를 종료시킬 때 사용함.
- 함수의 반환 타입이 void라면 return;
         반환 타입이 void가 아니라면, return 뒤에 해당 타입의 변수나 상수를 명시해준다.


함수 호출(함수 Call)
- 매개변수가 없는 함수: 함수 이름();
- 매개변수가 있는 함수: 함수 이름(데이터들);

해당 인자를 넣어주고 함수를 호출...
- 같은 함수를 호출하는 것이므로 함수의 재사용성.

###############################################################################

########################
   전역변수와 지역변수
########################

- 변수의 선언 위치와 함수는 깊은 관계가 있다.
- 선언되는 위치에 따라 "지역 변수", "전역 변수"

차이점.
- 메모리에 변수가 존재하는 위치. 
지역 변수는 Stack 영역(해당 함수의 지역, 영역에서만 접근이 가능하다.)
전역 변수는 Data 영역(초기화 하지 않으면 "0"으로 채워진다.
					  메모리 공유를 한다. 그래서 값을 어디에서든지 바꿀 수 있음.)

- 변수에 접근할 수 있는 범위.
지역 변수는 해당 함수 내부
전역 변수는 프로그램 전체 영역에서 어디서든 접근이 가능.

- 메모리에 존재하는 기간.
지역 변수는 함수가 종료될 때까지
전역 변수는 프로그램이 종료될 때까지


#######################
    메모리의 영역 - 추가 바람.
#######################

case 1. 코드_Code
- 소스 코드가 저장 됨.

case 2. 데이터_Data
- 전역 변수
(할당 시점: 프로그램 시작시(컴파일 시),
 소멸 시점: 프로그램이 종료 되었을 때

case 3. 힙_Heap
- 동적할당한 변수

case 4. 스택_Stack
- 지역 변수, 매개변수
- 함수 별로 스택에 올라감.
- 함수는 해당 스택에 있는 지역 변수에 접근 가능하다.
(할당 시점: 함수가 시작 되었을 때,
 소멸 시점: 함수가 종료 되었을 때)


 So, main과 add 함수의 stack
- main 함수가 실행되면 stack 영역에 할당되고, 해당 공간에 iA와 iB가 등록된다.
이후, add 함수가 실행되면 add 함수가 stack 영역에 할당되고, iRes가 등록된다.

Stack은 LIFO(Last In First Out) 구조.

- add 함수의 stack에는 iRes만 등록되어 있는 상황이므로, iA와 iB의 존재를 모른다.
마찬가지로, main 함수의 stack에는 iA와 iB만 등록되어 있는 상황이므로, iRes의 존재를 모른다.


지역 변수는 - 해당 지역, 영역에서만 접근이 가능하다.


###############################################################################


######################################
   이름이 동일한 전역변수와 지역변수
######################################

- 전역 변수가 메모리를 공유하기 때문에 접근이 가능하지만,
해당 함수에 동일한 이름의 지역변수가 있다면 지역 변수를 우선적으로 접근 or 참조한다.
(전역 변수가 지역 변수에 가려지는 현상)


###############################################################################




*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 정수 2개를 받아 더하고 그 값을 반환하는 함수
int add(int a, int b) {
	int result = a + b;
	return result; // 결과를 반환함.
}


int val2 = 22;

int main(void) {

	cout << "####################################################" << endl;
	cout << "### 함수의 선언과 정의, 함수 호출" << endl << endl;
	int num1 = add(10, 20);
	int num2 = add(20, 22); // 함수의 재사용.
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	cout << "####################################################" << endl;
	cout << "### 전역 변수와 지역 변수" << endl << endl;

	int val1 = 20;

	return 0;
}
