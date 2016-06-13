# AnitomyJS
NodeJS binding for [Anitomy](https://github.com/erengy/anitomy), an anime video filename parsing library.

## Using it
```javascript
// Require the library.
var anitomyjs = require('anitomyjs');

// Construct a new Anitomy instance.
var anitomy = new anitomyjs.Anitomy();

// Parse a filename
var success = anitomy.parse('[TaigaSubs]_Toradora!_(2008)_-_01v2_-_Tiger_and_Dragon_[1280x720_H.264_FLAC][1234ABCD].mkv');

// Get the elements
var elements = anitomy.elements();

// Output some info
console.log(elements.get('AnimeTitle') + " #" + elements.get('EpisodeNumber') + ' by ' + elements.get('ReleaseGroup'));
```

## Currently Implemented
  * Constructing Anitomy instances.
  * Parsing filenames, Note: lowercase function name 'parse' rather than 'Parse'.
  * Getting elements collection, same as Anitomy.
  * Nearly all of the elements collection functions, same as Anitomy, except for a few to do with iterators. Note: get_all returns a JS array.
  * Element categories, but are represented as strings, with same names as Anitomy, but without the "anitomy::kElement" prefix, ie. 'AnimeTitle' rather than anitomy::kElementAnimeTitle, 'EpisodeNumber', 'ReleaseGroup' etc.

Listing:
```javascript
new anitomyjs.Anitomy();
Anitomy.parse(filename);
Anitomy.elements();

Elements.empty();
Elements.empty(category);
Elements.size();
Elements.at(index);
Elements[index];
Elements.get(category);
Elements.get_all(category);
Elements.clear();
Elements.insert(category, value);
Elements.erase(category);
Elements.count(category);
```

## To Be Implemented
  * Anitomy.options()
  * Anitomy.tokens()

## License
*AnitomyJS* is licensed under [Mozilla Public License 2.0](https://www.mozilla.org/en-US/MPL/2.0/FAQ/).