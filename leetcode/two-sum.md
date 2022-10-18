## 题目描述

[two sum](https://leetcode.cn/problems/two-sum/)

## 代码

```python
def twoSum(nums,target):
    hashmap = {}
    for ind,num in enumerate(nums):
        hashmap[num]=ind
        if hashmap.get(target-num) is not None:
            return [i,hashmap.get(target-num)]
        hashmap[num]=i
       
```

```java
class Solution{
    public int[] twoSum(int[] nums,int target){
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
    }
    for(int i=0;i<nums.length;i++){
        if(hashtable.containsKey(target-nums[i])){
            return new int[]{hashtable.get(target-nums[i],i)}
        }
        hashtable.put(target-nums[i],i)
    }
    return new int[]{0}
}
```

```

```

