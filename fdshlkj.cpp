
//�ص�: ����ĳ�Ա����
////1.����Ĺ��캯��
//
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	Person(int id=10,int age=20) 
//		:_id(id)
//		,_age(age)
//	{
//		cout << "Person(int,int)" << endl;
//	}
//	Person(int id, int age, int num) {
//		cout << "Person(int,int,int)" << endl;
//	}
//
//protected:
//	int _id;
//	int _age;
//};
//
//class Student :public Person {
//	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
//public:
//	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
//	//��ʾ����Ĺ��캯��Ҳ�Զ����ø����Ĭ�Ϲ���,�ڳ�ʼ���б��е��ø��๹��
//	//����ĵ��ø���ĳ�ʼ���б���ɳ�ʼ��
//	Student(int id = 100, int age = 25)
//		/*:_age(age)  //�����Ա�����ø��๹�캯����ɳ�ʼ��
//		, _id(id)*/ //����������ǲ���������Ϊ�������ڸ���ĳ�Ա,��Ҫ���ø���ĳ�ʼ���б����г�ʼ��
//		: _num(id)
//		, Person(id,age)
//	{
//		cout << "Student(int,int)" << endl;
//	}
//private:
//	int _num;
//
//};
//
//void test1() {
//	Student st; //������һ��ѧ����,��Ȼ������Person�еĳ�Ա
//}
//
////���๹�캯��:
////1.һ�����Զ����ø���Ĺ��캯��
//   //a: �������ʾ����,�Զ����ø����Ĭ�Ϲ���
//   //b: �����ʾ����,�������ʾָ���ĸ��๹��
////2.�̳и���ĳ�Ա����,һ��ͨ������Ĺ��캯����ɳ�ʼ��,������ĳ�ʼ���б���ֻ����ʾ��ʼ������������Ա����
////3.��ʼ��˳��:һ�������ȳ�ʼ�������Ա,��ȥ��ʼ�������Ա
////4.�����������ʱ,���ȵ�������Ĺ��캯��,�����๹�캯���ĳ�ʼ���б��е��ø���Ĺ��캯��,��ִ�и���Ĺ����߼�,Ȼ����ִ�����౾���Ĺ����߼�
//
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.����Ŀ������캯��
//
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	//����Ĺ���
//	Person(int id = 10, int age = 20)
//		:_id(id)
//		, _age(age)
//	{
//		cout << "Person(int,int)" << endl;
//	}
//	Person(int id, int age, int num) {
//		cout << "Person(int,int,int)" << endl;
//	}
//	//����Ŀ�������
//	Person(const Person& p)
//		:_age(p._age)
//		, _id(p._id)
//	{
//		cout << "Person(const Person&)" << endl;
//	}
//
//	Person& operator=(const Person& p) {
//		if (this != &p) {
//			_id = p._id;
//			_age = p._age;
//		}
//		cout << "Person& operator=(const Person& )" << endl;
//		return *this;
//	}
//	~Person(){
//		cout << "~Person()" << endl;
//	
//	}
//
//protected:
//	int _id;
//	int _age;
//};
//
//class Student :public Person {
//
//public:
//
//	Student(int id = 100, int age = 25)
//		: _num(id)
//		, Person(id, age)
//	{
//		cout << "Student(int,int)" << endl;
//	}
//	//����û����ʾ����������Զ����ɵĿ��������Զ����ø���Ŀ�������
//	//��ʾ����Ŀ�������,�Զ����ø����Ĭ�Ϲ���,���Ǹ���Ŀ�������
//	//���ø���Ŀ�������������Ƭ�Ĳ���
//	Student(const Student& st)
//		/*	:_id(st._age)
//		, _id(st._id)*/
//		: _num(st._num)
//		//, Person(st._age,st._id) //�����๹��: Person(int,int)
//		, Person(st) ////�����๹��:Person(const Person&) ��Ϊǰ����ʾ������
//	{
//		cout << "Student(const Student&)" << endl;
//	}
//
//
//	//�������Զ��������ɵĸ�ֵ�����غ����Զ����ø���ĸ�ֵ��������غ���
//
//	//////���������������ʾ������: ����ǵ���������ĸ�ֵ��������غ���,
//	////���ำֵ�͸��������������ͬ������
//	//Student& operator=(const Student& st) {
//	//	if (this != &st) {
//	//	_id = st._id;
//	//	_age = st._age;
//	//	}
//	//	cout << "Student& operator=(const Student& )" << endl;
//	//	return *this;
//	//	}
//	//	
//	//��ʾ���ø���ĸ�ֵ�����: 
//	Student& operator=(const Student& st) {
//		if (this != &st) {
//			Person::operator=(st); //ǰ�������˸�����+::(�����޶������з���)
//			_num = st._num;
//		}
//		cout << "Student& operator=(const Student& )" << endl;
//		return *this;
//	}
//
//	~Student() {
//		cout << "~~Student()" << endl;
//	//	Person:: ~Person();  //��ʾ�ڵ��ø�����������ڶ��һ��,��Ϊ�������κ�ʱ����������Զ����ø����е�����
//	}
//
//private:
//	int _num;
//
//};
////����Ŀ�������:
////1.Ĭ����Ϊ(û����ʾ��������Ŀ�������):������Ŀ�������
////2.��ʾ�������࿽�������Ĭ����Ϊ(û����ʾ���ø���Ŀ�������): �������Ĭ�Ϲ���
////3.������Ŀ��������п���ָ��������һ�����๹�캯��,��һ���ǿ�������
//void test1() {
//	Student st; //������һ��ѧ����,��Ȼ������Person�еĳ�Ա
//	//�������Զ����ɵĿ��������Զ����ø���Ŀ�������
//	Student copy(st); //�ȼ���Student copy=st;
//	Student str2(1, 1);
//	str2 = st;
//}
//
//
//void test2() {
//	Student st;
//	Student str2(1, 1);
//	cout << "��ֵ" << endl;
//	str2 = st;
//	//����ĸ�ֵ�����:
//	//1.������������û�ж��帳ֵ��������صĺ���,��ô������Ĭ����Ϊ, Ĭ����Ϊ:ֱ�ӵ��ø���ĸ�ֵ���������
//	//2.��ʾ����: �͸���ĸ�ֵ�����ͬ������,�����Ҫ���ø���ĸ�ֵ�����,��Ҫָ�������������
//	//3.������ø���ĸ�ֵ�����:�ﵽ���븴�õ�Ŀ��
//
//}
//
//void test3() {
//	Student st;
//	//��������
//	//1.�������Զ����ɵ����������Զ����ø�������
//	//2.��ʾ�������������������Զ����ø�������
//	//3.�������������Ƿ���ʾ���ø�������,�����������Զ�����һ�θ�������
//	//4.���������͸��������ײ㺯������ͬ,���ɺ�������
//
//	//ע��: ������������Ҫ��ʾ����,�����ܻᵼ��Ϊ���ͷŵ�����
//}
//
//int main() {
//	//test1();
//	//test2();
//	test3();
//	system("color A");
//	system("pause");
//	return 0;
//}

//1.�̳еĻ����﷨: һ��ʹ��public�̳�:
//min(һ���Ǹ���ķ���Ȩ��+����ķ��ʷ�ʽ)
//ͬ������: ֻҪ�����ڲ�ͬ��������,��������ͬ��ô���ܹ��ɺ�������,�ͽ�ԭ��
//��Ƭ����:�����������ת���ɸ��������(������Ƭ/����)
//ָ��/���� ���ᷢ������

//2.���๹�캯��   (˳��: ����ɸ���Ĺ���,���������Ĺ���)
//1>.Ĭ�ϵ��ø���Ĺ��캯��2>.��ʾ����Ҳ���ø���Ĺ��캯��

//3.����Ŀ�������

//4.����ĸ�ֵ���������
//1>.����͸��๹�ɺ�������

//5.���� 
//˳��(�ȵ�������������ڵ��ø��������)



//*************�̳�����Ԫ**************************

//��Ԫ��ϵ���ܼ̳�,Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա

//*************�̳��뾲̬��Ա**************************

//��̬��Ա�����г�Ա����,�����̳��µĳ�Ա,���Ǳ�������

//���μ̳�: ��������
//��̳�
//��������̳�:�����������Ͷ�����
//1.ͨ�������ָ��������ʵ��
//2.�����Ҫ���ʹ�����Ա:����ͨ�������ָ���ҵ������,��ȡƫ����,��ǰλ��ƫ��ָ��λ�õ�ƫ����,�ҵ��������ֵ�ƫ����--->��Ƭ�ܲ�������
//3,ͨ��ָ��Ĵ�С��ȡ�ظ���Ա�Ĵ�С
//4.ʱ�任�ռ���﷨
//�ںв���: ֻ��ע��������
//�׺в���:������������
//����������:
//1.ʲô�����μ̳�?�����μ̳е�������ʲô?
//2.ʲô��������̳�?��ν����������Ͷ����Ե�?
//3.�̳к���ϵ�������ʲô?ʲôʱ���ü̳�?ʲôʱ�������?
//***********************************************��̬**************************************************

//��̬: ŭͨ�Ķ���ִ��ͬһ����Ϊʱ,                       ���ֱ�����ʽ

//ͬһ����Ϊ�Ĳ�ͬ������̬

//�����Ҫ��̬,ǰ�����ڼ̳��µ���Ϊ
//�ڼ̳��й��ɶ�̥����������:
//1.����ͨ�������ָ��������õ����麯��
//2.�����õĺ����������麯��,�����������Ի�����麯��������д


//
//#include <iostream>
//using namespace  std;
//
////��̬:
////1.�Ǽ̳�
////2.�麯��,��������麯������д
////3.�����麯�������ͱ�����ָ���������,һ�㶼�Ǹ���ָ��/����ָ�����Լ�����ʵ��,����Ϊ��Ƭ����
////����ͬʱ������������,ȱһ����
//
//class Person{
//
//public:
//	Person() {
//		cout << "����Person������Դ" << endl;
//	
//	}
//
//	virtual void BuyTicket() {
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//	//
//	virtual ~Person(){
//		cout << "����person������Դ" << endl;
//		//cout << "~Person()" << endl;
//	
//	}
//
//};
//
//class Student : public Person{
//	// ����/����        ����/������
//public:
//
//	Student() {
//	
//		cout << "����Student���������ӵ���Դ" << endl;
//	
//	}
//	/*virtual void BuyTicket() {
//		cout << "��Ʊ-���" << endl;
//		}*/
//	//�麯��, ��������麯������д
//	//�麯������д: ��д�����߼�
//	//�����麯������д����:���ຬ�к͸���ӿ���ȫ��ͬ�ĺ���-->����ֵ,������,������ȫ��ͬ(����: Э��,������������д)
//	//Э��:����ֵ���Ϳ��Բ�ͬ,���Ƿ���ֵ���ͱ����Ǹ��ӹ�ϵ��ָ��/����
//	virtual void BuyTicket() {
//		cout << "��Ʊ-���" << endl;
//	}
//	//�������������͸������������ײ���ͬ������ֻҪ�����������麯�����������������¸�������
//	~Student() {
//		cout << "����Student���������ӵ���Դ" << endl;
//		//cout << "~Student()" << endl;
//	}
//
//};
//
//void func(Person& p) {
//	p.BuyTicket();
//}
//
//void func2(Person* p) {
//	p->BuyTicket();
//}
//void test1() {
//
//	Person p;
//	Student s;
//
//	func(p);
//	func(s);
//	func2(&p);
//	func2(&s);
//}
//
//void test2() {
//	/*Person p;
//	Student s;*/
//	//�����ڶ��Ͽ��ٿռ䳢��,���벻����delete�ᵼ��ϵͳ�ڴ�й©
//	/*Person* ptr1 = new Person;
//	Student* ptr2 = new Student;
//
//	delete ptr1;
//	delete ptr2;*/
//
//	//�Ƕ�̬: ������
//	//��̬: ��ʵ��ָ���ʵ��
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student; //��ʱ���������Ǹ��������
//
//	delete ptr1;
//	delete ptr2;
//
//
//
//}
//
//int main () {
//	//test1();
//	test2();
//    system("color A");
//    system ("pause");
//    return 0;
//}

//��������:
//1.��������ͬ

//��������
//1.��������ͬ������ͬ

// �麯����д:
//1.�ӿ���ȫһ��:����ֵ,������,������ȫһ��,�������������,���Ǻ�������ͬ,�򹹳ɺ�������
//2.Э��: ����ֵ���Ϳ��Բ�ͬ,���Ǳ����Ǹ��ӹ�ϵ��ָ��/����
//ע��: ������ຯ������virtual����,������ӿ���ȫһ�µĺ���Ҳ�����麯��������,���Ƿ�����������,�����һ�����е��麯��������virtual

//����������д
//1.ֻҪ����������������麯����������������͸��������������д
//ԭ�� �������Լ̳�Ԫ��ϵ�µ�����������������ģ���������ͳһ��������֤�̳й�ϵ�µ���������ͬ����һ���������������ͳһ������destructor

//��̬ʵ������:
//1.�̳�
//2.���ඨ�����麯��,������д�˸����麯��
//3.�����麯�������ͱ�����ָ���������,һ�㶼�Ǹ���ָ��/����ָ�����Լ�����ʵ��,����Ϊ��Ƭ����
//����ͬʱ������������,ȱһ����

#include <iostream>
using namespace  std;

class A{
public:
	virtual void printV() {
		cout << "A::printV()" << endl;
	}
};

class B :public A{
public: 
	 virtual void printV() {
		cout << "B::printV()" << endl;
	}
};


class C :public B {
	//�ӿ���ȫһ�� ,'
public:
	virtual void printV() {
		cout << "C::printV()" << endl;
	}
};



void func(A& A) {

	A.printV();
}


void func(B& B) {

	B.printV();
}

void test1() {
	A a;
	B b;
	C c;
	func(a);
	func(b);

//	func(b); //b,c���ɶ�̬,,��Ҫ����Ӧ��һ����ӡ�����ǲ��Ƕ�Ӧ��ʵ��
//	func(c);
}

int main () {

	test1();
    system("color A");
    system ("pause");
    return 0;
}























