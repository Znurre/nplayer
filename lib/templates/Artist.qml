import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "Artist"

		Text
		{
			text: name
		}
	}

	Conditional
	{
		condition: bio.length > 0

		Section
		{
			title: "Description"

			Text
			{
				text: bio
				maxLength: 250
			}
		}
	}

	Conditional
	{
		condition: Utility.isNotEmpty(tags)

		Section
		{
			title: "Tags"

			List
			{
				values: tags
				limit: 3
			}
		}
	}

	Section
	{
		title: "Listeners"

		Text
		{
			text: listeners
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
