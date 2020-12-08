#ifndef SMARTALARM_H
#define SMARTALARM_H

#include <QDateTime>
#include <QTime>
#include <QWidget>


/**
 \brief class for creating main widget of application

 in ui it contains 2 tabs, that represents timer and alarm
*/
QT_BEGIN_NAMESPACE
namespace Ui {
class SmartAlarm;
}
QT_END_NAMESPACE

class SmartAlarm : public QWidget {
  Q_OBJECT

 public:
 /**
 \brief constructor

  first paremetr - is QWidget parent
 */
  SmartAlarm(QWidget* parent = nullptr);
  /// destructor
  ~SmartAlarm();
  
  /**
   \brief method for creating alarm

  first parameter - ammout of time for alarm work
  */
  void addAlarm(QDateTime time);
  
  
  /**
   \brief method for creating timer

  first parameter - ammout of time for timer work
  */
  void addTimer(QTime time);

 private:
  Ui::SmartAlarm* ui;

  /// QWidget interface
 protected:
 ///event for handling application close
  void closeEvent(QCloseEvent* event);
};
#endif  ///< SMARTALARM_H
