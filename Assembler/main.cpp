//  main.cpp
//  Project6
//  Created by Hannah Mao on 7/22/17.
//  Copyright (c) 2017 Hannah Mao. All rights reserved.


#include <iostream>
#include "std_lib_facilities.h"
#include <map>

string dest(string lines);            //parsing functions
string comp(string lines);
string jump(string lines);

string TranslateDest(string destM);   //translation functions
string TranslateComp(string compM);
string TranslateJump(string jumpM);
string TranslateA(string lines);
string TranslateSymbol(int num);

string AinstructionM;
string symbolM;
string variableM;

map<string, string> destTable;
map<string, string> compTable;
map<string, string> jumpTable;
map<string, int> symbolTable;

int vaddress=16;      // initialize variable address to 16


int main() {
    
    string lines;  //current line
    int pos;       //current line number
    pos=-1;
    
    destTable[""] = "000";
    destTable["M"] = "001";
    destTable["D"] = "010";
    destTable["MD"] = "011";
    destTable["A"] = "100";
    destTable["AM"] = "101";
    destTable["AD"] = "110";
    destTable["AMD"] = "111";
    
    compTable["0"] = "0101010";
    compTable["1"] = "0111111";
    compTable["-1"] = "0111010";
    compTable["D"] = "0001100";
    compTable["A"] = "0110000";
    compTable["!D"] = "0001101";
    compTable["!A"] = "0110001";
    compTable["-D"] = "0001111";
    compTable["-A"] = "0110011";
    compTable["D+1"] = "0011111";
    compTable["A+1"] = "0110111";
    compTable["D-1"] = "0001110";
    compTable["A-1"] = "0110010";
    compTable["D+A"] = "0000010";
    compTable["D-A"] = "0010011";
    compTable["A-D"] = "0000111";
    compTable["D&A"] = "0000000";
    compTable["D|A"] = "0010101";
    compTable["M"] = "1110000";
    compTable["!M"] = "1110001";
    compTable["-M"] = "1110011";
    compTable["M+1"] = "1110111";
    compTable["M-1"] = "1110010";
    compTable["D+M"] = "1000010";
    compTable["D-M"] = "1010011";
    compTable["M-D"] = "1000111";
    compTable["D&M"] = "1000000";
    compTable["D|M"] = "1010101";
    
    jumpTable[""] = "000";
    jumpTable["JGT"] = "001";
    jumpTable["JEQ"] = "010";
    jumpTable["JGE"] = "011";
    jumpTable["JLT"] = "100";
    jumpTable["JNE"] = "101";
    jumpTable["JLE"] = "110";
    jumpTable["JMP"] = "111";
    
    //pre-defined symbol
    symbolTable["R0"] = 0;
    symbolTable["R1"] = 1;
    symbolTable["R2"] = 2;
    symbolTable["R3"] = 3;
    symbolTable["R4"] = 4;
    symbolTable["R5"] = 5;
    symbolTable["R6"] = 6;
    symbolTable["R7"] = 7;
    symbolTable["R8"] = 8;
    symbolTable["R9"] = 9;
    symbolTable["R10"] = 10;
    symbolTable["R11"] = 11;
    symbolTable["R12"] = 12;
    symbolTable["R13"] = 13;
    symbolTable["R14"] = 14;
    symbolTable["R15"] = 15;
    symbolTable["SCREEN"] = 16384;
    symbolTable["KBD"] = 24576;
    symbolTable["SP"] = 0;
    symbolTable["LCL"] = 1;
    symbolTable["ARG"] = 2;
    symbolTable["THIS"] = 3;
    symbolTable["THAT"] = 4;
    

    string inputfilename;
    string outputfilename;
    
    cout<<"enter the name of the text file"<<endl;
    cin>>inputfilename;
    
    ifstream inFile;
    ofstream outfile;

    outputfilename=inputfilename.substr(0, inputfilename.length() - 4) + ".hack";
    //set outputfilename equal to inputfilename.hack
    
    outfile.open(outputfilename); //open outputfile stream
    
    if (outfile.fail()) {
        cout << "Failed to create output file." << endl;
       
    }
    

    inFile.open(inputfilename); //open inputfile stream
  
    if( inFile.is_open() ) {  // First pass: put labels in symbol tables.
        
        while (getline(inFile,lines)){
            
            lines.erase(remove(lines.begin(), lines.end(), '\r'), lines.end()); //erase all the \r
            
            if(lines.empty() || lines.find("//") == 0) { //skip empty lines and comments
                
               continue;
                
            }
            
            else
                
                if (lines.find("(") == 0) { // if a parenthesis is found
                    
                    int symboladdress;
                    symboladdress=pos+1;   // set next the line number to the address of the symbol
                    lines= lines.substr(1, lines.length()-2);  //get the lables inside of parenthesis
                    symbolTable[lines]=symboladdress;    // insert into the symbol table
                    pos=pos-1;
                    
                }
                pos++;
        }
        
        inFile.clear();
        inFile.seekg(0, std::ios_base::beg);
      
        while( getline(inFile,lines)){  // second pass
            
        lines.erase(remove(lines.begin(), lines.end(), '\r'), lines.end());
          
          if(lines.empty() || lines.find("//") == 0 || lines.find("(")==0) {
        
              continue;
          }
          
          
          size_t atposition = lines.find('@');  //find the positin of @
          
          if (atposition!= string::npos) {  //if @ is found in the string, it's A instruction
              
              lines= lines.substr(atposition+1, lines.length()-atposition);
              
              size_t wspace=lines.find(' ');
               if(wspace!= string::npos){
                  lines.erase(lines.begin()+wspace,lines.end());
               }
              
              if (lines.find_first_not_of("0123456789")==string::npos) { //if it's a number after @
                  AinstructionM=TranslateA(lines);   //convert the number into binary
                  cout<<AinstructionM<<endl;
                  outfile<<AinstructionM<<endl;
                  }
          
               //it's a symbol or a variable
               else if(symbolTable.count(lines)==1){ //if it's already found in the symbol table already
                   
                      int val=symbolTable.at(lines); //retrieve value of key (address)
                      symbolM=TranslateSymbol(val);  //convert address to binary
                      cout<<symbolM<<endl;
                      outfile<<symbolM<<endl;
                  
               }
           
               else{ // it's a variable (starts at address 16)
                
                      symbolTable[lines]=vaddress;   //insert variable into symbol table at address 16
                      int val=symbolTable.at(lines); //retrieve value of the key (address)
                      variableM=TranslateSymbol(val);  //convert address to binary
                      cout<<variableM<<endl;
                      outfile<<variableM<<endl;
                      vaddress++;
                    }
              }
          
              else{   //it's a C instruction
              
              string destM;
              string compM;
              string jumpM;
              
              string codeD;
              string codeC;
              string codeJ;
              
              
             size_t foundposition=lines.find_first_of("ADM01!-");
              
             lines=lines.substr(foundposition,lines.length()-foundposition); //delete space in front of command
              
              size_t wspace=lines.find(' ');
              if(wspace!= string::npos){
                  lines.erase(lines.begin()+wspace,lines.end());  //erase white space and inline comment after command
              }
          
               destM=dest(lines);
               compM=comp(lines);
               jumpM=jump(lines);
        
               codeD=TranslateDest(destM);
               codeC=TranslateComp(compM);
               codeJ=TranslateJump(jumpM);
              
              string sum;
              sum="111"+codeC+codeD+codeJ;
              cout<<sum<<endl;
              outfile<<sum<<endl;
              
              }
         }
    }
    else cout<<"unable to open";
        return 0;
}


string dest(string lines){  //parse dest

    size_t equalsignpos = lines.find('=');
    if (equalsignpos != string::npos) {
        return lines.substr(0, equalsignpos);
    }
    return "";
}

string comp(string lines){  //parse comp

    size_t equalsignpos = lines.find('=');  // find the position of the the equal sign
    size_t semicolonpos = lines.find(';');  // find the position of the semicolon
   
    if (equalsignpos != string::npos) {
        if(semicolonpos !=string::npos){
        // Case 1: dest = comp ; jump
        return lines.substr(equalsignpos + 1, semicolonpos - equalsignpos - 1);
       }
     // Case 2: dest = comp
        return lines.substr(equalsignpos + 1, lines.length() - equalsignpos - 1);
        }
    
    // Case 3: comp ; jump
    else if (semicolonpos != string::npos) {
    return lines.substr(0, semicolonpos);
    }

// If no computation was specified, return a blank string.
   return "";
  
}

string jump(string lines){  //parse comp
    
   size_t semicolonpos = lines.find(';');
   if (semicolonpos != string::npos) {
        return lines.substr(semicolonpos+1, lines.length()-semicolonpos-1);
    }
     return "";
}

string TranslateDest(string destM) { //translate dest mnemonic for C command
    
    if (destTable.find(destM) != destTable.end()) {
        return destTable[destM];
    }
    return "";
}


string TranslateComp(string compM) { //translate comp mnemonic for C command
    if (compTable.find(compM) != compTable.end()) {
        return compTable[compM];
    }
     return" ";
}

string TranslateJump(string jumpM) {    //translate jump mnemonic for C command
    if (jumpTable.find(jumpM) != jumpTable.end()) {
    
        return jumpTable[jumpM];
      
    }
    return" ";
}

string TranslateA(string lines) { //translate number for A command
   
    return bitset<16>(stoul(lines,nullptr)).to_string();
    //stoul:convert string to its integer value
}

string TranslateSymbol(int num){  //translate symbol and variable address for A command
    return bitset<16>(num).to_string();
}














