//
// Created by eddis on 5/31/2021.
//

#include "UpdateCommander.h"

UpdateCommander::UpdateCommander(repository &repo) : commander(repo) {

}

void UpdateCommander::store_update(int id, const student &s2, const string& operations){
    UndoRedoHandler handler;
    handler.operation="update";
    handler.data=s2;
    handler.old_id=id;
    undo_array.push(handler);
}

void UpdateCommander::undo_pop(){
    auto element=undo_array.top();
    undo_array.pop();
    undo_update_handler(element.old_id,element.data);
}

void UpdateCommander::redo_pop(){
    auto element=redo_array.top();
    redo_array.pop();
   redo_update_handler(element.old_id,element.data);
}