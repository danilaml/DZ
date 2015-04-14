import Control.Monad.Cont

map_cps :: (a->b) -> [a] -> Cont r [b]
map_cps f []     = return []
map_cps f (x:xs) = do
                    ys <- map_cps f xs
                    return $ (f x):ys

filter_cps :: (a -> Bool) -> [a] -> Cont r [a]
filter_cps f []     = return []
filter_cps f (x:xs) = do
                    ys <- filter_cps f xs
                    if (f x)
                    then return (x:ys)
                    else return ys