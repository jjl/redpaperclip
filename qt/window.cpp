#include <QMainWindow>

namespace redpaperclip {
namespace qt {

  struct QtWindow : public QMainWindow {
    // x, y, width, height
    static const QRect default_rect QRect(400, 300, 400, 300);
    QtWindow(char *id, char *title="RedPaperclip", QRect rect=default_rect);
    ~QtWindow();
  public slots:
  protected:
    QtWebView *webView;
    setupWindow(QRect rect, char *name);
  signals:
  }
}
}

#include <QMainWindow>

namespace redpaperclip {
namespace qt {
  QtWindow::QtWindow(char *id, char *title, QRect *rect) {
    setupWindow(id, title, rect);
  }
  QtWindow::~QtWindow() {
    delete webView;
  }
  QtWindow::setupWindow(char *id, char *title, QRect *rect) {
    webView = new QtWebview(this, rect, "wv", url);
    setCentralWidget(webView);
    setWindowTitle(QStringLiteral(title));
    setMinimumSize(QSize(100,100));
    //this->resize(476, 315);
    QMetaObject::connectSlotsByName(this);
  }
}
}
void RPQtWindow::RPQtWindow(char *id, char *title="RedPaperclip",QRect rect=default_rect) {
}
void RPQtWindow::setupWindow(char *id, char *title, QRect rect) {
}
void RPQtWindow::closeEvent(QCloseEvent *event) {
  event->accept();
}
