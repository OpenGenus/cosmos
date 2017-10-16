#lang racket
(define (binary-search val l)
  (cond [(empty? l) false]
        [(equal? val (first l)) true]
        [else
         (define midpoint (quotient (length l) 2))
         (define value-at-midpoint (first (drop l midpoint)))
         (if (>= val value-at-midpoint)
             (binary-search val (drop l midpoint))
             (binary-search val (take l midpoint)))]))

(define test-list (build-list 10 values))

(display "Searching for 4 should be #t: ")
(displayln (binary-search 4 test-list))
(display "Searching for 1 should be #t: ")
(displayln (binary-search 1 test-list))
(display "Searching for 8 should be #t: ")
(displayln (binary-search 8 test-list))
(display "Searching for 11 should be #f: ")
(displayln (binary-search 11 test-list))