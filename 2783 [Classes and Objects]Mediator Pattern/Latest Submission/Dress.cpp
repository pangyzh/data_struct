 #include"Dress.hpp"
#include<iostream>

Dress::Dress(const Dress& other)
{
	name=other.name;
	price=other.price;
}

Dress::Dress(const string & name_, const int price_)
:name(name_),price(price_)
{}

int Dress::getPrice() const{return price;}
string Dress::getName() const{return name;}