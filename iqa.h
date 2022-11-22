#ifndef IQA_H
#define IQA_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

class iqa
{
private:
    int aqi;
    QUrl qurl;
    QByteArray get(QUrl url);
    QByteArray post(QUrl url, QJsonObject json);
    QNetworkAccessManager m;

public:
    iqa();
    void _aqi(int aqi);
    void set_url(QString url);
    double get_iqa(QString ville, QString token);
    QByteArray get_jiqa(QString ville,QString token);
};

#endif // IQA_H
