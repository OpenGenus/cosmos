{-/* Part of Cosmos by OpenGenus Foundation */-}

module LinkedList where
import Data.Maybe
{-| A node for a linked list of type `a`-}
data Node a = Node {
    value :: a, -- Value of type `a` in node
    next :: LinkedList a -- Next node
}

{-| A linked list with nodes of type a -}
type LinkedList a = Maybe (Node a)

instance (Show a) => Show (Node a) where
    show node = 
        (show (value node) ++ " -> " ++
            case (next node) of
                Nothing -> "None"
                Just node' -> show node')

{-| Given a value, create a new node (singleton). -}
newNode :: a -> Node a
newNode a = Node {
    value = a,
    next = Nothing
}

{-| Given a linked list and a node, return a new list with the node in its head. -}
addNode :: Node a -> LinkedList a -> LinkedList a
addNode node list = Just $ Node {
    value = value node,
    next = list
}

{-| Given a linked list and a value, create a new node for it with this value. -}
addValue :: a -> LinkedList a -> LinkedList a
addValue x list = addNode (newNode x) list

{-| Function that returns sum of all values -}
sumLinkedList :: (Num a) => a -> LinkedList a -> a
sumLinkedList total Nothing = total
sumLinkedList x (Just node) =
    sumLinkedList (x + value node) (next node)
    
{-
Example:
> let ll = addValue 2 $ addValue 3 $ addValue 1 Nothing
> ll
Just 2 -> 3 -> 1 -> None
> sumLinkedList 0 ll
6
-}
