
#include "redpaperclip/core.hpp"

#include <locale>
#include <sstream>
#include <string>

namespace redpaperclip {
namespace core {
namespace local {

  using namespace std;

  const locale get_utf8_locale() {
    // This seems the most likely to exist utf-8 locale, but still may not
    try {
      return locale("en_US.UTF-8");
    } catch(runtime_error e) {
      throw("Owing to lazy programming, you currently require the en_US.UTF-8 locale installed for redpaperclip to work properly. Sorry about that.");
    }
  }

  const locale get_c_locale() {
    // Guaranteed to exist and treat characters as 1 byte
    return locale("C");
  }

  const ctype<wchar_t> &get_wchar_facet(std::locale l) {
    return use_facet< ctype<wchar_t> >(l);
  }

  const ctype<char> &get_char_facet(std::locale l) {
    return use_facet< ctype<char> >(l);
  }

  wstring read_utf8(const string &str) {
    auto l = get_utf8_locale();
    wostringstream wstm;
    wstm.imbue(l);
    auto facet = &get_wchar_facet(l);
    for( size_t i=0 ; i<str.size() ; ++i )
      wstm << facet->widen( str[i] );
    return wstm.str();
  }
  
  string write_utf8(const wstring &str) {
    auto l = get_c_locale();
    ostringstream stm ;
    stm.imbue(l);
    auto facet = &get_char_facet(l);
    for(size_t i=0 ; i<str.size() ; ++i)
      stm << facet->narrow(str[i], 0);
    return stm.str();
  }
  
}
}
}

