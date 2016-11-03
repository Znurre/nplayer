#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QXmlDefaultHandler>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "StatusRequest.h"
#include "LastFmStatusParser.h"

#include "entities/StatusResponse.h"

const QString URL = "http://status.last.fm/";

QString StatusRequest::trigger() const
{
	return ".status";
}

RequestResponse StatusRequest::invoke(const QStringList &arguments, const QString &who, const RequestInvocationContext &context)
{
	Q_UNUSED(arguments);
	Q_UNUSED(who);
	Q_UNUSED(context);

	QEventLoop eventLoop;
	QNetworkAccessManager network;
	QNetworkRequest request(URL);
	QNetworkReply *reply = network.get(request);

	QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

	eventLoop.exec();

	LastFMStatusParser parser;

	QXmlInputSource source(reply);
	QXmlSimpleReader reader;
	reader.setContentHandler(&parser);
	reader.setErrorHandler(&parser);
	reader.parse(&source, false);

	const QString &message = parser.message();

	StatusResponse *response = new StatusResponse();
	response->setMessage(message);

	return RequestResponse("templates/Status.qml", response);
}
