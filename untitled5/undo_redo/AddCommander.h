//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_ADDCOMMANDER_H
#define UNTITLED5_ADDCOMMANDER_H


#include "commander.h"

class AddCommander: public commander {
public:

    AddCommander(repository &repo);

    void undo_pop() override;
    stack<UndoRedoHandler> get_operations();
    void redo_pop() override;

    void add_operation(const student &s, const string &operations);

    void redo_add_handler(const student &s);

    void undo_add_handler(const student &s);
};


#endif //UNTITLED5_ADDCOMMANDER_H
