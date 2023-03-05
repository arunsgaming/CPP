# include <iostream>

using namespace std;


class cms
{
    private:
        char fName[50], lName[50], address[50], email[50];
        long long phNo;

    public:
        void CreateContact();
        void WriteOnFile();
        void ReadFromFile();
        void ShowContact();
        void SearchOnFile();
        void DeleteOnFile();
        void EditContact();
};