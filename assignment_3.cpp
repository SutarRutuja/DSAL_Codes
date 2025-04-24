#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>


using namespace std;


class tbst
{
public:
   int data;
   tbst *left;
   tbst *right;
   bool l_thread;
   bool r_thread;
   tbst(int d)
   {
       this->data = d;
       this->left = NULL;
       this->right = NULL;
       l_thread = false;
       r_thread = false;
   }
};
class tbst_op
{
public:
   // function to create root of tree
   tbst *create(tbst *&root)
   {
       tbst *newnode;
       cout << "Enter root's data: ";
       int k;
       cin >> k;
       newnode = new tbst(k);
       if (root == NULL)
       {
           root = newnode;
           return root;
       }
       return NULL;
   }
   void insert_node(tbst *&root, tbst *newnode)
   {
       if (root != NULL)
       {
           if (newnode->data <= root->data)
           {
               if (!root->left || root->l_thread)
               {
                   // If left child is NULL, insert the new node and adjust threading
                   tbst *parent = root;
                   newnode->right = parent;
                   newnode->r_thread = true;
                   newnode->left = parent->left;
                   newnode->l_thread = parent->l_thread;
                   parent->left = newnode;
                   parent->l_thread = false;
               }
               else
               {
                   // Recurse to the left child
                   insert_node(root->left, newnode);
               }
           }
           else
           {
               if (!root->right || root->r_thread)
               {
                   // If right child is NULL, insert the new node and adjust threading
                   tbst *parent = root;
                   newnode->left = parent;
                   newnode->l_thread = true;
                   newnode->right = parent->right;
                   newnode->r_thread = parent->r_thread;
                   parent->right = newnode;
                   parent->r_thread = false;
               }
               else
               {
                   // Recurse to the right child


                   insert_node(root->right, newnode);
               }
           }
       }
       else
       {
           return;
       }
   }


   void display(tbst *root)
   {


       cout << "Displaying BFS of tree: " << endl;
       if (root == NULL)
       {
           cout << "Empty tree" << endl;
           return;
       }
       queue<tbst *> q;
       map<tbst *, bool> visited;


       q.push(root);
       q.push(NULL);
       while (!q.empty())
       {
           tbst *temp = q.front();
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
               if (!visited[temp])
               {
                   cout << temp->data << " ";
                   visited[temp] = true;
               }


               if (temp->left && visited[temp->left] == false)
               {
                   q.push(temp->left);
               }
               if (temp->right && visited[temp->right] == false)
               {
                   q.push(temp->right);
               }
           }
       }
   }


   tbst *leftmost(tbst *root)
   {
       if (root == NULL)
       {
           return NULL;
       }
       while (root->left != NULL && root->l_thread == false)
       {
           root = root->left;
       }
       return root;
   }
   void tbst_inorder(tbst *root)
   {
       tbst *curr = leftmost(root);
       while (curr != NULL)
       {
           cout << curr->data << " ";


           if (curr->r_thread == true)
           {
               curr = curr->right;
           }
           else
           {
               curr = leftmost(curr->right);
           }
       }
       cout << endl;
   }


   void tbst_preorder(tbst *root)
   {
       if (root == NULL)
       {
           cout << "empty tree" << endl;
           return;
       }


       // Map to keep track of visited nodes
       map<tbst *, bool> visited;


       tbst *temp = root;
       while (temp != NULL)
       {
           // If the node has already been visited, break the loop
           if (visited[temp])
           {
               break;
           }


           // Mark the current node as visited
           visited[temp] = true;


           // Print the data of the current node
           cout << temp->data << " ";


           // If left child exists and is not a thread, go left
           if (temp->left && !temp->l_thread)
           {
               temp = temp->left;
           }
           // If there's no left child or it's a thread, go to the right child
           else
           {
               // If there is a right child and it's a thread, move right
               if (temp->r_thread)
               {
                   if (temp->right->right) // --------- very important step
                       temp = temp->right->right;
               }
               else
               {
                   // If not threaded, go to the leftmost node of the right subtree
                   temp = leftmost(temp->right);
               }
           }
       }
   }


   // function to find inorder_successor and predecessor
   tbst *in_successor(tbst *node)
   {
       if (node->r_thread == true)
       {
           return node->right;
       }
       node = node->right;
       while (node->l_thread == false)      //<------------------ segmentation fault
       {   if(node->left)
           node = node->left;
       }
       return node;
   }


  
   tbst *in_pred(tbst *curr)
   {
       if (curr->l_thread == true)
       {
           return curr->left;
       }


       curr = curr->left;
       while (curr->r_thread == false)
       {
           curr = curr->right;
       }
       return curr;
   }
   tbst *delete_node(tbst *root, int key)
   {
       tbst *parent = NULL;
       tbst *curr = root;
       if (root == NULL)
       {
           cout << "Tree is empty can't delete the nodes" << endl;
           return root;
       }
       // searching if the value is in tree;
       int found = 0;


       while (curr != NULL)
       {


           if (curr->data == key)
           {
               found = 1;
               break;
           }
           parent = curr;


           // go to left or right for searching the nodes
           if (curr->data > key)
           {
               if (curr->l_thread == false)
               {
                   curr = curr->left;
               }
               else
               {
                   break;
               }
           }
           else
           {
               if (curr->r_thread == false)
               {
                   curr = curr->right;
               }
               else
               {
                   break;
               }
           }
       }
       if (found == 0)
       {
           cout << "key is not found in the tree" << endl;
       }
       // if curr to be deleted has two childs
       else if (curr->l_thread == false && curr->r_thread == false)
       {
           root = case3(root, parent, curr);
       }
       // has left child only
       else if (curr->l_thread == false)
       {
           root = case2(root, parent, curr);
       } // has right child only
       else if (curr->r_thread == false)
       {
           root = case2(root, parent, curr);
       }
       // is a leaf node
       else
       {
           root = case1(root, parent, curr);
       }
       return root;
   }


   // for leaf node


   tbst *case1(tbst *root, tbst *parent, tbst *curr)
   {
       if (parent == NULL)
       {
           root = NULL;
       }
       // if leaf node is left child of it's parent
       else if (curr == parent->left)
       {
           parent->l_thread = true;
           parent->left = curr->left;
       }


       // if leaf node is right child of it's parent
       else
       {
           parent->r_thread = true;
           parent->right = curr->right;
       }
       free(curr);
       return root;
   }
   // function for deleting node which have either 1 child
   tbst *case2(tbst *root, tbst *parent, tbst *curr)
   {


       tbst *child;
       // if curr node has left child
       if (curr->l_thread == false)
       {
           child = curr->left;
       }


       // if it has right child


       else
       {
           child = curr->right;
       }






       //if root node has to be delete d
       if(parent==NULL){
           root=child;
       }
       else if(parent->left==curr){
          parent->left=child;
       }
       else{
         parent->right=child;
       }
       
         // find inorder predeseccor and successor of the node
         tbst * s=in_successor(curr);
         tbst * p = in_pred(curr);




         // if curr has left subtree
         if(curr->l_thread==false){
             p->right=s;
         }
         else if(curr->r_thread==false){
           s->left=p;
         }
       free(curr);
     return root;


   }
   tbst *case3(tbst *root, tbst *parent, tbst *curr)
   {


       tbst *par_succ=curr;
       tbst * succ=curr->right;


       while(succ->l_thread==false){
             par_succ=succ;
             succ=succ->left;


       }


       curr->data=succ->data;
       // now check if succ is leaf node or node having one child to give according to cases
       if(succ->l_thread==true && succ->r_thread==true){
           root=case1(root,par_succ,succ);
       }
       else{
           root=case2(root,par_succ,succ);
       }


     return root;
}
};


int main()
{
   tbst *root = NULL;
   tbst_op obj;
   root = obj.create(root);
   tbst *newnode;
   cout << "-----------------------------------------------------------------" << endl;
   cout << "Enter no of nodes you wants to add:  ";
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
       cout << "Enter value of node: ";
       int k;
       cin >> k;
       newnode = new tbst(k);
       obj.insert_node(root, newnode);
   }
   obj.display(root);


   for(int i=0;i<10;i++){
        cout << "\n -----------------------------------------------------------------" << endl;
       cout<<"\nMenu\n1.TBST inorder \n2.TBST inorder\n3.Delete Node\n4.Exit"<<endl;
       int m;
       cout<<"Enter your choice: ";
       cin>>m;
       if(m==1){
              cout << "\nTBST inorder" << endl;
              obj.tbst_inorder(root);
       }
       else if(m==2){
              cout << "\nTBST preorder" << endl;
               obj.tbst_preorder(root);
       }
       else if(m==3){
             cout << "Enter data to be delete: ";
             int k;
            cin >> k;
            root=obj.delete_node(root, k);
            cout<<"\nTree after deletion is "<<endl;
             obj.tbst_inorder(root);


       }
       else if(m==4){
           cout<<"Exiting from the code "<<endl;
           break;


       }
       
       else{
           cout<<"\nInvalid choice "<<endl;
       }
   }


  




   return 0;
}



