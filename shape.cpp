#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum Color {R,O,Y,G,B,I,V};
class Shape {
    private:
    int x, y;
    Color X;
    static int Cnt;
    int Id;
public:
    Shape();
    Shape(int x, int y, Color inp);
    ~Shape();
    Shape(const Shape &rhs);
    Shape &operator =(const Shape &rhs);
    float distance();
    void print();
    static int getTotalCount() { return Cnt; }
};

int Shape::Cnt = 0;

Shape::Shape(): x(0), y(0), Id(Cnt), X(R) {
    Cnt++;
}
Shape::Shape(int x, int y, Color inp): x(x), y(y), Id(Cnt), X(inp) {
    Cnt++;
}
Shape::~Shape() {
    
}
Shape::Shape(const Shape &rhs) {
    x = rhs.x;
    y = rhs.y;
    X = rhs.X;
    Id = Cnt;
    Cnt++;
}
Shape &Shape::operator =(const Shape &rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->X = rhs.X;
    return *this;
}
float Shape::distance() {
    return sqrt((x * x) + (y * y) + (1.0));
}
void Shape::print() {
    cout << "ID: " << Id << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << "Color: " << X << endl;
}

class Circle: public Shape {
    int Radius;
public:
    Circle();
    Circle(int x, int y, Color X, int R);
    Circle(const Circle &rhs);
    Circle &operator =(const Circle &rhs);
    float calcArea();
    int getRadius() const { return Radius; }
    void print();
};

Circle::Circle(): Radius(0), Shape() {
    cout << "Default constructor" << endl;
}
Circle::Circle(int x, int y, Color X, int R): Shape(x, y, X), Radius(R) {
    cout << "Parameterized constructor" << endl;
}
Circle::Circle(const Circle &rhs): Shape(rhs) {
    cout << "Copy constructor" << endl;
    Radius = rhs.Radius;
}
Circle &Circle::operator = (const Circle &rhs) {
    this->Radius = rhs.Radius;
    Circle::operator=(rhs);
    return *this;
}
float Circle::calcArea() {
    return 3.14159 * pow(Radius, 2);
}
void Circle::print() {
    cout << "--------------------------" << endl;
    cout << "Radius is: " << Radius << endl;
    Shape::print();
    cout << "--------------------------" << endl;
}

class Rectangle: public Shape {
    int Len, width;
public:
    Rectangle();
    Rectangle(int x, int y, Color X, int l, int w);
    Rectangle(const Rectangle &rhs);
    Rectangle &operator =(const Rectangle &rhs);
    float calcArea();
    int getLength() const { return Len; }
    int getWidth() const { return width; }
    void print();
};

Rectangle::Rectangle(): Len(0), width(0), Shape() {

}
Rectangle::Rectangle(int x, int y, Color X, int l, int w): Len(l), width(w), Shape(x, y, X) {

}
Rectangle::Rectangle(const Rectangle &rhs): Shape(rhs) {
    Len = rhs.getLength();
    width = rhs.getWidth();
}
Rectangle &Rectangle::operator =(const Rectangle &rhs){
    this->Len = rhs.getLength();
    this->width = rhs.getWidth();
    Rectangle::operator=(rhs);
    return *this;
}
float Rectangle::calcArea(){
    return Len * width;
}
void Rectangle::print(){
    cout << "--------------------------" << endl;
    cout << "Length is: " << Len << endl;
    cout << "Width is: " << width << endl;
    Shape::print();
    cout << "--------------------------" << endl;
}
int main() {

    string Name {"Jubyaid Uddin"};
    cout <<"----------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout <<"----------------------------------------------------\n";
    Shape X, Amoeba(3, 4, Y);
    Circle C1(3, 4, B, 5);
    Circle C2(15, 20, Y, 10);
    Rectangle R(12, 5, V, 8, 4);


    cout << "Area of Circle 1 is: " << C1.calcArea() << endl;
    cout << "Area of Circle 2 is: " << C2.calcArea() << endl;
    C1.print();
    
    C2.print();

    cout << "Distance between circles is: " << (C1.distance() * C2.distance()) - C1.getRadius() - C2.getRadius() << endl;
    cout << "Distance of C1 from origin is: " << C1.distance() << endl;
    cout << "Distance of C2 from origin is: " << C2.distance() << endl;
    cout << "Distance of R from origin is: " << R.distance() << endl;

    cout << "Total count is: " <<R.getTotalCount() << endl;
    return 0;
}
