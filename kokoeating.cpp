class Solution {
    public:
        bool check(int speed, vector<int> &piles, int h) {
            long long count = 0;
            for (int pile : piles) {
                count += (pile + speed - 1) / speed; 
            }
            return count <= h;
        }
    
        int minEatingSpeed(vector<int> &piles, int h) {
            int lo = 1, hi = *max_element(piles.begin(), piles.end());
    
            while (lo < hi) { 
                int mid = lo + (hi - lo) / 2;
                if (check(mid, piles, h)) {
                    hi = mid; 
                } else {
                    lo = mid + 1;
                }
            }
            return lo;
        }
    };
    