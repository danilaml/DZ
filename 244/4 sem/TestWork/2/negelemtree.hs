import Test.QuickCheck

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeFold :: (a -> b -> a) -> a -> Tree b -> a
treeFold f s (Leaf x) = f s x
treeFold f s (Branch l x r) = treeFold f (treeFold f (f s x) l) r

negativeElements :: (Ord a, Num a) => Tree a -> [a]
negativeElements = treeFold (\x y -> if y < 0 then y:x else x) []

testtree = Branch (Leaf 1) (-2) (Branch (Leaf (-3)) 2 (Leaf 4))

main = quickCheck (negativeElements testtree == [-3, -2])
