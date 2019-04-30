/*

###########################################
   ������ �����ε�(Operator Overloading)
###########################################

- Ŭ���� ������� ������ ��, ������ �����ϴ� �������� �ǹ̸� �ٲ� �� �ִٴ� ���� �ǹ���.
- ������ �����ε��� ���� ��ü �������� �����մϴ�.
(�ֳ��ϸ�, ������ ��ü�� �Լ��� �ǹ��ϱ� ������ !!!!)


- Ŭ���� ���ο� operator() �Լ��� �����Ͽ��� ������, ��� �Լ� ȣ�� ������ε� ����� �����ϴ� !!!

#######################################################################################################

######################################################
   ���� ������ in ��� ������(Arithmetic operator)
######################################################

########################
case 1. ��ü + ��ü ����
########################

Point Ŭ���� ������� ��� �Լ��μ�, "Operator Overloading"

Point operator+ (Point &ref);

- �̶�, ��ȯ���� "Reference"�� ���� �ʵ��� �Ѵ�.

(�ֳ��ϸ� ��ȯ�ϴ� ����� �Ű������� �޾ƿ��� ��ü�� �ƴ϶�,
�Լ� ���ο� ����� �ӽ� ��ü�� ��ȯ�ϱ� ������,
�Լ� ���ᰡ �Ǹ� ������ ����Ƿ� �ӽ� ��ü�� ������� �ȴ�.
So, �߸��� �޸� ���� ���ɼ��� ����� !!!!)



##########################
case 2. �Ϲ� �ڷ��� + ��ü
##########################

Point point23 = 400 + point1; // ������ ����, ���� ��ü �������� �����ϱ� ������...
Point point23 = operator+ (400, point21); // �� �� ���� ����.


############################################
�׷���, ��ȸ�ϴ� ����� �����ؾ� �մϴ� !!!!
############################################

- "Operator Overloading"�� Ŭ���� �ܺ��� "���� �Լ�"�� �����ϸ� �˴ϴ�.
(����, �Ű����� ���� �ش� ���� ������...)

- ��, �������� �������� ������ ���� �� �ϳ��� ������ ��ü Ÿ���̾�� �մϴ�.
�� �߿����� ��ü �����Ͱ� �ƴ� "���� ��ü Ÿ��"�� "Reference"�� �;��Ѵ�.



###################################################################
So, Ŭ���� ��� �Լ��θ� "Operator Overloading"�� �����ؾ��ϴ� ���
###################################################################

 - ������ ��ȯ ��Ģ�� ������ �ʴ� ��츦 �ǹ��մϴ�.

 case 1. ���� ������ - "="

 case 2. �Լ� ȣ�� ������ - "()"

 case 3. �迭 �ε��� ������ - "[]"

 case 4. ��� ���� ������ ������ - "->"

#######################################################################################################

##############################################################
   ���� ������ �����ε� (Assignment Operator Overlaoding)
##############################################################


#######################
  ����Ʈ ���� ������
#######################
- ��ü ���� ��, ����ڰ� �������� �ʾҴٸ� �����Ϸ��� �ڵ� �������ִ� �Լ��� �� �ϳ� !!!!
(������, �Ҹ���, ���� ������, ���� ������)

- �����Ϸ��� ���� ���� "Default Assignment Operator"��
����� �� �ܼ� ������ ���ֱ� ������ "���� ����"�� �����մϴ�.
(�޸� ���� �Ҵ��� ����� ���� ���, ���� �����ڵ� ���� ���� ������� "Operator Overloading")



���� �������� Operator Overloading - Default ����, ��� �� �ܼ� ����.
Point& operator= (Point &ref)
{
	xPos = ref.xPos; // ����� ������.
	yPos = ref.yPos;

	return *this; // ��ȯ���� �����ϴ� ������ point1 = point2 = point3;
				  // �������� ���� ������ �����ϱ� ���ؼ� !!!!
}


Visual Studio(IDE)�� ������ ������ �ٸ��ٴ� !!!!
- �������� �Ϲ����� �ǹ��� ������.
- ���� �ִ� ���� "Operator Overloading".

########################################################################################
- ��ü ������ ���ÿ� ������ ���� �������� ȣ���Դϴ� !!!!
(�̹� ������� ��ü�� ������� ���� ������ ���� �� ȣ�� �Ǵ� ���� ���� �������Դϴ� !!!!
########################################################################################

#######################################################################################################

*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

class Point
{
public:
	explicit Point() {}
	explicit Point(int x, int y)
		: xPos(x), yPos(y)
	{
		//cout << "explicit Point(int x, int y)" << endl;
	}

	// ���� ������ - Default ���� !!!!
	Point(Point &ref)
		: xPos(ref.xPos), yPos(ref.yPos)
	{
		cout << "Default Copy Constructor" << endl;
	}

	~Point() {}


public:
	Point operator+ (Point &ref) // �ش� Ŭ���� ��ü�� ������ �� !!!!
	{							 // ��ȯ���� "Reference"�� ���� �ʵ��� ������ ��.
								 // �Լ� ������ ���� ������ ��ȯ�ϴ� ���̱� ������, ����ġ ���� ������ ������ !!!!
		cout << "Point operator+ (Point &ref)" << endl;
		return Point(xPos + ref.xPos, yPos + ref.yPos); // �ӽ� ��ü�� ��ȯ������,
														// �״�� �ٷ� �־��ִ� ������ �����Ϸ��� ����ȭ�� �����Ѵ� !!!!
	}

	Point operator+ (int n) // �ش� Ŭ���� ��ü ������� int �ڷ����� ���� �� �� !!!!
	{
		cout << "Point operator+ (int n)" << endl;
		return Point(xPos + n, yPos + n); // �ӽ� ��ü�� ��ȯ������,
										  // �״�� �ٷ� �־��ִ� ������ �����Ϸ��� ����ȭ�� �����Ѵ� !!!!
	}

	// ���� �������� Operator Overloading - Default ���� !!!!
	Point& operator= (Point &ref)
	{
		cout << "Default Assignment Operator" << endl;
		xPos = ref.xPos; // ����� ������.
		yPos = ref.yPos;

		return *this; // ��ȯ���� �����ϴ� ������ point1 = point2 = point3;
					  // �̷��� ������ �����ϱ� ���ؼ� !!!!
	}

	friend ostream& operator<< (ostream &out, Point &ref) // "<< Operator Overloading"
	{													  // ostream Ŭ���� ���ο� private ���...
		out << '(' << ref.xPos << ", " << ref.yPos << ')';
		return out;
	}

private:
	int xPos;
	int yPos;
};

// ###################################################
// ������ ���� �� �����ڰ� �ش� Ŭ������ �ƴ� ���...
// ex. �Ϲ� �ڷ��� + �ش� Ŭ���� ��ü
// 
// ��ȸ�ϴ� ��� - Ŭ���� �ܺ��� ���� �Լ��� �̿� !!!!
// ###################################################

Point operator+ (int n, Point &ref) // �ӽ� ��ü�� "Reference"�� ��ȯ���� ���ô� !!!!
{
	cout << "Point operator+ (int n, Point &ref)" << endl;
	return Point(ref + n); // Point& operator+ (int n)�� ���� ��ü�� ���������...
						   // �װ��� ���ؼ� ���� �����ڰ� ȣ�� �ȴ�.
						   // �ֳ��ϸ�, Ŭ���� �ܺζ� get(), set() �Լ��� �ƴϰ����� ����� ���� �Ұ����̴ϱ�...
						   // Ŭ���� ����� "Operator Overloading"�� ���� �״�� ����...
}


int main(void)
{
	cout << "################################################################################" << endl;
	cout << "### The concepts of The Operator Overloading" << endl << endl;

	// �� X, Y ��ǥ���� ������ �����ϰ� �ϰ� ����.
	Point point11(100, 200);
	Point point12(300, 400);

	cout << "point11: " << point11 << endl;
	cout << "point12: " << point12 << endl << endl;


	Point point13 = point11 + point12; // �� �� ���� ����.
	Point point14 = point11.operator+(point12); // ��� �Լ� ȣ�� ������� �� ����.

	// Ŭ���� ����� ���ǵ� Point& operator+ (Point &ref) �Լ��� ���� ��ü point11�� �������� ����˴ϴ�. 
	// ���ο��� ���ڷ� ���� point12 ��ü�� ����� �̿��Ͽ� �� ��ǥ���� ������ �����մϴ�.
	// �� ����� ��ȯ�Ͽ� point3�� ���� ������ �ϰ� �ִ� ����

	cout << "point13: " << point13 << endl;
	cout << "point14: " << point14 << endl << endl;


	cout << "#################################################" << endl << endl;

	Point point21(100, 200);
	cout << endl;

	cout << "point22" << endl;
	Point point22 = point21 + 400; // Ŭ������ ����� ���ÿ� ��ü�� �ʱ�ȭ �ϹǷ�, ���� ������ ȣ�� !!!!
	cout << endl;

	cout << "point23" << endl;
	Point point23 = 400 + point21; // (������ �����ε� ������ ���) ������ ����, ���� ��ü �������� �����ϱ� ������...
	cout << endl;				   //
								   // �׷���, ��ȸ�ϴ� ����� �����ؾ� �մϴ� !!!!
								   // "Operator Overloading"�� ���� �Լ��� �������մϴ�. (�Ű������� �ش� ���� ������...)
								   // ��, �������� �������� ������ ���� �� �ϳ��� ������ ��ü Ÿ���̾�� �Ѵ�.
								   // ��ü Ÿ�Կ��� ��ü �����Ͱ� �ƴ� ���� ��üŸ�԰� Reference�� �;��Ѵ�.

	cout << "point24" << endl;				  // #######################################################################################
	Point point24 = operator+ (400, point21); // �� �� ���� ����.
	cout << endl;							  // �Լ� �������� "Point operator+ (int n);"�� �����.
											  // ���ο��� �ӽ� ��ü�� �����ϰ� ���� ������ �����ϴ� ���� �ƴϰ� �ٷ� return �ϱ� ������,
											  // point24 ��ü�� ������ ���ÿ� �ʱ�ȭ �ɶ� ȣ��Ǵ� ���� �����ڸ� ȣ�� �ȴ� !!!!
											  // �����Ϸ��� ����ȭ�� ���־��� !!!!
											  // #######################################################################################

	cout << "point22: " << point22 << endl;
	cout << "point23: " << point23 << endl;
	cout << "point24: " << point24 << endl << endl;

	// ###########################################################
	// ��� ���Ƿ� ���� �����̱� ������, ��ȯ ��Ģ�� �ش��ϴ� ����
	// �������� ��������� �ذ��� �� �ִ�.
	// ###########################################################
	// Ŭ���� ��� �Լ��θ� "Operator Overloading"�ؾ� �ϴ� ���
	// - ������ ��ȯ ��Ģ�� ������ �ʴ� ��츦 �ǹ���.
	//
	// case 1. ���� ������ - "="
	// case 2. �Լ� ȣ�� ������ - "()"
	// case 3. �迭 �ε��� ������ - "[]"
	// case 4. ��� ���� ������ ������ - "->"
	// ###########################################################


	cout << "################################################################################" << endl;
	cout << "### Assignment Operator Overloading " << endl << endl;

	Point point31(100, 200);
	Point point32(300, 400);

	Point point33 = point31 + point32; // ��ü ������ ���ÿ� ���� ������ ���� ������ ȣ��

	Point point34;
	point34 = point31 + point32; // ��ü ���� ������ ���� ������ ����Ʈ ���� ������ ȣ��
								 // ��� �� ���� ����� "���� ����"
								 // �׷���, �޸� ���� �Ҵ��ϴ� ����� �ִٸ� "���� ����"�� �ϴ� �������� �����ؾ� ��.

	cout << "################################################################################" << endl;

	Point point41(100, 200);
	Point point42(10, 20);
	Point point43(1, 2);
	cout << endl;

	point41 = point42 = point43; // ���ʿ�, "=" �����ڰ� �����ʺ��� ����ǹǷ� ���ϴ� ����� ���� !!!!

	cout << "point41: " << point41 << endl;
	cout << "point42: " << point42 << endl;
	cout << "point43: " << point43 << endl;

	return 0;
}