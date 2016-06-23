/*
** Copyright (c) 2016, Thomas Farr
**
** This Source Code Form is subject to the terms of the Mozilla Public
** License, v. 2.0. If a copy of the MPL was not distributed with this
** file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

const anitomy = require('../anitomy');
const expect = require('chai').expect;
const fs = require('fs');
const path = require('path');

function parseSync(filename) {
  return function () {
    return anitomy.parseSync(filename);
  }
}

describe('Anitomy', function () {
  describe('#parseSync(filename)', function () {
    it('should throw Error when filename is not provided', function () {
      expect(parseSync()).to.throw(Error, 'filename must be provided');

      expect(parseSync('')).to.not.throw(Error, 'filename must be provided');
    });

    it('should throw TypeError when filename is provided but isn\'t a string', function () {
      expect(parseSync(null)).to.throw(TypeError, 'filename must be a string');
      expect(parseSync(10)).to.throw(TypeError, 'filename must be a string');
      expect(parseSync(false)).to.throw(TypeError, 'filename must be a string');
      expect(parseSync([])).to.throw(TypeError, 'filename must be a string');
      expect(parseSync({})).to.throw(TypeError, 'filename must be a string');

      expect(parseSync('')).to.not.throw(TypeError, 'filename must be a string');
    });

    it('should preserve Unicode passing from string->wstring->string', function () {
      const data = fs.readFileSync(path.resolve(__dirname, '../lib/anitomy/test/data.json'), 'utf8');
      const testData = JSON.parse(data);

      for (var i = 0; i < testData.length; i++) {
        const anime = testData[i];
        
        expect(anitomy.parseSync(anime.file_name)).to.equal(anime.file_name);
      }
    });
  });
});