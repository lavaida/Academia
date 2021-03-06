///*
//
//########
//C++ 처음
//########
//
//1. 빌드(B) -> 솔루션 빌드(Ctrl + Shift + B)
//
//
//2. 디버그(D) -> 디버그 안 하고 시작 Ctrl +F5
//
//
//3. 주석
//- 코드에 삽입된 메모
//- 주석 처리가 되면 컴파일(compile) 대상에서 제외된다. = 번역을 하지 않겠다는 의미
//- 컴파일 및 실행 결과에 영향을 주지 않는다.
//
//## 필요한 이유
//- 타인이 코드를 이해하는데 도움을 주기 위해 해석을 달아 놓으려고...
//
//## 종류
//##1. 행 단위 주석
//##2. 블록 단위 주석
//
//## 단축키
//블록으로 지정한 뒤에 Ctrl +k c / Ctrl +k u
//(Ctrl +u 는 소문자로 / Ctrl +U 는 대문자로 변경...)
//
//
//4. 탐색기에서 프로젝트 폴더 -> Debug 폴더에 있는 실행파일이 생성되는 과정.
//
//- 코드 작성 -> 전처리기 -> 컴파일(빌드 과정) -> 어셈블러 -> 링커 -> 실행파일 생성
//
//##1. 코드 작성: 사용자가 프로그래밍 언어로 문법에 맞춰 코드를 작성하는 작업
//
//##2. 전처리기 : #이 붙은 코드라인을 컴파일 이전에 수행한다 하여 전처리기라 한다.
//            # : 전처리 지시자
//
//##3.  컴파일  : 고수준 언어를 저수준 언어로 번역하는 과정
//      컴파일러: 우리가 프로그래밍 언어로 작성한 소스 코드를 어셈블리어로 번역해주는 작업을 진행한다.
//
//##4. 어셈블러 : 저수준 언어(어셈블리어)를 기계어(바이너리 코드)로 번역하는 작업을 진행한다.
//
//- So, 컴파일과 어셈블러를 거치면 바이너리 코드로 이루어진 .Obj 파일을 생성한다.
//
//##5.     링커 : 생성된 .obj 파일과 .lib 파일을 하나로 묶어 실행파일(exe)을 생성한다.
//
//
//
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//void main(void)
//{
//	cout << "Hello World!" << endl;
//
//	system("pause");
//}
