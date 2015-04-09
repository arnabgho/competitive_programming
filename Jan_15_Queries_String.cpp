#include"assert.h"
struct segtree_node{/*{{{*/
public:
  void merge(segtree_node&, segtree_node&){}
  void split(segtree_node&, segtree_node&){}
};/*}}}*/
template<class node>
class segtree{/*{{{*/
	template<bool b>class param{};
	inline void spltdwn(int idx,param<true>){splt(idx);}
	inline void splt(int idx){/*{{{*/
		idx>>=1;
		if(idx>0)splt(idx);
		tree[idx].split(tree[idx<<1],tree[(idx<<1)|1]);
	}/*}}}*/
	inline void spltdwn(int,param<false>){};
	inline void split(node& a, node& b, node& c, param<true> ){return a.split(b,c);}
	inline void split(node&, node&, node&, param<false>){}
	template<typename t,void (t::*)(t&,t&)> class T{};
	template<typename t> static char test(T<t,&t::split>*){return 0;}
	template<typename t> static long double test(...){return 0;}
	int u,v;
	node query(int root, int left_range, int right_range){/*{{{*/
		if(u<=left_range && right_range<=v)
			return tree[root];
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		node res;
		if(u>=mid)res=query(r,mid,right_range);
		else if(v<=mid)res=query(l,left_range,mid);
		else{
			node n1 = query(l,left_range,mid),
				 n2 = query(r,mid,right_range);
			res.merge(n1,n2);
		}
                if(has_split) tree[root].merge(tree[l],tree[r]);
		return res;
	}/*}}}*/
 	template<void(*fn)(node&)>
	void local_update(int root, int left_range,int right_range){/*{{{*/
		if(u<=left_range && right_range<=v){
			return fn(tree[root]);
		}
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		if(v>mid)local_update<fn>(r,mid,right_range);
		if(u<mid)local_update<fn>(l,left_range,mid);
		tree[root].merge(tree[l],tree[r]);
	}/*}}}*/
	void mrgup(int idx){/*{{{*/
		idx>>=1;
		while(idx>0)
			tree[idx].merge(tree[idx<<1],tree[(idx<<1)|1]),
			idx>>=1;
	}/*}}}*/
public:
	static bool const has_split = (sizeof(test<node>(0))==sizeof(char));
	int N;
	int leftmost_leaf, rightmost_leaf;
	node* tree;
	node identity;
	segtree(){ tree=0; }
	~segtree(){
                if(tree) delete[] tree;
	}
	void init(int n, const node a[], const node& identity){/*{{{*/
                if(tree) delete[] tree;
		this->identity = identity;
		N=0;
		while((1<<N)<n)N++;
		leftmost_leaf = 1<<N;
		rightmost_leaf = leftmost_leaf<<1;
		tree = new node[rightmost_leaf];
		for(int i=0;i<n;i++)
			tree[i+leftmost_leaf] = a[i];
		for(int i=n+leftmost_leaf;i<rightmost_leaf;i++)
			tree[i]=identity;
		for(int i=leftmost_leaf-1;i;i--)
			tree[i].merge(tree[i<<1],tree[(i<<1)|1]);
	}/*}}}*/
	node query(int u, int v){//[u,v]/*{{{*/
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return query(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	node query(int u){//faster version of query(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		return tree[u];
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u, int v){/*{{{*/
		//0-indexed
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return local_update<fn>(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u){//faster version of update(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		fn(tree[u]);
		mrgup(u);
	}/*}}}*/
	void split_down(int leaf_idx){/*{{{*/
		spltdwn(leaf_idx+leftmost_leaf,param<has_split>());
	}/*}}}*/
	void merge_up(int leaf_idx){/*{{{*/
		mrgup(leaf_idx+leftmost_leaf);
	}/*}}}*/
	bool is_leaf(int tree_idx){return tree_idx>=leftmost_leaf;}
};/*}}}*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define INF 10000000       

struct node
{
	int sum,num;
	int prefix[3];
	int suffix[3];
	void split(node &l,node &r){}
	void merge(node &l,node &r){
		sum=(l.sum+r.sum)%3;
		num=l.num+r.num+l.suffix[0]*r.prefix[0]+l.suffix[1]*r.prefix[2]+l.suffix[2]*r.prefix[1];
		prefix[0]=l.prefix[0]+r.prefix[(3-l.sum)%3];
		prefix[1]=l.prefix[1]+r.prefix[(4-l.sum)%3];
		prefix[2]=l.prefix[2]+r.prefix[(5-l.sum)%3];
		suffix[0]=r.suffix[0]+l.suffix[(3-r.sum)%3];
		suffix[1]=r.suffix[1]+l.suffix[(4-r.sum)%3];
		suffix[2]=r.suffix[2]+l.suffix[(5-r.sum)%3];
	}	
};

node createLeaf(int k){
	node n;
	// cout<<"k "<<k;
	n.sum=k%3;
	// cout<<"n.sum "<<n.sum<<endl;
	n.num=(n.sum==0);

	n.prefix[0]=0;n.prefix[1]=0;n.prefix[2]=0;
	n.suffix[0]=0;n.suffix[1]=0;n.suffix[2]=0;

	n.prefix[k%3]=1;
	n.suffix[k%3]=1;
	return n;
}
int value;
void change(node& n){
	n.sum=value%3;
	n.num=(n.sum==0);

	n.prefix[0]=0;n.prefix[1]=0;n.prefix[2]=0;
	n.suffix[0]=0;n.suffix[1]=0;n.suffix[2]=0;

	n.prefix[value%3]=1;
	n.suffix[value%3]=1;
}
int main(){
	int n,m;
	cin>>n>>m;
	string st;
	cin>>st;
	node arr[n+1];
	for (int i = 0; i < n; ++i)
	{
		// cout<<"num "<<st[i]-'0'<<endl;
		arr[i]=createLeaf(st[i]-'0');
		// cout<<"i "<<i<<endl;
		// cout<<arr[i].num<<endl;
	}
	segtree<node> s;
	arr[n].sum=0;arr[n].num=0;arr[n].prefix[0]=0;arr[n].prefix[1]=0;arr[n].prefix[2]=0;arr[n].suffix[0]=0;arr[n].suffix[1]=0;arr[n].suffix[2]=0;
	s.init(n,arr,arr[n]);
	while(m--){
		int d;
		cin>>d;
		if(d==1){
			int pos;
			cin>>value>>pos;
			s.update<&change>(pos-1); 
		}
		else if(d==2){
			int c,d;
			cin>>c>>d;
			node x=s.query(c-1,d-1);
			cout<<x.num<<endl;
		}
	}
}