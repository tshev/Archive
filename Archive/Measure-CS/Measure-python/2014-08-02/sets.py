import time
import itertools
def intersect(list1, list2):
	return set(list1) & set(list2)

def symetric_dif(l1, l2):
	s1, s2  = set(l1), set(l2)
	return (s1 - s2) | (s2 - s1)

def symetric_dif2(l1, l2):
	s1, s2 = set(l1), set(l2)
	return s1 ^ s2

def measure(f):
	def wrap(*args, **argv):
		start = time.time()
		print(f(*args, **argv))
		end = time.time()
		return end - start
	return wrap
@measure
def f(x, y):
	return symetric_dif2(x , y)
if __name__ == '__main__':
	print(f([4,5,6],[45,5,4]))
	#itertools
	num = list(range(10))
	base = itertools.product(num, num)
	#for i in range(3):
	base = itertools.product([str(i[0])+str(i[1]) for i in base ], num)
	#print list(base)
	print list(itertools.product(['1','2','3'],['0'],['a'])	)
