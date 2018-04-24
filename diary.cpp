//
// Created by SwJ on 2018/4/23.
//
//confusions:
//1.move; 2.ctor single parameter
#include "diary.h"
typedef std::vector<Note*>::size_type vnint;
using namespace std;

/* Note ****************************************************/
string Note::Getdate()const{
    return date;
}
string Note::Getline(vsint i)const{
    return content[i];
}
void Note::Setdate(string d){
    date = move(d);
}
void Note::Setline(string s){
    content.push_back(s);
}
vsint Note::num_lines(){
    return content.size();
}
/* Diary ****************************************************/
Diary::Diary(){
    Note *mynote;
    string date;
    string line;
    ifstream fp(fpath);
    while(fp.peek()!=EOF){//read from diary.txt
        getline(fp,date);
        mynote = new Note;
        mynote->Setdate(date);
        getline(fp,line);
        while(line!="."){
            mynote->Setline(line);
            getline(fp,line);
        }
        notes.push_back(mynote);
    }
    fp.close();
}
void Diary::pdadd(string d){
    Note *mynote;
    vnint i;
    string line;
    mynote = new Note;
    mynote->Setdate(d);
    getline(cin,line);
    while(line!="."){// read inputs from sdtin
        mynote->Setline(line);
        getline(cin,line);
    }
    for(i = 0; i < notes.size(); i++){
        if(d == notes[i]->Getdate()){//update
            notes[i] = mynote;
            break;
        }
        else if(d.compare(notes[i]->Getdate())<0){//insert
            notes.insert(notes.begin()+i,mynote);
            break;
        }
    }
    if(i==notes.size())//push into the last one
        notes.push_back(mynote);
    writeback();
}
void Diary::pdlist(){
    vector<Note*>::iterator p;
    for(p = notes.begin(); p < notes.end(); p++){
        cout << (*p)->Getdate() << endl;
        cout << (*p)->Getline(0) << endl;
    }
}
void Diary::pdlist(string begin, string end){
    vector<Note*>::iterator p;
    for(p = notes.begin(); p < notes.end(); p++)
        if((*p)->Getdate().compare(begin)>=0&&(*p)->Getdate().compare(end)<=0){
            cout << (*p)->Getdate() << endl;
            cout << (*p)->Getline(0) << endl;
    }
}
void Diary::pdshow(string d){
    vector<Note*>::iterator p;
    vsint i;
    for(p = notes.begin(); p < notes.end(); p++)
        if(d == (*p)->Getdate())
            break;
    if(p == notes.end())
        cout << "Nothing is written on that date!" << endl;
    else{
        cout << (*p)->Getdate() << endl;
        for(i = 0; i < (*p)->num_lines(); i++)
            cout << (*p)->Getline(i) << endl;
    }
}
void Diary::pdremove(string d){
    vector<Note*>::iterator p;
    vsint i;
    for(p = notes.begin(); p < notes.end(); p++)
        if(d == (*p)->Getdate())
            break;
    if(p == notes.end())
        cout << "Nothing is written on that date!" << endl;
    else
        notes.erase(p);
    writeback();
}
void Diary::writeback(){
    ofstream fp(fpath);
    vsint i;
    vector<Note*>::iterator p;
    for(p = notes.begin(); p < notes.end(); p++){//write into diary.txt
        fp << (*p)->Getdate() << endl;
        for(i = 0; i < (*p)->num_lines(); i++)
            fp << (*p)->Getline(i) << endl;
        fp << "." << endl;
    }
    fp.close();
}
