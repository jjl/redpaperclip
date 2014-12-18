#ifndef QT_GLUE_H
#define QT_GLUE_H

#include <QObject>
#include <QSocketNotifier>

namespace redpaperclip {
namespace qt {
  class QtGlue : public QObject {
    Q_OBJECT
  public:
    QtGlue(QtBackend backend_, QObject *parent=0);
    ~QtGlue();
  public slots:
    void inputWaiting();
  protected:
    QtBackend backend;
    CommandReader reader;
    QSocketNotifier notifier;
  };
}
}
#endif
