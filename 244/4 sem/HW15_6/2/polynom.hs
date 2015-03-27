import Test.QuickCheck

newtype Polynom = P [Int] deriving (Eq)

instance Show Polynom where
    show (P l) = let sign x = if (x > 0) then "+" else "" in
                 let showhelp (0:xs) n = showhelp xs (n+1)
                     showhelp (x:xs) 0 = (show x) ++ showhelp xs 1
                     showhelp (x:xs) 1 = sign x ++ show x ++ "x" ++ showhelp xs 2
                     showhelp (x:xs) n = sign x ++ show x ++ "x^" ++ show n ++ showhelp xs (n+1)
                     showhelp [] _     = ""
                 in 
                 let showhelp' (0:xs) n = showhelp' xs (n+1)
                     showhelp' (x:xs) 0 = show x ++ showhelp xs 1
                     showhelp' (x:xs) 1 = show x ++ "x" ++ showhelp xs 2
                     showhelp' (x:xs) n = show x ++ "x^" ++ show n ++ showhelp xs (n+1)
                     showhelp' [] _     = ""
                 in showhelp' l 0

calculate :: Polynom -> Int -> Int
calculate (P l) v = let calculate' (x:xs) n = x * v^n + calculate' xs (n+1)
                        calculate' [] _ = 0
                    in calculate' l 0
    
plus :: Polynom -> Polynom -> Polynom
plus (P l1) (P l2) = let plushelp (x:xs) (l:ls) = (x + l) : plushelp xs ls
                         plushelp [] l = l
                         plushelp l [] = l
                     in P (plushelp l1 l2)

minus :: Polynom -> Polynom -> Polynom
minus (P l1) (P l2) = let minushelp (x:xs) (l:ls) = (x - l) : minushelp xs ls
                          minushelp [] l = l
                          minushelp l [] = l
                      in P (minushelp l1 l2)
                      
takenull :: Int -> [Int] -> [Int]
takenull n l
    | n > length l = l ++ (take (n - length l) (repeat 0))
    | otherwise = take n l

multiply :: Polynom -> Polynom -> Polynom
multiply (P l) (P s) = P [sum $ zipWith (*) (takenull n l) (reverse $ takenull n s) 
                          | n <- [1..(length l + length s)]]
                          
testexp1 = P [0,1,2,5]        -- x + 2x^2 + 5x^3
testexp2 = P [11,2]           -- 11 + 2x
testexp3 = P [0,11,24,59,10]  -- 11x + 24x^2 + 59x^3 + 10x^4 (testexp1 * testexp2)

main = do
    quickCheck (\s -> calculate (plus testexp1 testexp2) s == 11 + 3*s + 2*s^2 + 5*s^3)
    quickCheck (\s -> calculate (multiply testexp1 testexp2) s == calculate testexp3 s)
