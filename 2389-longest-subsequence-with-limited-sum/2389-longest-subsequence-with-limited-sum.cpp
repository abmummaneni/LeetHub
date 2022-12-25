class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries){
	sort(nums.begin(), nums.end());
	vector<int> ans;
	for (int q : queries){
		int count = 0;
		for (int sum = nums[0]; sum <= q; sum += nums[++count]){
			if (count == nums.size() - 1){ 
				count++;
				break; 
			}
		}
		ans.push_back(count);
	}
	return ans;
    }
};