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
	class PluginImpl
	{
		public:
			PluginImpl(const QString &fileName, RequestRepository &repository)
				: m_loader(fileName)
				, m_fileName(fileName)
				, m_repository(repository)
			{
				qDebug() << "Loading plugin" << fileName;

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

			~PluginImpl()
			{
				qDebug() << "Unloading plugin" << m_fileName;

				QObject *instance = m_loader.instance();

				IRequestProvider *provider = qobject_cast<IRequestProvider *>(instance);
				RequestRegistrator registrator;

				if (provider)
				{
					provider->definition(registrator);
				}

				registrator.detach(m_repository);

				if (!m_loader.unload())
				{
					qDebug() << m_loader.errorString();
				}
			}

			QString fileName() const
			{
				return m_fileName;
			}

		private:
			QPluginLoader m_loader;
			QString m_fileName;

			RequestRepository &m_repository;
	};

	public:
		Plugin(const QString &fileName, RequestRepository &requestRepository)
			: m_instance(new PluginImpl(fileName, requestRepository))
		{

		}

		operator QString() const
		{
			return m_instance->fileName();
		}

	private:
		QSharedPointer<PluginImpl> m_instance;
};

#endif // IREQUESTPROVIDER_H
