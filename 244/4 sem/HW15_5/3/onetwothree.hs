import Test.QuickCheck

onetwothree :: Integer -> [[Integer]]
onetwothree 0 = [[]]
onetwothree n 
    | n < 0 = error "only non-negative numbers are accepted"
    | otherwise = concatMap (\x -> [1:x, 2:x, 3:x]) (onetwothree (n - 1))

main = do
    quickCheckWith stdArgs { maxSize = 20 } (\(NonNegative s) -> length (onetwothree s) == 3^s)