#!/usr/bin/python
import itertools

def dict_from_lists(list1, list2):
  if len(list1) > len(list2):
    return dict(itertools.izip_longest(list1, list2))
  else:
    return dict(itertools.izip(list1, list2))

