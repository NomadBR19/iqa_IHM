#include "iqa.h"

iqa::iqa()
{
}

double iqa::get_iqa()
{
    QUrl url = qurl;
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    QJsonObject objetJSON = documentJSON.object();

    if(objetJSON.value("aqi").isDouble())
    {
        aqi = objetJSON.value("aqi").toDouble();
        return aqi;
    }
    else
    {
        return 0;
    }
}

QByteArray iqa::get(QUrl url)
{

    QNetworkRequest requete(url);

//    //Pour la gestion de la connexion sécurisée SSL (HTTPS)
//    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
//    config.setProtocol(QSsl::TlsV1_2);
//    requete.setSslConfiguration(config);

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