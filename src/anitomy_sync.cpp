/*
** Copyright (c) 2016, Thomas Farr
**
** This Source Code Form is subject to the terms of the Mozilla Public
** License, v. 2.0. If a copy of the MPL was not distributed with this
** file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include "anitomy_sync.h"
#include "utils.h"

NAN_METHOD(ParseSync) {
  std::string filename;
  if (!StringParam(info, 0, "filename", filename)) return;
}
