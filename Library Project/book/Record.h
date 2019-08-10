//  main.h
//  PA3
//  Created by Hannah Mao on 7/20/16.
//  Copyright (c) 2016 Hannah Mao. All rights reserved.


#include "std_lib_facilities.h"


class Record {
private:
    string title;  //function members
    string name;
    string ISBN;
    string year;
    string edition;
    
public:
    
   Record():title(""), name(""),ISBN(""),year(""), edition(""){}
   Record(string title, string name, string ISBN, string year, string edition):title(title), name(name), ISBN(ISBN), year(year), edition(edition){}  //constructor

    string get_title() const {return title;} //get functions
    string get_name() const {return name;}
    string get_ISBN() const {return ISBN;}
    string get_year() const {return year;}
    string get_edition() const {return edition;}
    
    void set_title(string booktitle){ title=booktitle;}  //set functions
    void set_name(string authorname){name= authorname;}
    void set_ISBN(string ISBN_NUM){ISBN=ISBN_NUM;}
    void set_year(string years){year=years;}
    void set_edition(string e){edition=e;}
    
};


istream& operator>>(istream& in,  Record& r){ // overload input operator to read the content of a record
    
    string t;
    string n;
    string i;
    string y;
    string e;
    string h; //dummy variable storing emptyline
    
    getline(in, t);
    getline(in, n);
    getline(in, i);       // 6 operations
    getline(in, y);
    getline(in, e);
    getline(in, h); //dummy variable storing emptyline
    
    t = t.substr(0, t.size()-1);  //delete newline charactor /r
    n = n.substr(0, n.size()-1);  //make sure that set functions do not
    i = i.substr(0, i.size()-1);  //include the newline character          // 6 operations
    y = y.substr(0, y.size()-1);
    e = e.substr(0, e.size()-1);
    h = h.substr(0, h.size()-1);
 
    r.set_title(t);
    r.set_name(n);      // 5 operations
    r.set_ISBN(i);
    r.set_year(y);
    r.set_edition(e);
    
    return in;           //f(n)=17=O(1)
}

ostream& operator<<(ostream& out, const Record& r){ //overload output operator to output the record
out<<endl<<r.get_title()<<endl<<r.get_name()<<endl<<r.get_ISBN()<<endl<<r.get_year()<<endl<<r.get_edition()<<endl;
    return out;           //f(n)=5=O(1);
}

bool  operator<(const Record& r1, const Record& r2){ //overload < operator to compare title, name and ISBN
 
   if(r1.get_title()<r2.get_title()) {return true;}     //1 comparison
    
   if(r1.get_title()==r2.get_title()&& r1.get_name()<r2.get_name()){return true;}  //2 comparisons
    
   if(r1.get_title()==r2.get_title() && r1.get_name()==r2.get_name() && r1.get_ISBN()<r2.get_ISBN()){return true;}  //3 comparisons
    
   else {return false;}

}        //f(n)=3=O(1);








