import Control.Monad.State
import Data.Char

data HashTable k v = HashTable {hash :: (k -> Int), table :: [(Int, v)]}

add :: k -> v -> HashTable k v -> HashTable k v
add k v (HashTable f t) = let h = f k in
                          let addh tb@((x,y):xs)
                                | h < x = (h, v) : tb
                                | h > x = (x, y) : (addh xs)
                                | otherwise = (h, v) : xs
                              addh [] = [(h, v)]
                          in HashTable f (addh t)

remove :: k -> v -> HashTable k v -> HashTable k v
remove k v (HashTable f t) = let h = f k in
                             let remh tb@((x,y):xs)
                                    | h < x = tb
                                    | h > x = (x, y) : (remh xs)
                                    | otherwise = xs
                                 remh [] = []
                             in HashTable f (remh t)

find :: k -> HashTable k v -> Maybe v
find k (HashTable f t) = let h = f k in
                         let findh tb@((x,y):xs)
                                | h < x = Nothing
                                | h > x = (findh xs)
                                | otherwise = Just y
                             findh [] = Nothing
                         in findh t

hasht = add "a" "b" $ add "11" "11" $ add "test2" "test2" $ add "test1" "!" $ add "test" "0" emptyh
    where emptyh = HashTable (\x -> (foldl (\s t -> s + (ord t)) 0 x) `mod` 127) []