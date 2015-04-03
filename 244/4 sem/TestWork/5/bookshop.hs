import Test.QuickCheck

data PrintedProduct = Book { name :: String, author :: String, price :: Int }
                    | Magazine { name :: String, year :: Int, issue :: Int, price :: Int}

pricesummary :: [PrintedProduct] -> Int
pricesummary pl = foldl (\x y -> x + price y) 0 pl

testlist = [ Book { name = "ABC", author = "xyz", price = 10}
           , Book { name = "Test", author = "tt", price = 20}
           , Magazine { name = "L", year = 2000, issue = 1, price = 5}]

main = quickCheck (pricesummary testlist == 35)
