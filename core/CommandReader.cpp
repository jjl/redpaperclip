#include <err.h>
#include <iostream>

#include "redpaperclip/core.hpp"     

using namespace redpaperclip::core;
using namespace std;

CommandId Command::simplify() {
  return InvalidCmd;
}

//! Unescapes backslashed string and updates state on failure.
void CommandReader::handle_escape(char c) {
  switch(c) {
  case 'n':
    token += '\n';
    return;
  case ' ': case '\\':
    token += c;
    return;
  default:
    state = State::ERROR;
    return;
  }
}

//! End-of-line processing and state reset.
/**
   \param error if true, push an error state rather than the parsed command.
 */
void CommandReader::eol(bool error) {
  if(error) {
    commands.push_back(Command());
  } else {
    commands.push_back(Command(command));
  }
  command.clear();
  token = "";
  state = State::BEGIN;
}

//! Parse a char array.
/**
    \param buffer Start of array.
    \param size Size of buffer in bytes.
    \returns Command%s produced by this buffer.
*/
void CommandReader::parse(const char *buffer, size_t size) {

  for(auto p = buffer; p < buffer + size; ++p) {
    auto c = *p;
    switch(state) {

    case State::BEGIN: switch(c) {
      case ' ':                 // inter-token space; skip
	continue;
      case '\n':                // EOL; emit command
	eol(false);
	continue;
      case '"':                 // start quoted token
	state = State::QUOTED;
	continue;
      default:                  // start unquoted token
	state = State::UNQUOTED;
	// goto because we need to re-parse in that state
	goto unquoted;
      }
      
    case State::ERROR: error: switch(c) {
      case '\n':                // EOL; emit error
	eol(true);
	continue;
      default:                  // non-EOL; skip
	continue;
      }
      
    case State::UNQUOTED: unquoted: switch(c) {
      case ' ':                 // end-of-token space; emit token
	command.push_back(token);
	token = "";
	state = State::BEGIN;
	continue;
      case '\n':                // EOL; emit token, then emit command
	command.push_back(token);
	eol(false);
	continue;
      case '\\':                // backslash; process escape
	state = State::UNQUOTED_ESCAPE;
	continue;
      default:                  // other; add to token
	token += c;
	continue;
      }

    case State::QUOTED: switch(c) {
      case '"':                 // end-of-token quote; emit token
	command.push_back(token);
	token = "";
	state = State::BEGIN;
	continue;
      case '\\':                // backslash; process escape
	state = State::QUOTED_ESCAPE;
	continue;
      case '\n':                // unexpected CR
	state = State::ERROR;
	goto error;
      default:                  // other; add to token
	token += c;
	continue;
      }

    case State::UNQUOTED_ESCAPE:
      state = State::UNQUOTED; // set state first as decode may change state to State::ERROR
      handle_escape(c);
      continue;
      
    case State::QUOTED_ESCAPE:
      state = State::QUOTED; // set state first as decode may change state to State::ERROR
      handle_escape(c);
      continue;

    default:
      errx(-1, "BUG: invalid state %d", state);

    }
  }
  
}

//! Retrieve and clear the parsed commands.
/**
   \return the parsed commands.
 */
vector<Command> CommandReader::take(void) {
  vector<Command> ret;
  swap(ret, commands);
  return ret;
}

namespace redpaperclip { namespace core {
    ostream &operator <<(ostream &os, const Command &cmd) {
      os << "[Command:";
      for(auto i = cmd.value.begin(), end = cmd.value.end(); i != end; ++i) {
	os << " \"" << *i << '"';
      }
      os << "]\n";
      return os;
    }
  }}
