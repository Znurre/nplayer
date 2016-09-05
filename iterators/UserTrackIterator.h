#ifndef USERTRACKITERATOR_H
#define USERTRACKITERATOR_H

#include "IIterator.h"

class User;
class Track;

class UserTrackIterator : public PagingIterator<User, Track>
{
	public:
		QList<Track *> fetchMore(User *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERTRACKITERATOR_H
