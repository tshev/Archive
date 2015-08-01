#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
#include <fstream>
std::fstream FILES("main");
std::vector<int> create(const int &count) {
  std::vector<int> res(count);
  for (int i = 0; i < count; i++) {
    res[i] = pow(10, i);
  }
  return res;
}
std::set<int> generator(std::vector<int> vector, int i) {
  std::vector<int> result;
  std::sort(vector.begin(), vector.end());
  while (std::next_permutation(vector.begin(), vector.end())) {
  for(int xi = 0; xi < i; xi++)  result.push_back(
   std::accumulate(vector.begin(), vector.begin()+xi, 0,
                          [](const int &x, const int &y) { return x + y; }));
    }
		std::cout << "Iter " << i  << std::endl;
	std::set<int> set(result.begin(), result.end());
	std::for_each(set.begin(), set.end(), [](const int &x){ FILES << x <<"\n";});
	return set;
}
void render(std::ostream &cout) {
	int length = 20;
	std::vector< std::set<int> > collection;
	for(int i = 1; i < length; i++) {
		collection.push_back(generator(create(i), i));
		/*	
		for(auto p = v.begin(); p != v.end(); p++) {
		std::cout << *p << std::endl;
		cout << *p << std::endl;
		*/
	}
}
int main() { 
	std::fstream file("fileCont"); 
	render(file);
}
