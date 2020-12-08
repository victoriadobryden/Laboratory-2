#ifndef ADDTIMERDIALOG_H
#define ADDTIMERDIALOG_H

#include <QWidget>

#include "smartalarm.h"


/**
  \brief class for creating dialog for timer
  */
namespace Ui {
class addTimerDialog;
}

class addTimerDialog : public QWidget {
  Q_OBJECT

 public:
 /**
  \brief constructor

 first param - pointer to class, that contains main widget
 second param - parent QWidget
 */
  explicit addTimerDialog(SmartAlarm *a, QWidget *parent = nullptr);
  
 ///destructor
  ~addTimerDialog();

 private:
  Ui::addTimerDialog *ui;
};

#endif  ///< ADDTIMERDIALOG_H
