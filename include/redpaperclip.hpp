#ifndef __REDPAPERCLIP_H_INCLUDED__
#define __REDPAPERCLIP_H_INCLUDED__

namespace redpaperclip {
  // struct BackendWindow {
  //   static create(
  // };
  // struct BackendGlobal {
  // };
  // struct is default public
  struct Backend {
    virtual void go() = 0;
  };
  struct RP {
    static void run();
    void go();
  protected:
    Backend *backend;
    RP();
    ~RP();
  };
};

#endif __REDPAPERCLIP_H_INCLUDED__
