import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Username"

		HighlightFilter
		{
			Text
			{
				text: user
			}
		}
	}

	Section
	{
		title: "Join date"

		Text
		{
			text: Qt.formatDateTime(registered, "yyyy-MM-dd")
		}
	}

	Section
	{
		title: "Play count"

		Text
		{
			text: playCount
		}
	}

	Section
	{
		title: "Country"

		Text
		{
			text: country
		}
	}

	Section
	{
		title: "Id"

		Text
		{
			text: id
		}
	}
}
