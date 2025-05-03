import "math"

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func minDominoRotations(tops []int, bottoms []int) int {
    n := len(tops)
    minRotations := math.MaxInt32

    // Iterate through possible target values (1 to 6)
    for target := 1; target <= 6; target++ {
        possible := true
        rotationsTop := 0 // Rotations to make tops[] == target
        rotationsBottom := 0 // Rotations to make bottoms[] == target

        for i := 0; i < n; i++ {
            topMatch := tops[i] == target
            bottomMatch := bottoms[i] == target

            // If target is not present in the i-th domino, this target is impossible
            if !topMatch && !bottomMatch {
                possible = false
                break
            }

            // Count rotations needed if we aim for tops[] == target
            if !topMatch { // Implies bottomMatch must be true because 'possible' is still true here
                rotationsTop++
            }
            // Count rotations needed if we aim for bottoms[] == target
            if !bottomMatch { // Implies topMatch must be true
                rotationsBottom++
            }
        }

        // If this target value worked for all dominoes
        if possible {
            minRotations = min(minRotations, rotationsTop)
            minRotations = min(minRotations, rotationsBottom)
        }
    }

    if minRotations == math.MaxInt32 {
        return -1
    }
    return minRotations
}