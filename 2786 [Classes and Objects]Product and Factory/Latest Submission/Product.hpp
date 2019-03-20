#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include<iostream>

using namespace std;
 
class Product{
	public:
		virtual void compileCppProgram(){}
		virtual void sendShortMessage(){}
		virtual ~Product(){}
};

class Laptop:public Product
{
	public:
		Laptop(string name_):nameOfCompany(name_)
		{}
		void compileCppProgram(){
			cout<<nameOfCompany<<' '<<"Laptop compiles a cpp program."<<endl;
		}
	private:
		string nameOfCompany;	
};

class MobilePhone:public Product{
	public:
		MobilePhone(string name_):nameOfCompany(name_)
		{}
		void sendShortMessage(){
			cout<<nameOfCompany<<' '<<"MobilePhone sends a short message."<<endl;
		}
	private:
		string nameOfCompany;		
};
#endif