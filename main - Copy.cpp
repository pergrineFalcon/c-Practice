#include <iostream>
#include <string>  
#include <fstream> 
#include <sstream> 
using namespace std;
class EnterData{
private:
    string a;
    string title , author;
    int year , id;
public:
    EnterData()
    {
        cout<<"enter add if you wanted to add a book:"<<endl;
         cin>>a;
         while(a=="add")
         {
             ofstream file("library.csv",ios::app);
      cin.ignore();

      cout<<"Enter the title of the book :"<<endl;
      getline(cin,title);

      cout<<"Enter the id of the book :"<<endl;
      cin>>id;

      cout<<"Enter the author of the book :"<<endl;
      cin.ignore();
      getline(cin,author);

      cout<<"Enter the year :"<<endl;
      cin>>year;

      file << id << "," << title << "," << author << "," << year << endl;


       file.close();


      cout<<"if you want to add an other book enter 'add' :"<<endl;
      cin>>a;
      if(a!="add")
        break;
    }
    }

};

void  searchByNamee(string bookName)
{
    ifstream file("library.csv");
    if(!file.is_open())
    {
        cout<<"the file could not have been open  !!!!"<<endl;
        return;
    }
    string line;
     bool found=false;
    while (getline(file,line))
    {
        stringstream ss(line);
        string title ,id ,author ,year;

        getline(ss,id,',');
        getline(ss,title,',');

        getline(ss,author,',');
        getline(ss,year,',');

        if(title==bookName)
        {
            cout << "the book is exist...." << endl;
            cout << "ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
              found=true;
            break; 
        }

    }
         if(found==false)
        cout<<"The book is not found.......!!!!"<<endl;



    file.close();
}
int main()
{
    int b;

static int d=0;
while(1)
{

    cout<<"Well come to this little stage to manage the library if you want to add data press 1."<<endl<<"and if you want to get data press 2."<<endl
<<"if you want to search a book enter 3."<<endl<<"if you want to escape enter something else"<<endl;

    cin>>b;
    if(b==1)
    {
       EnterData a;

    }

    else if (b == 2) {
    ifstream file("library.csv");
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
}
  else if(b==3)
  {
         cout<<"enter the name of the book you wanna check if it is in your library:......"<<endl;

         cin.ignore();
         string tit;
         getline(cin,tit);

        searchByNamee(tit);
  }
else break;
}










    return 0;
}
