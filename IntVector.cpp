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
    delete[] array;
    array = new_array;
    delete[] new_array;

  }

public:
  IntVector(int initialsize){
    this->arraysize = initialsize;
    this->num_elements = 0;
    array = new int[initialsize];
    cout<<"Constructed"<<endl;//REMOVE LATER

  }

  ~IntVector(){
    delete[] array;
    cout<<"Destroyed"<<endl;
  }


   void add(int value){
     if(num_elements == arraysize){
       expandArray();
     }if(num_elements == 0){
       array[num_elements] = value;
       ++num_elements;
     }else{
       int last = num_elements;
       array[last] = value;
       //cout<<"Added: "<<value<<endl;
       ++num_elements;
     }

   }

   void removeLast(){
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

   void remove(int index){
     int* new_array = new int[arraysize-1];
     for(int i = 0; i < index; ++i){
       *(new_array+i) = *(array+i);
     }
     for(int j = index+1; j < num_elements-1; ++j){
        *(new_array+j) = *(array+j);
     }
     delete[] array;
     array = new_array;
     delete[] new_array;
     --num_elements;
   }

   int get(int index) const{
     return array[index];
   }

   void set(int index, int val){
     array[index] = val;
   }

   void toString() const{
     //std::string str = "";
     for(int i = 0; i < num_elements;++i){
      // std::string str2 = std::to_string(array[i]);
      //string str = str + str2;
      cout<<*(array+i)<<endl;
     }
     // str;
   }
};

int main(int argc, char** argv){
  IntVector v(3);
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
  v.set(0,1000);
  v.set(1,2000);
  cout<<v.get(7)<<endl;
  v.removeLast();
  v.toString();
  return 0;
}

