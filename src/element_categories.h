/*
** Copyright (c) 2016, Thomas Farr
**
** This Source Code Form is subject to the terms of the Mozilla Public
** License, v. 2.0. If a copy of the MPL was not distributed with this
** file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#pragma once
#ifndef ANITOMYJS_ELEMENT_CATEGORIES_H
#define ANITOMYJS_ELEMENT_CATEGORIES_H

#include <algorithm>
#include <map>
#include <anitomy/element.h>

const std::map<std::wstring, anitomy::ElementCategory> ElementCategoryNames{
  { L"AnimeSeason",         anitomy::kElementAnimeSeason },
  { L"AnimeSeasonPrefix",   anitomy::kElementAnimeSeasonPrefix },
  { L"AnimeTitle",          anitomy::kElementAnimeTitle },
  { L"AnimeType",           anitomy::kElementAnimeType },
  { L"AnimeYear",           anitomy::kElementAnimeYear },
  { L"AudioTerm",           anitomy::kElementAudioTerm },
  { L"DeviceCompatibility", anitomy::kElementDeviceCompatibility },
  { L"EpisodeNumber",       anitomy::kElementEpisodeNumber },
  { L"EpisodeNumberAlt",    anitomy::kElementEpisodeNumberAlt },
  { L"EpisodePrefix",       anitomy::kElementEpisodePrefix },
  { L"EpisodeTitle",        anitomy::kElementEpisodeTitle },
  { L"FileChecksum",        anitomy::kElementFileChecksum },
  { L"FileExtension",       anitomy::kElementFileExtension },
  { L"FileName",            anitomy::kElementFileName },
  { L"Language",            anitomy::kElementLanguage },
  { L"Other",               anitomy::kElementOther },
  { L"ReleaseGroup",        anitomy::kElementReleaseGroup },
  { L"ReleaseInformation",  anitomy::kElementReleaseInformation },
  { L"ReleaseVersion",      anitomy::kElementReleaseVersion },
  { L"Source",              anitomy::kElementSource },
  { L"Subtitles",           anitomy::kElementSubtitles },
  { L"VideoResolution",     anitomy::kElementVideoResolution },
  { L"VideoTerm",           anitomy::kElementVideoTerm },
  { L"VolumeNumber",        anitomy::kElementVolumeNumber },
  { L"VolumePrefix",        anitomy::kElementVolumePrefix },
  { L"Unknown",             anitomy::kElementUnknown }
};

inline const std::wstring GetNameForCategory(anitomy::ElementCategory category) {
  auto pair = std::find_if(ElementCategoryNames.begin(), ElementCategoryNames.end(),
    [category](const auto& it) {
    return it.second == category;
  }
  );

  if (pair == ElementCategoryNames.end()) {
    return L"Unknown";
  }

  return pair->first;
}

#endif // !ANITOMYJS_ELEMENT_CATEGORIES_H
