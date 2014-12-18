
#include "redpaperclip/cmd.h"
#include "redpaperclip/responses.h"

// Prior to these, it was very hard to determine what was unique about a thing
#define XCMD(name) struct name : public Cmd
#define XBP(name) virtual resp run(); ~name();

namespace redpaperclip {
namespace cmds {

  using namespace redpaperclip;
  using namespace std;

  XCMD(Hello) {
    Hello();
    XBP(Hello);
  }
  XCMD(Goodbye) {
    Goodbye();
    XBP(Goodbye);
  }
  XCMD(WinAll) {
    WinAll();
    XBP(AllWins);
  }
  XCMD(WinNew) {
    WinNew(wstring name, wstring title, wstring url);
    XBP(NewWin);
  }
  XCMD(WinListen) {
    WinListen(wstring name, wstring title, wstring url);
    XBP(ListenToWin);
  }
  XCMD(WinGetWVs) {
    WinGetWVs(wstring name);
    XBP(WVsForWin);
  }
  XCMD(WVListen) {
    ListenToWV(wstring name);
    XBP(WVsForWin);
  }
  XCMD(WVGo) {
    WVGo(wstring url);
    XBP(WVGo);
  }
  XCMD(WVForward) {
    WVForward(int count);
    XBP(WVForward);
  }
  XCMD(WVBack) {
    WVBack(int count);
    XBP(WVBack);
  }
  XCMD(WV) {
    DocInWV(wstring name);
    XBP(DocInWV);
  }
  XCMD(SetDocInWV) {
    SetDocInWV(wstring document);
    XBP(SetDocInWV);
  }
  XCMD(FindDomInDoc) {
    XBP(FindDomInDoc);
  }
  XCMD(ListenToDom) {
    XBP(ListenToDom);
  }
  XCMD() {
    XBP;
  }
  XCMD() {
    XBP;
  }
  XCMD() {
    XBP;
  }
}
}

#undef XCMD
#undef XBP
