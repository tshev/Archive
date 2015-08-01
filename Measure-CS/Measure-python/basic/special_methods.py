class Array:
	def __init__(self, *lst):
		print("Inited")
		self.array = list(lst)
	def __getitem__(self, index):
		return self.array[index]
	def __setitem__(self, index, value):
		array[index] = value
	def __delitem__(self,index):
		del self.array[index]
	def __contains__(self, item):
		return item in self.array
class CustomArray(Array):
	def __init__(self):
		Array.__init__(1,23,4)
		print("Custom")
a = Array(1,2,3,4)
for i in a:
	print i
CustomArray()

