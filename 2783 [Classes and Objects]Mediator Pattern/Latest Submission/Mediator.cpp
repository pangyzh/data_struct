 #include"Mediator.hpp"

Mediator* Mediator::Ins = NULL;

void Mediator::RegisterHandler(User * use) { 
	users.push_back(use); 
}

void Mediator::ChatHandler(const int & to, const string &msg)
{
	for(list<User*>::iterator it = users.begin(); it != users.end(); it++){
		if((*it)->getId()==to){
			   	(*it)->GetMessage(msg);
                return ;
		}
	}
	 cout << "Are you kidding ? There is no such a guy!" << endl;
}

pair<int,string> Mediator::TradeHandler(const int & to,const int & pay,const string & dressName)
{
	for(list<User*>::iterator it = users.begin(); it != users.end(); it++)
	{
        if ((*it)->getId()==to)
        return (*it)->SellBeautifulDress(pay, dressName);
    }
		cout << "There is no Such a guy!" << endl;
    	return pair<int,string>(0,"No this guy");		
	
}

void Mediator::DressInfoHandler(const int & to)
{
    for (list<User*>::iterator it = users.begin();it!=users.end();it++)
        if ((*it)->getId()==to)
            (*it)->ShowMyCuteDresses();	
}