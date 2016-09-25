#ifndef USERALBUMITERATOR_H
#define USERALBUMITERATOR_H

#include "IIterator.h"

class IUser;
class Album;

class UserAlbumIterator : public PagingIterator<IUser, Album>
{
	public:
		QList<Album *> fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERALBUMITERATOR_H
