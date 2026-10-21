class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    Solution() {}

    // Apply an increment to the entire segment
    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        // Update sum of squares using the OLD sum
        tree[node].sq =
            (tree[node].sq
             + 2LL * x * tree[node].sum
             + len * x % MOD * x) % MOD;

        // Update the sum
        tree[node].sum =
            (tree[node].sum + len * x) % MOD;

        // Store the pending increment
        tree[node].lazy =
            (tree[node].lazy + x) % MOD;
    }

    // Pass pending updates to the children
    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        long long x = tree[node].lazy;

        apply(node * 2, l, mid, x);
        apply(node * 2 + 1, mid + 1, r, x);

        tree[node].lazy = 0;
    }

    // Range update: add x to every element in [ql, qr]
    void update(int node, int l, int r,
                int ql, int qr, long long x) {

        if (ql > r || qr < l) {
            return;
        }

        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, x);

        update(node * 2 + 1, mid + 1, r, ql, qr, x);

        // Merge the children's results
        tree[node].sum =
            (tree[node * 2].sum
             + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq
             + tree[node * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int prev = last[nums[i]];

            // All subarrays starting after the previous
            // occurrence gain one distinct element.
            update(1, 0, n - 1, prev + 1, i, 1);

            // Store the current occurrence
            last[nums[i]] = i;

            // Sum of squares of distinct counts for
            // all subarrays ending at index i
            ans = (ans + tree[1].sq) % MOD;
        }

        return ans;
    }
};