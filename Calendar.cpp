#include "Calendar.h"

#include <QMessageBox>

Calendar::Calendar()
{
}

void Calendar::ShowShedulerWindow() const
{
     QMessageBox msgBox;
     msgBox.setText("Button pushed");
     msgBox.exec();
}
