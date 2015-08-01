import itertools
def gen(stepen):
	N = len(stepen) + 1
	zeroone = []
	for i in xrange(1, N):
		c = itertools.combinations(stepen, i)
		for j in c:
			yield sum(j)
def stepen_generator(n):
	return [10**i for i in xrange(n)]
thir = stepen_generator(30)
def check(n, thir):
	for i in gen(thir):
		if i % n == 0:
			return i
num = input()
print check(num, thir)
