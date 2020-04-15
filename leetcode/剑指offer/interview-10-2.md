# 青蛙跳台阶问题

## 解法：dp
```java
class Solution {
    public int[] arr;
    public Solution(){
        arr = new int[110];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3;i<110;i++){
            arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
        }
    }
    public int numWays(int n) {
        return arr[n];
    }
}
```