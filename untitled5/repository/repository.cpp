
#include "repository.h"

#include <utility>


void repository::add(student s){
    array.push_back(s);
}

 vector<student> repository::get_array(){
    return array;
}

student repository::search(int id){
    for(auto & i : array){
        if(i.id==id){
            return i;
        }
    }
}

void repository::update(int id,student s1){
    int count=0;
    for(auto & i : array){
        if(i.id==id){
            break;
        }
        count++;
    }
    array[count]=std::move(s1);
}


void repository::remove(int id){
    int count=0;
    for(auto & i : array){
        if(i.id==id){
            break;
        }
        count++;
    }
    array.erase(array.begin()+count);
}