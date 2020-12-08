#include "addtimerdialog.h"

#include <QDebug>

#include "ui_addtimerdialog.h"

addTimerDialog::addTimerDialog(SmartAlarm *a, QWidget *parent)
    : QWidget(parent), ui(new Ui::addTimerDialog) {
  ui->setupUi(this);

 ///connect click event of cancel button on timer dialog to close event
  connect(ui->cancelButton, &QAbstractButton::clicked, this,
          &QWidget::deleteLater);
          
 ///connect click event of ok button on timer dialog to corresponing sequencing
  connect(ui->okayButton, &QAbstractButton::clicked, [a, this] {
 /// set data from ui spin boxes to timer
    a->addTimer(QTime(ui->hoursSpinBox->value(), ui->minutesSpinBox->value(),
                      ui->secSpinBox->value()));
    delete this;
  });
}


///destructor
addTimerDialog::~addTimerDialog() { delete ui; }
