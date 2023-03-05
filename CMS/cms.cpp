# include "cms.h"
# include <fstream>
# include <conio.h>


void cms::CreateContact()
{
    cout << "Enter your First Name: ";
    cin >> fName;
    cout << "Enter your Last Name: ";
    cin >> lName;
    cout << "Enter Phone: ";
    cin >> phNo;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter email: ";
    cin >> email;
}

void cms::WriteOnFile()
{
    char ch;
    ofstream fwriteptr;
    fwriteptr.open("CMS.dat", ios::binary | ios::app);

    do
    {
        CreateContact();
        fwriteptr.write(reinterpret_cast<char*>(this), sizeof(*this));
        cout << "D you have next data? (y/n)";
        cin >> ch;
    } while (ch == 'y');

    cout << "Contact has been sucessfully created..";
    fwriteptr.close();
}

void cms::ReadFromFile()
{
    ifstream freadptr;
    freadptr.open("CMS.dat", ios::binary);
    cout << "\n********************************\n";
    cout << "LIST OF CONTACTS";
    cout << "\n********************************\n";

    while (!freadptr.eof())
    {
        if (freadptr.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            ShowContact();
            cout << "\n********************************\n";
        }
    }
    freadptr.close();
}

void cms::ShowContact()
{
    cout << "Name: " << fName << " " << lName << endl;
    cout << "PhNo: " << phNo << endl;
    cout << "Address: " << address << endl;
    cout << "Email: " << email << endl;

}

void cms::SearchOnFile()
{
    ifstream freadptr;
    long long phone;
    cout << "Enter phone no.:   ";
    cin >> phone;
    freadptr.open("CMS.dat", ios::binary);
    while (!freadptr.eof())
    {
        if (freadptr.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            if (phone == phNo)
            {
                ShowContact();
                return;
            }
        }
    }
    cout << "\n\n No record found";
    freadptr.close();
}

void cms::DeleteOnFile()
{
    int flag = 0;
    long long num;
    ifstream freadptr;
    ofstream fwriteptr;

    freadptr.open("CMS.dat", ios::binary);
    fwriteptr.open("temp.dat", ios::binary);

    cout << "Enter phone no. to delete";
    cin >> num;

    while (!freadptr.eof())
    {
        if (freadptr.read(reinterpret_cast<char*>(this), sizeof(*this)))
            if (phNo != num)
                fwriteptr.write(reinterpret_cast<char*>(this), sizeof(*this));
            else
                flag = 1;
    }
    freadptr.close();
    fwriteptr.close();
    remove("CMS.dat");
    rename("temp.dat", "CMS.dat");

    flag == 1 ?
        cout << endl << endl << "\t Contact Deleted....":
        cout << endl << endl << "\tContact Not Found......";
}

void cms::EditContact()
{
    long long num;
    fstream fileptr;

    cout << "Edit contact";
    cout << "\n********************************\n\n";
    cout << "Enter the phone number to be edit: ";
    cin >> num;
    
    fileptr.open("CMS.dat", ios::binary | ios::out | ios::in);
    while (!fileptr.eof())
    {
        if (fileptr.read(reinterpret_cast<char*>(this), sizeof(*this)))
            if (phNo == num)
            {
                cout << "Enter new record\n";
                CreateContact();
                int pos = -1 * static_cast<int> (sizeof(*this));
                fileptr.seekp(pos, ios::cur);
                fileptr.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout << endl << endl << "\t Contact successfully updated";
                return;
            }
    }
    cout << "\n\n No record found";
    fileptr.close();
}

