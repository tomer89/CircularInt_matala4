#include <iostream>

#include "CircularInt.hpp"

int moduloC(int begin,int end,int val){
    int result = val%(end - begin + 1) + (begin - 1);
    if(result < 0){
        result += end;
    }
    return result;
}


//***constructors***
CircularInt::CircularInt(int b , int e){
    begin = b;
    end = e;
    
    current = b;
}

CircularInt::CircularInt(int b , int e ,int c){
    begin = b;
    end = e;
    
    current = c;
}


CircularInt::CircularInt(const CircularInt &ci){
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
    setCurrent(moduloC(begin,end,(this->getCurrent()+rhs)));
    return *this;
}

CircularInt& CircularInt::operator++(){
    setCurrent((this->getCurrent() + 1)%end);
    return *this;
}

//from https://stackoverflow.com/questions/3846296/how-to-overload-the-operator-in-two-different-ways-for-postfix-a-and-prefix?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
CircularInt& CircularInt::operator++(int i){
    CircularInt result(*this);   // make a copy for result 
    ++(*this);                   // Now use the prefix version to do the work
    return result;  
}




/*CircularInt& CircularInt::operator-(){
    setCurrent((end-current)%end);
    return *this;
}*/



CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2){
    CircularInt c = CircularInt(arg1.begin , arg1.end , moduloC(arg1.begin,arg1.end,arg1.current + arg2.current));
    return c;
}



//tomer - TODO this is not working good

CircularInt operator-(const int &arg1, const CircularInt &arg2)
{
	// use the Cents constructor and operator-(int, int)
	// we can access m_cents directly because this is a friend function
	//int y;
	CircularInt tmp = CircularInt(arg2.getBegin() , arg2.getEnd() , moduloC(arg2.getBegin(),arg2.getEnd(),(arg1 - arg2.getCurrent())));
    CircularInt &c =  tmp;
	
	return tmp;
}

CircularInt operator-(const CircularInt & c)
{
    //CircularInt v;
	// use the Cents constructor and operator-(int, int)
	// we can access m_cents directly because this is a friend function
	//TOMER: ASK
	CircularInt tmp = CircularInt(c.getBegin() , c.getEnd() , moduloC(c.begin,c.end,( c.getEnd() - c.getCurrent())));
    CircularInt &ci =  tmp;
	return tmp;
}

//division:
CircularInt* CircularInt::operator/ (int num) {
    CircularInt* c = this;
    return c; // call the first one
}

CircularInt& CircularInt::operator*=(const int& i){
    int j = i;
    CircularInt c = CircularInt(begin,end,current);;
    while(j > 1){
        //CircularInt c = CircularInt(begin,end,current);
        CircularInt c = c+c;
        
        j--;
    }
    if(j == 0){
        setCurrent(0);
    }
    //what to do with j < 0
    setCurrent(added.getCurrent());
    return *this; 
}




//getters:
int CircularInt::getBegin() const{
    return begin;
}
int CircularInt::getEnd() const{
    return end;
}

int CircularInt::getCurrent() const{
    return current;
}

void CircularInt::setCurrent(int newV) {
    current = newV;
}

