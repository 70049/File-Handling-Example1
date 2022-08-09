#include<iostream>
#include<string.h>
#include<fstream>
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
        cout<<"Enter The Book Data:";
        cin>>bookid;
        fflush(stdin);
        cin.get(title,29);
        cin>>price;
    }
    void showBookData()
    {
        cout<<"Entered Book Data Is: ";
        cout<<bookid<<" "<<title<<" "<<price;
    }
    int storeData()
    {
        if(bookid==0 && price==0)
            cout<<"Empty file:";
        else{
            ofstream fout;
            fout.open("File1.dat");
            fout.write((char*)this,sizeof(this));
            fout.close();
        }
    }
    int showCopyData()
    {
        ifstream fin;
        fin.open("File1.dat");
        if(!fin)
            cout<<"File NOt Exist!:";
        else{
            fin.read((char*)this,sizeof(this));
            while(!fin.eof()){
                showBookData();
                fin.read((char*)this,sizeof(this));
            }
        }
        fin.close();
    }
};
int main()
{
    Book b1;
    b1.storeData();
    b1.showCopyData();
}

