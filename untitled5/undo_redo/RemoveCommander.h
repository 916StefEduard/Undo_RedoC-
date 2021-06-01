//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_REMOVECOMMANDER_H
#define UNTITLED5_REMOVECOMMANDER_H


#include "commander.h"

class RemoveCommander: public commander {
public:


    explicit RemoveCommander(repository &repo);

    void undo_pop() override;

    void redo_pop() override;

    void redo_remove_handler(const student &s);

    void undo_remove_handler(const student &s);
};


#endif //UNTITLED5_REMOVECOMMANDER_H
