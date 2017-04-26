#include <iostream>
//#include <iomanip>
//using namespace std;

class Polygon {
	protected:
		float width, height;
	public:
		Polygon ( float w, float h ) : width(w), height(h) {};
		virtual float area () =0;
};

class Rectangle: public Polygon {
	public:
		Rectangle ( float w, float h ) : Polygon ( w, h ) {};
		float area () {
			return ( width * height );
		}
};

class Triangle: public Polygon {
	public:
		Triangle ( float w, float h ) : Polygon ( w, h ) {};
		float area () {
			return ( width * height / 2 );
		}

};

int main ()
{
	//Rectangle r(4,4);
	Polygon* rect = new Rectangle( 2, 4 );
	Polygon* tri = new Triangle( 1, 1 );
	//Polygon* poly1 = rect;
	//Polygon* poly2 = tri;

	std::cout << rect->area() << '\n';
	std::cout << tri->area() << '\n';
	//std::cout << std::fixed << std::setprecision(3) << tri->area() << '\n';

	return 0;
}

