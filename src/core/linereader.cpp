
#include "redpaperclip/core.hpp"

#include <cerrno>
#include <clocale>

#include <fcntl.h>
#include <sys/types.h>

#include <utility>		// pair<>
#include <vector>
#include <iostream>

namespace redpaperclip {
namespace core {

  using namespace std;
  using namespace local;
  
  LineReader::LineReader(int in_)
    : in(in_) {
    int flags = fcntl(in, F_GETFL, 0) | O_NONBLOCK;
    fcntl(in, F_SETFL, flags);
  }

  LineReader::~LineReader() {}
  
  bool LineReader::fill() {
    auto buf = vector<byte>(BUFFER_SIZE);
    switch(ssize_t len = read(in, buf.data(), BUFFER_SIZE)) {
    case -1:			// error
      switch(errno) {
      case EAGAIN:
	return true;
      default:
	wcout << "error: " << errno;
	throw("LineReader::fill could use some error handling");
      }
      break;
    case 0:			// EOF
      return false;
    default:			// read some data
      wcout << "Read " << len << " bytes\n";
      buf.resize(len);
      // buf.shrink_to_fit();
      auto last = buf.cbegin();
      for(auto i = last; i != buf.cend(); ++i) {
	wcout << "iter: " << *i << "\n";
	if ( (*i == '\n')) {
	  if (i != last) {
	    wcout << "notlast: [" << wstring(last, i) << "]\n";
	    wip.append(last, i);
	    last = next(i);
	    cout<<wip;
	    lines.push_back(read_utf8(wip));
	  }
	  wcout << "reset\n";
	  wip = string();
	}
      }
      if(last < buf.cend()) {
	wcout << "notend\n";
	//We got to the end of the buffer, but we're part-way through a command
	wip.append(last, buf.cend());
	return this->fill();
      }
      wcout << "end\n";
      return true;
    }
  }

  pair<bool, wstring> LineReader::sip(void) {
    if (lines.empty())
      return make_pair(false, wstring());

    wstring t = lines.front();
    lines.pop_front();
    return make_pair(true, t);
  }

}
}
