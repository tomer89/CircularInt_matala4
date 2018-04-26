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



CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2){
    CircularInt c = CircularInt(arg1.begin , arg1.end , moduloC(arg1.begin,arg1.end,arg1.current + arg2.current));
    return c;
}

/**
 * CLASS - CLASS
 * CLASS - INT
 * INT -CLASS
 * -CLASS
 * 
 */
CircularInt operator-(const CircularInt &c1, const CircularInt &c2){
	CircularInt tmp = CircularInt(c1.getBegin() , c1.getEnd() , moduloC(c1.getBegin(),c1.getEnd(),(c1.getCurrent()- c2.current)));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator-(const CircularInt &c1, const int &int2){
	CircularInt tmp = CircularInt(c1.getBegin() , c1.getEnd() , moduloC(c1.getBegin(),c1.getEnd(),(c1.getCurrent()- int2)));
    CircularInt &c =  tmp;
	return tmp;
}

CircularInt operator-(const int &arg1, const CircularInt &arg2)
{
	CircularInt tmp = CircularInt(arg2.getBegin() , arg2.getEnd() , moduloC(arg2.getBegin(),arg2.getEnd(),(arg1 - arg2.getCurrent())));
    CircularInt &c =  tmp;
	return tmp;
}


CircularInt operator-(const CircularInt & c)
{
	//TOMER: ASK
	CircularInt tmp = CircularInt(c.getBegin() , c.getEnd() , moduloC(c.begin,c.end,( c.getEnd() - c.getCurrent())));
    CircularInt &ci =  tmp;
	return tmp;
}

//division:
CircularInt CircularInt::operator/ (int num) {
    // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    bool flag = true;
    int i = begin;
    for( ; i <= end && flag ;i++ ){
        if(i * num== current)
            flag = false;
    }
    if(!flag){
        current = i - 1;
        CircularInt c = CircularInt(begin,end,(i-1));
        return c; // call the first one
    }
    else{
        throw (std::string)"No Answer";
    }
    

}


CircularInt& CircularInt::operator*=(const int& i){
    
    int j = std::abs(i);
    CircularInt c = CircularInt(begin,end,current);
    while(j > 1){
        c.setCurrent((c+c).getCurrent());               
        j--;
    }
    if(j == 0){
        c.setCurrent(0);
    }
    
    setCurrent(moduloC(begin,end,c.getCurrent()));
    return *this; 
}




bool operator==(const CircularInt& arg1,const CircularInt& arg2){
    if(arg1.begin == arg2.begin && arg1.end == arg2.end && arg1.current == arg2.current)
        return true;
    else
        return false;
}

bool operator==(const int& arg1,const CircularInt& arg2){
    if(arg2.current - arg2.begin + 1 == arg1 )
        return true;
    else
        return false;
}

bool operator==(const CircularInt& arg1,const int& arg2){
    if(arg1.current - arg1.begin + 1 == arg2)
        return true;
    else
        return false;
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

