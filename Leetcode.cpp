class Solution {
public:
    int solve(vector<int>& slices){
        int n=slices.size();
        int k=n;
        vector<int> prev(k/3+1,0);
        vector<int> curr(k/3+1,0);
        vector<int> next(k/3+1,0);


        for(int i=n-1; i>=1; i--){
            for(int eat=1; eat<=n/3; eat++){

            int include = slices[i] + prev[eat-1];
            int exclude =     0     + curr[eat];
            next[eat]=max(include, exclude);

            }
            prev=curr;
            curr=next;            
        }

        vector<int> prev1(k/3+1,0);
        vector<int> curr1(k/3+1,0);
        vector<int> next1(k/3+1,0);


        for(int i=n-2; i>=0; i--){
            for(int eat=1; eat<=n/3; eat++){

            int include = slices[i] + prev1[eat-1];
            int exclude =     0     + curr1[eat];
            next1[eat]=max(include, exclude);
            }
            prev1=curr1;
            curr1=next1;            
        }
        return max(curr1[n/3], curr[n/3]);
    }

    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};