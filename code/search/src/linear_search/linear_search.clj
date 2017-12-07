; generally in list processing languages we
; we don't work with indices but just in case
; you wanted to find position of element from list head
(defn linear-search-list
      "Returns the position of the list element from head"
      ([tlist elem]                                         ;tlist is a linked list
        (linear-search tlist elem 0))
      ([[x remm] elem idx]
        (if (= x elem)
          idx
          (recur remm elem (inc idx)))))                    ;recursive call with remaining list & args

(defn linear-search-in-vec
      "Function takes persistent vector and searches for elem"
      ([tvec elem]
        (linear-search-in-vec tvec elem idx))
      ([tvec elem idx]
        (if (= elem (get tvec idx))
          idx
          (recur tvec elem (inc idx)))))

;Example usage
(linear-search (list 1 2 3 4 5) 4)
(linear-search-in-vec (vector 1 2 3 4 5 6) 4)