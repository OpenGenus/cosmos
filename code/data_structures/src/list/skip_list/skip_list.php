<?php

class SkipNode
{
    public $key;
    public $value;
    public $forward;

    public function __construct(
        int $levels,
        $key = null,
        $value = null
    ) {
        $this->key = $key ?? 0;
        $this->value = $value;
        $this->forward = array_fill(0, $levels + 1, null);
    }

    public function adjustLevel(int $newLevel) {
        $this->forward = array_merge(
            $this->forward,
            array_fill(0, $newLevel + 1, null)
        );
    }

    public function printForward() {
        for ($i = count($this->forward) - 1; $i >= 0; $i--) {
            $output = $this->forward[$i]
                ? "({$this->forward[$i]->key} : {$this->forward[$i]->value})"
                : "null";
            echo "level : {$i} ----> {$output}", PHP_EOL;
        }
    }
}

class SkipList
{
    private $head;
    private $level;
    private $size;
    private $p;

    /**
     * SkipList constructor.
     */
    public function __construct($level = 1) {
        $this->level = $level;
        $this->head = new SkipNode($this->level);
        $this->size = 0;
        $this->p = 0.5;
    }

    public function adjustHead(int $newLevel): void {
        $this->head->adjustLevel($newLevel);
    }

    public function insert(int $k, $newValue) {
        $newLevel = $this->randomLevel();

        if ($newLevel > $this->level) {
            $this->adjustHead($newLevel);
            $this->level = $newLevel;
        }

        $update = array_fill(0, $this->level + 1, null);
        $x = $this->head;

        $i = $this->level;
        for (; $i >= 0; $i--) {
            while ($x->forward[$i] !== null && $k > $x->forward[$i]->key) {
                $x = $x->forward[$i];
            }
            $update[$i] = $x;
        }
        $x = new SkipNode($newLevel, $k, $newValue);
        for ($i = 0; $i <= $newLevel; $i++) {
            $x->forward[$i] = $update[$i]->forward[$i];
            $update[$i]->forward[$i] = $x;
        }

        $this->size++;
    }

    public function find(int $searchKey) {
        $x = $this->head;
        for ($i = $this->level; $i >= 0; $i--) {
            while ($x->forward[$i] !== null && $searchKey > $x->forward[$i]->key) {
                $x = $x->forward[$i];
            }
        }
        $x = $x->forward[0];
        if ($x->key === $searchKey) {
            return $x->value;
        }

        return null;
    }

    public function printList() {
        $ptr = $this->head;
        while (true) {
            if ($ptr->forward[0] === null) {
                break;
            }

            $ptr = $ptr->forward[0];
            echo "{$ptr->key}: {$ptr->value}", PHP_EOL;
        }
    }

    public function printEverything() {
        $ptr = $this->head;
        echo "Head Node ", PHP_EOL;
        $ptr->printForward();
        $ptr = $ptr->forward[0];
        while ($ptr !== null) {
            echo "Node ({$ptr->key} : {$ptr->value})", PHP_EOL;
            $ptr->printForward();
            $ptr = $ptr->forward[0];
        }
    }

    private function randomLevel() {
        $level = 0;
        while (lcg_value() < $this->p && $level < $this->level) {
            $level++;
        }
        return $level;
    }
}

$skipList = new SkipList(4);
foreach (range(1, 10) as $i) {
    $skipList->insert($i, "Value $i");
}

$skipList->printEverything();

$skipList->printList();

echo $skipList->find(4);
