#ifndef CORE_COMMANDREADER_H
#define CORE_COMMANDREADER_H
#include <string>
#include <vector>

#include <iosfwd>

namespace redpaperclip {namespace core {
    //! a parsed command.
    /**
       This is almost a glorified typedef for std::vector<std::string>, which is the output
       of the command processor.
    */
    class Command {
      friend std::ostream &operator <<(std::ostream &, const Command &);
    public:
      const std::vector<const std::string> value;
      Command(void) {}
      Command(const std::vector<const std::string> &value_) : value(value_) {}
      bool bad(void) const { return value.empty(); }
    };

    //! a command reader.
    /**
       This class is essentially a buffer which takes in arbitrary character
       data and emits zero or more complete Command%s. This is necessary
       because the commands are coming in on a socket or other device, and the
       read(2) call may not necessarily provide a complete command.

       You would normally pass the result of the read(2) call to parse(), and
       when you are ready to process the commands, run take() to get the
       accumulated commands.
    */
    class CommandReader {
  
      //! the states for our state machine
      enum class State {
	BEGIN,                    //!< at start or between tokens
	  ERROR,                  //!< error detected
	  QUOTED,                 //!< inside quoted token
	  UNQUOTED,               //!< inside unquoted token
	  QUOTED_ESCAPE,          //!< escape inside quoted token
	  UNQUOTED_ESCAPE         //!< escape inside unquoted token
	  };
  
      std::vector<Command> commands;	      //!< untaken commands
      std::vector<const std::string> command; //!< partial command
      std::string token;		      //!< partial token
      State state;			      //!< current state

      void handle_escape(char);
      void eol(bool);
    public:
      //! default ctor
      CommandReader(void) : state(State::BEGIN) {}
      void parse(const char *, size_t);
      std::vector<Command> take(void);
    };

  }}
    
#endif
