import functools 
def debug(func=None, *, d='*'):
	if func is None:
		return functools.partial(debug, d=d)
	def wrap(*args, **argv):
		print(d*10)
		return func(*args, **argv)
	return wrap
def debugmethods(cls):
	# cls is a class
	for key, value in vars(cls).items():
		if callable(value):
			setattr(cls, key, debug(value))
			print(key, value)
	return cls
@debugmethods
class A:
	@debug(d='**/')
	def a(self):
		pass
A().a()
@debug(d='s')
def m(x,y):
	return x-y
