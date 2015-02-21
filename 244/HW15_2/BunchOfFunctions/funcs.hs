reverse' :: [a] -> [a]
reverse' list = let helper (x : xs) res = helper xs (x : res)
                    helper [] res = res
                in helper list []
                
powers :: Integer -> [Integer]
powers n = [2^p | p <- [0..n]]

digitSum :: Integer -> Integer
digitSum num = if (num /= 0)
               then (num `mod` 10 + digitSum (num `div` 10))
               else 0

find :: (Eq a, Num a) => a -> [a] -> Maybe Integer
find num list = let find' (x : xs) pos = if (x == num)
                                         then Just pos
                                         else find' xs (pos + 1)
                    find' [] pos = Nothing
                in find' list 0

isPolindrom :: [Char] -> Bool
isPolindrom str = str == reverse str
