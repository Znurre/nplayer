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

	Conditional
	{
		condition: description.length > 0

		Section
		{
			title: "Description"

			Text
			{
				text: description
				maxLength: 250
			}
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
