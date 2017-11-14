<?php

# Part of Cosmos by OpenGenus Foundation

trait ArrayRandomize
{
    /**
     * Shuffle a given array
     *
     * @param array $entries
     * @return array
     */
    public function shuffle(array $entries) : array
    {
        $length = count($entries);

        for ($i = ($length - 1); $i >= 0; $i--) {
            $randomIx = rand(0, $i);

            $tmpEntry = $entries[$i];
            $entries[$i] = $entries[$randomIx];
            $entries[$randomIx] = $tmpEntry;
        }

        return $entries;
    }

    /**
     * Shuffle a given assoc array
     *
     * @param array $entries
     * @return array
     */
    public function shuffleAssoc(array $entries) : array
    {
        $mixedKeys = $this->shuffle(array_keys($entries));

        $mixedEntries = [];
        foreach ($mixedKeys as $key) {
            $mixedEntries[$key] = $entries[$key];
        }

        return $mixedEntries;
    }
}