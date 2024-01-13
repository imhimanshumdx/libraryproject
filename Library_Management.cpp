#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Enumerated type for different book genres
enum class BookType
{
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

// Mapping between strings and BookType enum values
struct BookTypeMapping
{
    const char *str;
    BookType type;
};

// Array of mappings for converting strings to BookType enum values
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
    {"health", BookType::Health}};

// Function to convert a string to a BookType enum value
BookType stringToBookType(const std::string &str)
{
    for (const auto &mapping : bookTypeMappings)
    {
        if (str == mapping.str)
        {
            return mapping.type;
        }
    }
    return BookType::Unknown;
}

// Decleration for book class
class Book;

// Class representing a Date with day, month, and year components
class Date
{
private:
    // Day of the month
    int day;
    // Month of the year
    int month;
    // Year
    int year;

public:
    // Constructor to initialize the Date object with given day, month, and year
    Date(int dd, int mm, int yy)
    {
        day = dd;
        month = mm;
        year = yy;
    }

    // Method to set the due date by adding 3 days to the current date
    void setDueDate(Date &date)
    {
        date.day = date.day + 3;
        date.month = date.month;
        date.year = date.year;

        // Check if the updated date exceeds valid month or day limits
        if (date.month > 12 || date.day > 31)
        {
            fixDate(date);
        }
    }

    // Method to fix the date if it exceeds valid month or day limits
    void fixDate(Date &date)
    {
        // Adjust day and month to stay within valid limits
        if (date.day > 31)
        {
            date.day = date.day - 31;
            date.month = date.month + 1;
        }
        // Adjust month and increment year if needed
        if (date.month > 12)
        {
            date.year = date.year++;
        }
    }

    // Method to get the day component of a Date
    int getDay(Date date)
    {
        return date.day;
    }

    // Method to get the month component of a Date
    int getMonth(Date date)
    {
        return date.month;
    }

    // Method to get the year component of a Date
    int getYear(Date date)
    {
        return date.year;
    }
};

// Class representing a basic Person with name, address, and email information
class Person
{
protected:
    // Name of the person
    string name;
    // Address of the person
    string address;
    // Email address of the person
    string email;

public:
    // Setter method to update the name of the person
    void setName(string &newName)
    {
        name = newName;
    }

    // Setter method to update the email address of the person
    void setEmail(string &newEmail)
    {
        email = newEmail;
    }

    // Setter method to update the address of the person
    void setAddress(string &newAddress)
    {
        address = newAddress;
    }

    // Getter method to retrieve the address of the person
    string getAddress()
    {
        return address;
    }

    // Getter method to retrieve the email address of the person
    string getEmail()
    {
        return email;
    }

    // Getter method to retrieve the name of the person
    string getName()
    {
        return name;
    }
};

// Class representing a library member, inheriting from the Person class
class Member : public Person
{
private:
    // Unique identifier for the member
    int memberID;
    // Vector to store books currently loaned by the member
    vector<Book> booksLoaned;

public:
    // Constructor to initialize a Member object with member ID, name, address, and email
    Member(int memID, string newName, string newAddress, string newEmail)
    {
        memberID = memID;
        name = newName;
        address = newAddress;
        email = newEmail;
    }

    // Getter method to retrieve the member's unique ID
    int getMemberID()
    {
        return memberID;
    }

    // Getter method to retrieve the vector of books currently borrowed by the member
    vector<Book> &getBooksBorrowed()
    {
        return booksLoaned;
    }

    // Method to add a book to the member's list of borrowed books
    void setBooksBorrowed(Book &book)
    {
        booksLoaned.push_back(book);
    }
};

// Class representing a book in the library
class Book
{
private:
    // Unique identifier for the book
    int bookID;
    // Title of the book
    string bookName;
    // First name of the book's author
    string authorFirstName;
    // Last name of the book's author
    string authorLastName;
    // Genre or type of the book
    BookType bookType;
    // Due date for the book (default set to December 12, 2025)
    Date dueDate = Date(12, 12, 2025);
    // Member who currently has the book on loan
    Member *borrower;
    // Number of pages in the book
    int pageCount;

public:
    // Constructor to initialize a Book object with specified attributes
    Book(int id, string name, int pages, string firstName, string lastName, BookType type)
    {
        bookID = id;
        bookName = name;
        authorFirstName = firstName;
        authorLastName = lastName;
        bookType = type;
        pageCount = pages;
    }

    // Setter method to update the page count of the book
    void setPageCount(int count)
    {
        pageCount = count;
    }

    // Getter method to retrieve the page count of the book
    int getPageCount()
    {
        return pageCount;
    }

    // Getter method to retrieve the unique ID of the book
    int getBookID()
    {
        return bookID;
    }

    // Getter method to retrieve the title of the book
    string getBookName()
    {
        return bookName;
    }

    // Getter method to retrieve the first name of the book's author
    string getAuthorFirstName()
    {
        return authorFirstName;
    }

    // Getter method to retrieve the last name of the book's author
    string getAuthorLastName()
    {
        return authorLastName;
    }

    // Getter method to retrieve the due date of the book
    Date getDueDate()
    {
        return dueDate;
    }

    // Setter method to update the due date of the book
    void setDueDate(Date &newDueDate)
    {
        dueDate = newDueDate;
    }

    // Method to mark the book as returned (no borrower)
    void returnBook()
    {
        borrower = nullptr;
    }

    // Method to borrow the book by a member, setting the borrower and due date
    void borrowBook(Member *newBorrower, Date &newDueDate)
    {
        borrower = newBorrower;
        dueDate = newDueDate;
    }
};

// Class representing a librarian, inheriting from the Person class
class Librarian : public Person
{
private:
    // Unique identifier for the librarian
    int staffID;
    // Salary of the librarian
    int salary;
    // Vector to store library members
    vector<Member> members;
    // Vector to store library books
    vector<Book> books;

    // Private helper method to find a member in the library by their unique ID.
    // Returns a pointer to the found member or nullptr if not found.
    Member *findMemberById(int memberID)
    {
        for (auto &member : members)
        {
            if (member.getMemberID() == memberID)
            {
                return &member;
            }
        }
        return nullptr; // Member not found
    }

    // Private helper method to find a book in the library by its unique ID.
    // Returns a pointer to the found book or nullptr if not found.
    Book *findBookById(int bookID)
    {
        for (auto &book : books)
        {
            if (book.getBookID() == bookID)
            {
                return &book;
            }
        }
        return nullptr; // Book not found
    }

public:
    // Constructor to initialize a Librarian object with staff ID, name, address, email, and salary
    Librarian(int id, string newName, string newAddress, string newEmail, int newSalary)
    {
        staffID = id;
        name = newName;
        address = newAddress;
        email = newEmail;
        salary = newSalary;
        // Reads books information from a CSV file during initialization
        readBooksFromCSV("library_books.csv");
    }

    // Reads book information from a CSV file and populates the library's book collection.
    // Parameters:
    //   filename - The name of the CSV file to read.
    void readBooksFromCSV(const string &filename)
    {
        ifstream file(filename);

        // Check if the file is successfully opened
        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line); // Read and discard the header line

        // Process each line in the CSV file
        while (getline(file, line))
        {
            istringstream iss(line);
            string token;
            vector<string> tokens;

            // Tokenize the line using ',' as the delimiter
            while (getline(iss, token, ','))
            {
                tokens.push_back(token);
            }

            // Check if the line contains the expected number of fields
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
                    // Convert the string to BookType enumeration
                    type = static_cast<BookType>(stoi(tokens[5]));
                }
                catch (const std::exception &e)
                {
                    cout << "Error converting string to integer for BookType: " << e.what() << endl;
                }

                // Create a new Book object and add it to the library's collection
                Book newBook(id, name, pageCount, firstName, lastName, type);
                books.push_back(newBook);
            }
            else
            {
                cout << "Error reading line from file: " << line << endl;
            }
        }

        file.close(); // Close the file after reading
    }

    // Getter method to retrieve the vector of books in the library
    vector<Book> getBooks() const
    {
        return books;
    }

    // Getter method to retrieve the librarian's unique ID
    int getStaffID()
    {
        return staffID;
    }

    // Getter method to retrieve the librarian's salary
    int getSalary()
    {
        return salary;
    }

    // Setter method to update the librarian's unique ID
    void setStaffID(int newStaffID)
    {
        staffID = newStaffID;
    }

    // Setter method to update the librarian's salary
    void setSalary(int newSalary)
    {
        salary = newSalary;
    }

    // Adds a new member to the library's collection.
    void addMember()
    {
        // Prompt the user for member information
        int memberID;
        string memberName, memberAddress, memberEmail;

        cout << "Enter Member ID: ";
        cin >> memberID;
        cin.ignore(); // Ignore the newline character in the input buffer

        cout << "Enter Member Name: ";
        getline(cin, memberName);

        cout << "Enter Member Address: ";
        getline(cin, memberAddress);

        cout << "Enter Member Email: ";
        getline(cin, memberEmail);

        // Create a new Member object with the provided information
        Member newMember(memberID, memberName, memberAddress, memberEmail);

        // Add the new member to the library's collection
        members.push_back(newMember);

        // Display a success message along with the member's information
        cout << "Member Added Successfully" << endl;
        cout << "Member ID: " << newMember.getMemberID();
        cout << "   Name: " << newMember.getName();
    }

    // Issues a book to a member by updating the book's borrower and due date information.
    void issueBook(int memberID, int bookID)
    {
        // Find the member and book using their respective IDs
        Member *borrower = findMemberById(memberID);
        Book *book = findBookById(bookID);

        // Check if both the member and book exist
        if (borrower != nullptr && book != nullptr)
        {
            // Set the current date as the issue date
            Date currentDate = Date(12, 12, 2025);

            // Set the due date by adding 3 days to the current date
            Date dueDate = currentDate;
            dueDate.setDueDate(dueDate);

            // Update the book's borrower and due date
            book->borrowBook(borrower, dueDate);

            // Add the borrowed book to the member's list of borrowed books
            borrower->setBooksBorrowed(*book);

            // Display success message along with book and borrower information
            cout << "Book Issued Successfully:" << endl;
            cout << "Book ID: " << book->getBookID();
            cout << "    Book Name: " << book->getBookName();
            cout << "    Borrower: " << borrower->getName() << endl;
        }
        else
        {
            // Display an error message if the member or book is not found
            cout << "Member or Book not found with the provided IDs." << endl;
        }
    }

    // Returns a borrowed book, updating both the member's list of borrowed books and the book's borrower information.
    void returnBook(int memberID, int bookID)
    {
        // Find the member and book using their respective IDs
        Member *borrower = findMemberById(memberID);
        Book *book = findBookById(bookID);

        // Check if both the member and book exist
        if (borrower != nullptr && book != nullptr)
        {
            // Get the list of books borrowed by the member
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();
            bool bookFound = false;

            // Iterate through the borrowed books to find the one being returned
            for (auto it = booksLoaned.begin(); it != booksLoaned.end(); ++it)
            {
                if (it->getBookID() == bookID)
                {
                    // Remove the book from the member's list of borrowed books
                    booksLoaned.erase(it);

                    // Set the book's borrower to null, indicating it has been returned
                    book->returnBook();

                    // Display success message along with book and borrower information
                    cout << "Book Returned Successfully:" << endl;
                    cout << "Book ID: " << book->getBookID();
                    cout << "    Book Name: " << book->getBookName();
                    cout << "    Returned by: " << borrower->getName() << endl;

                    bookFound = true;
                    break;
                }
            }

            // Display an error message if the book is not found in the member's borrowed list
            if (!bookFound)
            {
                cout << "Book not found in the member's borrowed list." << endl;
            }
        }
        else
        {
            // Display an error message if the member or book is not found
            cout << "Member or Book not found with the provided IDs." << endl;
        }
    }

    // Displays the list of books borrowed by a member identified by their unique ID.
    void displayBorrowedBooks(int memberID)
    {
        // Find the member using their ID
        Member *borrower = findMemberById(memberID);

        // Check if the member exists
        if (borrower != nullptr)
        {
            // Get the list of books borrowed by the member
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();

            // Display header with member ID
            cout << "Borrowed Books by Member ID " << borrower->getMemberID() << ":" << endl;

            // Check if the member has borrowed any books
            if (!booksLoaned.empty())
            {
                // Iterate through the borrowed books and display their IDs and names
                for (auto &book : booksLoaned)
                {
                    cout << "Book ID: " << book.getBookID() << ", Book Name: " << book.getBookName() << endl;
                }
            }
            else
            {
                // Display a message if the member has not borrowed any books
                cout << "No books borrowed by this member." << endl;
            }
        }
        else
        {
            // Display an error message if the member is not found
            cout << "Member not found with the provided ID." << endl;
        }
    }

    // Calculates and displays the fine for overdue books associated with a member identified by their unique ID.
    void calcFine(int memberID)
    {
        // Find the member using their ID
        Member *borrower = findMemberById(memberID);

        // Check if the member exists
        if (borrower != nullptr)
        {
            // Get the list of books borrowed by the member
            vector<Book> &booksLoaned = borrower->getBooksBorrowed();
            int totalFine = 0;

            // Iterate through the borrowed books
            for (auto &book : booksLoaned)
            {
                // Get the current date
                Date currentDate = Date(12, 12, 2025);
                // Get the due date of the book
                Date dueDate = book.getDueDate();

                // Check if the book is overdue
                if (currentDate.getDay(currentDate) > dueDate.getDay(dueDate) ||
                    currentDate.getMonth(currentDate) > dueDate.getMonth(dueDate) ||
                    currentDate.getYear(currentDate) > dueDate.getYear(dueDate))
                {
                    // Calculate the fine based on the number of overdue days (assuming 1 unit per day)
                    int fineDays = (currentDate.getYear(currentDate) - dueDate.getYear(dueDate)) * 365 +
                                   (currentDate.getMonth(currentDate) - dueDate.getMonth(dueDate)) * 30 +
                                   (currentDate.getDay(currentDate) - dueDate.getDay(dueDate));
                    int fine = fineDays * 1; // Assuming a fine of 1 unit per day
                    cout << "Fine for Book ID " << book.getBookID() << ": " << fine << " units" << endl;
                    totalFine += fine;
                }
            }

            // Display the total fine for the member
            if (totalFine > 0)
            {
                cout << "Total Fine for Member ID " << borrower->getMemberID() << ": " << totalFine << " units" << endl;
            }
            else
            {
                // Display a message if there are no fines for the member
                cout << "No fines for this member." << endl;
            }
        }
        else
        {
            // Display an error message if the member is not found
            cout << "Member not found with the provided ID." << endl;
        }
    }
};

// Main function representing the Library Management System menu and interactions.
int main()
{
    // Create a Librarian object with initial information
    Librarian librarian(1, "Librarian", "Librarian", "librarian@email.com", 50000);

    // Variable to store the user's menu choice
    int choice;

    // Display the menu and handle user input until the user chooses to exit
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

        // Get user input for menu choice
        cin >> choice;

        // Switch statement to handle different menu choices
        switch (choice)
        {
        case 1:
            // Call the Librarian's method to add a new member
            librarian.addMember();
            break;

        case 2:
            // Get input for Member ID and Book ID, then call Librarian's method to issue a book
            int memberID, bookID;
            cout << "Enter Member ID: ";
            cin >> memberID;
            cout << "Enter Book ID: ";
            cin >> bookID;
            librarian.issueBook(memberID, bookID);
            break;

        case 3:
            // Get input for Member ID and Book ID, then call Librarian's method to return a book
            cout << "Enter Member ID: ";
            cin >> memberID;
            cout << "Enter Book ID: ";
            cin >> bookID;
            librarian.returnBook(memberID, bookID);
            break;

        case 4:
            // Get input for Member ID, then call Librarian's method to display borrowed books by the member
            cout << "Enter Member ID: ";
            cin >> memberID;
            librarian.displayBorrowedBooks(memberID);
            break;

        case 6:
            // Display information for all books in the library
            for (auto &book : librarian.getBooks())
            {
                cout << "Book ID: " << book.getBookID() << ", Book Name: " << book.getBookName() << ", Author: "
                     << book.getAuthorFirstName() << " " << book.getAuthorLastName() << endl;
            }
            break;

        case 5:
            // Get input for Member ID, then call Librarian's method to calculate fines for the member
            cout << "Enter Member ID: ";
            cin >> memberID;
            librarian.calcFine(memberID);
            break;

        case 7:
            // Exit the program
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            // Display an error message for an invalid choice
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            break;
        }

    } while (choice != 7); // Continue the loop until the user chooses to exit

    return 0; // Return 0 to indicate successful program execution
}
