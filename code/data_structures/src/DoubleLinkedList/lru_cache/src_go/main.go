/*
- LRU cache implementation in Go
- Change the 'capacity' variable to adjust the size of cache
- Each node in the DLL can contain a key and a value
- There are 2 main functions:
    1. update(key, value): If the key-value pair is absent, then it will add it to the cache. If the key is already present, then it will update its value
    2. get(key): It will print the key's value. If the key doesn't exist then it will print -1
- traverse() is an additional function that can be used to visualize the DLL
- The attach() function is used to attach a node just after 'head'
- The detach() function is used to detach a node

*/
package main

import "fmt"

const capacity int = 2 // Capacity of the cache. Change it accordingly

type node struct{
  data_key  int
  data_val  int
  next      *node
  prev      *node
}

var head *node
var tail *node
var tracker map[int]*node



///////////////////////////////////////
// Helper functions                  //
///////////////////////////////////////
func attach(block *node){
  // Update the DLL
  block.next = head.next
  (head.next).prev = block
  head.next = block
  block.prev = head
  
}
func detach(block *node){
  //Detach the block
  (block.prev).next = block.next
  (block.next).prev = block.prev
}


func update(key int, value int){
  // If key is already present, then update the value
  v, found := tracker[key]
  if found{
    v.data_val = value
    detach(v)
    attach(v)
    return
  }

  // If key is absent
  nodeToAdd := &node{ data_key: key, data_val:value } // The node/block to be inserted
  if len(tracker) == capacity{

    nodeToRemove := tail.prev
    detach(nodeToRemove)
    delete(tracker, nodeToRemove.data_key) // Update the map accordingly
    attach(nodeToAdd)
    tracker[key] = nodeToAdd // Add the item to the map


  } else {
    attach(nodeToAdd)
    tracker[key] = nodeToAdd // Add the item to the map
  }

}

func get(key int){
  // Return the value
  reqdNode, found := tracker[key]
  if found{
    fmt.Printf("For key = %d, value = %d\n",key,reqdNode.data_val)
  } else {
    fmt.Printf("For key = %d, value = %d\n", key, -1)
    return
  }
  // Update the DLL
  detach(reqdNode)
  attach(reqdNode)

}

// Visualize the DLL
func traverse(){
  fmt.Println("\nHere's your DLL...")
  temp:=head.next
  for temp != tail{
    fmt.Printf("(%d,%d) ", temp.data_key, temp.data_val)
    temp=temp.next
  }
  fmt.Println()
}

func main(){

  head = &node{ data_key: 0, data_val: 0 }
  tail = &node{ data_key: 0, data_val: 0, prev: head }
  head.next = tail
  tracker = make(map[int]*node)

  // Sample Operations
  update(1, 1)
  update(2, 2)
  get(1)      // prints 1
  update(3,3)
  get(2)      // prints -1
  update(4,4) 
  get(1)      // prints -1
  get(3)      // prints 3
  get(4)      // prints 4

  traverse()
}
