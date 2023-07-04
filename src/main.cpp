#include <iostream>
#include "branch.h"
#include <string>

int main(int, char**) {
    Branch trees[5];
    std::cout << "Вo you want to place elves on branches automaticall? y/n: ";
    std::string answer;
    std::cin >> answer;
    if(answer == "y"){
        for(auto& tree: trees){
            tree.elf_name_auto_init();
        }
    } else {
        for(auto& tree: trees){
            tree.elf_name_init();
        }
    }
    
    for(auto& tree: trees){
        std::cout << "Tree" << std::endl;
        tree.print_elf_name();
    }

    
    

    std::cout << "Which elves are we looking for?" << std::endl;
    std::string elf_name;
    std::cin >> elf_name;
    Branch* found = nullptr;
    for(auto& tree: trees){
        found = tree.elf_search(elf_name);
        if(found) {
            std::cout << "Elf found." << std::endl;
            //std::cout << found->get_name() << std::endl;
            std::cout << "The total number of his neighbors on one large branch = ";
            Branch* top = found->getTopBranch();
            std::cout << top->elf_counter() - 1 << std::endl;
            return 0;
        } 
    }
    std::cout << "Elf not found" << std::endl;
    return 0;
}
