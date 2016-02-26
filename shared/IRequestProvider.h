#ifndef IREQUESTPROVIDER_H
#define IREQUESTPROVIDER_H

#include <QList>
#include <QPluginLoader>

#include "RequestRepository.h"

class IRequestDefinition
{
	public:
		virtual void attach(RequestRepository &repository) = 0;
		virtual void detach(RequestRepository &repository) = 0;
};

template<class TRequest>
class RequestDefinition : public IRequestDefinition
{
	public:
		void attach(RequestRepository &repository) override
		{
			repository.attach<TRequest>();
		}

		void detach(RequestRepository &repository) override
		{
			repository.detach<TRequest>();
		}
};

class RequestDefinitionBuilder
{
	public:
		template<class TRequest>
		RequestDefinitionBuilder &request()
		{
			m_definitions << new RequestDefinition<TRequest>();

			return *this;
		}

	protected:
		QList<IRequestDefinition *> m_definitions;
};

class RequestRegistrator : public RequestDefinitionBuilder
{
	public:
		void attach(RequestRepository &repository)
		{
			for (IRequestDefinition *definition : m_definitions)
			{
				definition->attach(repository);
			}
		}

		void detach(RequestRepository &repository)
		{
			for (IRequestDefinition *definition : m_definitions)
			{
				definition->detach(repository);
			}
		}
};

class IRequestProvider : public QObject
{
	Q_OBJECT

	public:
		virtual RequestDefinitionBuilder &definition(RequestDefinitionBuilder &builder) = 0;
};

Q_DECLARE_INTERFACE(IRequestProvider, "com.avoidpointer.IRequestProvider")

class Plugin
{
	public:
		Plugin(const QString &fileName)
			: m_loader(fileName)
			, m_fileName(fileName)
		{

		}

		QString fileName() const
		{
			return m_fileName;
		}

		void load(RequestRepository &repository)
		{
			if (!m_loader.load())
			{
				qDebug() << m_loader.errorString();
			}

			QObject *instance = m_loader.instance();

			IRequestProvider *provider = qobject_cast<IRequestProvider *>(instance);
			RequestRegistrator registrator;

			if (provider)
			{
				provider->definition(registrator);
			}

			registrator.attach(repository);
		}

		void unload(RequestRepository &repository)
		{
			QObject *instance = m_loader.instance();

			IRequestProvider *provider = qobject_cast<IRequestProvider *>(instance);
			RequestRegistrator registrator;

			if (provider)
			{
				provider->definition(registrator);
			}

			registrator.detach(repository);

			if (!m_loader.unload())
			{
				qDebug() << m_loader.errorString();
			}
		}

	private:
		QPluginLoader m_loader;
		QString m_fileName;
};

#endif // IREQUESTPROVIDER_H
