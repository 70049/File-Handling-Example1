#include<iostream>
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
    void setBookData()
    {
        cout<<"Enter Book Data: ";
        cin>>bookid;
        fflush(stdin);
        cin.get(title,30);
        cin>>price;
    }
    void showBookData()
    {
        cout<<"Entered Book Data Is: ";
        cout<<bookid<<" "<<title<<" "<<price;
    }
    int storeBook()
    {
        if(bookid==0 && price==0)
            cout<<"Empty" ;
        else
        {
            ofstream fout;
            fout.open("File1.dat");
            fout.write((char*)this,sizeof(this));
        }
//        fout.close();
    }
    void searchBook(char *t)
    {
        int counter=0;
        ifstream fin;
        fin.open("File1.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File Not Found! ";
        else
        {
            fin.read((char*)this,sizeof(this));
            while(!fin.eof()){
                if(!strcmp(t,title)){
                    showBookData();
                    counter++;
                }
                fin.read((char*)this,sizeof(this));
            }
            if(counter==0)
                cout<<"Record Not Found";
        }
        fin.close();
    }
    void showAlldata()
    {
        ifstream fin;
        fin.open("File1,dat");
        if(!fin)
            cout<<"Data Not Exist:";
        else
        {
            fin.read((char*)this,sizeof(this));
            while(!fin.eof()){
                showBookData();
            }
            fin.read((char*)this,sizeof(this));
        }
        fin.close();
    }
};
int main()
{
    Book b1;
    b1.setBookData();
    b1.showBookData();
    b1.storeBook();
    b1.searchBook();
    b1.showAlldata();
}
