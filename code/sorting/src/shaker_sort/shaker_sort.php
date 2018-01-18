<?php

/* Part of Cosmos by OpenGenus Foundation */

namespace OpenGenus;

trait ShakerSortTrait {
    /**
     * @param array $list
     * @return array
     */
    public function sort(array $list) : array
    {
        do {
            $swapped = false;
            $length = count($list);

            for ($i = 0; $i < $length - 2; $i++) {
                if ($list[$i] > $list[$i + 1]) {
                    $list = $this->swap($list, $i, $i + 1);
                    $swapped = true;
                }
            }

            if (false === $swapped) {
                break;
            }

            $swapped = false;
            for ($i = $length - 2; $i > 0; $i--) {
                if ($list[$i] > $list[$i + 1]) {
                    $list = $this->swap($list, $i, $i + 1);
                    $swapped = true;
                }
            }
        } while(true === $swapped);

        return $list;
    }

    /**
     * @param array $input
     * @param int $fromIndex
     * @param int $toIndex
     * @return array
     */
    private function swap(array $input, int $fromIndex, int $toIndex) : array
    {
        $swapFrom = $input[$fromIndex];
        $input[$fromIndex] = $input[$toIndex];
        $input[$toIndex] = $swapFrom;

        return $input;
    }
}