//
// Created by SwJ on 2018/4/23.
//

#ifndef WEEK4_DIARY_H
#define WEEK4_DIARY_H

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#define fpath "diary.txt"
typedef std::vector<std::string>::size_type vsint;

class Note{
private:
    std::string date;
    std::vector<std::string> content;
public:
    std::string Getdate()const;
    std::string Getline(vsint i)const;
    void Setdate(std::string d);
    void Setline(std::string s);
    std::vector<Note*>::size_type num_lines();
};

class Diary{
private:
    std::vector<Note*> notes;
public:
    Diary();
    void pdadd(std::string d);
    void pdlist();
    void pdlist(std::string begin, std::string end);
    void pdshow(std::string d);
    void pdremove(std::string d);
    void writeback();
};

#endif //WEEK4_DIARY_H
