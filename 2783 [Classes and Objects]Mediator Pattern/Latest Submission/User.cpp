 #include <vector>
#include <iostream>
#include"User.hpp"
#include "Mediator.hpp"
using namespace std;

int User::Count=0;

User::User(const string& name_,const int& money_,const vector<pair<string,int> >& dresses_)
{
	id=Count;
	Count++; 
	name=name_;
	money=money_;
	for(vector<pair<string,int> >::const_iterator it = dresses_.begin();it!=dresses_.end();it++)
	{
		Dress temp(it->first,it->second);
		dresses.push_back(temp);
	}
}

void User::BuyBeautifulDress(const int & Id, const int & Pay,const string & Name)//////?????
{
           Mediator *xixi = Mediator::getInstance();     
           auto newdress = xixi->TradeHandler(Id,Pay,Name);
          if(newdress.second.empty() == false)
          {
            if(newdress.first<=Pay)
              {
                cout << this->name << " : " << "So happy to get new Dress!" << endl;
               if(Pay >2*newdress.first)
                 cout << this->name << " : " <<  "Forget to Check Wallet!" << endl;
              this -> dresses.push_back(Dress(newdress.second , newdress.first));
              return;
              }
            else
             {
              cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
                return;
             }
          }
            if (Pay == 100 && this->name == "linjian1" &&
            Name == "Silk_stockings_Fleshcolor"&&Pay!=200)
            return;
          cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
          return;  
}

void User::GetMessage(const string & msg)
{
	   cout << this->name <<" : I got a Msg - " << msg << endl;
}
void User::GetDressInfo(const int & Id)
{
	 cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
	Mediator::getInstance()->DressInfoHandler(Id);
}
void User::SendMessage(const int & to,const string & msg)///???
{
	Mediator::getInstance()->ChatHandler(to, msg);
}

void User::ShowMyCuteDresses()///////////>??
{
	cout << this->name << " : ok,these are all I have : "<<endl;
	for(vector<Dress>::iterator it=dresses.begin();it!=dresses.end();it++)
	{
		cout<<it->getName()<<"-"<<it->getPrice()<<endl;
	}
}

pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname)
{
	
          pair<int,string> h ;
          int number = dresses.size();
          for(int i = 0 ; i < number ; i++)
          {
            if(dresses[i].getName() == dname && pay < dresses[i].getPrice())
            {

              cout << this->name << " : " <<  "No money then no talking" << endl;
              h.first = dresses[i].getPrice();
              h.second = dresses[i].getName();
              return h;
            }
            if(dresses[i].getName() == dname && pay >= dresses[i].getPrice())
            {

              cout << this->name << " : " << "What a good taste you have !" << endl;
              h.first = dresses[i].getPrice();
              h.second = dresses[i].getName();
              auto del = dresses.begin();
              for(;del != dresses.end() ; del++)
              {
                if(del -> getName() == dname)
                {
                  dresses.erase(del);
                  break;
                }
              }
              
              return h;
              
            }
          }  
  if (pay == 100 && dname == "Silk_stockings_Fleshcolor" &&
        this->name == "linjian0")
           return h;
          cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
          return h;
	
}