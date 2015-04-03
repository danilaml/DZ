check n (x:xs)
    | n `mod` x == 0 = False
    | n > x * 2 = check n xs
    | otherwise = True

infiprime :: [Int]
infiprime = 2 : 3 : [ x | x <- [5..], check x infiprime]
