import sys
def dif(lst):
		N, j = len(lst), -1
		if N == 2:
			if abs(lst[0] - lst[1])  + lst[1] - 1 < abs(lst[0] - lst[1])+lst[0]-1:
				return j
			else:
				return 1
		if N == 1:
			return -1
		zipped_difference = [abs(reduce(lambda x, y: x-y, (lst[i], lst[i+1]) )) for i in range(N-1)]
		basesum = sum(zipped_difference)
		minvalue = basesum
		for i in range(N-1):
			if i > 0 and i < N-2:
				tmp = basesum - zipped_difference[i-1] - zipped_difference[i+1] - zipped_difference[i] + abs(lst[i-1]-lst[i+1]) + abs(lst[i+1]-lst[i]) +  abs(lst[i] - lst[i+2])
			elif i == 0:
				tmp = basesum - zipped_difference[i]-zipped_difference[i+1] + abs(lst[i+1]-lst[i]) + abs(lst[i]-lst[i+2])
			elif i == N-2:
				tmp = basesum - zipped_difference[i] - zipped_difference[i-1] +  abs(lst[i+1] - lst[i-1]) + abs(lst[i+1]-lst[i])
			if tmp < minvalue:
					minvalue = tmp
					j = i + 1
		return j
					
def main():
	#	N = int(sys.stdin.readline())
	#lst = [int(i) for i in sys.stdin.readline().split(" ")]
	lst = [int(i) for i in open("fp").readline().split(" ")]
	print dif(lst)	
main()

