#include <iostream>
#include "branch.h"
#include <string>

int main(int, char**) {
    Branch trees[5];
    for(auto& tree: trees){
        tree.elf_name_auto_init();
    }
    
    for(auto& tree: trees){
        tree.print_elf_name();
    }

    std::cout << "Which elves are we looking for? (enter his name)" << std::endl;
    std::string elf_name;
    std::cin >> elf_name;
    Branch* found = nullptr;
    for(auto& tree: trees){
        found = tree.elf_search(elf_name);
        if(found) {
            std::cout << "Elf found." << std::endl;
            std::cout << found->get_name() << std::endl;
            std::cout << "The total number of his neighbors on one large branch = ";
            Branch* top = found->getTopBranch();
            std::cout << top->elf_counter() << std::endl;
        } 
    }
    return 0;
}
