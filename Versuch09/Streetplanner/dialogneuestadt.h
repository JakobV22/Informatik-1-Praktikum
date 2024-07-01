#ifndef DIALOGNEUESTADT_H
#define DIALOGNEUESTADT_H

#include <QDialog>
#include "city.h"

namespace Ui {
class DialogNeueStadt;
}

class DialogNeueStadt : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNeueStadt(QWidget *parent = nullptr);
    ~DialogNeueStadt();
    City* fetchCity();



private:
    Ui::DialogNeueStadt *ui;
};

#endif // DIALOGNEUESTADT_H
