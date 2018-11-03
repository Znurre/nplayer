import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Tags"

		ListNg
		{
			values: tags
			delegate: Text
			{
				text: name
			}
		}
	}
}
