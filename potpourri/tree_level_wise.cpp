#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;
struct TreeLinkNode {
     int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
     };
 
 struct ob{
    TreeLinkNode * node;
    int level;
 };
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return ;
        struct ob * newob,*got;
        TreeLinkNode *node;
        queue<struct ob*> myQ;
        newob=(struct ob *)malloc(sizeof(struct ob));
        node=(TreeLinkNode *)malloc(sizeof(TreeLinkNode));
        newob->node=root;
        newob->level=0;
        myQ.push(newob);
       // root->next=NULL;
        while(!myQ.empty()){
            cout<<"Hi\n";
            got=myQ.front();
            cout<<"Hi\n";
            myQ.pop();
            node=got->node;
            if(node->left!=NULL){
                newob=(struct ob *)malloc(sizeof(struct ob));
                newob->node=node->left;
                newob->level=got->level+1;
                myQ.push(newob);
                newob=(struct ob *)malloc(sizeof(struct ob));
                newob->node=node->right;
                newob->level=got->level+1;  
                myQ.push(newob);
            }

            if(myQ.empty()){
                node->next=NULL;
                break;
            }
            if(myQ.front()->level==got->level)
                node->next=myQ.front()->node;
            else
                node->next=NULL;
           // free(got);    
        }
    }
};

int main(){
    TreeLinkNode * root;
    TreeLinkNode * newnode;
    Solution * sol;
    root=(TreeLinkNode*)malloc(sizeof(TreeLinkNode));

    //left
    newnode=(TreeLinkNode*)malloc(sizeof(TreeLinkNode));
    root->left=newnode;
    //right
     newnode=(TreeLinkNode*)malloc(sizeof(TreeLinkNode));
    root->right=newnode;
    sol=(Solution*)malloc(sizeof(Solution));
    sol->connect(root);
    return 0;
}