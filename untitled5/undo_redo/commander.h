//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_COMMANDER_H
#define UNTITLED5_COMMANDER_H
#include <vector>
#include <stack>
#include "../domain/domain.h"
#include "../repository/repository.h"

class UndoRedoHandler{
public:
    student data;
    string operation;
    int old_id;
};

class commander {

protected:
    repository &repo;
    std::stack<UndoRedoHandler> undo_array;
    std::stack<UndoRedoHandler> redo_array;
public:
     void store_operation(const student &s, const string& operations);
    explicit commander(repository &repo);
    virtual void redo_update_handler(int id, const student&s2);
    virtual void undo_update_handler(int id, const student &s2);
    virtual void store_update(int id, const student &s2, const string &operations);

    virtual void undo_pop();

    virtual void redo_pop();
};


#endif //UNTITLED5_COMMANDER_H
