#include <err.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>

#include <iostream>

#include "redpaperclip/core.hpp"
#include "redpaperclip/core/CommandReader.hpp"

#include <QSocketNotifier>

using namespace std;
using namespace redpaperclip::core;

int main(int argc, char *argv[]) {

  int in = 0; 			// fd of stdin
  int flags = fcntl(in, F_GETFL, 0) | O_NONBLOCK;
  fcntl(in, F_SETFL, flags);
  
  //auto nread = select(in+1, &readfds, NULL, NULL, NULL)

  CommandReader reader;
    
  return 0;
}

