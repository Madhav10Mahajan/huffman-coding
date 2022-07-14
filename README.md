# huffman-coding
Huffman coding is file compression algorithm based on greedy approach.
it is implemented using a lot of data structures such as hash maps, vectors, priority queues and trees.
you will learn a lot about data structures by making this project since it involves use of a lot of data structures.
it also involves the use of OOPS concept that is object-oriented programming.

IMPLEMENTATION: 

1) the idea it first to calculate the frequency of all characters using a HashMap or a vector of type pair<char,int>.
2) the create a priority queue (min heap)  an insert all the elements inside the minheap.
3) create a custom Huffman class with data members such as char data, int freq, Node* right and Node* left and initialize all of them with a parametrized constructor.
4) now traverse the minheap one by one pop out all the elements form the minheap 2 at a time and create Huffman nodes.
5) then add the frequencies of the two nodes to create a newnode and connect its left pointer to one of the nodes and its right pointer to the other node.
6) return the root of the final node.
7) now travers the tree and mark all the left edges with 0 and right edges with 1 or vice versa.
8) find out the unique code for all the characters and multiply the bits in the unique code with their frequencies and add them to get the new size.
9) the original size of the file would be no of characters X 8 assuming ascii value is represented in 8bits.
10) this is how you can get the new compressed file with smaller size as compare to the original and in this process you learned the use of hash maps, trees, priority queues, vectors and making custom comparator along with the use of OOPS.
