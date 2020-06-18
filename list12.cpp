//list �ӿ�

#include <iostream>
#include <list>
using namespace std;

template <class T>

void printLst(list<T>& lst) {
	for (auto& ch : lst) {
		cout << ch << " ";
	}
	cout << endl;

}

class A {

public:
	A(int a, int b)
		:_a(a)
	{
	
		cout << "A(int ,int)" << endl;
	}
	bool operator < (const A& a) {
	
		return _a < a._a;
	}
	bool operator > (const A& a) {

		return _a > a._a;
	}

private:
	int _a;

};

//void test1() {
//	list<int>lst1;//�޲ι���
//	list<char>lst2(5, 'a');//����n��val //aaaaa
//
//	char str[] = "12345";
//	list<char>lst3(str, str + 5); //�ڵ��������䷶Χ�ڹ���list//12345
//	list<char>lst4(lst2.begin(), lst2.end()); //aaaaa
//
//	list<char>lst5(lst3);//12345
//	list<int>lst6(3, 1);
//	//����������
//	list<char>::iterator it3 = lst3.begin();
//	while (it3 != lst3.end()){
//		cout << *it3 << " ";
//		//*it3 = '6';
//		++it3;
//	}
//	cout << endl;
//	////���޸ĵĽ��д�ӡ
//	//cout << " �޸�֮��Ľ��: " << endl;
//	//it3 = lst3.begin();
//	//while (it3 != lst3.end()){
//	//	cout << *it3 << " ";
//	//	++it3;
//	//}
//	//cout << endl;
//
//	list<int>::iterator it6 = lst6.begin();
//	while (it6 != lst6.end()){
//		cout << *it6 << " ";
//		*it6 = 5;
//		++it6;
//	}
//	cout << endl;
//	//���޸ĵĽ��д�ӡ
//	cout << " �޸�֮��Ľ��: " << endl;
//	it6 = lst6.begin();
//	while (it6 != lst6.end()){
//		cout << *it6 << " ";
//		++it6;
//	}
//	cout << endl;
//
//	//��Χfor����
//	//����Ҫʹ��ӡ�Ľ�������޸�,��������ٶ����ʱ��ȡ&
//	for (auto ch : lst3) {
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	//for (auto& ch:lst3) {
//	//	cout << ch << " ";
//	//	ch = 'X';
//	//}
//	//cout << endl;
//
//	//for (auto& ch : lst3) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//	//����
//	list<char>::reverse_iterator rit = lst3.rbegin();
//	while (rit != lst3.rend()) {
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	//const ������
//	list<char>::const_iterator cit = lst3.cbegin();
//	while (cit != lst3.cend()) {
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//}

//void test2() {
//
//	//list<int>lst;
//	//lst.push_back(1);
//	//lst.push_front(0);
//	//lst.push_front(-1);
//	//lst.push_front(-2);
//	//for (auto& ch:lst) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//	////βɾ
//	//lst.pop_back();
//	//printLst(lst);
//	////ͷɾ
//	//lst.pop_front();
//	///*for (auto& ch : lst) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;*/
//	//printLst(lst);
//
//	list<A>lst;//�ò����������������
//
//	A a(5, 6);//���õ��ÿ�������
//	lst.emplace_back(10,9);//������emplace�Ͳ�������������,��Ϊ�ڲ��Ѿ���������,���Ч�ʸ�
//	lst.emplace_front(-1, 0);
//	lst.emplace_front(a);
//}

//�м�:lst�������ڲ���֮��,���ᵼ�µ�����ʧЧ,���³��������֤
//void test3() {
//	//����: �ȿ��Դ����������λ��,Ҳ���Դ�������������λ��
//	list<int>lst;
//	//list�������ڲ���󲻻�ʧЧ
//	lst.insert(lst.begin(), 1); //��lstͷ������1��1
//	list<int>::iterator it = lst.begin();
//	cout << "*it: " << *it << endl;
//	printLst(lst);//1
//	lst.insert(lst.begin(), 3, 0);//��lst��ͷ������3��0
//	cout << "*it: " << *it << endl;
//	printLst(lst);//0001
//	list<int>cop(lst);
//	lst.insert(lst.end(), cop.begin(), cop.end());//�������������  ����ʹ���Լ��ĵ�����
//	//lst.insert(lst.end(), lst.begin(), lst.end());// ע������ʹ���Լ�����ı�����,���³��������һ����ѭ���Ĺ���
//
//	cout << "*it: " << *it << endl;
//	printLst(lst);//0001 0001
//
//	//insert: �����Դ����������λ��,Ҳ���Բ�������������λ��
//	////**���ɾ��֮���µ�����ʧЧ,����ɾ���ӿں�,��Ҫ���¸��µ�����:1.����erase�ķ���ֵ,2.���õ������ӿ�
//	cout << "erase" << endl;
//	//lst.erase(it); //ɾ����һ��Ԫ�ص�λ�� 
//	//cout << "*it" << *it << endl; //ɾ��Ҳ�ᵼ�µ�����ʧЧ����ԭ������ɾ�� ֮��,���¿ռ��ͷ�,Ȼ���ٽ����õ���ʹ�÷Ƿ��ڴ�ռ䣩
//	//ɾ��֮��,Ȼ���ڴ�ӡ���µ�����ʵЧ.
//	//����취�����»�ȡ������,Ȼ���ӡ�������һ��Ԫ�ص�λ��
//	it = lst.erase(it);
//	cout << "*it: "<<*it << endl; //ɾ��Ҳ�ᵼ�µ�����ʧЧ����ԭ������ɾ��֮��Ȼ���ٽ����õ�����Ŀǰ�Ľ����
//	printLst(lst); 
//	lst.erase(lst.begin(),lst.end());//ɾ��[begin(),end)�����λ�õ�ֵ
//	printLst(lst);
//	//resize: �ӿ�
//	cout << "resize" << endl;
//	lst.resize(5);// Ĭ�����5��0
//	printLst(lst);
//	lst.resize(7,1);//
//	printLst(lst);
//
//	//����list������ӿ�
//	//Ӧ��: �����һ������,��ɾ�����е�Ԫ��
//	//remove: ɾ��ָ��ֵ,����ж��,��ȫ��ɾ��,���û�������κθı�
//	cout << "remove" << endl;
//	lst.remove(1);//ɾ��lst�е�1
//	printLst(lst); 
//	lst.remove(10);//ɾ��lst�е�10  ָ��Ԫ�ز�����,��ô�����κεĸı�,ֻɾ�������Ԫ�ض���
//	printLst(lst);
//	lst.remove(0);//ɾ��lst�е�0
//	printLst(lst);
//    //remove ɾ��ʱ,ֻɾ��ָ����Ԫ��,��Ԫ�ص�λ���޹�
//
//	int a[5] = { 1, 2, 1, 2, 1 };
//	list<int>lst2(a,a+5);
//	printLst(lst2);
//	lst2.remove(2);
//	printLst(lst2);
//
//}
//void test4() {
//	//if�ӿ�: �ҵ��ض���ֵ�����޸�
//	//remove_if();//����
//	list<int>lst1;
//	lst1.push_back(1);
//	lst1.push_back(2);
//	lst1.push_back(3);
//	lst1.push_back(4);
//	printLst(lst1);
//
//	list<int>lst2;
//	lst2.push_back(7);
//	lst2.push_back(8);
//	lst2.push_back(9);
//	printLst(lst2);
//	//splice: ƴ��ʱ,��ƴ�ӵ�Ԫ��ֱ�Ӵ����һ��lst1,�ڶ���list�в��ٱ�����ƴ�ӵ�Ԫ��
//	lst1.splice(++lst1.begin(), lst2); //�ӵ�ǰλ�õ�ǰ����в���  ������lst2ʱ,,��ʱ��Ϊȫ���ǿ���
//	cout << "splice" << endl;
//	printLst(lst1);
//	printLst(lst2);
//	lst2.splice(lst2.begin(),lst1,++lst1.begin(),--lst1.end());
//	printLst(lst1);
//	printLst(lst2);
//
//	lst1.splice(lst1.end(),lst2,--lst2.end());
//	printLst(lst1);
//	printLst(lst2);
//	//unique:(ȥ���������ЧԪ��)  ʹ��֮ǰ��Ҫlst����
//	lst2.push_back(7);
//	lst2.push_back(8);
//	lst2.push_back(9);
//	lst2.push_back(2);
//	printLst(lst2);
//	//unique:(ȥ��)  ʹ��֮ǰ��Ҫlst����  ����sort�ӿڽ��д���    
//	lst2.unique();
//	cout << "unique" << endl;
//	printLst(lst2);
//
//	lst2.sort();
//	cout << "sort: " << endl;
//	printLst(lst2);
//	lst2.unique();
//	cout <<" sorted unique: "<<endl;
//	printLst(lst2);
//}

//sort�ӿ�
void test5() {
	//list<A>lst1;
	//lst1.emplace_back(1,1);
	//lst1.emplace_back(2,2);
	//lst1.emplace_back(3,3);
	//lst1.emplace_back(4,4);
	//lst1.emplace_back(5,5);
	////�����Ҫ���Զ������ͽ�������,��ô�Զ���������Ҫ֧�ֱȽ�����
	//lst1.sort();
	////printLst(lst1);

	//merge sorted  lists:�ϲ�������������
	//�ϲ�֮ǰҪ��֤����
	list<int>lst2;
	lst2.push_back(4);
	lst2.push_back(10);
	lst2.push_back(6);
	lst2.push_back(1);
	lst2.sort();
	printLst(lst2);
	//list<int>lst3(lst2); //
	//lst2.sort();
	//lst3.sort();
	//lst2.merge(lst3);
	//printLst(lst2);
	//cout << "reverse:" << endl;
	//lst2.reverse();
	//printLst(lst2);
}
int main() {
	// test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}
























