#include <algorithm>
#include <iostream>
/*
  * В идеале - стоит спрятать указатель под вектор.
  * Как вариант - реализовать конструкторы по-умолчанию
  * вместо вызова явного вызова заданного конструктура.
  *
  * Нужно еще реализовать оператор равенства для класса Bar, конструктор копирования
  * Ну и конструктор копирования для класса Foo
  *
  * Дополнительно - реализовать move-семантику
  *
  * Приведенных изменений достаточно, что программа в main отработала корректно
  
*/
class Foo {
public:
  Foo(int j) : size1{j} {
    i1 = new int[j]; // Foo::i1;
  }
  virtual ~Foo() { delete[] i1; }
  Foo& operator=(const Foo &foo) { // *b = *f 
    std::cout << "Operator=\n";
    delete[] Foo::i1;
    size1 = 0;
    i1 = nullptr;
    i1 = new int[foo.size1];
    size1 = foo.size1;
    std::copy(foo.i1, foo.i1 + foo.size1, Foo::i1);
    return *this;
  }
  
private:
  int size1 = 0;
  int *i1 = nullptr;
};

class Bar : public Foo {
public:
  Bar(int j) : Foo(j), size2 {j} { i2 = new char[j]; }

  ~Bar() { delete[] i2; }

private:
  int size2 = 0;
  char *i2 = nullptr;
};

int main() {
  Foo *f = new Foo(100);
  Foo *b = new Bar(200);

  *f = *b;

  delete f;
  delete b;

}
