#include "branch.h"


Branch::Branch(){
    if(this->parent == nullptr){
        int count = std::rand()%3 + 3;
        for(int i = 0; i < count; i++){
            children.emplace_back(this);
        }
    }
}

Branch::Branch(Branch* parent_opt): parent(parent_opt){
    if(this->parent->parent == nullptr){
        int count = std::rand()%3 + 2;
        for(int i = 0; i < count; i++){
            children.emplace_back(this);
        }
    }
}

void Branch::setElfName(std::string name){
    elf_name = name;
    if(name == "None") elf_name = "";
}

void Branch::elf_name_init(){
    if (this->parent != nullptr){
        std::cout << "Enter the elf name: ";
        std::string name;
        std::cin >> name;
        this->setElfName(name);
    }

    for(auto& child: this->children){
        child.elf_name_init();
    }
}

void Branch::setElfName_auto(){
    std::string names[] = {"Legolas", "Elrond", "Arwen", "Galadriel", ""};
    elf_name = names[rand()%5];
    if(elf_name != "") elf_name += std::to_string(std::rand()%100);
}

void Branch::elf_name_auto_init(){
    if (this->parent != nullptr){
        this->setElfName_auto();
    }

    for(auto& child: this->children){
        child.elf_name_auto_init();
    }
}

void Branch::print_elf(){
    if (this->parent != nullptr){
        if(parent->parent != nullptr){
            std::cout << "Middle branch: ";
        } else {
            std::cout << "***Large branch: ";
        }
        std::cout << this->elf_name << std::endl;
    }

    for(auto& child: this->children){
        child.print_elf();
    }
}

std::string Branch::get_name(){
    return elf_name;
}

Branch* Branch::elf_search(std::string &elf_name_in){
    if(elf_name == elf_name_in) return this;

    for(auto& child: this->children){
        Branch* branch = child.elf_search(elf_name_in);
        if(branch != nullptr) return branch;
    } 
    return nullptr;
}

Branch* Branch::getTopBranch(){
    //Если это дерево
    if (parent == nullptr) return nullptr; 
    //Если это большая ветка
    if (parent->parent == nullptr) return this;
    //Если это средняя ветка
    if (parent->parent->parent == nullptr) return parent;
    return nullptr; 
}

int Branch::elf_counter(){
    int count = 0;

    if(elf_name != "") count++;

    for(auto& child: this->children){
        count += child.elf_counter();
    }
    return count;
}
