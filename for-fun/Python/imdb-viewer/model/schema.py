import sqlalchemy
from sqlalchemy.ext.declarative import declarative_base
Base = declarative_base()
engine = sqlalchemy.create_engine('sqlite:////home/tshev/memory', echo=True)
class Film(Base):
	__tablename__ = 'films'
	id = sqlalchemy.Column(sqlalchemy.Integer, primary_key=True)
	name = sqlalchemy.Column(sqlalchemy.String)
	year = sqlalchemy.Column(sqlalchemy.Integer)
	img = sqlalchemy.Column(sqlalchemy.String)
class CategoryNames(Base):
	__tablename__ = 'category_names'
	id = sqlalchemy.Column(sqlalchemy.Integer, primary_key=True)
	name = sqlalchemy.Column(sqlalchemy.String)
class FilmCategory(Base):
	__tablename__ = 'film_categories'
	id = sqlalchemy.Column(sqlalchemy.Integer, primary_key=True)
	category_id = sqlalchemy.Column(sqlalchemy.Integer)
	film_id = sqlalchemy.Column(sqlalchemy.Integer)


#Base.metadata.create_all(engine) 
