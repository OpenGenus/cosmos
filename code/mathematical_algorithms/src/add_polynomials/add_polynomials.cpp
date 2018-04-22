/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
/* Refactored by Adeen Shukla (adeen-s) */
#include <iostream>
#include <cstddef>
using namespace std;


class Term {
  private:
    int coeff_;
    int pow_;
    Term* next_;
  public:
    Term(int c, int p): coeff_(c), pow_(p), next_(nullptr) {}
    void setCoeff(int c) {coeff_ = c;}
    int getCoeff() {return coeff_;}
    void setPow(int p) {pow_ = p;}
    int getPow() {return pow_;}
    Term* getNext() {return next_;}
    void setNext(Term* n) {next_ = n;}
};

class Polynomial {
 private:
  Term* head;
  void free();

 public:
  Polynomial();
  ~Polynomial() {
    free();
  }
  void insertTerm(int, int);
  void print();
  friend ostream& operator<< (ostream& stream, Polynomial poly);
  friend Polynomial operator+(Polynomial, Polynomial); 
};

// constructor 
Polynomial::Polynomial() { head = nullptr; }

void Polynomial::insertTerm(int c, int p) {
  if (!head) {
    head = new Term(c, p);
    return;
  }
  if (p > head->getPow()) {
    Term* t = new Term(c, p);
    t->setNext(head);
    head = t;
    return;
  }
  Term* cur = head;
  while (cur) {
    if (cur->getPow() == p) {
      cur->setCoeff(cur->getCoeff()+c);
      return;
    }
    if ((!cur->getNext()) || (cur->getNext()->getPow() < p)) {
      Term* t = new Term(c, p);
      t->setNext(cur->getNext());
      cur->setNext(t);
      return;
    }
    cur = cur->getNext();
  }
}

void Polynomial::print() {
  Term* t = head;
  while (t) {
    cout << t->getCoeff();
    if (t->getPow()) cout << "x^" << t->getPow();
    if (t->getNext()) cout << "+";
    t = t->getNext();
  }
  cout << endl;
}

Polynomial operator+(Polynomial p1, Polynomial p2) {
  Polynomial p;
  Term *t1 = p1.head, *t2 = p2.head;
  while (t1 && t2) {
    if (t1->getPow() > t2->getPow()) {
      p.insertTerm(t1->getCoeff(), t1->getPow());
      t1 = t1->getNext();
    } else if (t1->getPow() < t2->getPow()) {
      p.insertTerm(t2->getCoeff(), t2->getPow());
      t2 = t2->getNext();
    } else {
      p.insertTerm(t1->getCoeff() + t2->getCoeff(), t1->getPow());
      t1 = t1->getNext();
      t2 = t2->getNext();
    }
  }
  while (t1) {
    p.insertTerm(t1->getCoeff(), t1->getPow());
    t1 = t1->getNext();
  }
  while (t2) {
    p.insertTerm(t2->getCoeff(), t2->getPow());
    t2 = t2->getNext();
  }
  return p;
}

ostream& operator<< (ostream& stream, Polynomial poly) {
  Term* t = poly.head;
  while (t) {
    stream << t->getCoeff();
    if (t->getPow()) stream << "x^" << t->getPow();
    if (t->getNext()) stream << "+";
    t = t->getNext();
  }
  stream << "\n";
  return stream;
}

void Polynomial::free() {
  Term* t = head;
  while (t) {
    Term* tmp = nullptr;
    if (t->getNext()) {
      tmp = t->getNext();
      delete t;
      t = tmp;
    } else {
      delete t;
      t = tmp;
    }
  }
}

int main() {
  Polynomial p1, p2;
  p1.insertTerm(7, 4);
  p1.insertTerm(4, 5);
  p1.insertTerm(10, 0);
  p1.insertTerm(9, 2);
  cout << "First polynomial:";
  p1.print();
  p2.insertTerm(5, 0);
  p2.insertTerm(6, 5);
  p2.insertTerm(7, 0);
  p2.insertTerm(3, 2);
  cout << "Second polynomial:";
  p2.print();
  Polynomial p3 = p1 + p2;
  cout << "Sum:";
  cout << p3;
  return 0;
}
