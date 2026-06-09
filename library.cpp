#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int bookId;
    string title;
    string author;
    bool isIssued;
    Book* next;
};

Book* head = NULL;

// Add Book
void addBook()
{
    Book* newBook = new Book();

    cout << "\nEnter Book ID: ";
    cin >> newBook->bookId;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, newBook->title);

    cout << "Enter Author Name: ";
    getline(cin, newBook->author);

    newBook->isIssued = false;
    newBook->next = head;
    head = newBook;

    cout << "Book Added Successfully!\n";
}

// Display Books
void displayBooks()
{
    if (head == NULL)
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    Book* temp = head;

    cout << "\n===== BOOK LIST =====\n";

    while (temp != NULL)
    {
        cout << "Book ID : " << temp->bookId << endl;
        cout << "Title   : " << temp->title << endl;
        cout << "Author  : " << temp->author << endl;
        cout << "Status  : "
             << (temp->isIssued ? "Issued" : "Available")
             << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

// Search Book
void searchBook()
{
    int id;

    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            cout << "\nBook Found!\n";
            cout << "Title  : " << temp->title << endl;
            cout << "Author : " << temp->author << endl;
            cout << "Status : "
                 << (temp->isIssued ? "Issued" : "Available")
                 << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Delete Book
void deleteBook()
{
    int id;

    cout << "\nEnter Book ID to Delete: ";
    cin >> id;

    Book* temp = head;
    Book* prev = NULL;

    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;

            cout << "Book Deleted Successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Issue Book
void issueBook()
{
    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            if (temp->isIssued)
            {
                cout << "Book Already Issued!\n";
            }
            else
            {
                temp->isIssued = true;
                cout << "Book Issued Successfully!\n";
            }
            return;
        }

        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

// Return Book
void returnBook()
{
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            if (!temp->isIssued)
            {
                cout << "Book Was Not Issued!\n";
            }
            else
            {
                temp->isIssued = false;
                cout << "Book Returned Successfully!\n";
            }
            return;
        }

        temp = temp->next;
    }

    cout << "Book Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                deleteBook();
                break;

            case 5:
                issueBook();
                break;

            case 6:
                returnBook();
                break;

            case 7:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}