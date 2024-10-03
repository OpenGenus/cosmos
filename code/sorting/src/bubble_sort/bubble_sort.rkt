#lang racket

              
(define (bsort lst gt?)
  (let ((sorted (bsort-helper lst gt?)))
     (if (equal? lst sorted)
         sorted
         (bsort sorted gt?))))

(define (bsort-helper lst gt?)
    (cond ((empty? (cdr lst)) lst)
          ((gt? (car lst) (cadr lst)) (cons (cadr lst) (bsort-helper (cons (car lst) (cddr lst)) gt?)))
          (else (cons (car lst) (bsort-helper (cdr lst) gt?)))))

(display (bsort '(9 8 7 6 5 4 3 2 1) >))
(newline)
(display (bsort '(1 2 3 4 5 6 7 8 9) <))
