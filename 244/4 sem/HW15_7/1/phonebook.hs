import Control.Exception.Base

printHelp :: IO ()
printHelp = do
    putStrLn "0 - exit"
    putStrLn "1 name number - add (name,number) record to the phonebook"
    putStrLn "2 name - find number via name"
    putStrLn "3 number - find name via number"
    putStrLn "4 file - save current data to file"
    putStrLn "5 file - read data from file"
    putStrLn "h - print help"

type PhoneBook = [(String, [String])]

addRecord :: (String, String) -> PhoneBook -> PhoneBook
addRecord (nm, nb) p = case (lookup nm p) of
                        Just _ -> map (\(x,y) -> if x == nm then (x, nb:y) else (x,y)) p
                        Nothing -> (nm, [nb]):p

findName :: String -> PhoneBook -> Maybe [String]
findName n l = case res of
    [] -> Nothing
    _ -> Just (map (fst) res)
    where res = filter (\(x,y) -> n `elem` y) l

progLoop :: PhoneBook -> IO ()
progLoop pb = do
    com <- getLine
    case (com !! 0) of
        '0' -> return ()
        '1' -> case (words $ drop 2 com) of
                [name, number] -> do putStrLn "OK";progLoop (addRecord (name, number) pb)
                _ -> fail "wrong number of arguments"
        '2' -> do case (words $ drop 2 com) of
                    [name] -> do putStrLn $ show (lookup name pb);putStrLn "OK";progLoop pb
                    _ -> fail "wrong number of arguments"
        '3' -> do case (words $ drop 2 com) of
                    [number] -> do putStrLn $ show (findName number pb);putStrLn "OK";progLoop pb
                    _ -> fail "wrong number of arguments"
        '4' -> do case (words $ drop 2 com) of
                    [filename] -> do writeFile filename (show pb);putStrLn "OK";progLoop pb
                    _ -> fail "wrong number of arguments"
        '5' -> do
                file <- readFile (drop 2 com)
                newpb <- readIO file :: IO PhoneBook
                putStrLn "OK"
                progLoop newpb
        'h' -> do printHelp; progLoop pb
        _   -> fail $ "wrong command: " ++ com
    `catch` (\e -> do putStrLn (show (e :: IOError));progLoop pb)

main = do printHelp; progLoop []