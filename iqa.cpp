#include "iqa.h"

iqa::iqa()
{
}

double iqa::get_iqa(QString ville, QString token)
{
    QUrl url = qurl;
    QString path = url.url() + "/feed/" + ville+ "/?token=" + token;
    url = QUrl(path);

    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    QJsonObject objetJSON = documentJSON.object();
    QJsonValue dataJSON = objetJSON.value("data");
    if(objetJSON.value("data").toObject().value("aqi").isDouble())
        {
            return objetJSON.value("data").toObject().value("aqi").toDouble();
        }
        else
        {
            return 0;
        }
}
QByteArray iqa::get_jiqa(QString ville, QString token)
{
    QUrl url = qurl;
        QString path = url.url() + "/feed/" + ville + "/?token=d9636de539c0cc32e3771e378fd51527b70526f1";;
        url = QUrl(path);

        return get(url);
}
QByteArray iqa::get(QUrl url)
{

    QNetworkRequest requete(url);

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}

void iqa::set_url(QString url)
{
    qurl = QUrl(url);
}
