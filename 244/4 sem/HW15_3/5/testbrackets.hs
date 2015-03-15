data Brackets = Normal | Curly | Square

testbrackets :: String -> Bool
testbrackets str = let testb str st = case (str, st) of
                                        ('(':xs, _)         -> testb xs (Normal:st)
                                        (')':xs, Normal:bs) -> testb xs bs
                                        ('{':xs, _)         -> testb xs (Curly:st)
                                        ('}':xs, Curly:bs)  -> testb xs bs
                                        ('[':xs, _)         -> testb xs (Square:st)
                                        (']':xs, Square:bs) -> testb xs bs
                                        (')':xs, _)         -> False
                                        ('}':xs, _)         -> False
                                        (']':xs, _)         -> False
                                        (_:xs, _)           -> testb xs st
                                        ([], [])            -> True
                                        (_, _)              -> False
                 in testb str []