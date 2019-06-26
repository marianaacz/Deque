// Project:  Deque
// Name: Mariana Acosta
// Submitted: 01/15/19
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying source
// code from any other source, providing source code to another student,
// or leaving my code on a public web site constitutes cheating.
// I acknowledge that  If I am found in violation of this policy this may result
// in a zero grade, a permanent record on file and possibly immediate failure of the class.
/* Reflection (1-2 paragraphs):    */

#include <stdexcept>
#include <cstddef>
#include <algorithm>

using std::size_t;
template<typename T>

class Deque {
    enum {CHUNK = 10};
    // Add you data members here…
    int front_;
    int back_;
    int size_;
    int capacity;
    int n;
    int pos;
    T *array;

public:
    Deque(){
        // Allocates a default-size (CHUNK) array
        front_ = (CHUNK /2)-1;
        back_ = front_;
        capacity = CHUNK;
        array = new T[capacity];
    }
    
    ~Deque(){
        // Deletes array heap memory
        delete [] array;
    }
    
    Deque(const Deque&) = delete; // Disables copy
    
    Deque& operator=(const Deque&) = delete; // Disables assignment
   
    void grow(){
        capacity += CHUNK;
        T *na = new T[capacity];
        //T *nf = new T;
        size_ = back_ - front_;
        int nf =(capacity-size_)/2;
        
        std::copy ( array+front_, array+back_, na+nf);
        delete [] array;
        array = na;
        front_ = nf;
        back_ = front_ + size_;
    }
    
    void push_front(T x){
        // Adds new element to the front (left end) **
        //Check for room, decrement front, add element
        if(front_ > 0){ //there is room
            front_--;
            array[front_] = x;
        }
        else { //no room
            grow();
            front_--;
            array[front_] = x; //?
        }
    }
    
    void push_back(T x){
        // Adds new element to the back (right end) **
        if(back_ < capacity){ //there is room
            array[back_] = x;
            back_++;
        }
        else { //no room
            grow();
            array[back_] = x; //?
            back_++;
        }
    }
    
    T& front(){
        // Returns a reference to the first used element **
        if(front_ == back_){
            throw std::logic_error("error");
        }
        return array[front_];

    }
    
    T& back(){
        // Returns a reference to the last used element **
        if(back_ == front_){
            throw std::logic_error("error");
        }
        return array[back_-1];
    }
    
    T& at(size_t pos){
        // Return a reference to the element in position pos
        //size_ = back_-front_;
        if(pos >= (back_-front_)){
            throw std::logic_error("error");
        }
        return array[pos+front_];
    }
    
    void pop_front(){
        // "Removes" first deque element (just change front_) **
        if(front_ == back_){
            
        }
        else{
            front_++;
        }
    }
    
    void pop_back(){
        // "Removes" last deque element (just change back_) **
        if(front_ == back_){
            
        }
        else{
            back_--;
        }
  
        
    }
    
    size_t size() const{
        // Returns the # of used items. NOTE:size_t is defined in <cstddef>
        return back_ - front_;
        
    }
    
    T* begin(){
        // Returns a pointer to the first element
        return &array[front_];
        
    }
    T* end(){
        // Returns a pointer to one position past the last element
        return &array[back_];
    }
};
