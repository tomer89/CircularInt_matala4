#ifndef CIRC_H
#define CIRC_H

//class List;

//static int count;
class CircularInt{
    public:
        CircularInt(int begin , int end);
        CircularInt(const CircularInt &ci);
        
        //***getters&setters***
        int getCurrent() const;
        void setCurrent(int);
        
        
        //***overloading***
        friend std::ostream& operator<<(std::ostream& os, CircularInt const &circ) ;
        //friend CircularInt operator+=(const int& rhs);
        CircularInt& operator+=(const int& rhs);
        //postfix
        CircularInt& operator++(int);
        //prefix
        CircularInt& operator++();
    private:
        int begin,end,current;
};


#endif