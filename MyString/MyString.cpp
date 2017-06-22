#include <iostream>
#include <utility>
#include <string.h>

class MyString {
private:
	char* _data;

public:
	MyString() : _data(new char[1]) {
		*_data = '\0';
	}

	explicit MyString(const char* str) : _data(new char[strlen(str) + 1]) {
		strcpy(_data, str);
	}

	MyString(const MyString& rhs) : _data(new char[rhs.size() + 1]) {
		strcpy(_data, rhs.c_str());
	}
	// ���߿���ʹ��C++11��ί�������캯��
	// MyString(const MyString& rhs) : MyString(rhs._data) { }

	MyString(MyString&& rhs) : _data(rhs._data) {
		rhs._data = nullptr;
	}

	~MyString() {
		delete[] _data;
	}

	MyString& operator= (MyString rhs) { // pass by value
		swap(rhs);
		return *this;
	}

	MyString& operator+= (MyString rhs) {
		int size = this->size() + rhs.size() + 1;
		char *tmp = new char[size];
		strcpy(tmp, this->_data);
		strcat(tmp, rhs._data);
		delete[] this->_data;
		this->_data = tmp;
		return *this;
	}

	char& operator[] (size_t n) {
		return _data[n];
	}

	size_t size() const {
		return strlen(_data);
	}

	const char* c_str() const {
		return _data;
	}

	void swap(MyString& rhs) {
		using std::swap;//��std::swap�ڴ˺����ڿ���(��Ҫ������class template�У��˴����޶������)
		swap(_data, rhs._data);//��ʵ������д���������Ļ����� �����κ����� �ҽ����˿ɶ��ԣ������п�����Ұ�����塣
	}
	friend std::istream& operator>>(std::istream& IS, MyString &S);
};

inline bool operator== (const MyString& lhs, const MyString& rhs) {
	return !strcmp(lhs.c_str(), rhs.c_str());
}

inline bool operator== (const MyString& lhs, const char* rhs) {
	return !strcmp(lhs.c_str(), rhs);
}

inline bool operator== (const char* lhs, const MyString& rhs) {
	return !strcmp(lhs, rhs.c_str());
}

inline MyString operator+ (MyString lhs, MyString const &rhs) {
	int size = lhs.size() + rhs.size() + 1;
	char * tmp = new char[size];
	strcpy(tmp, lhs.c_str());
	strcat(tmp, rhs.c_str());

	MyString res(tmp);
	delete[] tmp;

	return res;
}

inline MyString operator+ (const char* lhs, MyString const &rhs) {
	int size = strlen(lhs) + rhs.size() + 1;
	char* tmp = new char[size];
	strcpy(tmp, lhs);
	strcat(tmp, rhs.c_str());

	MyString res(tmp);
	delete[] tmp;

	return res;
}


inline std::ostream& operator<<(std::ostream& OS,const MyString &S){
	OS << S.c_str();
	return OS;
}

inline std::istream& operator>>(std::istream& IS, MyString &S){
	char *input = new char[100];
	IS.getline(input, 100);
	size_t i = strlen(input);
	/*while (input[i] != '\0') i++;*/
	delete[] S._data;
	S._data = new char[i + 1];
	strcpy(S._data, input);
	delete[] input;
	return IS;
}

namespace std {//����std::swap���ػ��汾
	template<>
	void swap<MyString>(MyString& lhs,MyString& rhs)
	{
		lhs.swap(rhs);//����MyString�ڵ�swap��Ա����
	}
}