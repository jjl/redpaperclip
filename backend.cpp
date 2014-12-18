#include <string>
#include <list>
#include <map>

namespace redpaperclip {

  using namespace redpaperclip;
  using namespace std;
  struct BackendDocument {
  };
  struct BackendWindow {
    typedef map<wstring, BackendWindow*> windowmap;
    static list<wstring> *getKeys();
    static BackendWindow *get(wstring name);
    static BackendWindow *create(wstring name, wstring title, wstring url);
    BackendDocument *getDocument();
    bool listen(wstring signals);
    BackendWindow(wstring id);
    ~BackendWindow();
  protected:
    static windowmap ws;
    wstring id;
  };
  struct BackendGlobal {
    BackendGlobal();
    resp hello();
    resp goodbye();
  };
  struct Backend {
    
  };
}
  // XCMD(WinListen) {
  //   WinListen(wstring name, wstring title, wstring url);
  // XCMD(WinGetWVs) {
  //   WinGetWVs(wstring name);
  // XCMD(WVListen) {
  //   ListenToWV(wstring name);
  // XCMD(WVGo) {
  //   WVGo(wstring url);
  // XCMD(WVForward) {
  //   WVForward(int count);
  // XCMD(WVBack) {
  //   WVBack(int count);
  // XCMD(WV) {
  //   DocInWV(wstring name);
  // XCMD(SetDocInWV) {
  //   SetDocInWV(wstring document);
  // XCMD(FindDomInDoc) {
  // XCMD(ListenToDom) {
