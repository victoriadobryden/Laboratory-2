#ifndef ADDALARMDIALOG_H
#define ADDALARMDIALOG_H

#include <QWidget>

#include "smartalarm.h"

/**
 \brief class for creating dialog for alarm
*/
namespace Ui {
class addAlarmDialog;
}

class addAlarmDialog : public QWidget {
  Q_OBJECT

 public:
 /**
  * \brief constructor

 first param - pointer to class, that contains main widget
 second param - parent QWidget
 */
  explicit addAlarmDialog(SmartAlarm *a, QWidget *parent = nullptr);
  
  ///destructor
  ~addAlarmDialog();

 private:
  Ui::addAlarmDialog *ui;
};

#endif  ///< ADDALARMDIALOG_H
