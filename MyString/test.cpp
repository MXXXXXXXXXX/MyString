#include <iostream>
#include <vector>
#include "MyString.cpp"

void func1(MyString x) {//���Թ��캯���Ƿ����������躯���壩

}

void func2(const MyString& x) {

}

MyString func3() {
	MyString ret("world");
	return ret;
}

int main() {
	MyString s0;
	MyString s1("Hello,World");
	MyString s2(s0);
	MyString s3 = s0;
	MyString s8;
	s8 = s2 = s1;//���Զ��ظ�ֵ��assignment�������

	s8 = s1 + s3;//����+�����

	s1 += s3;//����+=�����

	func1(s1);
	func2(s1);
	func1(MyString("literal"));//ֻ�ܽ�����ʾת�������캯����explicit��
	func2(MyString("litera2"));
	MyString s4 = func3();

	std::vector<MyString> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(func3());
	svec.push_back(MyString("test finished."));

	MyString *s5 = &s1;
	MyString s6 = *s5;

	std::cout << s6 << std::endl;//����<<�����

	char tes = s6[4];//����[]�����

	std::cin >> s0;//����>>�����
	std::cout << s0.size();//����size����

	return 0;
}