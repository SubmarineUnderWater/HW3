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
			cout << "꼭짓점의 개수를 입력하시오:";
			cin >> size;
		} while (size <= 1);

		int* x = new int[size];
		int* y = new int[size];
		Point* P = new Point[size];

		for (int i = 0; i < size; i++) {
			cout << "좌표를 입력하시오:";
			cin >> *(x + i);
			cin >> *(y + i);
			Point P(*(x + i), *(y + i));
		}

		PointArray PA(P, size);
		PointArray PA1(PA);
		int pos;

		if (size > 2) {
			int ans, ans1;
			cout << "입력된 좌표가 " << size - 2 << "개 삭제되어야 합니다." << endl;
			cout << "1. 다시 입력하기 | 2. 좌표 수정하기:" << endl;
			cin >> ans;
			if (ans == 1) {
				PA1.clear();
				continue;
			}
			else {
				while (size != 2) {
					cout << "현재 좌표는 ";
					for (int e = 0; e < size; e++) {
						cout << "(" << PA1.get(e + 1)->getX() << "," << PA1.get(e + 1)->getY() << ")" << " ";
					}
					cout << "입니다." << endl;
					cout << "1. 좌표 삭제하기 | 2. 좌표 추가하기:";
					cin >> ans1;

					if (ans1 == 1) {
						for (int h = 0; h < 2 - size; h++) {
							cout << "삭제할 좌표의 위치를 입력하시오:";
							cin >> pos;
							PA1.remove(pos);
						}
					}
					else {
						cout << "좌표를 추가할 위치를 입력하시오:" << endl;
						cin >> pos;
						int a, b;
						cout << "좌표를 입력하시오:";
						cin >> a;
						cin >> b;
						Point P1(a, b);
						PA1.insert(pos, P1);
					}
				}
			}
		}
		if (PA1.get(1)->getX() == PA1.get(2)->getX()) {
			cout << "x좌표의 값이 같습니다. 새로 입력할 좌표의 위치를 입력하시오:";
			cin >> pos;
			PA1.remove(pos);
			cout << "좌표를 입력하시오:";
			int a, b;
			cin >> a;
			cin >> b;
			PA1.get(pos)->setX(a);
			PA1.get(pos)->setY(b);
		}
		if (PA1.get(1)->getY() == PA1.get(2)->getY()) {
			cout << "y좌표의 값이 같습니다. 새로 입력할 좌표의 위치를 입력하시오:";
			cin >> pos;
			PA1.remove(pos);
			cout << "좌표를 입력하시오:";
			int a, b;
			cin >> a;
			cin >> b;
			PA1.get(pos)->setX(a);
			PA1.get(pos)->setY(b);
		}
		Rectangle REC(*(PA1.get(1)), *(PA1.get(2)));

		cout << "좌표가 만드는 면적은 " << REC.area() << "입니다." << endl;
		char ans3;
		cout << "직사각형 면적 구하기를 종료하시겠습니까?(Y/N):";
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