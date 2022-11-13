#include <iostream>

using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z }{}
	
	//���׿����� + �� ���� ��������� �����ε�
	Vector operator+(const Vector& v) const {
		return Vector{ x + v.x, y + v.y, z + v.z };
	}

	//���׿����� -
	Vector operator-(const Vector& v) const {
		return Vector{ x - v.x, y - v.y, z - v.z };
	}

	//���׿����� +
	Vector operator+() const {
		return Vector{ +x, +y, +z };
	}

	//���׿����� -
	Vector operator-() const {
		return Vector{ -x, -y, -z };
	}

	float operator*(const Vector& v) const {
		float dot = x * v.x + y * v.y + z * v.z;
		return dot;
	}

	Vector operator*(float n) const {
		return Vector{ x * n, y * n, z * n };
	}

	Vector operator/(float n) const {
		return Vector{ x / n, y / n, z / n };
	}

	Vector& operator++() {	//const ���� �� ����
		++x;
		++y;
		++z;
		return *this;
	}

	Vector& operator++(int) {	//���� ����������
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}

	Vector& operator--() {	//const ���� �� ����
		--x;
		--y;
		--z;
		return *this;
	}

	Vector& operator--(int) {	//���� ����������
		Vector temp = *this;
		--x;
		--y;
		--z;
		return temp;
	}

	void print() {
		cout << x << " " << y << " " << z << endl;
	}
	
};


int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1;	//���׿����� +
	//Vector v2 = v0.operator+(v1);
	v2.print();

	Vector v21 = v0 - v1;	//���׿����� -
	v21.print();

	Vector v3 = -v1;		//���׿����� -, v1.operator-();
	v3.print();

	Vector v31 = +v1;		//���׿����� +
	v31.print();

	//���׿����� *
	//���Ϳ���, ������� -> (v0.x * v1.x) + (v0.y * v1.y) = float�� 
	//���� * �Ǽ��� -> ����

	float v4 = v0 * v1;	//v0.operator*(v1);
	cout << v4 << endl;	//0 + 2 + 6 = 8

	Vector v5 = v1 * 3.0f;	//v1.operator*(3.0f);
	v5.print();

	Vector v51 = v1 / 3.0f;	//v1.operator/(3.0f);
	v51.print();

	// ++v1
	// v1++
	Vector v6 = ++v1;	//v1.operator++();
	v6.print();

	Vector v7 = v1++;	
	v7.print();

	// --v1
	// v1--
	Vector v61 = --v1;	//v1.operator--();
	v61.print();

	Vector v71 = v1--;
	v71.print();


}