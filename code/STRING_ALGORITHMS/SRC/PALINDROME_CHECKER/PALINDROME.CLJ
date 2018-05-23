;; Part of Cosmos by OpenGenus Foundation

(require '[clojure.string :as str])

(defn palindrome? [word]
  (let [w (str/lower-case word)]
    (= w (str/reverse w))))

(defn print-palindromes [words]
  (doseq [word words]
    (if (palindrome? word) (println word "is a palindrome"))))
      
(def words '("otto", "hello", "did", "eve", "lucas", "zZz", "sis", "clojure"))

;; otto is a palindrome
;; did is a palindrome
;; eve is a palindrome
;; zZz is a palindrome
;; sis is a palindrome
(print-palindromes words)
