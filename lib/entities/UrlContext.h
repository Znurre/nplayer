#ifndef URLCONTEXT_H
#define URLCONTEXT_H

#include <QObject>

class IUrlProvider;
class IInformationResource;

class UrlContext : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString url READ url CONSTANT)

	public:
		UrlContext(IUrlProvider *urlProvider, IInformationResource *resource);

		QString url() const;

	private:
		IUrlProvider *m_urlProvider;
		IInformationResource *m_resource;
};

#endif // URLCONTEXT_H
