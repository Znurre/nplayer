#ifndef INFORMATIONRESOURCEREPOSITORY_H
#define INFORMATIONRESOURCEREPOSITORY_H

#include <QHash>

class IInformationResource;

class InformationResourceRepository
{
	public:
		InformationResourceRepository();

		void add(IInformationResource *resource);

		template<class TResource>
		TResource *get(const QString &id)
		{
			IInformationResource *resource = m_resources.value(id);

			return dynamic_cast<TResource *>(resource);
		}

	private:
		QHash<QString, IInformationResource *> m_resources;
};

#endif // INFORMATIONRESOURCEREPOSITORY_H
