#include <bits/stdc++.h>
using namespace std;

// Need to print in sorted order 
// See dealloc again 

struct list_node                            // make a list node with start and length pointer and a pointer to next and prev 
{
	int start;
	int length;
	struct list_node* prev;
	struct list_node* next;
};

struct list_occured{							// contains all the dealloc statement that have occured 
	int value;
	struct list_occured *next;
};
struct list_node * make_node( int s1 , int l1) //  to a make a node of type list_node 
{
     struct list_node *temp;
     temp = (struct list_node *)calloc(1, sizeof(struct list_node));
     temp -> start = s1;
     temp -> length = l1;
     return temp; 
}

struct list_node *search_first(struct list_node *head, int l1)     // search first_occurance in free list  
{
   struct list_node *curr = head;
   while (curr != NULL && curr->length < l1) 
   { 
		curr = curr->next;
   }
   return curr;
} 

struct list_node *search_first_start(struct list_node *head, int l1)     // find the first place in free list  
{
   struct list_node *curr = head;
   while (curr != NULL && curr-> start < l1) 
   { 
		curr = curr->next;
   }
   return curr;
} 


struct list_node *insert_after_node (struct list_node *pcurr, struct list_node *pnew)    // to insert after a particular node 
{
    if (pcurr != NULL) 
    {
    	pnew -> prev=pcurr;
        pnew -> next = pcurr->next;
        pcurr-> next = pnew;
		return pcurr;
    }
    else return pnew;
}   
  
struct list_node *first_fit(struct list_node *Head_free, struct list_node **Head_alloc,int m)  // first fit funnction 
{
	struct list_node * temp;
	struct list_node * new_node;
	struct list_node * new_node1;
	struct list_node * temp1;
	struct list_node * temp2;
	temp=search_first(Head_free,m);        // search whether the space exist or not 
	if(temp==NULL)
		return NULL;
	new_node=make_node(temp -> start,m);
	new_node1=make_node(temp -> start,m);
	temp2=new_node;
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	temp -> start = temp -> start + m;
	temp -> length = temp -> length -m;
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	//printf("2\n");
	temp2=*Head_alloc;
	temp1= NULL;
	//printf("1\n");
	while( temp2 != NULL && temp2 -> start < temp -> start)    
	{
		temp1=temp2;
		temp2=temp2 -> next;
	}	
	//printf("1\n");
	new_node -> prev = temp1;
	if(temp2 != NULL)
	{
		new_node -> next = temp2 ;
		temp2-> prev = new_node;
	}	
	else
	{
		new_node -> next = NULL;
	}
	temp2=new_node;
	if (temp1 != NULL)
		temp1 -> next = temp2 ;
	else
	{
		*Head_alloc = temp2;
	}
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	/*struct list_node * temp3;
	temp3=Head_alloc;
	while(temp3 !=NULL)
	{	
		printf("%d %d \n", temp3 -> start , temp3 -> length);
		temp3 = temp3 -> next;
	}*/
	
	return new_node1;
}

struct list_node *search_best(struct list_node *head, int l1)     // search the best_fit in free list  
{
   struct list_node *curr = head;
   struct list_node *good=NULL;
   int diff;
   diff=123456789;
   while (curr != NULL) 
   { 
   		if(curr -> length >= l1)
   		{
   			if(diff>curr -> length -l1)
   			{
   				diff=curr -> length -l1;
   				good=curr;	
   			}
   		}
		curr = curr->next;
   }
   return good;
} 

struct list_node *best_fit(struct list_node *Head_free, struct list_node **Head_alloc,int m)  // allocate place in best fit 
{
	struct list_node * temp;
	struct list_node * new_node;	
	struct list_node * new_node1;
	struct list_node * temp1;
	struct list_node * temp2;
	temp=search_best(Head_free,m);
	if(temp==NULL)
		return NULL;
	new_node=make_node(temp -> start,m);
	new_node1=make_node(temp -> start,m);
	temp2=new_node;
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	temp -> start = temp -> start + m;
	temp -> length = temp -> length -m;
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	//printf("2\n");
	temp2=*Head_alloc;
	temp1= NULL;
	//printf("1\n");
	while( temp2 != NULL && temp2 -> start < temp -> start)
	{
		temp1=temp2;
		temp2=temp2 -> next;
	}	
	//printf("1\n");
	new_node -> prev = temp1;
	if(temp2 != NULL)
	{
		new_node -> next = temp2 ;
		temp2-> prev = new_node;
	}	
	else
	{
		new_node -> next = NULL;
	}
	temp2=new_node;
	if (temp1 != NULL)
		temp1 -> next = temp2 ;
	else
	{
		*Head_alloc = temp2;
	}
	//printf("%d %d \n", temp2 -> start , temp2 -> length);
	/*struct list_node * temp3;
	temp3=Head_alloc;
	while(temp3 !=NULL)
	{	
		printf("%d %d \n", temp3 -> start , temp3 -> length);
		temp3 = temp3 -> next;
	}*/
	
	return new_node1;

}

struct list_node *search_list(struct list_node *head, int l1)     //returns node to insert at a particular pos l1 in  free list  
{
   struct list_node *curr = head;
   int count=0;
   while (curr != NULL && count!=l1-1) 
   { 
		curr = curr->next;
		count++;
   }
   return curr;
} 

struct list_node *search_list_locate(struct list_node *head, int l1)     //to locate the place to insert in  free list  
{
   struct list_node *curr = head;
   while (curr != NULL && curr -> start != l1) 
   { 
		curr = curr->next;
   }
   return curr;
} 

struct list_node *search_list_start_less(struct list_node *head, int l1)     // search the first start more than l1 in free list  
{
   struct list_node *curr = head;
   while (curr != NULL && curr -> start <= l1) 
   {
		curr = curr->next;
   }
   return curr ;
} 
int main()
{
	char ch;
	string str1,str2;
	int d,n,i,m;
	struct list_node *New_pointer;
	struct list_node *Head_pointer;
	struct list_node *Next_pointer;
	cin >> str1 >> n >> d;
	struct list_node *Head_free;     // head of free list
	struct list_node *Head_alloc;	// head of alloctaed list 
	struct list_node *node_free; 
	struct list_node *node_alloc;
	node_free= make_node(0,n);			// make a node of free list of whole size 
	Head_free=node_free;
	node_alloc=NULL;					//// put the allocated list null
	Next_pointer=NULL;
	Head_alloc=node_alloc;
	Head_pointer=Next_pointer;        // pointer points to a node allocated so that one can dealloc
	Head_free -> prev = NULL;
	Head_free -> next = NULL;
	struct list_node *curr;
	struct list_node * New1;
	struct list_occured * possible;      // check whether a node is already dealocated 
	possible=NULL;
	while(cin >> str2)
	{
		cin >> m;
		if(str2.compare("alloc")==0)     // if we get allocated 
		{
			int flag=0;
			if(d==0)                    // if first fit 
			{
				if(Head_alloc== NULL)    // incase allocated list is null
				{
					New_pointer=make_node(0,m);
					New1= make_node(0,m);
					New_pointer -> next = NULL;
					New_pointer -> prev = NULL;
					if(Head_free -> next == NULL)
					//	printf("1\n");

					if(Head_free -> length < m)     // if the space exist in free list 
					{
						New1=NULL;
					}
					else
					{
						Head_alloc = New_pointer; 
						Head_free -> start = Head_free -> start + m;
						Head_free -> length = Head_free -> length -m;
					}
				}
				else
				{
					New1=first_fit(Head_free,&Head_alloc,m);
				}
			}
			else						// if best fit 
			{
				if(Head_alloc== NULL)    // if allocate list is null
				{
					New_pointer=make_node(0,m);
					New1= make_node(0,m);
					New_pointer -> next = NULL;
					New_pointer -> prev = NULL;
					if(Head_free -> length < m)    // in case possible to allocated 
					{
						New1=NULL;
					}
					else
					{
						Head_alloc = New_pointer; 
						Head_free -> start = Head_free -> start + m;
						Head_free -> length = Head_free -> length -m;
					}
				}
				else
					New1=best_fit(Head_free,&Head_alloc,m);
			}
			struct list_node * New2;
			int x,y;
			if(Head_pointer== NULL && New1 !=NULL )             // if it is NULL pointer points to a node allocated so that one can dealloc
			{
				x=New1 -> start;
				y= New1 -> length;
				New2=make_node(x,y);
				New2 -> prev = NULL;
				New2 -> next = NULL;
				Head_pointer = New2; 
			}
			else                                                 /// if not NULL
			{
			//printf ("%d %d new\n",New_pointer -> start, New_pointer -> length);
				struct list_node * temp;
				struct list_node * temp2;
				struct list_node * temp1;
				temp2=Head_pointer;
				if(New1 != NULL)
				{
					x=New1 -> start;
					y= New1 -> length;
				}
				else
				{
					x=n;
					y=n+m;
				}
				New2=make_node(x,y);
				while(temp2!=NULL)
				{
					//printf("1\n");
					temp1=temp2;
					//printf("%d %d\n",temp2 -> start , temp2 -> length);
					temp2=temp2 -> next;
				}	
				New2 -> prev = temp1;
				temp2= New2;
				temp2-> next = NULL;
				temp1 -> next = temp2 ;
			//	printf("%d %d \n", temp2 -> start , temp2 -> length);
			}


		}
		else                                     // if deallocated
		{
			struct list_occured * maybe;
			struct list_occured * may;
			maybe=possible;
			while(maybe!=NULL)                       // checks whether is is deallocated before or not 
			{
				if(maybe -> value==m)
				{
					break;
				//	printf("1\n");
				}
				maybe = maybe -> next;
			}
			if(maybe==NULL)                            // if not deallocated before
			{

				struct list_node * temp;
				struct list_node * temp3;
				struct list_node * temp1;
				struct list_node * temp2;
				int flag=0;
				temp=search_list(Head_pointer,m);       // search for the the no in the list 
				if(temp!=NULL)
				{
				//	printf ("%d %d \n",temp -> start , temp -> length);
					temp1=search_list_start_less(Head_free,temp -> start);   // search for start more than this 
				//	printf ("%d %d \n",temp1 -> start , temp1 -> length);
					if(temp1!=NULL)    // if that is the end
					{
						if(temp1 -> next==NULL)    // merging steps
						{
						//	printf("1\n");
						//	printf("%d %d\n",temp1 -> start , temp1 -> length);
							if(temp1 -> start == temp -> start + temp -> length)
							{
								temp1 -> start = temp1 -> start - temp ->  length;
								temp1 -> length = temp1 -> length + temp ->  length;
							}
							else
							{
								temp2 = make_node(temp -> start, temp -> length );
								if(temp1 == Head_free)
								{
									temp2 -> next = Head_free;
									temp2 -> prev = NULL;
									Head_free -> prev = temp2;
									Head_free= temp2;
									flag=2;
								}
								else
								{
									temp2 -> next = temp1;
									temp2 -> prev = temp1 -> prev;
									temp1 -> prev -> next = temp2;
									temp1 -> prev = temp2;
								}
							}
							if(flag!=2)
								flag=1;
						//	printf("1\n");
						}
						else if(temp1 -> start == temp -> start+ temp -> length)    // means value  exist 
						{
							temp1 -> start = temp1 -> start - temp -> length;
							temp1 -> length = temp1 -> length +temp -> length;
							flag=1;
						//	printf("2\n");
						}
						else if(temp1==Head_free && flag==0)    // if that is head 
						{
							temp2=make_node(temp -> start, temp -> length);
							temp2 -> next = Head_free;
							Head_free -> prev= temp2;
							Head_free = temp2;
							flag=2;
						//	printf("3\n");
						}

						if (temp1 -> prev != NULL && flag!=2 && temp -> start == temp1 -> prev -> start + temp1 -> prev -> length)
						{                                            // if previous not null
							if(flag==1 )
							{
								temp1 ->  prev -> length +=  temp1 -> length ;
								temp1 -> prev -> next = temp1 -> next;
								if(temp1 -> next !=NULL)
									temp1 -> next -> prev = temp1 -> prev;
								free (temp1);  
							}
							else
							{
								temp1 -> prev -> length += temp -> length ; 
							}
							flag=1;
						//	printf("4\n");
						}	
						if (temp1!=Head_free && flag==0)
						{
							temp2=make_node(temp -> start, temp -> length);
							temp2 -> next = temp1;
							temp1 -> prev -> next = temp2;
							temp2 -> prev = temp1 -> prev;
							temp1 -> prev = temp2;
						//	printf("5\n");
						}
					}
					temp2=search_list_locate(Head_alloc,temp -> start);          // search place to locate 
					if(temp2!=NULL)
					{
						//printf("%d %d \n",temp2 -> start , temp2  -> length);
						if(temp2 == Head_alloc)
						{
							Head_alloc= Head_alloc-> next;
						}
						else
						{
							temp3= temp2->prev;
							temp3 -> next = temp2 -> next ;
							if(temp2 -> next != NULL)
								temp2 -> next -> prev = temp3 ;
							free(temp2);
						} 
					}
					struct list_node * curr_free;                    
					struct list_node * curr_alloc;             
					curr_alloc = Head_alloc;
					while(curr_alloc!=NULL)                                // ensure no zero length alloc 
					{
						if(curr_alloc -> length == 0)
						{
							if(curr_alloc -> prev != NULL)
							{
								curr_alloc -> prev -> next  = curr_alloc -> next ;
								curr_alloc -> next -> prev = curr_alloc -> prev;
								free(curr_alloc);
							}
							else
							{
								curr_alloc -> next -> prev = NULL;
								free(curr_alloc);
							}
						}
						curr_alloc = curr_alloc -> next;
					}
					/*curr_free = Head_free;
					while(curr_free!=NULL)
					{
						if(curr_free -> length == 0)
						{
							if(curr_free -> prev != NULL && curr_free -> next !=NULL)
							{
								curr_free -> prev -> next  = curr_free -> next ;
								curr_free -> next -> prev = curr_free -> prev;
								free(curr_free);
							}
							else if(curr_free -> next != NULL)
							{
								curr_free -> next -> prev = NULL;
								free(curr_free);
							}
							else
								free(curr_free);
						}
						curr_free = curr_free -> next ;
					}*/
					struct list_occured *may1;
	  			   	may1 = (struct list_occured *)calloc(1, sizeof(struct list_occured));
	     			may1 -> value = m;
	     			may1 -> next = NULL;
					if(possible==NULL)                               /// add that dealloc in possible
					{
						possible = may1; 
					}
					else
					{
						maybe = possible;
						may=NULL;
						while(maybe!=NULL)
						{
							may=maybe;
							maybe=maybe -> next;
						}
						may -> next = may1;


					}
				}
			}
		}
		curr=Head_free;              // in case some left over merge
		if(curr!=NULL)
		{
			while(curr -> next !=NULL)
			{
				//printf("%d %d %d\n",curr -> start, curr -> length , curr -> next -> start);
				if(curr -> next -> start == curr -> start + curr -> length)
				{
					curr -> length += curr -> next -> length;
					curr -> next = curr -> next -> next;
					curr -> next -> prev = curr ; 
					//printf("1\n");
				}
				else
				{
					curr= curr -> next;
				}
				
			}
		}
		struct list_occured *currmay;
		currmay=possible;
		/*while(currmay!=	NULL)
		{
			printf("%d poss\n",currmay-> value);
			currmay=currmay -> next;
		}
		curr=Head_free;
		while(curr!=NULL)
		{
			printf("%d %d free\n",curr -> start, curr -> length);
			curr= curr -> next;
		}
		curr=Head_alloc;
		while(curr!=NULL)
		{
			printf("%d %d alloc\n",curr -> start, curr -> length);
			curr= curr -> next;
		}*/
	}

	struct list_node * curr_free;
	struct list_node * curr_alloc;
	int s_alloc,s_free;
	curr_free=Head_free;
	curr_alloc=Head_alloc;
	printf("\n");
	while(curr_alloc!=NULL && curr_free!=NULL)                              // printing in sorted order
	{
		while(curr_free != NULL && curr_free -> length == 0)
			curr_free = curr_free -> next ;
		if(curr_free == NULL)
			break;
		if(curr_alloc == NULL)
			break;
		s_free= curr_free -> start;
		s_alloc = curr_alloc -> start;
		if(s_free < s_alloc)
		{
			printf("%d %d free\n",curr_free -> start, curr_free -> length);
			curr_free = curr_free -> next;
 		}
		else
		{
			printf("%d %d allocated \n",curr_alloc -> start, curr_alloc -> length);
			curr_alloc = curr_alloc -> next;
		}
	}
	while(curr_free != NULL)
	{
		printf("%d %d free\n",curr_free -> start, curr_free -> length);
		curr_free = curr_free -> next;
	}
	while(curr_alloc != NULL)
	{
		printf("%d %d alloc\n",curr_alloc -> start, curr_alloc -> length);
		curr_alloc = curr_alloc -> next;
		
	}

	return 0;
}
