class Solution {
    // Max Segment Tree storing gap sizes, indexed by compressed obstacle positions
    static int[] seg;
    static int N;

    static void update(int node, int lo, int hi, int idx, int val) {
        if (lo == hi) { seg[node] = val; return; }
        int mid = (lo + hi) / 2;
        if (idx <= mid) update(2*node,   lo,    mid, idx, val);
        else            update(2*node+1, mid+1, hi,  idx, val);
        seg[node] = Math.max(seg[2*node], seg[2*node+1]);
    }

    static int query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) return seg[node];
        int mid = (lo + hi) / 2;
        return Math.max(query(2*node,   lo,    mid, l, r),
                        query(2*node+1, mid+1, hi,  l, r));
    }

    public List<Boolean> getResults(int[][] queries) {
    
        TreeSet<Integer> coords = new TreeSet<>();
        coords.add(0);
        for (int[] q : queries) {
            coords.add(q[1]); 
        }

        Map<Integer, Integer> compress = new HashMap<>();
        List<Integer> sortedCoords = new ArrayList<>(coords);
        for (int i = 0; i < sortedCoords.size(); i++) {
            compress.put(sortedCoords.get(i), i + 1);
        }

        N = sortedCoords.size();
        seg = new int[4 * N];

        // obstacles TreeSet for floor/ceiling lookups
        TreeSet<Integer> obstacles = new TreeSet<>();
        obstacles.add(0);

        List<Boolean> results = new ArrayList<>();

        for (int[] query : queries) {
            if (query[0] == 1) {
                // --- Type 1: Insert obstacle at x ---
                int x    = query[1];
                int xIdx = compress.get(x);

                Integer left  = obstacles.floor(x);
                Integer right = obstacles.higher(x);

                if (right != null) {
                    // Remove old gap stored at right's index
                    update(1, 1, N, compress.get(right), 0);
                    // New gaps
                    update(1, 1, N, xIdx,               x - left);
                    update(1, 1, N, compress.get(right), right - x);
                } else {
                    update(1, 1, N, xIdx, x - left);
                }

                obstacles.add(x);

            } else {
                // --- Type 2: Can we fit block of size sz in [0, x]? ---
                int x  = query[1];
                int sz = query[2];
                int xIdx = compress.get(x);

                // Gap from last obstacle <= x to virtual wall at x
                Integer lastObs = obstacles.floor(x);
                int rightGap = x - lastObs;

                // Max gap among all obstacle-to-obstacle gaps with right endpoint <= x
                // These are stored in seg tree at indices 1..xIdx
                int innerMax = query(1, 1, N, 1, xIdx);

                int maxGap = Math.max(rightGap, innerMax);
                results.add(maxGap >= sz);
            }
        }
        return results;
    }
}