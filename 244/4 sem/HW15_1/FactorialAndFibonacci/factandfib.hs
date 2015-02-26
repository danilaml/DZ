factorial :: Integer -> Integer
factorial n = if (n < 0) then error "Factorial doesn't take negative numbers" else
              if (n == 0)
              then 1
              else n * factorial (n - 1)

fibonacci :: Integer -> Integer			  
fibonacci n = if (n < 0) then error "Fibonacci doesn't take negative numbers" else
              if (n == 1 || n == 0)
              then 1
              else fibonacci (n - 1) + fibonacci (n - 2)

main = putStrLn (
                "factorial of 5 is: " ++ (show (factorial 5)) ++ "\n" ++
                "6th Fibonacci number is: " ++ (show (fibonacci 6))
                )