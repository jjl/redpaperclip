// #include "redpaperclip.h"
// #include "redpaperclip/backends/qt.h"

namespace redpaperclip {

  void RP::run(int argc, char *argv[]) {
    new RP()->go(argc, argv);
  }

  void RP::go(int argc, char *argv[]) {
    // we should probably do something with the arguments
    interpreter->spawn(cin, cout); // this starts another thread
    backend->go(); // this won't return until exit
  }

  RP::RP() {
    interpreter = new Interpreter();
    backend = new BlackholeBackend();
  }

  ~RP::RP() {
    delete bus;
    delete backend;
  }

}
