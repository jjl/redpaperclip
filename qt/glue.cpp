#include "redpaperclip/qt.hpp"
#include "redpaperclip/core.hpp"

#include <unistd.h> // STDIN_FILENO

using namespace redpaperclip::qt;
using namespace std;

void QtGlue::QtGlue(QObject *parent, Backend backend_) :
  QObject(parent),
  backend(backend_),
  notifier(STDIN_FILENO, QSocketNotifier::Read),
  reader()
{
  connect(&notifier, SIGNAL(activated(int)), this, SLOT(inputWaiting()));
  notifier.setEnabled(true);
}
void QtGlue::inputWaiting() {
  char buffer[8000];
  switch(auto len = read(in, buffer, sizeof(buffer))) {
  case -1: // error
    if (errno != EAGAIN)
      err(1, "oops?");
    break;
  case 0: // EOF
    // TODO: Exit
    break;
  default: // read some data
    reader.parse(buffer, len);
    auto commands = reader.take();
    cerr << "[Commands:\n";
    for(auto i = commands.begin(), end = commands.end(); i != end; ++i) {
      if(i->bad()) {
	cerr << "bad command!\n";
      }
      cerr << *i << endl;
    }
    cerr << "]\n";
  }
}
