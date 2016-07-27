#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QEventLoop>
#include <QJsonSerializer>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "Key.h"
#include "KeyValue.h"
#include "ObjectFactory.h"
#include "SignatureBuilder.h"
#include "UrlBuilder.h"

const QByteArray APIKEY = "086633358dc877dfd9c47a2812b06bc4";
const QByteArray SECRET = "02194139392e43fb7d89753185caeeb5";

class RequestHandler : public QObject
{
	public:
		RequestHandler(InformationResourceRepository &informationResourceRepository)
			: m_objectFactory(informationResourceRepository)
		{

		}

		template<class TReturn, class ...TArguments>
		TReturn *get(const QString &method, TArguments ...arguments) const
		{
			TReturn *target = new TReturn();

			get(target, method, arguments...);

			return target;
		}

		template<class TReturn, class ...TArguments>
		void get(TReturn *target, const QString &method, TArguments ...arguments) const
		{
			QList<as::KeyValue> list =
			{
				// Method specific arguments
				arguments...,

				// Default arguments
				as::api_key = APIKEY,
				as::method = method
			};

			qSort(list);

			UrlBuilder urlBuilder("http://ws.avoidpointer.com/");
			urlBuilder.setParameters(list);

			SignatureBuilder signatureBuilder(SECRET);
			signatureBuilder.setParameters(list);

			const QString &url = urlBuilder.url(signatureBuilder);
			const QNetworkRequest request(url);

			qDebug() << url;

			QEventLoop eventLoop;
			QNetworkAccessManager network;
			QJsonSerializer serializer;

			QNetworkReply *reply = network.get(request);

			connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

			eventLoop.exec();

			const QByteArray &data = reply->readAll();

			qDebug() << data;

			serializer.setObjectFactory(&m_objectFactory);
			serializer.deserialize(data, target);
		}

	private:
		ObjectFactory m_objectFactory;
};

#endif // REQUESTHANDLER_H
