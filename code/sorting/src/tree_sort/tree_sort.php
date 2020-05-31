<?php
// Part of Cosmos by OpenGenus

namespace SF;

class TreeSort
{
	public static function sort($input, $options = array())
	{
		$output = array();
		$all = array();
		$dangling = array();

		// Initialize arrays
		foreach ($input as $entry) {
		    $entry['children'] = array();
		    $entry['active'] = false;
		    $entry['active_parent'] = false;
		    $id = $entry['id'];

		    // If this is a top-level node, add it to the output immediately
		    if (!$entry['parent_id']) {
		        $all[$id] = $entry;
		        $output[] =& $all[$id];

		    // If this isn't a top-level node, we have to process it later
		    } else {
		        $dangling[$id] = $entry; 
		    }
		}

		// Process all 'dangling' nodes
		while (count($dangling) > 0) {
		    foreach($dangling as $entry) {
		        $id = $entry['id'];
		        $pid = $entry['parent_id'];

		        // If the parent has already been added to the output, it's
		        // safe to add this node too
		        if (isset($all[$pid])) {
		            $all[$id] = $entry;
		            $all[$pid]['children'][] =& $all[$id]; 
		            unset($dangling[$entry['id']]);
		        }
		    }
		}
		
		// Active
		if (isset($options['active_id'])) {
			$id = $options['active_id'];
			$all[$id]['active'] = true;
			
			do {
				$parent_id = $all[$id]['parent_id'];
				
				if (isset($all[$parent_id])) {
					$all[$parent_id]['active_parent'] = true;
					$id = $parent_id;
				} else {
					break;
				}
			} while (true);
		}
		
		return $output;
	}
	
	public static function sortFlat($items, $addHelpers = true)
	{
		$children = array();    // Parent's children
		$itemsize = array();    // Family sizes
		
		// Get children by parent
		foreach ($items as $item) {
			if ($item['parent_id'] != 0) {
				$children[$item['parent_id']][] = $item['id'];
			}
			$itemsize[$item['id']] = 1;
		}
		
		$adopted = array();     // Children that have been adopted
		for ($i = 0; count($children) != 0; $i++) {
			$itemId = $items[$i]['id'];
			
			// If I have children
			if (isset($children[$itemId])) {
				$offset = 1;
				
				// Loop through children and append them after me
				foreach ($children[$itemId] as $id) {
					$itemsize[$itemId] += $itemsize[$id];  // Update my family size
					$adopted[$id] = true;
					$childIndex = self::getIndexInArray($items, $id);
					
					// Move child with family
					for ($j = 0; $j < $itemsize[$id]; $j++) {
						if ($childIndex + $j < $i + $offset) {
							$childIndexReal = $childIndex;  // When we move a child, the next will come to into position
							$i--;   // If child is before me, I should adjust my index pointer
						} else {
							$childIndexReal = $childIndex + $j;
						}
						$child = array($items[$childIndexReal]);
						unset($items[$childIndexReal]);
						array_splice($items, $i + $offset++, 0, $child);
					}
				}
				
				// Resize parent if it has adopted me
				$thisId = $itemId;
				while (isset($adopted[$thisId])) {
					$parentId = $items[self::getIndexInArray($items, $thisId)]['parent_id'];
					$itemsize[$parentId] += $itemsize[$itemId];
					$thisId = $parentId;
				}
				
				unset($children[$itemId]);
			}
			
			// Prevent endless loop if the array isn't complete (disconnected parent_ids)
			if ($i == count($items) - 1) {
				break;
			}
		}
		
		if ($addHelpers) {
			return self::addHelpers($items);
		} else {
			return $items;
		}
	}
	
	public static function getIndexInArray(&$items, $id)
	{
		foreach ($items as $index => $item) {
			if ($item['id'] == $id) {
				return $index;
			}
		}
		return null;
	}
	
	public static function addHelpers($items)
	{
		$level = 0;
		$parentIds = array(0);
		$lastParentId = 0;
		$last = null;	// isset == false
		$first = true;
		
		foreach ($items as &$item) {
			// If we've gone deeper, or this is the first
			if (($item['parent_id'] != $lastParentId && !in_array($item['parent_id'], $parentIds)) || is_null($last)) {
				$item['first_child'] = true;
			} else {
				$item['first_child'] = false;
			}
			
			if (isset($last)) {
				// If we've gone up one/more level to the surface
				if ($item['parent_id'] != $lastParentId && in_array($item['parent_id'], $parentIds)) {
					$last['last_child'] = true;
				} else {
					$last['last_child'] = false;
				}
			}
			
			if ($item['parent_id'] != $lastParentId) {
				// If we've gone up one/more level to the surface
				if (in_array($item['parent_id'], $parentIds)) {
					if (isset($lastIndex)) {
						$items[$lastIndex] = true;
					}
					
					for ($i = count($parentIds) - 1; $item['parent_id'] != $parentIds[$i]; $i--) {
						$level--;
						unset($parentIds[$i]);
					}
				
				// If we've gone deeper
				} else {
					if (isset($last)) {
						$last['has_children'] = true;
					}
					
					$parentIds[count($parentIds)] = $item['parent_id'];
					$level++;
				}
			}
			
			$item['level'] = $level;
			$item['first'] = $first;
			$item['has_children'] = false;
			$item['last'] = false;
			$item['previous'] = &$last;
			$last['next'] = &$item;
			$lastParentId = $item['parent_id'];
			$first = false;
			$last = &$item;
		}
		
		$last['last'] = true;
		$last['last_child'] = true;
		
		return $items;
	}
}
