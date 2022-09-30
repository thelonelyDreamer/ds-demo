import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    public String solve (String s, String t) {
        // write code here
        StringBuffer buffer = new StringBuffer();
        int length1 = s.length();
        int length2 = t.length();
        int max = length1 > length2 ? length1 : length2;
        int full = 0;
        for (int i = 0; i < max; i++) {
            int x1, x2;
            if (i < length1) {
                x1 = s.charAt(length1 - 1 - i) - '0';
            } else {
                x1 = 0;
            }
            if (i < length2) {
                x2 = t.charAt(length2 - 1 - i) - '0';
            } else {
                x2 = 0;
            }
            int temp = x1 + x2 + full;
            if (temp > 9) {
                temp = temp - 10;
                full = 1;
            } else {
                full = 0;
            }
            buffer.append(temp);
        }
        if (full == 1) {
            buffer.append(1);
        }
        return buffer.reverse().toString();
    }
}