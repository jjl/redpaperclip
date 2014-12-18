
#include <string>
#include <future>
#include <QSocketNotifier>

namespace redpaperclip {
  namespace qt {
    using namespace std;
    // struct QtBElement : public BackendElement {
    //   QtBElement();
    //   ~QtBElement();
    //   // These two operate on the inside of the element
    //   void push(wstring markup);
    //   void unshift(wstring markup);
    //   // These two operate on the outside of the element
    //   void addBefore(wstring markup);
    //   void addAfter(wstring markup);
    //   void replaceWith(wstring markup);
    //   void wrap(wstring markup); // inserts self into the most nested element
    //   void js(wstring code);
    //   void empty(); // eats children
    //   void eat(); // eats self and children
    //   void cssclass(wstring name, bool remove=false); // multi-purpose add/remove css class
    //   void css(wstring prop, wstring val); // inline styles
    //   void geometry(); // we can use this to get positions on the page etc.
    //   void focus(); // set focus
    //   void setChildren(wstring markup); // eat() + push()
    // };
    // struct QtBDocument : public BackendDocument {
    //   QtBDocument();
    //   ~QtBDocument();
    // };
    // struct QtBWindow : public BackendWindow {
    //   QtBWindow();
    //   ~QtBWindow();
    //   wstring id;
    // };
    // struct QtBGlobal : public BackendGlobal {
    //   QtBGlobal();
    //   ~QtBGlobal();
    // };
    struct QtBackend : public Backend {
      QSocketNotifier sn(in, QSocketNotifier::Read);
      QtBackend(
      ~QtBackend();
      virtual void start();
      virtual void stop();
    protected:
      QSocketNotifier notifier;
    };
  }
};

using namespace redpaperclip::core;
using namespace redpaperclip::qt;
using namespace std;

}
}

