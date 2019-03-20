#include<iostream>
using namespace std;
class Vector;

class Point {
  public:
    Point() {}
    explicit Point(int x_, int y_) : x(x_), y(y_) {}////
    Point(const Point &other);//////////
    friend Point operator+(const Point &point, const Vector &other);/////////
    friend ostream& operator<<(ostream &out, Point &point);////////////
  private:
    int x;
    int y;
};


class Vector {
  public:
    Vector() {}
    explicit Vector(int x_, int y_) : x(x_), y(y_) {}////////
    Vector(const Vector &other);/////////
    Vector operator+(const Vector &other);//////////
    friend Point operator+(const Point &point, const Vector &other);/////
    friend ostream& operator<<(ostream &out, Vector &vect);////////////
  private:
    int x;
    int y;
};


Vector::Vector(const Vector &other) {
  x = other.x;
  y = other.y;
}

Point::Point(const Point &other) {
  x = other.x;
  y = other.y;
}

Vector Vector::operator+(const Vector &other) {
  Vector temp;
  temp.x = x + other.x;
  temp.y = y + other.y;
  return temp;
}

Point operator+(const Point &point, const Vector &other) {
  Point temp;
  temp.x = point.x + other.x;
  temp.y = point.y + other.y;
  return temp;
}

ostream& operator<<(ostream &out, Vector &vect) {
  out << vect.x << ' ' << vect.y;
  return out;
}

ostream& operator<<(ostream &out, Point &point) {
  out << point.x << ' ' << point.y;
  return out;
}