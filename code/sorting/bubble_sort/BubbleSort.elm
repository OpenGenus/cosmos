module BubbleSort exposing (sort)

import Tuple


sort : List a -> (a -> a -> Order) -> List a
sort list order =
    let
        ( swapped, listResult ) =
            swapPass ( False, list ) order
    in
    if swapped then
        sort listResult order
    else
        listResult


swapPass : ( Bool, List a ) -> (a -> a -> Order) -> ( Bool, List a )
swapPass ( swapped, list ) order =
    case list of
        x0 :: x1 :: xs ->
            case order x0 x1 of
                LT ->
                    let
                        ( swapped_, result ) =
                            swapPass ( swapped, x1 :: xs ) order
                    in
                    ( swapped_, x0 :: result )

                EQ ->
                    let
                        ( swapped_, result ) =
                            swapPass ( swapped, x1 :: xs ) order
                    in
                    ( swapped_, x0 :: result )

                GT ->
                    let
                        ( swapped_, result ) =
                            swapPass ( swapped, x0 :: xs ) order
                    in
                    ( True, x1 :: result )

        x1 :: [] ->
            ( swapped, [ x1 ] )

        [] ->
            ( swapped, [] )
