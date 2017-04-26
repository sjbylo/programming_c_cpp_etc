#include <iostream>
using namespace std;

class Polygon
{
	protected:
		int width, height;
	public:
		Polygon ( int w, int h ) : width(w), height(h) {}
		virtual int area() =0;
};

class Rectangle: public Polygon
{
	public:
		Rectangle ( int w, int h): Polygon (w, h) {}
		int area() {
			return width * height;
		}
};

class Triangle: public Polygon
{
	public:
		Triangle ( int w, int h): Polygon (w, h) {}
		int area() {
			return width * height / 2;
		}
};

int main()
{
	Polygon* r = new Rectangle( 3, 6);
	Polygon* t = new Triangle( 3, 2);
	cout << "Area of r is " << r->area() << '\n';
	cout << "Area of t is " << t->area() << '\n';

	return(0);
}

