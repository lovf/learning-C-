//c++�еļ̳�: ʵ�ʾ�����������ĸ���

//#include <string>
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	void Print() {
//	
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public: 
//	int _id=1;
//	//protected:���ⲻ�ɼ�,���ڲ�������ɼ�
//protected:
//	string _name = "hfsdkj"; //����
//	//private: ������������ж����ܷ���
//private:
//	int _age = 18;//����
//
//};
//�̳�:����븴��
//class/struct ������(����/������): ��Ҫ�̳е���(����/����)
               
//Student������ȫ����Person��,Student�ǿ��Ե���Person�е����ݵ�
//class Student:public Person //
//class Student :protected Person
//  class �������Ĭ�ϼ̳з�ʽ��˽�м̳�:private
//class Student : Person
// struct�������:Ĭ�ϼ̳з�ʽ:public
//struct Student : Person
//class Student :private Person
//{
//public:
//	void show() {
//		cout << _name << "\t" << _id << endl;
//		//����private��Ա�������в��ɼ�,����������ȷʵ�и����˽�г�Ա
//		//cout << _age << endl;  //���ܷ��ʸ����˽�г�Ա
//	}
//
//};
//
//class Empty {
//
//};
//
//void test1() {
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Student p;
//	//Print,id�ڸ����еķ���Ȩ��Ϊpublic
//	/*p.Print();
//	p._id = 3;*/
//
//	//�����Student�ǿ��Ե���Person�еĳ�Ա��
//	Student st; //st�в��ǰ���Person,���ǰ���_name,_age;
//	//����̳з�ʽΪprotect/private,�Ӹ����м̳����������г�Ա�����Ȩ��Ϊprotected/private
//	//�����������ⲻ�ɼ�
//	/*st.Print();
//	st._id = 2;*/
//	/*st._age = 12;
//	st._name = "dfsajl";*/ //˽�г�Ա�������ж����ɼ�, ����ɶ�Ҳ�ǲ��ɼ���.
//}
//�̳�: �༶��Ĵ��븴��

//1.�̳з�ʽ: public,protected,private
//2.protect����Ȩ��/private����Ȩ��: protect-->�ڵ�ǰ��������пɼ�,�����ط����ɼ�
                                 //private-->�ڵ�ǰ���пɼ�,�������ط����ɼ�

//3.�����Ա�������еķ���Ȩ��:min(��Ա�ڸ����е�ԭʼ����Ȩ��,�̳з�ʽ)
 
//4.һ�㶼��public�̳�,protected/private�̳к���ʹ��/��������
//5.Ĭ�ϼ̳з�ʽ:class-->private;struct--->public


//
//
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��Ƭ����:���ڰ����������еĳ�Ա�е�
//�����Ӧ���͸�ֵ�������Ӧ���͵Ĳ���-->��Ƭ:��ȫ������ʽ����ת��
//����(ָ��/����)��ֵ������(ָ��/����)--->ǿ������ת��:����ȫ,���ڷ���Խ�����.
//�̳������Ķ����ͱ���Լ�����
//#include <string>
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	void Print() {
//	
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public: 
//	int _id=1;
//	//protected:���ⲻ�ɼ�,���ڲ�������ɼ�
//protected:
//	string _name = "hfsdkj"; //����
//	//private: ������������ж����ܷ���
//private:
//	int _age = 18;//����
//
//};
//
//
//class Student:public Person 
//
//{
//public:
//	void show() {
//		cout << _name << "\t" << _id << endl;
//		//����private��Ա�������в��ɼ�,����������ȷʵ�и����˽�г�Ա
//		//cout << _age << endl;  //���ܷ��ʸ����˽�г�Ա
//	}
//protected:
//	int _num;
//};
//
//class Empty {
//
//};
//
//void test1() {
//	Person p;
//	Student st;
//	//��Ƭ����:�������,ָ��,���ÿ���ֱ�Ӹ�ֵ���������,ָ��,����,�˴�������ʽ����ת��
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//��������ܸ�ֵ���������
//	st = p;
//	st = (Student)p; //����ָ��,���ò���ֱ�Ӹ�ֵ������ָ��,����,ǿ��ת��
//	//ǿ��ת��Ҳ�п��ܵ��´���,һ����ö�̬ת��
//
//	Person& st = p;
//	Person* ptrs = &st;
//
//
//}
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////��������Ը����ิ��
////���಻���Ը������ำֵ(��Ա��ȫ)
//#include <string>
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	void Print() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	/*void showId() {
//		cout << _id << endl;
//		}*/
//
//	void showId(int a) {
//		cout << _id << endl;
//	}
//
//
//public:
//	int _id = 1;
//	//protected:���ⲻ�ɼ�,���ڲ�������ɼ�
//protected:
//	string _name = "hfsdkj";
//	int _age = 18;//����
//};
//
//
////����,�����������Ƕ�����,��ͬ���������п�����ͬ���ĳ�Ա.
//class Student :public Person {
//public:
//	//void setNum(int _num) {
//		//_num = _num; //ѡ����ֲ�������ֵ,�����ǳ�Ա������ֵ  2020
//	                   // ������ֵ�ͳ�Ա������ֵ�������ֿ�,��������ڲ�����ֵ�ͳ�Ա������ֵ��ȫ��ͬ,���ִ�оͽ�ԭ��
//		//this->_num ; //�𰸱��1999
//	void setNum(int num) {
//		_num = num; //�����1999
//	}
//
//	void showId() {
//		//��Ա����ͬ������: �����е�ͬ����Ա�������е�ͬ����Ա���ص�
//		cout << _id << endl;
//		//�������в鿴�����е�ͬ��ֵ: ������:+::(�������޶���)
//		cout << Person::_id << endl;
//
//		////����ͬ���������з���
//		//Person::showId();
//		Person::showId(10); //����Ҫ���ø����д��ε�,��ôһ�������ҲҪ���д�������
//	}
//	//���౾���showId()��showId(int a)��������
//	void showId(int a) {
//
//	}
//public:
//	int _id = 100;
//	int _num = 2020;
//};
//
//
//void test1() {
//	Student st;
//	//cout << st._num << endl; //2020
//	//st.setNum(1999);
//	//cout << st._num << endl;//2020
//	//cout << sizeof(Student) << endl;//36
//	//cout << sizeof(Person) << endl; //44
//	st.showId();//���100  �ܹ��۲쵽������Ҳ��_id,������Ҳ��_id,��ʱ��ӡ�Ľ��ֻ�����������еĽ��,�����е�ͬ����Ա������������
//}
////ͬ������: �����������ͬ���ĳ�Ա,����ֻ�ܿ����Լ��ĳ�Ա ,��ͬ��������,����ͬ����Ա,��ǰ�������µĳ�Ա�ͻ��������������µ�ͬ����Ա,���Ǽ̳�ϵ���е�
////         �����Ҫ���ʸ���ͬ���ĳ�Ա,��Ҫ�Ӹ���������
////��Ա��������:��Ա����������ͬ
////��������:ֻҪ����������ͬ,�ͻṹ�ɺ������غͲ����޹�,--->�����������������͸��൱��,����ͬһ��������
////��������:��ͬһ��������,��������ͬ,���ǲ�������ͬ
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}

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
//		, _id(id)*/ //����������ǲ���������Ϊ�������ڸ���ĳ�Ա,��Ҫ���ø���ĳ�ʼ���б���г�ʼ��
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
////4.�����������ʱ,���ȵ�������Ĺ��캯��,�����๹�캯���ĳ�ʼ���б��е��ø���Ĺ��캯��,��ִ�и���Ĺ����߼�,Ȼ����ִ�����౾��Ĺ����߼�
//
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.����Ŀ������캯��

#include <iostream>
using namespace  std;

class Person{
public:
	//����Ĺ���
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int,int)" << endl;
	}
	Person(int id, int age, int num) {
		cout << "Person(int,int,int)" << endl;
	}
	//����Ŀ�������
	Person(const Person& p)
		:_age(p._age)
		, _id(p._id)
	{
		cout << "Person(const Person&)" << endl;
	}

	Person& operator=(const Person& p) {
		if (this != & p) {
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person& )" << endl;
		return *this;
	}
protected:
	int _id;
	int _age;
};

class Student :public Person {
	
public:

	Student(int id = 100, int age = 25)
		: _num(id)
		, Person(id, age)
	{
		cout << "Student(int,int)" << endl;
	}
	//����û����ʾ����������Զ����ɵĿ��������Զ����ø���Ŀ�������
	//��ʾ����Ŀ�������,�Զ����ø����Ĭ�Ϲ���,���Ǹ���Ŀ�������
	//���ø���Ŀ�������������Ƭ�Ĳ���
	Student(const Student& st) 
		/*	:_id(st._age)
			, _id(st._id)*/
		: _num(st._num)
		//, Person(st._age,st._id) //�����๹��: Person(int,int)
		, Person(st) ////�����๹��:Person(const Person&) ��Ϊǰ����ʾ������
	{
		cout << "Student(const Student&)" << endl;
	}


	//�������Զ��������ɵĸ�ֵ�����غ����Զ����ø���ĸ�ֵ��������غ���

	//////���������������ʾ������: ����ǵ���������ĸ�ֵ��������غ���,
	////���ำֵ�͸��������������ͬ������
	//Student& operator=(const Student& st) {
	//	if (this != &st) {
	//	_id = st._id;
	//	_age = st._age;
	//	}
	//	cout << "Student& operator=(const Student& )" << endl;
	//	return *this;
	//	}
	//	
	//��ʾ���ø���ĸ�ֵ�����: 
	Student& operator=(const Student& st) {
		if (this != &st) {
			Person::operator=(st); //ǰ������˸�����+::(�����޶������з���)
			_num = st._num;
		}
		cout << "Student& operator=(const Student& )" << endl;
		return *this;
	}


private:
	int _num;

};
//����Ŀ�������:
//1.Ĭ����Ϊ(û����ʾ��������Ŀ�������):������Ŀ�������
//2.��ʾ�������࿽�������Ĭ����Ϊ(û����ʾ���ø���Ŀ�������): �������Ĭ�Ϲ���
//3.������Ŀ��������п���ָ��������һ�����๹�캯��,��һ���ǿ�������
void test1() {
	Student st; //������һ��ѧ����,��Ȼ������Person�еĳ�Ա
	//�������Զ����ɵĿ��������Զ����ø���Ŀ�������
	Student copy(st); //�ȼ���Student copy=st;
	Student str2(1, 1);
	str2 = st;
}


void test2() {
	Student st;
	Student str2(1, 1);
	cout << "��ֵ" << endl;
	str2 = st;
//����ĸ�ֵ�����:
	//1.������������û�ж��帳ֵ��������صĺ���,��ô������Ĭ����Ϊ, Ĭ����Ϊ:ֱ�ӵ��ø���ĸ�ֵ���������
	//2.��ʾ����: �͸���ĸ�ֵ�����ͬ������,�����Ҫ���ø���ĸ�ֵ�����,��Ҫָ�������������
	//3.������ø���ĸ�ֵ�����:�ﵽ���븴�õ�Ŀ��


}

int main() {
	//test1();
	test2();
	system("color A");
	system("pause");
	return 0;
}

//1.�̳еĻ����﷨:
//2.���๹�캯��
//3.����Ŀ�������
//4.����ĸ�ֵ���������
































