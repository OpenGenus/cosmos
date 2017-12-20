;; Part of Cosmos by OpenGenus Foundation

;; with loop-recur
(defn fibonacci [n]
  (loop [cnt n prev 0 cur 1]
    (cond
      (= cnt 0) prev
      (= cnt 1) cur
      :else (recur (dec cnt) cur (+' prev cur)))))

;; with traditional recursion
(defn fibonacci-rec [n]
  (cond
    (= n 0) 0
    (= n 1) 1
    :else (+' (fibonacci-rec (- n 1)) (fibonacci-rec (- n 2)))))

;; prints 6765 
(println (fibonacci 20))
(println (fibonacci-rec 20))
