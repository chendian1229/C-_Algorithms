#include <iostream>

using namespace std;

template <typename T>
struct Point
{
	T x, y;
	Point (T x = 0, T y = 0 ){this -> x = x;this -> y = y;}
};

// template <typename T>
// Point::Point (T x = 0, T y = 0)


template <typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B)
{
	return Point<T>(A.x + B.x, A.y + B.y);
}

template <typename T>
ostream& operator << (ostream &out, const Point<T>& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}


int main()
{
	// Point a, b(1,2);
	// a.x = 3;
	// cout << a + b << endl;

	Point<int> a(1,2), b(3,4);
	Point<double> c(1.1,2.2), d(3.3,4.4);
	cout << a + b <<endl<< c + d << endl;

	return 0;
}