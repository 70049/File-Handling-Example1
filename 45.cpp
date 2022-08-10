#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;
void setBook();
void showBook();
void storeBook();
void searchBook(char*);
void deleteBook(char*);
void showBookAllData();
class Book
{
private:
    int bookid;
    char title[30];
    float price;
public:
    Book(){
        int bookid=0;
        char title[30];
        float price=10;
    }
    void setBook()
    {
        cout<<endl<<"Enter Book Data: \n";
        cin>>bookid;
        fflush(stdin);
        cin.get(title,29);
        cin>>price;
    }
    void showBook()
    {
        cout<<"\nEntered Book Data Is: \n";
        cout<<bookid<<" "<<title<<" "<<price;
    }
    void storeBook()
    {
        if(bookid==0 && price==0)
            cout<<"Empty Data: ";
        else{
            ofstream fout;
            fout.open("File1.dat");
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }

    }
    void searchBook(char* t)
    {
        int counter=0;
        ifstream fin;
        fin.open("File1.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"\nFile Not Exist: ";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(!strcmp(t,title)){
                    showBook();
                    counter++;
                }
                fin.read((char*)this,sizeof(*this));
            }
            if(counter=0)
                cout<<"\nRecord Not Found:";
        }
        fin.close();
    }
    void deleteBook(char *t)
    {
        ifstream fin;
        ofstream fout;
        fin.open("File1.dat");
        if(!fin)
            cout<<"\nFile Not Exist:\n ";
        else{
            fout.open("tempfile.dat",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(!strcmp(title,t)){
                    fout.write((char*)this,sizeof(*this));
                    fin.read((char*)this,sizeof(*this));
                }
            }
        }
        fin.close();
    }
    void showBookAllData()
    {
        ifstream fin;
        fin.open("File1.dat");
        if(!fin)
            cout<<"\nFile NOt Exist:\n ";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                showBook();
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
};
int main()
{
    Book b1;
    b1.setBook();
    b1.showBook();
    b1.storeBook();
//    b1.searchBook();
    b2.deleteBook();
    b1.showBookAllData();
    getch();
}
