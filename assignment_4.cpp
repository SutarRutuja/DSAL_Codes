#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;


class hashing{


int size;
vector<pair<int,string>>table;
public:
hashing(int size){
   this->size=size;
   table.resize(size,{-1,""});


}
int getkey(int num){
   return num%10;
}
int insertWithReplacement(int key , string & value){
    int comparisons=0;
    int index=getkey(key);


    while(table[index].first!=-1){
      
       comparisons++;
       if(table[index].first==key){
          
           table[index].second=value;
       }
       else{




       }
       index=(index+1)%size;




    }
    table[index]={key,value};


     return comparisons;
}




void display(){
   cout<<"\n-------------------------------------------------------------------"<<endl;
   cout<<"Hash table is "<<endl;
   int i=0;
 vector<pair<int,string>>::iterator it=table.begin();
 while(it!=table.end()){


   cout<<i<<"---->" <<it->first <<" "<<it->second<<endl;
   it++;
   i++;
 }


 }


};
int main(){
hashing h1(10);
string a="";
string b="jfdk";
// h1.display();
// h1.insertWithReplacement(2,a);
// h1.insertWithReplacement(3,a);
// h1.insertWithReplacement(5,a);
// h1.display();
// h1.insertWithReplacement(15,b);
// h1.display();
// h1.insertWithReplacement(6,b);
// h1.display();
for(int i=0;i<=9;i++){
   h1.insertWithReplacement(i,a);


}
h1.display();
h1.insertWithReplacement(2,a);
h1.insertWithReplacement(3,a);
h1.insertWithReplacement(5,a);
h1.display();
h1.insertWithReplacement(15,b);
h1.display();
h1.insertWithReplacement(6,b);
h1.display();










   return 0;
}
//—-----------------------------------------------------------------------------------------

// Consider telephone book database of N clients. Make use of a hash table 
// implementation to quickly look up client‗s telephone number. Make use of two
// collision handling techniques and compare them using number of comparisons
// required to find a set of telephone numbers (use linear probing with replacement
// and without replacement)
// 5. Implement all the functions of a dictionary (ADT) using hashing and handle
#include <iostream>
using namespace std;

#define TABLE_SIZE 10

// Function to calculate hash value
int hashFunction(int key) {
 return key % TABLE_SIZE;
}

// Class to implement the hash table with linear probing
class HashTable {
public:
 int table[TABLE_SIZE];
 
 // Constructor to initialize the table with -1 (empty)
 HashTable() {
 for (int i = 0; i < TABLE_SIZE; i++) {
 table[i] = -1; // -1 means empty slot
 }
 }

 // Insert function without replacement (linear probing)
 void insertWithoutReplacement(int value) {
 int hashValue = hashFunction(value);
 int originalHash = hashValue;
 
 // Search for the next available space using linear probing
 while (table[hashValue] != -1) {
 cout<<"checking for next empty location"<<endl;
 hashValue = (hashValue + 1) % TABLE_SIZE;
 if (hashValue == originalHash) {
 cout << "No space for current element\n";
 return;
 }
 }
 
 // Insert the value into the found slot
 table[hashValue] = value;
 cout << "Element inserted\n";
 }

 // Insert function with replacement (linear probing)
 void insertWithReplacement(int value) {
 int hashValue = hashFunction(value);
 int originalHash = hashValue;
 if (table[hashValue] != -1) {
 int t = table[hashValue];

 if(hashFunction(t)!=hashValue){
 cout << "Replacing current element- " << table[hashValue] 
 << " with new element- " << value << endl;
 int m = table[hashValue] ;
 table[hashValue] = value;
 value = m;
 }
 hashValue++;
 while(table[hashValue]!=-1){
 hashValue = (hashValue + 1) % TABLE_SIZE;
 if (hashValue == originalHash) {
 cout << "No space for current element\n";
 return;
 }
 }
 

 
 
 
 // Insert the value into the found slot
 table[hashValue] = value;
 cout << "Element inserted\n";
 }
 else{
 table[hashValue] = value;
 }
 }

 // Display the current state of the hash table
 void displayTable() {
 
 for (int i = 0; i < TABLE_SIZE; i++) {
 cout << i<<" "<<table[i] << " ";
 cout<<endl;
 }
 cout << endl;
 }

 // Search for a value in the table (not required for this task, but useful)
 bool search(int value) {
 int hashValue = hashFunction(value);
 int originalHash = hashValue;

 while (table[hashValue] != -1) {
 if (table[hashValue] == value)
 return true;
 hashValue = (hashValue + 1) % TABLE_SIZE;
 if (hashValue == originalHash)
 return false;
 }
 return false;
 }
};

int main() {
 HashTable obj;
 HashTable obj1;


 int choice, value;

 while (true) {
 cout << "Enter 1 for Insert\n";
 cout << "Enter 2 to Display Hash Table\n";
 cout << "Enter 3 to Exit\n";
 cin >> choice;

 switch (choice) {
 case 1:
 cout << "Enter value: ";
 cin >> value;
 obj.insertWithoutReplacement(value);
 obj1.insertWithReplacement(value);
 break;

 
 case 2:
 cout << "Hash Table without replacement: "<<endl;
 cout<<"index"<<" "<<"tele number"<<endl;
 obj.displayTable();
 cout << "Hash Table with replacement: "<<endl;
 cout<<"index"<<" "<<"tele number"<<endl;
 obj1.displayTable();
 break;

 case 3:
 return 0;

 default:
 cout << "Invalid choice, try again.\n";
 }
 }

 return 0;
}

