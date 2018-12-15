mysum :: [Int] -> Int
mysum [] = 0
mysum (x:xs) = x + (mysum xs)

myprod :: [Int] -> Int
myprod [] = 1
myprod (x:xs) = x * (myprod xs)

myfoldr :: (a -> b -> b) -> b -> [a] -> b
myfoldr f acc [] = acc
myfoldr f acc (x:xs) = f x (myfoldr f acc xs)

myfoldl :: (a -> b -> a) -> a -> [b] -> a
myfoldl f acc [] = acc
myfoldl f acc (x:xs) = myfoldl f (f acc x) xs

mylengthr = myfoldr (\_ n -> 1 + n) 0
mysumr = myfoldr (+) 0
myprodr = myfoldr (*) 1

mylengthl = myfoldl (\n _ -> n + 1) 0
mysuml = myfoldl (+) 0
myprodl = myfoldl (*) 1

myreverser = myfoldr (\n m -> m ++ [n]) []
myreversel = myfoldl (\n m -> m : n) []

main = do
  print(mysum [1,2,3,4])
  print(myprod [1,2,3,4])
  print(mysumr [1,2,3,4])
  print(myprodr [1,2,3,4])
  print(mysuml [1,2,3,4])
  print(myprodl [1,2,3,4])
  print(mysumr [1,2,3,4])
  print(mylengthr [1,2,3])
  print(mylengthl [1,2,3])
  print(myreverser [1,2,3])
  print(myreversel [1,2,3])
