class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> ans;
        int i;
        for(i = 0; i<k; i++){
        }
        int l = 0;
        int r = i;
        while(r <= n){
            int maxi = INT_MIN;
            for(int i = l; i<r; i++){
                maxi = max(maxi , arr[i]);
            }
            ans.push_back(maxi);
            l++;
            r++;
        }
        return ans;
    }
};