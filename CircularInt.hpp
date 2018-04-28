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
        //postfix
        CircularInt& operator++(int);
        //prefix
        CircularInt& operator++();
        
        
        
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
        
        
        
        CircularInt& operator+=(const int& rhs);
        CircularInt& operator+=(const CircularInt &i);
        
        CircularInt& operator*=(const int& i);
        CircularInt& operator*=(const CircularInt &i);
        
        CircularInt& operator/=(const int& int2);
        CircularInt& operator/=(const CircularInt other);
        
        /**
         * CLASS/CLASS
         * INT/CLASS
         * CLASS/INT
         * 
         */ 
        friend CircularInt operator/(const CircularInt &c1, const CircularInt &c2);
        friend CircularInt operator/(const CircularInt &c1, const int &int2);
        friend CircularInt operator/(const int &int1, const CircularInt &c2);
        //friend CircularInt operator/(const CircularInt & c);
        /*
        friend CircularInt operator/(const int &c1, const CircularInt &c2);
        friend CircularInt operator/(const CircularInt &c2,const int &c1);
        
        //end void operator/(const int &c1);
        
        CircularInt operator/ ( int num);
*/
        /**
         * CLASS == CLASS
         * INT == CLASS
         * CLASS == INT
         */
        friend bool operator==(const CircularInt& arg1,const CircularInt& arg2);
        friend bool operator==(const int& arg1,const CircularInt& arg2);
        friend bool operator==(const CircularInt& arg1,const int& arg2);
        
        
        
        CircularInt  & operator= (const CircularInt & other);
        
        

    private:
        int begin,end,current;
};


#endif