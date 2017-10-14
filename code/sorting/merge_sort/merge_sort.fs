//Part of Cosmos by OpenGenus Foundation
open System
open System.Collections.Generic

let rec merge (left:IComparable list) (right:IComparable list): IComparable list = 
    match (left,right) with
    | (_,[]) -> left
    | ([],_) -> right
    | (l::ls,r::rs) when  l < r -> l::merge ls right
    | (l::ls,r::rs) -> r::merge left rs

let rec merge_sort= 
    function
    | [x]-> [x]
    |  x -> let (left,right) = List.splitAt (x.Length/2) x
            merge (merge_sort left) (merge_sort right)
    

[<EntryPoint>]

let main(argv) =
    printfn "%A" <| merge_sort [10;22;41;2;33;12;52]
    0
