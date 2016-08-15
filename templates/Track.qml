import QtQuick 2.0
import NowPlaying 1.0

Template
{
	property string title: "Track"

	id: template

	HighlightFilter
	{
		Section
		{
			title: template.title

			Conditional
			{
				condition: userLoved

				Text
				{
					text: "[♥]"
				}
			}

			Text
			{
				text: formattedTitle()
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
		title: "Plays"

		Text
		{
			text: userPlayCount
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
