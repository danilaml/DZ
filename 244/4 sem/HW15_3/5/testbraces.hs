testbraces :: String -> Bool
testbraces str = let testb str ob = if (ob < 0)
                                    then False
                                    else case str of
                                            '(':xs -> testb xs (ob + 1)
                                            ')':xs -> testb xs (ob - 1)
                                            _:xs -> testb xs ob
                                            _ -> ob == 0
                 in testb str 0