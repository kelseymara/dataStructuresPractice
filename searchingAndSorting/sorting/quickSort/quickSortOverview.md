# Quick Sort overview
from mycodeschool 


Average Case running time: O(nlogn)
Worst Case running time: O(n^2)
- pretty fast and efficient in practical scenarios
- in place sort : does not use extra memory (constant amount of storage space) , sort an existing list by moidfying the element order directly within the list

## Example
Unsorted Array
[7] [2] [1] [6] [8] [5] [3] [4]
indexes:
0 - 1-   2 - 3 - 4 - 5 - 6 - 7

- select one element from the list this will be your PIVOT
- ex. select 4 (index 7)
- rearrange the list so that all of the numbers lesser than the pivot are to the left, and all numbers greater are to the right

after partitioned: 

[2][1][3][pivot: 4][8][ 5] [7]   [6]
indexes: 
0 - 1- 2 ---3----4 - 5 - 6 - 7

- sort segment to left of pivot and sort segment to right of pivot

- do not have to create new arrays and combine them like merge sort
- work on same array, but keep in track of start and end 

split array:
- have two sub problems to solve 
  
[2][1][3]    - - - - - -     [8][5][7]

How do we solve these two sub problems?
Apply the paritioning Logic Once Again: 

- chose a pivot, rearrange sub list such that all elements to left is less than and all elements to right is greater than

- when you have one element in a sub list, that segment is already sorted






