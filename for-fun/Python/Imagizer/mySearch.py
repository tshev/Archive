import urllib as _urllib_
import BeautifulSoup as _BeautifulSoup_
import json as _json_

from joblib import Parallel, delayed

class ImageSearch(object):
    _baseUrl = "http://ru.images.search.yahoo.com/search/images;_ylt=A2oKiZdZOqlUPxQA1ebMxgt.;_ylc=X1MDMjExNDcwMTAwNARfcgMyBGJjawNjODd2amI5YTl0ZTNyJTI2YiUzRDMlMjZzJTNEb3MEZnIDBGdwcmlkAzFIM3ZYbGVXVGdLOWE4NnhWUkdvdEEEbXRlc3RpZANudWxsBG5fc3VnZwMxMARvcmlnaW4DcnUuaW1hZ2VzLnNlYXJjaC55YWhvby5jb20EcG9zAzAEcHFzdHIDBHBxc3RybAMEcXN0cmwDNQRxdWVyeQNoZWxsbwR0X3N0bXADMTQyMDM3NjY2OQR2dGVzdGlkA251bGw-?gprid=1H3vXleWTgK9a86xVRGotA&pvid=zui2QzEwNi7EH_NaVJ64ewlsMTA5LgAAAAA2kbGB&fr2=sb-top-ru.images.search.yahoo.com&p=%s&ei=UTF-8&iscqry=&fr=sfp"

    def __init__(self, text):
        self.changeText(text)

    def changeText(self, text):
        message = text.replace(" ", "+")
        self.url = ImageSearch._baseUrl % message


    def getImages(self):
        bs = _BeautifulSoup_.BeautifulSoup(self.read())
        img_tags = bs.findAll("img")
        img_attrs = [img.attrs for img in img_tags]
        images = []
        for i in img_attrs:
            for p in i:
                if p[0] == u'src':
                    images.append(p[1])
        return images

    def read(self):
        url = _urllib_.urlopen(self.url)
        text = url.read()
        url.close()
        return text


def getWords(txt):
    word = dict()
    for i in txt:
        word[i] = word.get(i, 0) + 1
    wrd, mx = "", 0

    for key, value in word.items():
        if mx < value:
            wrd, mx = key, value
    return wrd


def getResults(txt):
    words = ''.join(c if c.isalnum() else ' ' for c in txt).split()
    result = []

    api = ImageSearch(getWords(words))

    for w in words:
        api.changeText(w)
        result += api.getImages()

    api = ImageSearch("".join(words[0:5]))
    result += api.getImages()

    return _json_.dumps({"image_sources": result})


if __name__ == '__main__':
    imgAPI = ImageSearch("hello")
    images = imgAPI.getImages()
    print images
