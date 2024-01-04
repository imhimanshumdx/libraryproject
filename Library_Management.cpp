#include<iostream>
#include <vector>
using namespace std;

class Book;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int dd,int mm,int yy) 
    {
        day = dd;
        month = mm;
        year = yy;
    }
    void setDueDate(Date date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }

    Date getDueDate()
    {
        return Date(this->day,this->month,this->year);
    }
    
};

class Person {

protected:

    string name;
    string address;
    string email;

public:
    
    void setName (const string& newName) {
        name = newName;
    }

    void setEmail (const string& newEmail) {
        email = newEmail;
    }

    void setAddress (const string& newAddress) {
        address = newAddress;
    }

    string getAddress() const {
        return address;
    }

    string getEmail() const {
        return email;
    }

    string getName() const {
        return name;
    }

    

};

class Member : public Person {
    
private:
    int memberID;
    //std::vector<Book> booksLoaned;

public:
    Member(int memID, string newName, string newAddress, string newEmail)
    {
        memberID = memID;
        name = newName;
        address = newAddress;
        email = newEmail;
    }
};




int main()
{
    return 0;
}