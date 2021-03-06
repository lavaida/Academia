/*

################################
    메모리 동적 할당 in C++
################################

- C 기반의 메모리 동적 할당은 함수를 통해 수행했음.
but, C++ 기반의 메모리 동적 할당은 "new" 연산자를 통해 수행한다 !!!!

ex. int *ptr = new int; // 힙 영역에 4 Bytes 할당 하고
						// 읽을 때 4 Bytes를 한 번에 읽어야 한다고 명시하는 것과 같음.

ex. int *ptr2 = new int(10); // 메모리 동적 할당과 동시에 초기화도 가능하다.

############################################
"delete" 연산자를 통해서 메모리 해제를 한다.
############################################

ex. delete ptr;
ptr = nullptr;

- 그래도 메모리 공간의 주소는 남아있기 때문에, 포인터를 "nullptr"로 바꿔주어야 한다 !!!!


#########################################################################################

###########################
   동적 배열 선언 in C++
###########################

ex. int *ptr = new int[3]; // int 형 원소가 3개인 동적 배열

ex. int size = 0;
cin >> size;

int *ptr = new int[size]; // 동적 할당이기 때문에 Runtime 시 배열의 크기를 정해줄 수 있다.

- 동적 배열은 선언과 동시에 초기화할 수는 없다.
- 한 번 정해진 배열의 크기는 늘리거나 줄일 수 없다.
So, 메모리를 해제하고 다시 원하는 크기로 할당 받아야 한다.

############################################
"delete" 연산자를 통해서 메모리 해제를 한다.
############################################

but, 배열이기 때문에 형태가 약간 다름 !!!!

delete ptr; // (int *) 형 포인터기 때문에 int 자료형 1개만 지운다 !!!!

delete[] ptr; // 배열을 메모리 해제 한다고 명시를 해줘야 한다 !!!!


#########################################################################################

##################################
   메모리 동적 할당 시 주의 사항
##################################

ex. int a = 10;
int *ptr = new int;
ptr = &a; // 문제 있는 부분 !!!!

왜냐하면, 메모리 동적 할당을 받은 메모리 공간의 주소를 ptr이 가리키고 있었음.
다른 변수의 주소를 받기로 해버리면, 문제가 발생함.

동적 할당 받은 메모리는 어떻게 접근함?! 메모리 해제는 어떻고?!

So, 그래서 새로운 주소를 받으려면 메모리 해제를 하고....


#########################################################################################

*/


#include <iostream>

using std::cout;
using std::endl;



int main(void)
{

	cout << "#####################################################################" << endl;
	cout << "### 메모리 동적할당 in C++" << endl << endl;

	// "new" 연산자 뒤에 자료형을 명시하면,
	// 해당 자료형의 크기와 포인터 타입으로 메모리 동적 할당을 해준다.
	int *ptr = new int;

	cout << *ptr << endl; // 초기화를 안 한 생태라서 쓰레기값 !!!!

	int *ptr2 = new int(10); // 메모리 동적 할당과 동시에 초기화도 가능하다.

	cout << *ptr2 << endl << endl;

	delete ptr; // 메모리 해제.
	delete ptr2;

	ptr = nullptr;
	ptr2 = NULL;

	cout << "#####################################################################" << endl;
	cout << "### 동적 배열 선언 in C++" << endl << endl;

	int size = 0;
	int *ptr3 = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << &(ptr3[i]) << endl;
	}
	cout << endl << endl;

	cout << "#####################################################################" << endl;

	return 0;
}
