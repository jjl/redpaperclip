#ifndef __REDPAPERCLIP_CORE_LINEREADER_HPP_INCLUDED__
#define __REDPAPERCLIP_CORE_LINEREADER_HPP_INCLUDED__

#include <string>
#include <list>
#include <unistd.h>

#include <utility>

namespace redpaperclip {
namespace core {
  using namespace std;
  class LineReader {
  protected:
    int in;
    string wip;
    list<wstring> lines;
  public:
    static const size_t BUFFER_SIZE = 64000;
    LineReader(int = STDIN_FILENO);
    ~LineReader();
    bool fill();
    pair<bool, wstring> sip();
  };
}
}

#endif // __REDPAPERCLIP_CORE_LINEREADER_HPP_INCLUDED__
