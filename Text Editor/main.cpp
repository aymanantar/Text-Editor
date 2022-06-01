// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: text_editor.cpp
// Program Description: text editing
// Last Modification Date: 14/5/2022
// Author1 and ID and Group: 20210080
// Author2 and ID and Group: 20211043
// Author3 and ID and Group: 20210341
// Teaching Assistant: s3,s4.
// Purpose:..........
#include <iostream>
#include <fstream>
using namespace std;
void Add ();
void View();
void Empty ();
void Encrypt ();
void Decrypt ();
void Merge ();
void Count_Words ();
void Count_Chars ();
void Count_Lines ();
void Search ();
void Frequancy ();
void To_Upper ();
void To_Lower (bool f);
void First_Upper ();
void Save ();
int main()
{
    int n; bool f=1;
    while (f){
    cout<<"welcome ya user ya habibi, what do you wanna do ?\n 1. Add new text to the end of the file \n 2. Display the content of the file \n 3. Empty the file \n 4. Encrypt the file content \n 5. Decrypt the file content \n 6. Merge another file \n 7. Count the number of words in the file \n 8. Count the number of characters in the file \n 9. Count the number of lines in the file \n 10. Search for a word in the file \n 11. Count the number of times a word exists in the file \n 12. Turn the file content to upper case \n 13. Turn the file content to lower case \n 14. Turn file content to 1st caps (1st char of each word is capital) \n 15. Save \n 0. Exit : \n ";
    cin>>n;
    switch(n){
    case 0:
    f=0;
    break;
    case 1 :
    Add();
    break;
    case 2:
    View();
    break;
    case 3:
    Empty ();
    break;
    case 4:
    Encrypt ();
    break;
    case 5:
    Decrypt ();
    break;
    case 6:
    Merge ();
    break;
    case 7:
    Count_Words ();
    break;
    case 8:
    Count_Chars ();
    break;
    case 9:
    Count_Lines ();
    break;
    case 10:
    Search ();
    break;
    case 11:
    Frequancy ();
    break;
    case 12:
    To_Upper ();
    break;
    case 13:
    To_Lower (1);
    break;
    case 14:
    First_Upper ();
    break;
    case 15:
    Save ();
    break;
    default :
    cout<<"wrong chose ya basha , try again ......\n";
    }
}
}
void Add () {
fstream ss;
ss.open("mytext",ios::app);
cout<<"type the text to be added to the file please : \n";
string s; cin.clear(); cin.sync(); getline(cin,s);
ss<<s;cout<<"\ntext added successfully to the file, good night \n\n";
}
void View() {
string display;
fstream ss;
ss.open("mytext",ios::in);
cout<<".................................... here is what file includes ............................. \n\n\n";
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,display);
cout<<display<<endl;
}
cout<<"\n\n ..................................... end of the file ............................................. \n";
}

void Empty () {
fstream ss;
ss.open("mytext",ios::out);
ss.clear();
cout<<"\ndone, file is empty right now. \n\n";
}
void Encrypt (){
string Swap;
// adding the text to a dummy file where i can encrypt each line and append there
fstream ss;
ss.open("mytext",ios::in);
// make sure the dummy file is empty and ready to take encrypted text line by line
fstream s;
s.open("dummy",ios::out);s.clear();s.close();
// now start.... moving each later gives the chance to encrypt it
s.open("dummy",ios::app);
while (!ss.eof()){
ss.clear(); ss.sync(); getline(ss,Swap);
// this is the function of ceaser_encoding
for (int i=0; i<Swap.size(); i++){
if (Swap[i]==122) {Swap[i]=97;}
else if (Swap[i]==90) {Swap[i]=65;}
else {Swap[i]++;}
}
// end of the encoding and put the char in the dummy file
s<<Swap<<'\n';
    }

ss.close();
// simple step to make the old text file empty and ready for the encrypted text
s.close();s.open("mytext",ios::out);s.clear();s.close();
// open files again with reversed purpose (put the text from dummy to myfile)
ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,Swap);
s<<Swap<<'\n';

}

cout<<"\ncontent is encrypted successfully. \n\n";
}

void Decrypt (){
string Swap;
// adding the text to a dummy file where i can Decrypt each line and append there
fstream ss;
ss.open("mytext",ios::in);
// make sure the dummy file is empty and ready to take Decrypted text line by line
fstream s;
s.open("dummy",ios::out);s.clear();s.close();
// now start.... moving each later gives the chance to Decrypt it
s.open("dummy",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,Swap);
// this is the function of ceaser_Decoding
for (int i=0; i<Swap.size();i++){
if (Swap[i]==97) {Swap[i]=122;}
else if (Swap[i]==65) {Swap[i]=90;}
else {Swap[i]--;}
}
// end of the Decoding and put the char in the dummy file
s<<Swap<<'\n';
    }
ss.close();
// simple step to make the old text file empty and ready for the Decrypted text
s.close();s.open("mytext",ios::out);s.clear();s.close();
// open files again with reversed purpose (put the text from dummy to myfile)
ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,Swap);
s<< Swap<<'\n';
}
cout<<"\ncontent is Decrypted successfully. \n\n";
}
void Merge () {

string s1,s2,mov;
cout<<"what is the first file you want to merge ? \n if you want to merge another file with the current file that you are editing right now press 1 : \n";
cin>>s1;
if (s1[0]=='1'){s1="mytext";}
cout<<"Type the second file to be merged with it : \n";
cin>>s2;
fstream ss,s;
s.open(s1,ios::app);
ss.open(s2,ios::in);
while (!ss.eof()){
ss.clear();ss.sync();getline(ss,mov);
s<< mov<<'\n';
}
cout<<"\nmerged successfully. \n\n";
}
void Count_Words () {
int c=0;
string Count;
fstream ss;
ss.open("mytext",ios::in);
while (!ss.eof()){
ss>>Count;
if (Count==""){break;}
c++;
}
cout<<"\nThere is a total of "<<c<<" words in this file. \n\n";
}
void Count_Chars () {
int c=0;
string Count;
fstream ss;
ss.open("mytext",ios::in);
while (!ss.eof()){
ss>>Count;
if (Count==""){break;}
c+=Count.size();
}
cout<<"\nThere is a total of "<<c<<" chars in this file. \n\n";
}
void Count_Lines () {
int c=0;
string Count;
fstream ss;
ss.open("mytext",ios::in);
while (!ss.eof()){
getline(ss,Count);
if (Count==""){break;}
c++;
}
cout<<"\nThere is a total of "<<c<<" lines in this file. \n\n";
}
void Search () {
bool f=1;
string look,s;
cout<<" what is the word you are looking for ? \n"; cin>>s;
fstream ss;
ss.open("mytext",ios::in);
while (!ss.eof()){
ss>>look;
if ((look)==(s)) {cout<<"\nword was found in the file :) !! \n\n"; f=0; break;}
}
if (f){cout<<"\nword was not found in the file :( !! \n\n";}
}
void Frequancy () {
int c=0;
string look,s;
cout<<" what is the word you are looking for ? \n"; cin>>s;
fstream ss;
ss.open("mytext",ios::in);
while (!ss.eof()){
ss>>look;
if ((look)==(s)) {c++;}
}
cout<<"\nThis word exists "<<c<<" times in the file \n\n";
}
void To_Upper (){
    char Swap[1];
// adding the text to a dummy file where i can convert each line to upper case and append there
fstream ss;
ss.open("mytext",ios::in);
// make sure the dummy file is empty and ready to take convert text line by line
fstream s;
s.open("dummy",ios::out);s.clear();s.close();
// now start.... moving each later gives the chance to convert it
s.open("dummy",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();ss.getline(Swap,2);
s.clear(); s.sync();
// converting char to upper case
Swap[0]=towupper(Swap[0]);
// add the char
s<<Swap[0];
    }
ss.close();
// simple step to make the old text file empty and ready for the new text
s.close();s.open("mytext",ios::out);s.clear();s.close();
// open files again with reversed purpose (put the text from dummy to myfile)
ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();ss.getline(Swap,2);
s.clear(); s.sync(); s << Swap;
}
cout<<"all content now are upper case . \n";
}
void To_Lower (bool f){
    char Swap[1];
// adding the text to a dummy file where i can convert each line to lower case and append there
fstream ss;
ss.open("mytext",ios::in);
// make sure the dummy file is empty and ready to take convert text line by line
fstream s;
s.open("dummy",ios::out);s.clear();s.close();
// now start.... moving each later gives the chance to convert it
s.open("dummy",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();ss.getline(Swap,2);
s.clear(); s.sync();
// converting char to lower case
Swap[0]=towlower(Swap[0]);
// add the char
s<<Swap[0];
    }
ss.close();
// simple step to make the old text file empty and ready for the new text
s.close();s.open("mytext",ios::out);s.clear();s.close();
// open files again with reversed purpose (put the text from dummy to myfile)
ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss.clear();ss.sync();ss.getline(Swap,2);
s.clear(); s.sync(); s << Swap;
}
if (f) {cout<<"all content now are lower case . \n";}
}
void First_Upper (){
To_Lower(0);
string Swap;
// adding the text to a dummy file where i can convert first char in each line to upper case and append there
fstream ss;
ss.open("mytext",ios::in);
// make sure the dummy file is empty and ready to take convert text line by line
fstream s;
s.open("dummy",ios::out);s.clear();s.close();
// now start.... moving each later gives the chance to convert it
s.open("dummy",ios::app);
while (!ss.eof()){
ss>>Swap;
// converting ther first char to upper case
Swap[0]=towupper(Swap[0]);
// add the char
s<<Swap<<' ';
    }

ss.close();
// simple step to make the old text file empty and ready for the new text
s.close();s.open("mytext",ios::out);s.clear();s.close();
// open files again with reversed purpose (put the text from dummy to myfile)
ss.open("dummy",ios::in);
s.open("mytext",ios::app);
while (!ss.eof()){
ss>>Swap;
s<<Swap<<' ';
}
cout<<"all words now starts with upper case . \n";
}
void Save (){
fstream s,ss;
string s2,Swap;
cout<<"type the target file : \n";
cin>>s2;
// make sure the target file is empty and ready to take a copy of the text
s.open(s2,ios::out);s.clear();s.close();
///////////////////////////.............................................
ss.open("mytext",ios::in);
s.open(s2,ios::app);
while (!ss.eof()){
ss>>Swap;
s<<' '<<Swap;
}
cout<<"\n Successfully saved ! \n\n";
}
