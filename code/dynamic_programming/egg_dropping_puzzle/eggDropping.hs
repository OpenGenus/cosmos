--- Part of Cosmos by OpenGenus Foundation
eggDropping :: Int -> Int -> Int
eggDropping floors eggs = d floors eggs
  where m = floors
        n = eggs
        d floors' 1 = floors'
        d 1 _   = 1
        d 0 _   = 0
        d _ 0 = error "No eggs left"
        d floors' eggs' = minimum [1 + maximum [ table!(floors'-i, eggs')
                                               , table!(i-1, eggs'-1)
                                               ]
                                   | i <- [1..floors']
                                  ]

        table = listArray bounds
              [d i j | (i, j) <- range bounds] -- 2D array to store intermediate results
        bounds = ((0, 0), (m, n))
