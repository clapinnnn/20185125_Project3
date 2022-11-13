#include <iostream>

using namespace std;


class String {
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
};


int main() {

}