#ifndef USERTAGITERATOR_H
#define USERTAGITERATOR_H

#include "IIterator.h"

class User;
class Tag;

class UserTagIterator : public PagingIterator<User, Tag>
{
	public:
		QList<Tag *> fetchMore(User *resource, InformationResourceRepository &informationResourceRepository, IdGenerator &idGenerator, int page) override;
};

#endif // USERTAGITERATOR_H
