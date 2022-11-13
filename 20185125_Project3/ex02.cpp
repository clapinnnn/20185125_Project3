#include <iostream>
//#include <string>	//c++ 문자열 클래스
#include <cstring>	//strcpy, strcmp

using namespace std;

class String {
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& str) const {
		return strcmp(_chars, str._chars) == 0;
	}

	bool operator!=(const String& str) const {
		//!=의 반대 ==
		return !(*this == str);
	}

	bool operator>(const String& str) const {
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str) const {
		//<=의 반대 >
		return !(*this > str);
	}

	bool operator<(const String& str) const {
		return strcmp(_chars, str._chars) < 0;
	}

	bool operator>=(const String& str) const {
		//>=의 반대 <
		return !(*this < str);
	}
};


int main() {
	String str0{ "abc" };
	String str1{ "ced" };

	if (str0 == str1)//str0.operator==(str1)
		cout << "equal" << endl;

	if (str0 != str1)//str0.operator!=(str1)
		cout << "not equal" << endl;

	if (str0 > str1)	//str0.operator>(str1)
		cout << "str0 > str1" << endl;

	if (str0 <= str1)	//str0.operator<=(str1)
		cout << "str0 <= str1" << endl;

	if (str0 < str1)	//str0.operator<(str1)
		cout << "str0 < str1" << endl;

	if (str0 >= str1)	//str0.operator>=(str1)
		cout << "str0 >= str1" << endl;
}