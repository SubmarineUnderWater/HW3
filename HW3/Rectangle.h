#pragma once

class Point {
	int x, y;

public:
	Point(int xx = 0, int yy = 0) { x = xx; y = yy; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(const int xx) { x = xx; }
	void setY(const int yy) { y = yy; }

};

class PointArray {
	int size;
	Point* points;
	void resize(int size);
public:
	PointArray();
	PointArray(const Point pts[], const int size);
	PointArray(const PointArray& pv);
	~PointArray();
	void clear();
	int getSize() const { return size; }
	void push_back(const Point& p);
	void insert(const int pos, const Point& p);
	void remove(const int pos);
	Point* get(const int pos);
	const Point* get(const int pos) const;
};
/*class Polygon {
protected:
	static int numPolygons;
	PointArray points;
public:
	Polygon(const PointArray& pa);
	Polygon(const Point points[], const int numPoints);
	virtual double area() const = 0;
	static int getNumPolygons() { return numPolygons; }
	int getNumSides() const { return points.getSize(); }
	const PointArray* getPoints() const { return &points; }
	~Polygon() { --numPolygons; }
};*/

class Rectangle {
protected:
	PointArray points;
public:
	Rectangle(const Point& a, const Point& b);
	Rectangle(const int a, const int b, const int c, const int d);
	virtual double area() const;
};

