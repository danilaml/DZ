import Control.Monad.State
import Test.HUnit

data BinaryTree a = Empty | Node a (BinaryTree a) (BinaryTree a) deriving (Eq, Show)

toString :: BinaryTree Char -> String
toString (Node x left right) = 'n':x:(toString left ++ toString right)
toString (Empty)             = "e"

errormsg :: String -> String -> String
errormsg t s = show pos ++ ", " ++ (if length s == 0 then "EOL" else [t !! pos])
                where pos = length t - length s

fromString :: String -> BinaryTree Char
fromString t = let fString = do
                        state <- get
                        case state of
                            ('n':x:xs) -> do
                                put xs
                                left <- fString
                                right <- fString
                                return (Node x left right)
                            ('e':xs)   -> do
                                put xs
                                return (Empty)
                            str        -> error $ "Wrong syntax at: " ++ errormsg t str
               in evalState fString t

testtree1 = Node 'a' (Node 'b' Empty (Node 'c' Empty Empty)) (Node 'd' Empty Empty)
testtree2 = Node 'a' (Node 'b' (Node 'c' Empty Empty) Empty) (Node 'd' Empty Empty)
test1 = TestCase $ assertEqual "testtree1" testtree1 $ fromString $ toString testtree1
test2 = TestCase $ assertEqual "testtree2" testtree2 $ fromString $ toString testtree2
tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2]

main = do runTestTT tests