#include <err.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>

#include <iostream>

#include "redpaperclip/core.hpp"
#include "redpaperclip/core/CommandReader.hpp"

using namespace std;
using namespace redpaperclip::core;

int main(int argc, char *argv[]) {

  int in = 0; 			// fd of stdin
  int flags = fcntl(in, F_GETFL, 0) | O_NONBLOCK;
  fcntl(in, F_SETFL, flags);

  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(in, &readfds);
  
  char buffer[8000];

  CommandReader reader;
  
  bool exit = false;
  while(!exit) {

    switch(auto nread = select(in+1, &readfds, NULL, NULL, NULL)) {
    case -1:
      err(1, "BUG: select()");
    default:
      if(FD_ISSET(in, &readfds)) {
	FD_SET(in, &readfds);
      
	switch(auto len = read(in, buffer, sizeof(buffer))) {
	case -1: // error
	  switch(errno) {
	  case EAGAIN:
	    // do something useful!
	    continue;
	  default:
	    err(1, "oops?");
	  }
	  
	case 0: // EOF
	  exit = true;
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
    }
  }
    
  return 0;
}
