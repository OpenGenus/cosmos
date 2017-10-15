//Part of Cosmos by OpenGenus Foundation
open System
let rnd = Random()

//Simple method to shuffle lists, not really random in terms of crypthography
let shuffle (x:IComparable list)=
    List.sortBy(fun x -> rnd.Next()) x

let isSorted (sList:IComparable list)=
    let folder = fun (a,b) x -> (a && (b<=x),x)
    fst << List.fold (folder) (true,sList.[0]) <| sList

let rec bogosort (x: IComparable list)= 
    let shuffled = shuffle x
    if isSorted shuffled then
        shuffled
    else
        bogosort x

[<EntryPoint>]
let main (argv) =
    printfn "%A" <| bogosort [14;3;31;4;92;1]
    0
