<?php

class Node
{
    public $value, $prev, $next;

    public function __construct($value, $prev = null, $next = null) {
        $this->value = $value;
        $this->prev = $prev;
        $this->next = $next;
    }
}

class DoublyLinkedList
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

        $iter = $this->head;
        while ($iter->next) {
            $iter = $iter->next;
        }

        $iter->next = $node;
        $iter->next->prev = $iter;
    }

    public function delete(int $index): void {
        if ($this->isEmpty()) {
            return;
        }

        $iter = $this->head;
        $counter = 0;
        while ($iter->next && $counter != $index) {
            $iter = $iter->next;
            $counter++;
        }

        if ($counter != $index) {
            $list = $this->print();
            throw new Exception("Index ${index} not exists in ${list}");
        }

        if (null === $iter->prev) {
            $this->head = $this->head->next;
            $this->head->prev = null;
            return;
        }

        if (null === $iter->next) {
            $iter->prev->next = null;
            return;
        }
        $iter
            ->next
            ->prev = $iter->prev;
        $iter
            ->prev
            ->next = $iter->next;
    }

    public function addFirst($value): void {
        $node = new Node($value);
        $swap = $this->head;
        $this->head = $node;
        $this->head->next = $swap;
        $this->head->next->prev = $this->head;
    }

    public function isEmpty(): bool {
        return $this->head === null;
    }

    public function print(): string {
        if ($this->isEmpty()) {
            return "Empty list.";
        }

        $iter = $this->head;
        $output = $iter->value . ", ";
        while (null !== $iter->next) {
            $iter = $iter->next ?? $iter;
            $data = $iter->value;
            $output .= "${data}, ";
        }

        return substr($output, 0, -2);
    }
}

$list = new DoublyLinkedList();

foreach (range(1, 5) as $no) {
    $list->add($no);
}
$result = $list->print() === '1, 2, 3, 4, 5';
echo "Many elems: ${result}", PHP_EOL;

$list->addFirst('HEAD');
$result = $list->print() === 'HEAD, 1, 2, 3, 4, 5';
echo "Inserting: ${result}", PHP_EOL;

try {
    $list->delete(0);
    $result = $list->print() === '1, 2, 3, 4, 5';
} catch (Exception $e) {
    $result = false;
}
echo "Deleting: ${result}", PHP_EOL;
