<?php

class CircularBuffer
{
    private $array;
    private $size;
    private $index;

    /**
     * CircularBuffer constructor.
     * @param $size
     */
    public function __construct($size)
    {
        $this->size = $size;
        $this->index = 0;
        $this->array = array_fill(0, $this->size, 0);
    }

    /**
     * @param mixed $item
     */
    public function push($item)
    {
        $this->array[$this->index] = $item;
        $this->index = ($this->index + 1) % $this->size;
    }

    /**
     * @return array
     */
    public function getOrdered()
    {
        $ret = [];
        for ($i = 0; $i < $this->size; $i++) {
            $ret[] = $this->array[($i + $this->index) % $this->size];
        }
        return $ret;
    }

}

$circularBuffer = new CircularBuffer(2);
$circularBuffer->push(3);
$circularBuffer->push(4);
$circularBuffer->push(5);
$circularBuffer->push(6);

foreach($circularBuffer->getOrdered() as $n)
    print($n);
