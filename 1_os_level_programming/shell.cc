#include "shell.hh"

int main()
{ std::string input;
  while(true)
  { std::getline(std::cin, input);
    if (input == "ls") list();
    if (input == "new") new_file();
    if (input == "find") find();
    if (input == "python") python();
    if (input == "quit") return 0;
    if (input == "error") return 1; } }

void list()
{ std::cout << "LS" << std::endl; }

void find()
{ std::cout << "FIND" << std::endl; }

void new_file()
{ std::cout << "NEW" << std::endl; }

int python()
{ pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0)
  { // Child process
    const char* argv[] = { "python", (char*)NULL };
    if (execvp("python", (char* const*)argv ) == -1) {
      perror("lsh"); }
    exit(EXIT_FAILURE); }
  else if (pid < 0)
  { // Error forking
    perror("lsh"); } 
  else 
  { // Parent process
    do
    { wpid = waitpid(pid, &status, WUNTRACED); } 
    while (!WIFEXITED(status) && !WIFSIGNALED(status)); } }
