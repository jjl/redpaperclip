#include "redpaperclip.hpp"
#include "redpaperclip/cmd.hpp"
#include <string>
#include <future>

namespace redpaperclip {
  using namespace std;
  struct GlobalCommander {
    GlobalCommander();
    hello();
    static goodbye();
    static enumWindows();
  };
  struct WindowCommander {
    static enumWebviews();
  };
  struct WebviewCommander {
    WebviewCommander (wstring name);
    void getDocument();
    setDocument();
  };
  struct DocumentCommander {
  };
  struct DumbCommander {
    static resp hello();
    static resp goodbye();
    static resp enumWindows();
    static resp createWindow();
    static resp destroyWindow();
    static resp listenToWindow();
    static resp documentForWindow();
    static resp setDocumentInWindow();
    static resp listenToDocument();
    static resp 
  };
}

