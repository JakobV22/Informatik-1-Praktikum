#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>
#include "city.h"
#include "street.h"
#include "map.h"


/**
 * @brief DialogAddStreet class is used to open a dialog that asks for information to create a new Street-object
 */
namespace Ui {
class DialogAddStreet;
}

class DialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddStreet(QWidget *parent = nullptr);
    ~DialogAddStreet();
    Street* fetchStreet(Map& map) const;

private:
    Ui::DialogAddStreet *ui;
};

#endif // DIALOGADDSTREET_H
