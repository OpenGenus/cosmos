/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
/* Refactored by Adeen Shukla (adeen-s) */
#include <iostream>
#include <stddef.h>
using namespace std;


class Term {
  public:
    Term(int c, int p) {
      coeff = c;
      pow = p;
      next = NULL;
    }
    int coeff;
    int pow;
    Term* next;
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
  friend Polynomial operator+(Polynomial, Polynomial);
  void free(); 
};

// constructor 
Polynomial::Polynomial() { head = NULL; }

void Polynomial::insert_term(int c, int p) {
  if (head == NULL) {
    head = new Term(c, p);
    return;
  }
  if (p > head->pow) {
    Term* t = new Term(c, p);
    t->next = head;
    head = t;
    return;
  }
  Term* cur = head;
  while (cur != NULL) {
    if (cur->pow == p) {
      cur->coeff += c;
      return;
    }
    if ((cur->next == NULL) || (cur->next->pow < p)) {
      Term* t = new Term(c, p);
      t->next = cur->next;
      cur->next = t;
      return;
    }
    cur = cur->next;
  }
}

void Polynomial::print() {
  Term* t = head;
  while (t != NULL) {
    cout << t->coeff;
    if (t->pow) cout << "x^" << t->pow;
    if (t->next != NULL) cout << "+";
    t = t->next;
  }
  cout << endl;
}

Polynomial operator+(Polynomial p1, Polynomial p2) {
  Polynomial p;
  Term *t1 = p1.head, *t2 = p2.head;
  while ((t1 != NULL) && (t2 != NULL)) {
    if (t1->pow > t2->pow) {
      p.insert_term(t1->coeff, t1->pow);
      t1 = t1->next;
    } else if (t1->pow < t2->pow) {
      p.insert_term(t2->coeff, t2->pow);
      t2 = t2->next;
    } else {
      p.insert_term(t1->coeff + t2->coeff, t1->pow);
      t1 = t1->next;
      t2 = t2->next;
    }
  }
  while (t1 != NULL) {
    p.insert_term(t1->coeff, t1->pow);
    t1 = t1->next;
  }
  while (t2 != NULL) {
    p.insert_term(t2->coeff, t2->pow);
    t2 = t2->next;
  }
  return p;
}

void Polynomial::free() {
  Term* t = head;
  while (t) {
    Term* tmp = NULL;
    if (t->next) {
      tmp = t->next;
      delete t;
      t = tmp;
    } else {
      delete t;
      t = tmp;
    }
  }
  delete head;
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
  p3.print();
  return 0;
}
