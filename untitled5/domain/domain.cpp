#include <sstream>

#include "domain.h"

string student::to_string(){
    stringstream  ss;
    ss<<"Id:"<<id<<"Name:"<<name<<"Grade:"<<grade<<endl;
    return ss.str();
}