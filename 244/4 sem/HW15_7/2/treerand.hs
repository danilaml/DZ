import System.Random
import Control.Monad.State
import Data.Time.Clock.POSIX

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)

randomizeTree :: Tree a -> Int -> Tree Int
randomizeTree t s = let randHelper (Branch l x r) = do
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
                    in evalState (randHelper t) (mkStdGen s)

testtree = Branch (Leaf 1) (-2) (Branch (Leaf (-3)) 2 (Leaf 4))

main = do
    seed <- round `fmap` getPOSIXTime
    putStrLn . show $ randomizeTree testtree seed