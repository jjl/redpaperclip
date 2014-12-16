
#include "redpaperclip/core.hpp"

using namespace std;
using namespace redpaperclip::core;

int main(int argc, char *argv[]) {
  auto c = CommandRunner();
  while (c.once()) {}
  return 0;
}
