data Tree a = Leaf a | Branch (Tree a) a (Tree a)
            

treeheight :: Tree a -> Integer
treeheight tree = let treeh (Leaf _) h = h
                      treeh (Branch l _ r) h = max (treeh l (h + 1)) (treeh r (h + 1))
                  in treeh tree 0
                  
mindist :: Tree a -> Integer
mindist tree = let mind (Leaf _) h = h
                   mind (Branch l _ r) h = min (mind l (h + 1)) (mind r (h + 1))
               in mind tree 0
