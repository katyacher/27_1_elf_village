#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

class Branch{
private:
    Branch* parent = nullptr;
    std::vector<Branch> children; 
    std::string elf_name = "";

public:
    Branch(){
        if(this->parent == nullptr){
            int count = std::rand()%3 + 3;
            for(int i = 0; i < count; i++){
                children.emplace_back(this);
            }
        }
    }

    Branch(Branch* parent_opt): parent(parent_opt){
        if(this->parent->parent == nullptr){
            int count = std::rand()%3 + 2;
            for(int i = 0; i < count; i++){
                children.emplace_back(this);
            }
        }
    }

    void setElfName(std::string name){
        elf_name = name;
        if(name == "None") elf_name = "";
    }

    void setElfName_auto(){
        std::string names[] = {"Legolas", "Elrond", "Arwen", "Galadriel", ""};
        elf_name = names[rand()%5];
    }

    void elf_name_init(){
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

    void elf_name_auto_init(){
        if (this->parent != nullptr){
            this->setElfName_auto();
        }
        for(auto& child: this->children){
            child.elf_name_auto_init();
        }
    }

    void print_elf_name(){
        if (this->parent != nullptr){
            if(parent->parent != nullptr){
                std::cout << "Small branch: ";
            } else {
                std::cout << "Big branch: ";
            }
            std::cout << this->elf_name << std::endl;
        }
        for(auto& child: this->children){
            child.print_elf_name();
        }
    }

    std::string get_name(){
        return elf_name;
    }

    Branch* elf_search(std::string &elf_name_in){
        if(elf_name == elf_name_in) return this;
        for(auto& child: this->children){
            Branch* branch = child.elf_search(elf_name_in);
            if(branch != nullptr) return branch;
        } 
        return nullptr;
    }

    Branch* getTopBranch(){
    //Если это дерево
        if (parent == nullptr) return nullptr; 
    //Если это средняя ветка
        if (parent->parent == nullptr) return parent;
    //Если это маленькая ветка
        return parent->getTopBranch();
    }

    int elf_counter(){
        int count = 0;

        if(elf_name != "") count++;

        for(auto& child: this->children){
            count += child.elf_counter();
        }
        return count;
    }
};


