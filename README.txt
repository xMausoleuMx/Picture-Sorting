A program meant to rank a collection of pictures based on how much the user likes them.
Useful if you need to trim a large collection of images or want to pick your favorites.

Ranks by showing two images and has the user pick which he likes more. The selected one will gain
a point and then the program will re-rank if necessary. 

When ranking a very large image collection it is almost impossible to get a completed selection (as at
 least n^2 comparisons would need to be made) but depending on your goal you can divide them into
 small enough subsets to be useful. In my opinion once 4 comparisons have been reached for each
 image there is enough for you to be able to trim the collection without worrying too much. A that point
 the collection should be divided into 16 almost equal sections.


Hotkeys:
F1 = Open the Github page for this project
F4 = close the program
S = save file
A = select the left image
D = select the right image


Planned features.
Allow the user to do a perfect sort of the collection, will require a full n(log n) to be sorted but may be
useful in certain situations.

Expand the support for file formats (.tiff, vectors, webm, mp4, ect.)

Beautify the UI.

Linux/MacOS compatible port

