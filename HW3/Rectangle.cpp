#include <iostream>
#include "Rectangle.h"
using namespace std;

void PointArray::resize(int size) {
	this->size = size;
}
PointArray::PointArray() {
	size = 2;
	Point pt1(0, 0);
	Point pt2(0, 0);
	*(PointArray::points) = pt1;
	*(PointArray::points + 1) = pt2;
}
PointArray::PointArray(const Point pts[], const int size) {
	Point* points = new Point[size];
	for (int j = 0; j < size; j++) {
		*(points + j) = pts[j];
	}
	PointArray::points = points;
	this->size = size;
}
PointArray::PointArray(const PointArray& pv) {
	size = pv.size;
	Point* points = new Point[pv.size];
	PointArray::points = pv.points;
}
PointArray::~PointArray() { delete[]points; }
void PointArray::clear() {
	for (int u = 0; u < size; u++) {
		*(points + u) = NULL;
	}
}
void PointArray::push_back(const Point& p) {
	
}
void PointArray::insert(const int pos, const Point& p) {
	PointArray::resize(size++);
	for (int r = 0; r < size; r++) {
		*(points + pos + r) = *(points + (pos - 1) + r);
	}
	*(points + (pos - 1)) = p;
	//PointArray::push_back(p);
}
void PointArray::remove(const int pos) {
	for (int w = 0; w < size; w++) {
		*(points+(pos-1)+w)=*(points+pos+w);
	}
	PointArray::resize(size--);
}
Point* PointArray::get(const int pos) {
	return (points + (pos - 1));
}
const Point* PointArray::get(const int pos) const {
	return (points + (pos - 1));
}

/*Polygon::Polygon(const PointArray& pa) {
	Polygon::points = pa;
	numPolygons = 4;
}
Polygon::Polygon(const Point points[], const int numPoints) {
	*(Polygon::points.get(1)) = points[0];
	*(Polygon::points.get(2)) = points[1];
	numPolygons = 4;
}*/

Rectangle::Rectangle(const Point& a, const Point& b) {
	Point P[2] = { a, b };
	PointArray PA(P, 2);
	points = PA;
}
Rectangle::Rectangle(const int a, const int b, const int c, const int d) {
	Point P[2];
	P[0].setX(a);
	P[0].setY(b);
	P[1].setX(c);
	P[1].setY(d);
	PointArray PA(P, 2);
	points = PA;
}
double Rectangle::area() const {
	int sideA, sideB;
	PointArray PA2 = points;
	sideA = PA2.get(1)->getX() - PA2.get(2)->getX();
	sideB = PA2.get(1)->getY() - PA2.get(2)->getY();
	
	if (sideA < 0)
		sideA = -sideA;
	if (sideB < 0)
		sideB = -sideB;
	
	double area = sideA * sideB;

	return area;
}
int main() {
	while (1) {
		int size;
		do {
			cout << "�������� ������ �Է��Ͻÿ�:";
			cin >> size;
		} while (size <= 1);

		int* x = new int[size];
		int* y = new int[size];
		Point* P = new Point[size];

		for (int i = 0; i < size; i++) {
			cout << "��ǥ�� �Է��Ͻÿ�:";
			cin >> *(x + i);
			cin >> *(y + i);
			Point P(*(x + i), *(y + i));
		}

		PointArray PA(P, size);
		PointArray PA1(PA);
		int pos;

		if (size > 2) {
			int ans, ans1;
			cout << "�Էµ� ��ǥ�� " << size - 2 << "�� �����Ǿ�� �մϴ�." << endl;
			cout << "1. �ٽ� �Է��ϱ� | 2. ��ǥ �����ϱ�:" << endl;
			cin >> ans;
			if (ans == 1) {
				PA1.clear();
				continue;
			}
			else {
				while (size != 2) {
					cout << "���� ��ǥ�� ";
					for (int e = 0; e < size; e++) {
						cout << "(" << PA1.get(e + 1)->getX() << "," << PA1.get(e + 1)->getY() << ")" << " ";
					}
					cout << "�Դϴ�." << endl;
					cout << "1. ��ǥ �����ϱ� | 2. ��ǥ �߰��ϱ�:";
					cin >> ans1;

					if (ans1 == 1) {
						for (int h = 0; h < 2 - size; h++) {
							cout << "������ ��ǥ�� ��ġ�� �Է��Ͻÿ�:";
							cin >> pos;
							PA1.remove(pos);
						}
					}
					else {
						cout << "��ǥ�� �߰��� ��ġ�� �Է��Ͻÿ�:" << endl;
						cin >> pos;
						int a, b;
						cout << "��ǥ�� �Է��Ͻÿ�:";
						cin >> a;
						cin >> b;
						Point P1(a, b);
						PA1.insert(pos, P1);
					}
				}
			}
		}
		if (PA1.get(1)->getX() == PA1.get(2)->getX()) {
			cout << "x��ǥ�� ���� �����ϴ�. ���� �Է��� ��ǥ�� ��ġ�� �Է��Ͻÿ�:";
			cin >> pos;
			PA1.remove(pos);
			cout << "��ǥ�� �Է��Ͻÿ�:";
			int a, b;
			cin >> a;
			cin >> b;
			PA1.get(pos)->setX(a);
			PA1.get(pos)->setY(b);
		}
		if (PA1.get(1)->getY() == PA1.get(2)->getY()) {
			cout << "y��ǥ�� ���� �����ϴ�. ���� �Է��� ��ǥ�� ��ġ�� �Է��Ͻÿ�:";
			cin >> pos;
			PA1.remove(pos);
			cout << "��ǥ�� �Է��Ͻÿ�:";
			int a, b;
			cin >> a;
			cin >> b;
			PA1.get(pos)->setX(a);
			PA1.get(pos)->setY(b);
		}
		Rectangle REC(*(PA1.get(1)), *(PA1.get(2)));

		cout << "��ǥ�� ����� ������ " << REC.area() << "�Դϴ�." << endl;
		char ans3;
		cout << "���簢�� ���� ���ϱ⸦ �����Ͻðڽ��ϱ�?(Y/N):";
		cin >> ans3;
		if (ans3 == 'Y') {
			break;
			delete[]x;
			delete[]y;
			delete[]P;
		}
		else {
			continue;
			delete[]x;
			delete[]y;
			delete[]P;
		}
	}
	return 0;
}