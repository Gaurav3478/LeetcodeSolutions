# Equal Point in Sorted Array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a sorted array <strong>arr[ ]</strong> of <strong>N</strong> positive integers. Your task is to find an index <strong>i</strong> in the array from where the number of elements smaller than <strong>arr[i]</strong> in the left side of the index&nbsp;is equal to the number of elements&nbsp;greater than<strong> arr[i]</strong> in the right side of the index.<br>
If no such index exists, print "-1".</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 6
arr[] = {1, 2, 3, 3, 3, 3}
<strong>Output:</strong>
1
<strong>Explanation:
</strong>2 is the element before which we have one
element that is smaller than 2 and we have
one element to its right which is greater
than 2. Hence, print the index of 2.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 8
arr[] = {1, 2, 3, 3, 3, 3, 4, 4}
<strong>Output:</strong>
-1
<strong>Explanation:</strong>
There is no index as such, so print -1</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findEqualPoint()</strong>&nbsp;which takes the array <strong>arr[]</strong> and its size <strong>N</strong><strong> </strong>as input parameters&nbsp;and returns the required index. If there are multiple indices, return&nbsp;the smallest one. If such index doesn't exist&nbsp;then return "-1" (without quotes).</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N)<br>
<strong>Expected Auxiliary Space: </strong>O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A<sub>i</sub> ≤ 10<sup>12</sup></span></p>
</div>