import model.schema as schema
conn = schema.engine.connect()
def selectFilms():
	q = """
		select films.id, films.name, group_concat(category_names.name) from films inner join film_categories, category_names where  film_categories.film_id=films.id and film_categories.category_id=category_names.id group by films.name ;
		"""
	return conn.execute(q)
