import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Album"

		Text
		{
			text: name
		}
	}

	Section
	{
		title: "Artist"

		Text
		{
			text: artist
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
		title: "Id"

		Text
		{
			text: id
		}
	}
}
