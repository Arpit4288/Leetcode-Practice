public class Solution 
{
    public void Rotate(int[] arr, int k) 
    {
            k = k % arr.Length;
            Array.Reverse(arr);
            Array.Reverse(arr, 0, k);
            Array.Reverse(arr, k, arr.Length-k);
    }
}
/*
1, 2, 3, 4, 5, 6, 7,   ==> manual   7, 1, 2, 3, 4, 5, 6  -> 6, 7, 1, 2, 3, 4, 5 --> 5, 6, 7, 1, 2, 3, 4
7, 6, 5, 4, 3, 2, 1, 
5, 6, 7, 4, 3, 2, 1, 
5, 6, 7, 1, 2, 3, 4, 
*/
