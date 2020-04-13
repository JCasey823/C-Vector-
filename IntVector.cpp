#include <iostream>
#include "IntVector.h"
using namespace std;
// TODO: Figure out how to fill arrays and why toString doesn't work with set
// I think I figured out the above ^^
  void IntVector::expandArray(){
    arraysize = arraysize*2;
    int* temp = new int[arraysize];
    for(int i = 0; i < num_elements; ++i){
      temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    //delete[] temp;


  }

  IntVector::IntVector(int initialsize){
    this->arraysize = initialsize;
    this->num_elements = 0;
    this->array = new int[initialsize];
    cout<<"Constructed"<<endl;//REMOVE LATER

  }

  IntVector::~IntVector(){
    delete[] array;
    cout<<"Destroyed"<<endl;
  }

   void IntVector::add(int value){
     if(num_elements == arraysize){
       expandArray();
       cout << "Array Expanded" << endl;
     }if(num_elements == 0){
       array[num_elements] = value;
       ++num_elements;
       cout<< "Added: "<< value<< endl;
     }else{
       int last = num_elements;
       array[last] = value;
       cout<<"Added: "<<value<<endl;
       ++num_elements;
     }

   }

   void IntVector::removeLast(){
     int last = num_elements-1;
     //int* new_array = new int[arraysize-1];
     //int last = length;
     //for(int i = 0; i < length; ++i){
       //new_array[i] = array[i];
     //}
     array[last] = 0;
     --num_elements;
    // delete[] new_array;
   }

   void IntVector::remove(int index){
     int* new_array = new int[arraysize];
     for(int i = 0; i < index; ++i){
       new_array[i] = array[i];
     }
     for(int j = index; j < num_elements; ++j){
        new_array[j] = array[j+1];
     }
     delete[] array;
     array = new_array;
     //delete[] new_array;
     --num_elements;
   }

   int IntVector::get(int index) const{
     return array[index];
   }

   void IntVector::set(int index, int val){
     array[index] = val;
   }

   void IntVector::showSize(){
     cout<< "The size of your vector is: "<< num_elements<< " elements"<<endl;
   }

    std::string IntVector::toString() const{
     std::string str = "";
     for(int i = 0; i < num_elements;++i){
      if(i < num_elements-1){
        str = str + std::to_string(array[i]) + (", ");
      }else{
        str = str + std::to_string(array[i]);
     }
   }
     str = "[" + str + "]";
     return str;
   }

   

int main(int argc, char** argv){
  IntVector v(9);
  v.add(1);
  v.add(2);
  v.add(3);
  v.add(4);
  v.add(5);
  v.add(6);
  v.add(7);
  v.add(8);
  v.add(9);
  v.add(10);
  v.remove(7);
  v.remove(1);
  v.set(7,1000);
  v.set(8,2000);
  cout<<v.get(7)<<endl;
  v.add(42);
  v.removeLast();
  v.add(42);
  //v.toStr();
  cout<<v.toString()<<endl;
  v.showSize();
  return 0;
}
