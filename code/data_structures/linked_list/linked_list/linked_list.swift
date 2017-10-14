//
//  linked_list.swift
//
//  Created by Kajornsak Peerapathananont on 10/14/2560 BE.
//  Copyright © 2560 Kajornsak Peerapathananont. All rights reserved.
//

import Foundation
//: Playground - noun: a place where people can play


public struct Node<T>{
    private var data : T?
    private var next : [Node<T>?] = []
    
    init() {
        self.data = nil
    }
    
    init(data : T){
        self.data = data
    }
    
    func getData()->T? {
        return self.data
    }
    
    func getNext()->Node<T>?{
        return self.next[0]
    }
    
    mutating func setNext(next : Node<T>?){
        self.next = [next]
    }
}


public struct LinkedList<T>{
    private var head : Node<T>?
    
    init() {
        self.head = nil
    }
    
    init(head : Node<T>?) {
        self.head = head
    }
    
    func size() -> Int {
        if var current_node = head{
            var len = 1
            while let next = current_node.getNext(){
                current_node = next
                len += 1
            }
            return len
        }
        return 0
    }
    
    mutating func insert(data : T){

        var node : Node<T> = Node<T>(data: data)
        node.setNext(next : self.head)
        self.head = node
    }
    
  
}


