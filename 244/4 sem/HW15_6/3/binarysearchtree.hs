import Test.HUnit

data BinarySearchTree a = Empty
                        | Node a (BinarySearchTree a) (BinarySearchTree a)
                        deriving (Eq, Show)
                        

addElem :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
addElem t@(Node x l r) e
    | e > x     = Node x l (addElem r e)
    | e < x     = Node x (addElem l e) r
    | otherwise = t
addElem (Empty) e = Node e Empty Empty

findMin :: (Ord a) => BinarySearchTree a -> a
findMin (Node x Empty r) = x
findMin (Node x l r)     = findMin l
findMin (Empty)          = error "tree is empty"

removeElem :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
removeElem (Node x l r) e
    | e > x     = Node x l (removeElem r e)
    | e < x     = Node x (removeElem l e) r
    | otherwise = case (l,r) of
        (Empty, Empty)      -> Empty
        (Empty, _)          -> r
        (_, Empty)          -> l
        (_, Node v Empty n) -> Node v l n
        (_, Node v l1 r1)   -> Node m l (removeElem r m) where m = findMin l1
removeElem (Empty) e = Empty

findElem :: (Ord a) => BinarySearchTree a -> a -> Bool
findElem (Node x l r) e
    | e > x     = findElem r e
    | e < x     = findElem l e
    | otherwise = True
findElem (Empty) e = False

treeSize :: BinarySearchTree a -> Int
treeSize (Node x l r) = 1 + treeSize l + treeSize r
treeSize (Empty)      = 0

treeHeight :: BinarySearchTree a -> Int
treeHeight (Node x l r) = 1 + max (treeHeight l) (treeHeight r)
treeHeight (Empty)      = 0

testtree = Empty `addElem` 1 `addElem` 2 `addElem` 0 `addElem` 12 `addElem` 8
test1 = TestCase $ assertEqual "height" 4 $ treeHeight testtree
test2 = TestCase $ assertEqual "size" 5 $ treeSize testtree
test3 = TestCase $ assertBool "remove 1" $ not $ findElem (removeElem testtree 1) 1
test4 = TestCase $ assertBool "add 3" $ findElem (addElem testtree 3) 3
tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2
                    , TestLabel "test3" test3, TestLabel "test4" test4]

main = do runTestTT tests