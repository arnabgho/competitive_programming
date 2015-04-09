#include<algorithm>
#include<iostream>

using namespace std;

template <class ForwardIterator>
void Add10(ForwardIterator first,ForwardIterator last){
	while(first != last){
		*first = *first +10;
		first++;
	}
}

main(){
	int i,data[10];
	ostream_iterator<int> outStream(cout, " " );
	
	for(i=0;i<10;i++)
		data[i]=i;
	Add10(data,data+10);
	copy(data,data+10,outStream);
	cout<<"\n";
	return 0;
}
