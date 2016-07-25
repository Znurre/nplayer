#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "ITemplateComponent.h"

class Conditional : public ITemplateComponent
{
	Q_OBJECT

	Q_PROPERTY(bool condition READ condition WRITE setCondition NOTIFY conditionChanged)

	public:
		Conditional();

		bool condition() const;
		void setCondition(bool condition);

		QString render() override;

	private:
		bool m_condition;

	signals:
		void conditionChanged();
};

#endif // CONDITIONAL_H
