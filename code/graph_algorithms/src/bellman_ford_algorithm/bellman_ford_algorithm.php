<?php 
/*Part of Cosmos by OpenGenus Foundation*/

/*{source, destination, distance}*/
$edges =    array(
           array(0,1,5),
           array(0,2,8),
           array(0,3,-4),
           array(1,0,-2),
           array(2,1,-3),
           array(2,3,9),
           array(3,1,7),
           array(3,4,2),
           array(4,0,6),
           array(4,2,7),
       );

BellmanFord($edges,10,5,4);

function BellmanFord($edges, $edgecount, $nodecount, $source) {
    
    // Initialize distances
    $distances = array();
    
    // This is the initialize single source function.
    for($i =0; $i < $nodecount; ++$i)
        
      $distances[$i]= INF;
      $distances[$source]=0;

     // Do what we are suppose to do, This is the BellmanFord function
     for($i =0; $i < $nodecount;++$i) {
         $somethingChanged =false;
         
         for($j =0; $j < $edgecount;++$j) {
             
             if($distances[$edges[$j][0]]!= INF) { 
                 $newDist = $distances[$edges[$j][0]]+ $edges[$j][2];
                
                if($newDist < $distances[$edges[$j][1]]) { 
                     $distances[$edges[$j][1]]= $newDist;
                     $somethingChanged =true;
                }
            }
        }

       // If $somethingChanged == FALSE, then nothing has changed and we can go on with the next step.
       if(!$somethingChanged)break;
    }

   // Check the graph for negative weight cycles
   for($i =0; $i < $edgecount;++$i) {
        if($distances[$edges[$i][1]] > $distances[$edges[$i][0]]+ $edges[$i][2]){
            echo "Negative edge weight cycle detected!";
            return;
        }
    }

   // Print out the shortest distance
    for($i =0; $i < $nodecount;++$i) {
        echo "Shortest distance between nodes ". $source . " and ". $i ." is ". $distances[$i];
        echo "<br>";
    }
   return;
}

?>