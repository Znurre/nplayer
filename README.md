##Introduction ##
nplayer is an advanced last.fm bot developed for use in #np on quakenet (IRC) and #np:matrix.znurre.com (Matrix).

## Features ##
* User management
* Now playing
	- Currently playing song
	- Last played song
* Querying 
	- Artist info
	- Track info
	- Tag info
	- User info
	- Album info
* Showing last.fm status
* Linking/URLs
* Command chaining

## Triggers ##
**.account** username

Used to map your IRC nickname to a last.fm username.  
This is required for a few triggers such as **.np**, **.lp** and **.user** in addition to user specific stats such as play counts for artists, tracks and albums.

Please note that this trigger will set up a mapping between your current nickname and the *username* given as argument to the command.  
The bot does not keep track of nickname changes, so if you change your IRC nickname you will have to use this command again to map your new nickname to your account.


----------


**.status**

Used to query the last.fm status page for the latest status.  
In case the bot does not behave like you expect it to, this command might give you an explanation.


----------


**.ping**

Requests an immediate response from the bot.  
This command is mostly useful for troubleshooting in case the bot would be unresponsive or slow.  
If other commands take time to process but this one processes imediately, it probably means that the performance issue is on last.fm's side.


----------


**.help**

Shows a list of triggers.


----------


**.np** *nickname* --- **Track**

One of the most important triggers.  
Shows to the world what you are listening to currently.  
Can also be used to query what others are listening to by adding a nickname as argument.


----------


**.lp** *nickname* --- **Track**

Works exactly like **.np** with the exception of showing the last scrobbled song instead of the currently playing one.  
Also includes a timestamp to show when the song was scrobbled.


----------


**.user** *nickname* --- **User**

Shows information about your last.fm user or another user if a nickname is specified as parameter.


----------


**.artist** name | id --- **Artist**

Shows information about the specified artist.  
The artist name can either be specified as a name or taken from an id:

| Type | Function |
|------|----------|
| Album | Shows detailed information about the album artist |
| Artist | Shows detailed information about a similar artist |
| User | Shows detailed information about a user's top artist |
| Track | Shows detailed information about the artist of the song |
| Tag | Shows detailed information about a tag's top artist |


----------


**.artists** id

Shows a list of 10 artists for the specified id:

| Type | Function |
|------|----------|
| Artist | Shows a list of similar artists |
| User | Shows a list of a user's top artists |
| Tag | Shows a list of a tag's top artists |

**.tag** name --- **Tag**

Shows information about the specified tag.  
The tag name can either be specified as a name or taken from an id:

| Type | Function |
|------|----------|
| User | Shows detailed information about a user's top tag |


----------


**.tags** id

Shows a list of 10 tags for the specified id:

| Type | Function |
|------|----------|
| User | Shows a list of a user's top tags |

**.track** name | id --- **Track**

Shows information about the specified track.  
The track name can either be specified from an *artist - title* format, or taken from an id:

| Type | Function |
|------|----------|
| Album | Shows detailed information about an album's top track |
| Artist | Shows detailed information about an artist's top track |
| User | Shows detailed information about a user's top track |
| Track | Shows detailed information about a similar track |
| Tag | Shows detailed information about a tag's top track |


----------


**.album** id --- **Album**

Shows detailed information about the specified album.  
The album name can only be specified as an id:

| Type | Function |
|------|----------|
| Artist | Shows detailed information about an artist's top album |
| User | Shows detailed information about a user's top album |
| Track | Shows detailed information about a track's album |
| Tag | Shows detailed information about a tag's top album |


----------


**.year** id --- **User**  
**.week** id --- **User**  
**.month** id --- **User**  

These triggers are very special, in that they take an id pointing to a user and returns a new user object limited by the specified time period.  
This can be used for filtering the output for other triggers that works on user objects, such as **.album**, **.artist**, **.tag** and **.track**.


----------


**.yt** id  
**.fm** id  
**.spot** id  

These triggers returns links to YouTube, last.fm and Spotify respectively.  
Not all types of objects are supported by all URL providers, so please refer to the table below:

|        | YouTube | Spotify | Last.fm|
| :---   | :---:   | :---:   | :---:  |
| Track  | x       | x       | x      |
| Artist |         | x       | x      |
| Album  |         | x       | x      |
| Tag    |         |         | x      |
| User   |         |         | x      |

## Command chaining ##
Command chaining is one of the most powerful features of nplayer.  
All commands returning an object also comes with an id in the output.  
The type of object returned is specified in the trigger documentation above in bold after the list of arguments.

Let's take **.np** as an example.  
It returns an object of the type **Track**, which is quite obvious since it's used for posting the currently playing song.

The output can look somewhere along these lines:

> **Znurre np:** [♥] Uplift & Euphony - Hand of god | **Plays:** 35 | **Id:** 08wz

The interesting part here is the **id** attached to the output.  
Using this **id** we can refer to the trigger documentation above, and actually invoke any trigger supporting ids pointing to a **Track** object with this id as an argument.

Let's say we want more detailed information about this artist.  
We can see in the documentation that **.artist** supports working on **Track** objects.

This means that we can simply invoke **.artist** with our id as an argument, in this case we would simply type **.artist 08wz** which would give us an output similar to the following:

> **Artist:** Uplift & Euphony | **Tags:** uk Hardcore, uk Hardcore | **Listeners:** 168 | **Id:** 7kkr

A new object is returned, this time with the type **Artist**.  
Using the id of this object, we can keep querying for information.

Looking at the documentation we can see that invokig **.artist** with an id pointing to another **Artist** object will return a similar artist.  
Let's give it a try by typing **.artist 7kkr**, which will give us output resembling this:

> **Artist:** Hixxy & Styles | **Description:** Hixxy ascended to the elite class of happy hardcore DJs in the late '90s, mixing several entries in React's Bonkers series, releasing his tracks on his own Essential label, and spinning at many of the U.K.'s biggest happy hardcore events. Hixxy is pe... | **Tags:** happy hardcore, uk Hardcore, trance | **Listeners:** 5862 | **Id:** ppdp

We could keep going forever, like typing **.track ppdp** for instance, which would give us Hixxy's most popular track.

Having to type all these ids can be a bit bothersome, and therefore nplayer supports a simplified syntax for command chaining.

The above example could actually be achieved simply by typing **.np.artist.artist**, where **.np** would first get invoked, followed by **.artist** invoked with the id from **.np** and finally **.artist** would be invoked with the id from the previous artist.


## Iterators ##
Another powerful concept in nplayer is iterators.  
A lot of last.fm resources can have many child resources.

Let's take a **Tag** as an exmple.

Every tag has a list of top tracks, top artists and top albums.  
What if we want to go through all of these one by one using the bot?

Using the knowledge from the previous section about command chaining, we can easily use the same pattern here to get, let's say the top 3 artists for the tag *uk hardcore*.

We start by getting ourselves a **Tag** object by typing **.tag uk hardcore**.

> **Tag:** uk hardcore | **Description:** UK hardcore is a broad term to describe the evolved United Kingdom rave hardcore lineage 4/4-kick drum and breakbeat fueled sound, which emerged around the start of the 1990s and grew in strength during the 21st century. It is also a term used to des... | **Id:** n9ek

Okay, so we have our **Tag** object with an id and everything.  
We already know how to get the top artist for the tag by now, so we'll just type **.artist n9ek** which will give us an output similar to this:

> **Artist:** Clear Vu | **Description:** Mike Di Scala of ’Ultrabeat’ and Steve Grimes of ’The Farm’ met in 2003 to record some original dance songs influenced by the likes of Lasgo & Ian van Dahl. Steve had been writing with Christophe from Ian van Dahl for a Norwegian gospel singer Ingfri... | **Tags:** uk Hardcore, happy hardcore, trance | **Listeners:** 18577 | **Id:** qtbw

So far nothing new. We have the top artist for the tag *uk hardcore*.  
Now, if we want to keep iterating over this tag, returning one artist at a time, we can actually just keep typing **.artist n9ek** over and over again. Let's give it a try.

> **Artist:** Ultrabeat Vs Darren Styles | **Description:** The first single to be released from Ultrabeat's new album sees them join up with DJ Darren Styles. Read more on Last.fm. User-contributed text is available under the Creative Commons By-SA License; additional terms may apply. | **Tags:** hardcore, dance, uk Hardcore | **Listeners:** 9124 | **Id:** qtiw

Okay, so that was the second artist.  
We said we would get the top 3 for the tag, so let's type **.artist n9ek** one more time.

> **Artist:** DJ Kurt | **Description:** At the age of 25 Kurt has achieved so much. Having received “Best Record Label 2009” at the Hardcore Heaven awards, he also holds the title for “Best Live Act 2007” and “Best Breakthrough DJ 2008” , also having came 2nd and 3rd as “Best Producer” in ... | **Tags:** uk Hardcore, hardcore, happy hardcore | **Listeners:** 9890 | **Id:** qtpv

Okay, and there goes the third one.

We could actually keep going like this until last.fm has no more data to return.  
Your fellow channel friends would probably be quite pissed at all your spamming at that point though, so there are actually plural variants of both **.artist** and **.tag** called **.artists** and **.tags** respectively to remedy that problem.  
They will return a list of names, 10 entries at a time.

If we take the example above with *uk hardcore*, let's type **.artists n9ek**.  
You should get output similar to the following:

> **Artists:** Clear Vu, Ultrabeat Vs Darren Styles, DJ Kurt, Sy & Unknown Feat. Lou Lou, Ams, Frisky & Hujib, Squad-E, Gammer & Whizzkid, Access 3, Breeze & UFO

Okay, that's exactly 10 artists. But surely there are more artists tagged with *uk hardcore*?  
Let's type **.artists n9ek** again.

> **Artists:** Ams, Lisa Abbott, Frisky & Hujib, Squad-E, Re-Con & Squad-E, Access 3, Breeze & UFO, Lumin8, Kirsten Joy, Ham & DMO

Yet another 10 artists to check out, sweet.

Should you manage to reach the end of the iterator, the bot will let you know by simply responding with **No more data**.
