#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>

namespace redpaperclip {
  namespace qt {
    struct Webview : public QWebView {
      Webview(QMainWindow *parent, QString *url, QtBackend *backend_);
      ~Webview();
      protected:
    };
  }
}

#include "redpaperclip.h"
#include <QMainWindow>
#include <QtWebKitWidgets>

namespace redpaperclip {
  namespace qt {
    Webview::Webview(QMainWindow *parent, QString *url, QtBackend *backend_)
    : QWebView(parent), backend(backend_) {
      setGeometry(parent.getGeometry());
      setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
      setUrl(QUrl(url));
    }
    Webview::~Webview() {
      backend = NULL;
    }
  }
}
