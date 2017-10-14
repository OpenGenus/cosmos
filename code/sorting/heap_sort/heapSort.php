/* Part of Cosmos by OpenGenus Foundation */
<?php
  class Node
  {
  private $_i; 
  
  public function __construct($key)
  {
  $this->_i = $key;
  }
  
  public function getKey()
  {
  return $this->_i;
  }
  }
  
  class Heap
  {
  private $heap_Array;
  private $_current_Size;
  
  public function __construct()
  {
  $heap_Array = array();
  $this->_current_Size = 0;
  }
  
  // Remove item with max key 
 public function remove()
  {
  $root = $this->heap_Array[0];
  // put last element into root
  $this->heap_Array[0] = $this->heap_Array[--$this->_current_Size];
  $this->bubbleDown(0); 
  return $root; 
  }
  
  // Shift process
  public function bubbleDown($index)
  {
  $larger_Child = null;
  $top = $this->heap_Array[$index]; // save root
  while ($index < (int)($this->_current_Size/2)) { // not on bottom row
  $leftChild = 2 * $index + 1;
  $rightChild = $leftChild + 1;
  
  // find larger child
  if ($rightChild < $this->_current_Size 
  && $this->heap_Array[$leftChild] < $this->heap_Array[$rightChild]) // right child exists?
  {
  $larger_Child = $rightChild;
  } else {
  $larger_Child = $leftChild;
  }
  
  if ($top->getKey() >= $this->heap_Array[$larger_Child]->getKey()) {
  break;
  }
  
  // shift child up
  $this->heap_Array[$index] = $this->heap_Array[$larger_Child]; 
  $index = $larger_Child; // go down
  }
  
  $this->heap_Array[$index] = $top; // root to index
  }
  
  public function insertAt($index, Node $newNode)
  {
  $this->heap_Array[$index] = $newNode;
  }
  
  public function incrementSize()
  {
  $this->_current_Size++;
  }
  
  public function getSize()
  {
  return $this->_current_Size;
  }
  
  public function asArray()
  {
  $arr = array();
  for ($j = 0; $j < sizeof($this->heap_Array); $j++) {
  $arr[] = $this->heap_Array[$j]->getKey();
  }
  
  return $arr;
  }
  }
  
  function heapsort(Heap $Heap)
  { 
  $size = $Heap->getSize();
  // "sift" all nodes, except lowest level as it has no children
  for ($j = (int)($size/2) - 1; $j >= 0; $j--) 
  {
  $Heap->bubbleDown($j);
  }
  // sort the heap
  for ($j = $size-1; $j >= 0; $j--) { 
  $BiggestNode = $Heap->remove();
  // use same nodes array for sorted elements
  $Heap->insertAt($j, $BiggestNode);
  }
  
  return $Heap->asArray(); 
  }
  
  $arr = array(35, 02, 12, 65, -11, 04, 11);
  echo "previous Array : ";
  echo implode(', ',$arr ); 
  $Heap = new Heap();
  foreach ($arr as $key => $val) {
  $Node = new Node($val);
  $Heap->insertAt($key, $Node);
  $Heap->incrementSize();
  }
  $result = heapsort($Heap);
  echo "\nSorted Array : ";
  echo implode(', ',$result)."\n";
  ?>
  
