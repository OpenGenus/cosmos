// run: dotnet fsi .\binary-search.fsx

let rec binarySearch target items =
    match Array.length items with
        | 0 -> None
        | i ->  
            let mid = i / 2
            match sign <| compare target items.[mid] with
                | 0 -> Some(target)
                | -1 -> binarySearch target items.[..mid-1]
                | _ -> binarySearch target items.[mid+1..]

let result = binarySearch 345 [|1..10000000|]
printfn "%A" result // 345
