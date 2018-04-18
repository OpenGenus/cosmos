<?php

class Node
{
    public $value, $next;

    public function __construct($value, ?Node $next = null) {
        $this->value = $value;
        $this->next = $next;
    }

    public function __toString() {
        return (string)$this->value;
    }
}

class LinkedList
{
    private $head;

    public function __construct() {
        $this->head = null;
    }

    public function add($value): void {
        $node = new Node($value);
        if ($this->isEmpty()) {
            $this->head = $node;
            return;
        }

        $curr = $this->head;
        while ($curr->next) {
            $curr = $curr->next;
        }

        $curr->next = $node;
    }

    public function delete(int $index): void {
        if ($this->isEmpty()) {
            return;
        }

        $curr = $this->head;
        $prev = null;
        $counter = 0;
        while ($curr->next && $counter != $index) {
            $prev = $curr;
            $curr = $curr->next;
            $counter++;
        }

        if ($counter !== $index) {
            $list = $this->print();
            throw new Exception("Index ${index} not exists in ${list}");
        }

        if (null === $prev) {
            $this->head = $this->head->next();
            return;
        }
        $prev->next = $curr->next;
    }

    public function get(int $index) {
        if ($this->isEmpty()) {
            return null;
        }

        $curr = $this->head;
        $counter = 0;
        while ($curr->next) {
            if ($counter === $index) {
                return $curr->value;
            }
            $curr = $curr->next;
            $counter++;
        }

        return null;
    }

    public function insert($value): void {
        $this->head = new Node($value, $this->head);
    }

    public function isEmpty(): bool {
        return $this->head === null;
    }

    public function search($needle) {
        if ($this->isEmpty()) {
            return null;
        }

        $curr = $this->head;
        while ($curr->next) {
            if ($curr->value === $needle) {
                return $curr->value;
            }
            $curr = $curr->next;
        }

        return null;
    }

    public function size(): int {
        if ($this->isEmpty()) {
            return 0;
        }

        $curr = $this->head;
        $counter = 1;
        while ($curr->next) {
            $curr = $curr->next;
            $counter++;
        }

        return $counter;
    }

    public function print(): string {
        if ($this->isEmpty()) {
            return "";
        }

        $curr = $this->head;
        $output = "${curr}, ";
        while (null !== $curr->next) {
            $curr = $curr->next ?? $curr;
            $output .= "${curr}, ";
        }

        return substr($output, 0, -2);
    }
}

$list = new LinkedList();
$result = $list->print() === "" && $list->size() === 0;
echo "Empty test: ${result}", PHP_EOL;

foreach (range(1, 5) as $no) {
    $list->add($no);
}
$result = $list->print() === '1, 2, 3, 4, 5';
echo "Many elems: ${result}", PHP_EOL;


$list->insert('HEAD');
$result = $list->print() === 'HEAD, 1, 2, 3, 4, 5';
echo "Inserting: ${result}", PHP_EOL;

try {
    $list->delete(3);
    $result = $list->print() === 'HEAD, 1, 2, 4, 5';
    $list->delete(4);
    $result = $result && $list->print() === 'HEAD, 1, 2, 4';
    $list->delete(3);
    $result = $result && $list->print() === 'HEAD, 1, 2';
} catch (Exception $e) {
    $result = false;
}
echo "Deleting: ${result}", PHP_EOL;