import Test.HUnit
import Control.Monad

isValid :: (Ord a) => (a,a,a) -> Maybe a
isValid (a,b,c)
    | a < b && c < b = Just b
    | otherwise = Nothing

findbiggest :: (Ord a) => [a] -> Maybe a
findbiggest (x1:x2:x3:xs) = mplus (isValid (x1,x2,x3)) (findbiggest (x2:x3:xs))
findbiggest _ = Nothing

test1 = TestCase $ assertEqual "[1..10]" Nothing $ findbiggest [1..10]
test2 = TestCase $ assertEqual "[1,2,1,3]" (Just 2) $ findbiggest [1,2,1,3]
test3 = TestCase $ assertEqual "[1,2,1,3,1]" (Just 2) $ findbiggest [1,2,1,3,1]
tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]
    
main = runTestTT tests