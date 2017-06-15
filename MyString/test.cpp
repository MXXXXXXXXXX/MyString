#include <iostream>
#include <vector>
#include "MyString.cpp"

void func1(MyString x) {//测试构造函数是否正常（无需函数体）

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
	s8 = s2 = s1;//测试多重赋值（assignment运算符）

	s8 = s1 + s3;//测试+运算符

	s1 += s3;//测试+=运算符

	func1(s1);
	func2(s1);
	func1(MyString("literal"));//只能进行显示转换（构造函数是explicit）
	func2(MyString("litera2"));
	MyString s4 = func3();

	std::vector<MyString> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(func3());
	svec.push_back(MyString("test finished."));

	MyString *s5 = &s1;
	MyString s6 = *s5;

	std::cout << s6 << std::endl;//测试<<运算符

	char tes = s6[4];//测试[]运算符

	std::cin >> s0;//测试>>运算符
	std::cout << s0.size();//测试size函数

	return 0;
}