import Control.Monad.State

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

replace :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
replace e (l, r) = map (\(x, y) -> if (x == l) then (l, r) else (x, y)) e

findMin :: [(Int, Int)] -> (Int, Int)
findMin (l:ls) = let findHelp ((x,y):xs) (x1,y1) = if y < y1
                                                   then findHelp xs (x, y)
                                                   else findHelp xs (x1, y1)
                     findHelp [] m = m in findHelp ls l

dijkstra' :: Graph Int Int -> Int -> [(Int, Int)]
dijkstra' g@(Graph v e) src
    | length v == 1 = v
    | otherwise  = case (lookup src v) of
                    Nothing -> error "No such src"
                    Just mark -> let helper ((f, t, c):es)
                                        | src == f = do
                                            notvis <- get
                                            case (lookup t notvis) of
                                                Nothing -> helper es
                                                Just m  -> if m < (mark + c)
                                                               then helper es
                                                               else do
                                                                    put $ replace notvis (t, mark + c)
                                                                    helper es
                                        | otherwise  = helper es
                                     helper [] = return []
                                 in
                                 let newV = filter (\(x,y) -> x /= src) (execState (helper e) v) in
                                 let p = findMin newV in (findMin v):(dijkstra' (Graph newV e) (fst p))

dijkstra :: Graph Int Int -> Int -> [(Int, Int)]
dijkstra (Graph v e) src = dijkstra' (Graph (map (\(x,y) -> if x == src then (x, 0) else (x, inf)) v) e) src

inf = maxBound :: Int
testgraph = Graph [(0, 0), (1, 0), (2, 0)] [(0,1,8), (1,2,3), (0,2,13)] :: Graph Int Int