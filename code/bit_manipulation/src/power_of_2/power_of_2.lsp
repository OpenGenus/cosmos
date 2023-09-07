(defun power_of_two()
(princ "Enter number: ")
(setq n (read))
(if (equal (and (> n 0) (logand n (- n 1))) 0)
  (princ "Number is a power of two")

(princ "Number is not a power of two"))
)
(power_of_two)
