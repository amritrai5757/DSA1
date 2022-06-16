//Subset combinationn where element is a string and combination must not contain more than 1 char from 1 string

vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;         // no combinations formed without any digits
	helper(digits, 0, "");              
	return ans;
}

void helper(string &digits, int i, string combi){	
	if(i == size(digits)) { 
		ans.push_back(combi);    
		return;
	}

	for(auto &c : mappings[digits[i] - '2'])
		helper(digits, i + 1, combi + c);
}