#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class principale; }
QT_END_NAMESPACE

class principale : public QMainWindow
{
    Q_OBJECT

public:
    principale(QWidget *parent = nullptr);
    ~principale();

private:
    Ui::principale *ui;
};
#endif // PRINCIPALE_H
