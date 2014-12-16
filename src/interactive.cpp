#include <queue>
#include <string>

namespace redpaperclip {
  using namespace std;
  struct Interactive {
    Interactive(std::wistream in=std::wcin, std::wostream out=std::wcout);
    ~Interactive();
    std::wistream i;
    std::wostream o;
  protected:
    CmdQueue *q;
  };
}
