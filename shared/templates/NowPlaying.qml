import QtQuick 2.0
import NowPlaying 1.0

Template
{
	Section
	{
		title: "%1 np".arg(user)

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

	Conditional
	{
		condition: hasTags

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
}
