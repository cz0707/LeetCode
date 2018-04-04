/*
给定一个字符串，找出不含有重复字符的 最长子串 的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列 而不是子串。
*/

//自己做法：
int lengthOfLongestSubstring(char* s) {
	int max = 0;
	int num=0;
	int i, j;
	int b[200] = { 0 };
	for (i = 0; i<strlen(s); i++) {
		for (j = i; j<strlen(s); j++) {            //时间复杂度O(N^2),时间不满足要求！！有一个测试例子时间过长，不通过！
			if (b[s[j]] == 0) {
				num++;
				b[s[j]]++;
			}
			else {
				max = num>max ? num : max;
				num=0;
				memset(b,0,sizeof(int)*200);
				break;
			}
		}
	}
	max = num>max ? num : max;
	return max;
}

//双指针i，j做法，当遇到重复字符时不需要从头重新开始计算，只需要到重复的字符中前一个位置的后一个位置处开始
int lengthOfLongestSubstring(char* s) {
    int max=0;
    int b[200]={0};
    int i=0;  
    int j=0;  
    int length=strlen(s);  
    while(j<length)  
    {  
        if(b[(int)s[j]]==1)                          //char强制转换成int型
        {  
            while(s[i]!=s[j]) b[(int)s[i++]]=0;      //遇到重复字符s[j],则i置到前一个一样的字符位置，之间字符重复flag置0
            i++;                                     //i置于下一个位置
        }  
        b[(int)s[j]]=1;  
        j++;  
        if(j-i>max) max=j-i;                         //最长长度即是j-i
    }  
    max=max>(j-i)?max:(j-i);  
    return max;  
}  
