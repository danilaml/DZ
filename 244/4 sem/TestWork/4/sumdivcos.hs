sumdivcos :: (Floating a) => [a] -> a
sumdivcos list = let helper s p (l:ls) = helper (s + l) (p * cos l) ls
                     helper s p [] = s / p
                 in helper 0 1 list