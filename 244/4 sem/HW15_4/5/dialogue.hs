printHelp :: IO ()
printHelp = do
    putStrLn "0 - exit"
    putStrLn "1 v - add value v to sorted list"
    putStrLn "2 v - remove value v from list"
    putStrLn "3 - print list"
    putStrLn "h - print help"

addToList :: [String] -> String -> [String]
addToList [] str = [str]
addToList (x:xs) str
    | str >= x = x : (addToList xs str)
    | otherwise = str : x : xs
    
removeFromList :: [String] -> String -> [String]
removeFromList [] str = []
removeFromList (x:xs) str
    | str == x = xs
    | otherwise = x : (removeFromList xs str)
    
progLoop :: [String] -> IO ()
progLoop l = do
    com <- getLine
    case (com !! 0) of
        '0' -> return ()
        '1' -> progLoop (addToList l (drop 2 com))
        '2' -> progLoop (removeFromList l (drop 2 com))
        '3' -> do putStrLn (show l); progLoop l
        'h' -> printHelp
        _   -> fail $ "wrong command: " ++ com
     

main = do 
    printHelp
    progLoop []