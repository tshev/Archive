import itertools

def dict_from_lists(list1, list2):
  if len(list1) > len(list2):
    return dict(itertools.zip_longest(list1, list2))
  else:
    return dict(zip(list1, list2))

if __name__ == '__main__':
  a = ["a", "b", "c"]
  b = ["A", "B"]
  print(dict_from_lists(a, b))
  print(dict_from_lists(b, a))
