def fibo(n):
	if n < 2:
		return n
	else:
		return fibo(n-2) + fibo(n-1)
def main(argv):
	print(fibo(int(argv[1])))
	return 0
if __name__ == '__main__':
	import sys
	main(sys.argv)
	
