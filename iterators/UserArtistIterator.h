#ifndef USERARTISTITERATOR_H
#define USERARTISTITERATOR_H

#include <QList>

#include "IIterator.h"

class User;
class Artist;

class UserArtistIterator : public PagingIterator<User, Artist>
{
	public:
		QList<Artist *> fetchMore(User *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERARTISTITERATOR_H
