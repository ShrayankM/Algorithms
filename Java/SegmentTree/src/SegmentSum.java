public class SegmentSum {
    private int st[];
    private int N;
    public SegmentSum(int n) {
        st = new int[4 * n + 1];
        N = n;
    }

    private static int left(int p) {
        return p << 1;
    }

    private static int right(int p) {
        return (p << 1) + 1;
    }

    public void build(int A[]) {
        build(A, 1, 0, N - 1);
    }

    private void build(int A[], int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
            return;
        }
        build(A, left(p), L, (L + R)/2);
        build(A, right(p), (L + R)/2 + 1, R);
        st[p] = st[left(p)] + st[right(p)];
    }

    public int RSUM(int A[], int i, int j) {
        return RSUM(A, 1,0, N - 1, i, j);
    }

    private int RSUM(int A[], int p, int L, int R, int i, int j) {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return st[p];

        int leftSum = RSUM(A, left(p), L, (L + R)/2, i, j);
        int rightSum = RSUM(A, right(p), (L + R)/2 + 1, R, i, j);

        if (leftSum == 0) return rightSum;
        if (rightSum == 0) return leftSum;

        return leftSum + rightSum;
    }

    public void update(int A[], int index, int v) {
        update(A, 1, 0, N - 1, index, v);
    }

    private void update(int A[], int p, int L, int R, int index, int v) {
        if (L == R && L == index) {
            st[p] = v;
            return;
        }
        if (index >= L && index <= (L + R)/2)
            update(A, left(p), L, (L + R)/2, index, v);
        else
            update(A, right(p), (L + R)/2 + 1, R, index, v);
        st[p] = st[left(p)] + st[right(p)];
    }
}
