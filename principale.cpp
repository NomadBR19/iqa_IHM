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
    QString ville;
    ville = ui->urlEdit->text();

    afficheur.set_url("https://api.waqi.info");
    QJsonDocument documentJSON = QJsonDocument::fromJson(afficheur.get_jiqa(ville, "d9636de539c0cc32e3771e378fd51527b70526f1"));

    double iqa = afficheur.get_iqa(ville, "d9636de539c0cc32e3771e378fd51527b70526f1");
    ui->iqaSpinBox->setValue(iqa);

    if(iqa<50){ ui->lvlEdit_2->setText("bon");}
    if(iqa>50 && iqa<100){ ui->lvlEdit_2->setText("modéré");}
    if(iqa>100 && iqa<150){ ui->lvlEdit_2->setText("mauvais pour sensible");}
    if(iqa>150 && iqa<200){ ui->lvlEdit_2->setText("mauvais");}
    if(iqa>200 && iqa<300){ ui->lvlEdit_2->setText("très mauvais");}
    if(iqa>300){ ui->lvlEdit_2->setText("dangereux");}
}
void principale::changer_url()
{
    afficheur.set_url(ui->urlEdit->text());
}

