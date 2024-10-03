
(defun factorial())
(princ "Enter N: ")
(setq n (read))
(setq fact 1)
(setq i 1)

(loop
       	(if (> i n)
	  (return 0)
	)
	(setq fact (* fact i))
	(setq i (+ 1 i))
)
(write n)
(princ "! = ")
(write fact)

(factorial)
