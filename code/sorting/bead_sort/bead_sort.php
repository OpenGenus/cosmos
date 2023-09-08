function BeadSort(&$data)
{
	$i; $j; $max; $sum;
	$dataCount = count($data);

	for ($i = 1, $max = $data[0]; $i < $dataCount; ++$i)
		if ($data[$i] > $max)
			$max = $data[$i];

	$beads = array_fill(0, $max * $dataCount, 0);

	for ($i = 0; $i < $dataCount; ++$i)
		for ($j = 0; $j < $data[$i]; ++$j)
			$beads[$i * $max + $j] = 1;

	for ($j = 0; $j < $max; ++$j)
	{
		for ($sum = $i = 0; $i < $dataCount; ++$i)
		{
			$sum += $beads[$i * $max + $j];
			$beads[$i * $max + $j] = 0;
		}

		for ($i = $dataCount - $sum; $i < $dataCount; ++$i)
			$beads[$i * $max + $j] = 1;
	}

	for ($i = 0; $i < $dataCount; ++$i)
	{
		for ($j = 0; $j < $max && $beads[$i * $max + $j]; ++$j) ;
		$data[$i] = $j;
	}
}
