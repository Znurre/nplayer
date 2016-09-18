#ifndef SPOTIFYSEARCHFRAGMENT_H
#define SPOTIFYSEARCHFRAGMENT_H

#include <QObject>
#include <QJsonSerializer>

#include "SpotifyTrack.h"

template<class TResult>
class SpotifySearchFragment : public QObject
{
	public:
		Array<TResult *> items() const
		{
			return m_items;
		}

		void setItems(const Array<TResult *> &items)
		{
			m_items = items;
		}

	private:
		Array<TResult *> m_items;
};

class SpotifyTrackSearchFragment : public SpotifySearchFragment<SpotifyTrack>
{
	Q_OBJECT

	Q_PROPERTY(Array<SpotifyTrack *> items READ items WRITE setItems)

	public:
		Q_INVOKABLE SpotifyTrackSearchFragment() = default;
};

Q_DECLARE_METATYPE(SpotifyTrackSearchFragment *)

Q_DECLARE_METATYPE(Array<SpotifyTrack *>)

#endif // SPOTIFYSEARCHFRAGMENT_H
