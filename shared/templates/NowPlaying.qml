import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Znurre np"

		Text
		{
			text: artist
		}

		Text
		{
			text: "-"
		}

		Text
		{
			text: name
		}
	}

	Section
	{
		title: "Tags"

		List
		{
			values: tags
			limit: 3
		}
	}

	Section
	{
		title: "Plays"

		Text
		{
			text: userPlayCount
		}
	}
}
