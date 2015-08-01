import model.spider as spider
import model.schema as schema
result, ganres = spider.getFilms()
#Session = schema.sqlalchemy.sessionmaker()
Conn = schema.engine.connect()
def seed_categories(ganres):
	for g in ganres:
		Conn.execute("insert into category_names(name) values(\"%s\");"%(g))
def seed_ganres(result):
    for i in result:
      for j in i.ganre:
        Conn.execute("insert into film_categories(category_id, film_id) values((select id from category_names where name=\"%s\"), %s);"%(j, i.place))
def seed_films(result):
	for i in result:
		Conn.execute("insert into films(name) values(\"%s\")"%(i.name))
seed_categories(ganres)
seed_ganres(result)
seed_films(result)
