#include "../undo_redo/commander.h"
#include <iostream>
#include "ui.h"
#include "../undo_redo/AddCommander.h"
#include "../undo_redo/RemoveCommander.h"

using namespace std;



ui::ui(repository &repo, AddCommander &addCommander,RemoveCommander &removeCommander,UpdateCommander &updateCommander) : repo{repo},addCommander(addCommander),removeCommander(removeCommander),updateCommander(updateCommander)
{
    student s1,s2;
    s1.id=12;
    s1.name="Bogdan";
    s1.grade=10;
    s2.id=152;
    s2.name="Alexandru";
    s2.grade=10;
    this->repo.add(s1);
    this->repo.add(s2);
}


void ui::print_menu(){
    std::cout<<"\n";
    std::cout<<"1.List students"<<endl;
    std::cout<<"2.Add student"<<endl;
    std::cout<<"3.Remove student"<<endl;
    std::cout<<"4.Update student"<<endl;
    std::cout<<"5.Undo"<<endl;
    std::cout<<"6.Redo"<<endl;
}

void ui::ui_add(){
    student student1;
    std::cout<<"\n";
    std::cout<<"Id:";
    std::cin>>student1.id;
    std::cout<<"Name:";
    std::cin>>student1.name;
    std::cout<<"Grade:";
    std::cin>>student1.grade;
    this->repo.add(student1);
    undo_stack.push("add");
    this->addCommander.store_operation(student1,"add");
}

void ui::ui_update(){
    student student1;
    std::cout<<"\n";
    int ids;
    std::cout<<"Old_id:";
    std::cin>>ids;
    std::cout<<"New_Id:";
    std::cin>>student1.id;
    std::cout<<"New_Name:";
    std::cin>>student1.name;
    std::cout<<"New_Grade:";
    std::cin>>student1.grade;
    auto student3=this->repo.search(ids);
    this->repo.update(ids,student1);
    undo_stack.push("update");
    this->updateCommander.store_update(student1.id,student3,"update");
}


void ui::ui_undo(){
    auto element=undo_stack.top();
    redo_stack.push(element);
    undo_stack.pop();
    if(element=="add"){
        addCommander.undo_pop();
    }else if(element=="remove"){
        removeCommander.undo_pop();
    }else if(element=="update"){
        updateCommander.undo_pop();
    }
}

void ui::ui_redo(){
    auto element=redo_stack.top();
    redo_stack.pop();
    if(element=="add"){
        addCommander.redo_pop();
    }else if(element=="remove"){
        removeCommander.redo_pop();
    }else if(element=="update"){
        updateCommander.redo_pop();
    }
}

void ui::ui_remove(){
    student student1;
    std::cout<<"Id:";
    std::cin>>student1.id;
    auto student2=this->repo.search(student1.id);
    this->repo.remove(student1.id);
    undo_stack.push("remove");
    this->removeCommander.store_operation(student2,"remove");
}

void ui::print_students(){
    auto vector=std::vector<student>(this->repo.get_array());
    cout<<"\n";
    for(auto & i : vector){
        std::cout<<"Id:"<<i.id<<" Name:"<<i.name<<" Grade:"<<i.grade<<endl;
    }
}


void ui::run_menu(){
    bool done=false;
    int option;
    while(done!=true){
        print_menu();
        std::cout<<"command:";
        std::cin>>option;
        if(option==1){
                print_students();
        }else if(option==2){
            ui_add();
        }else if(option==3){
            ui_remove();
        }else if(option==5){
            ui_undo();
        }else if(option==4){
            ui_update();
        }else if(option==6){
            ui_redo();
        }
    }
}