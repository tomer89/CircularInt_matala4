#include <iostream>

#include "CircularInt.hpp"


//***constructors***
CircularInt::CircularInt(int b , int e){
    begin = b;
    end = e;
    
    current = b;
}

CircularInt(const CircularInt &ci){
    begin = ci.begin;
    end = ci.begin;
    
    current = ci.current;
}


/*std::ostream &operator<<(std::ostream &os, CircularInt const &circ) { 
    return os << circ.getBegin();
}*/


std::ostream& operator<<(std::ostream& os, CircularInt const &circ)  
{  
    os << circ.getCurrent();  
    return os;  
} 



    
CircularInt& CircularInt::operator+=(const int& rhs){
    this->setCurrent(this->getCurrent()+rhs);
    return *this;
}

CircularInt& CircularInt::operator++(){
    this->setCurrent(this->getCurrent() + 1);
    return *this;
}

//from https://stackoverflow.com/questions/3846296/how-to-overload-the-operator-in-two-different-ways-for-postfix-a-and-prefix?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
CircularInt& CircularInt::operator++(int i){
    CircularInt result(*this);   // make a copy for result
    ++(*this);              // Now use the prefix version to do the work
    return result;  
}


//getters:
int CircularInt::getCurrent() const{
    return current;
}

void CircularInt::setCurrent(int newV) {
    current = newV;
}