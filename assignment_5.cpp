/*Implement all the functions of a dictionary (ADT) using open hashing
technique: separate chaining using linked list

 OR
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, and Keys must be unique. Standard Operations: Insert(key,
value), Find(key), Delete(key) */
#include <iostream>
using namespace std;

class Node {
public:
  int word;
    Node* next;

    Node(int ch) {
        word = ch;
        next = nullptr;
    }
};

class heapoperation {
    Node* head[10];
public:
    heapoperation() {
        for (int i = 0; i < 10; i++) {
            head[i] = nullptr;
        }
    }

    int hashfunction(int v) {
        return v % 10;
    }

    void insert(int s) {
        char c = s[0];
        int key = hashfunction(c);

        Node* temp = head[key];
        if (temp == nullptr) {
            head[key] = new Node(s);
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node* newWord = new Node(s);
            temp->next = newWord;
        }
    }

    void display() {
        for (int i = 0; i < 26; i++) {
            Node* temp = head[i];
            cout << "Bucket " << i << ": ";
            if (temp != nullptr) {
                while (temp != nullptr) {
                    cout << temp->word << " -> ";
                    temp = temp->next;
                }
            }
            cout << "NULL" << endl;
        }
    }

    void find(string s) {
        int key = hashfunction(s[0]);
        Node* temp = head[key];
        if (temp == nullptr) {
            cout << "Word not found" << endl;
            return;
        } else {
            while (temp != nullptr) {
                if (temp->word == s) {
                    cout << "Word is found" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Word not found" << endl;
        }
    }

    void delete_word(string s) {
        int key = hashfunction(s[0]);
        Node* temp = head[key];


        if (temp == nullptr) {
            cout << "Word is not present" << endl;
            return;
        }

        Node* parent = nullptr;


        if (temp->word == s) {
            head[key] = temp->next;
            delete temp;
            cout << "Word deleted successfully" << endl;
            return;
        }


        while (temp != nullptr && temp->word != s) {
            parent = temp;
            temp = temp->next;
        }


        if (temp == nullptr) {
            cout << "Word is not present" << endl;
            return;
        }


        parent->next = temp->next;
        delete temp;
        cout << "Word deleted successfully" << endl;
    }
};

int main() {
    heapoperation h;
    string arr[15] = {"aryan", "amit", "vishal", "vedant", "chinmay", "sarvesh", "pranav", "harish", "varad", "abhijit", "rajesh", "aditya","manish","kiran","yogesh"};

    for (int i = 0; i < 15; i++) {
        h.insert(arr[i]);
    }

    h.display();

    cout << "Enter the word to be searched" << endl;
    string s;
    cin >> s;
    h.find(s);

    cout << "Enter the word to delete" << endl;
    cin >> s;
    h.delete_word(s);

    h.display();

    return 0;
}


//—------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class node{
public:
int value;
node * next;
node(int v){
   value=v;
   next=NULL;
}




};
class hashing{
public:
 vector<node *> table;
 int size;
 hashing(int s){
   size=s;
   table.resize(size,NULL);
 }
 int hashfunc(int k){
   return k%size;
 }


 void insert(int key){
   int index=hashfunc(key);
   node * nn=new node(key);


   if(table[index]==NULL){
       table[index]=nn;
       return ;
   }
   node * curr=table[index];
   while (curr->next!=NULL)
   {
       curr=curr->next;
   }
   curr->next=nn;
   cout<<"key value added"<<endl;
  
 }
void display(){


   cout<<"\n------------------------------------------------------------------------------"<<endl;
for(int i=0;i<size;i++){
cout<<"Bucket "<<i<<" : ";
node * curr=table[i];
while(curr!=NULL){
   cout<<curr->value<<"-->";
   curr=curr->next;
}
cout<<"NULL"<<endl;


}


}




int search(int key){
   int cnt=0;
int hashvalue=hashfunc(key);
node * curr=table[hashvalue];
while(curr!=NULL){
   if(curr->value==key){
       cnt++;


       cout<<"key found in comp "<<cnt<<endl;
       return key;
       break;


   }
   cnt++;


   curr=curr->next;
}
cout<<"value not found"<<endl;
return -1;


}




void delete_ele(int key){
   int hashvalue=hashfunc(key);
   node * curr=table[hashvalue];
   node * prev=NULL;


   while(curr!=NULL){
      if(curr->value==key){
       if(prev==NULL){
           table[hashvalue]=curr->next;


         }
         else if(curr->value==key){
           prev->next=curr->next;
         }


         delete curr;
         cout<<"deleted succesfully"<<endl;
         return ;


      }
          


     
              prev=curr;
              curr=curr->next;






}
cout<<"value cant deletd "<<endl;
}


};


int main(){
hashing h1(10);
cout<<"inital hash table is "<<endl;
h1.display();
// h1.insert(25);
// h1.insert(46);
// h1.insert(11);
// h1.insert(121);
// h1.display();
// h1.search(46);
// h1.delete_ele(46);
// h1.display();
// h1.delete_ele(121);
// h1.display();
for(int i=0;i<17;i++){
cout<<"\n Menu \n1.insert value \n2.display\n3.search\n4.delete key\n5.exit"<<endl;
int k;
cout<<"Enter your choice: ";
cin>>k;


if(k==1){
 cout<<"Enter value to insert: ";
 int m;
 cin>>m;
 h1.insert(m);


}
if(k==2){
   h1.display();


}
if(k==3){
   cout<<"Enter value to search: ";
 int m;
 cin>>m;
 h1.search(m);
 }
if(k==4){
cout<<"Enter value to delete: ";
 int m;
 cin>>m;
 h1.delete_ele(m);
 }
if(k==5){
   break;
}


}
    
   return 0;
}

