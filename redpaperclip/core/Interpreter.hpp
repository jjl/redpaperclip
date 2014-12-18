#ifndef CORE_INTERPRETER_H
#define CORE_INTERPRETER_H
#include <string>
#include <vector>

#include <iosfwd>

namespace redpaperclip {
namespace core {
  struct Interpreter {
    Interpreter(CommandReader reader_, Backend backend_);
    ~Interpreter() {}
    void process_pending();
    void process_one(Command cmd);
  protected:
    CommandReader reader;
    Backend backend;
  };
}}

#endif
