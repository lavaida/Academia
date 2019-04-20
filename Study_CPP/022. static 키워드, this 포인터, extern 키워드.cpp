/*


##################
   static 변수
##################

- 지역적인 특징 : 해당 영역에서만 접근이 가능함.
- 전역적인 특징 : Data 메모리 영역에 저장되고, 프로그램 시작 시 할당, 종료 시 소멸


#####################################################################################################

###########################################
     static 키워드와 클래스의 멤버 변수
###########################################

- (const 멤버 변수처럼) 선언과 동시에 초기화를 할 수가 없다.

- static 멤버 변수는 프로그램 시작 시, Data 메모리 영역에 할당이 되고,
Member Initializer와 생성자는 객체가 생성되어야 호출된다.
So, 할당되는 시점이 다르기 때문에 초기화 하는 과정이라고 볼 수 없다.

ex.

class Obj
{
private:
	static int num1 = 10;// 오류, static 변수의 초기화 방법은?!
	static int num2;

public:
	Obj() {}
	Obj(int a)
	{
		num2 = a; // 객체가 생성될 때마다 static 변수에 값을 넣어주는 것.
				// 초기화하는 행위라고 볼 수가 없다.
	}

	void SumStaticVal()
	{
		++num2;
		cout << "num2: " << num2 << endl;
	}
}; // 클래스 정의 뒤에 반드시 세미콜론 ";" 넣어주자 !!!!!!!!!!

int Obj::num2 = 10; // 결국, Global 영역(static 변수가 존재하는 메모리영역)을 지정해서 초기화를 해준다.
					// 그리고 프로그램이 시작되면, 딱 한번만 선언과 초기화가 이루어진다.

int main(void)
{
	Obj obj1;
	Obj obj2;
	Obj obj3;

	obj1.SumStaticVal(); // 11
	obj2.SumStaticVal(); // 12
	obj3.SumStaticVal(); // 13

	// 결국, 동일한 클래스의 객체가 static 멤버 변수를 공유한다 !!!!
	// but, static 멤버 변수는 객체의 소유가 아님.
}



############################################
   영역 지정을 통한 static 멤버 변수 접근
############################################

- Access Modifier에 따라서 접근 가능성이 결정됨.
- 클래스이름 + "::" scope 연산자

ex.

class Obj
{
public:
	static int num2;

};

int Obj::num2 = 10; // static 키워드가 초기화할 때는 없다 !!!!

int main(void)
{

	cout << Obj::num2 << endl; // scope 연산자를 통한 public 멤버 접근
}


#####################################################################################################

###########################################
     static 키워드와 클래스의 멤버 함수
###########################################

- static 키워드를 멤버 함수 앞에다가 붙이면 된다.
- 생성되지 않은 객체는 메모리에 할당되지 않았으므로, 객체에 대한 정보를 알 수 없다.
(물론, 객체의 멤버에 대해서도 알 수가 없음.)

- static 키워드가 있으면, 프로그램 시작 시 메모리에 할당 되었는지 여부에 따른 호출 가능성을 염두 !!!!

ex.

class Obj
{
public:
	void Func()
	{
		num++; // 객체 생성 시, 일반 멤버 변수는 존재함.
		staticNum++; // 가능함.
	}

	static void StaticFunc() // static 멤버 함수, static 키워드가 맨 앞에 위치한다 !!!!
	{
		//num++; // 오류, 객체가 만들어지지도 않았기 때문에 메모리에 할당을 받지도 않았음 !!!!
		staticNum++;
	}
private:
	int num;
	static int staticNum;	
	
};

얘도 Obj::StaticFunc(); 로 호출 가능함?!

#####################################################################################################

###########################
        this 포인터
###########################

- 자기 참조?!
- "this" 키워드를 사용하는 객체의 주소를 반환해주는 포인터.
- 클래스 내에서 멤버 변수를 사용하고 있을 시, "this->"가 생략된 형태였다.

특히, 멤버 변수와 매개변수의 이름이 같을 경우 사용한다.

ex.

class A
{
private:
	int num;
public:
	void Func(int num)
	{
		this->num = num; // 앞의 this->num은 멤버 변수 num
						 // 뒤의 num은 매개변수의 num
	}
};


######################################################################################################

##################################
     extern 키워드와 전역 변수
##################################

- 파일 외부의 어딘가에 해당 전역 변수가 있다고 알려주는 키워드
마치, 클래스의 Forward Declaration과 비슷함.
(왜냐하면 컴파일러가 파일 단위로 컴파일을 수행하기 때문에,
다른 파일에서는 존재의 유무를 알 수 없어서 컴파일러에게 미리 알려주는 것 !!!!)

- 그리고, extern 키워드는 파일 외부에 존재한다는 것만 알려줄 뿐, 선언 자체로 메모리 공간에 할당하는 것이 아님.

- 전역 변수가 선언된 파일말고, 다른 파일에서 extern 키워드를 사용하면 된다.
(전역 변수의 접근 영역은 프로젝트 범위 내 !!!!)

ex.

extern int gNum;


##################################
   extern 키워드와 전역 함수
##################################

ex.

extern void Func(int num, int num2);


###################################
     extern 키워드 넣는 법
###################################

- 모든 cpp 파일에 해당 문장을 넣지 말고, header 파일 만들어서 stdafx.h 에 #include로 포함시키면 된다.

######################################################################################################

*/

#include "stdafx.h"

// 다음번 소스 코드에 속해있음. 같이 다운 받아야함.
// 다음번 소스 코드의 main 함수 주석처리하고 실행.

//extern int gNum; // 다른 파일에 속해있는 전역변수를 extern 키워드를 통해 컴파일러에게 미리 알려주는 것 !!!!
//extern void Func(int num, int num2); // 함수도 extern 키워드를 통해 다른 소스파일의 전역 함수에 접근할 수 있다.


class Obj
{
public:
	Obj()
		: num1(42)
	{

	}

	void NormalFunc() // 이미 프로그램이 시작될 때, 할당이 되었으므로
	{		  // 객체 생성 뒤, static 멤버 변수에 접근하면 충분히 가능함.			
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl;
	}

	static void StaticFunc()
	{
		//cout << "num1: " << num1 << endl; // 프로그램 시작 후, static 멤버들이 할당될 때에는
											// 인스턴스(멤버) 변수들은 할당이 되어있지 않으므로 접근이 불가능하다.
		cout << "num2: " << num2 << endl;
	}

private:
	int num1;
	static int num2;	
	
};

int Obj::num2 = 442; // static 키워드는 선언 시, 한 번만 !!!!
					// 초기화할 때는 없어야 함 !!!!


class A
{
private:
	int num;
public:
	void Func(int num)
	{
		this->num = num; // 앞의 this->num은 멤버 변수 num
						 // 뒤의 num은 매개변수의 num
	}

	int GetNum(void)
	{
		return num;
	}
};


int main(void)
{
	cout << "####################################################################" << endl;
	cout << "### static 키워드와 클래스의 멤버 함수" << endl << endl;

	Obj obj;

	obj.NormalFunc(); // 일반적인 인스턴스 변수와 static 멤버 변수 모두 접근이 가능함.
	cout << endl;

	obj.StaticFunc(); // static 멤버 변수만 접근이 가능함.
					  // 메모리 할당 시기를 생각하면 이해하기 쉬움.

	cout << "####################################################################" << endl;
	cout << "### this 포인터" << endl << endl;

	A a;
	a.Func(42);

	cout << a.GetNum() << endl; // this 포인터를 이용한 멤버 변수의 초기화가 잘 되었음.

	cout << "####################################################################" << endl;
	cout << "### extern 키워드" << endl << endl;

	//cout << "gNum: " << gNum << endl; // 현재 소스코드 말고, 프로젝트 내 다른 소스코드의 전역 변수를 extern 키워드로 받음.

	//Func(42, 442); // 현재 소스코드 말고, 프로젝트 내 다른 소스코드의 전역 함수를 extern 키워드로 받음.

	cout << "####################################################################" << endl;


	return 0;
}
