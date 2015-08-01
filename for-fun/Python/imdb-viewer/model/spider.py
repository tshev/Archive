import bs4
import requests
import collections
html = requests.get("http://ru.wikipedia.org/wiki/250_%D0%BB%D1%83%D1%87%D1%88%D0%B8%D1%85_%D1%84%D0%B8%D0%BB%D1%8C%D0%BC%D0%BE%D0%B2_%D0%BF%D0%BE_%D0%B2%D0%B5%D1%80%D1%81%D0%B8%D0%B8_IMDb")
res = bs4.BeautifulSoup(html.text)
table = res.findAll("table")
table = bs4.BeautifulSoup(str(table[1]))
tr = [ i.text for i in table.findAll("td")]

Struct = collections.namedtuple("Struct", "place name year regeser ganre")
def getFilms():
	result = []
	ganre = set()
	for i in range(0, len(tr), 5):
		[ganre.add(j) for j in tr[i+4].split(", ")]
		result.append(Struct(tr[i], tr[i+1], tr[i+2], tr[i+3], tr[i+4].split(", ")))
	return result, ganre

