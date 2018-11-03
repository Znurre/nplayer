#include "Utility.h"

QObject *Utility::instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
	Q_UNUSED(engine);
	Q_UNUSED(scriptEngine);

	return new Utility();
}

bool Utility::isNotEmpty(const Array<QString> &array)
{
	return !array.isEmpty();
}
