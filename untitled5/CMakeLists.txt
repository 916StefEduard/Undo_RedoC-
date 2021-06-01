cmake_minimum_required(VERSION 3.17)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5 main.cpp undo_redo/UpdateCommander.cpp undo_redo/UpdateCommander.h undo_redo/RemoveCommander.cpp undo_redo/RemoveCommander.h undo_redo/AddCommander.cpp undo_redo/AddCommander.h undo_redo/commander.cpp undo_redo/commander.h ui/ui.cpp ui/ui.h repository/repository.h repository/repository.cpp domain/domain.cpp domain/domain.h)