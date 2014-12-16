#ifndef __REDPAPERCLIP_CORE_LOCAL_HPP_INCLUDED__
#define __REDPAPERCLIP_CORE_LOCAL_HPP_INCLUDED__

#include <string>
#include <locale>

namespace redpaperclip {
namespace core {
namespace local {
 
 using namespace std;
  const locale get_utf8_locale();
  const locale get_c_locale();
  const ctype<wchar_t> &get_wchar_facet(std::locale l=get_utf8_locale());
  const ctype<char> &get_char_facet(std::locale l=get_c_locale());
  wstring read_utf8(const string &str);
  string write(const wstring &str);

}
}
}

#endif // __REDPAPERCLIP_CORE_LOCAL_HPP_INCLUDED__
