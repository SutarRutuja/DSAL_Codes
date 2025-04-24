#include<iostream>
#include<string>
#include<stack> 
#include<queue>
#include<vector>
using namespace std;
class bst{
public:
int data;
bst*left;
bst*right;
bst(int d){
   this->data=d;
   this->left=NULL;
   this->right=NULL;
}




};


class bst_operation{
public:
//function to create root of tree
bst * create(bst * &root){
   bst * newnode;
   cout<<"Enter root's data: ";
   int k;
   cin>>k;
   newnode =new bst(k);
   if(root==NULL){
       root=newnode;
       return root;
   }
return NULL;
}


void insert_node(bst* &root,bst * newnode)
{
  if(root!=NULL){
      if(newnode->data <=root->data){
       if(!root->left){
           root->left=newnode;


       }
       else{
           insert_node(root->left,newnode);
       }
      }
      else{
            if(!root->right){
           root->right=newnode;


       }
       else{
           insert_node(root->right,newnode);
       }






      }




  }
  else{
   return;
  }




}
void preorder(bst *root){
   if(root==NULL){
       return ;
   }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);


}
void postorder(bst * root){
    if(root==NULL){
       return ;
   }
 
   postorder(root->left);
   postorder(root->right);
    cout<<root->data<<" ";


}


void display(bst *root)
   {


       cout << "Displaying BFS of tree: " << endl;
       if (root == NULL)
       {
           cout << "Empty tree" << endl;
           return;
       }
       queue<bst*> q;
       q.push(root);
       q.push(NULL);
       while (!q.empty())
       {
           bst *temp = q.front();
           q.pop();


           if (temp == NULL)
           {
               cout << endl;
               if (!q.empty())
               {
                   q.push(NULL);
               }
           }
           else
           {
               cout << temp->data << " ";
               if (temp->left)
               {
                   q.push(temp->left);
               }
               if (temp->right)
               {
                   q.push(temp->right);
               }
           }
       }
   }
void inorder(bst *root){
   if(root==NULL){
       return ;
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}


int height(bst * root){
   if(root==NULL){
       return -1 ;
   }
   int left =height(root->left);
   int right=height(root->right);
   int maxi =max(left,right)+1;
   return maxi;
}
void swap_tree(bst *root){


if(root==NULL){
   return ;
}
bst *temp=root->left;
root->left=root->right;
root->right=temp;
swap_tree(root->left);
swap_tree(root->right);








}


int max_path(bst * root){
   return height(root)+1;


}
int min_ele(bst * root){
   if(root==NULL){
       cout<<"Empty tree"<<endl;
       return 0;
   }
   while (root->left)
   {
      root=root->left;
   }
   return root->data;
  
}
int max_ele(bst * root){
   if(root==NULL){
       cout<<"Empty tree"<<endl;
       return 0;
   }
   while (root->right)
   {
      root=root->right;
   }
   return root->data;
  
}
void search(bst * root,int key){
bst * curr=root;
int cnt=0;
while(curr!=NULL){
if(curr->data ==key){
cnt++;
cout<<"key found in "<<cnt<<" comparision"<<endl;
break;


}
else if(curr->data < key){
   cnt++;
   curr=curr->right;


}
else{
   cnt++;
   curr=curr->left;


}


}


if(curr==NULL){
   cout<<"Key not found  in "<<cnt<<" comparision"<<endl;
}


}






   // non recursive function for tree inorder traversal
   void inorder_1(bst *root)
   {
       if (!root)
       {
           return;
       }
       stack<bst *> s1;
       bst *temp = root;


       while (temp != NULL || !s1.empty())
       {
           while (temp != NULL)
           {
               s1.push(temp);
               temp = temp->left;
           }
           temp = s1.top();
           s1.pop();
           cout << temp->data << " ";


           temp = temp->right;
       }


       cout << endl;
   }
   // non recursive function for preorder tree traversal
   void preorder_1(bst*root)
   {
       if (!root)
       {
           return;
       }
       stack<bst *> s1;
   bst *temp = root;
       s1.push(temp);
       while (!s1.empty())
       {
           temp = s1.top();
           s1.pop();


           // dislapy the data
           cout << temp->data << " ";
           if (temp->right)
           {
               s1.push(temp->right);
           }
           if (temp->left)
           {
               s1.push(temp->left);
           }
       }


       cout << endl;
   }


     // non recursive function for postorder traversal
   void postorder_1(bst*root)
   {
       if (root == nullptr)
       {
           return;
       }
       stack<bst *> s1, s2;
       s1.push(root);
       while (!s1.empty())
       {
           bst *temp = s1.top();
           s1.pop();
           s2.push(temp);


           if (temp->left)
           {
               s1.push(temp->left);
           }
           if (temp->right)
           {
               s1.push(temp->right);
           }
       }
       while (!s2.empty())
       {
           bst *temp = s2.top();
           s2.pop();
           cout << temp->data << " ";
       }
       cout << endl;
   }
   void swap(int &a,int &b){
       int temp=a;
       a=b;
       b=temp;
   }
//value must be present in the root
  void delete_node(bst *&root, int val) {
   if (root == NULL) {
       return;  // If the tree is empty, do nothing
   }
   if(root->data <val){
       delete_node(root->right,val);
   }
   else if(root->data>val){
            delete_node(root->left,val);
   }
   else{
     if(root->left==NULL && root->right==NULL){
       delete root;
       root=NULL;


     }
    else if(root->left==NULL){
         bst *temp=root;
         root=root->right;
         delete temp;
     }
    else if(root->right==NULL){
         bst *temp=root;
         root=root->left;
         delete temp;


     }
     else{
             bst * temp=root->left;
             while(temp->right!=NULL){
               temp=temp->right;
             }
             root->data=temp->data;
             delete_node(root->left,temp->data);
             return ;








     }


   }
  }

};



















int main(){
   bst * root=NULL;
   bst_operation obj;
  root= obj.create(root);
//    obj.insert_node(root);
bst *newnode;
cout<<"-----------------------------------------------------------------"<<endl;
cout<<"Enter no of nodes you wants to add:  ";
int n;
cin>>n;
for(int i=0;i<n;i++){
   cout<<"Enter value of node: ";
   int k;
   cin>>k;
 newnode=new bst(k);
   obj.insert_node(root,newnode);
}
   obj.display(root);


    cout<<"-----------------------------------------------------------------"<<endl;
  
   


    for(int i=0;i<20;i++){
       int z;
       cout<<"\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\n4.Height\n5.max path\n6.Minimum value\n7.Maximun value\n8.Search in bst\n9.Swap tree\n10Insert node to bst\n11.Delete node \n12.Exit"<<endl;
       cout<<"\nEnter your choice: ";
       cin>>z;
       if(z==1){
           cout<<"-----------------------------------------------------------------"<<endl;


            obj.inorder(root);
            cout<<endl;
            obj.inorder_1(root);
       }
       if(z==2){
            cout<<"-----------------------------------------------------------------"<<endl;


            obj.preorder(root); cout<<endl;
            obj.preorder_1(root);
       }
       if(z==3){
           cout<<"-----------------------------------------------------------------"<<endl;


            obj.postorder(root); cout<<endl;
            obj.postorder_1(root);
       }
       if(z==4){
           cout<<"-----------------------------------------------------------------"<<endl;
            cout<<"height of tree: "<<obj.height(root)<<endl;
       }
       if(z==5){
           cout<<"-----------------------------------------------------------------"<<endl;
            cout<<"No of nodes in maximum path: "<<obj.max_path(root)<<endl;
       }
       if(z==6){
           cout<<"-----------------------------------------------------------------"<<endl;
           cout<<"Minimum value in tree is "<<obj.min_ele(root)<<endl;
       }
       if(z==7){
           cout<<"-----------------------------------------------------------------"<<endl;
           cout<<"Maximun value in tree is "<<obj.max_ele(root)<<endl;
       }
       if(z==8){
           cout<<"-----------------------------------------------------------------"<<endl;
           for(int i=0;i<2;i++){
       int key;
       cout<<"Enter key to search: ";
       cin>>key;
       obj.search(root,key);
     }
       }
       if(z==12){
           break;
       }
       if(z==9){
      cout<<"-----------------------------------------------------------------"<<endl;
      cout<<"swapping the tree and displaying it "<<endl;
           obj.swap_tree(root);
               obj.display(root);
                 cout<<endl;
       }
       if(z==10){
            cout<<"Enter value of node: ";
              int k;
           cin>>k;
           newnode=new bst(k);
            obj.insert_node(root,newnode);
            obj.display(root);
       }
       if(z==11){
            cout<<"\nEnter node to be delete: ";
            int m;
            cin>>m;


            obj.delete_node(root,m);
            obj.display(root);
       }
      
    }
 
 


   return 0;
}


