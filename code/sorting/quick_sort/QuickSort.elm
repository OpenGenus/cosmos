module QuickSort exposing (sort)


sort : List a -> (a -> a -> Order) -> List a
sort list order =
    case list of
        [] ->
            []

        x :: xs ->
            let
                less =
                    List.filter (order x >> (==) GT) xs

                greater =
                    List.filter (order x >> (/=) GT) xs
            in
            sort less order ++ [ x ] ++ sort greater order
