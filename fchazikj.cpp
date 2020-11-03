//c++中的继承: 实际就是完成码代码的复用

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
//	//protected:类外不可见,类内部和子类可见
//protected:
//	string _name = "hfsdkj"; //姓名
//	//private: 在类外和子类中都不能访问
//private:
//	int _age = 18;//年龄
//
//};
//继承:类代码复用
//class/struct 新类名(子类/派生类): 需要继承的类(父类/基类)
               
//Student类是完全包含Person的,Student是可以调用Person中的内容的
//class Student:public Person //
//class Student :protected Person
//  class 定义的类默认继承方式是私有继承:private
//class Student : Person
// struct定义的类:默认继承方式:public
//struct Student : Person
//class Student :private Person
//{
//public:
//	void show() {
//		cout << _name << "\t" << _id << endl;
//		//父类private成员在子类中不可见,但是子类中确实有父类的私有成员
//		//cout << _age << endl;  //不能访问父类的私有成员
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
//	//Print,id在父类中的访问权限为public
//	/*p.Print();
//	p._id = 3;*/
//
//	//定义的Student是可以调用Person中的成员的
//	Student st; //st中不是包含Person,而是包含_name,_age;
//	//子类继承方式为protect/private,从父类中继承下来的所有成员的最低权限为protected/private
//	//所以在子类外不可见
//	/*st.Print();
//	st._id = 2;*/
//	/*st._age = 12;
//	st._name = "dfsajl";*/ //私有成员在子类中都不可见, 类外可定也是不可见的.
//}
//继承: 类级别的代码复用

//1.继承方式: public,protected,private
//2.protect访问权限/private访问权限: protect-->在当前类和子类中可见,其他地方不可见
                                 //private-->在当前类中可见,在其他地方不可见

//3.父类成员在子类中的访问权限:min(成员在父类中的原始访问权限,继承方式)
 
//4.一般都是public继承,protected/private继承很少使用/几乎不用
//5.默认继承方式:class-->private;struct--->public


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
//切片操作:等于把派生派特有的成员切掉
//子类对应类型赋值给父类对应类型的操作-->切片:安全不是隐式类型转化
//父类(指针/引用)赋值给子类(指针/引用)--->强制类型转化:不安全,存在访问越界风险.
//继承下来的东西就变成自己的了
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
//	//protected:类外不可见,类内部和子类可见
//protected:
//	string _name = "hfsdkj"; //姓名
//	//private: 在类外和子类中都不能访问
//private:
//	int _age = 18;//年龄
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
//		//父类private成员在子类中不可见,但是子类中确实有父类的私有成员
//		//cout << _age << endl;  //不能访问父类的私有成员
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
//	//切片操作:子类对象,指针,引用可以直接赋值给父类对象,指针,引用,此处不是隐式类型转换
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//父类对象不能赋值给子类对象
//	st = p;
//	st = (Student)p; //父类指针,引用不能直接赋值给子类指针,引用,强制转化
//	//强制转化也有可能导致错误,一般采用动态转化
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
////派生类可以给基类复制
////基类不可以给派生类赋值(成员不全)
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
//	//protected:类外不可见,类内部和子类可见
//protected:
//	string _name = "hfsdkj";
//	int _age = 18;//年龄
//};
//
//
////父类,子类作用域都是独立的,不同的作用域中可以有同名的成员.
//class Student :public Person {
//public:
//	//void setNum(int _num) {
//		//_num = _num; //选择给局部变量赋值,而不是成员变量赋值  2020
//	                   // 参数的值和成员变量的值尽量区分开,这块是由于参数的值和成员变量的值完全相同,因此执行就近原则
//		//this->_num ; //答案变成1999
//	void setNum(int num) {
//		_num = num; //结果是1999
//	}
//
//	void showId() {
//		//成员变量同名隐藏: 父类中的同名成员被子类中的同名成员隐藏掉
//		cout << _id << endl;
//		//怎样进行查看父类中的同名值: 父类名:+::(作用域限定符)
//		cout << Person::_id << endl;
//
//		////父类同名函数进行访问
//		//Person::showId();
//		Person::showId(10); //假如要调用父类中带参的,那么一定在这边也要进行带参设置
//	}
//	//子类本身的showId()和showId(int a)构成重载
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
//	st.showId();//结果100  能够观察到父类中也有_id,子类中也有_id,此时打印的结果只包含有子类中的结果,父类中的同名成员被子类所隐藏
//}
////同名隐藏: 父类和子类有同名的成员,子类只能看到自己的成员 ,不同作用域下,含有同名成员,当前作用域下的成员就会隐藏其他作用下的同名成员,不是继承系独有的
////         如果需要访问父类同名的成员,需要加父类作用域
////成员变量隐藏:成员变量名称相同
////函数隐藏:只要函数名字相同,就会构成函数隐藏和参数无关,--->这种情况发生在子类和父类当中,不在同一个作用域
////函数重载:在同一个作用域,函数名相同,但是参数不相同
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}

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

#include <iostream>
using namespace  std;

class Person{
public:
	//父类的构造
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int,int)" << endl;
	}
	Person(int id, int age, int num) {
		cout << "Person(int,int,int)" << endl;
	}
	//父类的拷贝构造
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
	//假如没有显示定义编译器自动生成的拷贝构造自动调用父类的拷贝构造
	//显示定义的拷贝构造,自动调用父类的默认构造,不是父类的拷贝构造
	//调用父类的拷贝构造是有切片的操作
	Student(const Student& st) 
		/*	:_id(st._age)
			, _id(st._id)*/
		: _num(st._num)
		//, Person(st._age,st._id) //调父类构造: Person(int,int)
		, Person(st) ////调父类构造:Person(const Person&) 因为前面显示定义了
	{
		cout << "Student(const Student&)" << endl;
	}


	//编译器自动调用生成的赋值符重载函数自动调用父类的赋值运算符重载函数

	//////这块是在子类中显示定义了: 结果是调用了子类的赋值运算符重载函数,
	////子类赋值和父类运算符构成了同名隐藏
	//Student& operator=(const Student& st) {
	//	if (this != &st) {
	//	_id = st._id;
	//	_age = st._age;
	//	}
	//	cout << "Student& operator=(const Student& )" << endl;
	//	return *this;
	//	}
	//	
	//显示调用父类的赋值运算符: 
	Student& operator=(const Student& st) {
		if (this != &st) {
			Person::operator=(st); //前面添加了父类名+::(作用限定符进行访问)
			_num = st._num;
		}
		cout << "Student& operator=(const Student& )" << endl;
		return *this;
	}


private:
	int _num;

};
//子类的拷贝构造:
//1.默认行为(没有显示定义子类的拷贝构造):调父类的拷贝构造
//2.显示定义子类拷贝构造的默认行为(没有显示调用父类的拷贝构造): 调父类的默认构造
//3.在子类的拷贝构造中可以指定调用哪一个父类构造函数,不一定是拷贝构造
void test1() {
	Student st; //定义了一个学生类,竟然调用了Person中的成员
	//编译器自动生成的拷贝构造自动调用父类的拷贝构造
	Student copy(st); //等价于Student copy=st;
	Student str2(1, 1);
	str2 = st;
}


void test2() {
	Student st;
	Student str2(1, 1);
	cout << "赋值" << endl;
	str2 = st;
//子类的赋值运算符:
	//1.假如在子类中没有定义赋值运算符重载的函数,那么是属于默认行为, 默认行为:直接调用父类的赋值运算符重载
	//2.显示定义: 和父类的赋值运算符同名隐藏,如果需要调用父类的赋值运算符,需要指定父类的作用域
	//3.建议调用父类的赋值运算符:达到代码复用的目的


}

int main() {
	//test1();
	test2();
	system("color A");
	system("pause");
	return 0;
}

//1.继承的基本语法:
//2.子类构造函数
//3.子类的拷贝构造
//4.子类的赋值运算符重载
































