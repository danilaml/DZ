import Test.HUnit

isdiff :: (Eq a) => [a] -> Bool
isdiff [] = True
isdiff (x:xs)
    | x `elem` xs = False
    | otherwise = isdiff xs
    
test1 = TestCase $ assertEqual "[1..10]" True $ isdiff [1..10]
test2 = TestCase $ assertEqual "[1,1,2]" False $ isdiff [1,1,2]
tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2]
    
main = runTestTT tests