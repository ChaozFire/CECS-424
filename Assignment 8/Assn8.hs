fac :: Int -> Int
fac 1 = 1
fac n = n * (fac (n-1))

tailFac :: Int -> Int
tailFac n = loop n 1
    where loop n' acc
            | n' == 1 = acc
            | otherwise = loop (n' - 1) (n' * acc)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib(n-1) + fib(n-2)

tailFib :: Int -> Int
tailFib n = loop n 0 1
    where loop n' param1 param2
            | n' == 0 = param1
            | n' == 1 = param2
            | otherwise = loop (n'-1) (param2) (param1+param2)

main = do
    print (fac 10)
    print (tailFac 10)
    print (fib 10)
    print (tailFib 10)
