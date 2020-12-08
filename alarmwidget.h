#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QDateTime>
#include <QMediaPlayer>
#include <QTimer>
#include <QWidget>


/**
 \brief class for creating widget for single alarm
 */
namespace Ui {
class alarmwidget;
}

class alarmwidget : public QWidget {
  Q_OBJECT

 public:
 
 /**
  \brief constructor

 first param - day and time for creating alarm
 second param - parent QWidget
 */
  explicit alarmwidget(QDateTime dtime, QWidget* parent = nullptr);
  
  ///destructor
  ~alarmwidget();

 private:
  Ui::alarmwidget* ui;
  
  ///store day and time
  QDateTime dtime;
  
  ///timer
  QTimer* timer;
  
  ///media player for sound signal
  QMediaPlayer* player;
};

#endif  ///< ALARMWIDGET_H
