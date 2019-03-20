 #include <string>
#include <cstdio>
#include<iostream>
#include"date.hpp"
using namespace std;
  void Date::setDate(int year, int month, int day){
  	year_=year;
  	month_=month;
  	day_=day;
  }
  int Date::year() const{return year_;}
  int Date::month() const{return month_;}
  int Date::day() const{return day_;}

  void Date::increase(){
  	if(daysOfMonth(year_,month_)==31){
  		if(day_==31){
  			if(month_==12){
  				year_++;
  				month_=1;
      	day_=1;
  				return ;
			  }
			month_++;
			day_=1;
			return;
		  }
			day_++;
			return ;
	  }
	  if(daysOfMonth(year_,month_)==30&&day_==30){
	  		month_++;
	  		day_=1;
	  		return ;
	  }
	  if(daysOfMonth(year_,month_)==29&&day_==29){
	  		month_++;
	  		day_=1;
	  		return ;
	  }
	  if(daysOfMonth(year_,month_)==28&&day_==28){
	  		month_++;
	  		day_=1;
	  		return ;
	  }
    day_++;
    return ;
  }
  void Date::decrease(){
  	if(month_==1&&day_==1){
  		year_--;
  		month_=12;
  		day_=31;
  		return; 
	  }
	  if(month_!=1&&day_==1){
  	if(daysOfMonth(year_,month_-1)==31)
  		{
			month_--;
  			day_=31;
		  	return ;
		  }
	  if(daysOfMonth(year_,month_-1)==30){
	  		month_--;
	  		day_=30;
	  		return ;
			}
	  if(daysOfMonth(year_,month_-1)==29){
	  		month_--;
	  		day_=29;
	  		return ;
	  		}
	  if(daysOfMonth(year_,month_-1)==28){
	  		month_--;
	  		day_=28;
	  		return ;
		  }
	  }
	  day_--;
	  return;
  }
  int Date::daysOfMonth(int year, int month) const{
  	if((year%400==0||year%4==0&&year%100!=0)&&month==2)return 29;
  	if(month==4||month==6||month==9||month==11)
  			return 30;
  	if(month==2)return 28;
    return 31;

  }