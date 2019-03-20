 
 int sumOfIntersection(const set<int>& s1, const set<int>& s2){
  int count=0;
  set<int>::iterator iter1;
      set<int>::iterator iter2;
		for(int i = 0; i < 10000; i++){
    if((iter1=s1.find(i))!=s1.end()&&(iter2=s2.find(i))!=s2.end())
        count+=i;
   }
   return count;
 }
/*Set Set::operator&(const Set &s){//
  Set c;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < s.size; j++){
			if(members[i] == s.members[j]){
			
			c.append(members[i]);
			break;
			}
		}


	return c;
}	}*/