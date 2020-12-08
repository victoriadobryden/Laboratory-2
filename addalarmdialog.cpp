#include "addalarmdialog.h"

#include <QList>
#include <QMessageBox>
#include <QTimeZone>

#include "ui_addalarmdialog.h"

addAlarmDialog::addAlarmDialog(SmartAlarm* a, QWidget* parent)
    : QWidget(parent), ui(new Ui::addAlarmDialog) {
  ui->setupUi(this);

  /// connect click event of cancel button on alarm dialog to close event
  connect(ui->cancelButton, &QAbstractButton::clicked, this,
          &QWidget::deleteLater);

  /// connect click event of ok button on alarm dialog to corresponing sequencing
  connect(ui->okayButton, &QAbstractButton::clicked, [a, this] {
    /// get data about time zone
    auto zone = QTimeZone(ui->comboBox->currentText().toLatin1());
    /// get data about time to set alarm
    auto time = QDateTime(ui->calendarWidget->selectedDate(),
                          ui->timeEdit->time(), zone)
                    .toLocalTime();
    /// call addAlarm method from main widget

    if (time < QDateTime::currentDateTime()) {
      QMessageBox::warning(this, "Info", "Could not wake up you in the past");
      return;
    }
    a->addAlarm(time);
    close();
  });

  /// generate list of time zones
  QList<QByteArray> ids = QTimeZone::availableTimeZoneIds();
  for (auto id : ids) {
    ui->comboBox->addItem(id);
  }

  /// set current time zone
  ui->comboBox->setCurrentText("Europe/Kiev");
}
/// destructor
addAlarmDialog::~addAlarmDialog() {
  delete ui;
}
