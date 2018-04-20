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
    void set_coeff(int c) {coeff_ = c;}
    int get_coeff() {return coeff_;}
    void set_pow(int p) {pow_ = p;}
    int get_pow() {return pow_;}
    Term* get_next() {return next_;}
    void set_next(Term* n) {next_ = n;}
};

class Polynomial {
 private:
  Term* head;

 public:
  Polynomial();
  ~Polynomial() {
    free();
  }
  void insert_term(int, int);
  void print();
  friend ostream& operator<< (ostream& stream, Polynomial poly);
  friend Polynomial operator+(Polynomial, Polynomial);
  void free(); 
};

// constructor 
Polynomial::Polynomial() { head = nullptr; }

void Polynomial::insert_term(int c, int p) {
  if (!head) {
    head = new Term(c, p);
    return;
  }
  if (p > head->get_pow()) {
    Term* t = new Term(c, p);
    t->set_next(head);
    head = t;
    return;
  }
  Term* cur = head;
  while (cur) {
    if (cur->get_pow() == p) {
      cur->set_coeff(cur->get_coeff()+c);
      return;
    }
    if ((!cur->get_next()) || (cur->get_next()->get_pow() < p)) {
      Term* t = new Term(c, p);
      t->set_next(cur->get_next());
      cur->set_next(t);
      return;
    }
    cur = cur->get_next();
  }
}

void Polynomial::print() {
  Term* t = head;
  while (t) {
    cout << t->get_coeff();
    if (t->get_pow()) cout << "x^" << t->get_pow();
    if (t->get_next()) cout << "+";
    t = t->get_next();
  }
  cout << endl;
}

Polynomial operator+(Polynomial p1, Polynomial p2) {
  Polynomial p;
  Term *t1 = p1.head, *t2 = p2.head;
  while (t1 && t2) {
    if (t1->get_pow() > t2->get_pow()) {
      p.insert_term(t1->get_coeff(), t1->get_pow());
      t1 = t1->get_next();
    } else if (t1->get_pow() < t2->get_pow()) {
      p.insert_term(t2->get_coeff(), t2->get_pow());
      t2 = t2->get_next();
    } else {
      p.insert_term(t1->get_coeff() + t2->get_coeff(), t1->get_pow());
      t1 = t1->get_next();
      t2 = t2->get_next();
    }
  }
  while (t1) {
    p.insert_term(t1->get_coeff(), t1->get_pow());
    t1 = t1->get_next();
  }
  while (t2) {
    p.insert_term(t2->get_coeff(), t2->get_pow());
    t2 = t2->get_next();
  }
  return p;
}

ostream& operator<< (ostream& stream, Polynomial poly) {
  Term* t = poly.head;
  while (t) {
    stream << t->get_coeff();
    if (t->get_pow()) stream << "x^" << t->get_pow();
    if (t->get_next()) stream << "+";
    t = t->get_next();
  }
  stream << "\n";
  return stream;
}

void Polynomial::free() {
  Term* t = head;
  while (t) {
    Term* tmp = nullptr;
    if (t->get_next()) {
      tmp = t->get_next();
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
  p1.insert_term(7, 4);
  p1.insert_term(4, 5);
  p1.insert_term(10, 0);
  p1.insert_term(9, 2);
  cout << "First polynomial:";
  p1.print();
  p2.insert_term(5, 0);
  p2.insert_term(6, 5);
  p2.insert_term(7, 0);
  p2.insert_term(3, 2);
  cout << "Second polynomial:";
  p2.print();
  Polynomial p3 = p1 + p2;
  cout << "Sum:";
  cout << p3;
  return 0;
}
