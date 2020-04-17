/**
*Vector of integers written in C++
*@author Justin Casey CS-174
*@version 1.0, April 17, 2020
*/

#include <iostream>
#include "IntVector.h"
using namespace std;
/**
* Helper function that expands the internal array to accommodate more values
* @return void
*/
  void IntVector::expandArray(){
    arraysize = arraysize*expansion_factor;// adjust arraysize to accommodate more values
    int* temp = new int[arraysize];//create new array to hold values
    for(int i = 0; i < num_elements; ++i){//loop over elements
      temp[i] = array[i];//set temp value equal to array value
    }
    delete[] array;//delete old array to free its memory
    array = temp;// set array value equal to expanded array


  }
  /**
  * The consructor creates the IntVector with an initial size of whatever integer the user
  * inputs
  * @param initialsize The initial size of the internal array used in making an IntVector
  * @return void
  */
  IntVector::IntVector(int initialsize){
    this->arraysize = initialsize; // initialize our variables
    this->num_elements = 0;
    this->expansion_factor = 2;
    this->array = new int[initialsize];

  }
  /**
  * The destructor deletes internal array to free memory it was allocated.
  * @return void
  */
  IntVector::~IntVector(){
    delete[] array;
  }
  /**
  * Adds a value to the end of the IntVector
  * @param value The value of the index to be added to the IntVector
  * @return void
  */
   void IntVector::add(int value){
     if(num_elements == arraysize){//checks if array is full
       expandArray();
     }
     array[num_elements] = value;
     ++num_elements;
     }
   /**
   * Removes the last element of the IntVector
   * @return void
   */
   void IntVector::removeLast(){
     --num_elements;//decrease elements by 1 so last index is not accesable, thus removed
   }
   /**
   * Removes the value at index and shifts all elements after index to the left
   * in the internal array
   * @param index The index of the element in the IntVector the user wishes to remove
   * @return void
   */
   void IntVector::remove(int index){
     int* new_array = new int[arraysize]; // create new array to hold values
     for(int i = 0; i < index; ++i){//fill new array with same values as array until index
       new_array[i] = array[i];
     }
     for(int j = index; j < num_elements; ++j){//jump over index wished to be removed
        new_array[j] = array[j+1];
     }
     delete[] array;//delete old array
     array = new_array;//set array to new_array
     --num_elements;
   }
   /**
   * Returns value conatained at index that user inputs
   * @param index The index of the vector element the user wishes to get
   * @return The integer value at a given index
   */
   int IntVector::get(int index) const{
     return array[index];
   }
   /**
   * Sets the value at index to the user input value
   * @param index The index of the vector element the user wishes to set
   * @param value The value the user wishes to set a given element to
   * @return void
   */
   void IntVector::set(int index, int val){
     array[index] = val;
   }
   /**
   * Returns the number of elements in the IntVector
   *@return int num_elements, the number of elemets in a list
   */
   int IntVector::size() const{
     return num_elements;
   }
   /**
   * Returns a string representation of the current state of the IntVector
   * @return A string representation if the current IntVector
   */
    std::string IntVector::toString() const{
     std::string str = "";//initialize empty string
     for(int i = 0; i < num_elements;++i){//loop through elements
      if(i < num_elements-1){
        str = str + std::to_string(array[i]) + (", ");//print out elements with comma
      }else{
        str = str + std::to_string(array[i]);// prints with no comma if last element
     }
   }
     str = "[" + str + "]";//adds brackets around string
     return str;
   }


// Test Program
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
  v.set(2,69);
  cout<<v.get(7)<<endl;
  cout<<v.get(0)<<endl;
  v.add(42);
  cout<<v.toString()<<endl;
  v.removeLast();
  v.add(43);
  cout<<v.toString()<<endl;
  cout<<v.size()<<endl;
  int x = v.size();
  for(int i = 0; i<x; ++i){
    v.remove(i);
  }
  cout<<v.toString()<<endl;
  cout<<v.size()<<endl;
  cout<< "New Test 4" << endl;
  return 0;
}
