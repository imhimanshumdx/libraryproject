#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum class BookType {
    Unknown = -1,  
    Guide = 0,
    Journals = 1,
    Diaries = 2,
    Drama = 3,
    ScienceFiction = 4,
    Art = 5,
    Romance = 6,
    History = 7,
    ActionAndAdventure = 8,
    Satire = 9,
    Mystery = 10,
    Fantasy = 11,
    Horror = 12,
    Comics = 13,
    Science = 14,
    Health = 15
};

struct BookTypeMapping {
    const char* str;
    BookType type;
};

BookTypeMapping bookTypeMappings[] = {
    {"guide", BookType::Guide},
    {"journals", BookType::Journals},
    {"diaries", BookType::Diaries},
    {"drama", BookType::Drama},
    {"science fiction", BookType::ScienceFiction},
    {"art", BookType::Art},
    {"romance", BookType::Romance},
    {"history", BookType::History},
    {"action and adventure", BookType::ActionAndAdventure},
    {"satire", BookType::Satire},
    {"mystery", BookType::Mystery},
    {"fantasy", BookType::Fantasy},
    {"horror", BookType::Horror},
    {"comics", BookType::Comics},
    {"science", BookType::Science},
    {"health", BookType::Health}
};

BookType stringToBookType(const std::string& str) {
    for (const auto& mapping : bookTypeMappings) {
        if (str == mapping.str) {
            return mapping.type;
        }
    }
    return BookType::Unknown;
}

class Book;

class Date
{

private:
    int day;
    int month;
    int year;

public:
    Date(int dd, int mm, int yy)
    {
        day = dd;
        month = mm;
        year = yy;
    }

    void setDueDate(Date &date)
    {
        date.day = date.day + 3;
        date.month = date.month;
        date.year = date.year;
        if (date.month > 12 || date.day > 31)
        {
            fixDate(date);
        }
    }

    void fixDate(Date &date)
    {
        if (date.day > 31)
        {
            date.day = date.day - 31;
            date.month = date.month + 1;
        }
        if (date.month > 12)
        {
            date.year = date.year++;
        }
    }

    int getDay(Date date)
    {
        return date.day;
    }

    int getMonth(Date date)
    {
        return date.month;
    }

    int getYear(Date date)
    {
        return date.year;
    }
};

class Person
{

protected:
    string name;
    string address;
    string email;

public:
    void setName(string &newName)
    {
        name = newName;
    }

    void setEmail(string &newEmail)
    {
        email = newEmail;
    }

    void setAddress(string &newAddress)
    {
        address = newAddress;
    }

    string getAddress()
    {
        return address;
    }

    string getEmail()
    {
        return email;
    }

    string getName()
    {
        return name;
    }
};

class Member : public Person
{

private:
    int memberID;
    vector<Book> booksLoaned;

public:
    Member(int memID, string newName, string newAddress, string newEmail)
    {
        memberID = memID;
        name = newName;
        address = newAddress;
        email = newEmail;
    }
    int getMemberID()
    {
        return memberID;
    }

    vector<Book> &getBooksBorrowed()
    {
        return booksLoaned;
    }

    void setBooksBorrowed(Book &book)
    {
        booksLoaned.push_back(book);
    }
};

class Book
{
private:
    int bookID;
    string bookName;
    string authorFirstName;
    string authorLastName;
    BookType bookType;
    Date dueDate = Date(12, 12, 2025);
    Member *borrower;
    int pageCount;

public:
    Book(int id, string name, int pages, string firstName, string lastName, BookType type)
    {
        bookID = id;
        bookName = name;
        authorFirstName = firstName;
        authorLastName = lastName;
        bookType = type;
        pageCount = pages;
    }

    void setPageCount(int count)
    {
        pageCount = count;
    }

    int getPageCount()
    {
        return pageCount;
    }

    int getBookID()
    {
        return bookID;
    }

    string getBookName()
    {
        return bookName;
    }

    string getAuthorFirstName()
    {
        return authorFirstName;
    }

    string getAuthorLastName()
    {
        return authorLastName;
    }

    Date getDueDate()
    {
        return dueDate;
    }

    void setDueDate(Date &newDueDate)
    {
        dueDate = newDueDate;
    }

    void returnBook()
    {
        borrower = nullptr;
    }

    void borrowBook(Member *newBorrower, Date &newDueDate)
    {
        borrower = newBorrower;
        dueDate = newDueDate;
    }
};

class Librarian : public Person
{
private:
    int staffID;
    int salary;
    vector<Member> members;
    vector<Book> books;
    Member *findMemberById(int memberID)
    {
        for (auto &member : members)
        {
            if (member.getMemberID() == memberID)
            {
                return &member;
            }
        }
        return nullptr;
    }

    Book *findBookById(int bookID)
    {
        for (auto &book : books)
        {
            if (book.getBookID() == bookID)
            {
                return &book;
            }
        }
        return nullptr;
    }

public:
    Librarian(int id, string newName, string newAddress, string newEmail, int newSalary)
    {
        staffID = id;
        name = newName;
        address = newAddress;
        email = newEmail;
        salary = newSalary;
        readBooksFromCSV("library_books.csv");
    }

    void readBooksFromCSV(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line))
        {
            istringstream iss(line);
            string token;
            vector<string> tokens;

            while (getline(iss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() == 6)
            {
                int id = stoi(tokens[0]);
                string name = tokens[1];
                int pageCount = stoi(tokens[2]);
                string firstName = tokens[3];
                string lastName = tokens[4];
                BookType type;
                try
                {
                    BookType type = static_cast<BookType>(stoi(tokens[5]));
                }
                catch (const std::exception &e)
                {
                    cout << "Error converting string to integer for BookType: " << e.what() << endl;
                }

                Book newBook(id, name, pageCount, firstName, lastName, type);
                books.push_back(newBook);
            }
            else
            {
                cout << "Error reading line from file: " << line << endl;
            }
        }

        file.close();
    }

    vector<Book> getBooks() const
    {
        return books;
    }

    int getStaffID()
    {
        return staffID;
    }

    int getSalary()
    {
        return salary;
    }

    void setStaffID(int newStaffID)
    {
        staffID = newStaffID;
    }

    void setSalary(int newSalary)
    {
        salary = newSalary;
    }

    void addMember()
    {
        int memberID;
        string memberName, memberAddress, memberEmail;
        cout << "Enter Member ID: ";
        cin >> memberID;
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, memberName);
        cout << "Enter Member Address: ";
        getline(cin, memberAddress);
        cout << "Enter Member Email: ";
        getline(cin, memberEmail);

        Member newMember(memberID, memberName, memberAddress, memberEmail);
        members.push_back(newMember);

        cout << "Member Added Successfully" << endl;
        cout << "Member ID: " << newMember.getMemberID();
        cout << "   Name: " << newMember.getName();
    }

    void issueBook(int memberID, int bookID)
    {
        Member *borrower = findMemberById(memberID);
        Book *book = findBookById(bookID);

        if (borrower != nullptr && book != nullptr)
        {
            Date currentDate = Date(12, 12, 2025);
            Date dueDate = currentDate;
            dueDate.setDueDate(dueDate);
            book->borrowBook(borrower, dueDate);
            borrower->setBooksBorrowed(*book);
            cout << "Book Issued Successfully:" << endl;
            cout << "Book ID: " << book->getBookID();
            cout << "    Book Name: " << book->getBookName();
            cout << "    Borrower: " << borrower->getName() << endl;
        }
        else
        {
            cout << "Member or Book not found with the provided IDs." << endl;
        }
    }

    void returnBook(int memberID, int bookID)
    {
        Member *borrower = findMemberById(memberID);
        Book *book = findBookById(bookID);

        if (borrower != nullptr && book != nullptr)
        {
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();
            bool bookFound = false;

            for (auto it = booksLoaned.begin(); it != booksLoaned.end(); ++it)
            {
                if (it->getBookID() == bookID)
                {
                    booksLoaned.erase(it);

                    book->returnBook();

                    cout << "Book Returned Successfully:" << endl;
                    cout << "Book ID: " << book->getBookID();
                    cout << "    Book Name: " << book->getBookName();
                    cout << "    Returned by: " << borrower->getName() << endl;

                    bookFound = true;
                    break;
                }
            }

            if (!bookFound)
            {
                cout << "Book not found in the member's borrowed list." << endl;
            }
        }
        else
        {
            cout << "Member or Book not found with the provided IDs." << endl;
        }
    }

    void displayBorrowedBooks(int memberID)
    {
        Member *borrower = findMemberById(memberID);

        if (borrower != nullptr)
        {
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();

            cout << "Borrowed Books by Member ID " << borrower->getMemberID() << ":" << endl;

            if (!booksLoaned.empty())
            {
                for (auto &book : booksLoaned)
                {
                    cout << "Book ID: " << book.getBookID() << ", Book Name: " << book.getBookName() << endl;
                }
            }
            else
            {
                cout << "No books borrowed by this member." << endl;
            }
        }
        else
        {
            cout << "Member not found with the provided ID." << endl;
        }
    }

    void calcFine(int memberID)
    {
        Member *borrower = findMemberById(memberID);

        if (borrower != nullptr)
        {
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();
            int totalFine = 0;

            for (auto &book : booksLoaned)
            {
                Date currentDate = Date(12, 12, 2025);
                Date dueDate = book.getDueDate();

                if (currentDate.getDay(currentDate) > dueDate.getDay(dueDate) || currentDate.getMonth(currentDate) > dueDate.getMonth(dueDate) || currentDate.getYear(currentDate) > dueDate.getYear(dueDate))
                {
                    int fineDays = (currentDate.getYear(currentDate) - dueDate.getYear(dueDate)) * 365 + (currentDate.getMonth(currentDate) - dueDate.getMonth(dueDate)) * 30 + (currentDate.getDay(currentDate) - dueDate.getDay(dueDate));
                    int fine = fineDays * 1;
                    cout << "Fine for Book ID " << book.getBookID() << ": " << fine << " units" << endl;
                    totalFine += fine;
                }
            }

            if (totalFine > 0)
            {
                cout << "Total Fine for Member ID " << borrower->getMemberID() << ": " << totalFine << " units" << endl;
            }
            else
            {
                cout << "No fines for this member." << endl;
            }
        }
        else
        {
            cout << "Member not found with the provided ID." << endl;
        }
    }
};

int main()
{
    Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);

    int choice;
    do
    {

        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Member\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Borrowed Books\n";
        cout << "5. Calculate Fine\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            librarian.addMember();
            break;

        case 2:
            int memberID, bookID;
            cout << "Enter Member ID: ";
            cin >> memberID;
            cout << "Enter Book ID: ";
            cin >> bookID;
            librarian.issueBook(memberID, bookID);
            break;

        case 3:
            cout << "Enter Member ID: ";
            cin >> memberID;
            cout << "Enter Book ID: ";
            cin >> bookID;
            librarian.returnBook(memberID, bookID);
            break;

        case 4:
            cout << "Enter Member ID: ";
            cin >> memberID;
            librarian.displayBorrowedBooks(memberID);
            break;

        case 6:
            for (auto &book : librarian.getBooks())
            {
                cout << "Book ID: " << book.getBookID() << ", Book Name: " << book.getBookName() << ", Author: "
                     << book.getAuthorFirstName() << " " << book.getAuthorLastName() << endl;
            }
            break;

        case 5:
            cout << "Enter Member ID: ";
            cin >> memberID;
            librarian.calcFine(memberID);
            break;

        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            break;
        }

    } while (choice != 7);

    return 0;
}
