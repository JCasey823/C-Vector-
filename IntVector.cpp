#include <iostream>
//#include "IntVector.h"
using namespace std;

class IntVector {
private:
  int* array;
  int arraysize;
  int num_elements;
  int expansion_factor;

  void expandArray(){
    int* new_array = new int[arraysize*2];
    for(int i = 0; i < num_elements; ++i){
      new_array[i] = array[i];
    }
    array = new_array;
    delete[] new_array;

  }

public:
  IntVector(int initialsize){
    this->arraysize = initialsize;
    this->num_elements = 0;
    this->array = new int[initialsize];
    cout<<"Constructed"<<endl;//REMOVE LATER

  }

  ~IntVector(){
    delete[] array;
    cout<<"Destroyed"<<endl;
  }


   void add(int value){
     if(num_elements == arraysize){
       expandArray();

     }
       int last = num_elements-1;
       array[last] = value;
       cout<<"Added: "<<value<<endl;
       ++num_elements;
       cout<<num_elements-1<<endl;
   }

   void removeLast(){
     int length = num_elements-1;
     int* new_array = new int[arraysize-1];
     int last = length;
     for(int i = 0; i < length; ++i){
       new_array[i] = array[i];
     }
     array = new_array;
     delete[] new_array;
   }

   void remove(int index){
     int* new_array = new int[arraysize-1];
     for(int i = 0; i < index; ++i){
       new_array[i] = array[i];
     }
     for(int j = index; j < num_elements-1; ++j){
       new_array[j] = array[j];
     }
     array = new_array;
     delete[] new_array;
     --num_elements;
   }

   //int get(int index) const{
  //   return 0;
  // }

  // void set(int index, int val){

  // }

   //std::string toString() const{
    // std::string str = "";
     //for(int i = 0; i < num_elements;++i){
      // str = str + array[i];
    // }
    // return str;
  // }
};

int main(int argc, char** argv){
  IntVector v(3);
  v.add(1);
  v.add(2);
  v.add(3);
  v.add(4);
  //v.removeLast();
  return 0;
}
