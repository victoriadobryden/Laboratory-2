#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QTime>
#include <QWidget>
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class timerWidget;
}

/**
 \brief class for creating widget for single timer
  */
class timerWidget : public QWidget {
  Q_OBJECT

 public:
  /**
  \brief constructor

 first param -  time for creating timer
 second param - parent QWidget
 */
  explicit timerWidget(QTime time, QWidget* parent = nullptr);
/// destructor
  ~timerWidget();

  QTime time;

 private slots:
 
 /// slot for stop timer
  void on_StopButton_clicked();
 /// slot for pause/resume timer
  void on_pauseButton_clicked();

 private:
 ///timer
  QTimer* timer;
  Ui::timerWidget* ui;
 /// mediaplayer for sound signal
  QMediaPlayer* player;
};

#endif  ///< TIMERWIDGET_H
