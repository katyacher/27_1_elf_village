#include <string>
#include <list>
#include <cstdlib>
#include <iostream>

class Branch{
private:
    Branch* parent = nullptr;
    std::list<Branch> children; 
    std::string elf_name = "";

public:

    Branch (const Branch &) = delete;
    Branch();
    Branch(Branch* parent_opt);

    void setElfName(std::string name);
    void elf_name_init();

    void setElfName_auto();
    void elf_name_auto_init();

    void print_elf();
    std::string get_name();

    Branch* elf_search(std::string &elf_name_in);
    Branch* getTopBranch();
    int elf_counter();
};


