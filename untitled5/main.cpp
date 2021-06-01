#include <iostream>
#include "ui/ui.h"


int main() {
    repository repo{};
    commander commander{repo};
    AddCommander addcommand{repo};
    RemoveCommander removeCommander{repo};
    UpdateCommander updateCommander{repo};
    ui ui{repo,addcommand,removeCommander,updateCommander};
    ui.run_menu();
    return 0;
}
