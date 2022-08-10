#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
private:
    int bookid;
    char title[20];
    float price;
public:
    Book()
    {
        bookid=0;
        strcpy(title,"No title");
        price=0;
    }
    void setBook()
    {
        cout<<"\nEnter Book Data: ";
        cin>>bookid;
        fflush(stdin);
        cin.get(title,19);
        cin>>price;
    }
    void showBook()
    {
        cout<<"Entered Book Data Is: ";
        cout<<bookid<<" "<<title<<" "<<price;
    }
    void storeBook()
    {
        if(bookid==0 && price==0)
            cout<<"\nRecord Is Empty\n: ";
        else{
            ofstream fout;
            fout.open("File1.dat");
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }
    }
    void searchBook(char *t)
    {
        int counter=0;
        ifstream fin;
        fin.open("File1.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"\nFile NOt Open";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
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
    void updateBook(char *t)
    {
        fstream file;
        file.open("File1.dat",ios::in|ios::out|ios::ate|ios::binary);
        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof()){
            if(!strcmp(t,title)){
                showBook();
                file.seekp(file.tellp,sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
    }
    void deleteBook(char *t)
    {
        ifstream fin;
        ofstream fout;
        fin.open("File1.dat",ios::in|ios::binary);
        if(!fin)
            cout<<"File NOt Found: ";
        else{
            fout.open("tempfile,dat",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){
                if(!strcmp(title,t)){
                    fout.write((char*)this,sizeof(*this));
                    fin.read((char*)this,sizeof(*this));
                }
            }
        }
        fin.close();
        fout.close();
        remove("File1.dat");
        rename("tempfile.dat","File1.dat");
    }
    void showAllBook()
    {
        ifstream fin;
        fin.open("File1.dat");
        if(!fin)
            cout<<"\nFile Not Found:";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.read){
                showBook();
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
};
int menu()
{
    int chioce;
    cout<<"\nBOOK MANAGEMENT:";
    cout<<"\n1. Insert New Book" ;
    cout<<"\n2. View Inserted Book Data: ";
    cout<<"\n3. Search Book Title: ";
    cout<<"\n4. Delete Any Specific Title: ";
    cout<<"\n5. Update Book Title: ";
    cout<<"\n6. Exit: ";
    cout<<"\n\nEnter Your Chioce: ";
    cin>>chioce;
}
int main()
{
    char title[20];
    Book b1;
    while(1){
        system("cls");
        switch(menu()){
            case 1:
                b1.setBook();
                cout<<"\nRecord Inserted: ";
                break;
            case 2:
                b1.showBook();
                break;
            case 3:
                cout<<"\nEnter Title Book to Search: ";
                fflush(stdin);
                cin.get(title,20);
                b1.searchBook();
                break;
            case 4:
                cout<<"\nEnter Book Title to Delete Record: ";
                fflush(stdin);
                cin.get(title,20);
                b1.deleteBook();
                break;
            case 5:
                cout<<"\nEnter Book Title to Update Book Record: ";
                fflush(stdin);
                cin.get(title,20);
                b1.updateBook();
                break;
            case 6:
                cout<<"\nThank You For Using This Application: ";
                cout<<"\nPress Any Key to Exit: ";
                getch();
                exit(0);
        }
    }
}
