import unittest
from solution import dict_from_lists

class TestDictFromList(unittest.TestCase):
  def setUp(self):
    self.longer_list = [1, 2, 3, 4]
    self.shorter_list = [10, 20, 30]
  
  def test_dict_from_lists_1(self):
    dict1 = dict_from_lists(self.longer_list, self.shorter_list)
    self.assertEqual(dict1[4], None)

  def test_dict_from_lists_2(self):
    dict2 = dict_from_lists(self.shorter_list, self.longer_list)
    self.assertEqual(len(dict2), len(self.shorter_list))

  def test_dict_from_lists_3(self):
    dict1 = dict_from_lists(self.longer_list, self.shorter_list)
    self.assertEqual(dict1[1], self.shorter_list[0])

if __name__ == '__main__':
  unittest.main()
