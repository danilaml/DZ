import Test.QuickCheck

length' :: [a] -> Integer
length' l = let length'' [] n = n
                length'' (x:xs) n = length'' xs (n + 1)
            in length'' l 0

counteven1 :: [Integer] -> Integer
counteven1 = foldr (\x y -> (x + 1) `mod` 2 + y) 0

counteven2 :: [Integer] -> Integer
counteven2 = length' . filter (\x -> x `mod` 2 == 0)

counteven3 :: [Integer] -> Integer
counteven3 = sum . map (\x -> (x + 1) `mod` 2)

foureq :: Integer -> Integer -> Integer -> Integer -> Bool
foureq a b c d = a == b && b == c && c == d

main = do
    quickCheck (\s -> let l = if s > 0 then [0..s] else [s..0] in 
                      foureq (counteven1 l) (counteven2 l) (counteven3 l) ((abs s) `div` 2 + 1))
