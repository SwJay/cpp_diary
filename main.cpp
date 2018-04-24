#include "diary.h"
#include <map>
int main(int argc, char *argv[]) {
    Diary mydiary;
    std::map<std::string, int> instruction = {{"pdadd",0},{"pdlist",1},{"pdshow",2},{"pdremove",3}};
    switch(instruction[argv[1]]){
        case 0:
            mydiary.pdadd(argv[2]);
            break;
        case 1:
            if(argc == 2)
                mydiary.pdlist();
            else
                mydiary.pdlist(argv[2],argv[3]);
            break;
        case 2:
            mydiary.pdshow(argv[2]);
        case 3:
            mydiary.pdremove(argv[2]);
    }
    return 0;
}