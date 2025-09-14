 Lab 1 - Data Structures and Algorithms

This folder contains solutions for **Lab 1** of Data Structures and Algorithms.  
Each question is implemented in its own .cpp file.  

---

Questions

Question 1
Write a C++ program to copy data of a 2D array in a 1D array using **Column Major Order**.

---

Question 2
Write a program to calculate the GPA of students of all subjects of a single semester.  
Assume all the courses have the same credit hour (let’s assume 3 credit hours).  

---

Question 3
The median is the middle value in an ordered integer list. If the size of the list is even,  
there is no middle value, and the median is the mean of the two middle values.  

Implement the MedianFinder class:
- MedianFinder() initializes the object.  
- void addNum(int num) adds the integer num from the data stream.  
- double findMedian() returns the median of all elements so far.  

Example:

Input:  ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
        [[], [1], [2], [], [3], []]
Output: [null, null, null, 1.5, null, 2.0]


Constraints:
- -10^5 <= num <= 10^5  
- At most 5 * 10^4 calls will be made to addNum and findMedian.



Question 4
Given an array of integers nums which is sorted in ascending order, and an integer target,  
write a function to search target in nums. If target exists, return its index. Otherwise, return -1.  
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4


Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1


Constraints:
- 1 <= nums.length <= 10^4  
- -10^4 < nums[i], target < 10^4  
- All integers in nums are unique.



Question 5
Given an m x n integer matrix with the following properties:  
- Each row is sorted in non-decreasing order.  
- The first integer of each row is greater than the last integer of the previous row.  

Given an integer target, return true if target is in matrix or false otherwise.  
You must write a solution in O(log(m * n)) time complexity.

Example:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Constraints:
- m == matrix.length  
- n == matrix[i].length  
- 1 <= m, n <= 100  
- -10^4 <= matrix[i][j], target <= 10^4  



File Mapping
- question1.cpp → Question 1  
- question2.cpp → Question 2  
- question3.cpp → Question 3  
- question4.cpp → Question 4  
- question5.cpp → Question 5  
