# 斐波那契数列
+ https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
## 解法：打表
```java
class Solution {
    public int[] arr;
    public Solution(){
        arr = new int[110];
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2;i < 101; i++){
            arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
        }
    }
    public int fib(int n) {
        return arr[n];
    }
}
```