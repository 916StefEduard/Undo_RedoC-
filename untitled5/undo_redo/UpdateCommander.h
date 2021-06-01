//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_UPDATECOMMANDER_H
#define UNTITLED5_UPDATECOMMANDER_H


#include "commander.h"

class UpdateCommander: public commander {
public:


    UpdateCommander(repository &repo);

    void undo_pop() override;

    void redo_pop() override;

    void store_update(int id, const student &s2, const string &operations) override;
};


#endif //UNTITLED5_UPDATECOMMANDER_H
