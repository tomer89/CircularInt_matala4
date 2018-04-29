

#ifndef CIRC_H
#define CIRC_H
#include <iostream>

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
        //streaming
        friend std::ostream& operator<<(std::ostream& os, CircularInt const &circ) ;
        
        //UNARY
        //postfix
        CircularInt& operator++(int);
        //prefix
        CircularInt& operator++();
        //postfix
        CircularInt& operator--(int);
        //prefix
        CircularInt& operator--();
        
        /**
         * CLASS + CLASS
         * CLASS + INT
         * INT + CLASS
         */
        friend CircularInt operator+(const CircularInt& arg1,const CircularInt& arg2);
        friend CircularInt operator+(const CircularInt& arg1,const int& int2);
        friend CircularInt operator+(const int& int1,const CircularInt& arg2);
        CircularInt& operator+();
        
        /**
         * CLASS - CLASS
         * CLASS - INT
         * INT - CLASS
         * -CLASS
         */ 
        friend CircularInt operator-(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator-(const CircularInt &c1, const int &int2);
        friend CircularInt operator-(const int &c1, const CircularInt &c2);
        friend CircularInt operator-(const CircularInt & c);
        
        /**
         * CLASS * CLASS
         * CLASS * INT
         * INT * CLASS
         * *CLASS
         */ 
        friend CircularInt operator*(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator*(const CircularInt &c1, const int &int2);
        friend CircularInt operator*(const int &c1, const CircularInt &c2);
        friend CircularInt operator*(const CircularInt & c);
        
        /**
         * CLASS/CLASS
         * INT/CLASS
         * CLASS/INT
         * 
         */ 
        friend CircularInt operator/(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator/(const CircularInt &c1, const int &int2);
        friend CircularInt operator/(const int &int1, const CircularInt &c2);
        //CircularInt operator/();
        
                
        CircularInt& operator+=(const int& rhs);
        CircularInt& operator+=(const CircularInt &i);
        
        CircularInt& operator*=(const int& i);
        CircularInt& operator*=(const CircularInt &i);
        
        CircularInt& operator/=(const int& int2);
        CircularInt& operator/=(const CircularInt other);
        
        CircularInt& operator-=(const int& rhs);
        CircularInt& operator-=(const CircularInt& rhs);
        
        /**
         * CLASS == CLASS
         * INT == CLASS
         * CLASS == INT
         */
        friend bool operator==(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator==(const int& arg1,const CircularInt& arg2);
        friend bool operator==(const CircularInt& arg1,const int& arg2);
        
        
         /**
         * CLASS != CLASS
         * INT != CLASS
         * CLASS != INT
         */
        friend bool operator!=(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator!=(const int& arg1,const CircularInt& arg2);
        friend bool operator!=(const CircularInt& arg1,const int& arg2);
        
        
        
         /**
         * CLASS < CLASS
         * INT < CLASS
         * CLASS < INT
         */
        friend bool operator<(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator<(const int& arg1,const CircularInt& arg2);
        friend bool operator<(const CircularInt& arg1,const int& arg2);
        
         /**
         * CLASS <= CLASS
         * INT <= CLASS
         * CLASS <= INT
         */
        friend bool operator<=(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator<=(const int& arg1,const CircularInt& arg2);
        friend bool operator<=(const CircularInt& arg1,const int& arg2);
        
        
         /**
         * CLASS < CLASS
         * INT < CLASS
         * CLASS < INT
         */
        friend bool operator>(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator>(const int& arg1,const CircularInt& arg2);
        friend bool operator>(const CircularInt& arg1,const int& arg2);
        
         /**
         * CLASS <= CLASS
         * INT <= CLASS
         * CLASS <= INT
         */
        friend bool operator>=(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator>=(const int& arg1,const CircularInt& arg2);
        friend bool operator>=(const CircularInt& arg1,const int& arg2);
        
        
        
        CircularInt  & operator= (const CircularInt & other);
        CircularInt  & operator= (const int & other);
        
        CircularInt(int n): CircularInt(1, 12 , n) { }            //since all the examples in the tests are hours I took liberty to assume that the conversion will be as: 1 -> 12
        /*explicit*/ operator int() const{ return current;};
        
        

    private:
        int begin,end,current;
};


#endif