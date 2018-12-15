--select_first
select_first = \first -> \second -> first

--select_second

--make_pair
make_pair = \f -> \s -> \func -> func f s

main = do
    select_first 5 6
