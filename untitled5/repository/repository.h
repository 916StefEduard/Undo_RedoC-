//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_REPOSITORY_H
#define UNTITLED5_REPOSITORY_H
#include <vector>
#include "../domain/domain.h"
using namespace std;

class repository {
private:
    std::vector<student> array;
public:


    void add(student s);

    vector<student> get_array();

    void remove(int id);

    student search(int id);

    void update(int id, student s1);
};


#endif //UNTITLED5_REPOSITORY_H
