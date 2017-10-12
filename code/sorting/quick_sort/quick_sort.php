<?php

functionfunction quick_sort( $array ) {

	if ( count( $array ) <= 1 ) {
		return $array;
	} else {
		$pivot = $array[0];
		$left = $right = [];

		for ( $i = 1; $i < count( $array ); $i ++ ) {
			if ( $array[ $i ] < $pivot ) {
				$left[] = $array[ $i ];
			} else {
				$right[] = $array[ $i ];
			}
		}
		return array_merge( quick_sort( $left ), array( $pivot ), quick_sort( $right ) );
	}
}

?>
