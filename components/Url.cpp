#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "Url.h"
#include "QStringEx.h"

QString Url::render()
{
	return m_text;
}

QString Url::text() const
{
	return m_text;
}

void Url::setText(const QString &text)
{
	QNetworkAccessManager network;
	QEventLoop loop;

	connect(&network, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

	const QByteArray &urlEncoded = text
		.toUtf8()
		.toPercentEncoding();

	const QString &input = QString::fromUtf8(urlEncoded);
	const QString &url = QStringEx::format("http://lt3.in/s/?url=%1", input);

	const QNetworkRequest request(url);

	QNetworkReply *reply = network.get(request);

	loop.exec();

	const QByteArray &data = reply->readAll();
	const QString &encoded = QString::fromUtf8(data);

	m_text = encoded;
}
