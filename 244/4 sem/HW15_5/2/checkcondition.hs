import Test.QuickCheck

checkcon :: (a -> Bool) -> [a] -> Bool
checkcon f l = foldr ((&&).f) True l

main = quickCheck (\s -> checkcon (id) s == and s)
