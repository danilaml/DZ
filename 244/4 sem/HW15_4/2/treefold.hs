import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeFold :: (a -> b -> a) -> a -> Tree b -> a
treeFold f s (Leaf x) = f s x
treeFold f s (Branch l x r) = treeFold f (treeFold f (f s x) l) r

tree = Branch (Leaf 1) 2 (Branch (Leaf 3) 2 (Leaf 4))
test1 = TestCase $ assertEqual "\\x y -> x+y, s = 0" 12 $ treeFold (\x y -> x + y) 0 tree
test2 = TestCase $ assertEqual "\\x y -> x*y, s = 1" 48 $ treeFold (\x y -> x * y) 1 tree
test3 = TestCase $ assertEqual "\\x y -> 2" 2 $ treeFold (\x y -> 2) 1 tree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]
                                                
main = runTestTT tests