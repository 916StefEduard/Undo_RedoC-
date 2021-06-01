
#include "commander.h"


commander::commander(repository &repo):repo{repo}{

}

void commander::store_update(int id, const student &s2, const string& operations){
    UndoRedoHandler handler;
    handler.operation="update";
    handler.data=s2;
    handler.old_id=id;
    undo_array.push(handler);
}


void commander::store_operation(const student &s, const string& operations) {
    UndoRedoHandler handler;
    handler.operation=operations;
    handler.old_id=0;
    handler.data=s;
    undo_array.push(handler);
}

void commander::undo_pop(){
//    auto element=undo_array.top();
//    undo_array.pop();
//    if(element.operation=="add") {
//        undo_add_handler(element.data);
//    }else if(element.operation=="remove"){
//        undo_remove_handler(element.data);
//    }
}


void commander::redo_pop(){
//    auto element=redo_array.top();
//    redo_array.pop();
//    if(element.operation=="add") {
//        redo_add_handler(element.data);
//    }else if(element.operation=="remove"){
//        redo_remove_handler(element.data);
//    }
}


void commander::redo_update_handler(int id, const student&s2){
    this->repo.update(id, s2);
}


void commander::undo_update_handler(int id, const student&s2){
    auto student=this->repo.search(id);
    this->repo.update(id, s2);
    UndoRedoHandler handler;
    handler.old_id=s2.id;
    handler.data=student;
    handler.operation="update";
    redo_array.push(handler);
}

