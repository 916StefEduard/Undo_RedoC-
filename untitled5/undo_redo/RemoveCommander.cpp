
#include "RemoveCommander.h"


RemoveCommander::RemoveCommander(repository &repo) : commander(repo) {

}


void RemoveCommander::undo_pop(){
    auto element=undo_array.top();
    undo_array.pop();
    undo_remove_handler(element.data);
}

void RemoveCommander::redo_pop(){
    auto element=redo_array.top();
    redo_array.pop();
    redo_remove_handler(element.data);
}

void RemoveCommander::redo_remove_handler(const student&s){
    this->repo.remove(s.id);
}


void RemoveCommander::undo_remove_handler(const student& s){
    this->repo.add(s);
    UndoRedoHandler handler;
    handler.old_id=0;
    handler.data=s;
    handler.operation="remove";
    redo_array.push(handler);
}
