#include "principale.h"
#include "ui_principale.h"

principale::principale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principale)
{
    ui->setupUi(this);
    afficheur.set_url(ui->urlEdit->text());
}

principale::~principale()
{
    delete ui;
}

void principale::iqa_afficher()
{
    double iqa = afficheur.get_iqa();
    ui->iqaSpinBox->setValue(iqa);
}
void principale::changer_url()
{
    afficheur.set_url(ui->urlEdit->text());
}

