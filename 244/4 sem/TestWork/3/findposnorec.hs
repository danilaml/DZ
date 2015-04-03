findpos :: (Eq a) => a -> [a] -> Maybe Int
findpos el l = case (foldl (\y@(y1,y2) x -> if y2 then y else if x /= el then (y1 + 1, y2) else (y1, True)) (0, False) l) of
                    (n, True) -> Just n
                    _         -> Nothing