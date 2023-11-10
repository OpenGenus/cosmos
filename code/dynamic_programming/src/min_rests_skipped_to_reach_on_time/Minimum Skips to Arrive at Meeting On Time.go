import "fmt"

func main() {
	fmt.Println(minTimeToVisitAllPoints([][]int{{1, 1}, {3, 4}, {-1, 0}}))
	fmt.Println(minTimeToVisitAllPoints([][]int{{3, 2}, {-2, 2}}))
}

func minTimeToVisitAllPoints(points [][]int) int {
	n := len(points)
	if n == 0 {
		return 0
	}
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if i == j {
				dp[i][j] = 0
			} else {
				dp[i][j] = -1
			}
		}
	}

	for i := 0; i < n; i++ {
		dp[i][i] = 0
	}

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			dp[i][j] = dp[i][j-1] + dist(points[i], points[j])
			if dp[i][j] > points[j][0] {
				dp[i][j] = -1
			}
		}
	}
