#ifndef CIRC_H
#define CIRC_H

//class List;

//static int count;
class CircularInt{
    public:
        CircularInt(int begin , int end);
        CircularInt(int begin , int end , int current);
        CircularInt(const CircularInt &ci);
        
        //***getters&setters***
        int getCurrent() const;
        int getBegin() const;
        int getEnd() const;
        void setCurrent(int);
        
        
        //***overloading***
        friend std::ostream& operator<<(std::ostream& os, CircularInt const &circ) ;
        //friend CircularInt operator+=(const int& rhs);
        CircularInt& operator+=(const int& rhs);
        //postfix
        CircularInt& operator++(int);
        //prefix
        CircularInt& operator++();
        
        friend CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2);
         
        CircularInt& operator+();
        
        
        
        friend CircularInt operator-(const int &c1, const CircularInt &c2);
        friend CircularInt operator-(const CircularInt & c);
        
        CircularInt& operator*=(const int& i);
        
        friend CircularInt operator/(const int &c1, const CircularInt &c2);
        
        friend CircularInt operator/(const CircularInt &c2,const int &c1);
        
        //end void operator/(const int &c1);
        
        CircularInt operator/ ( int num);


    private:
        int begin,end,current;
};


#endif