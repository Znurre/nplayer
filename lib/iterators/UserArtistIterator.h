#ifndef USERARTISTITERATOR_H
#define USERARTISTITERATOR_H

#include <QList>

#include "IIterator.h"

class IUser;
class Artist;

class UserArtistIterator : public PagingIterator<IUser, Artist>
{
	public:
		QList<Artist *> fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERARTISTITERATOR_H
