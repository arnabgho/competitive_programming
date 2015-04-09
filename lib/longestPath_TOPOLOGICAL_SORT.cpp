topological(i);
					vector<int> order;
					while(!revtop.empty()){
						//cout<<"revtop.top() "<< revtop.top()<<endl;
						order.push_back(revtop.top());
						revtop.pop();
					}
					int k=order.size();
					vector<int> longest(n,1);
					int mx=1;
					for(int p=0;p<k;p++){
						int u=order[p];
						//cout<<"u "<<u<<endl;
						for(int v=0;v<n;v++){
							if(!alive[v]) continue;
							if(redG[u][v]=='1'){
								//cout<<"v "<<v<<endl;
								longest[v]=max(1+longest[u],longest[v]);
								mx=max(mx,longest[v]);
							}
						}
					}
					ans=max(mx,ans);