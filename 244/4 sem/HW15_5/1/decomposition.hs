import Control.Monad

prettyPrint :: [Integer] -> IO ()
prettyPrint [] = return ()
prettyPrint [x] = print x
prettyPrint (x:xs) = do putStr $ show x; putStr " + "; prettyPrint xs

decompose :: Integer -> IO ()
decompose m = let decompose' 0 k l = prettyPrint $ reverse l -- reverse for prettiness
                  decompose' n k l
                    | n < 0 = return ()
                    | otherwise = do
                                    when (n - k >= 0) $ decompose' (n - k) k (k:l)
                                    when (k - 1 > 0) $ decompose' n (k - 1) l
              in decompose' m m []