#ifndef __REDPAPERCLIP_CORE_PARSER_HPP_INCLUDED__
#define __REDPAPERCLIP_CORE_PARSER_HPP_INCLUDED__

#include "redpaperclip/core/local.hpp"

#include <list>

#include <stdint.h>
#include <unistd.h>

namespace redpaperclip {
namespace core {
namespace parser {

  using namespace std;

  struct PState {
    wstring::const_iterator it;
    const ctype<wchar_t>& facet;
    wstring str;
    PState(const wstring &);
    ~PState();
    wstring getResult();
    bool empty();
    void skip_ws();
    bool expect(wchar_t c);
    bool expect_a(ctype_base::mask mask);
    bool parse_bareword();
    bool parse_quoted();
    bool parse_arg();
    list<wstring> pieces;
  };
  
  void parse(const wstring &str);
    
}
 
  struct Cmd {
    
  };
}
}

#endif // __REDPAPERCLIP_CORE_PARSER_HPP_INCLUDED__
