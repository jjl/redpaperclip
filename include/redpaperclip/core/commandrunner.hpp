#ifndef __REDPAPERCLIP_CORE_COMMANDRUNNER_HPP_INCLUDED__
#define __REDPAPERCLIP_CORE_COMMANDRUNNER_HPP_INCLUDED__

#include "redpaperclip/core/linereader.hpp"
#include "redpaperclip/core/parser.hpp"

namespace redpaperclip {
namespace core {

  struct CommandRunner {
    CommandRunner();
    ~CommandRunner();
    bool once();
  protected:
    LineReader reader;
  };

}
}

#endif // __REDPAPERCLIP_CORE_COMMANDRUNNER_HPP_INCLUDED__
