#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct coord{
	int x,y;
};

class WordFind {
public:


	struct coord* search_horiz(vector<string> grid,string word){
		int i,size_word,rows,cols,j,pos,k;
		size_word=word.size();
		cols=grid[0].size();
		rows=grid.size();
		struct coord* new_coord=(struct coord*)malloc(sizeof(coord));
		if(size_word>cols){
			new_coord->x=-1;
			new_coord->y=-1;
			return new_coord;
		}	
		int found=0;
		for(j=0;j<rows && !found;j++){
			for(i=0;i<=cols-size_word && !found;i++){
				pos=1;
				for(k=i;k<size_word+i && pos;k++){
					if(grid[j][k]!=word[k-i]){
						pos=0;
					}
				}
				if(pos){
					found=1;
					new_coord->x=j;
					new_coord->y=i;
				}
			}
		}
		return new_coord;
	}
	
	struct coord* search_vert(vector<string> grid,string word){
		int i,size_word,rows,cols,j,pos,k;
		size_word=word.size();
		cols=grid[0].size();
		rows=grid.size();
		struct coord* new_coord=(struct coord*)malloc(sizeof(coord));
		if(size_word>rows){
			new_coord->x=-1;
			new_coord->y=-1;
			return new_coord;
		}	
		int found=0;
		for(j=0;j<cols && !found;j++){
			for(i=0;i<=rows-size_word && !found;i++){
				pos=1;
				for(k=i;k<size_word+i && pos;k++){
					if(grid[k][j]!=word[k-i]){
						pos=0;
					}
				}
				if(pos){
					found=1;
					new_coord->x=i;
					new_coord->y=j;
				}
			}
		}
		return new_coord;
	}
	
	struct coord* search_diag(vector<string> grid,string word){
		int i,size_word,rows,cols,j,pos,k;
		size_word=word.size();
		cols=grid[0].size();
		rows=grid.size();
		struct coord* new_coord=(struct coord*)malloc(sizeof(coord));
		if(size_word>rows){
			new_coord->x=-1;
			new_coord->y=-1;
			return new_coord;
		}	
		int found=0;
		for(j=0;j<cols && !found;j++){
			for(i=0;i<=rows-size_word && !found;i++){
				pos=1;
				for(k=i;k<size_word+i && pos;k++){
					if(grid[k][j]!=word[k-i]){
						pos=0;
					}
				}
				if(pos){
					found=1;
					new_coord->x=i;
					new_coord->y=j;
				}
			}
		}
		return new_coord;
	}	
	
	
	struct coord* search_vert(vector<string> grid,string word){
		
	}
	struct coord* search_diag(vector<string> grid,string word){
		
	}

	vector <string> findWords(vector <string> grid, vector <string> wordList) {
			int size,i;
			struct coord* res_h,res_v,res_d;
			string temp,x,y;
			vector<string> res;
			size=wordList.size();
			for(i=0;i<size;i++){
				temp="";
				res_h=search_horiz(grid,wordList[i]);
				if(res_h->x!=-1 && res_h->y!=-1){
					x=to_string(res_h->x);
					temp=x;
					temp+=" ";
					y=to_string(res_h->y);
					temp+=y;
					
				}
				res_v=search_vert(grid,wordList[i]);
				else if(res_v->x!=-1 && res_v->y!=-1){
					x=to_string(res_v->x);
					temp=x;
					temp+=" ";
					y=to_string(res_v->y);
					temp+=y;
					
				} 
				res_d=search_diag(grid,wordList[i]);
				else if(res_d->x!=-1 && res_d->y!=-1){
					x=to_string(res_d->x);
					temp=x;
					temp+=" ";
					y=to_string(res_d->y);
					temp+=y;
					
				} 
				res.push_back(temp); 
			}
			return res;
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!n