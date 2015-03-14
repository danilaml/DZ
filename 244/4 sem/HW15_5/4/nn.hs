import Test.QuickCheck

nn :: Integer -> [Integer]
nn n = [1..n] >>= (\x -> map (x*) [1..n])
    
main = do
    quickCheck (\(Positive s) -> fromIntegral (length (nn s)) == s*s)
    quickCheck (\(Positive x) (Positive y) -> (nn x) !! (fromInteger (y `mod` x)) <= x*x)