# Overview

The idea behind this code is that Qt (or whatever) has its own run loop, and
only calls into our code when it notices that there is pending data on our
read file descriptor. We than perform a non-blocking read to retrieve commands
from said file descriptor.

# Command Language

A command is a UTF-8 string terminated with a CR character, and is a sequence
of token separated by spaces. If a command needs to contain a CR or space
charater, these must be quoted. The quote mechanism depends on whether the
token is inside of a double-quoted string:

* In a quoted string, quote characters MUST be escaped as `\"`, space
  characters MAY be escaped as `\ `.

* In an unquoted string, quote characters MAY be escaped as `\"`, space
  characters MUST be escaped as `\ `.

Because CR and backslash are metacharacters in this language, they MUST be
escaped as `\n` and `\\` respectively. `\` MUST NOT be followed by any other
character.

# Implementation

We provide a function to be called whenever there is new data to be read on
our file descriptor, which performs a read() to drain the kernel buffer. This
read() is unlikely to contain a whole command, and may even be in the middle
of a UTF-8 character. What we do is operate a state machine that scans the
incoming octet stream and appends to a temporary std::string until
end-of-token, then perform end-of-command processing on receipt of the CR.

