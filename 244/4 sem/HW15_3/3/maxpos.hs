maxpos :: (Ord a, Num a) => [a] -> Integer
maxpos (x1:x2:x3:xs) = let maxpos' (x1:x2:x3:xs) pos m = if ((x1 + x3) > m)
                                                         then maxpos' (x2:x3:xs) (pos + 1) (x1 + x3)
                                                         else maxpos' (x2:x3:xs) (pos + 1) m
                           maxpos' _ pos m = pos 
                       in maxpos' (x2:x3:xs) 1 (x1 + x3)
maxpos _ = error "list must have more than 2 elements"           