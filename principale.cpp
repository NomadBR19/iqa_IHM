#include "principale.h"
#include "ui_principale.h"

principale::principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principale)
{
    ui->setupUi(this);
}

principale::~principale()
{
    delete ui;
}

