import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Artists"

		ListNg
		{
			values: artists
			delegate: Container
			{
				Text
				{
					text: name
				}

				Conditional
				{
					condition: userPlayCount > 0

					Text
					{
						text: "(%1)".arg(userPlayCount)
					}
				}
			}
		}
	}
}
