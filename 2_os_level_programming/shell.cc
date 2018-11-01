#include "shell.hh"

int main()
{ std::string input;
  while(true)
  { std::getline(std::cin, input);
    if (input == "ls") list();
    if (input == "new") new_file();
    if (input == "find") find();
    if (input == "quit") return 0;
    if (input == "error") return 1; } }

void list()
{ std::cout << "LS" << endl; }

void find()
{ std::cout << "FIND" << endl; }

void new_file()
{ std::cout << "NEW" << endl; }
