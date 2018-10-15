;; Part of Cosmos by OpenGenus Foundation

;; with loop-recur
(defn factorial [n]
  (loop [counter n acc 1]
    (if (zero? counter)
      acc
      (recur (dec counter) (*' acc counter)))))

;; with reduce
(defn factorial-with-reduce [n]
  (reduce *' (range 1 (inc n))))

(println (factorial 10))
(println (factorial-with-reduce 10)) 
