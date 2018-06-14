#include "swap.hh"

int main()
{ std::string s;
  std::string r = "";
  while(std::getline(std::cin, s))
  { for(char & c : s)
    { if (c >= 'a' && c <= 'z')
      { c -= 32; }
      else if (c >= 'A' && c <= 'Z')
      { c += 32; } }
    r += s;
    r += '\n'; }
  std::cout << r;
  return 0; }
