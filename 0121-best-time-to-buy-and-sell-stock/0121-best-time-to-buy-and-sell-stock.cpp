class Solution{
 public:
  int maxProfit(vector<int> &prices){
	  int currMin = prices[0];
	  int currMax = prices[0];
	  int currProfit = 0;
	  int profit = 0;
	  for (int price : prices){
		  if (price < currMin){
			  currMin = price;
			  currMax = price;
		  }
		  if (price > currMax){
			  currMax = price;
			  currProfit = currMax - currMin;
		  }
		  if (currProfit > profit){
			  profit = currProfit;
		  }
	  }
	  return profit;
  }
};