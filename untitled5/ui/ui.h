//
// Created by eddis on 5/31/2021.
//

#ifndef UNTITLED5_UI_H
#define UNTITLED5_UI_H


#include "../repository/repository.h"
#include "../undo_redo/commander.h"
#include "../undo_redo/AddCommander.h"
#include "../undo_redo/RemoveCommander.h"
#include "../undo_redo/UpdateCommander.h"

class ui{
private:
    repository &repo;
    AddCommander &addCommander;
    RemoveCommander &removeCommander;
    UpdateCommander &updateCommander;
    std::stack<string> undo_stack;
    std::stack<string> redo_stack;
public:
    void print_menu();
    void ui_add();
    void run_menu();
    void print_students();
    void ui_remove();
    void ui_undo();
    ui(repository &repo, AddCommander &addCommander,RemoveCommander &removeCommander,UpdateCommander &updateCommander);

    void ui_update();

    void ui_redo();
};


#endif //UNTITLED5_UI_H
