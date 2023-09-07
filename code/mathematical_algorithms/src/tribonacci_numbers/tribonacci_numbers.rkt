#lang racket

(define (trib n)
  (cond
    [(< n 2) 0]
    [(= n 2) 1]
    [(> n 2) ( + (trib (- n 1)) (trib (- n 2)) (trib (- n 3)))]))
    

(define (tribonacci n)
  (write (trib n))
  (display #\space)
  (when (> n 0) (tribonacci (- n 1))))

  