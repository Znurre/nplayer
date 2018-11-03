#ifndef INFORMATIONRESOURCEREPOSITORY_H
#define INFORMATIONRESOURCEREPOSITORY_H

#include <QHash>

class IInformationResource;

class IResourceId
{
	public:
		virtual QStringList keys() const = 0;

		operator QStringList() const
		{
			return keys();
		}
};

class TrackId : public IResourceId
{
	public:
		TrackId(const QString &id, const QString &artist, const QString &title, const QString &user)
			: m_id(id)
			, m_artist(artist)
			, m_title(title)
			, m_user(user)
		{

		}

		QStringList keys() const override
		{
			return
			{
				m_id,
				m_artist + m_title + m_user
			};
		}

	private:
		QString m_id;
		QString m_artist;
		QString m_title;
		QString m_user;
};

class InformationResourceRepository
{
	public:
		void add(IInformationResource *resource);
		void remove(IInformationResource *resource);

		template<class TResource>
		TResource *get(const QString &id) const
		{
			IInformationResource *resource = m_resources.value(id);

			return dynamic_cast<TResource *>(resource);
		}

		IInformationResource *get(const QString &id) const;

	private:
		QHash<QString, IInformationResource *> m_resources;
};

#endif // INFORMATIONRESOURCEREPOSITORY_H
