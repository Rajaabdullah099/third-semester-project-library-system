#include<iostream>
#include<string>

using namespace std;

int bookID[100];
string title[100];
string author[100];
bool issued[100];

int totalBooks = 0;

void addBook()
{
    cout<<"\nEnter Book ID : ";
    cin>>bookID[totalBooks];

    cin.ignore();

    cout<<"Enter Book Title : ";
    getline(cin,title[totalBooks]);

    cout<<"Enter Author Name : ";
    getline(cin,author[totalBooks]);

    issued[totalBooks]=false;

    totalBooks++;

    cout<<"\nBook Added Successfully.\n";
}

void displayBooks()
{
    if(totalBooks==0)
    {
        cout<<"\nNo Books Available.\n";
        return;
    }

    cout<<"\n BOOK LIST \n";

    for(int i=0;i<totalBooks;i++)
    {
        cout<<"\nBook "<<i+1<<endl;
        cout<<"ID : "<<bookID[i]<<endl;
        cout<<"Title : "<<title[i]<<endl;
        cout<<"Author : "<<author[i]<<endl;

        if(issued[i])
            cout<<"Status : Issued"<<endl;
        else
            cout<<"Status : Available"<<endl;
    }
}

void searchBook()
{
    int id;

    cout<<"\nEnter Book ID : ";
    cin>>id;

    for(int i=0;i<totalBooks;i++)
    {
        if(bookID[i]==id)
        {
            cout<<"\nBook Found\n";
            cout<<"ID : "<<bookID[i]<<endl;
            cout<<"Title : "<<title[i]<<endl;
            cout<<"Author : "<<author[i]<<endl;

            if(issued[i])
                cout<<"Status : Issued"<<endl;
            else
                cout<<"Status : Available"<<endl;

            return;
        }
    }

    cout<<"\nBook Not Found.\n";
}


void issueBook()
{
    int id;

    cout<<"\nEnter Book ID : ";
    cin>>id;

    for(int i=0;i<totalBooks;i++)
    {
        if(bookID[i]==id)
        {
            if(issued[i])
            {
                cout<<"\nBook is already issued.\n";
            }
            else
            {
                issued[i]=true;
                cout<<"\nBook Issued Successfully.\n";
            }

            return;
        }
    }

    cout<<"\nBook Not Found.\n";
}

void returnBook()
{
    int id;

    cout<<"\nEnter Book ID : ";
    cin>>id;

    for(int i=0;i<totalBooks;i++)
    {
        if(bookID[i]==id)
        {
            if(issued[i]==false)
            {
                cout<<"\nThis book is already available.\n";
            }
            else
            {
                issued[i]=false;
                cout<<"\nBook Returned Successfully.\n";
            }

            return;
        }
    }

    cout<<"\nBook Not Found.\n";
}

void deleteBook()
{
    int id;

    cout<<"\nEnter Book ID : ";
    cin>>id;

    for(int i=0;i<totalBooks;i++)
    {
        if(bookID[i]==id)
        {
            for(int j=i;j<totalBooks-1;j++)
            {
                bookID[j]=bookID[j+1];
                title[j]=title[j+1];
                author[j]=author[j+1];
                issued[j]=issued[j+1];
            }

            totalBooks--;

            cout<<"\nBook Deleted Successfully.\n";

            return;
        }
    }

    cout<<"\nBook Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout<<"\n  LIBRARY MANAGEMENT SYSTEM";
        cout<<"\n1. Add Book";
        cout<<"\n2. Display Books";
        cout<<"\n3. Search Book";
        cout<<"\n4. Issue Book";
        cout<<"\n5. Return Book";
        cout<<"\n6. Delete Book";
        cout<<"\n7. Exit";
        cout<<"\n\nEnter Your Choice : ";
        cin>>choice;

        switch(choice)
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
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                cout<<"\nThank You For Using Library Management System.\n";
                break;

            default:
                cout<<"\nInvalid Choice.\n";
        }

    }while(choice!=7);

    return 0;
}