
#include "redpaperclip/core/commandrunner.hpp"

#include <iostream>

namespace redpaperclip {
namespace core {

  using namespace std;
  
  CommandRunner::CommandRunner() {
    reader = LineReader();
  }

  CommandRunner::~CommandRunner() {}
 
  bool CommandRunner::once() {
    if (!reader.fill())
      return false;
    
    try {
      auto ret = reader.sip();

      if (ret.first) {
	wcout << "first:[" << ret.first << "]\n";
	wcout << "second:[" << ret.second << "]\n";
	try {
	  parser::parse(ret.second);
	} catch(length_error e) {
	  wcout << "Bar";
	}
	wcout << "Yay[" << ret.second << "]\n";
      }
      return true;
    } catch(length_error e) {
      wcout << "Foo";
      return false;
    }
  }
}
}
