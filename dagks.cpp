//c++����ģ�����ģ��
һ.����ģ��
1.����ģ��:����һ�������ͨ�ú���,�����Ĳ��������Ͳ�����ȷ��,��һ����������������ͨ�ú����Ĳ���������,��ʹ�õĹ�����,
ֻҪ�������ͺ͸�ͨ������ƥ��,�Ͳ����˶ඨ�庯��(ֻ����һ��ͨ�ú���),ֱ�ӿ��Ե���ͨ�ú���,�ڵ��ù�����,����ʵ�ε�����
�������������͵�����,�Ӷ�ʵ�ֲ�ͬ�����ĵ���.
���� : �����˳���Գ�����������, �û����Զ�����ʶ��.(ʵ�ʵĴ���������ȫû���ٵ�ֻ���û�������ʶ�����)

2.����ģ��ĸ�ʽ
template<typename /class T1, typename/class T2, typename/class T3, typename/class T4, typename/class T5, ....>
����ֵ���� ������(�����б�){}

**��������:
template<typename T>
void Swap(T& left,T&right){  // ͨ�ú���ģ��
	T temp = left;
	left = right;
	right = temp;

}

template �ĺ����ǡ�ģ�塱���������� typename����class���ǹؼ��֣�T��һ�����Ͳ�������������������� 
typename��class��������ͬ�����Ǳ�ʾ���������������߿��Ի�����

3.����ģ���ʵ����
�ò�ͬ���͵Ĳ���ʹ�ú���ģ��ʱ,��Ϊ����ģ���ʵ����.
(1)��ʽʵ���� �ñ���������ʵ�ν�������ʵ�ʵ�����

#include <iostream>
using namespace std;

template <class T>

T Swap(const T left,const T right) {
	return left+right;
}

int main() {
	int a = 1, b = 3,ret1;
	double c = 2.1, d = 3.2,ret2;

	ret1 = Swap(a, b); //���ú���ģ��,��ʱT��int����
	ret2 = Swap(c, d);//���ú���ģ��,��ʱT��double����
	cout << ret1 << endl; //4
	cout << ret2 << endl; //5.3

	system("pause");
	return 0;
}
//***********************************************************************************************
(2)��ʾʵ����:�ں����ĺ������<����>ָ��������ʵ������
#include <iostream>
using namespace std;

template <class T>

T Swap(const T left,const T right) {
	return left+right;
}

int main() {
	int a = 1;
	double c = 2.1,ret;

	ret = Swap<double>(a, c);//��ʾʵ���� ���ú���ģ��,��ʱT��double����
	cout << ret << endl;
	system("pause");
	return 0;
}
//*******************************************************************************************************
��������������ʶ���л�����ʱ��,��ʱӦ�ý�����ʾʵ����.
2.����ģ���ƥ��ԭ��
(1).��ͨ������ģ�庯������ʱ,�����ͨ�����Ĳ������Ϳ�����ȫƥ��ʱ,������ִ����ͨ����ģ��,������ģ�庯����ʵ����.
(2).����ͨ����������ƥ��ʱ,����ʵ����֮����ȫƥ���������,���ʹ��ģ�庯��.
(3).�����Ѿ�ָ����ʵ���� (Add()<int >(a,c)),��ôһ��ִ�е���ģ�庯��.

��.��ģ��
1.��ʽ:
template <class T1, class T2, class T3, class T4, ..>
class ��ģ������
{

	//���ڳ�Ա����
};

template <class T> //������ģ�壬����������Ϊnumtype
class Compare { //��ģ����ΪCompare

private:
	T x, y;
public:
	Compare(T a, T b) { //���幹�캯��
		x = a;
		y = b;
	}
}




