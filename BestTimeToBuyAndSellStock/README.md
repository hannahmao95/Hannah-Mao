Best Time to Buy and Sell Stock<br />

Example 1:.<br />
Input: address = "1.1.1.1".<br />
Output: "1[.]1[.]1[.]1".<br />

Example 2:.<br />
Input: address = "255.100.50.0".<br />
Output: "255[.]100[.]50[.]0".

Say you have an array for which the ith element is the price of a given stock on day i.<br />

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.<br />

Note that you cannot sell a stock before you buy one.<br />

Example 1:<br />

Input: [7,1,5,3,6,4]<br />
Output: 5<br />
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.<br />
             Not 7-1 = 6, as selling price needs to be larger than buying price.<br />
             
Example 2:<br />

Input: [7,6,4,3,1]<br />
Output: 0<br />
Explanation: In this case, no transaction is done, i.e. max profit = 0.<br />