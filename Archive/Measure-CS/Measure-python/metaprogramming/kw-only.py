def recv(maxx, *, block=True):
	print(maxx)
def multiple(*v, inital=1):
	for i in v:
		inital *= i
	return inital
print(multiple(10, 23, 32, inital=10))
