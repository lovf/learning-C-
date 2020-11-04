
//重点: 子类的成员函数
////1.子类的构造函数
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
//	//编译器自动生成的默认构造自动调用父类的默认构造
//public:
//	//编译期自动生成的默认构造自动调用父类的默认构造
//	//显示定义的构造函数也自动调用父类的默认构造,在初始化列表中调用父类构造
//	//父类的调用父类的初始化列表完成初始化
//	Student(int id = 100, int age = 25)
//		/*:_age(age)  //父类成员必须用父类构造函数完成初始化
//		, _id(id)*/ //上面的两个是不成立的因为他们属于父类的成员,需要调用父类的初始化列表进行初始化
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
//	Student st; //定义了一个学生类,竟然调用了Person中的成员
//}
//
////子类构造函数:
////1.一定会自动调用父类的构造函数
//   //a: 如果不显示调用,自动调用父类的默认构造
//   //b: 如果显示调用,则调用显示指定的父类构造
////2.继承父类的成员变量,一定通过父类的构造函数完成初始化,在子类的初始化列表中只能显示初始化自雷新增成员变量
////3.初始化顺序:一定是首先初始化父类成员,再去初始化子类成员
////4.创建子类对象时,首先调用子类的构造函数,在子类构造函数的初始化列表中调用父类的构造函数,先执行父类的构造逻辑,然后再执行子类本身的构造逻辑
//
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.子类的拷贝构造函数
//
//#include <iostream>
//using namespace  std;
//
//class Person{
//public:
//	//父类的构造
//	Person(int id = 10, int age = 20)
//		:_id(id)
//		, _age(age)
//	{
//		cout << "Person(int,int)" << endl;
//	}
//	Person(int id, int age, int num) {
//		cout << "Person(int,int,int)" << endl;
//	}
//	//父类的拷贝构造
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
//	//假如没有显示定义编译器自动生成的拷贝构造自动调用父类的拷贝构造
//	//显示定义的拷贝构造,自动调用父类的默认构造,不是父类的拷贝构造
//	//调用父类的拷贝构造是有切片的操作
//	Student(const Student& st)
//		/*	:_id(st._age)
//		, _id(st._id)*/
//		: _num(st._num)
//		//, Person(st._age,st._id) //调父类构造: Person(int,int)
//		, Person(st) ////调父类构造:Person(const Person&) 因为前面显示定义了
//	{
//		cout << "Student(const Student&)" << endl;
//	}
//
//
//	//编译器自动调用生成的赋值符重载函数自动调用父类的赋值运算符重载函数
//
//	//////这块是在子类中显示定义了: 结果是调用了子类的赋值运算符重载函数,
//	////子类赋值和父类运算符构成了同名隐藏
//	//Student& operator=(const Student& st) {
//	//	if (this != &st) {
//	//	_id = st._id;
//	//	_age = st._age;
//	//	}
//	//	cout << "Student& operator=(const Student& )" << endl;
//	//	return *this;
//	//	}
//	//	
//	//显示调用父类的赋值运算符: 
//	Student& operator=(const Student& st) {
//		if (this != &st) {
//			Person::operator=(st); //前面添加了父类名+::(作用限定符进行访问)
//			_num = st._num;
//		}
//		cout << "Student& operator=(const Student& )" << endl;
//		return *this;
//	}
//
//	~Student() {
//		cout << "~~Student()" << endl;
//	//	Person:: ~Person();  //显示在调用父类的析构属于多此一举,因为无论在任何时候编译器会自动调用父类中的析构
//	}
//
//private:
//	int _num;
//
//};
////子类的拷贝构造:
////1.默认行为(没有显示定义子类的拷贝构造):调父类的拷贝构造
////2.显示定义子类拷贝构造的默认行为(没有显示调用父类的拷贝构造): 调父类的默认构造
////3.在子类的拷贝构造中可以指定调用哪一个父类构造函数,不一定是拷贝构造
//void test1() {
//	Student st; //定义了一个学生类,竟然调用了Person中的成员
//	//编译器自动生成的拷贝构造自动调用父类的拷贝构造
//	Student copy(st); //等价于Student copy=st;
//	Student str2(1, 1);
//	str2 = st;
//}
//
//
//void test2() {
//	Student st;
//	Student str2(1, 1);
//	cout << "赋值" << endl;
//	str2 = st;
//	//子类的赋值运算符:
//	//1.假如在子类中没有定义赋值运算符重载的函数,那么是属于默认行为, 默认行为:直接调用父类的赋值运算符重载
//	//2.显示定义: 和父类的赋值运算符同名隐藏,如果需要调用父类的赋值运算符,需要指定父类的作用域
//	//3.建议调用父类的赋值运算符:达到代码复用的目的
//
//}
//
//void test3() {
//	Student st;
//	//子类析构
//	//1.编译器自动生成的析构函数自动调用父类析构
//	//2.显示定义子类析构函数会自动调用父类析构
//	//3.无论子类析构是否显示调用父类析构,编译器都会自动调用一次父类析构
//	//4.子类析构和父类析构底层函数名相同,构成函数隐藏
//
//	//注意: 父类析构不需要显示调用,可以能会导致为此释放的问题
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

//1.继承的基本语法: 一般使用public继承:
//min(一般是父类的访问权限+子类的访问方式)
//同名隐藏: 只要出现在不同的作用域,函数名相同那么就能构成函数隐藏,就近原则
//切片操作:把子类的类型转化成父类的类型(拷贝切片/构造)
//指针/引用 不会发生拷贝

//2.子类构造函数   (顺序: 先完成父类的构造,在完成子类的构造)
//1>.默认调用父类的构造函数2>.显示定义也调用父类的构造函数

//3.子类的拷贝构造

//4.子类的赋值运算符重载
//1>.子类和父类构成函数隐藏

//5.析构 
//顺序(先调用子类的析构在调用父类的析构)



//*************继承与友元**************************

//友元关系不能继承,也就是说基类友元不能访问子类私有和保护成员

//*************继承与静态成员**************************

//静态成员被所有成员共享,包括继承下的成员,都是被共享的

//菱形继承: 数据冗余
//多继承
//菱形虚拟继承:解决数据冗余和二义性
//1.通过虚基表指针和虚基表实现
//2.如果需要访问公共成员:首先通过虚基表指针找到虚基表,读取偏移量,当前位置偏移指定位置的偏移量,找到公共部分的偏移量--->切片能操作过程
//3,通过指针的大小换取重复成员的大小
//4.时间换空间的语法
//黑盒测试: 只关注输入和输出
//白盒测试:看代码找问题
//笔试面试题:
//1.什么是菱形继承?零菱形继承的问题是什么?
//2.什么是菱虚拟继承?如何解决数据冗余和二义性的?
//3.继承和组合的区别是什么?什么时候用继承?什么时候用组合?
//***********************************************多态**************************************************

//多态: 怒通的对象执行同一种行为时,                       多种表现形式

//同一种行为的不同表现形态

//如果想要多态,前提是在继承下的行为
//在继承中构成堕胎的两个条件:
//1.必须通过基类的指针或者引用调用虚函数
//2.被调用的函数必须是虚函数,且派生类必须对基类的虚函数进行重写


//
//#include <iostream>
//using namespace  std;
//
////多态:
////1.是继承
////2.虚函数,子类完成虚函数的重写
////3.调用虚函数的类型必须是指针或者引用,一般都是父类指针/引用指向父类以及子类实体,即都为切片操作
////必须同时满足以上条件,缺一不可
//
//class Person{
//
//public:
//	Person() {
//		cout << "开辟Person对象资源" << endl;
//	
//	}
//
//	virtual void BuyTicket() {
//		cout << "买票-全价" << endl;
//	}
//	//
//	virtual ~Person(){
//		cout << "清理person对象资源" << endl;
//		//cout << "~Person()" << endl;
//	
//	}
//
//};
//
//class Student : public Person{
//	// 子类/基类        父类/派生类
//public:
//
//	Student() {
//	
//		cout << "开辟Student对象先添加的资源" << endl;
//	
//	}
//	/*virtual void BuyTicket() {
//		cout << "买票-半价" << endl;
//		}*/
//	//虚函数, 子类完成虚函数的重写
//	//虚函数的重写: 重写函数逻辑
//	//构成虚函数的重写条件:子类含有和父类接口完全相同的函数-->返回值,函数名,参数完全相同(例外: 协变,析构函数的重写)
//	//协变:返回值类型可以不同,但是返回值类型必须是父子关系的指针/引用
//	virtual void BuyTicket() {
//		cout << "买票-半价" << endl;
//	}
//	//子类析构函数和父类析构函数底层相同，所以只要父类析构是虚函数，则子类析构重新父类析构
//	~Student() {
//		cout << "清理Student对象新添加的资源" << endl;
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
//	//尝试在堆上开辟空间尝试,假入不调用delete会导致系统内存泄漏
//	/*Person* ptr1 = new Person;
//	Student* ptr2 = new Student;
//
//	delete ptr1;
//	delete ptr2;*/
//
//	//非多态: 看类型
//	//多态: 看实际指向的实体
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student; //此时在这块调的是父类的析构
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

//函数隐藏:
//1.函数名相同

//函数重载
//1.函数名相同参数不同

// 虚函数重写:
//1.接口完全一致:返回值,函数名,参数完全一致,如果不满足条件,但是函数名相同,则构成函数隐藏
//2.协变: 返回值类型可以不同,但是必须是父子关系的指针/引用
//注意: 如果父类函数加了virtual声明,则子类接口完全一致的函数也具有虚函数的属性,但是反过来不成立,建议对一般所有的虚函数都加上virtual

//析构函数重写
//1.只要父类的析构函数是虚函数，则子类的析构和父类的析构构成重写
//原因： 编译器对继承元关系下的所有类的析构函数的，名字做了统一处理，保证继承关系下的析构函数同名，一般把析构函数名称统一处理成destructor

//多态实现条件:
//1.继承
//2.父类定义了虚函数,子类重写了父类虚函数
//3.调用虚函数的类型必须是指针或者引用,一般都是父类指针/引用指向父类以及子类实体,即都为切片操作
//必须同时满足以上条件,缺一不可

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
	//接口完全一致 ,'
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

//	func(b); //b,c构成多态,,主要看对应哪一个打印出来是不是对应的实体
//	func(c);
}

int main () {

	test1();
    system("color A");
    system ("pause");
    return 0;
}
























