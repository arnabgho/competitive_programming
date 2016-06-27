#include<list.h>
#include<stdio.h>

main(){

	list<int>  list1;
	list<int>::iterator list_iter;
	int i;
	ostream_iterator<int> out_stream(cout, " ");
	
	for(i=0;i<10;i++){
		list1.push_back(i);
	}
	
	copy(list1.begin(),list1.end(),out_stream);

	cout<<'\n';
	
	list_iter=list1.begin();
	while(list_iter!= list1.end()){
		cout<<*list_iter++<<' ';
	}
	cout<<"\n";
	return 0;
}

