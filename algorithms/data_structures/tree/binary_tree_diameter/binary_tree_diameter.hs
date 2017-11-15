data Tree = Nil | Tree `Fork` Tree
  deriving Show

leaf :: Tree
leaf = Fork Nil Nil

diameter :: Tree -> Int
diameter = snd . go
  where
    -- go keeps track of the diameter as well as the depth of the tree
    go :: Tree -> (Int, Int)
    go Nil           = (0, 0)
    go (Fork t1 t2)   = (ht, dt)
      where
      (h1, d1) = go t1
      (h2, d2) = go t2
      ht = 1 + max h1 h2
      dt = maximum [(h1 + h2), d1, d2]
