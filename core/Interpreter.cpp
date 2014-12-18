
#include "redpaperclip/core.hpp"

#include <iostream>

using namespace redpaperclip::core;
using namespace std;

Interpreter::Interpreter(CommandReader reader_, Backend backend_)
  : reader(reader_), backend(backend_) {
}

void Interpreter::process_pending() {
  auto cmds = reader.take();
  for(auto i = cmds.begin(), end = cmds.end(); i != end; ++i) {
    process_one(*i);
  }
}

void Interpreter::process_one(Command cmd) {
  cerr << "Processed command: " << cmd << endl;
  cerr << "Command code: " << cmd.simplify() << endl;
}
