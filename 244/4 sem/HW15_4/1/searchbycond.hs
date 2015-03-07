import Data.Maybe
import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findElement :: (a -> Bool) -> Tree a -> Maybe [a]
findElement p (Leaf x) = if p x then Just [x] else Nothing
findElement p (Branch l x r) = if p x
                               then mergeRes (Just [x]) (mergeRes (findElement p l) (findElement p r)) 
                               else mergeRes (findElement p l) (findElement p r)
                               where mergeRes a b = case (a,b) of
                                                (Nothing, Nothing) -> Nothing
                                                (notn, Nothing) -> notn
                                                (Nothing, notn) -> notn
                                                (Just lr, Just rr) -> Just (lr ++ rr)
                                                
tree = Branch (Leaf 1) 2 (Branch (Leaf 3) 2 (Leaf 4))
test1 = TestCase $ assertEqual "\\x -> x>2" (Just [3,4]) $ findElement (\x -> x>2) tree
test2 = TestCase $ assertEqual "\\x -> x>9" Nothing $ findElement (\x -> x>9) tree
test3 = TestCase $ assertEqual "\\x -> x==2" (Just [2,2]) $ findElement (\x -> x==2) tree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]
                                                
main = runTestTT tests
                                              