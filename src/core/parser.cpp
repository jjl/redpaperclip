
#include "redpaperclip/core.hpp"

#include <iostream>

namespace redpaperclip {
namespace core {
namespace parser {

  using namespace std;
  using namespace local;

  void parse(const wstring &str) {
    PState ps = PState(str);
    ps.skip_ws();
    if (!ps.parse_bareword()) {
      wcout << "Malformed input: [" << wstring(ps.it, str.cend()) << "]\n";
      return;
    }
    // Consume the rest of the arguments
    do {
      ps.skip_ws();
    } while (ps.parse_arg());
    // we need to validate that the command has enough arguments
    wcout << "parse: [" << ps.getResult() << "]\n";
    // ps.parse_command(p
    // parse_args(ps);
    // auto ret = ps->getResult();
  }

  bool PState::parse_bareword() {
    wcout << "parse_bareword\n";
    if(this->empty())
      return false;

    auto old = it;
    while (it != str.cend()) {
      wcout << "pb[" << *it << "] in [" << str << "]\n";
      if (!this->expect_a(facet.alpha))
	goto DONE;
      ++it;
    }
  DONE:
    if (it == old)
      return false;
    auto n = wstring(old, it);
    wcout << "n: [" << n << "]\n";
    pieces.push_front(n);
    return true;
  }
  
  bool PState::empty() {
    return (it == str.cend());
  }

  bool PState::expect(wchar_t c) {
    return (this->empty() ? false : (*it == c));
  }

  bool PState::expect_a(ctype_base::mask mask) {
    if (this->empty())
      return false;
    wcout << "expect_a. mask: " << mask << "\n";
    wcout.flush();
    wcout << "it: [" << *it << "]\n";
    wcout.flush();
    return facet.is(mask, *it);
  }
  
  bool PState::parse_quoted() {
    wcout << "parse_quoted\n";
    if (!this->expect('"'))
      return false;

    auto old = ++it;
    for ( ; it != str.cend() ; ++it) {
      // We can't not have escape support forever
      // if (expect('\\')) {
      // }
      if (this->expect('"')) {
	pieces.push_front(wstring(old, it));
	return true;
      }
    }
    // Dangling open string
    return false;
  }
  
  bool PState::parse_arg() {
    wcout << "parse_arg\n";
    return this->parse_bareword();
    //return (this->parse_bareword() || this->parse_quoted());
  }

  void PState::skip_ws() {
    wcout << "skip_ws\n";
    while (this->expect(facet.space))
      ++it;
  }

  PState::PState(const wstring &str_)
    : it(str_.cbegin()), facet(local::get_wchar_facet()), str(str_)
  {}

  PState::~PState() {}

  wstring PState::getResult() {
    return wstring(it, str.cend());
  }
  
}
}
}

