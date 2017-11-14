#include <iostream>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

// 比较这个工程中 main1, main2, main3, main4 和 main5 的算法运行效率

// main1的方案
int lengthOfLongestSubstring1(const string& s) {

    int freq[256] = {0};
    int l = 0, r = -1;
    int res = 0;

    while(l < s.size()){
        if(r + 1 < s.size() && freq[s[r+1]] == 0)
            freq[s[++r]] ++;
        else
            freq[s[l++]] --;

        res = max(res, r-l+1);
    }

    return res;
}

// main2的方案
int lengthOfLongestSubstring2(const string& s) {

    int freq[256] = {0};
    int l = 0, r = 0;
    int res = 0;

    while( r < s.size() ){
        if( freq[s[r]] == 0 )
            freq[s[r++]] ++;
        else    //freq[s[r]] == 1
            freq[s[l++]] --;

        res = max( res , r-l);
    }

    return res;
}


// main3 的方案
int lengthOfLongestSubstring3(const string& s) {

    int freq[256] = {0};

    int l = 0, r = -1;
    int res = 0;

    while( r + 1 < s.size() ){

        while( r + 1 < s.size() && freq[s[r+1]] == 0 )
            freq[s[++r]] ++;

        res = max( res , r-l+1);

        if( r + 1 < s.size() ){
            freq[s[++r]] ++;
            assert( freq[s[r]] == 2 );
            while( l <= r && freq[s[r]] == 2 )
                freq[s[l++]] --;
        }
    }

    return res;
}


// 查看s[l...r-1]之间是否存在s[r]
// 若存在,返回相应的索引, 否则返回-1
int isDuplicateChar(const string& s, int l, int r){
    for(int i = l ; i < r ; i ++)
        if(s[i] == s[r])
            return i;
    return -1;
}

// main4的方案
int lengthOfLongestSubstring4(const string& s) {

    int l = 0, r = 0; //滑动窗口为s[l...r]
    int res = 0;

    while( r < s.size() ){

        int index = isDuplicateChar(s, l, r);
        if( index != -1 )
            l = index + 1;

        res = max(res, r-l+1);
        r ++;
    }

    return res;
}


// main5的方案
int lengthOfLongestSubstring5(const string& s) {

    int last[256];
    memset(last, -1, sizeof(last));

    int l = 0, r = -1;
    int res = 0;
    while(r + 1 < s.size()){
        r ++;
        if(last[s[r]] != -1)
            l = max(l, last[s[r]] + 1);

        res = max(res, r - l + 1);
        last[s[r]] = r;
    }

    return res;
}


void testPerformance(const string& algoName,
                     int (*lengthOfLongestSubstring)(const string&),
                     const string& s){
    clock_t startTime = clock();
    int res = lengthOfLongestSubstring(s);
    clock_t endTime = clock();

    cout << algoName << " : res = " << res << " ";
    cout << "Time = " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}


int main() {

    int n = 10000000;

    // 测试, 使用长度为1000万的完全随机字符串
    // 每一个字符是asc ii码从32-126之间的随机字符
    string s = "";
    for(int i = 0 ; i < n ; i ++)
        s += (rand()%95 + 32);

    cout << "Test: 10,000,000 length of completely random string:" << endl;
    testPerformance("algo1", lengthOfLongestSubstring1, s);
    testPerformance("algo2", lengthOfLongestSubstring2, s);
    testPerformance("algo3", lengthOfLongestSubstring3, s);
    testPerformance("algo4", lengthOfLongestSubstring4, s);
    testPerformance("algo5", lengthOfLongestSubstring5, s);

    return 0;
}