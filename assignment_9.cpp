/*
A Dictionary stores keywords and its meanings. Provide facility for
adding new keywords, deleting keywords, updating values of any entry.
Provide facility to display whole data sorted in ascending/ Descending
order. Also find how many maximum comparisons may require for
finding any keyword. Use Height balance tree and find the complexity for
finding a keyword.
*/


#include<bits/stdc++.h>
using namespace std;
class node{
   public:
   string key;
   string meaning;
node * left;
node * right;
int height;
node (string k,string m){
   key=k;
   meaning=m;
   left=NULL;
   right=NULL;
   height=1;


}
};


class bst_opeartion{
public:
int getheight(node * root){
   if(root){
       return root->height;
   }
return 0;
}
int getbalenceFactor(node * root){
   if(root){
       return getheight(root->left)-getheight(root->right);
   }
return 0;
}


void updateHeight(node* root) {
  root->height = 1 + max(getheight(root->left), getheight(root->right));
}


void inorder(node * root){
   if(root==NULL){
       return;
   }
   inorder(root->left);
   cout<<root->key<<" : "<<root->meaning<<"\t\t";
   inorder(root->right);
}


void inorder2(node * root){
   if(root==NULL){
       return;
   }
   inorder2(root->right);
   cout<<root->key<<" : "<<root->meaning<<"\t\t";
   inorder2(root->left);
}


bool search(node * root,string  keyword){
   int cmp=0;
   while(root){
       cmp++;
       if( keyword>root->key ){
           root=root->right;
       }
       else if(keyword<root->key){
           root=root->left;


          
       }else{


           cout<<"Comparisons required: "<<cmp<<endl;
           cout<<"Meaning of "<<keyword<<" is: "<<root->meaning<<endl;
           return true;


       }


   }
   return false;


}
void update(node * root,string  keyword,string m){
  
   while(root){
     
       if( keyword>root->key ){
           root=root->right;
       }
       else if(keyword<root->key){
           root=root->left;


          
       }else{


           root->meaning=m;
           cout<<"updated";


           cout<<"Meaning of "<<keyword<<" is: "<<root->meaning<<endl;
           return;
          


       }


   }
  


}
node * left_rotate(node * x){


   node * y=x->right;
   node * t2=y->left;




   y->left=x;
   x->right=t2;
   updateHeight(x);
   updateHeight(y);




   return y;




}


node * right_rotate(node * x){


   node * y=x->left;
   node * t2=y->right;




   y->right=x;
   x->left=t2;


   updateHeight(x);
   updateHeight(y);
  


   return y;
  


}


node * balance(node * root){
   int balence_factor=getbalenceFactor(root);


   if(balence_factor>1){
       if(getbalenceFactor(root->left)<0){
           root->left=left_rotate(root->left);


       }
       return right_rotate(root);


   }
   else if(balence_factor<-1){
  if(getbalenceFactor(root->right)>0){
           root->right=right_rotate(root->right);


       }
       return left_rotate(root);
      
   }


   return root;
}
node * insert(node * &root,string k1,string m1){
if(!root){
   return new node(k1,m1);
}


if(root->key<k1){
 root->right=insert(root->right,k1,m1);
}
else if(root->key>k1){
   root->left=insert(root->left,k1,m1);
}
updateHeight(root);
return balance(root);


}
node* findMin(node* root) {
   if(root==NULL)return NULL;
   while (root->left != NULL)
       root = root->left;
   return root;
}


node* deleteNode(node* root, string key) {
   if (!root) return root; // Base case


   // Step 1: Perform BST delete
   if (key < root->key) {
       root->left = deleteNode(root->left, key);
   } else if (key > root->key) {
       root->right = deleteNode(root->right, key);
   } else {
       // Node found
       if (!root->left || !root->right) {
           node* temp = root->left ? root->left : root->right;
           delete root;
           return temp; // Return non-null child or NULL
       } else {
           // Node has two children, find inorder successor (smallest in right subtree)
           node* temp = findMin(root->right);
           root->key = temp->key;
           root->meaning = temp->meaning;
           root->right = deleteNode(root->right, temp->key); // Delete successor
       }
   }


   // Step 2: Update height and balance
   updateHeight(root);
   return balance(root);
}


void display(node *root)
  {




      cout << "Displaying BFS of tree: " << endl;
      if (root == NULL)
      {
          cout << "Empty tree" << endl;
          return;
      }
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      while (!q.empty())
      {
          node *temp = q.front();
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
              cout << temp->key << " ";
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










};
int main(){
cout<<"\n--------------------------------------------------------------------------"<<endl;
bst_opeartion obj;
node * root=NULL;
cout<<"how many nodes you want to add: ";
int n;
cin>>n;
for(int i=0;i<n;i++){
   string k,m;
   cout<<"Enter keyword : ";cin>>k;
   cout<<"Enter Meaning: "; cin>>m;
   root=obj.insert(root,k,m);


}
obj.display(root);


for(int i=0;i<29;i++){
cout<<"\n--------------------------------------------------------------------------"<<endl;
cout<<"\nMenu\n1.insert node \n2.Inorder\n3.Reverse inorder\n4.Search key for meaning\n5.delete keyword\n6.Display tree\n7.Update Meaning \n8.Exit"<<endl;
int k;
cout<<"Enter your choice: ";
cin>>k;
if(k==1){
   string k,m;
   cout<<"Enter keyword : ";cin>>k;
   cout<<"Enter Meaning: "; cin>>m;
   root=obj.insert(root,k,m);


}
if(k==2){
obj.inorder(root);


}
if(k==3){
obj.inorder2(root);


}
if(k==4){
   string k,m;
   cout<<"Enter keyword to search: ";cin>>k;
   obj.search(root,k);


}
if(k==5){
   string k,m;
   cout<<"Enter keyword to delete: ";cin>>k;
   root=obj.deleteNode(root,k);
   obj.display(root);


}
if(k==6){
obj.display(root);


}
if(k==8){
break;
}
if(k==7){
   cout<<"Enter which keyword you want to update: ";
   string k,m;
   cin>>k;
   cout<<"Enter new meaning: ";
   cin>>m;
   obj.update(root,k,m);


}






}
   return 0;


}
