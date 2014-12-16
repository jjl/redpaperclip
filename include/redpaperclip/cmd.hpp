
#include <string>
#include <future>

namespace redpaperclip {
  using namespace std;
  struct Response {
    virtual wstring to_string() = 0;
  };
  typedef std::future<Response *> resp;
  struct Cmd {
    virtual resp run() = 0;
  };
}

