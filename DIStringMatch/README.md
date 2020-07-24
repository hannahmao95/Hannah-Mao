DI String Match

Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.<br />

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:<br />

If S[i] == "I", then A[i] < A[i+1]<br />
If S[i] == "D", then A[i] > A[i+1]<br />
 

Example 1:<br />
Input: "IDID"<br />
Output: [0,4,1,3,2]<br />

Example 2:<br />
Input: "III"<br />
Output: [0,1,2,3]<br />

Example 3:<br />
Input: "DDI"<br />
Output: [3,2,0,1]<br />
 