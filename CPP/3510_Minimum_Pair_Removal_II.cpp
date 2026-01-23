#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<long long> val(n);
        vector<int> L(n), R(n);
        vector<int> ver(n, 0); 

        
        using Element = tuple<long long, int, int>;
        priority_queue<Element, vector<Element>, greater<Element>> pq;

        int bad_count = 0;

        for(int i = 0; i < n; ++i) {
            val[i] = nums[i];
            L[i] = i - 1;
            R[i] = i + 1;
            
            if (i + 1 < n) {
                if (nums[i] > nums[i+1]) bad_count++;
                pq.push({(long long)nums[i] + nums[i+1], i, 0});
            }
        }
        R[n-1] = -1;

        if (bad_count == 0) return 0;

        int ops = 0;
        
        while (bad_count > 0 && !pq.empty()) {
            auto [sum, u, v_ver] = pq.top();
            pq.pop();

           
            if (v_ver != ver[u]) continue;

            int v = R[u];
            if (v == -1) continue; 

            ops++;

            
            if (L[u] != -1 && val[L[u]] > val[u]) bad_count--;
            if (val[u] > val[v]) bad_count--;
            if (R[v] != -1 && val[v] > val[R[v]]) bad_count--;

            // B. Qiymatlarni yangilaymiz
            val[u] += val[v]; 
            int next_node = R[v];
            R[u] = next_node; 
            if (next_node != -1) {
                L[next_node] = u; 
            }
            
           
            ver[u]++;       
            if (L[u] != -1) ver[L[u]]++; 
            ver[v]++;       
            
            if (L[u] != -1) {
                if (val[L[u]] > val[u]) bad_count++;
                pq.push({val[L[u]] + val[u], L[u], ver[L[u]]});
            }
            
            if (R[u] != -1) {
                if (val[u] > val[R[u]]) bad_count++;
                pq.push({val[u] + val[R[u]], u, ver[u]});
            }
        }
        
        return ops;
    }
};
