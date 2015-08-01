import model.schema as schema
def getTables():
	table_names = dir(schema)
	tables = []
	for i in table_names:
		current = getattr(schema, i)
		if 'metadata' in dir(current) and current.__base__ ==schema.Base:
			tables.append(current)
	return tables
def seed():
	tables = getTables()
	for Table in tables:
		Table.metadata.create_all(schema.engine)
if __name__ == '__main__':
	seed()
