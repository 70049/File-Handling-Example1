#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
private:
    int bookid;
    char title[30];
    float price;
public:
    Book()
    {
        bookid=0;
        strcpy(title,"no title");
        price=0;
    }
    void getBookData()
    {
        cout<<endl<<"Enter Book Data: \n";
        cout<<"BOOKID:"<<"   "<<"TITLE:"<<"   "<<"PRICE:\n";
        cin>>bookid;
        fflush(stdin);
        cin.get(title,29);
        cin>>price;
    }
    void showBookData()
    {
        cout<<"Entered Book Data: \n";
        cout<<bookid<<" "<<title<<" "<<price;
    }
    void StoreBookData()
    {
        if(bookid==0 && price==0)
            cout<<"Book Data Not Intilized: ";
        else{
            ofstream fout;
            fout.open("File1.dat");
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }
    }
};
int main()
{
    Book b1;
    b1.getBookData();
    b1.showBookData();
    b1.StoreBookData();
    getch();
}
