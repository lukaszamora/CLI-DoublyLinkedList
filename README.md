# DoublyLinkedList

An intuitive implementation of a doubly linked list in C++.

## Introduction

A linked list is a linear data structure that links elements, called nodes, together by pointers. These are dynamic in size, and are easy to insert/delete nodes.

Starting at the head node, we can traverse through each node in a single direction. Note that the tail node points to `nullptr`.

![singlell](https://user-images.githubusercontent.com/26682469/48298992-feba2800-e48b-11e8-9654-6b9f36ae302f.png)

However for a doubly linked list, we now have the option of traversing forwards and backwards between nodes. Now both head and tail nodes point to `nullptr`.

![doublell](https://user-images.githubusercontent.com/26682469/48299175-fb746b80-e48e-11e8-9902-2dd50760c2d7.png)

### `DoublyLinkedList.cpp`

This is where the bulk of the project is located. All member function definitions are found here as well as the overloaded insertion operator. This overloaded function is responsible for displaying each node/address and updating whenever it is invoked.

## Demo

Lets create a new doubly linked list named `ll` and insert the values `7, 11, 27` into it We'll also want to output our list after each operation. The output is then:
~~~~
Doubly Linked List
Head: 0xe66ce8   Tail: 0xe66ce8
Nodes (accessible from head to tail):

                      prev            data            next
                .---------------.---------------.---------------.
    0xe66ce8    |       0       |       7       |       0       |
                '---------------'---------------'---------------'



Doubly Linked List
Head: 0xe66d00   Tail: 0xe66ce8
Nodes (accessible from head to tail):

                      prev            data            next
                .---------------.---------------.---------------.
    0xe66d00    |       0       |      11       |   0xe66ce8    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66ce8    |   0xe66d00    |       7       |       0       |
                '---------------'---------------'---------------'



Doubly Linked List
Head: 0xe66d18   Tail: 0xe66ce8
Nodes (accessible from head to tail):

                      prev            data            next
                .---------------.---------------.---------------.
    0xe66d18    |       0       |      27       |   0xe66d00    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66d00    |   0xe66d18    |      11       |   0xe66ce8    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66ce8    |   0xe66d00    |       7       |       0       |
                '---------------'---------------'---------------'


~~~~
Now lets insert a value of `50` into the index `2`. Our linked list is now updated to:

~~~~
Doubly Linked List
Head: 0xe66d18   Tail: 0xe66ce8
Nodes (accessible from head to tail):

                      prev            data            next
                .---------------.---------------.---------------.
    0xe66d18    |       0       |      27       |   0xe66d30    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66d30    |       0       |      50       |   0xe66d00    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66d00    |   0xe66d18    |      11       |   0xe66ce8    |
                '---------------'---------------'---------------'

                .---------------.---------------.---------------.
    0xe66ce8    |   0xe66d00    |       7       |       0       |
                '---------------'---------------'---------------'

~~~~
