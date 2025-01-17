
HASHING:
CHECKING ISOGRAM
UNCOMMON CHRACHTERS
ANAGRAM PALINDROME
SUBARRAY WITH 0 SUM
SUBSTRINGS WITH SIMILAR FIRST and LAST CHRACHTERS
STRING REVERSAL
MAXIMUM DISTANCE BETWEEN SAME ELEMENTS
WINNER OF ELECTION
LARGEST SUBARRAY WITH 0 SUM
COUNT DISTINT ELEMENTS IN EVERY WINDOW
DISTINCT SUBSTRINGS
MINIMUM DISTINCT IDS
COUNT THE ELEMENTS
FIND ALL PAIRS WITH K SUM
Count distinct pairs with difference k 
Swapping pairs make sum equal
Count pairs with given sum 
Largest Fibonacci Subsequence 
Numbers containing 1, 2 and 3 
Subarrays with equal 1s and 0s 
PRINT ANAGRAMS TOGETHER
SUBARRAYS WITH SUM K 
LONGEST CONSECATIVE SUBSEQUENCE
SAMPLE FRACTION
TRANSFORM STRING

/*
Check if a string is Isogram or not 
Basic Accuracy: 55.24% Submissions: 23754 Points: 1
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Example 1:

Input:
S = machine
Output: 1
Explanation: machine is an isogram
as no letter has appeared twice. Hence
we print 1.
*/
  bool isIsogram(string s)
    {
      int hash[256];
        memset(hash, 0, sizeof(hash));
      for(int i=0;i<s.size();i++){
          hash[s[i]]++;
      }
      for(int i=0;i<256;i++){
          if(hash[i]>1){
              return false;
          }
      }
      return true;
       
    }
/*
Uncommon characters 
Basic Accuracy: 37.25% Submissions: 7863 Points: 1
Given two strings A and B. Find the characters that are not common in the two strings. 

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
*/
int hash[256]={0};
        int hash2[256]={0};
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
        }
        for(int i=0;i<B.size();i++){
            hash2[B[i]]++;
        }
        string res;
        for(int i=0;i<256;i++){
            if(hash[i]!=0 && hash2[i]==0){
                res+=i;
            }
            else if(hash[i]==0 && hash2[i]!=0){
                res+=i;
            }
        }
         return res.size() == 0 ? "-1" : res;
            // code here
        }
/*
Anagram Palindrome 
Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 

Example 1:

Input:
S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted
into a palindrome: geeksoskeeg
*/
int isPossible (string S)
{
    int hash[256]={0};
    int count=1;
    for(int i=0;i<S.size();i++){
        hash[S[i]]++;
    }
    for(int i=0;i<256;i++){
    if(count==1 &&hash[i]%2==1){
        count++;
    }
           else if(count>1 &&hash[i]%2==1)
        return 0;
        
    }
    
    return 1;
    // your code here
}
/*
Subarray with 0 sum 
Easy Accuracy: 49.91% Submissions: 71355 Points: 2
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
*/
//Your code here
bool subArrayExists(int arr[], int n)
    {
        
        int sum=0;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
        }
        for(auto x:mp){
            if(x.second>1 || x.first==0){
                return 1;
            }
        }
        return 0;
    }
/*Substrings with similar first and last characters 
Basic Accuracy: 68.4% Submissions: 1801 Points: 1
Given string s, the task is to find the count of all substrings which have the same character at the beginning and end.

Example 1:

Input: s = "abcab"
Output: 7
Explanation: a, abca, b, bcab, 
c, a and b
*/
// Your code goes here
	int countSubstringWithEqualEnds(string s)
	{
	   
	    int hash[256]={0};
	    int res=0;
	    for(int i=0;i<s.size();i++){
	        hash[s[i]]++;
	    }
	    for(int i=0;i<256;i++){
	        res+=(hash[i]*(hash[i]+1))/2;
	    }
	    return res;
	}
/*
String Reversal 
Basic Accuracy: 69.01% Submissions: 1313 Points: 1
Given a string, say S, print it in reverse manner eliminating the repeated characters and spaces.

Example 1:

Input: S = "GEEKS FOR GEEKS"
Output: "SKEGROF"
*/
string reverseString(string s)
{
    //code here.
  int hash[256]={0};
  string str;
  for(int i=0;i<s.size()-1;i++){
      if(s[i]!=' ')
      hash[s[i]]++; 
  }
    for(int i=s.size()-1;i>=0;i--){
          if(hash[s[i]]>=1){
             str+=s[i];
             hash[s[i]]=-1;
          }
      }
 
  return str;
    
}

/*Subarray with 0 sum 
Easy Accuracy: 49.91% Submissions: 71355 Points: 2
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
//Your code here*/
bool subArrayExists(int arr[], int n)
    {
        
        int sum=0;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
        }
        for(auto x:mp){
            if(x.second>1 || x.first==0){
                return 1;
            }
        }
        return 0;
    }
 bool subArrayExists(int arr[], int n)
    {
        unordered_set<int>s;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(s.find(sum)!=s.end() || arr[i]==0||sum==0 )return true;
            s.insert(sum);
        }
        return false;
        //Your code here
    }
/*
Max distance between same elements 
Easy Accuracy: 50.34% Submissions: 26427 Points: 2
Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5
*/
 int maxDistance(int arr[], int n)
    {
        int maxi=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end())
            mp[arr[i]]=i;
            maxi=max(maxi,i-mp[arr[i]]);
            
        }
        return maxi;
    //Code here
    }
/*Winner of an election 
Easy Accuracy: 49.75% Submissions: 19414 Points: 2
Given an array of names (consisting of lowercase characters) of candidates in an election.
A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes.
If there is tie, print lexicographically smaller name.

Example 1:

Input:
n = 13
Votes[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4
Explanation: john has 4 votes casted for 
him, but so does johny. john is 
lexicographically smaller, so we print 
john and the votes he received.
*/
 vector<string> winner(string arr[],int n)
    {
        vector<string>s;
        string res;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int count=0;
        for(auto x:mp){
            count=max(count,x.second);
            
        }
        for(auto x:mp){
            if(x.second==count){
            string ans=x.first;
            if(res.size()==0 || ans<res){
                res=ans;
            }
            }
            
        }
             return{res,to_string(count)};
        
    }

//Largest subarray with 0 sum
int maxLen(vector<int>&A, int n)
    {   
        // Your code here
     unordered_map<int,int>mp;
        int maxLen=0;
        int sum=0; 
// to consider corner case if sum of elements from 0 to i is zero then length would be i-(-1)=i+1.
        mp[0]=-1; 
        for(int i=0;i<n;i++){
            sum+=A[i];
        if(mp.find(sum)!=mp.end())maxLen=max(maxLen,i-mp[sum]);
            else mp[sum]=i;
        }
        return maxLen;
    }
/*

Count distinct elements in every window 
Easy Accuracy: 44.16% Submissions: 70051 Points: 2
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.*/
   vector <int> countDistinct (int A[], int n, int k)
    { 
        vector<int>v;
            unordered_map<int,int>s;
        for(int i=0;i<k;i++){
        
            s[A[i]]++;
        }
        v.push_back(s.size());
        int j=0;
        for(int i=k;i<n;i++){
        s[A[j]]--;
        if(s[A[j]]==0){
            s.erase(A[j]);
        }
        s[A[i]]++;
        v.push_back(s.size());
        j++;
        
        }
        return v;
        //code here.
    }
/*
Distinct Substrings 
Easy Accuracy: 58.8% Submissions: 780 Points: 2
Given a string s consisting of uppercase and lowercase alphabetic characters. 
Return the  number of distinct substrings of size 2 that appear in s as contiguous substrings.

Example

Input :
s = "ABCAB"
Output :
3
Explanation:  For "ABCAB", the 
three distinct substrings of size 
2 are "AB", "BC" and "CA". 
*/
int fun(string s)
{
    unordered_map<string,int>mp;
    int count=0;
   for(int i=0;i<s.size()-1;i++){
       string str;
       str+=s[i];
       str+=s[i+1];
       mp[str]++;
       
       
   } 
   for(auto x:mp){
       count++;
   }
   return count;

}
/*
Minimum Distinct Ids 
Easy Accuracy: 46.58% Submissions: 1334 Points: 2
Given an array of items, the i'th index element denotes the item id’s and given a number m,
the task is to remove m elements such that there should be minimum distinct id’s left. Print the number of distinct id’s.

Example 1 -

Input:
n = 6
arr[] = {2, 2, 1, 3, 3, 3}
m = 3
Output:
1
Explanation : 
Remove 2,2,1
*/
unordered_map<int,int> mp;
for(int i = 0; i < n; i++)
mp[arr[i]]++;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int count = 0;
for(auto it : mp)
{
pq.push({it.second, it.first});
}
while(!pq.empty() && m--)
{
int x = pq.top().first;
int y = pq.top().second;
pq.pop();
x--;
if(x != 0)
pq.push({x, y});
}

return pq.size(); 
}
/*
Count the elements 
Easy Accuracy: 60.23% Submissions: 684 Points: 2
Given two arrays a and b. Given q queries each having a positive integer i denoting an index of the array a. 
For each query, your task is to find all the elements less than or equal to qi in the array b.

Example 1:

Input:
N=6
a[] = {1, 2, 3, 4, 7, 9}
b[] = {0, 1, 2, 1, 1, 4} 
Query 1 -> 5
Query 2 -> 4
Output : 6
         6
Explanation: For 1st query, the given index is 5,
             A[5] is 9 and in B all the elements 
             are smaller than 9.
             For 2nd query, the given index is 4, 
             A[4] is 7 and in B all the elements 
             are smaller than 7. 
*/
vector<long long> find(vector<long long> a,vector<long long> b,vector<long long> q) {
vector<long long>v;
unordered_map<int,int>mp;

for(long long i=0;i<b.size();i++)mp[b[i]]++;
for(int i=0;i<q.size();i++){
    int qu=a[q[i]];
    int count=0;
    for(auto x:mp){
        if(x.first<=qu){
            count+=x.second;
        }
    }
  
    v.push_back(count);
}
  return v;  
}
/*
Find all pairs with a given sum 
Easy Accuracy: 38.72% Submissions: 7618 Points: 2
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

 

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.
*/
 vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int k)
    {
         unordered_set<int> s;
   
   for(int i = 0; i < m; i++)
   {
       s.insert(b[i]);
   }
   
   
   vector<pair<int,int>> res;
   
   for(int i = 0; i < n; i++)
   {
       if(s.find(k - a[i]) != s.end())
       {
           res.push_back({a[i], k - a[i]});
       }
   }
   
   sort(res.begin(), res.end());
   
   return res;
    
    }
/*
Count distinct pairs with difference k 
Easy Accuracy: 31.01% Submissions: 7076 Points: 2
Given an integer array and a non-negative integer k, count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k
 

Example 1:

Input: array = {1, 5, 4, 1, 2}, k = 0
Output: 1
Explanation: There is only one pair (1, 1)
whose difference equal to 0.
*/
int TotalPairs(vector<int>nums, int k){
	   unordered_map<int,int>s;
	   int count=0;
	   for(int i=0;i<nums.size();i++){
	       s[nums[i]]++;;
	   }
	   if(k!=0){
	   for(auto it:s){
	       if(s.find(k+it.first)!=s.end()){
	           count++;
	       }
	   }
	   }
	   else{
	       for(auto it = s.begin(); it != s.end(); ++it)
               if(it->second > 1)
                   ++count;
	   }
	   return count;
	    // Code here
	}
/*
Swapping pairs make sum equal 
Easy Accuracy: 41.35% Submissions: 12576 Points: 2
Given two arrays of integers A[] and B[] of size N and M, 
the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

 

Example 1:

Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in A[] = 11
Sum of elements in B[] = 15, To get same 
sum from both arrays, we can swap following 
values: 1 from A[] and 3 from B[]
*/
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    sort(A,A+n);
	    sort(B,B+m);
	    int k=0;
	    int j=0;
	    int sum1=0;
	    int sum2=0;
	    for(int i=0;i<n;i++)sum1+=A[i];
	     for(int i=0;i<m;i++)sum2+=B[i];
	     
	  
	    while(k<n && j<m){
	        
	        if(sum1-A[k]+B[j]>sum2-B[j]+A[k]){
	            k++;
	        }
	        else if(sum1-A[k]+B[j]<sum2-B[j]+A[k]){
	            j++;
	        }
	        else{
	            return 1;
	        }
	    }
	    return -1;
        // Your code goes here
	}
/*
Count pairs with given sum 
Easy Accuracy: 41.59% Submissions: 79930 Points: 2
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
*/
 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int c=0;
        for(int i=0;i<n;i++){
            if(mp.find(k-arr[i])!=mp.end()){
            c+=mp[k-arr[i]];
              mp[arr[i]]++;
            }
   else{
        mp[arr[i]]++;
  }
	}
        return c;
       // code here
    }
/*
Largest Fibonacci Subsequence 
Easy Accuracy: 63.25% Submissions: 1592 Points: 2
Given an array with positive number the task to find the largest subsequence from array that contain elements which are Fibonacci numbers.

 

Example 1:

Input : arr[] = {1, 4, 3, 9, 10, 13, 7}
Output : subset[] = {1, 3, 13}
The output three numbers are Fibonacci
numbers.
*/
 vector<int> findFibSubset(int arr[], int n) {
        
         vector<int>v;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
         maxi=max(maxi,arr[i]);   
        }
    unordered_map<int,int>fib;
    int sum = 0;
int a = 0;
int b = 1;
int k=0;
    while(sum<=maxi){
        fib[sum]++;
        a=b;
        b=sum;
        sum=a+b;
    }
        
        for(int i=0;i<n;i++){
            if(fib.find(arr[i])!=fib.end()){
                v.push_back(arr[i]);
            }
	}
        return v;
    }
/*
Numbers containing 1, 2 and 3 
Easy Accuracy: 52.63% Submissions: 5915 Points: 2
Given an array arr[] of n numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

Example 1:

Input:
n = 3
arr[] = {4,6,7}
Output: -1
Explanation: No elements are there in the 
array which contains digits 1, 2 or 3.
*/
 bool validEntry(int n) {
    
    while(n) {
        int key = n % 10;
        
        if(key == 0 or key >= 4) return false;
        
        n = n/10;
    }    
    return true;
}
//Function to find all the numbers with only 1,2 and 3 in their digits.
void findAll() {
   for(int i = 1; i < 1e6+1; ++i) {
        
        if(validEntry(i)) mp[i]++;
    }
} 
/*
Subarrays with equal 1s and 0s 
Medium Accuracy: 50.04% Submissions: 19978 Points: 4
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)

*/
 long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(long long i=0;i<n;i++){
            if(arr[i]==0)arr[i]=-1;
        }
        long long sum=0;
        unordered_map<long long,long long >mp;
        for(long long int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
        }
        long long count=0;
        for(auto x:mp){
            if(x.second>1){
            long long int f=x.second;
            count+=(f*(f-1))/2;
            }
        }
        if(mp.find(0)!=mp.end()){
            count+=mp[0];
        }
        return count;
        //Your code here
    }

Print Anagrams Together 
Medium Accuracy: 56.1% Submissions: 20347 Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
*/
 vector<vector<string> > Anagrams(vector<string>& string_list) {
         vector<vector<string>> vect;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<string_list.size();i++){
            string fist=string_list[i];
            sort(fist.begin(),fist.end());
            mp[fist].push_back(string_list[i]);
        }
        for(auto x:mp){
            vect.push_back(x.second);
        }
        return vect;
        //code here
    }
/*
Subarrays with sum K 
Medium Accuracy: 60.17% Submissions: 8781 Points: 4
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.


Example 1:

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.
*/
 int findSubArraySum(int Arr[], int N, int k)
    {
        unordered_map<int,int>mp;
        int count=0,sum=0;
        for(int i=0;i<N;i++){
            sum+=Arr[i];
            if(sum==k){
                count++;
            }
             if(mp.find(sum-k)!=mp.end()){
               count+=mp[sum-k];
           }
            mp[sum]++;
           
        }
        return count;
        
        // code here
    }
/*
Longest consecutive subsequence 
Medium Accuracy: 48.9% Submissions: 86739 Points: 4
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
*/
 unordered_map<int,int>mp;
        for(int i=0;i<N;i++)mp[arr[i]]++;
        int first=0;
        int count=1;
        int maxi=1;
        for(int i=0;i<N;i++){
            if(mp.find(arr[i]-1)==mp.end()){
                first=arr[i];
                count=1;
            
           while(mp.find(first+count)!=mp.end()){
               count++;
               
           }
            maxi=max(maxi,count);
            
        }
        }
    return maxi;
}
/*
/*
A Simple Fraction 
Medium Accuracy: 48.0% Submissions: 19113 Points: 4
Given a fraction. Convert it into a decimal. 
If the fractional part is repeating, enclose the repeating part in parentheses.
 

Example 1:

Input: numerator = 1, denominator = 3
Output: "0.(3)"
Explanation: 1/3 = 0.3333... So here 3 is 
recurring.
*/
//just count number of zeroes and frequencies of distinct sum
/*
*/
 unordered_map<int,int>m;
        int q= n/d;
        string ans=to_string(q);
        int r=0;
        if(n%d==0)
        {
            return ans;
        }
        else
        {
            ans+='.';
            r=n%d;
            while(r!=0)
            {
                if(m.find(r)!=m.end())
                {
                    int l=m[r];
                    ans.insert(l,"(");
                    ans+=")";
                    break;
                }
                else
                {
                    m[r]=ans.length();
                    r*=10;
                    q=r/d;
                    r=r%d;
                    ans = ans+to_string(q);
                }
                
            }
        }
    
	  return ans;  // Code here
	}
};
/*
Transform String 
Medium Accuracy: 44.38% Submissions: 2556 Points: 4
Given two strings A and B. Find the minimum number of steps required to transform string A into string B.
The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

Example 1:

Input:
A = "abd"
B = "bad"
Output: 1
Explanation: The conversion can take place in
1 operation: Pick 'b' and place it at the fron
*/
 int transform (string A, string B)
    {if(A.length()!=B.length()){
        return -1;
    }
    int n=A.size();
    unordered_map<char,int>mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
        mp[B[i]]--;
    }
    for(auto x:mp){
        if(x.second!=0){
            return -1;
        }
    }
    
int i=n-1;
int j=n-1;
int res=0;
while(i>=0 &&j>=0 ){
    while(i>=0 && A[i]!=B[j]){
        res++;
        i--;
    }
    i--;
    j--;
}
     return res;   //code here.
    }
