//  main.cpp
//  Created by Hannah Mao on 7/20/16.
//  Copyright (c) 2016 Hannah Mao. All rights reserved.


#include "Record.h"
#include "TemplateDoublyLinkedList.h"
#include <vector>
#include <stdio.h>
#include <ctype.h>

    
void read(vector<DoublyLinkedList<Record>>&book){//read from file and input record orderly
    
    
    ifstream nfile("Book.txt");
    Record Record;
    
    if(nfile.is_open()){
        
        while(!nfile.eof()) {
            
            nfile>>Record; //read from the file and input into record
            book[Record.get_title().at(0)-65].insertOrderly(Record);
            //insert record into vector of Doublelinked lists in order
        }
        
    }
    
    else cout<<"can't open file"<<endl;
    nfile.close();
    
}

void showLibrary(vector<DoublyLinkedList<Record>> & book){ //show library with all books
    cout<<endl<<"show library: "<<endl;
    for (int i=0;i<26;i++){
        cout << book[i];
    }
}

void addToLibrary(vector<DoublyLinkedList<Record>> & book){ //if the book is not found, add it to the library
    
    Record newRecord;
    
    string title;
    string name;
    string ISBN;
    string year;
    string edition;
    
    cout<<endl<<"The given book is not found, please add it to the library!!!"<<endl;
    cout<<"Please enter the title of the book: ";
    getline(cin,title);
    newRecord.set_title(title);
    
    cout<<"Please enter the name of the author: ";
    getline(cin,name);
    newRecord.set_name(name);
    
    cout<<"Please enter ISBN: ";
    getline(cin,ISBN);
    newRecord.set_ISBN(ISBN);
    
    cout<<"Please enter year: ";
    getline(cin,year);
    newRecord.set_year(year);
    
    cout<<"Please enter edition: ";
    getline(cin,edition);
    newRecord.set_edition(edition);
    
    book[newRecord.get_title().at(0)-65].insertOrderly(newRecord);
    
    cout<<endl<<"Now the book is added to the library:"<<endl;
    showLibrary(book);
  
}



void search(vector<DoublyLinkedList<Record>> & book, string &input){ //search for a book
    
    vector<Record>count;  //count the number of the books with the record requested by the user
    
    int index=(input.at(0)-65); //index of the first letter of the book title    //1 operation
    
    DListNode<Record>*temp=book[index].getFirst();                       //1 operation
    

while(temp != book[index].getAfterLast()){    //n iterations
        
        if(input == temp->getElem().get_title()){  
            count.push_back(temp->getElem());  //1 operation

        }
    
        temp=temp->getNext();//1 operation
    }
    
    if(count.size()==1){ //if only one record has the title
        
       cout<<count[0];   //return the record
          
    }
    
    if(count.size()>1){ //if more than one record has the same title and author, ask which edition
       
    cout<<endl<<"More than one record with the same titles and authors are found!!!"<<endl;
         
          for(int i=0;i<count.size();i++){
              cout<<count[i];
          }
          
          cout<<endl<<"what author?"<<endl;
          string input;
          getline(cin,input);
          
          
          cout<<endl<<"what edition?"<<endl;
          string edition;
          getline(cin,edition);
        
          for( int i=0; i<count.size();i++){   //less than n iterations
              if(edition==count[i].get_edition()){
                 cout<<count[i];
                     }
               }
    }
    
    if(count.size()<1){addToLibrary(book);}; //if no book exist, add to library
    
}   //f(n)=2+2n=O(n)


void userinterface(vector<DoublyLinkedList<Record>> & book){
   
    cout<<endl<<"Please enter the name of the book that you want to search for:";
    string input;
    getline(cin,input);
    search(book,input);
    
    cout<<endl<<"Do you want to keep searching?";
    string anwser;
    getline(cin,anwser);
    
    while(anwser=="yes"){
        
        cout<<endl<<"Please enter the name of the book that you want to search for:";
        string input;
        getline(cin,input);
        search(book,input);
         
        cout<<endl<<"Do you want to keep searching?";
        string answer;
        getline(cin, answer);
        
        if(answer=="no")break;
    }
    
}


int main(){
    try {
        
        vector<DoublyLinkedList<Record>>book(26);
        
        read(book);
        userinterface(book);
        showLibrary(book);
        
        return 0;
        
    }
    
    catch(exception&error){
    cerr<<"Error:" <<error.what()<<endl;
    }
    
}


