import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Tag"

		Text
		{
			text: name
		}
	}

	Section
	{
		title: "Description"

		Text
		{
			text: description
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
