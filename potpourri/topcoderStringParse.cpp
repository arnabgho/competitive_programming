void split(string s,vector<string>&v){
	int i=0;
	int n=s.size();
	for(;i<n;i++){
		if(s[i]==' ')
			break;
	}
	string f="",se="",t="";
	f=s.substr(0,i);
	int j=i+1;
	for(;j<n;j++){
		if(s[j]==' ')
			break;
	}
	se=s.substr(i+1,j-i-1);
	t=s.substr(j+1);
	//cout<<"f -"<<f<<"-"<<endl;
	//cout<<"se -"<<se<<"-"<<endl;
	//cout<<"t -"<<t<<"-"<<endl;
	v.push_back(f);
	v.push_back(se);
	v.push_back(t);
}
