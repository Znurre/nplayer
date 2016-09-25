#ifndef USERTRACKITERATOR_H
#define USERTRACKITERATOR_H

#include "IIterator.h"

class IUser;
class Track;

class UserTrackIterator : public PagingIterator<IUser, Track>
{
	public:
		QList<Track *> fetchMore(IUser *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERTRACKITERATOR_H
