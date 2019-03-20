 #include <iostream>
#include <cstring>
#include"Vector.h"
using namespace std;

Vector::Vector(string name_,int dimen, int para[])
:name(name_),dimension(dimen)
{
	param=new int[dimen];
	for(int i = 0; i < dimen; i++)
	param[i]=para[i];
	cout<<"construct a vector called "<<name<<'.'<<endl;
}
Vector::Vector(const Vector &other)
{
	name=other.name;
	dimension=other.dimension;
	param=new int[dimension];
	for(int i = 0; i < dimension; i++)
	{
		param[i]=other.param[i];
	} 
	cout<<"copy a vector called "<<name<<'.'<<endl;
}

Vector::~Vector()
{
	delete [] param;
	cout<<"release memory from a vector called "<<name<<'.'<<endl;
}

void Vector::isEqual(const Vector & otherVec)
{
	    if (name==otherVec.name)
        std::cout<<"same name, ";
    else
        std::cout<<"different name, ";
    if (dimension==otherVec.dimension)
        {
            bool falg = true;
            for (int n = 0;n<dimension;n++)
                if (param[n]!=otherVec.param[n])
                    {
                        falg = false;
                        break;
                    }
            if (falg)
                std::cout<<"same value."<<std::endl;
            else
                std::cout<<"different value."<<std::endl;
        }
    else
        std::cout<<"different value."<<std::endl;
}
void Vector::setName(string name_){
	name=name_;
}
void Vector::print(){
	cout<<name<<'(';
	for(int i=0;i<dimension-1;i++)
		cout<<param[i]<<", ";
	
		cout<<param[dimension-1]<<')'<<endl;

}