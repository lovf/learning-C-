///1. ����ʽ����
//����ʽ����Ҳ�������洢���ݵģ�������ʽ������ͬ���ǣ�������洢����<key, value>�ṹ�ļ�ֵ�ԣ���
//���ݼ���ʱ������ʽ����Ч�ʸ���.key��ʾ�������ݵ�����(������������Ϊ�κ�ֵ),value��ʾ������Ӧ������
//pair������������:----first(key)----second(value)-----

//first======>key    second=====>value
//ǿ��:======key��ʾ�������ݵ�����(������������Ϊ�κ�ֵ,����,�ַ���������,û�о��� )
//2. ��ֵ��
//������ʾ����һһ��Ӧ��ϵ��һ�ֽṹ���ýṹ��һ��ֻ����������Ա����key��value��key�����ֵ��
//value��ʾ��key��Ӧ����Ϣ�����磺����Ҫ����һ��Ӣ��������ֵ䣬�Ǹ��ֵ��б�Ȼ��Ӣ�ĵ��������Ӧ
//�����ĺ��壬���ң�Ӣ�ĵ����������ĺ�����һһ��Ӧ�Ĺ�ϵ����ͨ����Ӧ�õ��ʣ��ڴʵ��оͿ����ҵ���
//���Ӧ�����ĺ��塣

//3. ���νṹ�Ĺ���ʽ����
//����Ӧ�ó����Ĳ�Ͱ��STL�ܹ�ʵ�������ֲ�ͬ�ṹ�Ĺ���ʽ���������ͽṹ���ϣ�ṹ�����ͽṹ�Ĺ���ʽ
//������Ҫ�����֣�map��set��multimap��multiset�������������Ĺ�ͬ���ǣ�ʹ��ƽ��������(�������)
//��Ϊ��ײ����������е�Ԫ����һ����������С�����һ���ν���ÿһ��������
//map��set��multimap��multiset  ���ǲ����޸�key��

//3.1 set----�д�ŵ�Ԫ�ض��ǲ��ظ���---��������ȥ�ز���
//3.1.1 set�Ľ���
//==key��value��һ����,���ݲ����ظ�
//==�������
//==�����޸�

//���룺
//1. set�ǰ���һ������洢Ԫ�ص�����
//2. ��set�У�Ԫ�ص�valueҲ��ʶ��(value����key������ΪT)������ÿ��value������Ψһ�ġ�set�е�Ԫ��
//�������������޸�(Ԫ������const)�����ǿ��Դ������в����ɾ�����ǡ�
//3. ���ڲ���set�е�Ԫ�����ǰ������ڲ��Ƚ϶���(���ͱȽ�)��ָʾ���ض��ϸ�������׼���������
//4. set����ͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_set���������������������˳����Ӽ�����ֱ�ӵ�����
//5. set�ڵײ����ö���������(�����)ʵ�ֵġ�

//ע�⣺
//1. ��map / multimap��ͬ��map / multimap�д洢���������ļ�ֵ��<key, value>��set��ֻ��value����
//�ڵײ�ʵ�ʴ�ŵ�����<value, value>���ɵļ�ֵ�ԡ�
//2. set�в���Ԫ��ʱ��ֻ��Ҫ����value���ɣ�����Ҫ�����ֵ�ԡ�
//3. set�е�Ԫ�ز������ظ�(��˿���ʹ��set����ȥ��)��
//4. ʹ��set�ĵ���������set�е�Ԫ�أ����Եõ���������
//5. set�е�Ԫ��Ĭ�ϰ���С�����Ƚ�========�õ�Ԫ��Ϊ��������
//6. set�в���ĳ��Ԫ��, ʱ�临�Ӷ�Ϊ:log(2^n)
//7.set�е�Ԫ�ز������޸�(Ϊʲô)
//8. set�еĵײ�ʹ�ö���������(�����)��ʵ��

//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//template<class T> 
//
//void PrintSet(const set<T>& set) {
//	for (const auto& e:set) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
////set�������ݱ���========
//void testSet1() {
//	//����set���͵Ĵ���
//	set<int> s1;
//	int arr[] = { 10, 2, 13, 4, 35 };
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	set<int> copy(s2);
//	//���������������
//	//set���������������====Ĭ����С�ڵıȽ�,��˵õ��������������
//	set<int>::iterator sit1 = s2.begin();
//	while (sit1 != s2.end()) {
//		cout << *sit1 << " ";
//		++sit1;
//	}
//	cout << endl;
//
//	//���մ��ڱȽ�:  ��������---�ݼ�
//	set<int, greater<int>> s3(arr, arr + sizeof(arr) / sizeof(arr[0]), greater<int>());
//	set<int, greater<int>>::iterator sit2 = s3.begin();
//	while (sit2 != s3.end()) {
//		cout << *sit2 << " ";
//
//		//set���������ܽ����޸�
//		//*sit2 = 10; ����key�ǲ��ܽ����޸ĵ�
//		++sit2;
//	}
//	cout << endl;
//
//	////====================���������ŵ�Ԫ�ز��ܽ����޸�
//
//	//���������
//	//��������====Ĭ����С�ڵıȽ�,��˵õ��������������
//	set<int>::reverse_iterator rit1 = s2.rbegin();
//	while (rit1 != s2.rend()) {
//		cout << *rit1 << " ";
//		++rit1;
//	}
//	cout << endl;
//
//	set<int>::reverse_iterator rit2 = s3.rbegin();
//	while (rit2 != s3.rend()) {
//		cout << *rit2 << " ";
//		++rit2;
//	}
//	cout << endl;
//}
//
//
////��֤set���ܴ���ظ�������====����ӡ��֮��õ�ֻ�ظ�����һ������
//void testSet2() {
//	int arr[] = { 10, 10, 10 };
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//��������====Ĭ����С�ڵıȽ�,��˵õ��������������
//	set<int>::iterator sit = s2.begin();
//	while (sit != s2.end()) {
//		cout << *sit << " ";
//		++sit;
//	}
//	cout << endl;
//}
////���ڲ�����õĽӿ�: 1.insert�ӿ� 2.insert(s.begin(),s.end()) ���������ӿ�
////ɾ��:
//void testSet3() {
//	set<int> s;
//
//	//Ԫ�ز���: ʧ��--->����ֵ: bool:true    iterator: �²���Ԫ�ص�λ��    
//	pair<set<int>::iterator, bool> kvRet = s.insert(1); //pair<set<int>::iterator, bool>===K  V��ֵ���ж��Ƿ����Ԫ��
//	bool ret = kvRet.second;
//
//	cout << ret << endl;
//	set<int>::iterator it = kvRet.first;
//	cout << *it << endl;
//
//	//�ظ�Ԫ�ز���:ʧ��--->����ֵ: bool:false    iterator:�Ѿ�����Ԫ�ص�λ��   
//	kvRet = s.insert(1);
//	ret = kvRet.second;
//	cout << ret << endl;
//	it = kvRet.first;
//	cout << *it << endl; //1 �Ѿ����ڵ�Ԫ��
//
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	it = s.begin();
//
//	//insert(iterator,value): iteratorֻ��һ���ο�λ��
//	it = s.insert(it, 12); //��ʾ�ڵ�һ��Ԫ�ص�λ��ǰ���һ��12,����ʵ�ʲ�һ���Ź�ȥ=====
//	//�ײ㻹�ǰ������������в����
//
//	cout << *it << endl; //��ӡ�²���Ԫ�ص�λ��
//	++it;
//	//cout << *it << endl;
//
//	//��ʾ��������µ�Ԫ��,��ΪҪ���������Ԫ���Ѿ�����
//	//s.insert(s.begin(), s.end());
//	//������µ�Ԫ��,s2��Ԫ��û��s�е�Ԫ��
//	set<int> s2;
//	s2.insert(s.begin(), s.end());
//
//	PrintSet(s);
//	//erase 1.ɾ��һ��λ��(s.begin())2.ɾ��һ��value(value) 3.ɾ��һ������������(s.begin(),s.end())
//	//PrintSet(s);
//	cout << "erase:" << endl;
//	s.erase(3);//ɾ��Ԫ��3 
//	PrintSet(s);
//
//	s.erase(s.begin());//ɾ����һ��λ�õ�Ԫ��
//	PrintSet(s);
//
//	s.erase(s.begin(),s.end());//ɾ��һ�������Ԫ��
//	PrintSet(s);
//
//	PrintSet(s2);
//	s2.clear();//��ʾ���Ԫ��
//	PrintSet(s2);
//}
//
////���ҽӿ�: �ҵ���:�����ҵ�����Ԫ�صĵ�����  û�ҵ�:����endԪ�صĵ������ȼ���  ����ֵ����end��ʾԪ�ز�����
////�õıȽ϶�
////count====��ʾvalue���ֵĴ���
////find======
//
//void testSet4() {
//	set<int> s;
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//
//	auto it = s.find(5);
//	cout << (it == s.end()) << endl; //�ҵ�������end
//
//	it = s.find(10);
//	cout << (it == s.end()) << endl; //û���ҵ�����end 
//
//	cout << s.count(5) << endl;
//	cout << s.count(10) << endl;
//
//	//������ò���
//	pair<set<int>::iterator, set<int>::iterator> p = s.equal_range(5);
//	cout << *(p.first) << endl;
//	cout << *(p.second) << endl;
//
//}
//int main() {
//
//	//testSet1();
//	//testSet2();
//	//testSet3();
//	testSet4();
//	system("pause");
//	return 0;
//}

//set�ӿ��ܽ�:
//�ص�:1.set�Ĺ��� 2.���������� 3.�����ɾ��  3.find��count�ӿ�(����Ч�ʸ�)=====��Ϊkey��value��һ����,��˵���value�ǲ����ظ���

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//3.2 map
//3.2.1 map�Ľ���
//���룺
//1. map�ǹ����������������ض��Ĵ���(����key���Ƚ�)�洢�ɼ�ֵkey��ֵvalue��϶��ɵ�Ԫ�ء�
//2. ��map�У���ֵkeyͨ�����������Ωһ�ر�ʶԪ�أ���ֵvalue�д洢��˼�ֵkey���������ݡ���ֵ
//key��ֵvalue�����Ϳ��ܲ�ͬ��������map���ڲ���key��valueͨ����Ա����value_type����һ��
//Ϊ��ȡ������Ϊpair :
//typedef pair<const key,T> value_type;
//3. ���ڲ���map�е�Ԫ�����ǰ��ռ�ֵkey���бȽ�����ġ�
//4. map��ͨ����ֵ���ʵ���Ԫ�ص��ٶ�ͨ����unordered_map����������map�������˳���Ԫ�ؽ���
//ֱ�ӵ���(����map�е�Ԫ�ؽ��е���ʱ�����Եõ�һ�����������)��
//5. map֧���±���ʷ�������[]�з���key���Ϳ����ҵ���key��Ӧ��value
//6. mapͨ����ʵ��Ϊ����������(��׼ȷ��˵��ƽ�����������(�����)


//key: ��ֵ����key������
//	 T�� ��ֵ����value������
// Compare : �Ƚ��������ͣ�map�е�Ԫ���ǰ���key���Ƚϵģ�ȱʡ����°���С�����Ƚϣ�һ�����
//		   ��(��������Ԫ��)�ò�������Ҫ���ݣ�����޷��Ƚ�ʱ(�Զ�������)����Ҫ�û��Լ���ʽ���ݱȽϹ���
//		   (һ������°��պ���ָ����߷º���������)
//		   Alloc��ͨ���ռ�������������ײ�ռ䣬����Ҫ�û����ݣ������û�����ʹ�ñ�׼���ṩ�Ŀռ�������
//		   ע�⣺��ʹ��mapʱ����Ҫ����ͷ�ļ���

//Ĭ�ϰ���key��С����Ĺ�ϵ���бȽ�============================================
//map����֧��operator[]���з���
//map���еĽӿڶ��ǻ���key���в��ҵ�

//#include <string>
//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//
//template<class K,class V> 
//
//
//void PrintMap(const map<K, V,less<K>>& mp) {
//	for (const auto& p:mp) {
//		cout << p.first << "--->" << p.second << endl;
//	}
//}
//
//
//template<class K, class V>
//void PrintMap(const map<K, V, greater<K>>& mp) {
//	for (const auto& p : mp) {
//		cout << p.first << "--->" << p.second << endl;
//	}
//}
//
//
//void testMap() {
//	map<int, int> mp1;
//	map<string, int> mp2; //��ʾkey��һ���ַ���,value��һ������  Ӧ��: ͳ�Ƶ��ʳ��ֵĴ���
//
//
//	//���ݵ�Ԫ: pair����
//	pair<int, int> arr[] = { { 1, 2 }, { 3, 4 } };
//	map<int, int> mp3(arr, arr + 2);
//
//	pair<string, int> arr2[] = { { "a", 10 }, { "bcd" , 5 } };
//	map<string, int> mp4(arr2, arr2 + 2);
//
//	//Ĭ�ϴ�ӡ��ֵ(С�ڱȽ�)�ǰ��յ�����˳����д�ӡ��
//	////��������: ��������key�Ĵ�С��ϵ�����������: ���������������
//	//map<int, int>::iterator it = mp3.begin();
//	//while (it != mp3.end()) {
//	//	//�����д��	:������֮���������pair,pair��֧��cout(���)
//	//	//cout<<*it<<endl;
//	//	//pair�ж����Ա,����ͨ����������->����ÿһ����Ա
//	//	cout << it->first << "--->" << it->second << endl;
//	//	++it;
//	//}
//
//	//map<string, int>::iterator it2 = mp4.begin();
//	//while (it2 != mp4.end()) {
//	//	cout << it2->first << "--->" << it2->second << endl;
//	//	++it2;
//	//}
//	//����Ĭ�ϴ�ӡ��ֵ(С�ڱȽ�)�ǰ��յ�����˳����д�ӡ��
//	
//	/////======��Ĭ�ϵ�С�ڱȽϸĳɴ��ڵıȽ�=====��key��С������бȽ�
//	////��������: ��������key�Ĵ�С��ϵ�����������: ���������������
//	map<int, int,greater<int>>::iterator it = mp3.begin();
//	while (it != mp3.end()) {
//		//�����д��	:������֮���������pair,pair��֧��cout(���)
//		//cout<<*it<<endl;
//		//pair�ж����Ա,����ͨ����������->����ÿһ����Ա
//		cout << it->first << "--->" << it->second << endl;
//		++it;
//	}
//
//	map<string, int, greater<int>>::iterator it2 = mp4.begin();
//	while (it2 != mp4.end()) {
//		cout << it2->first << "--->" << it2->second << endl;
//		++it2;
//	}
//	//////////////////////////////////////////////////////////////////
//
//	////ֻ���޸�value,�����޸�value;�޸���֮�����е�ֵ�����޸�֮���ֵ
//	//cout << "value�޸�" << endl;
//	//it = mp3.begin();
//	//while (it != mp3.end()) {
//	//	//�����д��	:������֮���������pair,pair��֧��cout
//	//	//cout<<*it<<endl;
//	//	//ͨ���������޸�
//	//	//it->first = 10;
//	//	it->second = 100;
//	//	//pair�ж����Ա,����ͨ����������->����ÿһ����Ա
//	//	cout << it->first << "--->" << it->second << endl;
//	//	++it;
//	//}
//
//
//	//operator[] (key)����ͨ��key�ҵ�����Ӧ��value,����value������
//	cout << "�޸�֮ǰ��Ӧ��ֵ: " << endl;
//	cout << mp4["a"] << endl; // mp4["a"]====�ҵ�mp4���ַ�a����Ӧ��value,��ʱkey��"a"
//	mp4["a"] = 1000;//�޸�value��Ӧ��ֵ
//	cout << "�޸�֮���Ӧ��ֵ: " << endl;
//	cout << mp4["a"] << endl;
//
//	cout << "[]�޸�֮��ȫ����ֵ: " << endl;
//	PrintMap(mp4);
//
//
//	//insert==Ҳ������ɲ���Ĳ���
//	//operator[]����:   ���key������,ֱ�Ӳ���
//	//1.����:K,V
//	//2.����ɹ�:����k��Ӧ��pair���ݵĵ�����,��ȡpair���ݶ�Ӧ��second(value��Ӧ��Ĭ��ֵ)
//	//  ����ʧ��:�����Ѿ����ڵ�K��Ӧ���ݵĵ�����,��ȡpair���ݶ�Ӧ��second(�Ѿ����ڵ�valueֵ)
//
//	mp4["f"] = 10;
//	cout << "[]����֮��ȫ����ֵ:" << endl;
//	PrintMap(mp4);
//	
//	cout << "insert: " << endl;
//	//����д��
//	//mp4.insert("fffff", 5);  //���Ĳ����Ǵ����,��ΪҪ����K,V��ֵ����˲���pair����=====K,V�����Ǹ���pair������
//
//	//Ҫ����pair���͵�����
//	//1.���ù���
//	mp4.insert(pair<string, int>("fffff", 5));
//	PrintMap(mp4);
//
//	//2.����make_pair����
//	mp4.insert(make_pair("aa", 5));
//	PrintMap(mp4);
//
//
//	//at����: ���key������,���쳣
//	//mp4.at("q");//��Ϊkey������,�޷�ͨ��key�ҵ���Ӧ�ļ�ֵ��
//
//	//erase:
//	//ɾ��ĳһ��λ�õ�Ԫ��
//	//ɾ��key����Ӧ�ļ�ֵ�Ե�����
//	//ɾ�������������Ԫ��
//	
//	//find����key���в��ҵ�
//	//�Ҳ�������end����
//	//countͳ�Ƽ�ֵΪkey��Ԫ���ж��ٸ�,key�����ظ�==һ�����ǵ���1,���ߵ���0
//}
//
//int main() {
//
//	testMap();
//	system("pause");
//	return 0;
//}

//���ܽ᡿
//1. map�еĵ�Ԫ���Ǽ�ֵ��
//2. map�е�key��Ψһ�ģ����Ҳ����޸�
//3. Ĭ�ϰ���С�ڵķ�ʽ��key���бȽ�;�õ��������ǵ���������
//4. map�е�Ԫ������õ�����ȥ���������Եõ�һ�����������
//5. map�ĵײ�Ϊƽ��������(�����)������Ч�ʱȽϸ�
//6. ֧��[]��������operator[]��ʵ�ʽ��в�����ҡ�

//3.3 multiset
//3.3.1 multiset�Ľ���
//multiset�ĵ�����
//[����]��
//1. multiset�ǰ����ض�˳��洢Ԫ�ص�����������Ԫ���ǿ����ظ��ġ�
//2. ��multiset�У�Ԫ�ص�valueҲ��ʶ����(��Ϊmultiset�б���洢�ľ���<value, value>��ɵļ�ֵ�ԣ�
//���value�������key��key����value������ΪT).multisetԪ�ص�ֵ�����������н����޸�(��ΪԪ������const��)�������Դ������в����ɾ����
//3. ���ڲ���multiset�е�Ԫ�����ǰ������ڲ��ȽϹ���(���ͱȽ�)��ָʾ���ض��ϸ�������׼���������
//4. multiset����ͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_multiset������������ʹ�õ���������ʱ��õ�һ���������С�
//5. multiset�ײ�ṹΪ����������(�����)��
//ע�⣺
//1. multiset���ٵײ��д洢����<value, value>�ļ�ֵ��
//2. mtltiset�Ĳ���ӿ���ֻ��Ҫ���뼴��
//3. ��set�������ǣ�multiset�е�Ԫ�ؿ����ظ���set����value��Ψһ��
//4. ʹ�õ�������multiset�е�Ԫ�ؽ��б��������Եõ����������
//5. multiset�е�Ԫ�ز����޸�
//6. ��multiset����ĳ��Ԫ�أ�ʱ�临�Ӷ�Ϊ
//7. multiset�����ã����Զ�Ԫ�ؽ�������


//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//
//void test() {
//	//multiset====�������ڴ���ظ�������
//	//��������: ��С������б���
//	multiset<int> s;
//	s.insert(1);
//	s.insert(15);
//	s.insert(1);
//	s.insert(3);
//	s.insert(1);
//	s.insert(10);
//	
//
//	for (const auto& e: s) {
//		cout << e << " ";
//	}
//	cout << endl;
//	//pair<multiset<int>::iterator, multiset<int>::iterator> it = s.equal_range(1);//�ҵ�����ֵ��ͬ(��ʼ������)������
//	// pair<multiset<int>::iterator, multiset<int>::iterator>//��һ��Ϊλ�ô�����ʼλ�õ�����   �ڶ���λ�ô������λ�õ�����
//	    
//	auto it = s.equal_range(1);
//	//multiset<int>::iterator start = it.first;//������ʼλ�õĵ�����
//	auto start = it.first;
//	while (start != it.second) {
//		cout << *start << " ";
//		++start;
//	}
//	cout << endl;
//	//find:���ص�һ��Ԫ�ص�λ��
//	start = s.find(1);
//	cout << *start << endl;
//	//count: �ҵ�Ԫ�س��ֵĴ���
//
//	cout << s.count(1) << endl;  // s.count(1)��ʾ�ҵ�keyԪ�س��ֵĸ���
//}
//
//int main() {
//	test();
//	system("pause");
//	return 0;
//}

//3.4 multimap
//3.4.1 multimap�Ľ���
//multimap�ĵ�����
//���룺
//1. Multimaps�ǹ���ʽ�������������ض���˳�򣬴洢��key��valueӳ��ɵļ�ֵ��<key, value>�����ж����ֵ��֮���key�ǿ����ظ��ģ����ǲ�֧��[]����
//2. ��multimap�У�ͨ������key�����Ωһ�ر�ʶԪ�أ���ӳ���value�洢��key���������ݡ�key��value�����Ϳ��ܲ�ͬ��ͨ��multimap�ڲ��ĳ�Ա����value_type�����һ��value_type�����key
//��value�ļ�ֵ�� :
//typedef pair<const Key, T> value_type;
//3. ���ڲ���multimap�е�Ԫ������ͨ�����ڲ��Ƚ϶��󣬰���ָ�����ض��ϸ��������׼��key��������ġ�
//4. multimapͨ��key���ʵ���Ԫ�ص��ٶ�ͨ����unordered_multimap������������ʹ�õ�����ֱ�ӱ���
//multimap�е�Ԫ�ؿ��Եõ�����key��������С�
//5. multimap�ڵײ��ö���������(�����)��ʵ�֡�
//
//ע�⣺multimap��map��Ψһ��ͬ���ǣ�map�е�key��Ψһ�ģ���multimap��key�ǿ����ظ��ġ�
//
//3.4.2 multimap��ʹ��

#include<functional>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void test() {

	//map��keyֵ�ǲ����ظ���,���Ƕ���multimap����key�ǿ����ظ���,���ǲ��ܽ����޸�
	multimap<int, int> mp;
	//map<int, int> mp;

	mp.insert(make_pair(1, 2));
	mp.insert(make_pair(1, 3));
	mp.insert(make_pair(1, 4));
	mp.insert(make_pair(1, 5));
	mp.insert(make_pair(1, 6));
	mp.insert(make_pair(1, 7));

	auto it = mp.begin();
	while (it != mp.end()) {
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

}
int main() {
	test();
	system("pause");
	return 0;
}