#include<iostream>
#include"Product.hpp"
using namespace std;

class Factory{
	public:
		virtual Laptop* produceLaptop(){}
		virtual MobilePhone* produceMobilePhone(){}
		virtual ~Factory(){}
};

class XiaomiFactory:public Factory
{
	public:
		~XiaomiFactory(){}
		Laptop* produceLaptop(){
			Laptop* xmlaptop=new Laptop("Xiaomi");
			return xmlaptop;
		}
		MobilePhone* produceMobilePhone(){
			MobilePhone* xmphone=new MobilePhone("Xiaomi");
			return xmphone;
		}
};

class AppleFactory:public Factory
{
	public:
		Laptop* produceLaptop(){
			Laptop* alaptop=new Laptop("Apple");
			return alaptop;
		}
		MobilePhone* produceMobilePhone(){
			MobilePhone* aphone=new MobilePhone("Apple");
			return aphone;
		}	
};
