#include<iostream>
using namespace std;
class Vector{
	public:
		Vector(){
			x=0;
			y=0;
		}
		Vector(int a,int b){
			x=a;
			y=b;
		}
		friend ostream& operator<<(ostream &os,Vector& out)
		{
			os<<out.x<<" "<<out.y;
			return os;
		}
		Vector operator+(Vector & other)
		{
			int xx=x+other.x;
			int yy=y+other.y;
			return Vector(xx,yy);
		} 
		
		Vector& operator=(Vector other)
		{
			x=other.x;
			y=other.y;
			return *this;
		}
		int getx(){
			return x;
		}
		int gety(){return y;}
	private:
		int x,y;
}; 

class Point{
	public:
		Point()
		{
			y_=0;
			x_=0;
		}
	Point(int a,int b){
		x_=a;
		y_=b;
	}
	Point& operator+(Point& other)
	{
		x_+=other.x_;
		y_+=other.y_;
		return *this;
	}
	Point& operator=(Point& other)
	{
		x_=other.x_;
		y_=other.y_;
		return *this;
		
	}
	
	Point& operator+(Vector & other)
	{
		x_+=other.getx();
		y_+=other.gety();
		return *this;
	}
	
	friend ostream& operator<<(ostream &os,Point& out)
	{
		os<<out.x_<<" "<<out.y_;
		return os;
	}
	private:
		int x_;
		int y_;
};