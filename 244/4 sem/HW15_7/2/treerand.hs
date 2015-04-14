import System.Random
import Control.Monad.State

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)

randomizeTree :: Tree a -> Tree Int
randomizeTree t = let randHelper (Branch l x r) = do
                                                generator <- get
                                                let (ranval, newgen) = random generator
                                                put newgen
                                                rl <- randHelper l
                                                rr <- randHelper r
                                                return (Branch rl ranval rr)
                      randHelper (Leaf a) = do
                                        generator <- get
                                        let (ranval, newgen) = random generator
                                        put newgen
                                        return (Leaf ranval)
                  in evalState (randHelper t) (mkStdGen 0)

testtree = Branch (Leaf 1) (-2) (Branch (Leaf (-3)) 2 (Leaf 4))