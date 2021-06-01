
#include "AddCommander.h"

AddCommander::AddCommander(repository &repo) : commander(repo) {

}


void AddCommander::undo_pop(){
    auto element=undo_array.top();
    undo_array.pop();
    undo_add_handler(element.data);
}

void AddCommander::redo_pop(){
    auto element=redo_array.top();
    redo_array.pop();
    redo_add_handler(element.data);
}

void AddCommander::redo_add_handler(const student&s){
    this->repo.add(s);
}

void AddCommander::undo_add_handler(const student& s){
    this->repo.remove(s.id);
    UndoRedoHandler handler;
    handler.old_id=0;
    handler.data=s;
    handler.operation="add";
    redo_array.push(handler);
}
