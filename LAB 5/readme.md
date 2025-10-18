# 📘 DSA Lab 5

This lab focuses on **Queues**, **Circular Data Structures**, and **Stream Processing**.  
It covers practical implementations of queues and real-world simulations using data structures.

---

## 🧩 Questions

### **Q1. Circular Double-Ended Queue (Deque)**
Design your implementation of the **Circular Double-Ended Queue (Deque)**.

#### Class Structure:
Implement the `MyCircularDeque` class with the following methods:
- **MyCircularDeque(int k)** – Initializes the deque with a maximum size of `k`.  
- **boolean insertFront()** – Adds an item at the front of Deque. Returns true if the operation is successful.  
- **boolean insertLast()** – Adds an item at the rear of Deque. Returns true if successful.  
- **boolean deleteFront()** – Deletes an item from the front. Returns true if successful.  
- **boolean deleteLast()** – Deletes an item from the rear. Returns true if successful.  
- **int getFront()** – Returns the front item from Deque or -1 if empty.  
- **int getRear()** – Returns the last item from Deque or -1 if empty.  
- **boolean isEmpty()** – Returns true if the deque is empty.  
- **boolean isFull()** – Returns true if the deque is full.

---

### **Q2. The Josephus Problem (Game Simulation)**
There are `n` friends sitting in a circle, numbered 1 to `n`.  
Every `k`-th friend is eliminated in a clockwise manner until only one remains.  
Return the number of the friend who wins the game.

#### Requirements:
- Simulate the elimination process using a circular queue or linked list.
- Start at the 1st friend, count `k` friends, remove the `k`-th friend, and continue until one remains.

---

### **Q3. Customer Service Call Center Simulation**
Simulate a **call center** with a fixed number of **Customer Service Representatives (CSRs)**.

#### Requirements:
- Use a **Queue** to manage incoming calls.
- Each CSR handles one call at a time.
- Simulate arrival, processing, and completion of calls.

#### Implementation Details:
- Define a **Call** class with attributes: `Call ID`, `Arrival Time`, `Customer Name`.
- Define a **CallCenter** class with:
  - A queue for incoming calls.  
  - An integer for the number of CSRs.  
  - A boolean vector to track CSR availability.  
- Include methods to:
  - Add new calls to the queue.  
  - Assign calls to available CSRs.  
  - Simulate processing and completion of calls.  

---

### **Q4. Product of Last K Numbers**
Design an algorithm that maintains a **stream of integers** and retrieves the **product of the last `k` numbers**.

#### Class Structure:
Implement the `ProductOfNumbers` class:
- **ProductOfNumbers()** – Initializes an empty stream.  
- **void add(int num)** – Appends `num` to the stream.  
- **int getProduct(int k)** – Returns the product of the last `k` numbers.  

*(Assume the product fits within a 32-bit integer.)*

---

### **Q5. Data Stream with Consecutive Value Check**
Implement a data structure that checks if the **last `k` integers** in a stream are equal to a given value.

#### Class Structure:
Implement the `DataStream` class:
- **DataStream(int value, int k)** – Initializes the stream with parameters `value` and `k`.  
- **boolean consec(int num)** – Adds `num` to the stream and returns true if the last `k` integers are equal to `value`, false otherwise.  

If there are fewer than `k` integers, the condition returns false.

---

## 🧠 Concepts Covered
- Queue and Deque Implementation  
- Circular Data Structures  
- Simulation and Real-World Modeling  
- Stream Data Processing  
- Class Design and Encapsulation  

---

## ✨ Author
*Eman Anjum*  
Bachelor’s in Computer Science, **NED University**
