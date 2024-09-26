#include "libirary.h"
#include <iostream>
#include <string>

#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<libirary*>libirary;
    int choice;
    do
    {
        cout << "1. Add Book :" << endl;
        cout << "2. BOOKS DISPLAY : " << endl;
        cout << "3. CHECK PARTICULAR : " << endl;
        cout << "4. UPDATE BOOK : " << endl;
        cout << "5. delete BOOk : " << endl;
        cout << "6. EXIT : " << endl;
        cin >> choice;
        if (choice == 1)
        {
            int i, n;
            string nam, A;
            cout << "Enter Name BOOK :" << endl;
            cin >> nam;
            cin.ignore();
            cout << "Enter ID BOOK :" << endl;
            cin >> i;
            cin.ignore();
            cout << "Enter Author Name :" << endl;
            getline(cin, A);
            cout << "Number of copies BOOK :" << endl;
            cin >> n;
            libirary.push_back(new ::libirary(i, nam, A, n));
            char ch;
            cout << "Do you want to continue(y/n)" << endl;
            cin >> ch;
            if(ch == 'n' || ch == 'N')
            {
                for (auto lib : libirary)
                {
                    lib->display();
                }
	            
            }else
            {
	            continue;
            }
            
        }
        else if (choice == 2)
        {
            for (auto lib : libirary)
            {
                lib->display();
            }
        }
        else if (choice == 3)
        {
            string new_book_name;
            bool found = false;
            cout << "Enter Name BOOK TO Search: " << endl;
            cin.ignore();
            getline(cin, new_book_name);
            for (auto lib : libirary)
            {
                if (lib->B_name == new_book_name)
                {
                    cout << "Detail of BOOK Is :" << endl;
                    lib->display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "This BOOK Is NOT Found" << endl;
            }
        }
        else if (choice == 4)
        {
            int new_id;
            cout << "Enter ID To search:";
            cin >> new_id;
            cout << endl;
            for (auto lib : libirary)
            {
                if (new_id == lib->id)
                {
                    
                    string new_name; int new_id2; string new_author; int new_numper;
                    cout << "Enter new Book ID: ";
                    cin >> new_id;
                    cout << "Enter new Book name: ";
                    cin.ignore();
                    getline(cin, new_name);
                    cout << "Enter new Author name: ";
                    getline(cin, new_author);
                    cout << "Enter new number of copies: ";
                    cin >> new_numper;
                    lib->updata(new_name, new_id, new_author, new_numper);
                    break;
                }
            }
        }
        else if (choice == 5)
        {
            int delete_id;
            cout << "Enter Book ID to Delete: ";
            cin >> delete_id;

            auto it = remove_if(libirary.begin(), libirary.end(), [delete_id](class libirary *lib)
                {
                    if (lib->id == delete_id)
                    {
                        delete lib;
                        return true;
                    }
                    return false;
                });

            libirary.erase(it, libirary.end());
            cout << "Book Deleted." << endl;
        };
        
    } while (choice !=6);
    {
        for (auto lib : libirary)
        {
            delete lib;
        }
	
    }
    
    
}







